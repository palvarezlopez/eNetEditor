#ifndef ABSTRACTTURNRATIOTABLE_H
#define ABSTRACTTURNRATIOTABLE_H

#include "../eNetEditorTable.h"


class abstractTurnRatioTable : public eNetEditorTable
{
public:

    abstractTurnRatioTable(const QString &newNameOfTable, eNetEditorItemConfiguration *newItemConfiguration, eNetEditorDatabase *newDatabase);

    virtual ~abstractTurnRatioTable();
};

#endif // ABSTRACTTURNRATIOTABLE_H
