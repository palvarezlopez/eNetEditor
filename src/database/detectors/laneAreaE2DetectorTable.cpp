#include "laneAreaE2DetectorTable.h"

// Configuration
#include "../../configuration/items/detectors/laneAreaE2DetectorItemConfiguration.h"

// Items


laneAreaE2DetectorTable::laneAreaE2DetectorTable(const QString &newNameOfTable, laneAreaE2DetectorItemConfiguration *laneAreaE2DetectorItemC, eNetEditorDatabase *newDatabase) : abstractDetectorTable(newNameOfTable, laneAreaE2DetectorItemC, newDatabase)
{
    /*
    // Set default Pos
    pos = getItemsConfiguration()->get->getDetectorDefaultPos();

    // Set default frecuency
    frequency = getItemConfiguration()->getDetectorDefaultFrequency();

    // Set default filename
    fileName = getItemConfiguration()->getDetectorDefaultFileName();
    */
}

laneAreaE2DetectorTable::~laneAreaE2DetectorTable()
{

}
