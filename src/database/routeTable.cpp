#include "routeTable.h"

// Configuration
#include "../configuration/items/routeItemConfiguration.h"

// Items
#include "../items/routeItem.h"
#include "../items/edges/edgeItem.h"


routeTable::routeTable(const QString &newNameOfTable, routeItemConfiguration *routeItemC, eNetEditorDatabase *newDatabase) : eNetEditorTable(newNameOfTable, routeItemC, newDatabase)
{
    // Nothing to declare
}

routeTable::~routeTable()
{
    // Drop route Table
    for(QList<routeItem *>::iterator i = rTable.begin(); i != rTable.end(); i++)
    {
        delete (*i);
    }
}



routeItem *routeTable::findRouteById(const QString &idToSearch) const
{
    // Search the route comparing their Strings and idToSearch.
    for (QList<routeItem *>::const_iterator i = rTable.begin(); i != rTable.end(); i++)
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
