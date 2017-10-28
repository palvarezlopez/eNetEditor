#include "flowTable.h"

// main
#include "../../dialogs/main/eNetEditorMainWindow.h"

// Database
#include "../../database/eNetEditorDatabase.h"

// Project
#include "../../project/eNetEditorProject.h"

// Scene
#include "../../project/eNetEditorScene.h"

// Configuration
#include "../../configuration/main/eNetEditorMainConfiguration.h"
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/vehicles/flowItemConfiguration.h"

// Items
#include "../../items/vehicles/flowItem.h"
#include "../../items/vehicleTypeItem.h"
#include "../../items/routeItem.h"


flowTable::flowTable(const QString &newNameOfTable, flowItemConfiguration *flowItemC, eNetEditorDatabase *newDatabase) : abstractVehicleTable(newNameOfTable, flowItemC, newDatabase)
{
    // Nothing to do
}

flowTable::~flowTable()
{
    // Nothing to erase
}
