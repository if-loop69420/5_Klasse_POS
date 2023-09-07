/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *numberInput;
    QPushButton *insertButton;
    QPushButton *removeButton;
    QPushButton *findButton;
    QLabel *foundLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        numberInput = new QLineEdit(centralwidget);
        numberInput->setObjectName("numberInput");
        numberInput->setGeometry(QRect(20, 20, 113, 26));
        insertButton = new QPushButton(centralwidget);
        insertButton->setObjectName("insertButton");
        insertButton->setGeometry(QRect(20, 60, 87, 26));
        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");
        removeButton->setGeometry(QRect(120, 60, 87, 26));
        findButton = new QPushButton(centralwidget);
        findButton->setObjectName("findButton");
        findButton->setGeometry(QRect(220, 60, 87, 26));
        foundLabel = new QLabel(centralwidget);
        foundLabel->setObjectName("foundLabel");
        foundLabel->setGeometry(QRect(150, 20, 151, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        insertButton->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        findButton->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        foundLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
