#ifndef FLOWTABLE_H
#define FLOWTABLE_H

#include "abstractVehicleTable.h"


class flowTable : public abstractVehicleTable
{
public:

    // 01 - Función terminada y documentada
    flowTable(const QString &newNameOfTable, flowItemConfiguration *flowItemC, eNetEditorDatabase *newDatabase);

    // 02 - Función terminada y documentada
    ~flowTable();


private:
};

#endif // FLOWTABLE_H
