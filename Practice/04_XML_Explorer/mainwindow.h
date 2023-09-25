#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <ltinyxml2/tinyxml2.h>
#include "QTreeWidgetXmlItem.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:

    void on_xmlTree_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);


private:
    Ui::MainWindow *ui;
    tinyxml2::XMLDocument doc = tinyxml2::XMLDocument();

    void loadDocument();

    void initXmlTree();

    void syncTree(QTreeWidgetXmlItem *treeNode, const tinyxml2::XMLElement *xmlNode);

    void displayAttributes(const tinyxml2::XMLElement *xmlElement);
};


#endif //XML_EXPLORER_MAINWINDOW_H
