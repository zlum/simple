#include "client.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTime>
#include <QVBoxLayout>

Client::Client(const QString& strHost, quint16 nPort, QWidget* pwgt):
    QWidget(pwgt),
    m_nNextBlockSize(0)
{
    m_pTcpSocket = new QTcpSocket(this);
    m_pTcpSocket->connectToHost(strHost, nPort);
    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_pTcpSocket, SIGNAL(readyRead() ), SLOT(slotReadyRead()));
    connect(m_pTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(slotError(QAbstractSocket::SocketError)));

    m_ptxtinfo = new QTextEdit;
    m_ptxtinput = new QLineEdit;

    m_ptxtinfo->setReadOnly(true);
    auto pcmd = new QPushButton("&Send");

    connect(pcmd, SIGNAL(clicked()), SLOT(slotSendToServer()));
    connect(m_ptxtinput, SIGNAL(returnPressed()),
            this, SLOT(slotSendToServer()));

    //Layout setup
    auto pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(new QLabel("<Нl>Client</Нl>"));
    pvbxLayout->addWidget(m_ptxtinfo);
    pvbxLayout->addWidget(m_ptxtinput);
    pvbxLayout->addWidget(pcmd);
    setLayout(pvbxLayout);
}


void Client::slotReadyRead()
{
    QDataStream in(m_pTcpSocket);

    in.setVersion(QDataStream::Qt_5_11);

    for(;;)
    {
        if(m_nNextBlockSize == 0)
        {
            if(m_pTcpSocket->bytesAvailable() < qint64(sizeof(quint16)))
            {
                break;
            }

            in >> m_nNextBlockSize;
        }

        if(m_pTcpSocket->bytesAvailable() < m_nNextBlockSize)
        {
            break;
        }

        QTime time;
        QString str;

        in >> time >> str;
        m_ptxtinfo->append(time.toString() + " " + str);
        m_nNextBlockSize = 0;
    }
}

void Client::slotError(QAbstractSocket::SocketError err)
{
    QString strError =
            "Error: "+ (err == QAbstractSocket::HostNotFoundError ?
                            "The host was not found." :
                            err == QAbstractSocket::RemoteHostClosedError ?
                                "The remote host is closed." :
                                err == QAbstractSocket::ConnectionRefusedError ?
                                    "The connection was refused." :
                                    QString(m_pTcpSocket->errorString()));
}

void Client::slotSendToServer()
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_5_11);
    out << quint16(0) << QTime::currentTime() << m_ptxtinput->text();
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    m_pTcpSocket->write(arrBlock);
    m_ptxtinput->setText("");
}

void Client::slotConnected()
{
    m_ptxtinfo->append("Received the connected() signal");
}
