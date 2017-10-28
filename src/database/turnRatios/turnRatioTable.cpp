#include "turnRatioTable.h"

// Configuration
#include "../../configuration/items/turnRatios/turnRatioItemConfiguration.h"

// Items

turnRatioTable::turnRatioTable(const QString &newNameOfTable, turnRatioItemConfiguration *turnRatioItemC, eNetEditorDatabase *newDatabase) : eNetEditorTable(newNameOfTable, turnRatioItemC, newDatabase)
{

}

turnRatioTable::~turnRatioTable()
{

}
