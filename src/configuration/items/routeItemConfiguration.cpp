#include "routeItemConfiguration.h"

routeItemConfiguration::routeItemConfiguration() : eNetEditorItemConfiguration()
{
    // Set item Extension
    setItemFileExtension("xml");

    // Set Item Altitude
    setItemAltitude(4);

    // Set item pen size
    setItemPenSize(0);

    // Set filename
    setItemFileName("routes");

    // Set Text font
    setItemTextFont("arial");

    // Set Text Size
    setItemTextSize(1);

    // Set Color
    setItemTextPenColor("black");

    // Set Text Pen size
    setItemTextPenSize(0);

    // Set default Route parameters
    routeDefaultColor = "red";
}

routeItemConfiguration::~routeItemConfiguration()
{
    // Nothing to erase
}

QString routeItemConfiguration::getRouteDefaultColor() const
{
    return routeDefaultColor;
}

