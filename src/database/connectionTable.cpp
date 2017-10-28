#include "connectionTable.h"

// Configuration
#include "../configuration/items/connectionItemConfiguration.h"

// Items
#include "../items/nodeItem.h"
#include "../items/edges/edgeItem.h"
#include "../items/laneItem.h"
#include "../items/connectionItem.h"


connectionTable::connectionTable(const QString &newNameOfTable, connectionItemConfiguration *connectionItemC, eNetEditorDatabase *newDatabase) : eNetEditorTable(newNameOfTable, connectionItemC, newDatabase)
{
    // Nothing to declare
}

connectionTable::~connectionTable()
{
    // Nothing to do
}

connectionItem *connectionTable::findConnectionByComponents(laneItem *laneOrigin, laneItem *laneDestiny)
{
    // Declare connectionItem Aux
    connectionItem *cAux;

    // Iterate over list of items
    for(QList<eNetEditorItem *>::iterator i = iteratorTableBegin(); i != iteratorTableEnd(); i++)
    {
        // Cast connectionItem item
        cAux = dynamic_cast<connectionItem *>(*i);

        // If node Origin and destiny are the same
        if(cAux->getLaneOrigin() == laneOrigin && cAux->getLaneDestiny() == laneDestiny)
        {
            // Return connectionItem Aux
            return cAux;
        }
    }

    // If not exist, return NULL
    return NULL;
}
