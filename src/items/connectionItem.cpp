#include "connectionItem.h"

// Configuration
#include "../configuration/project/eNetEditorProjectConfiguration.h"
#include "../configuration/items/connectionItemConfiguration.h"

// Parameter Manager
#include "../project/itemManagerProject.h"

// Database
#include "../database/eNetEditorDatabase.h"
#include "../database/connectionTable.h"

// Items
#include "nodeItem.h"
#include "edges/edgeItem.h"
#include "laneItem.h"
#include "trafficLightItem.h"


connectionItem::connectionItem(laneItem *newLaneOrigin, laneItem *newLaneDestiny, eNetEditorDatabase *database) : eNetEditorItem(database->getConnectionTable())
{
    // Set lane origin (from)
    laneOrigin = newLaneOrigin;

    // Set lane destiny (to)
    laneDestiny = newLaneDestiny;

    // Set the pass parameter
    pass = getProjectConfiguration()->getConnectionItemConfiguration()->getConnectionDefaultPass();

    // Link node origin with connection
    nodeParent = laneOrigin->getEdgeParent()->getNodeDestiny();

    // Add actual connection to list of connections of node
    nodeParent->addConnection(this);

    // Add actual connection to list of outcomings connections of lane origin
    laneOrigin->addOutcomingConnection(this);

    // Add actual connection to list of incomings connections of lane destiny
    laneDestiny->addIncomingConnection(this);

    // Set pointer to traffic Light (if exist)
    tlight = laneOrigin->getEdgeParent()->getNodeDestiny()->getTrafficLight();

    // Set ID
    eNetEditorItem::setItemId("con_" +
                              laneOrigin->getEdgeParent()->getItemId() +
                              "[" + QString::number(laneOrigin->getIndex()) + "] -> " +
                              laneDestiny->getEdgeParent()->getItemId() +
                              "[" + QString::number(laneDestiny->getIndex()) + "]");

    // Set pen size
    setItemPen(getProjectConfiguration()->getConnectionItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getConnectionItemConfiguration()->getItemPenSize());

    // Set font
    setItemFontText(getProjectConfiguration()->getConnectionItemConfiguration()->getItemTextFont(), getProjectConfiguration()->getConnectionItemConfiguration()->getItemTextSize());

    // Set pen text size
    setItemPenText(getProjectConfiguration()->getConnectionItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getConnectionItemConfiguration()->getItemTextPenSize());

    // Item is a graphical item
    setItemGraphical(true, getProjectConfiguration()->getConnectionItemConfiguration()->getItemAltitude());

    // Update linkIndexLabel of all connections of node
    for(QList<connectionItem *>::iterator i = getNodeParent()->iteratorConnectionsBegin(); i != getNodeParent()->iteratorConnectionsEnd(); i++)
    {
        // Upate LinkIndexLabel
        (*i)->updateIndexLabel();
    }

    // Make connection
    make();
}

connectionItem::~connectionItem()
{
    // Delete pointers to incomings parents
    laneOrigin->removeOutcomingConnection(this);
    laneDestiny->removeIncomingConnection(this);

    // Delete pointer to node
    nodeParent->removeConnection(this);
}

void connectionItem::make()
{
    // Declare QPainterpath
    QPainterPath connectionPainterPath;

    // Declare components of the connection A->B->C->D
    QLineF lineA;

    // Declare components of the connection A->B->C->D
    QLineF lineB;

    // Declare components of the connection A->B->C->D
    QLineF lineC;

    // Declare components of the connection A->B->C->D
    QLineF lineD;

    // Declare middle line of the component A->B
    QLineF lineMiddleAB;

    // Declare middle line of the component C->D
    QLineF lineMiddleCD;

    // Declare variables for distances
    qreal distanceAB;
    qreal distanceCD;

    // Set points of the lineA
    lineA.setP1(mapFromItem(laneOrigin, laneOrigin->getConnectionLineFrontTop(this).p1()));
    lineA.setP2(mapFromItem(laneOrigin, laneOrigin->getConnectionLineFrontTop(this).p2()));

    // Set points of the lineB
    lineB.setP1(mapFromItem(laneDestiny, laneDestiny->getConnectionLineBackTop(this).p1()));
    lineB.setP2(mapFromItem(laneDestiny, laneDestiny->getConnectionLineBackTop(this).p2()));

    // Set points of the lineA
    lineC.setP1(mapFromItem(laneOrigin, laneOrigin->getConnectionLineFrontBottom(this).p1()));
    lineC.setP2(mapFromItem(laneOrigin, laneOrigin->getConnectionLineFrontBottom(this).p2()));

    // Set points of the lineB
    lineD.setP1(mapFromItem(laneDestiny, laneDestiny->getConnectionLineBackBottom(this).p1()));
    lineD.setP2(mapFromItem(laneDestiny, laneDestiny->getConnectionLineBackBottom(this).p2()));

    // Set points of middle Lines
    lineMiddleAB.setP1(lineA.p2());
    lineMiddleAB.setP2(lineB.p2());
    lineMiddleCD.setP1(lineC.p2());
    lineMiddleCD.setP2(lineD.p2());

    // Get lenghts of middle Lanes
    distanceAB = lineMiddleAB.length() * 0.5;
    distanceCD = lineMiddleCD.length() * 0.5;

    // Set lenghts of the lines
    lineA.setLength(lineA.length() + distanceAB);
    lineB.setLength(lineB.length() + distanceAB);
    lineC.setLength(lineC.length() + distanceCD);
    lineD.setLength(lineD.length() + distanceCD);

    // Move painterPath to start of lineMiddleAB
    connectionPainterPath.moveTo(lineMiddleAB.p1());

    // Draw a cubic bezier curve to lineMiddleAB using lineA.p2() and lineB.p2() as control points
    connectionPainterPath.cubicTo(lineA.p2(), lineB.p2(), lineMiddleAB.p2());

    // Draw a line to lineMiddleCD
    connectionPainterPath.lineTo(lineMiddleCD.p2());

    // Draw a cubic bezier curve to lineMiddleAB using lineD.p2() and lineC.p2() as control points
    connectionPainterPath.cubicTo(lineD.p2(), lineC.p2(), lineMiddleCD.p1());

    // Close Path
    connectionPainterPath.closeSubpath();

    // Set Path in the path Item
    connectionPath.setPath(connectionPainterPath);

    // Set Bounding Rect
    setBoundingRect(connectionPath.boundingRect());

    // Set color depending of the index
    /** Poner una llamada a función en ItemConfig **/
    if(getOriginIndex() % 11 == 0)
    {
        setItemFirstColor("lightgray");
        setItemSecondColor("darkgray");
    }
    else if(getOriginIndex() % 11 == 1)
    {
        setItemFirstColor("lightslategray");
        setItemSecondColor("darkslategray");
    }
    else if(getOriginIndex() % 11 == 2)
    {
        setItemFirstColor("lightsalmon");
        setItemSecondColor("darksalmon");
    }
    else if(getOriginIndex() % 11 == 3)
    {
        setItemFirstColor("lightslategrey");
        setItemSecondColor("darkslategrey");
    }
    else if(getOriginIndex() % 11 == 4)
    {
        setItemFirstColor("lightseagreen");
        setItemSecondColor("darkseagreen");
    }
    else if(getOriginIndex() % 11 == 5)
    {
        setItemFirstColor("lightsteelblue");
        setItemSecondColor("steelblue");
    }
    else if(getOriginIndex() % 11 == 6)
    {
        setItemFirstColor("lightpink");
        setItemSecondColor("deeppink");
    }
    else if(getOriginIndex() % 11 == 7)
    {
        setItemFirstColor("lightskyblue");
        setItemSecondColor("deepskyblue");
    }
    else if(getOriginIndex() % 11 == 8)
    {
        setItemFirstColor("mediumslateblue");
        setItemSecondColor("darkslateblue");
    }
    else if(getOriginIndex() % 11 == 9)
    {
        setItemFirstColor("mediumturquoise");
        setItemSecondColor("darkturquoise");
    }
    else if(getOriginIndex() % 11 == 10)
    {
        setItemFirstColor("lightcyan");
        setItemSecondColor("darkcyan");
    }

    // Reset Index
    indexRegardingNode = -1;

    // Declare counter
    int counter = 0;

    // Iterate over connection list
    for (QList<connectionItem *>::iterator i = nodeParent->iteratorConnectionsBegin(); (i != nodeParent->iteratorConnectionsEnd()) && (indexRegardingNode == -1); i++)
    {
        // If iterator == connection
        if((*i) == this)
        {
            // Set index
            indexRegardingNode = counter;
        }
        else
        {
            // Update counter
            counter++;
        }
    }
}

QDomElement connectionItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("connection");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement connectionItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("connection");

    // Set atribute from
    itemDomElement.setAttribute("from", laneOrigin->getEdgeParent()->getItemId());

    // Set atribute to
    itemDomElement.setAttribute("to", laneDestiny->getEdgeParent()->getItemId());

    // Set atribute fromLane
    itemDomElement.setAttribute("fromLane", QString::number(laneOrigin->getIndex()));

    // Set atribute toLane
    itemDomElement.setAttribute("toLane", QString::number(laneDestiny->getIndex()));

    // Set atribute pass
    if(pass == true)
    {
        itemDomElement.setAttribute("pass", "true");
    }
    else
    {
        itemDomElement.setAttribute("pass", "false");
    }
    /*
    // Set atribute keepClear
    itemDomElement.setAttribute(, QString::number());

    // Set atribute keepClear
    itemDomElement.uncontrolled(, QString::number());
    */
    // Return itemDomElement
    return itemDomElement;
}

void connectionItem::updateIndexLabel()
{
    // Set label of the item with the linKindex
    setItemLabel(QString::number(getIndexRegardingNode()) + "➜");
}

bool connectionItem::updateState(int index, char c)
{
    // If the index is valid
    if (vectorOfStates.size() < index)
    {
        if(c == 'G' || c == 'g' || c == 'y' || c == 'r')
        {
            // Add State
            vectorOfStates[index] = c;

            // State added, then return true
            return true;
        }
        else
        {
            // State not valid, then return false
            return false;
        }
    }
    else
    {
        // Index not valid, then return false
        return false;
    }
}



nodeItem *connectionItem::getNodeParent() const
{
    return nodeParent;
}

edgeItem *connectionItem::getEdgeOrigin() const
{
    return laneOrigin->getEdgeParent();
}

edgeItem *connectionItem::getEdgeDestiny() const
{
    return laneDestiny->getEdgeParent();
}

laneItem *connectionItem::getLaneOrigin() const
{
    return laneOrigin;
}

laneItem *connectionItem::getLaneDestiny() const
{
    return laneDestiny;
}

trafficLightItem *connectionItem::getTlight() const
{
    return tlight;
}

int connectionItem::getIndexRegardingNode() const
{
    return indexRegardingNode;
}

int connectionItem::getIndexRegardingLaneOrigin() const
{
    return indexRegardingLaneOrigin;
}

int connectionItem::getIndexRegardingLaneDestiny() const
{
    return indexRegardingLaneDestiny;
}

int connectionItem::getLinkIndex() const
{
    return linkIndex;
}

QVector<char> &connectionItem::getVectorOfStates()
{
    return vectorOfStates;
}

int connectionItem::getOriginIndex() const
{
    // Declare index
    int index = 0;

    // Iterate over list of incomingsconnections
    for (QList<connectionItem *>::iterator i = laneOrigin->iteratorOutcomingsConnectionsBegin(); i != laneOrigin->iteratorOutcomingsConnectionsEnd(); i++)
    {
        // If connection was founded
        if ((*i) == this)
        {
            // Return actual index
            return index;
        }
        else
        {
            // Update index
            index++;
        }
    }

    // Connection not founded, then return -1
    return -1;
}

int connectionItem::getDestinyIndex() const
{
    // Declare index
    int index = 0;

    // Iterate over list of incomingsconnections
    for (QList<connectionItem *>::iterator i = laneDestiny->iteratorIncomingsConnectionsBegin(); i != laneDestiny->iteratorIncomingsConnectionsEnd(); i++)
    {
        // If connection was founded
        if ((*i) == this)
        {
            // Return actual index
            return index;
        }
        else
        {
            // Update index
            index++;
        }
    }

    // Connection not founded, then return -1
    return -1;
}

int connectionItem::getOriginPos() const
{
    return laneDestiny->getNumberOfIncomingsConnections() - 1 - getOriginIndex();
}

int connectionItem::getDestinyPos() const
{
    return laneDestiny->getNumberOfIncomingsConnections() - 1 - getDestinyIndex();
}

void connectionItem::setItemId(const QString &newId)
{
    if(newId == "")
    {
        eNetEditorItem::setItemId("con_" +
                                  laneOrigin->getEdgeParent()->getItemId() +
                                  "[" + QString::number(laneOrigin->getIndex()) + "] -> " +
                                  laneDestiny->getEdgeParent()->getItemId() +
                                  "[" + QString::number(laneDestiny->getIndex()) + "]");
    }
    else
    {
        eNetEditorItem::setItemId(newId);
    }
}

void connectionItem::setTrafficLight(trafficLightItem *newTlight)
{
    tlight = newTlight;
}

void connectionItem::setPass(bool value)
{
    pass = value;
}

void connectionItem::setLinkIndex(int newLinkIndex)
{
    linkIndex = newLinkIndex;
}

void connectionItem::setVectorOfStates(const QVector<char> &newVectorOfStates)
{
    vectorOfStates = newVectorOfStates;
}

bool connectionItem::isPassEnabled()
{
    return pass;
}

void connectionItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // if Draw item is enabled (In general, and in this concrete element)
    if(getParameterManager()->isShowAllConnectionItems() /*&& isShowIntemEnabled()*/)
    {
        // Set brush
        if(isItemSelectable() && isItemMouseIn())
        {
            // Set Selected color if item is selectable and mouse is over item
            painter->setBrush(getItemColorSelected());
        }
        else if (isItemMarked())
        {
            // Set Marked color if item is selected
            painter->setBrush(getItemColorMarked());
        }
        else if (isItemMouseIn())
        {
            // Set first color if mouse is over item but isn't blocked
            painter->setBrush(getItemFirstColor());
        }
        else
        {
            // Set second color in the rest of cases
            painter->setBrush(getItemSecondColor());
        }

        // Set Pen
        painter->setPen(getItemPen());

        // Draw connection path
        painter->drawPath(connectionPath.path());

        // If flag ShowLabels is enabled
        if(getParameterManager()->isConnectionShowLabelEnabled())
        {
            // Set the modified font to the painter
            painter->setFont(getItemFontText());

            // Add pen to painter
            painter->setPen(getItemPenText());
            /*
                        // Traslate to start point of line A
                        painter->translate(lineA.p1());

                        // Rotate to adjust the arrow
                        painter->rotate(360.0 - lineA.angle());
            */
            // Traslat to adjust the label to center of connection
            painter->translate(QPointF(0, -0.58));

            // Scale the painter to draw te label a little bit small
            painter->scale(0.35 , 0.35);

            // Draw connection Label
            painter->drawStaticText(QPointF(0, 0), getItemLabel());
        }
    }
}

void connectionItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath connectionItem::shape() const
{
    // Declare QPainterPath
    QPainterPath path;

    // If the item isn't blocked
    if(getParameterManager()->isConnectionBlocked() == false)
    {
        // Add path
        path.addPath(connectionPath.path());
    }

    // Return PainterPath from ConnectionPath
    return path;
}
