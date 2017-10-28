#ifndef FLOWMEASURETABLE_H
#define FLOWMEASURETABLE_H

#include "eNetEditorTable.h"


class flowMeasureTable : public eNetEditorTable
{
public:

    flowMeasureTable(const QString &newNameOfTable, flowMeasureItemConfiguration *flowMeasureItemC, eNetEditorDatabase *newDatabase);

    ~flowMeasureTable();

    bool exportTableToCSV(const QString &filePath);
};

#endif // FLOWMEASURETABLE_H
