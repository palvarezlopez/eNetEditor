#include "trafficLightParsing.h"

#include "../configuration/items/trafficLightItemConfiguration.h"
#include "../configuration/project/eNetEditorProjectConfiguration.h"

#include "../database/eNetEditorDatabase.h"
#include "../database/trafficLightTable.h"
#include "../items/connectionItem.h"

#include "../main/eNetEditorMessages.h"

#include "../project/eNetEditorProject.h"

#include "../items/trafficLightItem.h"
#include "../items/nodeItem.h"


trafficLightConverter::trafficLightConverter(eNetEditorMessages *newMessages) : eNetEditor()
{
    // LinkMessages
    messages = newMessages;
}

trafficLightConverter::~trafficLightConverter()
{
    //Nothing to erase
}

bool trafficLightConverter::parseTrafficLights(eNetEditorDatabase *database, const QString &netPath, const QString &trafficLightPath)
{
    // Declare net File
    QFile netFile(netPath);

    // Declare traffic light file
    QFile trafficLightFile(trafficLightPath);

    // Declare XML DOM Document
    QDomDocument XMLDocument;

    // Declare QVector to keep the parsed traffic light phases
    QVector<QString> vectorOfParsedPhases;

    // Write start of processing
    messages->processingStart("Traffic Light Parser");

    // Check if the files are valids
    if(!netFile.open(QFile::ReadOnly | QFile::Text))
    {
        /** Write error message **/
        qDebug() << "ERROR net FILE: " << netPath;

        // Finished Process with error
        messages->processingError();

        return false;
    }

    if(!trafficLightFile.open(QFile::WriteOnly | QIODevice::Truncate | QFile::Text))
    {
        /** Write error message **/
        qDebug() << "ERROR traffic light FILE: " << trafficLightPath;

        // Finished Process with error
        messages->processingError();

        return false;
    }

    // Try to set XML DOM
    if(!XMLDocument.setContent(&netFile))
    {
        /** Write error message in console **/
        qDebug() << "fallo en set DXML DOm";

        return false;
    }

    // Set the automaticLinkIndex in all connections
    setLinkIndexAutomatic(database, XMLDocument.firstChildElement());

    // Create XML stream writer
    QXmlStreamWriter xmlWriter(&trafficLightFile);

    // Set autoformating
    xmlWriter.setAutoFormatting(true);

    // Write start of document
    xmlWriter.writeStartDocument();

    // Write open Label "additional"
    xmlWriter.writeStartElement("additional");

    qDebug() << "FALTAN ITERADORES";
    /**
        // Iterate over Traffic Lights
        for(QList<trafficLightItem*>::iterator i = database->getTrafficLightTable()->begin(); i != database->getTrafficLightTable()->end(); i++)
        {
            // Open tag tlLogic
            xmlWriter.writeStartElement("tlLogic");

            // Write ID
            xmlWriter.writeAttribute("id", (*i)->getItemId());

            // Write type of TL
            xmlWriter.writeAttribute("type", (*i)->getProjectConfiguration()->getTrafficLightItemConfiguration()->getTrafficLightTypeValue((*i)->getType()));

            // Write programID
            xmlWriter.writeAttribute("programID",(*i)->getProgramID());

            // Write offset
            xmlWriter.writeAttribute("offset",QString::number((*i)->getOffset()));

            // Parse traffic Light phases
            vectorOfParsedPhases = parseTrafficLightsPhases(*i);

            // Declare int to iterate over listOfParsedPhases
            int listOfParsedPhasesIterator = 0;

            // Write States
            for(QVector<int>::iterator j = (*i)->getVectorOfDuration().begin(); j != (*i)->getVectorOfDuration().end(); j++)
            {
                // Write tag phase
                xmlWriter.writeStartElement("phase");

                // Write duration of phase
                xmlWriter.writeAttribute("duration",QString::number(*j));

                // Write parsed state
                xmlWriter.writeAttribute("state",vectorOfParsedPhases.at(listOfParsedPhasesIterator));

                // end tag endElement
                xmlWriter.writeEndElement();

                // Update Iterator
                listOfParsedPhasesIterator++;
            }

            // End tlLogic
            xmlWriter.writeEndElement();
        }
        **/

    // Close traffic lights tag
    xmlWriter.writeEndElement();

    // Close traffic Light file
    trafficLightFile.close();

    // Close net File
    netFile.close();

    // Finished Process
    messages->processingFinished();

    // Net converted, then return true
    return true;
}

void trafficLightConverter::setLinkIndexAutomatic(eNetEditorDatabase *database, QDomElement rootOfNetfile)
{
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
                qDebug() << connectionID << "NO ENCONTRADO";
            }
        }
    }

    // Write the number of link index founded
    messages->writeInConsole("Traffic Light Parser: founded " + QString::number(numberOfLinkIndexFounded) + "linkIndexs");
}


QVector<QString> trafficLightConverter::parseTrafficLightsPhases(trafficLightItem *tl)
{
    // Declare Vector with the parsed Phases
    QVector<QVector<char>> listOfPhasesOrderByLinkIndexAutomatic;

    // Declare Vector with the parsed Phases
    QVector<QString> listOfPhasesParsed;

    // Declare Vector to keep the temporal phases
    QString phase;

    // Check integrity of the phases vectors
    for(QList<connectionItem *>::iterator i = tl->getNodeParent()->iteratorConnectionsBegin(); i != tl->getNodeParent()->iteratorConnectionsEnd(); i++)
    {
        // If the size of vectors (states and duration are different)
        if((*i)->getVectorOfStates().size() < tl->getVectorOfDuration().size())
        {
            // Declare fixVectorOfStates
            QVector<char> fixVectorOfStates;

            // Fill fixVectorOfStates with the rest of states
            fixVectorOfStates.fill('g', tl->getVectorOfDuration().size() - (*i)->getVectorOfStates().size() );

            // Set in the connection the fixVectorOfStates
            (*i)->setVectorOfStates((*i)->getVectorOfStates() + fixVectorOfStates);
        }
    }

    // Fill vector of listOfPhasesOrderByLinkIndexAutomatic
    listOfPhasesOrderByLinkIndexAutomatic.fill(QVector<char>(), tl->getNodeParent()->getNumberOfConnections());

    // Order List Of phases using their Link Index Automatic
    for (QList<connectionItem *>::iterator i = tl->getNodeParent()->iteratorConnectionsBegin(); i != tl->getNodeParent()->iteratorConnectionsEnd(); i++)
    {
        listOfPhasesOrderByLinkIndexAutomatic[(*i)->getLinkIndex()] = (*i)->getVectorOfStates();
    }

    // Parse phases
    for (int i = 0; i < tl->getVectorOfDuration().size(); i++)
    {
        // Clear phase
        phase.clear();

        // Fill phase
        for(QVector<QVector<char>>::iterator j = listOfPhasesOrderByLinkIndexAutomatic.begin(); j != listOfPhasesOrderByLinkIndexAutomatic.end(); j++)
        {
            phase += (*j).at(i);
        }

        // Add phase to vector
        listOfPhasesParsed.push_back(phase);
    }

    // Return phases parsed
    return listOfPhasesParsed;
}
