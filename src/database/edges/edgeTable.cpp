#include "edgeTable.h"

// Configuration
#include "../../configuration/items/edges/edgeItemConfiguration.h"
#include "../../configuration/items/vehicleTypeItemConfiguration.h"

// Items
#include "../../items/nodeItem.h"
#include "../../items/edges/edgeItem.h"
#include "../../items/laneItem.h"


edgeTable::edgeTable(const QString &newNameOfTable, edgeItemConfiguration *edgeItemC, eNetEditorDatabase *newDatabase) : abstractEdgeTable(newNameOfTable, edgeItemC, newDatabase)
{
    // Nothing to declare
}

edgeTable::~edgeTable()
{
    // Nothing to do
}

edgeItem *edgeTable::findEdgeByNodes(nodeItem *nodeOrigin, nodeItem *nodeDestiny)
{
    // Declare edge Aux
    edgeItem *eAux;

    // Iterate over list of items
    for(QList<eNetEditorItem *>::iterator i = iteratorTableBegin(); i != iteratorTableEnd(); i++)
    {
        // Cast edge item
        eAux = dynamic_cast<edgeItem *>(*i);

        // If node Origin and destiny are the same
        if(eAux->getNodeOrigin() == nodeOrigin && eAux->getNodeDestiny() == nodeDestiny)
        {
            // Return edge Aux
            return eAux;
        }
    }

    // If the edge isn't founded, then return NULL
    return NULL;
}

QStringList edgeTable::getIdsOfLanes(edgeItem *e)
{
    // Declare list of ids of lanes
    QStringList IdsLanes;

    // If edge e exists
    if(e != NULL)
    {
        // Iterate over lanes
        for (QList<laneItem *>::iterator i = e->iteratorLanesBegin(); i != e->iteratorLanesEnd(); i++)
        {
            // Set each Lane id to IdLanes
            IdsLanes << (*i)->getItemId();
        }
    }

    // Return list of id's
    return IdsLanes;
}
