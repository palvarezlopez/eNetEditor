#include "laneItem.h"

// Configuration
#include "../configuration/project/eNetEditorProjectConfiguration.h"
#include "../configuration/items/laneItemConfiguration.h"
#include "../configuration/items/edges/edgeItemConfiguration.h"
#include "../configuration/items/vehicleTypeItemConfiguration.h"

// Parameter Manager
#include "../project/itemManagerProject.h"

// Database
#include "../database/eNetEditorDatabase.h"
#include "../database/laneTable.h"

// Items
#include "edges/edgeItem.h"
#include "nodeItem.h"
#include "vehicleTypeItem.h"
#include "connectionItem.h"
#include "prohibitionItem.h"
#include "stops/busStopItem.h"
#include "stops/chargingStationItem.h"
#include "detectors/inductionLoopsE1DetectorItem.h"
#include "detectors/laneAreaE2DetectorItem.h"
#include "detectors/multiEntryExitE3DetectorItem.h"


laneItem::laneItem(edgeItem *newEdgeParent, eNetEditorDatabase *database) : eNetEditorItem(database->getLaneTable(), "gray", "black")
{
    // Set edge Parent
    edgeParent = newEdgeParent;

    /** ATENCION: Poner estos dos parametros de abajo en la lane configuration **/

    // Set Speed
    speed = getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeDefaultSpeed();

    // Set width
    width = getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeItemDefaultWidth();

    // Set default allowed vehicles
    allowedVehicles = new QList<vehicleClass>(getProjectConfiguration()->getLaneItemConfiguration()->getLaneDefaultListOfAllowedVehicles());

    // Set default disallowed vehicles
    disallowedVehicles = new QList<vehicleClass>(getProjectConfiguration()->getLaneItemConfiguration()->getLaneDefaultListOfDisallowedVehicles());

    // Add item to list of lanes of edge
    edgeParent->addLane(this);

    // Set Id
    eNetEditorItem::setItemId(edgeParent->getItemId() + "_" + QString::number(getIndex()));

    // Set pen size
    setItemPen(getProjectConfiguration()->getLaneItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getLaneItemConfiguration()->getItemPenSize());

    // Set font
    setItemFontText(getProjectConfiguration()->getLaneItemConfiguration()->getItemTextFont(), getProjectConfiguration()->getLaneItemConfiguration()->getItemTextSize());

    // Set pen text size
    setItemPenText(getProjectConfiguration()->getLaneItemConfiguration()->getItemPenColor(), getProjectConfiguration()->getLaneItemConfiguration()->getItemTextPenSize());

    // Item is a graphical item
    setItemGraphical(true, getProjectConfiguration()->getEdgeItemConfiguration()->getItemAltitude());

    // Make origin nodes
    edgeParent->getNodeOrigin()->make();
    edgeParent->getNodeDestiny()->make();
}

laneItem::~laneItem()
{
    // Clear incoming connections
    clearIncomingConnection();

    //Cclear outcoming connections
    clearOutcomingConnection();

    // Clear incoming prohibitions
    clearIncomingProhibition();

    // Clear outcoming prohibitions
    clearOutcomingProhibition();

    // Clear busstops
    clearBusStop();

    // Clear charging stations
    clearChargingStation();

    // Clear induction Loops E1 detectors
    clearInductionLoopsE1Detector();

    // Clear laneAreaE2 Detectors
    clearLaneAreaE2Detector();

    // Clear multi Entry Exit Detectors
    clearMultiEntryExitE3Detector();

    // Erase lane of their edge parent
    edgeParent->removeLane(this);

    // Delete vehicles
    delete allowedVehicles;
    delete disallowedVehicles;
}

void laneItem::make()
{
    // Move matrix to center of Node origin
    setPos(edgeParent->getNodeOrigin()->pos());

    // Do a rotation using as reference the position of both nodes
    setRotation(360.0 - QLineF(edgeParent->getNodeOrigin()->pos(), edgeParent->getNodeDestiny()->pos()).angle());

    // Reset Index
    index = -1;

    // Declare temporal index
    int tmpIndex = 0;

    // Iterate over lane list
    for (QList<laneItem *>::iterator i = edgeParent->iteratorLanesBegin(); (i != edgeParent->iteratorLanesEnd()) && (index == -1); i++)
    {
        // If iterator == lane
        if((*i) == this)
        {
            // Set index
            index = tmpIndex;
        }
        else
        {
            // Update temporal index
            tmpIndex++;
        }
    }

    /** Una de las lineas se puede eliminar **/

    // Set the rect that compounds the lane
    laneRect = QRectF(0, index * getProjectConfiguration()->getLaneItemConfiguration()->getLaneWidth(), edgeParent->getDistanceBetweenCenters(), getProjectConfiguration()->getLaneItemConfiguration()->getLaneWidth());

    // Set Front Line A
    frontLineA.setP1( QPointF( laneRect.topRight().x() - (getProjectConfiguration()->getLaneItemConfiguration()->getLaneOffset() + edgeParent->getNodeDestiny()->getCurrentlyDiametre() * 0.5), laneRect.topRight().y() ) );
    frontLineA.setP2( QPointF( laneRect.bottomRight().x() - (getProjectConfiguration()->getLaneItemConfiguration()->getLaneOffset() + edgeParent->getNodeDestiny()->getCurrentlyDiametre() * 0.5), laneRect.bottomRight().y() ) );

    // Set Front Line B
    frontLineB.setP1( QPointF( laneRect.topRight().x() - (edgeParent->getNodeDestiny()->getCurrentlyDiametre() * 0.5), laneRect.topRight().y() ) );
    frontLineB.setP2( QPointF( laneRect.bottomRight().x() - (edgeParent->getNodeDestiny()->getCurrentlyDiametre() * 0.5), laneRect.bottomRight().y() ) );

    // Set Back Line A
    backLineA.setP1( QPointF( laneRect.topLeft().x() + (getProjectConfiguration()->getLaneItemConfiguration()->getLaneOffset() + edgeParent->getNodeOrigin()->getCurrentlyDiametre() * 0.5), laneRect.topLeft().y()));
    backLineA.setP2( QPointF( laneRect.bottomLeft().x() + (getProjectConfiguration()->getLaneItemConfiguration()->getLaneOffset() + edgeParent->getNodeOrigin()->getCurrentlyDiametre() * 0.5), laneRect.bottomLeft().y()));

    // Set Back Line B
    backLineB.setP1( QPointF( laneRect.topLeft().x() + (edgeParent->getNodeOrigin()->getCurrentlyDiametre() * 0.5), laneRect.topLeft().y()));
    backLineB.setP2( QPointF( laneRect.bottomLeft().x() + (edgeParent->getNodeOrigin()->getCurrentlyDiametre() * 0.5), laneRect.bottomLeft().y()));

    // Set bounding rect
    setBoundingRect(laneRect);

    // Set endRect
    endRect.setTopRight(frontLineA.p1());
    endRect.setBottomRight(frontLineA.p2());

    endRect.setTopLeft(frontLineA.p1() - QPointF(getProjectConfiguration()->getLaneItemConfiguration()->getLaneRectHeight(), 0));
    endRect.setBottomLeft(frontLineA.p2() - QPointF(getProjectConfiguration()->getLaneItemConfiguration()->getLaneRectHeight(), 0));

    // Remake all elements
    for (QList<connectionItem *>::iterator i = listOfIncomingsConnections.begin(); i != listOfIncomingsConnections.end(); i++)
    {
        (*i)->make();
    }

    for (QList<connectionItem *>::iterator i = listOfOutcomingsConnections.begin(); i != listOfOutcomingsConnections.end(); i++)
    {
        (*i)->make();
    }

    for (QList<prohibitionItem *>::iterator i = listOfIncomingsProhibitions.begin(); i != listOfIncomingsProhibitions.end(); i++)
    {
        (*i)->make();
    }

    for (QList<prohibitionItem *>::iterator i = listOfOutcomingsProhibitions.begin(); i != listOfOutcomingsProhibitions.end(); i++)
    {
        (*i)->make();
    }

    for (QList<busStopItem *>::iterator i = listOfBusStops.begin(); i != listOfBusStops.end(); i++)
    {
        (*i)->make();
    }

    for (QList<chargingStationItem *>::iterator i = listOfChargingStations.begin(); i != listOfChargingStations.end(); i++)
    {
        (*i)->make();
    }

    for (QList<inductionLoopsE1DetectorItem *>::iterator i = listOfInductionLoopsE1Detector.begin(); i != listOfInductionLoopsE1Detector.end(); i++)
    {
        (*i)->make();
    }

    for (QList<laneAreaE2DetectorItem *>::iterator i = listOfLaneAreaE2Detector.begin(); i != listOfLaneAreaE2Detector.end(); i++)
    {
        (*i)->make();
    }

    for (QList<multiEntryExitE3DetectorItem *>::iterator i = listOfMultiEntryExitE3Detector.begin(); i != listOfMultiEntryExitE3Detector.end(); i++)
    {
        (*i)->make();
    }
}

QDomElement laneItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("lane");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement laneItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("lane");

    // Set atribute index
    itemDomElement.setAttribute("index", getIndex());

    // Declare QString for the Edges Id's
    QString listOfVehicleClasses;

    // Iterate over list of edges
    for (QList<vehicleClass>::iterator i = allowedVehicles->begin(); i != allowedVehicles->end(); i++)
    {
        // Keep Edge ID
        listOfVehicleClasses.append(getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeClassValue(*i) + " ");
    }

    // if listOfVehicleClasses != ""
    if(listOfVehicleClasses != "")
    {
        // Remove last Space
        listOfVehicleClasses.remove(listOfVehicleClasses.size() - 1, 1);

        // Set atribute allow
        itemDomElement.setAttribute("allow", listOfVehicleClasses);
    }

    // Clear listOfVehicleClasses
    listOfVehicleClasses.clear();

    // Iterate over list of edges
    for (QList<vehicleClass>::iterator i = disallowedVehicles->begin(); i != disallowedVehicles->end(); i++)
    {
        // Keep Edge ID
        listOfVehicleClasses.append(getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeClassValue(*i) + " ");
    }

    // if listOfVehicleClasses != ""
    if(listOfVehicleClasses != "")
    {
        // Remove last Space
        listOfVehicleClasses.remove(listOfVehicleClasses.size() - 1, 1);

        // Set atribute disallow
        itemDomElement.setAttribute("disallow", listOfVehicleClasses);
    }

    // Set atribute speed
    itemDomElement.setAttribute("speed", QString::number(speed));

    // Set atribute width
    itemDomElement.setAttribute("width", QString::number(width));

    /**
    // Set atribute endOffset
    itemDomElement.setAttribute(, QString::number(endOffset));
    **/

    // Return itemDomElement
    return itemDomElement;
}

void laneItem::updateLaneLabel()
{
    // Set the name to show over each lane
    setItemLabel(edgeParent->getItemId() + "[" + QString::number(getIndex()) + "] ➜");
}

void laneItem::addIncomingConnection(connectionItem *c)
{
    // Add incoming connection
    listOfIncomingsConnections.push_back(c);

    // Remake lane
    make();
}

void laneItem::addOutcomingConnection(connectionItem *c)
{
    // Add outcoming connection
    listOfOutcomingsConnections.push_back(c);

    // Remake lane
    make();
}

void laneItem::addIncomingProhibition(prohibitionItem *p)
{
    listOfIncomingsProhibitions.push_back(p);
}

void laneItem::addOutcomingProhibition(prohibitionItem *p)
{
    listOfOutcomingsProhibitions.push_back(p);
}

void laneItem::addBusStop(busStopItem *bs)
{
    listOfBusStops.push_back(bs);

    // Declare Counter
    int counter = 0;

    // Update Id's of all Detectors
    for(QList<busStopItem *>::iterator i = listOfBusStops.begin(); i != listOfBusStops.end(); i++)
    {
        // Set ID
        (*i)->setItemId("busStop" + QString::number(counter) + "_" + getItemId());

        // Update Counter
        counter++;
    }
}

void laneItem::addChargingStation(chargingStationItem *cs)
{
    listOfChargingStations.push_back(cs);

    // Declare Counter
    int counter = 0;

    // Update Id's of all Detectors
    for(QList<chargingStationItem *>::iterator i = listOfChargingStations.begin(); i != listOfChargingStations.end(); i++)
    {
        // Set ID
        (*i)->setItemId("chargingStation" + QString::number(counter) + "_" + getItemId());

        // Update Counter
        counter++;
    }
}

void laneItem::addInductionLoopsE1Detector(inductionLoopsE1DetectorItem *E1)
{
    listOfInductionLoopsE1Detector.push_back(E1);

    // Declare Counter
    int counter = 0;

    // Update Id's of all Detectors
    for(QList<inductionLoopsE1DetectorItem *>::iterator i = listOfInductionLoopsE1Detector.begin(); i != listOfInductionLoopsE1Detector.end(); i++)
    {
        // Set ID
        (*i)->setItemId("detectorE1_" + QString::number(counter) + "_" + getItemId());

        // Update Counter
        counter++;
    }
}

void laneItem::addLaneAreaE2Detector(laneAreaE2DetectorItem *E2)
{
    listOfLaneAreaE2Detector.push_back(E2);

    // Declare Counter
    int counter = 0;

    // Update Id's of all Detectors
    for(QList<laneAreaE2DetectorItem *>::iterator i = listOfLaneAreaE2Detector.begin(); i != listOfLaneAreaE2Detector.end(); i++)
    {
        // Set ID
        (*i)->setItemId("detectorE2_" + QString::number(counter) + "_" + getItemId());

        // Update Counter
        counter++;
    }
}

void laneItem::addMultiEntryExitE3Detector(multiEntryExitE3DetectorItem *E3)
{
    listOfMultiEntryExitE3Detector.push_back(E3);

    // Declare Counter
    int counter = 0;

    // Update Id's of all Detectors
    for(QList<multiEntryExitE3DetectorItem *>::iterator i = listOfMultiEntryExitE3Detector.begin(); i != listOfMultiEntryExitE3Detector.end(); i++)
    {

        // Set ID
        (*i)->setItemId("detectorE3_" + QString::number(counter) + "_" + getItemId());

        // Update Counter
        counter++;
    }
}

void laneItem::removeIncomingConnection(connectionItem *c)
{
    // Remove Connection
    listOfIncomingsConnections.removeAll(c);

    // Remake lane
    make();
}

void laneItem::clearIncomingConnection()
{
    // Create copy of list of incomings connections
    QList<connectionItem *> copyOfListOfIncomingsConnections = listOfIncomingsConnections;

    //Iterate over copy of list of incomings connections
    for(QList<connectionItem *>::iterator i = copyOfListOfIncomingsConnections.begin(); i != copyOfListOfIncomingsConnections.end(); i++)
    {
        // Delete connection
        delete (*i);
    }
}

void laneItem::removeOutcomingConnection(connectionItem *c)
{
    // Remove Connection
    listOfOutcomingsConnections.removeAll(c);

    // Remake lane
    make();
}

void laneItem::clearOutcomingConnection()
{

    // Create copy of list of outcomings connections
    QList<connectionItem *> copyOfListOfOutcomingsConnections = listOfOutcomingsConnections;

    //Iterate over copy of list of outcomings connections
    for(QList<connectionItem *>::iterator i = copyOfListOfOutcomingsConnections.begin(); i != copyOfListOfOutcomingsConnections.end(); i++)
    {
        // Delete connection
        delete (*i);
    }
}

void laneItem::removeIncomingProhibition(prohibitionItem *p)
{
    // Remove prohibition
    listOfIncomingsProhibitions.removeAll(p);

    // Remake lane
    make();
}

void laneItem::clearIncomingProhibition()
{
    // Create copy of list of incomings prohibitions
    QList<prohibitionItem *> copyOfListOfIncomingsProhibitions = listOfIncomingsProhibitions;

    // Iterate over copy of list of incomings prohibitions
    for(QList<prohibitionItem *>::iterator i = copyOfListOfIncomingsProhibitions.begin(); i != copyOfListOfIncomingsProhibitions.end(); i++)
    {
        // Delete prohibition
        delete (*i);
    }
}

void laneItem::removeOutcomingProhibition(prohibitionItem *p)
{
    // Remove prohibition
    listOfOutcomingsProhibitions.removeAll(p);

    // Remake lane
    make();
}

void laneItem::clearOutcomingProhibition()
{
    // Create copy of list of outcomings prohibition
    QList<prohibitionItem *> copyOfListOfOutcomingsProhibitions = listOfOutcomingsProhibitions;

    //Iterate over copy of list of outcomings prohibition
    for(QList<prohibitionItem *>::iterator i = copyOfListOfOutcomingsProhibitions.begin(); i != copyOfListOfOutcomingsProhibitions.end(); i++)
    {
        // Delete prohibition
        delete (*i);
    }
}

void laneItem::removeBusStop(busStopItem *bs)
{
    listOfBusStops.removeAll(bs);

    // Declare Counter
    int counter = 0;

    // Update Id's of all Detectors
    for(QList<busStopItem *>::iterator i = listOfBusStops.begin(); i != listOfBusStops.end(); i++)
    {
        // Set ID
        (*i)->setItemId("busStop" + QString::number(counter) + "_" + getItemId());

        // Update Counter
        counter++;
    }
}

void laneItem::clearBusStop()
{
    // Create copy of list of bus Stop
    QList<busStopItem *> copyOfListOfBusStops = listOfBusStops;

    // Iterate over copy of list of bus Stop
    for(QList<busStopItem *>::iterator i = copyOfListOfBusStops.begin(); i != copyOfListOfBusStops.end(); i++)
    {
        // Delete bus Stop
        delete (*i);
    }
}

void laneItem::removeChargingStation(chargingStationItem *cs)
{
    listOfChargingStations.removeAll(cs);

    // Declare Counter
    int counter = 0;

    // Update Id's of all Detectors
    for(QList<chargingStationItem *>::iterator i = listOfChargingStations.begin(); i != listOfChargingStations.end(); i++)
    {
        // Set ID
        (*i)->setItemId("chargingStation" + QString::number(counter) + "_" + getItemId());

        // Update Counter
        counter++;
    }
}

void laneItem::clearChargingStation()
{
    // Create copy of list of charging station
    QList<chargingStationItem *> copyOfListOfChargingStations = listOfChargingStations;

    // Iterate over copy of list of charging station
    for(QList<chargingStationItem *>::iterator i = copyOfListOfChargingStations.begin(); i != copyOfListOfChargingStations.end(); i++)
    {
        // Delete charging station
        delete (*i);
    }
}

void laneItem::removeInductionLoopsE1Detector(inductionLoopsE1DetectorItem *E1)
{
    listOfInductionLoopsE1Detector.removeAll(E1);

    // Declare Counter
    int counter = 0;

    // Update Id's of all Detectors
    for(QList<inductionLoopsE1DetectorItem *>::iterator i = listOfInductionLoopsE1Detector.begin(); i != listOfInductionLoopsE1Detector.end(); i++)
    {
        // Set ID
        (*i)->setItemId("detectorE1_" + QString::number(counter) + "_" + getItemId());

        // Update Counter
        counter++;
    }
}

void laneItem::clearInductionLoopsE1Detector()
{
    // Create copy of list of E1
    QList<inductionLoopsE1DetectorItem *> copyOfListOfInductionLoopsE1Detector = listOfInductionLoopsE1Detector;

    // Iterate over copy of list of E1
    for(QList<inductionLoopsE1DetectorItem *>::iterator i = copyOfListOfInductionLoopsE1Detector.begin(); i != copyOfListOfInductionLoopsE1Detector.end(); i++)
    {
        // Delete E1
        delete (*i);
    }
}

void laneItem::removeLaneAreaE2Detector(laneAreaE2DetectorItem *E2)
{
    listOfLaneAreaE2Detector.removeAll(E2);

    // Declare Counter
    int counter = 0;

    // Update Id's of all Detectors
    for(QList<laneAreaE2DetectorItem *>::iterator i = listOfLaneAreaE2Detector.begin(); i != listOfLaneAreaE2Detector.end(); i++)
    {
        // Set ID
        (*i)->setItemId("detectorE2_" + QString::number(counter) + "_" + getItemId());

        // Update Counter
        counter++;
    }
}

void laneItem::clearLaneAreaE2Detector()
{
    // Create copy of list of E2
    QList<laneAreaE2DetectorItem *> copyOfListOfLaneAreaE2Detector = listOfLaneAreaE2Detector;

    // Iterate over copy of list of E2
    for(QList<laneAreaE2DetectorItem *>::iterator i = copyOfListOfLaneAreaE2Detector.begin(); i != copyOfListOfLaneAreaE2Detector.end(); i++)
    {
        // Delete E2
        delete (*i);
    }
}

void laneItem::removeMultiEntryExitE3Detector(multiEntryExitE3DetectorItem *E3)
{
    listOfMultiEntryExitE3Detector.removeAll(E3);

    // Declare Counter
    int counter = 0;

    // Update Id's of all Detectors
    for(QList<multiEntryExitE3DetectorItem *>::iterator i = listOfMultiEntryExitE3Detector.begin(); i != listOfMultiEntryExitE3Detector.end(); i++)
    {
        // Set ID
        (*i)->setItemId("detectorE3_" + QString::number(counter) + "_" + getItemId());

        // Update Counter
        counter++;
    }
}

void laneItem::clearMultiEntryExitE3Detector()
{
    // Create copy of list of E3
    QList<multiEntryExitE3DetectorItem *> copyOfListOfMultiEntryExitE3Detector = listOfMultiEntryExitE3Detector;

    // Iterate over copy of list of E3
    for(QList<multiEntryExitE3DetectorItem *>::iterator i = copyOfListOfMultiEntryExitE3Detector.begin(); i != copyOfListOfMultiEntryExitE3Detector.end(); i++)
    {
        // Delete E3
        delete (*i);
    }
}



int laneItem::getIndex() const
{
    return index;
}

edgeItem *laneItem::getEdgeParent() const
{
    return edgeParent;
}

qreal laneItem::getSpeed() const
{
    return speed;
}

qreal laneItem::getWidth() const
{
    return width;
}

QList<vehicleClass> *laneItem::getListOfAllowedVehicles() const
{
    return allowedVehicles;
}

QList<vehicleClass> *laneItem::getListOfDisallowedVehicles() const
{
    return disallowedVehicles;
}

int laneItem::getNumberOfIncomingsConnections() const
{
    return listOfIncomingsConnections.size();
}

int laneItem::getNumberOfOutcomingsConnections() const
{
    return listOfOutcomingsConnections.size();
}

int laneItem::getNumberOfIncomingsProhibitions() const
{
    return listOfIncomingsProhibitions.size();
}

int laneItem::getNumberOfOutcomingsProhibitions() const
{
    return listOfOutcomingsProhibitions.size();
}

int laneItem::getNumberOfBusStops() const
{
    return listOfBusStops.size();
}

int laneItem::getNumberOfChargingStations() const
{
    return listOfChargingStations.size();
}

int laneItem::getNumberOfInductionLoopsDetectorsE1()
{
    return listOfInductionLoopsE1Detector.size();
}

int laneItem::getNumberOfLaneAreaDetectorsE2()
{
    return listOfLaneAreaE2Detector.size();
}

int laneItem::getNumberOfMultiEntryExitDetectorssE3()
{
    return listOfMultiEntryExitE3Detector.size();
}



connectionItem *laneItem::getFirstIncomingsConnections() const
{
    if(listOfIncomingsConnections.size() > 0)
    {
        return listOfIncomingsConnections.first();
    }
    else
    {
        return NULL;
    }
}

connectionItem *laneItem::getLastIncomingsConnections() const
{
    if(listOfIncomingsConnections.size() > 0)
    {
        return listOfIncomingsConnections.last();
    }
    else
    {
        return NULL;
    }
}

connectionItem *laneItem::getFirstOutcomingsConnections() const
{
    if(listOfOutcomingsConnections.size() > 0)
    {
        return listOfOutcomingsConnections.first();
    }
    else
    {
        return NULL;
    }
}

connectionItem *laneItem::getLastOutcomingsConnections() const
{
    if(listOfOutcomingsConnections.size() > 0)
    {
        return listOfOutcomingsConnections.last();
    }
    else
    {
        return NULL;
    }
}

prohibitionItem *laneItem::getFirstIncomingsProhibitions() const
{
    if(listOfIncomingsProhibitions.size() > 0)
    {
        return listOfIncomingsProhibitions.first();
    }
    else
    {
        return NULL;
    }
}

prohibitionItem *laneItem::getLastIncomingsProhibitions() const
{
    if(listOfIncomingsProhibitions.size() > 0)
    {
        return listOfIncomingsProhibitions.last();
    }
    else
    {
        return NULL;
    }
}

prohibitionItem *laneItem::getFirstOutcomingsProhibitions() const
{
    if(listOfOutcomingsProhibitions.size() > 0)
    {
        return listOfOutcomingsProhibitions.first();
    }
    else
    {
        return NULL;
    }
}

prohibitionItem *laneItem::getLastOutcomingsProhibitions() const
{
    if(listOfOutcomingsProhibitions.size() > 0)
    {
        return listOfOutcomingsProhibitions.last();
    }
    else
    {
        return NULL;
    }
}

busStopItem *laneItem::getFirstBusStops() const
{
    if(listOfBusStops.size() > 0)
    {
        return listOfBusStops.first();
    }
    else
    {
        return NULL;
    }
}

busStopItem *laneItem::getLastBusStops() const
{
    if(listOfBusStops.size() > 0)
    {
        return listOfBusStops.last();
    }
    else
    {
        return NULL;
    }
}

chargingStationItem *laneItem::getFirstChargingStations() const
{
    if(listOfChargingStations.size() > 0)
    {
        return listOfChargingStations.first();
    }
    else
    {
        return NULL;
    }
}

chargingStationItem *laneItem::getLastChargingStations() const
{
    if(listOfChargingStations.size() > 0)
    {
        return listOfChargingStations.last();
    }
    else
    {
        return NULL;
    }
}

inductionLoopsE1DetectorItem *laneItem::getFirstInductionLoopsE1Detector() const
{
    return listOfInductionLoopsE1Detector.first();
}

inductionLoopsE1DetectorItem *laneItem::getLastInductionLoopsE1Detector() const
{
    return listOfInductionLoopsE1Detector.last();
}

laneAreaE2DetectorItem *laneItem::getFirstLaneAreaE2Detector() const
{
    return listOfLaneAreaE2Detector.first();
}

laneAreaE2DetectorItem *laneItem::getLastLaneAreaE2Detector() const
{
    return listOfLaneAreaE2Detector.last();
}

multiEntryExitE3DetectorItem *laneItem::getFirstMultiEntryExitE3Detector() const
{
    return listOfMultiEntryExitE3Detector.first();
}

multiEntryExitE3DetectorItem *laneItem::getLastMultiEntryExitE3Detector() const
{
    return listOfMultiEntryExitE3Detector.last();
}

QLineF laneItem::getConnectionLineFrontTop(connectionItem *c) const
{
    // Declare connectionLineFrontTop line
    QLineF connectionLineFrontTop;

    // If the list of outcoming connections isn't empty
    if(!listOfOutcomingsConnections.empty())
    {
        // Get position of connection in the list
        int positionOfConnectionInList = listOfOutcomingsConnections.indexOf(c);

        // Obtain position in the vectors frontLineA and frontLineB;
        qreal positionInVectors = (qreal(1) / listOfOutcomingsConnections.size() ) * positionOfConnectionInList;

        // Set P1 of connectionLineFrontTop;
        connectionLineFrontTop.setP1(frontLineA.pointAt(positionInVectors));

        // Set P2 of connectionLineFrontTop;
        connectionLineFrontTop.setP2(frontLineB.pointAt(positionInVectors));
    }

    // Return ConnectionLineFrontTop line
    return connectionLineFrontTop;
}

QLineF laneItem::getConnectionLineFrontBottom(connectionItem *c) const
{
    // Declare connectionLineFrontBottom line
    QLineF connectionLineFrontBottom;

    // If the list of outcoming connections isn't empty
    if(!listOfOutcomingsConnections.empty())
    {
        // Get position of connection in the list
        int positionOfConnectionInList = listOfOutcomingsConnections.indexOf(c);

        // Obtain position in the vectors frontLineA and frontLineB;
        qreal positionInVectors = (qreal(1) / listOfOutcomingsConnections.size() ) * (positionOfConnectionInList + 1);

        // Set P1 of connectionLineFrontBottom;
        connectionLineFrontBottom.setP1(frontLineA.pointAt(positionInVectors));

        // Set P2 of connectionLineFrontBottom;
        connectionLineFrontBottom.setP2(frontLineB.pointAt(positionInVectors));
    }

    // Return connectionLineFrontBottom line
    return connectionLineFrontBottom;
}

QLineF laneItem::getConnectionLineBackTop(connectionItem *c) const
{
    // Declare connectionLineBackTop line
    QLineF connectionLineBackTop;

    // If the list of incomings connections isn't empty
    if(!listOfIncomingsConnections.empty())
    {
        // Get position of connection in the list
        int positionOfConnectionInList = listOfIncomingsConnections.indexOf(c);

        // Obtain position in the vectors backLineA and backLineB;
        qreal positionInVectors = (qreal(1) / listOfIncomingsConnections.size() ) * positionOfConnectionInList;

        // Set P1 of connectionLineBackTop;
        connectionLineBackTop.setP1(backLineA.pointAt(positionInVectors));

        // Set P2 of connectionLineBackTop;
        connectionLineBackTop.setP2(backLineB.pointAt(positionInVectors));
    }

    // Return connectionLineBackTop line
    return connectionLineBackTop;
}

QLineF laneItem::getConnectionLineBackBottom(connectionItem *c) const
{
    // Declare connectionLineBackBottom line
    QLineF connectionLineBackBottom;

    // If the list of Incomings connections isn't empty
    if(!listOfIncomingsConnections.empty())
    {
        // Get position of connection in the list
        int positionOfConnectionInList = listOfIncomingsConnections.indexOf(c);

        // Obtain position in the vectors backLineA and backLineB;
        qreal positionInVectors = (qreal(1) / listOfIncomingsConnections.size() ) * (positionOfConnectionInList + 1);

        // Set P1 of connectionLineBackBottom;
        connectionLineBackBottom.setP1(backLineA.pointAt(positionInVectors));

        // Set P2 of connectionLineBackBottom;
        connectionLineBackBottom.setP2(backLineB.pointAt(positionInVectors));
    }

    // Return connectionLineBackBottom line
    return connectionLineBackBottom;
}



QLineF laneItem::getInternalLineCentral() const
{
    return QLineF(backLineB.pointAt(0.5), frontLineB.pointAt(0.5));
}

QLineF laneItem::getInternalLineTop() const
{
    return QLineF(backLineB.p1(), frontLineB.p1());
}

QLineF laneItem::getInternalLineBottom() const
{
    return QLineF(backLineB.p2(), frontLineB.p2());
}

QLineF laneItem::getExternalLineFrontCentral() const
{
    return QLineF(frontLineA.pointAt(0.5), frontLineB.pointAt(0.5));
}

QLineF laneItem::getExternalLineFrontTop() const
{
    return QLineF(frontLineA.p1(), frontLineB.p1());
}

QLineF laneItem::getExternalLineFrontBottom() const
{
    return QLineF(frontLineA.p2(), frontLineB.p2());
}

QLineF laneItem::getExternalLineBackCentral() const
{
    return QLineF(backLineA.pointAt(0.5), backLineB.pointAt(0.5));
}

QLineF laneItem::getExternalLineBackTop() const
{
    return QLineF(backLineA.p1(), backLineB.p1());
}

QLineF laneItem::getExternalLineBackBottom() const
{
    return QLineF(backLineA.p2(), backLineB.p2());
}

void laneItem::setItemId(const QString &newId)
{
    if(newId == "")
    {
        eNetEditorItem::setItemId(edgeParent->getItemId() + "_" + QString::number(getIndex()));
    }
    else
    {
        eNetEditorItem::setItemId(newId);
    }

    for(QList<connectionItem *>::iterator i = listOfIncomingsConnections.begin(); i != listOfIncomingsConnections.end(); i++)
    {
        (*i)->setItemId();
    }

    for(QList<connectionItem *>::iterator i = listOfOutcomingsConnections.begin(); i != listOfOutcomingsConnections.end(); i++)
    {
        (*i)->setItemId();
    }
}

void laneItem::setSpeed(qreal newSpeed)
{
    speed = newSpeed;
}

void laneItem::setWidth(qreal newWidth)
{
    width = newWidth;
}

void laneItem::setListOfAllowedVehicles(const QList<vehicleClass> &newAllowedVehicles)
{
    (*allowedVehicles) = newAllowedVehicles;
}

void laneItem::setListOfDisalllowedVehicles(const QList<vehicleClass> &newDisallowedVehicles)
{
    (*disallowedVehicles) = newDisallowedVehicles;
}

QList<connectionItem *>::iterator laneItem::iteratorIncomingsConnectionsBegin()
{
    return listOfIncomingsConnections.begin();
}

QList<connectionItem *>::iterator laneItem::iteratorIncomingsConnectionsEnd()
{
    return listOfIncomingsConnections.end();
}

QList<connectionItem *>::iterator laneItem::iteratorOutcomingsConnectionsBegin()
{
    return listOfOutcomingsConnections.begin();
}

QList<connectionItem *>::iterator laneItem::iteratorOutcomingsConnectionsEnd()
{
    return listOfOutcomingsConnections.end();
}

QList<prohibitionItem *>::iterator laneItem::iteratorIncomingsProhibitionsBegin()
{
    return listOfIncomingsProhibitions.begin();
}

QList<prohibitionItem *>::iterator laneItem::iteratorIncomingsProhibitionsEnd()
{
    return listOfIncomingsProhibitions.end();
}

QList<prohibitionItem *>::iterator laneItem::iteratorOutcomingsProhibitionsBegin()
{
    return listOfOutcomingsProhibitions.begin();
}

QList<prohibitionItem *>::iterator laneItem::iteratorOutcomingsProhibitionsEnd()
{
    return listOfOutcomingsProhibitions.end();
}

QList<busStopItem *>::iterator laneItem::iteratorBusStopsBegin()
{
    return listOfBusStops.begin();
}

QList<busStopItem *>::iterator laneItem::iteratorBusStopsEnd()
{
    return listOfBusStops.end();
}

QList<chargingStationItem *>::iterator laneItem::iteratorChargingStationsBegin()
{
    return listOfChargingStations.begin();
}

QList<chargingStationItem *>::iterator laneItem::iteratorChargingStationsEnd()
{
    return listOfChargingStations.end();
}

QList<inductionLoopsE1DetectorItem *>::iterator laneItem::iteratorInductionLoopsE1DetectorBegin()
{
    return listOfInductionLoopsE1Detector.begin();
}

QList<inductionLoopsE1DetectorItem *>::iterator laneItem::iteratorInductionLoopsE1DetectorEnd()
{
    return listOfInductionLoopsE1Detector.end();
}

QList<laneAreaE2DetectorItem *>::iterator laneItem::iteratorLaneAreaE2DetectorBegin()
{
    return listOfLaneAreaE2Detector.begin();
}

void laneItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // if Draw item is enabled
    if(getParameterManager()->isShowAllLaneItems())
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

        // Add pen to painter
        painter->setPen(getItemPen());

        // Draw the rect
        painter->drawRect(laneRect);

        // Change color of the brush depend of the node Destiny is a traffic light or not
        if(getEdgeParent()->getNodeDestiny()->getType() == nodeItemTypeTrafficLight)
        {
            // Change the color of endRect to red or green depending of their index
            if(getIndex() % 2 == 0)
            {
                painter->setBrush(QColor("red"));
            }
            else
            {
                painter->setBrush(QColor("green"));
            }
        }
        else
        {
            // If not a traffic light, change color to white
            painter->setBrush(QColor("white"));
        }

        // Draw end rect
        painter->drawRect(endRect);

        // If flag ShowLabels is enabled
        if(getParameterManager()->isLaneShowLabelEnabled())
        {
            // Set the modified font to the painter
            painter->setFont(getItemFontText());

            // Add pen to painter
            painter->setPen(getItemPenText());

            // Draw text with the label
            painter->drawStaticText(laneRect.topLeft() + QPointF( (laneRect.size().width() / 2.0) - 5.5, -0.75 ), getItemLabel());
        }
    }
}

void laneItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath laneItem::shape() const
{
    // Declare QPainterPath
    QPainterPath path;

    // If the item isn't blocked
    if(getParameterManager()->isLaneBlocked() == false)
    {
        // Add path
        path.addRect(laneRect);
    }

    // Return new path
    return path;
}


QList<laneAreaE2DetectorItem *>::iterator laneItem::iteratorLaneAreaE2DetectorEnd()
{
    return listOfLaneAreaE2Detector.end();
}

QList<multiEntryExitE3DetectorItem *>::iterator laneItem::iteratorMultiEntryExitE3DetectorBegin()
{
    return listOfMultiEntryExitE3Detector.begin();
}

QList<multiEntryExitE3DetectorItem *>::iterator laneItem::iteratorMultiEntryExitE3DetectorEnd()
{
    return listOfMultiEntryExitE3Detector.end();
}
