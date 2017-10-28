#include "abstractDetectorTable.h"

// Configuration
#include "../../configuration/items/detectors/abstractDetectorItemConfiguration.h"

// Items
#include "../../items/detectors/abstractDetectorItem.h"
#include "../../items/laneItem.h"


abstractDetectorTable::abstractDetectorTable(const QString &newNameOfTable, eNetEditorDetectorConfiguration *eNetEditorDetectorItemC, eNetEditorDatabase *newDatabase) : eNetEditorTable(newNameOfTable, eNetEditorDetectorItemC, newDatabase)
{
    // Set index to 0
    index = 0;
}

abstractDetectorTable::~abstractDetectorTable()
{
    // Nothing to erase
}

void abstractDetectorTable::resetIndex()
{
    index = 0;
}

void abstractDetectorTable::updateIndex()
{
    index++;
}

void abstractDetectorTable::setIndex(int newIndex)
{
    index = newIndex;
}

