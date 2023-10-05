#include "QTreeWidgetXmlItem.h"

QTreeWidgetXmlItem::QTreeWidgetXmlItem(
        QTreeWidgetItem *parent, const tinyxml2::XMLElement *xmlElement
) : QTreeWidgetItem(parent) {
    this->xmlElement = xmlElement;
}
