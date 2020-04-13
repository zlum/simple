#ifndef SERVER_H
#define SERVER_H

#include <QWidget>

class QTcpServer;
class QTcpSocket;
class QTextEdit;

class Server:
        public QWidget
{
    Q_OBJECT

public:
    explicit Server(quint16 nPort, QWidget* pwgt = nullptr);

public slots:
    virtual void slotNewConnection();
    void slotReadClient();

private:
    void sendToClient(QTcpSocket* pSocket, const QString& str);

private:
    QTcpServer* m_ptcpServer;
    QTextEdit* m_ptxt;
    quint16 m_nNextBlockSize;
};

#endif // SERVER_H
