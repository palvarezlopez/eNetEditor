#include "distributionFunctionTable.h"

// Configuration
#include "../configuration/items/distributionFunctionItemConfiguration.h"


distributionFunctionTable::distributionFunctionTable(const QString &newNameOfTable, distributionFunctionItemConfiguration *distributionFunctionItemC, eNetEditorDatabase *newDatabase) : eNetEditorTable(newNameOfTable, distributionFunctionItemC, newDatabase)
{

}

distributionFunctionTable::~distributionFunctionTable()
{

}

