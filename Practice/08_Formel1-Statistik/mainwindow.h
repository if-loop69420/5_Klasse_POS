#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "driver.h"
#include <QxOrm_Impl.h>
#include <algorithm>
#include <regex>

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
    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_driverCombobox_activated(int index);

    void on_driverCombobox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QList<drivers> driver_list;
    QList<drivers> current_search;
    QList<drivers> current_selected;
};
#endif // MAINWINDOW_H
