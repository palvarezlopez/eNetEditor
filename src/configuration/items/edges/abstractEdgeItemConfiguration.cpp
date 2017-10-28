#include "abstractEdgeItemConfiguration.h"

eNetEditorEdgeConfiguration::eNetEditorEdgeConfiguration() : eNetEditorItemConfiguration()
{
    // Comprobar

    edgeDefaultPriority = 1;

    edgeDefaultSpeed = 50;

    edgeDefaultSidewalkWidth = 0;
}

eNetEditorEdgeConfiguration::~eNetEditorEdgeConfiguration()
{

}

int eNetEditorEdgeConfiguration::getEdgeDefaultPriority() const
{
    return edgeDefaultPriority;
}

qreal eNetEditorEdgeConfiguration::getEdgeDefaultSpeed() const
{
    return edgeDefaultSpeed;
}

qreal eNetEditorEdgeConfiguration::getEdgeDefaultSidewalkWidth() const
{
    return edgeDefaultSidewalkWidth;
}
