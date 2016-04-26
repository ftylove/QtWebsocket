/*
Copyright 2013 Antoine Lafarge qtwebsocket@gmail.com

This file is part of QtWebsocket.

QtWebsocket is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

QtWebsocket is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with QtWebsocket.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Client.h"
#include "ui_Client.h"
#include <QInputDialog>

Client::Client(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Client)
{
	ui->setupUi(this);

	defaultPseudo = QString("user%1").arg(qrand() % 9000 + 1000);
	ui->pseudoLineEdit->setPlaceholderText(defaultPseudo);

	wsSocket = new QtWebsocket::QWsSocket(this, NULL, QtWebsocket::WS_V13);

	socketStateChanged(wsSocket->state());

	QObject::connect(ui->sendButton, SIGNAL(pressed()), this, SLOT(sendMessage()));
	QObject::connect(ui->textLineEdit, SIGNAL(returnPressed()), this, SLOT(sendMessage()));
	QObject::connect(ui->connectButton, SIGNAL(pressed()), this, SLOT(connectSocket()));
	QObject::connect(ui->disconnectButton, SIGNAL(pressed()), this, SLOT(disconnectSocket()));
	QObject::connect(wsSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(socketStateChanged(QAbstractSocket::SocketState)));
	QObject::connect(wsSocket, SIGNAL(frameReceived(QString)), this, SLOT(displayMessage(QString)));
	QObject::connect(wsSocket, SIGNAL(connected()), this, SLOT(socketConnected()));
	QObject::connect(wsSocket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
	QObject::connect(wsSocket, SIGNAL(sslErrors(const QList<QSslError>&)), this, SLOT(displaySslErrors(const QList<QSslError>&)));
}

Client::~Client()
{
	delete ui;
}

void Client::sendMessage()
{
	QString pseudo = ui->pseudoLineEdit->text();
	pseudo = (pseudo.isEmpty() ? defaultPseudo : pseudo);

	QString message = ui->textLineEdit->text();
	message = (message.isEmpty() ? QLatin1String("echo") : message);

	ui->textLineEdit->clear();

	wsSocket->write(QString("%1: %2").arg(pseudo).arg(message));
}

void Client::displayMessage(QString message)
{
	ui->chatTextEdit->append(message);
}

void Client::displaySslErrors(const QList<QSslError>& errors)
{
	for (int i=0, sz=errors.size(); i<sz; i++)
	{
		QString errorString = errors.at(i).errorString();
		displayMessage(errorString);
	}
}

void Client::connectSocket()
{
    dialog = new MultiInputDialog(this,tr("Client"));
    connect(dialog,SIGNAL(accepted()),this,SLOT(connectAccepted()));
    dialog->addRow(tr("Server IP:"), QLineEdit::Normal, "wss://echo.websocket.org");
    dialog->addRow(tr("Protocol:"), QLineEdit::Normal, "");
    dialog->exec();
}

void Client::connectAccepted(){
    if(!dialog)
        return;

    QList<QLineEdit*> fields = dialog->getFields();
    QString ipAddress = fields.at(0)->text();
    QString protocol = fields.at(1)->text();

    ipAddress = ipAddress.trimmed();
    if (!ipAddress.isEmpty())
    {
        QUrl url(ipAddress);
        QString host = url.scheme()+"://"+url.host();
        quint16 port = url.port()!=-1 ? url.port() :
                                        url.scheme()=="wss" ? 443 : 80;
        int resModLen = url.port()!=-1 ? QString::number(url.port()).length()+1 : 0;
        QString resource = ipAddress.right(ipAddress.length()-host.length()-resModLen);
        wsSocket->setProtocol(protocol);
        wsSocket->setResourceName(resource);
        wsSocket->setOrigin("QtWebSocket_Client");
        wsSocket->connectToHost(host, port);
    }
    dialog->deleteLater();
}

void Client::disconnectSocket()
{
	wsSocket->disconnectFromHost();
}

void Client::socketConnected()
{	
	displayMessage(tr("CONNECTED"));
}

void Client::socketDisconnected()
{
	displayMessage(tr("DISCONNECTED"));
}

void Client::socketStateChanged(QAbstractSocket::SocketState socketState)
{
	switch (socketState)
	{
		case QAbstractSocket::UnconnectedState:
			ui->socketStateLabel->setText(tr("Unconnected"));
			break;
		case QAbstractSocket::HostLookupState:
			ui->socketStateLabel->setText(tr("HostLookup"));
			break;
		case QAbstractSocket::ConnectingState:
			ui->socketStateLabel->setText(tr("Connecting"));
			break;
		case QAbstractSocket::ConnectedState:
			ui->socketStateLabel->setText("Connected");
			break;
		case QAbstractSocket::BoundState:
			ui->socketStateLabel->setText(tr("Bound"));
			break;
		case QAbstractSocket::ClosingState:
			ui->socketStateLabel->setText(tr("Closing"));
			break;
		case QAbstractSocket::ListeningState:
			ui->socketStateLabel->setText(tr("Listening"));
			break;
		default:
			ui->socketStateLabel->setText(tr("Unknown"));
			break;
	}
}
