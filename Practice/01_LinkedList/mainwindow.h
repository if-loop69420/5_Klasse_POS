#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <optional>
#include "linkedlist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_numberInput_textChanged(const QString &arg1);

    void on_insertButton_clicked();

    void on_removeButton_clicked();

    void on_findButton_clicked();

private:
    Ui::MainWindow *ui;
    optional<int> current_input = nullopt;
    unique_ptr<LinkedList> list = unique_ptr<LinkedList>(new LinkedList());
};
#endif // MAINWINDOW_H
