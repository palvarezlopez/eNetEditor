#include "inductionLoopsE1DetectorItemConfiguration.h"

inductionLoopsE1DetectorItemConfiguration::inductionLoopsE1DetectorItemConfiguration() : eNetEditorDetectorConfiguration()
{
    // Set Item Altitude
    setItemAltitude(4);

    // Set item pen size
    setItemPenSize(0);

    // Set filename
    setItemFileName("inductionLoopsDetectorsE1");

    // Set extension
    setItemFileExtension("xml");

    // Set Text font
    setItemTextFont("arial");

    // Set Text Size
    setItemTextSize(1);

    // Set Color
    setItemTextPenColor("white");

    // Set Text Pen size
    setItemTextPenSize(0);

    // Set InductionLoopsE1DetectorItem default parameters
    inductionLoopsE1DetectorItemDefaultDetectorDefinitionsFileName = "detectorDefinitions";
    inductionLoopsE1DetectorItemDefaultDetectorDefinitionsExtension = "xml";
    inductionLoopsE1DetectorItemDefaultFriendlyPos = false;
    inductionLoopsE1DetectorItemDefaultSplitByType = false;
}

inductionLoopsE1DetectorItemConfiguration::~inductionLoopsE1DetectorItemConfiguration()
{
    // Nothing to erase
}

const QString &inductionLoopsE1DetectorItemConfiguration::getInductionLoopsE1DetectorItemDefaultDetectorDefinitionsFileName()
{
    return inductionLoopsE1DetectorItemDefaultDetectorDefinitionsFileName;
}

const QString &inductionLoopsE1DetectorItemConfiguration::getInductionLoopsE1DetectorItemDefaultDetectorDefinitionsExtension()
{
    return inductionLoopsE1DetectorItemDefaultDetectorDefinitionsExtension;
}

QString inductionLoopsE1DetectorItemConfiguration::getInductionLoopsE1DetectorItemDefaultDetectorDefinitionsFileNameWithExtension()
{
    return QString(inductionLoopsE1DetectorItemDefaultDetectorDefinitionsFileName + "." + inductionLoopsE1DetectorItemDefaultDetectorDefinitionsExtension);
}

bool inductionLoopsE1DetectorItemConfiguration::getInductionLoopsE1DetectorItemDefaultFriendlyPos() const
{
    return inductionLoopsE1DetectorItemDefaultFriendlyPos;
}

bool inductionLoopsE1DetectorItemConfiguration::getInductionLoopsE1DetectorItemDefaultSplitByType() const
{
    return inductionLoopsE1DetectorItemDefaultSplitByType;
}


