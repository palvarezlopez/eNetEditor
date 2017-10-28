#include "vehicleTable.h"

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
#include "../../configuration/items/vehicles/vehicleItemConfiguration.h"

// Items
#include "../../items/vehicles/vehicleItem.h"
#include "../../items/routeItem.h"



vehicleTable::vehicleTable(const QString &newNameOfTable, vehicleItemConfiguration *vehicleItemC, eNetEditorDatabase *newDatabase) : abstractVehicleTable(newNameOfTable, vehicleItemC, newDatabase)
{
    // Nothing to declare
}


vehicleTable::~vehicleTable()
{
    // Drop Vehicle Table
    for(QList<vehicleItem *>::iterator i = vTable.begin(); i != vTable.end(); i++)
    {
        delete (*i);
    }
}

vehicleItem *vehicleTable::findVehicleById(const QString &idToSearch) const
{
    // Search the vehicle comparing their Strings and idToSearch.
    for (QList<vehicleItem *>::const_iterator i = vTable.begin(); i != vTable.end(); i++)
    {
        // If founded, then return a pointer to item.
        if(idToSearch.compare( (*i)->getItemId() ) == 0)
        {
            return (*i);
        }
    }

    // If not founded, then return null.
    return NULL;
}
