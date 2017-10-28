#include "eNetEditorScene.h"

// Main Dialog
#include "../dialogs/main/eNetEditorMainWindow.h"

// Messages
#include "../main/eNetEditorMessages.h"

// Database
#include "../database/eNetEditorDatabase.h"

// Project
#include "../project/eNetEditorProject.h"

// Parameter manager
#include "../project/itemManagerProject.h"

// Configuration
#include "../configuration/main/eNetEditorMainConfiguration.h"
#include "../configuration/project/eNetEditorProjectConfiguration.h"
#include "../configuration/items/eNetEditorItemConfiguration.h"

// Items Dialog
#include "../dialogs/items/nodeItemDialog.h"
#include "../dialogs/items/edges/edgeItemDialog.h"
#include "../dialogs/items/laneItemDialog.h"
#include "../dialogs/items/connectionItemDialog.h"
#include "../dialogs/items/prohibitionItemDialog.h"
#include "../dialogs/items/trafficLightItemDialog.h"
#include "../dialogs/items/routeItemDialog.h"
#include "../dialogs/items/stops/busStopItemDialog.h"
#include "../dialogs/items/stops/chargingStationItemDialog.h"
#include "../dialogs/items/vehicles/vehicleItemDialog.h"
#include "../dialogs/items/vehicleTypeItemDialog.h"
#include "../dialogs/items/vehicles/flowItemDialog.h"
#include "../dialogs/items/detectors/abstractDetectorItemDialog.h"
#include "../dialogs/items/detectors/inductionLoopsE1DetectorItemDialog.h"
#include "../dialogs/items/detectors/laneAreaE2DetectorItemDialog.h"
#include "../dialogs/items/detectors/multiEntryExitE3DetectorItemDialog.h"

// Tables Dialog
#include "../dialogs/database/nodeTableDialog.h"
#include "../dialogs/database/edges/edgeTableDialog.h"
#include "../dialogs/database/laneTableDialog.h"
#include "../dialogs/database/connectionTableDialog.h"
#include "../dialogs/database/prohibitionTableDialog.h"
#include "../dialogs/database/trafficLightTableDialog.h"
#include "../dialogs/database/routeTableDialog.h"
#include "../dialogs/database/stops/busStopTableDialog.h"
#include "../dialogs/database/stops/chargingStationTableDialog.h"
#include "../dialogs/database/vehicles/vehicleTableDialog.h"
#include "../dialogs/database/vehicleTypeTableDialog.h"
#include "../dialogs/database/vehicles/flowTableDialog.h"
#include "../dialogs/database/detectors/abstractDetectorTableDialog.h"
#include "../dialogs/database/detectors/inductionLoopsE1DetectorTableDialog.h"
#include "../dialogs/database/detectors/laneAreaE2DetectorTableDialog.h"
#include "../dialogs/database/detectors/multiEntryExitE3DetectorTableDialog.h"

// Tools dialogs
#include "../dialogs/tools/cadytsToolDialog.h"
#include "../dialogs/tools/dfRouterToolDialog.h"
#include "../dialogs/tools/duaRouterToolDialog.h"
#include "../dialogs/tools/jtrRouterToolDialog.h"
#include "../dialogs/tools/netConvertToolDialog.h"
#include "../dialogs/tools/netGenerateToolDialog.h"
#include "../dialogs/tools/sumoToolDialog.h"

// Items
#include "../items/nodeItem.h"
#include "../items/edges/edgeItem.h"
#include "../items/laneItem.h"
#include "../items/connectionItem.h"
#include "../items/prohibitionItem.h"
#include "../items/trafficLightItem.h"
#include "../items/routeItem.h"
#include "../items/stops/busStopItem.h"
#include "../items/stops/chargingStationItem.h"
#include "../items/vehicles/vehicleItem.h"
#include "../items/vehicleTypeItem.h"
#include "../items/vehicles/flowItem.h"
#include "../items/detectors/inductionLoopsE1DetectorItem.h"
#include "../items/detectors/laneAreaE2DetectorItem.h"
#include "../items/detectors/multiEntryExitE3DetectorItem.h"


eNetEditorScene::eNetEditorScene(eNetEditorProject *newProject) : QGraphicsScene(newProject), eNetEditor()
{
    // link pointer to project
    project = newProject;

    // Create parameter Manager
    parameterManager = new itemManagerProject();

    // Create database
    database = new eNetEditorDatabase(this);

    // Default position of mouse
    posx = 0;
    posy = 0;

    // Number of automatic lanes
    numberOfAutomaticLanes = 1;

    // Automatic double Edge
    doubleEdge = true;

    // By default, pointer to nodes is NULL
    temporalNode = NULL;
    lastInsertedNode = NULL;

    // By default shiftKeyPressed is false
    shiftKeyPressed = false;

    // By default user don't scroll window
    scrolling = false;

    // By default selfconnection is disabled
    allowSelfconnection = false;

    // By default Flag is in NoOperation mode
    flag = flagOperationNoOperation;
}

eNetEditorScene::eNetEditorScene(const QString &filePath, eNetEditorProject *newProject) : QGraphicsScene(newProject)
{
    // link pointer to project
    project = newProject;

    // Create parameter Manager
    parameterManager = new itemManagerProject();

    // Create database
    database = new eNetEditorDatabase(filePath, this);

    // Default position of mouse
    posx = 0;
    posy = 0;

    // By default Flag is in NoOperation mode
    flag = flagOperationNoOperation;
}

eNetEditorScene::~eNetEditorScene()
{
    // Delete database
    delete database;

    // Delete parameter manager
    delete parameterManager;
}

void eNetEditorScene::setImageMap()
{
    // Add image to scene
    imageMapItem = addPixmap(getProject()->getImageMap());

    // Set position of the image int the center of scene
    imageMapItem->setPos(imageMapItem->boundingRect().width() / -2, imageMapItem->boundingRect().height() / -2);

    // Adjust size of view to image bounding
    setSceneRect(QRectF(imageMapItem->pos().x(), imageMapItem->pos().y(), imageMapItem->boundingRect().width(), imageMapItem->boundingRect().height()));
}

eNetEditorProject *eNetEditorScene::getProject() const
{
    return project;
}

qreal eNetEditorScene::getMousePosx() const
{
    return posx;
}

qreal eNetEditorScene::getMousePosy() const
{
    return posy;
}

flagOperation eNetEditorScene::getFlag() const
{
    return flag;
}

eNetEditorDatabase *eNetEditorScene::getDatabase() const
{
    return database;
}

itemManagerProject *eNetEditorScene::getParameterManager() const
{
    return parameterManager;
}

eNetEditorMessages *eNetEditorScene::getMessages() const
{
    return project->geteNetEditorMainWindow()->getMessages();
}

void eNetEditorScene::setFlag(flagOperation newFlag)
{
    // Set Flag
    flag = newFlag;

    // Dismark All items
    parameterManager->dismarkAllItems();

    // If temporalNode is != NULL
    if(temporalNode)
    {
        // Erase temporal Node
        //database->eraseNodeOfSceneAndDatabase(temporalNode);

        delete temporalNode;

        // Set pointer to nodes to NULL
        temporalNode = NULL;
        lastInsertedNode = NULL;
    }

    // If the Flag is the special flag No operation
    if (flag == flagOperationNoOperation)
    {
        // Nodes aren't movables
        getParameterManager()->setNodesMovables(false);

        // Block all items
        getParameterManager()->setBlockAllItems(true);

        // Hidde items
        getParameterManager()->setShowAllConnections(false);
        getParameterManager()->setShowAllProhibitions(false);
        getParameterManager()->setShowAllRoutes(false);
        getParameterManager()->setShowAllDetectors(false);
    }
    else if (flag == flagOperationMoveNode)
    {
        // Only in this case the nodes are movables
        getParameterManager()->setNodesMovables(true);

        // Block all items
        getParameterManager()->setBlockAllItems(true);

        // Nodes aren't blocked
        getParameterManager()->setBlockAllNodes(false);

        // Hidde items
        getParameterManager()->setShowAllConnections(false);
        getParameterManager()->setShowAllProhibitions(false);
        getParameterManager()->setShowAllRoutes(false);
        getParameterManager()->setShowAllDetectors(false);
    }
    else if (flag == flagOperationAddOrRemoveNodeOrEdgeOrLane)
    {
        // Nodes aren't movables
        getParameterManager()->setNodesMovables(false);

        // Block all items
        getParameterManager()->setBlockAllItems(true);

        // The nodes aren't blocked
        getParameterManager()->setBlockAllNodes(false);
        getParameterManager()->setBlockAllEdges(false);
        getParameterManager()->setBlockAllLanes(false);

        // Hidde items
        getParameterManager()->setShowAllConnections(false);
        getParameterManager()->setShowAllProhibitions(false);
        getParameterManager()->setShowAllRoutes(false);
        getParameterManager()->setShowAllDetectors(false);
    }
    else if (flag == flagOperationAddOrRemoveConnection)
    {
        // Nodes aren't movables
        getParameterManager()->setNodesMovables(false);

        // Block all items
        getParameterManager()->setBlockAllItems(true);

        // The connection and lanes aren't blocked
        getParameterManager()->setBlockAllLanes(false);
        getParameterManager()->setBlockAllConnections(false);

        // Show connections
        getParameterManager()->setShowAllConnections(true);

        // Hidde items
        getParameterManager()->setShowAllProhibitions(false);
        getParameterManager()->setShowAllRoutes(false);
        getParameterManager()->setShowAllDetectors(false);
    }
    else if (flag == flagOperationAddOrRemoveProhibition)
    {
        // Nodes aren't movables
        getParameterManager()->setNodesMovables(false);

        // Block all items
        getParameterManager()->setBlockAllItems(true);

        // The prohibition and lanes aren't blocked
        getParameterManager()->setBlockAllEdges(false);
        getParameterManager()->setBlockAllProhibitions(false);

        // Show prohibitions
        getParameterManager()->setShowAllProhibitions(true);

        // Hidde items
        getParameterManager()->setShowAllConnections(false);
        getParameterManager()->setShowAllRoutes(false);
        getParameterManager()->setShowAllDetectors(false);
    }
    else if (flag == flagOperationAddOrRemoveRoute)
    {
        // Nodes aren't movables
        getParameterManager()->setNodesMovables(false);

        // Block all items
        getParameterManager()->setBlockAllItems(true);

        // The prohibition and lanes aren't blocked
        getParameterManager()->setBlockAllRoutes(false);
        getParameterManager()->setBlockAllEdges(false);

        // Show routes
        getParameterManager()->setShowAllRoutes(true);

        // Hidde items
        getParameterManager()->setShowAllConnections(false);
        getParameterManager()->setShowAllProhibitions(false);
        getParameterManager()->setShowAllDetectors(false);
    }
    else if (flag == flagOperationAddOrRemoveTrafficLight)
    {
        // Nodes aren't movables
        getParameterManager()->setNodesMovables(false);

        // Block all items
        getParameterManager()->setBlockAllItems(true);

        // The nodes and traffic lights aren't blocked
        getParameterManager()->setBlockAllNodes(false);

        // Hidde items
        getParameterManager()->setShowAllConnections(false);
        getParameterManager()->setShowAllProhibitions(false);
        getParameterManager()->setShowAllRoutes(false);
        getParameterManager()->setShowAllDetectors(false);
    }
    else if (flag == flagOperationAddOrRemoveBusStop)
    {
        // Nodes aren't movables
        getParameterManager()->setNodesMovables(false);

        // Block all items
        getParameterManager()->setBlockAllItems(true);

        // The lanes and busStops aren't blocked
        getParameterManager()->setBlockAllLanes(false);
        getParameterManager()->setBlockAllBusStops(false);

        // Hidde items
        getParameterManager()->setShowAllConnections(false);
        getParameterManager()->setShowAllProhibitions(false);
        getParameterManager()->setShowAllRoutes(false);
        getParameterManager()->setShowAllDetectors(false);
    }
    else if (flag == flagOperationAddOrRemoveChargingStation)
    {
        // Nodes aren't movables
        getParameterManager()->setNodesMovables(false);

        // Block all items
        getParameterManager()->setBlockAllItems(true);

        // The lanes and charging stations aren't blocked
        getParameterManager()->setBlockAllLanes(false);
        getParameterManager()->setBlockAllChargingStations(false);

        // Hidde items
        getParameterManager()->setShowAllConnections(false);
        getParameterManager()->setShowAllProhibitions(false);
        getParameterManager()->setShowAllRoutes(false);
        getParameterManager()->setShowAllDetectors(false);
    }
    else if (flag == flagOperationAddOrRemoveDetector)
    {
        // Nodes aren't movables
        getParameterManager()->setNodesMovables(false);

        // Block all items
        getParameterManager()->setBlockAllItems(true);

        // The lanes and detectors aren't blocked
        getParameterManager()->setBlockAllLanes(false);
        getParameterManager()->setBlockAllDetectors(false);

        // Show detectors
        getParameterManager()->setShowAllDetectors(true);

        // Hidde items
        getParameterManager()->setShowAllConnections(false);
        getParameterManager()->setShowAllProhibitions(false);
        getParameterManager()->setShowAllRoutes(false);
    }

    // Update scene
    update();
}

void eNetEditorScene::setDoubleEdge(bool newDoubleEdge)
{
    // Set condition of new double edge
    doubleEdge = newDoubleEdge;

    // If in this moment a new node are being created
    if(temporalNode)
    {
        // If the option doubleEdge is enabled
        if(doubleEdge)
        {
            // If previously don't exits a outcoming edge
            if(temporalNode->iteratorOutcomingEdgesBegin() == temporalNode->iteratorOutcomingEdgesEnd())
            {
                // Insert new edge in scena and database
                edgeItem *e = new edgeItem(temporalNode, (*(temporalNode->iteratorIncomingEdgesBegin()))->getNodeOrigin(), database);

                // Add numberOfAutomaticLanes lanes in the created edge
                for(int i = 1; i < numberOfAutomaticLanes; i++)
                {
                    // Create Lane
                    laneItem *l = new laneItem(e, database);

                    // Show console message
                    getMessages()->writeInConsole("Created lane in edge '" + e->getItemId() + "' with Index = '" + QString::number(l->getIndex()) + "'.", consoleMessageTypeNormal);
                }
            }
        }
        else
        {
            // If previously exits a outcoming edge
            if(temporalNode->iteratorOutcomingEdgesBegin() != temporalNode->iteratorOutcomingEdgesEnd())
            {
                // Get pointer to outcoming edge
                edgeItem *e = *(temporalNode->iteratorOutcomingEdgesBegin());

                // Remove edge of scene and database
                delete e;
            }
        }

        // Remake edge and their adyacents
        temporalNode->make();
    }
}

void eNetEditorScene::setScrolling(bool value)
{
    scrolling = value;
}

bool eNetEditorScene::isScrolling()
{
    return scrolling;
}

void eNetEditorScene::setNumberOfAutomaticLanes(int newNumberOfAutomaticLanes)
{
    // Set number of automatic lanes
    numberOfAutomaticLanes = newNumberOfAutomaticLanes;

    // If in this moment a new node are being created
    if(temporalNode)
    {
        // If temporal Node has incoming edges
        if(temporalNode->iteratorIncomingEdgesBegin() != temporalNode->iteratorIncomingEdgesEnd())
        {
            // Get pointer to unique incoming edge of the temporal Node
            edgeItem *incomingEdge = temporalNode->getFirstIncomingEdge();

            // If the number of lanes of the unique incoming edge is less than the numberOfAutomaticLanes
            if(incomingEdge->getNumberOfLanes() < numberOfAutomaticLanes)
            {
                // While the number of lanes of the unique incoming edge is different of the numberOfAutomaticLanes
                while(incomingEdge->getNumberOfLanes() != numberOfAutomaticLanes)
                {
                    // Insert new lane in the unique incoming edge
                    new laneItem(incomingEdge, database);
                }
            }
            // If the number of lanes of the unique incoming edge is more than the numberOfAutomaticLanes
            else if(incomingEdge->getNumberOfLanes() > numberOfAutomaticLanes)
            {
                // While the number of lanes of the unique incoming edge is different of the numberOfAutomaticLanes
                while(incomingEdge->getNumberOfLanes() != numberOfAutomaticLanes)
                {
                    // Insert new lane in the unique incoming edge
                    delete (*(incomingEdge->iteratorLanesBegin()));
                }
            }
        }

        // If the option "double edge" is enabled
        if(doubleEdge)
        {
            // If temporal Node has outcomings edges
            if(temporalNode->iteratorOutcomingEdgesBegin() != temporalNode->iteratorOutcomingEdgesEnd())
            {
                // Get pointer to unique outcoming edge of the temporal Node
                edgeItem *outcomingEdge = temporalNode->getFirstOutcomingEdge();

                // If the number of lanes of the unique outcoming edge is less than the numberOfAutomaticLanes
                if(outcomingEdge->getNumberOfLanes() < numberOfAutomaticLanes)
                {
                    // While the number of lanes of the unique outcoming edge is different of the numberOfAutomaticLanes
                    while(outcomingEdge->getNumberOfLanes() != numberOfAutomaticLanes)
                    {
                        // Insert new lane in the unique outcoming edge
                        new laneItem(outcomingEdge, database);
                    }
                }
                // If the number of lanes of the unique outcoming edge is more than the numberOfAutomaticLanes
                else if(outcomingEdge->getNumberOfLanes() > numberOfAutomaticLanes)
                {
                    // While the number of lanes of the unique outcoming edge is different of the numberOfAutomaticLanes
                    while(outcomingEdge->getNumberOfLanes() != numberOfAutomaticLanes)
                    {
                        // Insert new lane in the unique outcoming edge
                        delete (*(outcomingEdge->iteratorLanesBegin()));
                    }
                }
            }
        }

        if(lastInsertedNode != NULL)
        {
            // Reset and create automatic connections
            resetAndCreateAutomaticConnections(lastInsertedNode);
        }

        // Remake edge and their adyacents
        temporalNode->make();
    }
}

nodeItem *eNetEditorScene::insertNodeInScene(qreal posx, qreal posy)
{
    // Create new node
    nodeItem *n = new nodeItem("", posx, posy, database);

    // Add Item to Database
    if (n)
    {
        // Emit positive console Message
        getMessages()->writeInConsole("Created node with ID = '" + n->getItemId() + "' in position (" + QString::number(n->getPosx()) + "," + QString::number(n->getPosy()) + ").", consoleMessageTypeNormal);

        // Node added, then return true
        return n;
    }
    else
    {
        // Emit positive console Message
        getMessages()->writeInConsole("Error in the insertion of node in Database in the position (" + QString::number(n->getPosx()) + "," + QString::number(n->getPosy()) + ").", consoleMessageTypeError);

        // Delete the created node
        delete n;

        // Node not added, then return false
        return false;
    }
}

edgeItem *eNetEditorScene::insertEdgeInScene(nodeItem *nodeOrigin, nodeItem *nodeDestiny)
{
    // If the nodes exists AND are different
    if((nodeOrigin != NULL) && (nodeDestiny != NULL) && (nodeOrigin != nodeDestiny))
    {
        // Try to find the edge, if exist.
        edgeItem *e = database->findEdgeById(nodeOrigin->getItemId() + "to" + nodeDestiny->getItemId());

        // If the edge not exist
        if (e == NULL)
        {
            // Create new edge
            e = new edgeItem(nodeOrigin, nodeDestiny, database);

            // Add edge to database
            if (e)
            {
                // Emit console Message if the edge was inserted
                getMessages()->writeInConsole("Created edge '" + e->getItemId() + "' between node '" + nodeOrigin->getItemId() + "' and node '" + nodeDestiny->getItemId() + "'.", consoleMessageTypeNormal);

                // If created edge has lanes
                if(e->getNumberOfLanes() > 0)
                {
                    // Emit console Message
                    getMessages()->writeInConsole("Created lane in edge '" + e->getItemId() + "' with Index = '" + QString::number(e->getFirstLane()->getIndex()) + "'.", consoleMessageTypeNormal);
                }

                // Edge and laned inserted, then return true
                return e;
            }
            else
            {
                // Emit error message
                getMessages()->writeInConsole("Error with the insertion in the Database of the edge '" + e->getItemId() + "' between node '" + nodeOrigin->getItemId() + "' and node '" + nodeDestiny->getItemId() + "'.", consoleMessageTypeError);

                // Edge not inserted, them return false
                return false;
            }
        }
        else
        {
            // Create new Lane
            laneItem *l = new laneItem(e, database);

            // Emit console Message
            getMessages()->writeInConsole("Created lane in edge '" + e->getItemId() + "' with Index = '" + QString::number(l->getIndex()) + "'.", consoleMessageTypeNormal);

            // Lane added, then return true
            return e;
        }
    }
    // If both nodes are the same
    else
    {
        // Emit console Warning
        getMessages()->writeInConsole("Warning: A edge between the same node are not allowed. Edge/lane not created.", consoleMessageTypeWarning);

        // Edge not added, then return false.
        return NULL;
    }
}

connectionItem *eNetEditorScene::insertConnectionInScene(laneItem *laneOrigin, laneItem *laneDestiny)
{
    // If Lane Origin and lane Destiny exist AND are differents
    if((laneOrigin != NULL) && (laneDestiny != NULL) && (laneOrigin != laneDestiny))
    {
        // If selfconnection is disabled
        if(allowSelfconnection == false)
        {
            // if this is a selfconnection
            if(laneOrigin->getEdgeParent()->getNodeOrigin() == laneDestiny->getEdgeParent()->getNodeDestiny())
            {
                // Don't insert connection, and then return NULL
                return NULL;
            }
        }

        // Check if the connection exist already in the database
        if(database->findConnectionByComponents(laneOrigin, laneDestiny) != NULL)
        {
            // Emit console Message
            getMessages()->writeInConsole("Warning: exists already a connection between lane '" + laneOrigin->getItemId() + "' and lane '" + laneDestiny->getItemId() + "'.", consoleMessageTypeWarning);

            // Connection already exist, then return false
            return NULL;
        }

        // Create new connection
        connectionItem *c = new connectionItem(laneOrigin, laneDestiny, database);

        // If the connection was created
        if(c)
        {
            // If the new connection is in a node that is a traffic light
            if(laneOrigin->getEdgeParent()->getNodeDestiny()->isTrafficLight())
            {
                // Vinculate connection and traffic light
                c->setTrafficLight(laneOrigin->getEdgeParent()->getNodeDestiny()->getTrafficLight());
            }

            // Emit console Message
            getMessages()->writeInConsole("Created connection between lane '" + laneOrigin->getEdgeParent()->getItemId() + "[" + QString::number(laneOrigin->getIndex()) + "]' and lane '" + laneDestiny->getEdgeParent()->getItemId() + "[" + QString::number(laneDestiny->getIndex()) + "]'.", consoleMessageTypeNormal);

            // Prohibition added, then return true
            return c;
        }
        else
        {
            // Emit console message
            getMessages()->writeInConsole("Error. connection was not inserted in the database, possible integrity error.", consoleMessageTypeError);

            // Deleted created connection
            delete c;

            // Connection was not inserted, then return false
            return NULL;
        }
    }
    else
    {
        // Emit console Warning
        getMessages()->writeInConsole("Warning: A connection betwee the same lane is not allowed. Connection not created.", consoleMessageTypeWarning);

        // Connection not created, then return false
        return NULL;
    }
}

prohibitionItem *eNetEditorScene::insertProhibitionInScene(edgeItem *edgeOrigin, edgeItem *edgeDestiny)
{
    // If Lane Origin and lane Destiny exist AND are differents
    if((edgeOrigin != NULL) && (edgeDestiny != NULL) && (edgeOrigin != edgeDestiny))
    {
        // Check if the prohibition already exist
        if(database->findProhibitionByComponents(edgeOrigin, edgeDestiny) != NULL)
        {
            // Emit console Message
            getMessages()->writeInConsole("Warning: exists already a prohibition between edge '" + edgeOrigin->getItemId() + "' and edge '" + edgeDestiny->getItemId() + "'.", consoleMessageTypeWarning);

            // Prohibition already exist, then return false
            return false;
        }

        // Try to insert lane to database
        prohibitionItem *p = new prohibitionItem(edgeOrigin, edgeDestiny, database);

        // If prohibition was created and inserted inserted
        if(p)
        {
            // Emit console Message
            getMessages()->writeInConsole("Created prohibition between '" + edgeOrigin->getItemId() + "' and '" + edgeDestiny->getItemId() + "'.", consoleMessageTypeNormal);

            // Prohibition added, then return true
            return p;
        }
        else
        {
            // Emit console message
            getMessages()->writeInConsole("Error. prohibition was not inserted in the database, possible integrity error.", consoleMessageTypeError);

            // Deleted created prohibition
            delete p;

            // prohibition was not inserted, then return false
            return NULL;
        }
    }
    else
    {
        // Emit console Warning
        getMessages()->writeInConsole("Warning: A prohibition betwee the same lane is not allowed. prohibition not created.", consoleMessageTypeWarning);

        // Prohibition not added, then return false
        return NULL;
    }
}

trafficLightItem *eNetEditorScene::insertTrafficLightInScene(nodeItem *n)
{
    // If node isn't a traffic Light
    if (n->getType() != nodeItemTypeTrafficLight)
    {
        // save old ID
        QString aux = n->getItemId();

        // Set node type to traffic Light
        n->setType(nodeItemTypeTrafficLight);

        // Change node ID
        n->setItemId("tl" + aux);

        // Create Traffic Light
        trafficLightItem *tl = new trafficLightItem(n, database);

        // If traffic Light waas created
        if(tl)
        {
            // Emit console message
            getMessages()->writeInConsole("Node with ID = '" + aux + "' is now a Traffic Light with ID = '" + n->getItemId() + "'.", consoleMessageTypeNormal);

            // n is a traffic light, then return true
            return tl;
        }
        else
        {
            // Write error Message
            getMessages()->writeInConsole("Error inserting a traffic light in node with ID = '" + n->getItemId() + "'.", consoleMessageTypeError);

            // Error creating a new traffic Light, then return false
            return NULL;
        }
    }
    else
    {
        // Emit console message
        getMessages()->writeInConsole("Node with ID = '" + n->getItemId() + "' is already a Traffic Light.", consoleMessageTypeWarning);

        // n is a traffic light, then return true
        return n->getTrafficLight();
    }
}

routeItem *eNetEditorScene::insertOrUpdateRouteInScene(edgeItem *edgeOrigin, edgeItem *edgeDestiny)
{
    // If we want to add one more edge to a marked route
    if((edgeOrigin != NULL) && (edgeDestiny != NULL))
    {
        /** CAMBIAR ESTO **/

        // Create new route (The ID will be added automatic after insertion in Database)
        routeItem *r = new routeItem("", edgeOrigin, edgeDestiny, database);

        // Try to insert route to Database
        if(r)
        {
            // Mark route added
            parameterManager->markRoute(r);

            // Emit console message
            getMessages()->writeInConsole("Added route with ID = '" + r->getItemId() + "'.", consoleMessageTypeNormal);

            // Route added, then return true
            return r;
        }
        else
        {
            // Delete created route
            delete r;

            // Emit console message
            getMessages()->writeInConsole("Error adding route to database.", consoleMessageTypeError);

            // Route not added, then return false.
            return NULL;
        }
    }
    else
    {
        // Emit console message
        getMessages()->writeInConsole("Error creating route.", consoleMessageTypeError);

        // route not created, then return true;
        return NULL;
    }
}

busStopItem *eNetEditorScene::insertBusStopInScene(laneItem *laneParent)
{
    // Check if laneParent exist
    if (laneParent != NULL)
    {
        // Create Bus Stop
        busStopItem *bs = new busStopItem("", laneParent, database);

        // If bus Stop was sucesfully created
        if (bs)
        {
            // Emit console message
            getMessages()->writeInConsole("Inserted Bus Stop with ID = '" + bs->getItemId() + "' in lane with ID = '" + bs->getLane()->getItemId() + "'.", consoleMessageTypeNormal);

            // Open Dialog to configure the new Bus Stop
            project->geteNetEditorMainWindow()->getBusStopTableDialog()->getBusStopItemDialog()->openItemDialog(bs);

            // Bus station inserted, then return true
            return bs;
        }
        else
        {
            // Emit console message
            getMessages()->writeInConsole("Error: Bus Station cannnot be inserted in the Database, possible Integrity error.", consoleMessageTypeError);

            // Delete the created Bus Station
            delete bs;

            // Bus Station not inserted, then return false.
            return NULL;
        }
    }
    else
    {
        // Emit console message
        getMessages()->writeInConsole("Error: Bus Stop cannot be inserted, the lane parent don't exist.", consoleMessageTypeError);

        // Bus Station not inserted, then return false.
        return false;
    }
}

chargingStationItem *eNetEditorScene::insertChargingStationInScene(laneItem *laneParent)
{
    // Check if laneParent exist
    if (laneParent != NULL)
    {
        // Create Charging station
        chargingStationItem *cs = new chargingStationItem("", laneParent, database);

        // If the charging station was sucesfully created
        if (cs)
        {
            // Emit console message
            getMessages()->writeInConsole("Inserted charging station with ID = '" + cs->getItemId() + "' in lane with ID = '" + cs->getLane()->getItemId() + "'.", consoleMessageTypeNormal);

            // Open Dialog to configure the new Bus Stop
            project->geteNetEditorMainWindow()->getChargingStationTableDialog()->getChargingStationItemDialog()->openItemDialog(cs);

            // Bus station inserted, then return true
            return cs;
        }
        else
        {
            // Emit console message
            getMessages()->writeInConsole("Error: Charging Station cannnot be inserted in the Database, possible Integrity error.", consoleMessageTypeError);

            // Delete the created Bus Station
            delete cs;

            // Bus Station not inserted, then return false.
            return NULL;
        }
    }
    else
    {
        // Emit console message
        getMessages()->writeInConsole("Error: Charging Station cannot be inserted, the lane parent don't exist.", consoleMessageTypeError);

        // Bus Station not inserted, then return false.
        return false;
    }
}

void eNetEditorScene::resetAndCreateAutomaticConnections(nodeItem *n)
{
    /**
    // Reset connections
    database->resetConnections(n);

    // Declare counters
    int counterA = 0;
    int counterB = 0;

    // Declare pointers to lanes
    laneItem *lane1 = NULL;
    laneItem *lane2 = NULL;

    for(QList<edgeItem*>::iterator i = n->iteratorIncomingEdgesBegin(); i != n->iteratorIncomingEdgesEnd(); i++)
    {
        for(QList<edgeItem*>::iterator j = n->iteratorOutcomingEdgesBegin(); j != n->iteratorOutcomingEdgesEnd(); j++)
        {
            //if((*i)->getNodeOrigin() != (*j)->getNodeDestiny())
            {
                counterA = -1;
                counterB = -1;

                // While counters are lower than sizes of lists
                while(((*i)->getLaneByIndex(counterA+1)) || ((*j)->getLaneByIndex(counterB+1)))
                {
                    // If this is not the last Lane 1
                    if((*i)->getLaneByIndex(counterA+1) != NULL)
                    {
                        counterA++;

                        // Get pointer to lane 1
                        lane1 = (*i)->getLaneByIndex(counterA);
                    }

                    // If this is not the last Lane 2
                    if((*j)->getLaneByIndex(counterB+1) != NULL)
                    {
                        counterB++;

                        // Get pointer to lane 2
                        lane2 = (*j)->getLaneByIndex(counterB);
                    }

                    // Crate connection between two lanes
                    insertConnectionInScene(lane1, lane2);
                }
            }
        }
    }
    **/
}



/*
    for(QList<edgeItem*>::iterator i = n->iteratorIncomingEdgesBegin(); i != n->iteratorIncomingEdgesEnd(); i++)
    {
        if((*i)->getNumberOfLanes() > maxLane)
        {
            maxLane = (*i)->getNumberOfLanes();
        }
    }

    for(QList<nodeItem*>::iterator i = n->iteratorOutcomingEdgesBegin(); i != n->iteratorOutcomingEdgesEnd(); i++)
    {
        if((*i)->getNumberOfLanes() > maxLane)
        {
            maxLane = (*i)->getNumberOfLanes();
        }
    }

    for(int i = 0; i < maxLane; i++)
    {
        for(QList<edgeItem*>::iterator j = n->iteratorIncomingEdgesBegin(); j != n->iteratorIncomingEdgesEnd(); j++)
        {
            for(QList<nodeItem*>::iterator k = n->iteratorOutcomingEdgesBegin(); k != n->getListOfOutcomingsEdges(); k++)
            {
                laneItem *L1;
                laneItem *L2;

                if((*i)->getNumberOfLanes() < )
                database->insertNewConnectionInSceneAndDatabase()
            }

        }
    }

    */

bool eNetEditorScene::removeNode(nodeItem *n)
{
    // if the item node exist (the casting was sucesfully)
    if(n)
    {
        // If the node is a traffic light
        if(n->getType() == nodeItemTypeTrafficLight)
        {
            // first remove the associated traffic light
            removeTrafficLight(n);
        }

        // Try to erase element of the database and scene
        if(true)//if(database->eraseNodeOfSceneAndDatabase(n))
        {

            delete n;

            // Node removed, then return true
            return true;
        }
        else
        {
            // Show error message
            getMessages()->writeInConsole("Error deleting node with ID = '" + n->getItemId() + "', don't exist in the database.", consoleMessageTypeError);

            // Node not removed, then return false
            return false;
        }
    }
    else
    {
        // the item isn't a node, then return false
        return false;
    }
}

bool eNetEditorScene::removeLane(laneItem *l)
{
    // If the item lane exist
    if(l)
    {
        // Keep node Origin and destiny of lane
        nodeItem *nodeOrigin = l->getEdgeParent()->getNodeOrigin();
        nodeItem *nodeDestiny = l->getEdgeParent()->getNodeDestiny();

        // Remove Lane
        delete l;

        // Reset and create automatic connections in node origin
        resetAndCreateAutomaticConnections(nodeOrigin);

        // Reset and ceate automatic connections in node destiny
        resetAndCreateAutomaticConnections(nodeDestiny);

        // Lane erased, then return true
        return true;
    }
    else
    {
        // Show error message
        getMessages()->writeInConsole("Error deleting lane, don't exist.", consoleMessageTypeError);

        // Lane not erased, then return false
        return false;
    }
}

bool eNetEditorScene::removeConnection(connectionItem *c)
{
    // If the item connection exist
    if (c)
    {
        // Delete connection
        delete c;

        // Connection removed, then return true
        return true;
    }
    else
    {
        // Show error message
        getMessages()->writeInConsole("Error deleting connection, don't exist.", consoleMessageTypeError);

        // The item isn't a Connection, then return false
        return false;
    }
}

bool eNetEditorScene::removeProhibition(prohibitionItem *p)
{
    // If the item prohibition exist
    if (p)
    {
        // Delete prohibition
        delete p;

        // Prohibition erased, then return true
        return true;
    }
    else
    {
        // Show error message
        getMessages()->writeInConsole("Error deleting prohibition, don't exist.", consoleMessageTypeError);

        // Prohibition not removed, then return false
        return false;
    }
}



bool eNetEditorScene::removeTrafficLight(nodeItem *n)
{
    // If the iten node exist
    if(n)
    {
        // If the node is an Traffic light
        if(n->isTrafficLight())
        {
            // save old ID
            QString oldNodeId = n->getItemId();

            // Delete traffic light of the database
            delete (n->getTrafficLight());

            // Set node type to priority
            n->setType(nodeItemTypePriority);

            // Change node ID
            n->setItemLabel(oldNodeId.remove(0, 2));

            // Emit console message
            getMessages()->writeInConsole("Node with ID '" + oldNodeId + "' is now a normal node with ID = '" + n->getItemId() + "'.", consoleMessageTypeNormal);

            // Traffic light erased, then return true
            return true;
        }
        else
        {
            // Node isn't a Traffic light, then return false
            return false;
        }
    }
    else
    {
        // Item isn't a node, then return false
        return false;
    }
}

bool eNetEditorScene::removeRoute(routeItem *r)
{
    // If the item route exist
    if(r)
    {
        // Delete route
        delete r;

        // Bus stop erased, then return true
        return true;
    }
    else
    {
        // Show error message
        getMessages()->writeInConsole("Error deleting route, don't exist.", consoleMessageTypeError);

        // Item isn't a bus stop, then return false
        return false;
    }
}





void eNetEditorScene::processOperationAddNodeOrEdgeOrLane(QGraphicsItem *item)
{
    // Cast node to Item
    nodeItem *n = dynamic_cast<nodeItem *>(item);

    // If was clicke over a empty area or over a node
    if((item == NULL) || (item == temporalNode))
    {
        // Set lastInsertedNode with the currently temporalNode
        lastInsertedNode = temporalNode;

        // Add node to scene and database (And link it with the variable temporal node
        temporalNode = insertNodeInScene(posx, posy);

        // If during this process shift key is pulsed
        if(shiftKeyPressed && (lastInsertedNode != NULL) && (temporalNode != NULL))
        {
            // Create and edge between lastInsertedNode and temporalNode
            edgeItem *e = insertEdgeInScene(lastInsertedNode, temporalNode);

            // Insert automatic Lanes
            for(int i = 1; i < numberOfAutomaticLanes; i++)
            {
                new laneItem(e, database);
            }

            // Reset and create automatic connections in node Origin of edge
            resetAndCreateAutomaticConnections(e->getNodeOrigin());

            // Reset and create automatic connections in node Destiny of edge
            resetAndCreateAutomaticConnections(e->getNodeDestiny());

            // If option Double edge is enabled
            if(doubleEdge)
            {
                // Insert inverse edge
                e = insertEdgeInScene(temporalNode, lastInsertedNode);

                // Insert automatic Lanes in the inverse edge
                for(int i = 1; i < numberOfAutomaticLanes; i++)
                {
                    new laneItem(e, database);
                }

                // Reset and create automatic connections in node Origin of inverse edge
                resetAndCreateAutomaticConnections(e->getNodeOrigin());

                // Reset and create automatic connections in node Destiny of inverse edge
                resetAndCreateAutomaticConnections(e->getNodeDestiny());
            }
        }
    }
    // If selected item is a node, but NOT temporal node
    else if ((item != NULL) && (n != NULL) && (n != temporalNode))
    {
        // If previously there isn't a marked node
        if (parameterManager->getListOfNodesMarked()->size() == 0)
        {
            // Node clicked is now marked
            parameterManager->markNode(n);
        }
        // If previously there is a marked node
        else
        {
            // Get marked node
            nodeItem *nOrigin = parameterManager->getListOfNodesMarked()->first();

            // Dismark all nodes
            parameterManager->dismarkAllNodes();

            // If marked node is different of selected node
            if(nOrigin != n)
            {
                // Create and edge between the marked node and currently node
                edgeItem *e = insertEdgeInScene(nOrigin, n);

                // Insert automatic Lanes
                for(int i = 1; i < numberOfAutomaticLanes; i++)
                {
                    new laneItem(e, database);
                }

                // Reset and create automatic connections in node Origin of edge
                resetAndCreateAutomaticConnections(e->getNodeOrigin());

                // Reset and create automatic connections in node Destiny of edge
                resetAndCreateAutomaticConnections(e->getNodeDestiny());

                // If option Double edge is enabled
                if(doubleEdge)
                {
                    // Insert inverse edge
                    e = insertEdgeInScene(n, nOrigin);

                    // Insert automatic Lanes in the inverse edge
                    for(int i = 1; i < numberOfAutomaticLanes; i++)
                    {
                        new laneItem(e, database);
                    }

                    // Reset and create automatic connections in node Origin of inverse edge
                    resetAndCreateAutomaticConnections(e->getNodeOrigin());

                    // Reset and create automatic connections in node Destiny of inverse edge
                    resetAndCreateAutomaticConnections(e->getNodeDestiny());
                }
            }
        }
    }
}

void eNetEditorScene::processOperationAddConnection(QGraphicsItem *item)
{
    /**
    // If previously there isn't a marked lane
    if(temporalLane == NULL)
    {
        // Cast item to laneItem
        laneItem *l = dynamic_cast<laneItem*>(item);

        // If casted item is a lane
        if (l != NULL)
        {
            // Set temporal Lane
            temporalLane = l;

            // Mark Lane
            parameterManager->markLane(l);

            // Set as selectables only the outcomings lanes of the node of the connection
            for(QList<edgeItem*>::iterator i = l->getEdgeParent()->getNodeDestiny()->iteratorOutcomingEdgesBegin(); i != l->getEdgeParent()->getNodeDestiny()->iteratorOutcomingEdgesEnd(); i++)
            {
                for(QList<laneItem*>::iterator j = (*i)->iteratorLanesBegin(); j != (*i)->iteratorLanesEnd(); j++)
                {
                    (*j)->setItemSelectable(true);
                }
            }

            // Show all outcomingsConnections
            for(QList<connectionItem*>::iterator i = l->iteratorOutcomingsConnectionsBegin(); i != l->iteratorOutcomingsConnectionsEnd(); i++)
            {
                // Change flag show item
                ;//(*i)->setShowItem(true);
            }
        }
    }
    // else if previously there are a marked lane
    else
    {
        // If none item was selected
        if(item == NULL)
        {
            // If previously there are a marked lane
            if (temporalLane != NULL)
            {
                // Set as no selectables only the outcomings lanes of the node of the connection
                for(QList<edgeItem*>::iterator i = temporalLane->getEdgeParent()->getNodeDestiny()->iteratorOutcomingEdgesBegin(); i != temporalLane->getEdgeParent()->getNodeDestiny()->iteratorOutcomingEdgesEnd(); i++)
                {
                    for(QList<laneItem*>::iterator j = (*i)->iteratorLanesBegin(); j != (*i)->iteratorLanesEnd(); j++)
                    {
                        (*j)->setItemSelectable(false);
                    }
                }

                // Hidde all outcomingsConnections
                for(QList<connectionItem*>::iterator i = temporalLane->iteratorOutcomingsConnectionsBegin(); i != temporalLane->iteratorOutcomingsConnectionsEnd(); i++)
                {
                    // Change flag show item
                    ;//(*i)->setShowItem(false);
                }

                // DismarkLane
                parameterManager->dismarkAllLanes();

                // Set temporal lane to NULL
                temporalLane = NULL;
            }
        }
        // If a certain item was selected
        else
        {
            // Casting item to lane
            laneItem *l = dynamic_cast<laneItem*>(item);

            // Check if item is a lane
            if ((l != NULL) && (l != temporalLane))
            {
                // if the lane clicked is selectable
                if(l->isItemSelectable())
                {
                    // Add connection between the marked lane and the lane clicked
                    connectionItem* c = insertConnectionInScene(parameterManager->getListOfLanesMarked()->first(), l);

                    // if connection was sucesfully created
                    if(c)
                    {
                        // Show new connection created
                        ;//c->setShowItem(true);

                        // Disable item selectable of all lanes marked previously
                        for(QList<laneItem*>::iterator i = parameterManager->getListOfLanesMarked()->begin(); i != parameterManager->getListOfLanesMarked()->end(); i++)
                        {
                            for(QList<edgeItem*>::iterator j = (*i)->getEdgeParent()->getNodeDestiny()->iteratorOutcomingEdgesBegin(); j != (*i)->getEdgeParent()->getNodeDestiny()->iteratorOutcomingEdgesEnd(); j++)
                            {
                                for(QList<laneItem*>::iterator k = (*j)->iteratorLanesBegin(); k != (*j)->iteratorLanesEnd(); k++)
                                {
                                    (*k)->setItemSelectable(false);
                                }
                            }
                        }
                    }
                }
                else
                {
                    // Emit console Message
                    getMessages()->writeInConsole("Warning: item not valid. Only outcomings lanes.", consoleMessageTypeWarning);
                }
            }
        }
    }
    **/
}

void eNetEditorScene::processOperationAddProhibition(QGraphicsItem *item)
{
    // If the item is NULL
    if(item == NULL)
    {
        // Dismark all items of the database
        parameterManager->dismarkAllItems();

        // Unblock all edge Parameters
        parameterManager->setBlockAllEdges(false);
    }
    // If a item was selected
    else
    {
        // Casting item to edge
        edgeItem *e = dynamic_cast<edgeItem *>(item);

        // Check if item is a edge and isn't blocked
        if ((e != NULL) && (e->isItemSelectable()))
        {
            // If previously a edge was not marked
            if (parameterManager->getListOfEdgesMarked()->size() == 0)
            {
                // Mark edge
                parameterManager->markEdge(e);

                // Block all edges of the scenario
                parameterManager->setBlockAllEdges(true);

                // Unblocks only the outcomings edges of the node of the connection
                for(QList<edgeItem *>::iterator i = e->getNodeDestiny()->iteratorOutcomingEdgesBegin(); i != e->getNodeDestiny()->iteratorOutcomingEdgesEnd(); i++)
                {
                    (*i)->setItemSelectable(true);
                }
            }
            else
            {
                //Add prohibition between the marked edge and the new edge
                insertProhibitionInScene(parameterManager->getListOfEdgesMarked()->first(), e);

                // Dismark selected edge
                parameterManager->dismarkAllEdges();

                // Unblock all edge Parameters
                parameterManager->setBlockAllEdges(false);
            }
        }
    }
}

void eNetEditorScene::processOperationAddRoute(QGraphicsItem *item)
{
    // If grabbed item
    if (item == NULL)
    {
        // If previously there are a marked route, disable eges selected of the last outcomings edges
        for(QList<routeItem *>::iterator i = parameterManager->getListOfRoutesMarked()->begin(); i != parameterManager->getListOfRoutesMarked()->end(); i++)
        {
            for(QList<edgeItem *>::iterator j = (*i)->getListOfEdges()->last()->getNodeDestiny()->iteratorOutcomingEdgesBegin(); j != (*i)->getListOfEdges()->last()->getNodeDestiny()->iteratorOutcomingEdgesEnd(); j++)
            {
                (*j)->setItemSelectable(false);
            }
        }

        // Disable item selectable of all edges marked previously
        for(QList<edgeItem *>::iterator i = parameterManager->getListOfEdgesMarked()->begin(); i != parameterManager->getListOfEdgesMarked()->end(); i++)
        {
            for(QList<edgeItem *>::iterator j = (*i)->getNodeDestiny()->iteratorOutcomingEdgesBegin(); j != (*i)->getNodeDestiny()->iteratorOutcomingEdgesEnd(); j++)
            {
                (*j)->setItemSelectable(false);
            }
        }

        // Dismark all items of the database
        parameterManager->dismarkAllItems();
    }
    else
    {
        // Try to cast item to edge and to route
        edgeItem *e = dynamic_cast<edgeItem *>(item);
        routeItem *r = dynamic_cast<routeItem *>(item);

        // If item is a edge
        if(e != NULL)
        {
            // If previously we have a marked route AND the edge selected is marked
            if(parameterManager->getListOfRoutesMarked()->size() > 0)
            {
                // If edge clicked id selectable
                if(e->isItemSelectable())
                {
                    // Get a pointer for the edge marked edge
                    edgeItem *edgeLast = parameterManager->getListOfRoutesMarked()->first()->getListOfEdges()->last();

                    // Disable flag selectionable for all outcomings edges of edgeLast
                    for(QList<edgeItem *>::iterator i = edgeLast->getNodeDestiny()->iteratorOutcomingEdgesBegin(); i != edgeLast->getNodeDestiny()->iteratorOutcomingEdgesEnd(); i++)
                    {
                        (*i)->setItemSelectable(false);
                    }

                    // Add selected edge to route
                    parameterManager->getListOfRoutesMarked()->first()->addEdge(e);

                    // Enable flag selectionable for all outcomings edges of the last inserted edge
                    for(QList<edgeItem *>::iterator i = e->getNodeDestiny()->iteratorOutcomingEdgesBegin(); i != e->getNodeDestiny()->iteratorOutcomingEdgesEnd(); i++)
                    {
                        (*i)->setItemSelectable(true);
                    }
                }
            }
            else
            {
                // If previously there are a marked edge
                if((parameterManager->getListOfEdgesMarked()->size() > 0))
                {
                    // If the edge cliked is selectionable
                    if ((e->isItemSelectable()))
                    {
                        // Disable flag selectionable for all outcomings edges of the marked edge
                        for(QList<edgeItem *>::iterator i = parameterManager->getListOfEdgesMarked()->first()->getNodeDestiny()->iteratorOutcomingEdgesBegin(); i != parameterManager->getListOfEdgesMarked()->first()->getNodeDestiny()->iteratorOutcomingEdgesEnd(); i++)
                        {
                            (*i)->setItemSelectable(false);
                        }

                        // Create a new route between the marked edge and the new edge
                        routeItem *newr = insertOrUpdateRouteInScene(parameterManager->getListOfEdgesMarked()->first(), e);

                        // Dismark marked edge
                        parameterManager->dismarkAllEdges();

                        // If was sucesfully created
                        if(newr != NULL)
                        {
                            // Mark created route
                            parameterManager->markRoute(newr);

                            // Enable flag selectionable for all outcomings edges of the edge e
                            for(QList<edgeItem *>::iterator i = e->getNodeDestiny()->iteratorOutcomingEdgesBegin(); i != e->getNodeDestiny()->iteratorOutcomingEdgesEnd(); i++)
                            {
                                (*i)->setItemSelectable(true);
                            }
                        }
                    }
                }
                // If previously we don't have a marked edge
                else
                {
                    // Mark first edge of the route
                    parameterManager->markEdge(e);

                    // Enable flag selectionable for all outcomings edges of the edge e
                    for(QList<edgeItem *>::iterator i = e->getNodeDestiny()->iteratorOutcomingEdgesBegin(); i != e->getNodeDestiny()->iteratorOutcomingEdgesEnd(); i++)
                    {
                        (*i)->setItemSelectable(true);
                    }
                }
            }
        }
        // If item is a route
        else if (r)
        {
            // If previously we have a marked route
            if(parameterManager->getListOfEdgesMarked()->size() > 0)
            {
                // Dismark route
                parameterManager->dismarkAllRoutes();
            }

            // Mark route
            parameterManager->markRoute(r);
        }
    }
}

void eNetEditorScene::processOperationAddTrafficLight(QGraphicsItem *item)
{
    // If grabbed item
    if (item != NULL)
    {
        // Try to convert the grabbed item to node
        nodeItem *n = dynamic_cast<nodeItem *>(item);

        // If grabbed item is a Node
        if(n)
        {
            // Add traffic light
            insertTrafficLightInScene(n);
        }
        else
        {
            // Emit warning
            getMessages()->writeInConsole("Warning: Only nodes can be converted to traffic lights", consoleMessageTypeWarning);
        }
    }
}

void eNetEditorScene::processOperationAddBusStop(QGraphicsItem *item)
{
    // If grabbed item
    if (item != NULL)
    {
        // Try to cast item to lane
        laneItem *l = dynamic_cast<laneItem *>(item);

        // If grabbed item is a lane
        if (l)
        {
            // Add Bus Stop
            insertBusStopInScene(l);

            /** Update label with the number of bus stations **/
        }
        else
        {
            // Emit warning
            getMessages()->writeInConsole("Warning: BusStops can only be placed over Lanes", consoleMessageTypeWarning);
        }
    }
}

void eNetEditorScene::processOperationAddChargingStation(QGraphicsItem *item)
{
    // If grabbed item
    if (item != NULL)
    {
        // Try to cast item to lane
        laneItem *l = dynamic_cast<laneItem *>(item);

        // If grabbed item is a lane
        if (l)
        {
            // Add Bus Stop
            insertChargingStationInScene(l);

            /** Update label with the number of bus stations **/
        }
        else
        {
            // Emit warning
            getMessages()->writeInConsole("Warning: Charging Stations can only be placed over Lanes", consoleMessageTypeWarning);
        }
    }
}

void eNetEditorScene::processOperationRemoveNodeOrEdgeOrLane(QGraphicsItem *item)
{
    if(item != NULL)
    {
        // If item is the temporal node
        if(item == temporalNode)
        {
            // Remove temporal node
            removeNode(dynamic_cast<nodeItem *>(item));

            // Set temporal node pointer to null
            temporalNode = NULL;
            lastInsertedNode = NULL;
        }
        // If item is a Node
        else if(dynamic_cast<nodeItem *>(item))
        {
            // Remove Node
            removeNode(dynamic_cast<nodeItem *>(item));
        }
        // If item is an Edge
        else if(dynamic_cast<edgeItem *>(item))
        {
            // Remove edge
            delete (dynamic_cast<edgeItem *>(item));
        }
        // Else if item is a Lane
        else if (dynamic_cast<laneItem *>(item))
        {
            // Get Edge Parent of lane
            edgeItem *e = dynamic_cast<laneItem *>(item)->getEdgeParent();

            // Remove lane
            removeLane(dynamic_cast<laneItem *>(item));

            // If after deletion of lane edge parent don't have more Lanes
            if(e->getNumberOfLanes() == 0)
            {
                // Delete edge
                delete e;
            }
        }
    }
}

void eNetEditorScene::processOperationRemoveConnection(QGraphicsItem *item)
{
    // If item isn't NULL
    if(item != NULL)
    {
        // Disable item selectable of all lanes marked previously
        for(QList<laneItem *>::iterator i = parameterManager->getListOfLanesMarked()->begin(); i != parameterManager->getListOfLanesMarked()->end(); i++)
        {
            for(QList<edgeItem *>::iterator j = (*i)->getEdgeParent()->getNodeDestiny()->iteratorOutcomingEdgesBegin(); j != (*i)->getEdgeParent()->getNodeDestiny()->iteratorOutcomingEdgesEnd(); j++)
            {
                for(QList<laneItem *>::iterator k = (*j)->iteratorLanesBegin(); k != (*j)->iteratorLanesEnd(); k++)
                {
                    (*k)->setItemSelectable(false);
                }
            }
        }

        // Try to remove item if is a Connection
        removeConnection(dynamic_cast<connectionItem *>(item));
    }
}

void eNetEditorScene::processOperationRemoveProhibition(QGraphicsItem *item)
{
    // If item isn't NULL
    if(item != NULL)
    {
        // Try to remove item if is a prohibition
        removeProhibition(dynamic_cast<prohibitionItem *>(item));
    }
}

void eNetEditorScene::processOperationRemoveRoute(QGraphicsItem *item)
{
    // If item isn't NULL
    if(item != NULL)
    {
        // If previously there are a marked route, Disable eges selected of the last outcomings edges
        for(QList<routeItem *>::iterator i = parameterManager->getListOfRoutesMarked()->begin(); i != parameterManager->getListOfRoutesMarked()->end(); i++)
        {
            for(QList<edgeItem *>::iterator j = (*i)->getListOfEdges()->last()->getNodeDestiny()->iteratorOutcomingEdgesBegin(); j != (*i)->getListOfEdges()->last()->getNodeDestiny()->iteratorOutcomingEdgesEnd(); j++)
            {
                (*j)->setItemSelectable(false);
            }
        }

        // Try to remove route
        removeRoute(dynamic_cast<routeItem *>(item));
    }
}

void eNetEditorScene::processOperationRemoveTrafficLight(QGraphicsItem *item)
{
    // If item isn't NULL
    if(item != NULL)
    {
        // Try to remove traffic light
        removeTrafficLight(dynamic_cast<nodeItem *>(item));
    }
}

void eNetEditorScene::processOperationRemoveBusStop(QGraphicsItem *item)
{
    // Create pointer to bus Stop Item
    busStopItem *bs = dynamic_cast<busStopItem *>(item);

    // If item isn't NULL
    if(bs != NULL)
    {
        // remove BusStop
        delete(bs);
    }
}

void eNetEditorScene::processOperationRemoveChargingStation(QGraphicsItem *item)
{
    // Create pointer to charging station
    chargingStationItem *cs = dynamic_cast<chargingStationItem *>(item);

    // If item isn't NULL
    if(cs != NULL)
    {
        // remove charging Station
        delete(cs);
    }
}


/*
void drawMap::drawBackground(QPainter *painter, const QRectF &rect)
{
    #define adjy 30
    #define adjx 30

    int j = 0;
    int alto = 0;


    QPen pen;
    pen.setWidth(1);
    pen.lawngreen(Qt::lightGray);
    painter->setPen(pen);

    painter->drawText(-225, 10, this->str);
    alto = _alto;  // 50 + 2

    for(int i = 0; i < alto; ++i)
    {
        j = i * adjy - 17;

        painter->drawLine(QPoint(-210, j), QPoint(_ancho, j));
    }

    for(int i = 0; i < 300; ++i)
    {
        j = i * adjx - 210;

        painter->drawLine(QPoint(j, 0), QPoint(j, _ancho * 2));
    }

}
*/

void eNetEditorScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    // Execute father's function mouseMoveEvent
    QGraphicsScene::mouseMoveEvent(mouseEvent);

    // Save mouse position
    posx = mouseEvent->scenePos().x();
    posy = mouseEvent->scenePos().y();

    // If in this moment user is setting a new node
    if(temporalNode != NULL)
    {
        // Set position of temporal node
        temporalNode->setPosx(posx);
        temporalNode->setPosy(posy);

        // make temporal node
        temporalNode->make();
    }

    // Emit signal with the mouse pos
    emit updateMousePos(posx, posy);

    // Update scene
    update();
}

void eNetEditorScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    // Execute QGraphicsScene function
    QGraphicsScene::mouseDoubleClickEvent(event);

    // If double click was did with right button of mouse
    if(event->button() == Qt::LeftButton)
    {
        // Try to get the grabbed item
        QGraphicsItem *item = mouseGrabberItem();

        // If a item was grabbed by the mouse
        if(item)
        {
            // If FlagOperationAddNodeis enabled
            if(flag == flagOperationAddOrRemoveNodeOrEdgeOrLane)
            {
                // Try to cast node
                nodeItem *n = dynamic_cast<nodeItem *>(item);

                // try to cast edge
                edgeItem *e = dynamic_cast<edgeItem *>(item);
                // Try to cast lane

                laneItem *l = dynamic_cast<laneItem *>(item);

                // If the casted item is a node
                if(n)
                {
                    // Open node dialog
                    project->geteNetEditorMainWindow()->getNodeTableDialog()->getNodeItemDialog()->openItemDialog(n);
                }
                // If the casted item is an Edge
                else if(e)
                {
                    // Open edge dialog
                    project->geteNetEditorMainWindow()->getEdgeTableDialog()->getEdgeItemDialog()->openItemDialog(e);
                }
                // If casted item is a lane
                else if(l)
                {
                    // Open lane Dialog
                    project->geteNetEditorMainWindow()->getLaneTableDialog()->getLaneItemDialog()->openItemDialog(l);
                }
            }
            // If FlagOperationAddConnectionis enabled
            else if(flag == flagOperationAddOrRemoveConnection)
            {
                // try to cast connection
                connectionItem *c = dynamic_cast<connectionItem *>(item);

                // If the casted item is a Connection
                if(c)
                {
                    // Open connection dialog
                    project->geteNetEditorMainWindow()->getConnectionTableDialog()->getConnectionItemDialog()->openItemDialog(c);
                }
            }
            // If FlagOperationAddProhibition is enabled
            else if(flag == flagOperationAddOrRemoveProhibition)
            {
                // try to cast prohibition
                prohibitionItem *p = dynamic_cast<prohibitionItem *>(item);

                // If the casted item is a Connection
                if(p)
                {
                    // Open prohibition dialog
                    project->geteNetEditorMainWindow()->getProhibitionTableDialog()->getProhibitionItemDialog()->openItemDialog(p);
                }
            }
            // If FlagOperationAddRoute is enabled
            else if(flag == flagOperationAddOrRemoveRoute)
            {
                // try to cast route
                routeItem *r = dynamic_cast<routeItem *>(item);

                // If the casted item is a route
                if(r)
                {
                    // Open route dialog
                    project->geteNetEditorMainWindow()->getRouteTableDialog()->getRouteItemDialog()->openItemDialog(r);
                }
            }
            // If FlagOperationAddTrafficLight is enabled
            else if(flag == flagOperationAddOrRemoveTrafficLight)
            {
                // try to cast node
                nodeItem *n = dynamic_cast<nodeItem *>(item);

                // If element is a node
                if(n)
                {
                    // If the node is an Traffic Light
                    if(n->isTrafficLight())
                    {
                        // Open Traffic light dialog
                        project->geteNetEditorMainWindow()->getTrafficLightTableDialog()->getTrafficLightItemDialog()->openItemDialog(n->getTrafficLight());
                    }
                }
            }
            // If FlagOperationAddBusStop is enabled
            else if(flag == flagOperationAddOrRemoveDetector)
            {
                // Try to cast inductionLoopsE1DetectorItem
                inductionLoopsE1DetectorItem *dE1 = dynamic_cast<inductionLoopsE1DetectorItem *>(item);

                // Try to cast laneAreaE2DetectorItem
                laneAreaE2DetectorItem *dE2 = dynamic_cast<laneAreaE2DetectorItem *>(item);

                // Try to cast multiEntryExitE3DetectorItem
                multiEntryExitE3DetectorItem *dE3 = dynamic_cast<multiEntryExitE3DetectorItem *>(item);

                // If casted item is an inductionLoopsE1DetectorItem
                if(dE1)
                {
                    //Open inductionLoopsE1DetectorItemDialog
                    project->geteNetEditorMainWindow()->getinductionLoopsE1DetectorTableDialog()->getInductionLoopsE1DetectorItemDialog()->openItemDialog(dE1);
                }
                // If casted item is a laneAreaE2DetectorItem
                else if(dE2)
                {
                    //Open laneAreaE2DetectorItemDialog
                    project->geteNetEditorMainWindow()->getLaneAreaE2DetectorTableDialog()->getLaneAreaE2DetectorItemDialog()->openItemDialog(dE2);
                }
                // If casted item is a multiEntryExitE3DetectorItem
                else if(dE3)
                {
                    //Open multiEntryExitE3DetectorItemDialog
                    project->geteNetEditorMainWindow()->getMultiEntryExitE3DetectorTableDialog()->getMultiEntryExitE3DetectorItemDialog()->openItemDialog(dE3);
                }
            }
            // If FlagOperationAddBusStop is enabled
            else if(flag == flagOperationAddOrRemoveBusStop)
            {
                // Try to cast Bus Stop
                busStopItem *bs = dynamic_cast<busStopItem *>(item);

                // If the item is a Bus Stop
                if(bs)
                {
                    // Open charging Station Dialog
                    project->geteNetEditorMainWindow()->getBusStopTableDialog()->getBusStopItemDialog()->openItemDialog(bs);
                }
            }
            // If FlagOperationAddChargingStation is enabled
            else if(flag == flagOperationAddOrRemoveChargingStation)
            {
                // Try to cast Charging Station
                chargingStationItem *cs = dynamic_cast<chargingStationItem *>(item);

                // If the item is a Charging Station
                if(cs)
                {
                    // Open Charging Station Dialog
                    project->geteNetEditorMainWindow()->getChargingStationTableDialog()->getChargingStationItemDialog()->openItemDialog(cs);
                }
            }
        }
    }
}

void eNetEditorScene::keyPressEvent(QKeyEvent *event)
{
    // If Flag flagOperationAddOrRemoveNodeOrEdgeOrLane is enabled
    if(flag == flagOperationAddOrRemoveNodeOrEdgeOrLane || flag == flagOperationMoveNode)
    {
        // If shift key is pressed
        if(event->key() == Qt::Key_Shift)
        {
            // Change flag shiftKeyPressed
            shiftKeyPressed = true;

            // If lastInsertedNode and TemporalNode != NULL
            if(lastInsertedNode != NULL && temporalNode != NULL)
            {
                // Create and edge between lastInsertedNode and temporalNode
                edgeItem *e = insertEdgeInScene(lastInsertedNode, temporalNode);

                // Insert automatic Lanes
                for(int i = 1; i < numberOfAutomaticLanes; i++)
                {
                    new laneItem(e, database);
                }

                // Reset and create automatic connections in node Origin of edge
                resetAndCreateAutomaticConnections(e->getNodeOrigin());

                // Reset and create automatic connections in node Destiny of edge
                resetAndCreateAutomaticConnections(e->getNodeDestiny());

                // If option Double edge is enabled
                if(doubleEdge)
                {
                    // Insert inverse edge
                    e = insertEdgeInScene(temporalNode, lastInsertedNode);

                    // Insert automatic Lanes in the inverse edge
                    for(int i = 1; i < numberOfAutomaticLanes; i++)
                    {
                        new laneItem(e, database);
                    }

                    // Reset and create automatic connections in node Origin of inverse edge
                    resetAndCreateAutomaticConnections(e->getNodeOrigin());

                    // Reset and create automatic connections in node Destiny of inverse edge
                    resetAndCreateAutomaticConnections(e->getNodeDestiny());
                }
            }
        }
        else if(event->key() == Qt::Key_Control)
        {
            setFlag(flagOperationMoveNode);
        }
    }
}

void eNetEditorScene::keyReleaseEvent(QKeyEvent *event)
{
    // If Flag flagOperationAddOrRemoveNodeOrEdgeOrLane is enabled
    if(flag == flagOperationAddOrRemoveNodeOrEdgeOrLane || flag == flagOperationMoveNode)
    {
        if(event->key() == Qt::Key_Control)
        {
            setFlag(flagOperationAddOrRemoveNodeOrEdgeOrLane);
        }
        else if(event->key() == Qt::Key_Shift)
        {
            // Disable shiftKeyPressed
            shiftKeyPressed = false;

            // If temporal node != NULL
            if(temporalNode != NULL)
            {
                // Declare list of edgeItem to remove
                QList<edgeItem *> listOfEdgesToRemove;

                // Fill list with the incoming edges
                for(QList<edgeItem *>::iterator i = temporalNode->iteratorIncomingEdgesBegin(); i != temporalNode->iteratorIncomingEdgesEnd(); i++)
                {
                    listOfEdgesToRemove.push_back(*i);
                }

                // Fill list with the outcoming edges
                for(QList<edgeItem *>::iterator i = temporalNode->iteratorOutcomingEdgesBegin(); i != temporalNode->iteratorOutcomingEdgesEnd(); i++)
                {
                    listOfEdgesToRemove.push_back(*i);
                }

                // Erase all edges of temporalNode
                for(QList<edgeItem *>::iterator i = listOfEdgesToRemove.begin(); i != listOfEdgesToRemove.end(); i++)
                {
                    delete (*i);
                }
            }
        }
    }
}

void eNetEditorScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // Call the QGraphicsScene function
    QGraphicsScene::mousePressEvent(event);

    // Set value scrolling to false
    scrolling = false;

    // Keep grabbed item
    grabbedItem = mouseGrabberItem();
}

void eNetEditorScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    // Call parent function
    QGraphicsScene::mouseReleaseEvent(event);

    // If Left button is pressed
    if (event->button() == Qt::LeftButton)
    {
        // If between mousePressEvent and mouseReleaseEvent user didn't scroll window
        if(scrolling == false)
        {
            // If the flag "Add edgeOrLane" is enabled
            if(flag == flagOperationAddOrRemoveNodeOrEdgeOrLane)
            {
                processOperationAddNodeOrEdgeOrLane(grabbedItem);
            }
            // If the flag "Add Direction" is enabled
            else if(flag == flagOperationAddOrRemoveConnection)
            {
                processOperationAddConnection(grabbedItem);
            }
            // If the flag "Add Prohibition" is enabled
            else if(flag == flagOperationAddOrRemoveProhibition)
            {
                processOperationAddProhibition(grabbedItem);
            }
            // If flag add route is ienabled
            else if(flag == flagOperationAddOrRemoveRoute)
            {
                processOperationAddRoute(grabbedItem);
            }
            // If the flag "Add Traffic Light" is enabled
            else if(flag == flagOperationAddOrRemoveTrafficLight)
            {
                processOperationAddTrafficLight(grabbedItem);
            }
            // If the flag "Add Bus Station" is enabled
            else if(flag == flagOperationAddOrRemoveBusStop)
            {
                processOperationAddBusStop(grabbedItem);
            }
            // If the flag "Add Charging Station" is enabled
            else if(flag == flagOperationAddOrRemoveChargingStation)
            {
                processOperationAddChargingStation(grabbedItem);
            }

            grabbedItem = NULL;
        }
    }
    // If button pressed is right (erase button)
    else if (event->button() ==  Qt::RightButton)
    {
        // If FlagOperationAddNodeis enabled
        if(flag == flagOperationAddOrRemoveNodeOrEdgeOrLane)
        {
            processOperationRemoveNodeOrEdgeOrLane(grabbedItem);
        }
        // If FlagOperationAddConnectionis enabled
        else if(flag == flagOperationAddOrRemoveConnection)
        {
            processOperationRemoveConnection(grabbedItem);
        }
        // If flag FlagOperationAddProhibition is enabled
        else if(flag == flagOperationAddOrRemoveProhibition)
        {
            processOperationRemoveProhibition(grabbedItem);
        }
        // If flag FlagOperationAddRoute is enabled
        else if(flag == flagOperationAddOrRemoveRoute)
        {
            processOperationRemoveRoute(grabbedItem);
        }
        // If flag FlagOperationAddTrafficLight is enabled
        else if(flag == flagOperationAddOrRemoveTrafficLight)
        {
            processOperationRemoveTrafficLight(grabbedItem);
        }
        // If FlagOperationAddBusStop is enabled
        else if(flag == flagOperationAddOrRemoveBusStop)
        {
            processOperationRemoveBusStop(grabbedItem);
        }
        // If FlagOperationAddChargingStation is enabled
        else if(flag == flagOperationAddOrRemoveChargingStation)
        {
            processOperationRemoveChargingStation(grabbedItem);
        }

        // Set grabbed item to NULL
        grabbedItem = NULL;

        // Dismark All items
        parameterManager->dismarkAllItems();
    }

    // Update scene
    update();
}
