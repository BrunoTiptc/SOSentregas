#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstring.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    testDatabaseQuery();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testDatabaseQuery() {
    QSqlQuery query;
    if (!query.exec("SELECT * FROM tabela_inexistente")) { // Nome de tabela incorreto para teste
        showError("Erro ao executar a consulta: " + query.lastError().text());
    } else {
        while (query.next()) {
            qDebug() << query.value(0).toString(); // Exemplo de como acessar os dados retornados
        }
    }
}

void MainWindow::showError(const QString &message) {
    QMessageBox::critical(this, "Erro", message);
}

void MainWindow::on_pushButton_3_clicked()
{
    {
        Cadastro *cadastroWindow = new Cadastro(this);
        cadastroWindow->showMaximized(); //
    }
}

