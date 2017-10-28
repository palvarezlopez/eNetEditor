#include "nodeItemConfiguration.h"

nodeItemConfiguration::nodeItemConfiguration() : eNetEditorItemConfiguration()
{
    // Set item Extension
    setItemFileExtension("xml");

    // Set Item Altitude
    setItemAltitude(3);

    // Set item pen size
    setItemPenSize(0);

    // Set filename
    setItemFileName("nodes");

    // Set Text font
    setItemTextFont("arial");

    // Set Text Size
    setItemTextSize(1);

    // Set Color
    setItemTextPenColor("white");

    // Set Text Pen size
    setItemTextPenSize(0);

    // Declare Pixmap pointer
    QPixmap *p;

    // Create and Insert every node icons in the map
    p = new QPixmap(":/items/trafficSigns/nodePriority.png");
    mapOfNodeIcons.insert(nodeItemTypePriority, p);

    p = new QPixmap(":/items/trafficSigns/nodeTrafficLight.png");
    mapOfNodeIcons.insert(nodeItemTypeTrafficLight, p);

    p = new QPixmap(":/items/trafficSigns/nodeRightBeforeLeft.png");
    mapOfNodeIcons.insert(nodeItemTypeRightBeforeLeft, p);

    p = new QPixmap(":/items/trafficSigns/nodeUnregulated.png");
    mapOfNodeIcons.insert(nodeItemTypeUnregulated, p);

    p = new QPixmap(":/items/trafficSigns/nodePriorityStop.png");
    mapOfNodeIcons.insert(nodeItemTypePriorityStop, p);

    p = new QPixmap(":/items/trafficSigns/nodeTrafficLightUnregulated.png");
    mapOfNodeIcons.insert(nodeItemTypeTrafficLightUnregulated, p);

    p = new QPixmap(":/items/trafficSigns/nodeAllwayStop.png");
    mapOfNodeIcons.insert(nodeItemTypeAllwayStop, p);

    // Fill vector of node types
    vectorOfNodeTypes.push_back("priority");
    vectorOfNodeTypes.push_back("traffic_light");
    vectorOfNodeTypes.push_back("right_before_left");
    vectorOfNodeTypes.push_back("unregulated");
    vectorOfNodeTypes.push_back("priority_stop");
    vectorOfNodeTypes.push_back("traffic_light_unregulated");
    vectorOfNodeTypes.push_back("allway_stop");
    vectorOfNodeTypes.push_back("rail_signal");

    // Set node defaults parameters
    nodeDefaultPosz = 0;
    nodeDefaultType = nodeItemTypePriority;
}

nodeItemConfiguration::~nodeItemConfiguration()
{
    // Clear icons
    for(QMap<nodeItemType, QPixmap *>::iterator i = mapOfNodeIcons.begin(); i != mapOfNodeIcons.end(); i++)
    {
        delete (*i);
    }
}

QPixmap *nodeItemConfiguration::NodeSignalIcon(nodeItemType type) const
{
    return mapOfNodeIcons[type];
}

const QString &nodeItemConfiguration::getNodeTypeValue(nodeItemType type) const
{
    return vectorOfNodeTypes.at(type);
}

qreal nodeItemConfiguration::getNodeDefaultPosz() const
{
    return nodeDefaultPosz;
}

nodeItemType nodeItemConfiguration::getNodeDefaultType() const
{
    return nodeDefaultType;
}
