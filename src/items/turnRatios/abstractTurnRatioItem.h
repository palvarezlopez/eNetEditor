#ifndef ABSTRACTTURNRATIOITEM_H
#define ABSTRACTTURNRATIOITEM_H

#include "../eNetEditorItem.h"


class abstractTurnRatioItem : public eNetEditorItem
{
public:

    abstractTurnRatioItem(eNetEditorTable *newItemTable);

    virtual ~abstractTurnRatioItem();

    virtual void make() = 0;

    virtual QDomElement saveItem(QDomDocument *domDoc) = 0;

    virtual QDomElement exportItemToXML(QDomDocument *domDoc) = 0;


protected:

    // Each type of item has seir own paint function
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;

    // Each type of item has their own shape Function
    virtual QPainterPath shape() const = 0;


private:

    nodeItem *nodeParent;

};

#endif // ABSTRACTTURNRATIOITEM_H
