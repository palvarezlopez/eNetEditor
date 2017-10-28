#ifndef MULTIENTRYEXITDETECTORSE3TABLE_H
#define MULTIENTRYEXITDETECTORSE3TABLE_H

#include "abstractDetectorTable.h"


class multiEntryExitE3DetectorTable : public abstractDetectorTable
{
public:

    multiEntryExitE3DetectorTable(const QString &newNameOfTable, multiEntryExitE3DetectorItemConfiguration *multiEntryExitE3DetectorItemC, eNetEditorDatabase *newDatabase);

    ~multiEntryExitE3DetectorTable();


private:

    // Container with the multiEntryExitE3DetectorItem
    QList<multiEntryExitE3DetectorItem *> E3Table;
};



#endif // MULTIENTRYEXITDETECTORSE3TABLE_H
