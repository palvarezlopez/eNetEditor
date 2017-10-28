#ifndef ABSTRACTEDGETABLE_H
#define ABSTRACTEDGETABLE_H

#include "../eNetEditorTable.h"


class abstractEdgeTable  : public eNetEditorTable
{
public:

    abstractEdgeTable(const QString &newNameOfTable, eNetEditorItemConfiguration *newItemConfiguration, eNetEditorDatabase *newDatabase);

    virtual ~abstractEdgeTable();

};

#endif // ENETEDITOREDGETABLE_H
