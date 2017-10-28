#ifndef TURNRATIOINTERVALTABLE_H
#define TURNRATIOINTERVALTABLE_H

#include "abstractTurnRatioTable.h"


class turnRatioIntervalTable : public abstractTurnRatioTable
{
public:

    turnRatioIntervalTable(const QString &newNameOfTable, turnRatioIntervalItemConfiguration *newTurnRatioIntervalItemConfiguration, eNetEditorDatabase *newDatabase);

    ~turnRatioIntervalTable();

    void orderByInterval();
};

#endif // TURNRATIOINTERVALTABLE_H
