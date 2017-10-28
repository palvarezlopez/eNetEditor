#include "edgeItemConfiguration.h"

edgeItemConfiguration::edgeItemConfiguration() : eNetEditorEdgeConfiguration()
{
    // Set item Extension
    setItemFileExtension("xml");

    // Set Item Altitude
    setItemAltitude(2);

    // Set item pen size
    setItemPenSize(0);

    // Set filename
    setItemFileName("edges");

    // Set Text font
    setItemTextFont("arial");

    // Set Text Size
    setItemTextSize(1);

    // Set Color
    setItemTextPenColor("white");

    // Set Text Pen size
    setItemTextPenSize(0);

    // Set Vector of edge spread types
    vectorOfEdgeSpreadTypes.push_back("center");
    vectorOfEdgeSpreadTypes.push_back("right");

    // Set Sizes
    edgeWidth = 2;
    edgeOffset = 0.5;
    edgeIconOffset = 0.3;

    // Set Edge defaults Parameters
    edgeItemDefaultShape = "";
    edgeItemDefaultSpreadTyp = edgeSpreadTypeRight;
    edgeItemDefaultWidth = 3;
    edgeItemDefaultName = "";
    edgeItemDefaultEndOffset = -1;
}

edgeItemConfiguration::~edgeItemConfiguration()
{
    // Nothing to erase
}

const QString &edgeItemConfiguration::getEdgeSpreadTypeValue(edgeSpreadType index)
{
    return vectorOfEdgeSpreadTypes.at(index);
}

qreal edgeItemConfiguration::getEdgeWidth() const
{
    return edgeWidth;
}

qreal edgeItemConfiguration::getEdgeOffset() const
{
    return edgeOffset;
}

qreal edgeItemConfiguration::getEdgeIconOffset() const
{
    return edgeIconOffset;
}

QString edgeItemConfiguration::getEdgeItemDefaultShape() const
{
    return edgeItemDefaultShape;
}

edgeSpreadType edgeItemConfiguration::getEdgeItemDefaultSpreadTyp() const
{
    return edgeItemDefaultSpreadTyp;
}

qreal edgeItemConfiguration::getEdgeItemDefaultWidth() const
{
    return edgeItemDefaultWidth;
}

QString edgeItemConfiguration::getEdgeItemDefaultName() const
{
    return edgeItemDefaultName;
}

qreal edgeItemConfiguration::getEdgeItemDefaultEndOffset() const
{
    return edgeItemDefaultEndOffset;
}
