#include "routeItem.h"

// Configuration
#include "../configuration/project/eNetEditorProjectConfiguration.h"
#include "../configuration/items/routeItemConfiguration.h"

// Parameter Manager
#include "../project/itemManagerProject.h"

// Database
#include "../database/eNetEditorDatabase.h"
#include "../database/routeTable.h"

// Items
#include "edges/edgeItem.h"
#include "routeItem.h"


routeItem::routeItem(const QString &newId, edgeItem *newEdgeOrigin, edgeItem *newEdgeDestiny, eNetEditorDatabase *database) : eNetEditorItem(database->getRouteTable(), "black", "black")
{
    // Set the new id of route
    eNetEditorItem::setItemId(newId);

    // Set the new color of route
    color = getProjectConfiguration()->getRouteItemConfiguration()->getRouteDefaultColor();

    // Create lists
    listOfEdges = new QList<edgeItem *>;
    listOfVehicles = new QList<vehicleItem *>;
    listOfFlows = new QList<flowItem *>;

    // Set pen size
    setItemPen(getProjectConfiguration()->getRouteItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getRouteItemConfiguration()->getItemPenSize());

    // Set font
    setItemFontText(getProjectConfiguration()->getRouteItemConfiguration()->getItemTextFont(), getProjectConfiguration()->getRouteItemConfiguration()->getItemTextSize());

    // Set pen text size
    setItemPenText(getProjectConfiguration()->getRouteItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getRouteItemConfiguration()->getItemTextPenSize());

    // Item is a graphical item
    setItemGraphical(true, getProjectConfiguration()->getRouteItemConfiguration()->getItemAltitude());

    /**


        // if the route ID Is not defined
        if(newID == "")
        {
            // Set the correspond index to maintain the integrity
            r->setItemId("route" + QString::number(counter));

            // Update nextIndex
            counter++;
        }

        // Add first edge
        r->addEdge(firstEdge);

        // Add second Edge
        r->addEdge(secondEdge);

        // Add route to the scene
        getDatabase()->geteNetEditorScene()->addItem(r);

        // Set position Z of the route
        r->setZValue(getDatabase()->geteNetEditorScene()->getProject()->geteNetEditorMainWindow()->geteNetEditorConfiguration()->getProjectConfiguration()->getRouteItemConfiguration()->getItemAltitude());

        // When a route is created, flag "route" is activated, then is NOT selectable
        r->setItemSelectable(false);

        // Add node to Container
        rTable.push_back(r);

    **/

    // Add edges to route
    listOfEdges->push_back(newEdgeOrigin);
    listOfEdges->push_back(newEdgeDestiny);

    // Make route
    make();
}

routeItem::~routeItem()
{
    // Remove route of edges
    for(QList<edgeItem *>::iterator i = listOfEdges->begin(); i != listOfEdges->end(); i++)
    {
        // Remove route of edge
        (*i)->removeRoute(this);
    }

    // Delete lists
    delete listOfEdges;
    delete listOfVehicles;
    delete listOfFlows;
}

void routeItem::make()
{
    // Declare QPainterpath
    QPainterPath routePainterPath;

    // Declare point with the widht of the Route
    QPointF routeWidth(0, 0.125);
    QPointF intersection;
    QLineF segmentATop;
    QLineF segmentBTop;
    QLineF segmentABTop;
    QLineF segmentABot;
    QLineF segmentBBot;
    QLineF segmentABBot;
    QLineF segmentAux1;
    QLineF segmentAux2;

    QList<QPointF> listOfTopPoints;
    QList<QPointF> listOfBotPoints;

    listOfTopPoints.push_back(mapFromItem(listOfEdges->first(), listOfEdges->first()->getCentralLine().p1() + routeWidth /*+ QPointF(0, -1 + offsetOrigin)*/));
    listOfBotPoints.push_front(mapFromItem(listOfEdges->first(), listOfEdges->first()->getCentralLine().p1() - routeWidth /*+ QPointF(0, -1 + offsetOrigin)*/));


    for (QList<edgeItem *>::iterator i = listOfEdges->begin(); i != listOfEdges->end(); i++)
    {
        if ((i + 1) != listOfEdges->end())
        {
            // Get top segment of the actual line
            segmentATop.setP1(mapFromItem((*i), (*i)->getCentralLine().p1() + routeWidth /*+ QPointF(0, -1 + offsetOrigin)*/));
            segmentATop.setP2(mapFromItem((*i), (*i)->getCentralLine().p2() + routeWidth /*+ QPointF(1, -1 + offsetOrigin)*/));

            // Get top segment of the next line
            segmentBTop.setP1(mapFromItem((*(i + 1)), (*(i + 1))->getCentralLine().p1() + routeWidth /*+ QPointF(0, -1 + offsetOrigin)*/));
            segmentBTop.setP2(mapFromItem((*(i + 1)), (*(i + 1))->getCentralLine().p2() + routeWidth /*+ QPointF(1, -1 + offsetOrigin)*/));

            // Get bot segment of the actual line
            segmentABot.setP1(mapFromItem((*i), (*i)->getCentralLine().p1() - routeWidth /*+ QPointF(0, -1 + offsetOrigin)*/));
            segmentABot.setP2(mapFromItem((*i), (*i)->getCentralLine().p2() - routeWidth /*+ QPointF(1, -1 + offsetOrigin)*/));

            // Get bot segment of the next line
            segmentBBot.setP1(mapFromItem((*(i + 1)), (*(i + 1))->getCentralLine().p1() - routeWidth /*+ QPointF(0, -1 + offsetOrigin)*/));
            segmentBBot.setP2(mapFromItem((*(i + 1)), (*(i + 1))->getCentralLine().p2() - routeWidth /*+ QPointF(1, -1 + offsetOrigin)*/));

            // Get Mid Segment between lines
            segmentAux1.setP1(mapFromItem((*i), (*i)->getCentralLine().p2() /*+ QPointF(0, -1 + offsetOrigin)*/));
            segmentAux1.setP2(mapFromItem((*(i + 1)), (*(i + 1))->getCentralLine().p1() /*+ QPointF(1, -1 + offsetOrigin)*/));

            // Set lenght of the new line
            segmentAux1.setLength(0.125);

            // Get Mid Segment between lines
            segmentAux2.setP1(mapFromItem((*(i + 1)), (*(i + 1))->getCentralLine().p1() /*- routeWidth + QPointF(1, -1 + offsetOrigin)*/));
            segmentAux2.setP2(mapFromItem((*i), (*i)->getCentralLine().p2() /*- routeWidth + QPointF(0, -1 + offsetOrigin)*/));

            // Set lenght of the new line
            segmentAux2.setLength(0.125);

            // Rotate 90º aux1
            segmentAux1 = segmentAux1.normalVector();

            // Rotate 270º aux2
            segmentAux2 = segmentAux2.normalVector().normalVector().normalVector();

            // Create segment AB top
            segmentABBot.setP1(segmentAux1.p2());
            segmentABBot.setP2(segmentAux2.p2());

            // Rotate 180º aux1 and aux2
            segmentAux1 = segmentAux1.normalVector().normalVector();
            segmentAux2 = segmentAux2.normalVector().normalVector();

            // Create segment AB bot
            segmentABTop.setP1(segmentAux1.p2());
            segmentABTop.setP2(segmentAux2.p2());

            // Calculate top points
            if(segmentATop.intersect(segmentBTop, &intersection) == QLineF::BoundedIntersection)
            {
                listOfTopPoints.push_back(intersection);
            }
            else
            {
                segmentATop.intersect(segmentABTop, &intersection);

                listOfTopPoints.push_back(intersection);

                segmentABTop.intersect(segmentBTop, &intersection);

                listOfTopPoints.push_back(intersection);
            }

            // Calculate bot points
            if(segmentABot.intersect(segmentBBot, &intersection) == QLineF::BoundedIntersection)
            {
                listOfBotPoints.push_front(intersection);
            }
            else
            {
                segmentABot.intersect(segmentABBot, &intersection);

                listOfBotPoints.push_front(intersection);

                segmentABBot.intersect(segmentBBot, &intersection);

                listOfBotPoints.push_front(intersection);
            }
        }
        else
        {
            // Add the last points
            listOfTopPoints.push_back(mapFromItem(listOfEdges->last(), listOfEdges->last()->getCentralLine().p1() + routeWidth /* + QPointF(0, -1 + offsetOrigin)*/));
            listOfTopPoints.push_back(mapFromItem(listOfEdges->last(), listOfEdges->last()->getCentralLine().p2() + routeWidth /* + QPointF(0, -1 + offsetOrigin)*/));

            listOfBotPoints.push_front(mapFromItem(listOfEdges->last(), listOfEdges->last()->getCentralLine().p1() - routeWidth /* + QPointF(0, -1 + offsetOrigin)*/));
            listOfBotPoints.push_front(mapFromItem(listOfEdges->last(), listOfEdges->last()->getCentralLine().p2() - routeWidth /* + QPointF(0, -1 + offsetOrigin)*/));
        }
    }

    // Mix both lists
    listOfTopPoints += listOfBotPoints;

    // Set position of the first point
    routePainterPath.moveTo(listOfTopPoints.first());

    // Create lines
    for (QList<QPointF>::iterator i = listOfTopPoints.begin(); i != listOfTopPoints.end(); i++)
    {
        routePainterPath.lineTo(*i);
    }

    // Close subpat
    routePainterPath.closeSubpath();

    // Set Path in the path Item
    routePath.setPath(routePainterPath);

    // Set Bounding Rect
    setBoundingRect(routePath.boundingRect());

    // Set colors only if the list of edges is not empty
    if(!listOfEdges->empty())
    {
        // Set color depending of the index
        if(listOfEdges->first()->getNumberOfRoutes() % 7 == 0)
        {
            setItemFirstColor("darkorchid");
            setItemSecondColor("mediumorchid");
        }
        else if(listOfEdges->first()->getNumberOfRoutes() % 7 == 1)
        {
            setItemFirstColor("coral");
            setItemSecondColor("lightcoral");
        }
        else if(listOfEdges->first()->getNumberOfRoutes() % 7 == 2)
        {
            setItemFirstColor("darkgoldenrod");
            setItemSecondColor("goldenrod");
        }
        else if(listOfEdges->first()->getNumberOfRoutes() % 7 == 3)
        {
            setItemFirstColor("darkslategrey");
            setItemSecondColor("lightslategrey");
        }
        else if(listOfEdges->first()->getNumberOfRoutes() % 7 == 4)
        {
            setItemFirstColor("darkgrey");
            setItemSecondColor("grey");
        }
        else if(listOfEdges->first()->getNumberOfRoutes() % 7 == 5)
        {
            setItemFirstColor("steelblue");
            setItemSecondColor("lightsteelblue");
        }
        else if(listOfEdges->first()->getNumberOfRoutes() % 7 == 6)
        {
            setItemFirstColor("darkviolet");
            setItemSecondColor("violet");
        }
    }
}

QDomElement routeItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("route");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement routeItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("route");

    // Set atribute id
    itemDomElement.setAttribute("id", getItemId());

    // Set atribute color
    itemDomElement.setAttribute("color", color);

    // Declare QStringList for the Edges Id's
    QString listOfEdgeIds;

    // Iterate over list of edges
    for (QList<edgeItem *>::iterator i = listOfEdges->begin(); i != listOfEdges->end(); i++)
    {
        // Keep Edge ID
        listOfEdgeIds.append((*i)->getItemId() + " ");
    }

    // Remove last Space
    listOfEdgeIds.remove(listOfEdgeIds.size() - 1, 1);

    // Set atribute listOfEdges
    itemDomElement.setAttribute("edges", listOfEdgeIds);

    // Return itemDomElement
    return itemDomElement;
}

bool routeItem::addEdge(edgeItem *e)
{
    // If edge != NULL
    if (e != NULL)
    {
        // Insert edge in the list of edges
        listOfEdges->push_back(e);

        // Insert edge in the interne list of edge
        e->addRoute(this);

        make();

        // edge added, then return true
        return true;
    }
    else
    {
        // edge NULL, then return false;
        return false;
    }

}

bool routeItem::removeEdge(edgeItem *e)
{
    // If edge != NULL
    if (e != NULL)
    {
        // Remove edge of list of edges
        listOfEdges->removeAll(e);

        // Remove route of edge
        e->removeRoute(this);

        // edge removed, then return true
        return true;
    }
    else
    {
        // Edge Null, then return false
        return false;
    }
}

void routeItem::addVehicle(vehicleItem *v)
{
    listOfVehicles->push_back(v);
}

void routeItem::removeVehicle(vehicleItem *v)
{
    listOfVehicles->removeAll(v);
}

void routeItem::addFlow(flowItem *f)
{
    listOfFlows->push_back(f);
}

void routeItem::removeFlow(flowItem *f)
{
    listOfFlows->removeAll(f);
}



const QString &routeItem::getColor() const
{
    return color;
}

QList<edgeItem *> *routeItem::getListOfEdges() const
{
    return listOfEdges;
}

QList<vehicleItem *> *routeItem::getListOfVehicles() const
{
    return listOfVehicles;
}

QList<flowItem *> *routeItem::getListOfFlows() const
{
    return listOfFlows;
}



void routeItem::setColor(const QString &newColor)
{
    color = newColor;
}

void routeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // if Draw item is enabled (In the general manager an for this concrete element)
    if(getParameterManager()->isShowAllRouteItems())
    {
        // Set brush
        if(isItemSelectable() && isItemMouseIn())
        {
            // Set Selected color if item is selected
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

        // Draw route
        painter->drawPath(routePath.path());
    }
}

void routeItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath routeItem::shape() const
{
    // Declare QPainterPath
    QPainterPath path;

    // If the item isn't blocked
    if(getParameterManager()->isRouteBlocked() == false)
    {
        // Add path
        path.addPath(routePath.path());
    }

    // Return new path
    return path;
}
