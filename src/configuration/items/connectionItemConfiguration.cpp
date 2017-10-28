#include "connectionItemConfiguration.h"

connectionItemConfiguration::connectionItemConfiguration() : eNetEditorItemConfiguration()
{
    // Set item Extension
    setItemFileExtension("xml");

    // Set Item Altitude
    setItemAltitude(4);

    // Set item pen size
    setItemPenSize(0);

    // Set filename
    setItemFileName("connections");

    // Set Text font
    setItemTextFont("arial");

    // Set Text Size
    setItemTextSize(1);

    // Set Color
    setItemTextPenColor("green");

    // Set Text Pen size
    setItemTextPenSize(0);

    // Fill vector with the connection directions
    vectorOfConnectionDirections.push_back("s");
    vectorOfConnectionDirections.push_back("t");
    vectorOfConnectionDirections.push_back("l");
    vectorOfConnectionDirections.push_back("r");
    vectorOfConnectionDirections.push_back("L");
    vectorOfConnectionDirections.push_back("R");
    vectorOfConnectionDirections.push_back("invalid");

    // Fill vector with the connection states
    vectorOfConnectionStates.push_back('-');
    vectorOfConnectionStates.push_back('=');
    vectorOfConnectionStates.push_back('m');
    vectorOfConnectionStates.push_back('M');
    vectorOfConnectionStates.push_back('o');
    vectorOfConnectionStates.push_back('O');
    vectorOfConnectionStates.push_back('y');
    vectorOfConnectionStates.push_back('Y');
    vectorOfConnectionStates.push_back('r');
    vectorOfConnectionStates.push_back('g');
    vectorOfConnectionStates.push_back('G');

    // Set Connection defaults values
    connectionDefaultPass = false;
}

connectionItemConfiguration::~connectionItemConfiguration()
{
    // Nothing to erase
}

const QString &connectionItemConfiguration::getConnectionDirectionValue(connectionDirection cDirection) const
{
    return vectorOfConnectionDirections.at(cDirection);
}

char connectionItemConfiguration::getConnectionStatesValue(connectionState cState) const
{
    return vectorOfConnectionStates.at(cState);
}

bool connectionItemConfiguration::getConnectionDefaultPass() const
{
    return connectionDefaultPass;
}
