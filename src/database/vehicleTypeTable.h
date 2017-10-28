#ifndef VEHICLETYPETABLE_H
#define VEHICLETYPETABLE_H

#include "eNetEditorTable.h"


class vehicleTypeTable : public eNetEditorTable
{
public:

    // 01 - Función terminada y documentada
    vehicleTypeTable(const QString &newNameOfTable, vehicleTypeItemConfiguration *vehicleTypeItemC, eNetEditorDatabase *newDatabase);

    // 02 - Función terminada y documentada
    ~vehicleTypeTable();

    int getNextVehicleTypeIndex(vehicleClass vc);

    void updateNextVehicleTypeIndex(vehicleClass vc);


private:

    QVector<int> nextVehicleTypeIndex;
};

#endif // VEHICLETYPETABLE_H
