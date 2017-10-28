#include "laneTable.h"

// Configuration
#include "../configuration/items/laneItemConfiguration.h"
#include "../configuration/items/edges/edgeItemConfiguration.h"


// Items
#include "../items/edges/edgeItem.h"
#include "../items/laneItem.h"

laneTable::laneTable(const QString &newNameOfTable, laneItemConfiguration *laneItemC, eNetEditorDatabase *newDatabase) : eNetEditorTable(newNameOfTable, laneItemC, newDatabase)
{
    // Nothing to declare
}

laneTable::~laneTable()
{
    // Nothing to do
}

laneItem *laneTable::findLaneByEdge(edgeItem *parent) const
{
    /// ARREGLAR
    /*
    // Searc comparing the pointer of all lanes with parent
    for(QList<laneItem*>::const_iterator i = lTable.begin(); i != lTable.end(); i++)
    {
        // If pointer searched is the same of parent
        if((*i)->getEdgeParent() == parent)
        {
            // Return lane
            return (*i);
        }
    }
    */
    // If the lane isn't founded, then return NULL
    return NULL;
}
