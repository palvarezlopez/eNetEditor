#include "multiEntryExitE3DetectorItemConfiguration.h"

multiEntryExitE3DetectorItemConfiguration::multiEntryExitE3DetectorItemConfiguration() : eNetEditorDetectorConfiguration()
{
    // Set Item Altitude
    setItemAltitude(4);

    // Set item pen size
    setItemPenSize(0);

    // Set filename
    setItemFileName("multiEntryExitDetectorsE3");

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
}

multiEntryExitE3DetectorItemConfiguration::~multiEntryExitE3DetectorItemConfiguration()
{
    // Nothing to erase
}
