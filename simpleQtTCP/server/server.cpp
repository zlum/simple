#include "server.h"

#include <QLabel>
#include <QMessageBox>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>
#include <QTime>
#include <QVBoxLayout>

Server::Server(quint16 nPort, QWidget* pwgt):
    QWidget(pwgt),
    m_nNextBlockSize(0)
{
    m_ptcpServer = new QTcpServer(this);

    if (!m_ptcpServer->listen(QHostAddress::Any, nPort))
    {
        QMessageBox::critical(nullptr,
                              "Server Error",
                              "Unable to start the server:" +
                              m_ptcpServer->errorString());
        m_ptcpServer->close();

        return;
    }

    connect(m_ptcpServer, SIGNAL(newConnection()),
            this, SLOT(slotNewConnection()));

    m_ptxt = new QTextEdit;
    m_ptxt->setReadOnly(true);

    //Layout setup
    auto pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(new QLabel("<Hl>Server</Hl>"));
    pvbxLayout->addWidget(m_ptxt);
    setLayout(pvbxLayout);
}

void Server::slotNewConnection()
{
    QTcpSocket* pClientSocket = m_ptcpServer->nextPendingConnection();

    connect(pClientSocket, SIGNAL(disconnected()),
            pClientSocket, SLOT(deleteLater()));
    connect(pClientSocket, SIGNAL(readyRead()),
            this, SLOT(slotReadClient()));

    sendToClient(pClientSocket, "Server Response: Connected!");
}

void Server::slotReadClient()
{
    auto pClientSocket = static_cast<QTcpSocket*>(sender());
    QDataStream in(pClientSocket);

    in.setVersion(QDataStream::Qt_5_11);

    for(;;)
    {
        if(!m_nNextBlockSize)
        {
            if(pClientSocket->bytesAvailable() < sizeof(quint16))
            {
                break;
            }

            in >> m_nNextBlockSize;
        }

        if(pClientSocket->bytesAvailable() < m_nNextBlockSize)
        {
            break;
        }

        QTime time;
        QString str;

        in >> time >> str;

        QString strMessage =
                time.toString() + " " + "Client has sent - " + str;
        m_ptxt->append(strMessage);
        m_nNextBlockSize = 0;

        sendToClient(pClientSocket,
                     "Server Response: Received \"" + str + "\"");
    }
}

void Server::sendToClient(QTcpSocket *pSocket, const QString &str)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_5_11);
    out << quint16(0) << QTime::currentTime() << str;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    pSocket->write(arrBlock);
}
