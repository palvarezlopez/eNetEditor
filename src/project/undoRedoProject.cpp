#include "undoRedoProject.h"

// Database
#include "../database/eNetEditorDatabase.h"

// Messages
#include "../main/eNetEditorMessages.h"

// Items
#include "../items/nodeItem.h"
#include "../items/edges/edgeItem.h"
#include "../items/laneItem.h"
#include "../items/connectionItem.h"
#include "../items/prohibitionItem.h"
#include "../items/routeItem.h"
#include "../items/trafficLightItem.h"
#include "../items/stops/busStopItem.h"
#include "../items/stops/chargingStationItem.h"
#include "../items/vehicles/vehicleItem.h"
#include "../items/vehicleTypeItem.h"
#include "../items/vehicles/flowItem.h"
#include "../items/edges/edgeTypeItem.h"



undoRedoProject::undoRedoProject(eNetEditorDatabase *newDatabase, eNetEditorMessages *newMessages)
{
    // LInk database
    database = newDatabase;

    // Link netEditorMessages
    messages = newMessages;

}

undoRedoProject::~undoRedoProject()
{
    /*
    // Clean stack
    while(!operationsStack.isEmpty())
    {
        // Delete an pop all elements
        delete (operationsStack.pop());
    }
    */
}

void undoRedoProject::addOperation(eNetEditorItem *item, eNetEditorAction operationType, QString attributeChanged, QString attributeValueChanged)
{
    /*
    // Declare pointer for a new operation
    projectOperation *operation;

    // Check what type of operation is
    if(operationType == eNetEditorActionAddItem)
    {
      // Create new Operation
        operation = new projectOperation;

        //Check type of item
        if(dynamic_cast<nodeItem*>(item))
        {
            // Save type of Item
            operation->itemID = dynamic_cast<nodeItem*>(item)->getItemId();
        }
        else if(dynamic_cast<edgeItem*>(item))
        {
            // Save type of Item
            operation->itemID = dynamic_cast<edgeItem*>(item)->getItemId();
        }
        else if(dynamic_cast<laneItem*>(item))
        {
            // Save type of Item
            operation->itemID = dynamic_cast<laneItem*>(item)->getItemId();
        }
        else if(dynamic_cast<connectionItem*>(item))
        {
            // Save type of Item
            operation->itemID = dynamic_cast<connectionItem*>(item)->getItemId();
        }
        else if(dynamic_cast<prohibitionItem*>(item))
        {
            // Save type of Item
            operation->itemID = dynamic_cast<prohibitionItem*>(item)->getItemId();
        }
        else if(dynamic_cast<routeItem*>(item))
        {
            // Save type of Item
            operation->itemID = dynamic_cast<routeItem*>(item)->getItemId();
        }
        else if(dynamic_cast<trafficLightItem*>(item))
        {
            // Save type of Item
            operation->itemID = dynamic_cast<trafficLightItem*>(item)->getItemId();
        }
        else if(dynamic_cast<busStopItem*>(item))
        {
            // Save type of Item
            operation->itemID = dynamic_cast<busStopItem*>(item)->getItemId();
        }
        else if(dynamic_cast<chargingStationItem*>(item))
        {
            // Save type of Item
            operation->itemID = dynamic_cast<chargingStationItem*>(item)->getItemId();
        }
        else if(dynamic_cast<vehicleItem*>(item))
        {
            // Save type of Item
            operation->itemID = dynamic_cast<vehicleItem*>(item)->getItemId();
        }
        else if(dynamic_cast<vehicleTypeItem*>(item))
        {
            // Save type of Item
            operation->itemID = dynamic_cast<vehicleTypeItem*>(item)->getItemId();
        }
        else if(dynamic_cast<flowItem*>(item))
        {
            // Save type of Item
            operation->itemID = dynamic_cast<flowItem*>(item)->getItemId();
        }
        else if(dynamic_cast<edgeTypeItem*>(item))
        {
            // Save type of Item
            operation->itemID = dynamic_cast<edgeTypeItem*>(item)->getItemId();
        }
        else
        {
            // Write error message
            messages->writeInConsole("ERROR in the UndoRedo module: item is unknow", consoleMessageTypeError);
        }
    }
    else if(operationType == eNetEditorActionRemoveItem)
    {
        //Check type of item
        if(dynamic_cast<nodeItem*>(item))
        {
            // Erase node
            database->eraseNodeOfSceneAndDatabase(dynamic_cast<nodeItem*>(item));
        }
        else if(dynamic_cast<edgeItem*>(item))
        {
            // Erase Edge
            database->eraseEdgeOfSceneAndDatabase(dynamic_cast<edgeItem*>(item));
        }
        else if(dynamic_cast<laneItem*>(item))
        {
            // Erase Lane
            database->eraseLaneOfSceneAndDatabase(dynamic_cast<laneItem*>(item));
        }
        else if(dynamic_cast<connectionItem*>(item))
        {
            // Erase Connection
            database->eraseLaneOfSceneAndDatabase(dynamic_cast<laneItem*>(item));
        }
        else if(dynamic_cast<prohibitionItem*>(item))
        {

        }
        else if(dynamic_cast<routeItem*>(item))
        {

        }
        else if(dynamic_cast<trafficLightItem*>(item))
        {

        }
        else if(dynamic_cast<busStopItem*>(item))
        {

        }
        else if(dynamic_cast<chargingStationItem*>(item))
        {

        }
        else if(dynamic_cast<vehicleItem*>(item))
        {

        }
        else if(dynamic_cast<vehicleTypeItem*>(item))
        {

        }
        else if(dynamic_cast<flowItem*>(item))
        {

        }
        else if(dynamic_cast<edgeTypeItem*>(item))
        {

        }
        else
        {
            // Write error message
            messages->writeInConsole("ERROR in the UndoRedo module: item is unknow", consoleMessageTypeError);
        }
    }
    else if(operationType == eNetEditorActionMoveItem)
    {

    }
    else if(operationType == eNetEditorActionChangeParameterItem)
    {
        //Check type of item
        if(dynamic_cast<nodeItem*>(item))
        {

        }
        else if(dynamic_cast<edgeItem*>(item))
        {

        }
        else if(dynamic_cast<laneItem*>(item))
        {

        }
        else if(dynamic_cast<connectionItem*>(item))
        {

        }
        else if(dynamic_cast<prohibitionItem*>(item))
        {

        }
        else if(dynamic_cast<routeItem*>(item))
        {

        }
        else if(dynamic_cast<trafficLightItem*>(item))
        {

        }
        else if(dynamic_cast<busStopItem*>(item))
        {

        }
        else if(dynamic_cast<chargingStationItem*>(item))
        {

        }
        else if(dynamic_cast<vehicleItem*>(item))
        {

        }
        else if(dynamic_cast<vehicleTypeItem*>(item))
        {

        }
        else if(dynamic_cast<flowItem*>(item))
        {

        }
        else if(dynamic_cast<edgeTypeItem*>(item))
        {

        }
        else
        {
            // Write error message
            messages->writeInConsole("ERROR in the UndoRedo module: item is unknow", consoleMessageTypeError);
        }
    }
    else
    {
        // Write error message
        messages->writeInConsole("ERROR in the UndoRedo module: operation code is unknow", consoleMessageTypeError);
    }
    */
}

void undoRedoProject::commit()
{
    /*
    // Create NE Operation
    projectOperation *operation = new projectOperation();

    // Set type of operation to "commit"
    operation->operationTyp = eNetEditorActionCommit;

    // Add operation to stack
    operationsStack.push(operation);
    */
}

void undoRedoProject::redo()
{

}

bool undoRedoProject::empty()
{
    return operationsStack.empty();
}
