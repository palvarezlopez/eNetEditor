#include "abstractDetectorItem.h"

// Parameter Manager
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/detectors/abstractDetectorItemConfiguration.h"
#include "../../configuration/items/detectors/inductionLoopsE1DetectorItemConfiguration.h"


// Table
#include "../../database/eNetEditorTable.h"

// DataBase
#include "../../database/eNetEditorDatabase.h"

// Project
#include "../../project/eNetEditorProject.h"

// Parameter Manager
#include "../../project/itemManagerProject.h"

// Items
#include "../laneItem.h"
#include "../edges/edgeItem.h"
#include "../nodeItem.h"
#include "../flowMeasureItem.h"


abstractDetectorItem::abstractDetectorItem(eNetEditorTable *newItemTable, laneItem *newLaneOfDetector) : eNetEditorItem(newItemTable, "gold", "goldenrod")
{
    // Set pointer to lane Detector
    laneParent = newLaneOfDetector;

    // Set default pos
    pos = getProjectConfiguration()->getInductionLoopsE1DetectorItemConfiguration()->getDetectorDefaultPos();

    // Set default frecuency
    frequency = getProjectConfiguration()->getInductionLoopsE1DetectorItemConfiguration()->getDetectorDefaultFrequency();

    // Set default filename
    fileName = getProjectConfiguration()->getInductionLoopsE1DetectorItemConfiguration()->getDetectorDefaultFileNameOutput();
}

abstractDetectorItem::~abstractDetectorItem()
{
    // Nothing to remove
}

laneItem *abstractDetectorItem::getLaneParent() const
{
    return laneParent;
}

qreal abstractDetectorItem::getPosDetector() const
{
    return pos;
}

qreal abstractDetectorItem::getFrequency() const
{
    return frequency;
}

const QString &abstractDetectorItem::getFileName() const
{
    return fileName;
}

void abstractDetectorItem::setPosInLane(qreal newPos)
{
    if (newPos < laneParent->getEdgeParent()->getLength())
    {
        pos = newPos;
    }
}

void abstractDetectorItem::setFrequency(qreal newFrecuency)
{
    frequency = newFrecuency;
}

void abstractDetectorItem::setFileName(const QString &newFileName)
{
    fileName = newFileName;
}
