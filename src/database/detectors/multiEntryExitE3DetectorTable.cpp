#include "multiEntryExitE3DetectorTable.h"

// Configuration
#include "../../configuration/items/detectors/multiEntryExitE3DetectorItemConfiguration.h"

// Items



multiEntryExitE3DetectorTable::multiEntryExitE3DetectorTable(const QString &newNameOfTable, multiEntryExitE3DetectorItemConfiguration *multiEntryExitE3DetectorItemC, eNetEditorDatabase *newDatabase) : abstractDetectorTable(newNameOfTable, multiEntryExitE3DetectorItemC, newDatabase)
{
    /*
    // Set default Pos
    pos = getItemsConfiguration()-> ->getDetectorDefaultPos();

    // Set default frecuency
    frequency = getItemConfiguration()->getDetectorDefaultFrequency();

    // Set default filename
    fileName = getItemConfiguration()->getDetectorDefaultFileName();
    */
}

multiEntryExitE3DetectorTable::~multiEntryExitE3DetectorTable()
{

}
