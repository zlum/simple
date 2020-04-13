#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QTextEdit>
#include <QWidget>

class QLineEdit;
class QTextEdit;

class Client:
        public QWidget
{
    Q_OBJECT

public:
    explicit Client(const QString& strHost,
                    quint16 nPort,
                    QWidget* pwgt = nullptr);

private:
    QTcpSocket* m_pTcpSocket;
    QTextEdit* m_ptxtinfo;
    QLineEdit* m_ptxtinput;
    quint16 m_nNextBlockSize;

private slots:
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError);
    void slotSendToServer();
    void slotConnected();
};

#endif // CLIENT_H
