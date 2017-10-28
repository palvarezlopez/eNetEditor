#include "eNetEditorTable.h"

// main
#include "../dialogs/main/eNetEditorMainWindow.h"

// Database
#include "../database/eNetEditorDatabase.h"

// Project
#include "../project/eNetEditorProject.h"

// Scene
#include "../project/eNetEditorScene.h"

// Configuration
#include "../configuration/main/eNetEditorMainConfiguration.h"
#include "../configuration/project/eNetEditorProjectConfiguration.h"
#include "../configuration/items/eNetEditorItemConfiguration.h"

// Item
#include "../items/eNetEditorItem.h"


eNetEditorTable::eNetEditorTable(const QString &newNameOfTable, eNetEditorItemConfiguration *newItemConfiguration, eNetEditorDatabase *newDatabase) : eNetEditor()
{
    // Set pointer to database
    database = newDatabase;

    // Set name of database
    tableName = newNameOfTable;

    // Set pointer to itemConfiguration
    itemConfiguration = newItemConfiguration;

    // Set path of Table
    //tablePath = getProject()->getProjectPath() + "/" + getProject()->getProjectName() + "." + itemConfiguration + "." + extensionOfFile;
}

eNetEditorTable::~eNetEditorTable()
{
    // Create copy of items of table
    QList<eNetEditorItem *> copyOfItemTable = itemTable;

    // Iterate over table
    for(QList<eNetEditorItem *>::iterator i = copyOfItemTable.begin(); i != copyOfItemTable.end(); i++)
    {
        // Delete item
        delete (*i);
    }

    // Alternative less elegant but a little bit more efficient
    //while(!itemTable.empty())
    //{
    //    delete itemTable.first();
    //}
}

void eNetEditorTable::loadTable(QDomDocument *domDoc)
{
    /**
    // Get list of all items  all items with the tag "connection"
    QDomNodeList connectionsNodeList = rootOfNetfile.elementsByTagName("connection");

    // Declare QDomElement
    QDomElement connectionElement;

    // Declare connection pointer to keep the pointer of the database
    connectionItem *c;

    // Declare QString to make connections ID
    QString connectionID;

    // Declare int to count linkIndexs
    int numberOfLinkIndexFounded = 0;

    // Interate over connectionsNodeList
    for(int i = 0; i < connectionsNodeList.count(); i++)
    {
        // Get Element of type connection
        connectionElement = connectionsNodeList.at(i).toElement();

        // If the element has the atribute linkindex
        if(connectionElement.hasAttribute("linkIndex"))
        {
            // Make id of the information of net file
            connectionID = "con_"
                        + connectionElement.attribute("from")
                        + "["
                        + connectionElement.attribute("fromLane")
                        + "] -> "
                        + connectionElement.attribute("to")
                        + "["
                        + connectionElement.attribute("toLane")
                        + "]";

            // Get connection of the database using the made connection
            c = database->findConnectionById(connectionID);

            // If the element was founded in the database
            if(c)
            {
                // Update linkIndexAutomatic
                c->setLinkIndex(connectionElement.attribute("linkIndex").toInt());

                //Update Counter
                numberOfLinkIndexFounded++;
            }
            else
            {
                qDebug()<< connectionID << "NO ENCONTRADO";
            }
        }
    }
    **/
}

QDomElement eNetEditorTable::saveTable(const QString &tableId, QDomDocument *domDoc)
{
    // Declare QDomElements
    QDomElement tableElement;
    QDomElement itemElement;

    // Set atribute
    tableElement = domDoc->createElement(tableId);

    // Iterate over table
    for(QList<eNetEditorItem *>::iterator i = iteratorTableBegin(); i != iteratorTableEnd(); i++)
    {
        // Get own of item
        itemElement = (*i)->saveItem(domDoc);

        // Get commons atribute id
        itemElement.setAttribute("id", (*i)->getItemId());

        // Get commons atribute extra parameter 1 name
        itemElement.setAttribute("extraParameter1Name", (*i)->getExtraParameter1Name());

        // Get commons atribute extra parameter 1 value
        itemElement.setAttribute("extraParameter1Value", (*i)->getExtraParameter1Value());

        // Get commons atribute extra parameter 2 name
        itemElement.setAttribute("extraParameter2Name", (*i)->getExtraParameter2Name());

        // Get commons atribute extra parameter 2 value
        itemElement.setAttribute("extraParameter2Value", (*i)->getExtraParameter2Value());

        // Get commons atribute extra parameter 3 name
        itemElement.setAttribute("extraParameter3Name", (*i)->getExtraParameter3Name());

        // Get commons atribute extra parameter 3 value
        itemElement.setAttribute("extraParameter3Value", (*i)->getExtraParameter3Value());

        // Append to nodeTableElement
        tableElement.appendChild(itemElement);
    }

    // Return nodeTableElement to append in the QDomElement project
    return tableElement;
}

bool eNetEditorTable::exportTableToXML()
{
    // Create QString with filePath
    QString filePath = getProject()->getProjectPath() + "/" + getProject()->getProjectName() + "." + itemConfiguration->getItemFileNameWithExtension();

    // Create Qfile with the file path
    QFile file(filePath);

    // check if file exits
    if (file.exists())
    {
        // If exist, remove it
        QFile::remove(filePath);
    }

    // Set open parameters
    file.open(QIODevice::WriteOnly);

    // Try to open file
    if(!file.error())
    {
        // Create QDomDocument
        QDomDocument *domDoc = new QDomDocument();

        // Declare QDomElement to keep atributes
        QDomElement domElementTable;
        QDomElement domElementItem;
        QDomElement extraParameter;

        // Create Element with the corresponding tag (nameOfTable)
        domElementTable = domDoc->createElement(tableName);

        // Iterate over table
        for(QList<eNetEditorItem *>::iterator i = iteratorTableBegin(); i != iteratorTableEnd(); i++)
        {
            // Append item table to domElementProject
            domElementItem = (*i)->exportItemToXML(domDoc);

            // If extra parameter 1 was setted
            if((*i)->getExtraParameter1Name() != "")
            {
                // Create Child extraParameter1
                extraParameter = domDoc->createElement("extraParameter1");

                // Set atribute and their value
                extraParameter.setAttribute((*i)->getExtraParameter1Name(), (*i)->getExtraParameter1Value());

                // Add child extraParameter with the extra parameter to domElementItem
                domElementItem.appendChild(extraParameter);
            }

            // If extra parameter 2 was setted
            if((*i)->getExtraParameter2Name() != "")
            {
                // Create Child extraParameter2
                extraParameter = domDoc->createElement("extraParameter2");

                // Set atribute and their value
                extraParameter.setAttribute((*i)->getExtraParameter2Name(), (*i)->getExtraParameter2Value());

                // Add child extraParameter with the extra parameter to domElementItem
                domElementItem.appendChild(extraParameter);
            }

            // If extra parameter 3 was setted
            if((*i)->getExtraParameter3Name() != "")
            {
                // Create Child extraParameter3
                extraParameter = domDoc->createElement("extraParameter3");

                // Set atribute and their value
                extraParameter.setAttribute((*i)->getExtraParameter3Name(), (*i)->getExtraParameter3Value());

                // Add child extraParameter with the extra parameter to domElementItem
                domElementItem.appendChild(extraParameter);
            }

            // Append domElementItem child to domElementTable
            domElementTable.appendChild(domElementItem);
        }

        // Append domElementTable child to general document
        domDoc->appendChild(domElementTable);

        // Create TexStream with the file
        QTextStream out(&file);

        // Save file using textStream
        out << domDoc->toString();

        // Delete domDoc
        delete domDoc;

        // Close stream
        file.close();

        // Table of items exported sucesfully, then return true
        return true;
    }
    else
    {
        // If there are an error open the file, then return false
        return false;
    }
}

void eNetEditorTable::addeNetEditorItem(eNetEditorItem *item)
{
    // If item is valid
    if(item != NULL)
    {
        // Add item in itemTable
        itemTable.push_back(item);

        // Set saved flag of database false
        database->setSaved(false);
    }
}

void eNetEditorTable::eraseeNetEditorItem(eNetEditorItem *item)
{
    // If item is valid
    if(item != NULL)
    {
        // If item is a graphical item
        if(item->isItemGraphical())
        {
            // Remove item of scene
            database->geteNetEditorScene()->removeItem(item);
        }

        // Remove item of itemTable
        itemTable.removeAll(item);

        // Set saved flag of database false
        database->setSaved(false);
    }
}

eNetEditorItem *eNetEditorTable::findItemById(const QString &idToSearch) const
{
    // Iterate over list of items comparing id and idToSearch.
    for (QList<eNetEditorItem *>::const_iterator i = itemTable.begin(); i != itemTable.end(); i++)
    {
        // If item was founded
        if(idToSearch.compare( (*i)->getItemId() ) == 0)
        {
            // Then return a pointer to item.
            return (*i);
        }
    }

    // If item wasn't founded, then return NULL.
    return NULL;
}

eNetEditorItem *eNetEditorTable::getItemAt(int index)
{
    // If index is valid
    if((index >= 0) && (index < itemTable.size()))
    {
        return itemTable.at(index);
    }
    else
    {
        return NULL;
    }
}

const QString &eNetEditorTable::getTableName()
{
    return tableName;
}

int eNetEditorTable::getNumberOfItems() const
{
    return itemTable.size();
}

eNetEditorDatabase *eNetEditorTable::getDatabase() const
{
    return database;
}

eNetEditorScene *eNetEditorTable::geteNetEditorScene() const
{
    return database->geteNetEditorScene();
}

eNetEditorProject *eNetEditorTable::getProject() const
{
    return database->geteNetEditorScene()->getProject();
}

eNetEditorMainWindow *eNetEditorTable::geteNetEditorMainWindow() const
{
    return database->geteNetEditorScene()->getProject()->geteNetEditorMainWindow();
}

eNetEditorMessages *eNetEditorTable::getMessages() const
{
    return database->geteNetEditorScene()->getProject()->geteNetEditorMainWindow()->getMessages();
}

QList<eNetEditorItem *>::iterator eNetEditorTable::iteratorTableBegin()
{
    return itemTable.begin();
}

QList<eNetEditorItem *>::iterator eNetEditorTable::iteratorTableEnd()
{
    return itemTable.end();
}

