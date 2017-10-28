#ifndef LANEAREADETECTORE2TABLE_H
#define LANEAREADETECTORE2TABLE_H

#include "abstractDetectorTable.h"


class laneAreaE2DetectorTable : public abstractDetectorTable
{
public:

    laneAreaE2DetectorTable(const QString &newNameOfTable, laneAreaE2DetectorItemConfiguration *laneAreaE2DetectorItemC, eNetEditorDatabase *newDatabase);

    ~laneAreaE2DetectorTable();


private:

    // Container with the laneAreaE2DetectorItem
    QList<laneAreaE2DetectorItem *> E2Table;
};

#endif // LANEAREADETECTORE2TABLE_H
