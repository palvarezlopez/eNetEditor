#include "abstractVehicleTable.h"

#include "../../configuration/items/vehicles/abstractVehicleItemConfiguration.h"


abstractVehicleTable::abstractVehicleTable(const QString &newNameOfTable, eNetEditorVehicleConfiguration *eNetEditorVehicleC, eNetEditorDatabase *newDatabase) : eNetEditorTable(newNameOfTable, eNetEditorVehicleC, newDatabase)
{

}

abstractVehicleTable::~abstractVehicleTable()
{

}

