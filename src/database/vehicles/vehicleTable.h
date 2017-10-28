#ifndef VEHICLETABLE_H
#define VEHICLETABLE_H

#include "abstractVehicleTable.h"


class vehicleTable : public abstractVehicleTable
{
public:

    // 01 - Función terminada y documentada
    vehicleTable(const QString &newNameOfTable, vehicleItemConfiguration *vehicleItemC, eNetEditorDatabase *newDatabase);

    // 03 - Función terminada y documentada
    ~vehicleTable();

    // 13 - Función terminada y documentada
    vehicleItem *findVehicleById(const QString &idToSearch) const;

private:

    // Table with the vehicles
    QList<vehicleItem *> vTable;
};

#endif // VEHICLETABLE_H
