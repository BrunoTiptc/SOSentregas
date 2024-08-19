#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Verifique os drivers disponíveis
    qDebug() << "Drivers disponíveis:" << QSqlDatabase::drivers();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("sosentregas"); // Nome do banco de dados
    db.setUserName("root"); // Nome de usuário do banco de dados
    db.setPassword("@Bruno1518"); // Senha do banco de dados

    if (!db.open()) {
        qDebug() << "Erro ao conectar ao banco de dados:" << db.lastError().text();
        QMessageBox::critical(nullptr, "Erro", "Erro ao conectar ao banco de dados: " + db.lastError().text());
        return -1;
    }

    MainWindow w;
    w.showMaximized();
    return a.exec();
}
