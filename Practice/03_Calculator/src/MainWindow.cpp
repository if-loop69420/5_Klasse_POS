#include <QMessageBox>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "../exprtk/exprtk.hpp"
#include "calculation.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_zeroButton_clicked() { appendText("0"); }

void MainWindow::on_oneButton_clicked() { appendText("1"); }

void MainWindow::on_twoButton_clicked() { appendText("2"); }

void MainWindow::on_threeButton_clicked() { appendText("3"); }

void MainWindow::on_fourButton_clicked() { appendText("4"); }

void MainWindow::on_fiveButton_clicked() { appendText("5"); }

void MainWindow::on_sixButton_clicked() { appendText("6"); }

void MainWindow::on_sevenButton_clicked() { appendText("7"); }

void MainWindow::on_eightButton_clicked() { appendText("8"); }

void MainWindow::on_nineButton_clicked() { appendText("9"); }

void MainWindow::on_plusButton_clicked() { appendText(" + "); }

void MainWindow::on_minusButton_clicked() { appendText(" - "); }

void MainWindow::on_timesButton_clicked() { appendText(" * "); }

void MainWindow::on_divideButton_clicked() { appendText(" / "); }

void MainWindow::on_pointButton_clicked() { appendText("."); }

void MainWindow::on_openBracketButton_clicked() { appendText(" ("); }

void MainWindow::on_closeBracketButton_clicked() { appendText(") "); }

void MainWindow::on_backspaceButton_clicked() {
    QString newText = ui->display->text().trimmed();

    if (newText.isEmpty()) return;

    newText = newText.chopped(1).trimmed();
    ui->display->setText(newText);
}

void MainWindow::on_evaluateButton_clicked() {
    std::string expression = ui->display->text().toStdString();

    double result;
    try {
        result = evaluate(expression);
    } catch (std::invalid_argument &e) {
        displayError(e.what());
        return;
    }

    ui->display->setText(QString::number(result));
}

void MainWindow::appendText(const QString &text) {
    QString newText = ui->display->text() + text;
    ui->display->setText(newText);
}

void MainWindow::displayError(const QString &message) {
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.exec();
}
