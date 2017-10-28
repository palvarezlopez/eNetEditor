#include "vehicleTypeTable.h"

// main
#include "../dialogs/main/eNetEditorMainWindow.h"

// Project
#include "../project/eNetEditorProject.h"

// Configuration
#include "../configuration/main/eNetEditorMainConfiguration.h"
#include "../configuration/project/eNetEditorProjectConfiguration.h"
#include "../configuration/items/vehicleTypeItemConfiguration.h"

// Items
#include "../items/vehicleTypeItem.h"


vehicleTypeTable::vehicleTypeTable(const QString &newNameOfTable, vehicleTypeItemConfiguration *vehicleTypeItemC, eNetEditorDatabase *newDatabase) : eNetEditorTable(newNameOfTable, vehicleTypeItemC, newDatabase)
{
    // Fill vehicle Type Index
    nextVehicleTypeIndex.fill(0, geteNetEditorMainWindow()->geteNetEditorConfiguration()->getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeNumberOfVehicleClasses());
}

vehicleTypeTable::~vehicleTypeTable()
{
    // Nothing to erase
}

int vehicleTypeTable::getNextVehicleTypeIndex(vehicleClass vc)
{
    return nextVehicleTypeIndex.at(static_cast<int>(vc));
}

void vehicleTypeTable::updateNextVehicleTypeIndex(vehicleClass vc)
{
    (nextVehicleTypeIndex[static_cast<int>(vc)])++;
}
