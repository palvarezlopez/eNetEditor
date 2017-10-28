#ifndef TURNPROBABILITIESTABLE_H
#define TURNPROBABILITIESTABLE_H

#include "../eNetEditorTable.h"


class turnRatioTable : public eNetEditorTable
{
public:

    turnRatioTable(const QString &newNameOfTable, turnRatioItemConfiguration *turnRatioItemC, eNetEditorDatabase *newDatabase);

    ~turnRatioTable();
};

#endif // TURNPROBABILITIESTABLE_H
