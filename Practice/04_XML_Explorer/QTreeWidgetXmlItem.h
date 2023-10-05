#ifndef XML_EXPLORER_QTREEWIDGETXMLITEM_H
#define XML_EXPLORER_QTREEWIDGETXMLITEM_H


#include <QTreeWidgetItem>
#include <tinyxml2.h>

class QTreeWidgetXmlItem : public QTreeWidgetItem {
public:
    explicit QTreeWidgetXmlItem(QTreeWidgetItem *parent, const tinyxml2::XMLElement *xmlElement);

    const tinyxml2::XMLElement *xmlElement;
};


#endif //XML_EXPLORER_QTREEWIDGETXMLITEM_H
