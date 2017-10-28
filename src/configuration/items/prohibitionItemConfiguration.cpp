#include "prohibitionItemConfiguration.h"

prohibitionItemConfiguration::prohibitionItemConfiguration() : eNetEditorItemConfiguration()
{
    // Set item Extension
    setItemFileExtension("xml");

    // Set Item Altitude
    setItemAltitude(4);

    // Set item pen size
    setItemPenSize(0);

    // Set filename
    setItemFileName("prohibitions");

    // Set Text font
    setItemTextFont("arial");

    // Set Text Size
    setItemTextSize(1);

    // Set Color
    setItemTextPenColor("black");

    // Set Text Pen size
    setItemTextPenSize(0);
}

prohibitionItemConfiguration::~prohibitionItemConfiguration()
{
    // Nothing to erase
}

