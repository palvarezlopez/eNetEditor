#include "chargingStationTable.h"

// Configuration
#include "../../configuration/items/stops/chargingStationItemConfiguration.h"

// Items
#include "../../items/stops/chargingStationItem.h"
#include "../../items/laneItem.h"


chargingStationTable::chargingStationTable(const QString &newNameOfTable, chargingStationItemConfiguration *chargingStationItemC, eNetEditorDatabase *newDatabase) : eNetEditorTable(newNameOfTable, chargingStationItemC, newDatabase)
{
    // Nothing to do
}

chargingStationTable::~chargingStationTable()
{
    // Nothing to do
}
