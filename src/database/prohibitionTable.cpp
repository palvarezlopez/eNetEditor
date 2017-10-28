#include "prohibitionTable.h"

// Configuration
#include "../configuration/items/prohibitionItemConfiguration.h"

// Items
#include "../items/prohibitionItem.h"


prohibitionTable::prohibitionTable(const QString &newNameOfTable, prohibitionItemConfiguration *prohibitionItemC, eNetEditorDatabase *newDatabase) : eNetEditorTable(newNameOfTable, prohibitionItemC, newDatabase)
{
    // Nothing to declare
}

prohibitionTable::~prohibitionTable()
{
    // Nothing to erase
}



prohibitionItem *prohibitionTable::findProhibitionByComponents(edgeItem *edgeOrigin, edgeItem *edgeDestiny)
{
    // Declare prohibition Aux
    prohibitionItem *pAux;

    // Iterate over list of items
    for(QList<eNetEditorItem *>::iterator i = iteratorTableBegin(); i != iteratorTableEnd(); i++)
    {
        // Cast prohibition item
        pAux = dynamic_cast<prohibitionItem *>(*i);

        // If node Origin and destiny are the same
        if(pAux->getEdgeProhibitionOrigin() == edgeOrigin && pAux->getEdgeProhibitionDestiny() == edgeDestiny)
        {
            // Return prohibition Aux
            return pAux;
        }
    }

    // If not exist, return NULL
    return NULL;
}
