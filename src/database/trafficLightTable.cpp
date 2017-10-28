#include "trafficLightTable.h"

// main
#include "../dialogs/main/eNetEditorMainWindow.h"

// Configuration
#include "../configuration/items/trafficLightItemConfiguration.h"

// Items
#include "../items/nodeItem.h"
#include "../items/connectionItem.h"
#include "../items/trafficLightItem.h"



trafficLightTable::trafficLightTable(const QString &newNameOfTable, trafficLightItemConfiguration *trafficLightItemC, eNetEditorDatabase *newDatabase) : eNetEditorTable(newNameOfTable, trafficLightItemC, newDatabase)
{
    // Nothing to declare
}

trafficLightTable::~trafficLightTable()
{
    // Drop Traffic light Table
    for(QList<trafficLightItem *>::iterator i = tlTable.begin(); i != tlTable.end(); i++)
    {
        delete (*i);
    }
}



trafficLightItem *trafficLightTable::findTrafficLightById(const QString &idToSearch) const
{
    // Search the Prohibition comparing their Strings and idToSearch.
    for (QList<trafficLightItem *>::const_iterator i = tlTable.begin(); i != tlTable.end(); i++)
    {
        // If founded, then return a pointer to item.
        if(idToSearch.compare( (*i)->getItemId() ) == 0)
        {
            return (*i);
        }
    }

    // If prohibition was not founded, then return NULL
    return NULL;
}
