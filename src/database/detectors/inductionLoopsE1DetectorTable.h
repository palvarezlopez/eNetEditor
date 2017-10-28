#ifndef INDUCTIONLOOPSDETECTORE1TABLE_H
#define INDUCTIONLOOPSDETECTORE1TABLE_H

#include "abstractDetectorTable.h"


class inductionLoopsE1DetectorTable : public abstractDetectorTable
{
public:

    inductionLoopsE1DetectorTable(const QString &newNameOfTable, inductionLoopsE1DetectorItemConfiguration *inductionLoopsE1DetectorItemC, eNetEditorDatabase *newDatabase);

    ~inductionLoopsE1DetectorTable();

    bool exportDetectorDefinitionsToXML();


private:

    // Container with the inductionLoopsE1DetectorItem
    QList<inductionLoopsE1DetectorItem *> E1Table;
};

#endif // INDUCTIONLOOPSDETECTORE1TABLE_H
