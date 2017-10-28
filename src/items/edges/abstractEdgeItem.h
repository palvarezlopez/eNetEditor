#ifndef ABSTRACTEDGEITEM_H
#define ABSTRACTEDGEITEM_H

#include "../eNetEditorItem.h"


class abstractEdgeItem : public eNetEditorItem
{
public:

    abstractEdgeItem(eNetEditorTable *newTable);

    virtual ~abstractEdgeItem();

    virtual QDomElement saveItem(QDomDocument *domDoc) = 0;

    virtual QDomElement exportItemToXML(QDomDocument *domDoc) = 0;

};

#endif // ENETEDITOREDGEITEM_H
