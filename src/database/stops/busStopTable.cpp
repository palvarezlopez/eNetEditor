#include "busStopTable.h"

// Configuration
#include "../../configuration/items/stops/busStopItemConfiguration.h"

// Items
#include "../../items/stops/busStopItem.h"
#include "../../items/laneItem.h"


busStopTable::busStopTable(const QString &newNameOfTable, busStopItemConfiguration *busStopItemC, eNetEditorDatabase *newDatabase) : eNetEditorTable(newNameOfTable, busStopItemC, newDatabase)
{
    // Nothing to do
}

busStopTable::~busStopTable()
{
    // Nothing to do
}
