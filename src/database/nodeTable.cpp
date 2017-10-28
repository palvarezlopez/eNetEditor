#include "nodeTable.h"

// Configuration
#include "../configuration/items/nodeItemConfiguration.h"

// Items
#include "../items/nodeItem.h"
#include "../items/edges/edgeItem.h"



nodeTable::nodeTable(const QString &newNameOfTable, nodeItemConfiguration *nodeItemC, eNetEditorDatabase *newDatabase) : eNetEditorTable(newNameOfTable, nodeItemC, newDatabase)
{
    // By default, Scale is 0
    mapPixelMeter = 0;

    // By default index is 0
    index = 0;
}

nodeTable::~nodeTable()
{
    // Nothing to do
}



void nodeTable::setMapPixelMeter(qreal newMapPixelMeter)
{
    mapPixelMeter = newMapPixelMeter;
}

void nodeTable::updateIndex()
{
    index++;
}

QStringList nodeTable::getIdsOfIncomingsEdges(nodeItem *n)
{
    // Declare QStringList
    QStringList idsOfIncomingsEdges;

    // If the node exist
    if(n != NULL)
    {
        // Get all ID's of the Incomings Edges
        for (QList<edgeItem *>::iterator i = n->iteratorIncomingEdgesBegin(); i != n->iteratorIncomingEdgesEnd(); i++)
        {
            idsOfIncomingsEdges << (*i)->getItemId();
        }
    }

    // Return QStringList
    return idsOfIncomingsEdges;
}

QStringList nodeTable::getIdsOfOutcomingsEdges(nodeItem *n)
{
    // Declare QStringList
    QStringList idsOfOutcomingsEdges;

    // If the node exist
    if(n != NULL)
    {
        // Get all ID's of the Incomings Edges
        for (QList<edgeItem *>::iterator i = n->iteratorOutcomingEdgesBegin(); i != n->iteratorOutcomingEdgesEnd(); i++)
        {
            idsOfOutcomingsEdges << (*i)->getItemId();
        }
    }

    // Return QStringList
    return idsOfOutcomingsEdges;
}

int nodeTable::getIndex()
{
    return index;
}
