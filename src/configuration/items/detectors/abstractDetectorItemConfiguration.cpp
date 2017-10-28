#include "abstractDetectorItemConfiguration.h"

eNetEditorDetectorConfiguration::eNetEditorDetectorConfiguration() : eNetEditorItemConfiguration()
{
    // Set detectors default parameters
    detectorDefaultPos = 0;
    detectorDefaultFrequency = 1;
    detectorDefaultFileNameOutput = "";
}

eNetEditorDetectorConfiguration::~eNetEditorDetectorConfiguration()
{
    // Nothing to erase
}



qreal eNetEditorDetectorConfiguration::getDetectorDefaultPos() const
{
    return detectorDefaultPos;
}

int eNetEditorDetectorConfiguration::getDetectorDefaultFrequency() const
{
    return detectorDefaultFrequency;
}

const QString &eNetEditorDetectorConfiguration::getDetectorDefaultFileNameOutput() const
{
    return detectorDefaultFileNameOutput;
}

