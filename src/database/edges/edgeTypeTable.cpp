#include "edgeTypeTable.h"

// Configuration
#include "../../configuration/items/edges/edgeTypeItemConfiguration.h"

// Items
#include "../../items/edges/edgeTypeItem.h"


edgeTypeTable::edgeTypeTable(const QString &newNameOfTable, edgeTypeItemConfiguration *edgeTypeItemC, eNetEditorDatabase *newDatabase) : abstractEdgeTable(newNameOfTable, edgeTypeItemC, newDatabase)
{
    // Nothing to declare
}

edgeTypeTable::~edgeTypeTable()
{
    // Nothing to do
}

