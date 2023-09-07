#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_numberInput_textChanged(const QString &arg1)
{
    // Try converting to int. If that fails, do nothing
    bool ok;
    int value = arg1.toInt(&ok);
    this->current_input = (ok) ? make_optional<int>(value) : nullopt;
}


void MainWindow::on_insertButton_clicked()
{
    if(this->current_input != nullopt) {
        this->list->insert(this->current_input.value());
        this->ui->foundLabel->setText("Number inserted");
    }
}






void MainWindow::on_removeButton_clicked()
{
    if(this->current_input != nullopt) {
        this->list->remove(current_input.value());
        this->ui->foundLabel->setText("Number removed");
    }
}


void MainWindow::on_findButton_clicked()
{
    if(this->current_input != nullopt) {
        bool result = this->list->find(current_input.value());
        QString findResult = (result == true) ? "Number was found" : "Number wasn't found";
        this->ui->foundLabel->setText(findResult);
    }
}

