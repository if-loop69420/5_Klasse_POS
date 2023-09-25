#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include <stack>

using std::cout, std::endl;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    loadDocument();
    initXmlTree();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_xmlTree_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous) {
    auto xmlItem = dynamic_cast<QTreeWidgetXmlItem *>(current)->xmlElement;
    auto text = xmlItem->GetText();
    if (text == nullptr) text = "";

    ui->contentLabel->setText(xmlItem->GetText());
    displayAttributes(xmlItem);
}

void MainWindow::loadDocument() {
    QString fileName = "";
    while (fileName.isEmpty()) {
        fileName = QFileDialog::getOpenFileName(
            this,
            "Open XML File",
            "",
            "XML Files (*.xml)"
            );
    }

    doc.LoadFile(fileName.toStdString().c_str());
    if (doc.Error()) {
        QMessageBox::critical(this, "Error", "Bad XML File!");
        QApplication::exit(1);
    }
}

void MainWindow::initXmlTree() {
    auto xmlRoot = doc.RootElement();
    if (xmlRoot == nullptr) {
        QMessageBox::critical(this, "Error", "Bad XML File!");
        QApplication::exit(1);
    }

    auto treeRoot = new QTreeWidgetXmlItem(ui->xmlTree->invisibleRootItem(), xmlRoot);
    syncTree(treeRoot, xmlRoot);
}

void MainWindow::syncTree(QTreeWidgetXmlItem *treeNode, const tinyxml2::XMLElement *xmlNode) {
    treeNode->setText(0, xmlNode->Name());

    for (auto xmlChild = xmlNode->FirstChildElement();
         xmlChild != nullptr;
         xmlChild = xmlChild->NextSiblingElement()) {
        auto treeChild = new QTreeWidgetXmlItem(treeNode, xmlChild);
        syncTree(treeChild, xmlChild);
    }
}

void MainWindow::displayAttributes(const tinyxml2::XMLElement *xmlElement) {
    ui->attributesLabel->setText("");

    std::string attributes;
    for (auto attr = xmlElement->FirstAttribute();
         attr != nullptr;
         attr = attr->Next()) {
        attributes += attr->Name();
        attributes += "=\"";
        attributes += attr->Value();
        attributes += "\"\n";
    }

    ui->attributesLabel->setText(attributes.c_str());
}
