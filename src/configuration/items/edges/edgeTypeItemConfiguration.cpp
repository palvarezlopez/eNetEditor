#include "edgeTypeItemConfiguration.h"

edgeTypeItemConfiguration::edgeTypeItemConfiguration() : eNetEditorEdgeConfiguration()
{
    // Set item Extension
    setItemFileExtension("xml");

    // Set filename
    setItemFileName("edgeTypes");

    // Set defaults parameters
    discard = false;
    oneway = false;
}

edgeTypeItemConfiguration::~edgeTypeItemConfiguration()
{
    // Nothing to erase
}

bool edgeTypeItemConfiguration::getOneway() const
{
    return oneway;
}

bool edgeTypeItemConfiguration::getDiscard() const
{
    return discard;
}

