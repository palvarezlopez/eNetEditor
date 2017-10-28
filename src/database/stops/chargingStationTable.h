#ifndef CHARGINGSTATIONTABLE_H
#define CHARGINGSTATIONTABLE_H

#include "../eNetEditorTable.h"


class chargingStationTable : public eNetEditorTable
{
public:

    // 01 - Función terminada y documentada
    chargingStationTable(const QString &newNameOfTable, chargingStationItemConfiguration *chargingStationItemC, eNetEditorDatabase *newDatabase);

    // 02 - Función terminada y documentada
    ~chargingStationTable();



private:

};

#endif // CHARGINGSTATIONTABLE_H
