#ifndef CONNECTIONTABLE_H
#define CONNECTIONTABLE_H

#include "eNetEditorTable.h"


class connectionTable : public eNetEditorTable
{
public:

    // 01 - Función terminada y documentada
    connectionTable(const QString &newNameOfTable, connectionItemConfiguration *connectionItemC, eNetEditorDatabase *newDatabase);

    // 03 - Función terminada y documentada
    ~connectionTable();


    // 14 - Función terminada y documentada
    connectionItem *findConnectionByComponents(laneItem *laneOrigin, laneItem *laneDestiny);


private:
};

#endif // CONNECTIONTABLE_H
