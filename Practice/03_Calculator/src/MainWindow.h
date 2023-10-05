
#ifndef GRAPHICAL_CALCULATOR_MAINWINDOW_H
#define GRAPHICAL_CALCULATOR_MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:

    void on_zeroButton_clicked();

    void on_oneButton_clicked();

    void on_twoButton_clicked();

    void on_threeButton_clicked();

    void on_fourButton_clicked();

    void on_fiveButton_clicked();

    void on_sixButton_clicked();

    void on_sevenButton_clicked();

    void on_eightButton_clicked();

    void on_nineButton_clicked();

    void on_plusButton_clicked();

    void on_minusButton_clicked();

    void on_timesButton_clicked();

    void on_divideButton_clicked();

    void on_pointButton_clicked();

    void on_openBracketButton_clicked();

    void on_closeBracketButton_clicked();

    void on_backspaceButton_clicked();

    void on_evaluateButton_clicked();

private:
    Ui::MainWindow *ui;

    void appendText(const QString &text);
    static void displayError(const QString &message = "Invalid expression");
};


#endif //GRAPHICAL_CALCULATOR_MAINWINDOW_H
