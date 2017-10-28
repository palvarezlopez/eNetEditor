#include "eNetEditorDatabase.h"

// main
#include "../dialogs/main/eNetEditorMainWindow.h"

// Messages
#include "../main/eNetEditorMessages.h"

// Project
#include "../project/eNetEditorProject.h"

// Undo Redo modul
#include "../project/undoRedoProject.h"

// Scene of net Editor
#include "../project/eNetEditorScene.h"

// Configurations
#include "../configuration/eNetEditorConfiguration.h"
#include "../configuration/items/stops/busStopItemConfiguration.h"
#include "../configuration/items/stops/chargingStationItemConfiguration.h"
#include "../configuration/items/connectionItemConfiguration.h"
#include "../configuration/items/detectors/inductionLoopsE1DetectorItemConfiguration.h"
#include "../configuration/items/detectors/laneAreaE2DetectorItemConfiguration.h"
#include "../configuration/items/detectors/multiEntryExitE3DetectorItemConfiguration.h"
#include "../configuration/items/distributionFunctionItemConfiguration.h"
#include "../configuration/items/edges/edgeItemConfiguration.h"
#include "../configuration/items/edges/edgeTypeItemConfiguration.h"
#include "../configuration/items/flowMeasureItemConfiguration.h"
#include "../configuration/items/laneItemConfiguration.h"
#include "../configuration/items/nodeItemConfiguration.h"
#include "../configuration/items/prohibitionItemConfiguration.h"
#include "../configuration/items/routeItemConfiguration.h"
#include "../configuration/items/trafficLightItemConfiguration.h"
#include "../configuration/items/turnRatios/turnRatioItemConfiguration.h"
#include "../configuration/items/vehicleTypeItemConfiguration.h"
#include "../configuration/items/vehicles/flowItemConfiguration.h"
#include "../configuration/items/vehicles/vehicleItemConfiguration.h"
#include "../configuration/main/eNetEditorMainConfiguration.h"
#include "../configuration/project/eNetEditorProjectConfiguration.h"
#include "../configuration/tools/netConvertToolConfiguration.h"

//Tables
#include "stops/busStopTable.h"
#include "stops/chargingStationTable.h"
#include "connectionTable.h"
#include "detectors/inductionLoopsE1DetectorTable.h"
#include "detectors/laneAreaE2DetectorTable.h"
#include "detectors/multiEntryExitE3DetectorTable.h"
#include "distributionFunctionTable.h"
#include "edges/edgeTable.h"
#include "edges/edgeTypeTable.h"
#include "flowMeasureTable.h"
#include "laneTable.h"
#include "nodeTable.h"
#include "prohibitionTable.h"
#include "routeTable.h"
#include "trafficLightTable.h"
#include "turnRatios/turnRatioTable.h"
#include "turnRatios/turnRatioIntervalTable.h"
#include "vehicleTypeTable.h"
#include "vehicles/flowTable.h"
#include "vehicles/vehicleTable.h"

// Items
#include "../items/stops/busStopItem.h"
#include "../items/stops/chargingStationItem.h"
#include "../items/connectionItem.h"
#include "../items/detectors/abstractDetectorItem.h"
#include "../items/detectors/inductionLoopsE1DetectorItem.h"
#include "../items/detectors/laneAreaE2DetectorItem.h"
#include "../items/detectors/multiEntryExitE3DetectorItem.h"
#include "../items/distributionFunctionItem.h"
#include "../items/edges/edgeItem.h"
#include "../items/edges/edgeTypeItem.h"
#include "../items/flowMeasureItem.h"
#include "../items/laneItem.h"
#include "../items/nodeItem.h"
#include "../items/prohibitionItem.h"
#include "../items/routeItem.h"
#include "../items/trafficLightItem.h"
#include "../items/turnRatios/turnRatioItem.h"
#include "../items/vehicleTypeItem.h"
#include "../items/vehicles/flowItem.h"
#include "../items/vehicles/vehicleItem.h"



eNetEditorDatabase::eNetEditorDatabase(eNetEditorScene *newScene) : eNetEditor()
{
    // Set pointer to project
    scene = newScene;

    // By default, database isn't saved
    saved = false;

    // Create undoRedo modul
    undoRedo = new undoRedoProject(this, getMessages());

    // Create Tables
    nTable = new nodeTable("nodes", getProjectConfiguration()->getNodeItemConfiguration(), this);
    eTable = new edgeTable("edges", getProjectConfiguration()->getEdgeItemConfiguration(), this);
    lTable = new laneTable("lanes", getProjectConfiguration()->getLaneItemConfiguration(), this);
    cTable = new connectionTable("connections", getProjectConfiguration()->getConnectionItemConfiguration(), this);
    pTable = new prohibitionTable("prohibitions", getProjectConfiguration()->getProhibitionItemConfiguration(), this);
    rTable = new routeTable("routes", getProjectConfiguration()->getRouteItemConfiguration(), this);
    tlTable = new trafficLightTable("trafficlights", getProjectConfiguration()->getTrafficLightItemConfiguration(), this);
    bsTable = new busStopTable("additional", getProjectConfiguration()->getBusStopItemConfiguration(), this);
    csTable = new chargingStationTable("additional", getProjectConfiguration()->getChargingStationItemConfiguration(), this);
    vtTable = new vehicleTypeTable("routes", getProjectConfiguration()->getVehicleTypeItemConfiguration(), this);
    fTable = new flowTable("routes", getProjectConfiguration()->getFlowItemConfiguration(), this);
    etTable = new edgeTypeTable("types", getProjectConfiguration()->getEdgeTypeItemConfiguration(), this);
    vTable = new vehicleTable("routes", getProjectConfiguration()->getVehicleItemConfiguration(), this);
    E1Table = new inductionLoopsE1DetectorTable("additional", getProjectConfiguration()->getInductionLoopsE1DetectorItemConfiguration(), this);
    E2Table = new laneAreaE2DetectorTable("additional", getProjectConfiguration()->getLaneAreaE2DetectorItemConfiguration(), this);
    E3Table = new multiEntryExitE3DetectorTable("additional", getProjectConfiguration()->getMultiEntryExitE3DetectorItemConfiguration(), this);
    fmTable = new flowMeasureTable("flowMeasure", getProjectConfiguration()->getFlowMeasureItemConfiguration(), this);
    dfTable = new distributionFunctionTable("distributionFunction", getProjectConfiguration()->getDistributionFunctionItemConfiguration(), this);
    triTable = new turnRatioIntervalTable("turns", getProjectConfiguration()->getTurnRatioIntervalItemConfiguration(), this);
    trTable = new turnRatioTable("turns", getProjectConfiguration()->getTurnRatioItemConfiguration(), this);

    // By default is not saved
    saved = false;

    // Add extra Vehicle Type PKW
    vehicleTypeItem *VTypePKV = new vehicleTypeItem("PKW", this);

    // Set Vehicle Class
    VTypePKV->setVClass(vehicleClassPrivate);

    // This vehicle cannotbe removed
    VTypePKV->setRemovable(false);

    // Add extra Vehicle Types LKW
    vehicleTypeItem *VTypeLKW = new vehicleTypeItem("LKW", this);

    // Set Vehicle Class
    VTypeLKW->setVClass(vehicleClassTruck);

    // This vehicle cannotbe removed
    VTypeLKW->setRemovable(false);
}

eNetEditorDatabase::eNetEditorDatabase(const QString &filePath, eNetEditorScene *newScene)
{
    // Set pointer to project
    scene = newScene;

    // Declare file
    QFile projectFile(filePath);

    // Declare XML DOM Document
    QDomDocument XMLDocument;

    // OpenFile
    if(!projectFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Error (A ver como arreglo esto luego";
    }

    // Set file in DOM Document
    XMLDocument.setContent(&projectFile);

    // Get root of node
    QDomNode root = XMLDocument.firstChild();

    // Get Element (Tag) "project"
    QDomElement projectElement = XMLDocument.firstChildElement("project");

    // Create undoRedo modul
    undoRedo = new undoRedoProject(this, getMessages());

    // Create Tables
    nTable = new nodeTable("nodes", getProjectConfiguration()->getNodeItemConfiguration(), this);
    eTable = new edgeTable("edges", getProjectConfiguration()->getEdgeItemConfiguration(), this);
    lTable = new laneTable("lanes", getProjectConfiguration()->getLaneItemConfiguration(), this);
    cTable = new connectionTable("connections", getProjectConfiguration()->getConnectionItemConfiguration(), this);
    pTable = new prohibitionTable("prohibitions", getProjectConfiguration()->getProhibitionItemConfiguration(), this);
    rTable = new routeTable("routes", getProjectConfiguration()->getRouteItemConfiguration(), this);
    tlTable = new trafficLightTable("trafficlights", getProjectConfiguration()->getTrafficLightItemConfiguration(), this);
    bsTable = new busStopTable("additional", getProjectConfiguration()->getBusStopItemConfiguration(), this);
    csTable = new chargingStationTable("additional", getProjectConfiguration()->getChargingStationItemConfiguration(), this);
    vtTable = new vehicleTypeTable("routes", getProjectConfiguration()->getVehicleTypeItemConfiguration(), this);
    fTable = new flowTable("routes", getProjectConfiguration()->getFlowItemConfiguration(), this);
    etTable = new edgeTypeTable("types", getProjectConfiguration()->getEdgeTypeItemConfiguration(), this);
    vTable = new vehicleTable("routes", getProjectConfiguration()->getVehicleItemConfiguration(), this);
    E1Table = new inductionLoopsE1DetectorTable("detectors", getProjectConfiguration()->getInductionLoopsE1DetectorItemConfiguration(), this);
    E2Table = new laneAreaE2DetectorTable("detectors", getProjectConfiguration()->getLaneAreaE2DetectorItemConfiguration(), this);
    E3Table = new multiEntryExitE3DetectorTable("detectors", getProjectConfiguration()->getMultiEntryExitE3DetectorItemConfiguration(), this);
    fmTable = new flowMeasureTable("flowMeasure", getProjectConfiguration()->getFlowMeasureItemConfiguration(), this);
    dfTable = new distributionFunctionTable("distributionFunction", getProjectConfiguration()->getDistributionFunctionItemConfiguration(), this);
    triTable = new turnRatioIntervalTable("turns", getProjectConfiguration()->getTurnRatioIntervalItemConfiguration(), this);
    trTable = new turnRatioTable("turns", getProjectConfiguration()->getTurnRatioItemConfiguration(), this);

    // Set scale of the map
    nTable->setMapPixelMeter(projectElement.attribute("scale").toDouble());

    // Load items
    loadNodes(projectElement.firstChildElement("nodeTable"));
    loadEdges(projectElement.firstChildElement("edgeTable"));

    // By default is not saved
    saved = false;
}

eNetEditorDatabase::~eNetEditorDatabase()
{
    // Delete undoRedo modul
    delete undoRedo;

    // Delete Tables (And therefore all items) WARNING: Deleting tables with this order
    delete fmTable;
    delete dfTable;
    delete trTable;
    delete triTable;
    delete E1Table;
    delete E2Table;
    delete E3Table;
    delete fTable;
    delete vtTable;
    delete csTable;
    delete bsTable;
    delete rTable;
    delete tlTable;
    delete cTable;
    delete pTable;
    delete lTable;
    delete etTable;
    delete eTable;
    delete nTable;
}

bool eNetEditorDatabase::save()
{
    QString  saveFilePath = getProject()->getProjectPath() + "/" + getProject()->getProjectName() + getProjectConfiguration()->getDefaultProjectExtensionFile();

    QFile file(saveFilePath);

    if (file.exists())
    {
        // Check if the file exist
        if(file.exists())
        {
            // If exist, remove it
            QFile::remove(saveFilePath);
        }
    }

    // Set open parameters
    file.open(QIODevice::WriteOnly);

    // Try to open file
    if(!file.error())
    {
        // Create QDomDocument
        QDomDocument *domDoc = new QDomDocument();

        // Create QDomElements
        QDomElement domElementProject;

        // Create Element "project"
        domElementProject = domDoc->createElement("project");

        // Save all elements of project
        domElementProject.setAttribute("projectName", getProject()->getProjectName());
        domElementProject.setAttribute("path", getProject()->getProjectPath());
        domElementProject.setAttribute("imagePath", getProject()->getImagePath());
        domElementProject.setAttribute("timeStart", QString::number(getProject()->getTimeBegin()));
        domElementProject.setAttribute("timeEnd", QString::number(getProject()->getTimeEnd()));
        domElementProject.setAttribute("scale", QString::number(getProject()->getScaleMap()));

        // Append node table to domElementProject
        domElementProject.appendChild(nTable->saveTable("nodeTable", domDoc));

        // Append edge table domElementProject
        domElementProject.appendChild(eTable->saveTable("edgeTable", domDoc));

        // Append lane table domElementProject
        domElementProject.appendChild(lTable->saveTable("laneTable", domDoc));

        // Append connection table domElementProject
        domElementProject.appendChild(cTable->saveTable("connectionTable", domDoc));

        // Append prohibition table domElementProject
        domElementProject.appendChild(pTable->saveTable("prohibitionTable", domDoc));

        // Append route table domElementProject
        domElementProject.appendChild(rTable->saveTable("routeTable", domDoc));

        // Append traffic light table domElementProject
        domElementProject.appendChild(tlTable->saveTable("trafficLightTable", domDoc));

        // Append bus stops table domElementProject
        domElementProject.appendChild(bsTable->saveTable("busStopTable", domDoc));

        // Append charging station table domElementProject
        domElementProject.appendChild(csTable->saveTable("chargingStationTable", domDoc));

        // Append vehicle type table domElementProject
        domElementProject.appendChild(vtTable->saveTable("vehicleTypeTable", domDoc));

        // Append flow table domElementProject
        domElementProject.appendChild(fTable->saveTable("flowTable", domDoc));

        // Append vehicle table domElementProject
        domElementProject.appendChild(vTable->saveTable("vehicleTable", domDoc));

        // Append edge type table domElementProject
        domElementProject.appendChild(etTable->saveTable("edgeTypeTable", domDoc));

        // Append E1 table domElementProject
        domElementProject.appendChild(E1Table->saveTable("E1Table", domDoc));

        // Append E2 table domElementProject
        domElementProject.appendChild(E2Table->saveTable("E2Table", domDoc));

        // Append E3 table domElementProject
        domElementProject.appendChild(E3Table->saveTable("E3Table", domDoc));

        // Append E3 table domElementProject
        domElementProject.appendChild(fmTable->saveTable("flowMeasureTable", domDoc));

        // Append E3 table domElementProject
        domElementProject.appendChild(dfTable->saveTable("distributionFunctionTable", domDoc));

        // Append E3 table domElementProject
        domElementProject.appendChild(trTable->saveTable("turnRatioTable", domDoc));

        // Append domElementProject to main domDoc
        domDoc->appendChild(domElementProject);

        QTextStream out(&file);

        out << domDoc->toString();
        /*
            // Image with the map
            QGraphicsPixmapItem* imageMapItem;

            // QPixmap with the map
            QPixmap imageMap;
        */
        delete domDoc;

        // Close stream
        file.close();

        // Connections exported sucesfully, then return true
        return true;
    }
    else
    {
        // If there are an error open the file, then return false
        return false;
    }
}

bool eNetEditorDatabase::load()
{
    return true;
}

eNetEditorScene *eNetEditorDatabase::geteNetEditorScene() const
{
    return scene;
}

eNetEditorProject *eNetEditorDatabase::getProject() const
{
    return scene->getProject();
}

eNetEditorProjectConfiguration *eNetEditorDatabase::getProjectConfiguration() const
{
    return getProject()->geteNetEditorMainWindow()->geteNetEditorConfiguration()->getProjectConfiguration();
}

eNetEditorMessages *eNetEditorDatabase::getMessages() const
{
    return getProject()->geteNetEditorMainWindow()->getMessages();
}

void eNetEditorDatabase::setScaleInTable(qreal newMapPixelMeter)
{
    nTable->setMapPixelMeter(newMapPixelMeter);
}

void eNetEditorDatabase::setSaved(bool value)
{
    saved = value;
}

bool eNetEditorDatabase::isSaved()
{
    return saved;
}

bool eNetEditorDatabase::exportDatabaseToXML()
{
    // Write information in the processin dialog
    getMessages()->processingStart("Exporting Database to XML");

    // Write information in the processin dialog
    getMessages()->processingMessage("export nodes");

    // Try to export node table
    if(!nTable->exportTableToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of nodes to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Write information in the processin dialog
    getMessages()->processingMessage("export edges and lanes");

    // Try to export edge (And lane) table
    if(!eTable->exportTableToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of edges to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Write information in the processin dialog
    getMessages()->processingMessage("export connections");

    // Try to export connection table
    if(!cTable->exportTableToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of connections to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Write information in the processin dialog
    getMessages()->processingMessage("export prohibitions");

    // Try to export prohibition table
    if(!pTable->exportTableToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of prohibitions to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Write information in the processin dialog
    getMessages()->processingMessage("export traffic LIghts");

    // Try to export edge (And lane) table
    if(!tlTable->exportTableToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of Traffic lights to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Write information in the processin dialog
    getMessages()->processingMessage("export routes");

    // Try to export trafficLight table
    if(!rTable->exportTableToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of routes to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Write information in the processin dialog
    getMessages()->processingMessage("export bus stops");

    // Try to export BusStop table
    if(!bsTable->exportTableToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of bus stations to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Write information in the processin dialog
    getMessages()->processingMessage("export charging stations");

    // Try to export chargingStation table
    if(!csTable->exportTableToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of charging stations to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Write information in the processin dialog
    getMessages()->processingMessage("export vehicle types");

    // Try to export vehicle Type table
    if(!vtTable->exportTableToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of vehicle types to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Write information in the processin dialog
    getMessages()->processingMessage("export flows");

    // Try to export flow table
    if(!fTable->exportTableToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of flows to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Write information in the processin dialog
    getMessages()->processingMessage("export edge types");

    // Try to export types table
    if(!etTable->exportTableToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of edge types to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Write information in the processin dialog
    getMessages()->processingMessage("export vehicles");

    // Try to export vehicle table
    if(!vTable->exportTableToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of vehicles to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Write information in the processin dialog
    getMessages()->processingMessage("export detectors");

    // Try to export E1 Table
    if(!E1Table->exportTableToXML() || !E1Table->exportDetectorDefinitionsToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of Induction Loops Detectors E1 to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Try to export E2 table
    if(!E2Table->exportTableToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of Lane Area Detectors E2 to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Try to export E3 Table
    if(!E3Table->exportTableToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of Multi Entry Detectors E3 to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }


    // Try to export route Table
    if(!rTable->exportTableToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of route to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Try to export flowMeasure Table
    if(!fmTable->exportTableToCSV(getProject()->getProjectPath() + "/" + getProject()->getProjectName() + "." + getProjectConfiguration()->getFlowMeasureItemConfiguration()->getItemFileNameWithExtension()))
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of flow Measuress to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Try to export Turn Probability
    if(!trTable->exportTableToXML())
    {
        // If an error occurred during the exporting, show a error message
        QMessageBox::critical(0, ("Export"), ("Error in the conversion of Turn probabilities to SUMO format.\n"), QMessageBox::Ok);

        // Write information in the processin dialog
        getMessages()->processingError();

        // And return false
        return false;
    }
    else
    {
        // Write information in the processin dialog
        getMessages()->processingDone();
    }

    // Write information in the processin dialog
    getMessages()->processingFinished();

    // and return true
    return true;
}

int eNetEditorDatabase::getNumberOfItems()
{
    return  nTable->getNumberOfItems() +
            eTable->getNumberOfItems() +
            lTable->getNumberOfItems() +
            cTable->getNumberOfItems() +
            pTable->getNumberOfItems() +
            rTable->getNumberOfItems() +
            tlTable->getNumberOfItems() +
            bsTable->getNumberOfItems() +
            csTable->getNumberOfItems() +
            vtTable->getNumberOfItems() +
            fTable->getNumberOfItems() +
            etTable->getNumberOfItems() +
            vTable->getNumberOfItems() +
            E1Table->getNumberOfItems() +
            E2Table->getNumberOfItems() +
            E3Table->getNumberOfItems() +
            fmTable->getNumberOfItems();
}

nodeItem *eNetEditorDatabase::findNodeById(const QString &IdToSearch)
{
    return dynamic_cast<nodeItem *>(nTable->findItemById(IdToSearch));
}

edgeItem *eNetEditorDatabase::findEdgeById(const QString &IdToSearch)
{
    return dynamic_cast<edgeItem *>(eTable->findItemById(IdToSearch));
}

QStringList eNetEditorDatabase::getIdsOfLanes(edgeItem *e)
{
    return eTable->getIdsOfLanes(e);
}

laneItem *eNetEditorDatabase::findLaneById(const QString &IdToSearch)
{
    return dynamic_cast<laneItem *>(lTable->findItemById(IdToSearch));
}

connectionItem *eNetEditorDatabase::findConnectionById(const QString &IdToSearch)
{
    return dynamic_cast<connectionItem *>(cTable->findItemById(IdToSearch));
}

connectionItem *eNetEditorDatabase::findConnectionByComponents(laneItem *laneOrigin, laneItem *laneDestiny)
{
    return cTable->findConnectionByComponents(laneOrigin, laneDestiny);
}

prohibitionItem *eNetEditorDatabase::findProhibitionById(const QString &IdToSearch)
{
    return dynamic_cast<prohibitionItem *>(pTable->findItemById(IdToSearch));
}

prohibitionItem *eNetEditorDatabase::findProhibitionByComponents(edgeItem *edgeOrigin, edgeItem *edgeDestiny)
{
    return pTable->findProhibitionByComponents(edgeOrigin, edgeDestiny);
}

routeItem *eNetEditorDatabase::findRouteById(const QString &IdToSearch)
{
    return rTable->findRouteById(IdToSearch);
}

trafficLightTable *eNetEditorDatabase::getTrafficLightTable() const
{
    return tlTable;
}

busStopItem *eNetEditorDatabase::findBusStopById(const QString &IdToSearch)
{
    return dynamic_cast<busStopItem *>(bsTable->findItemById(IdToSearch));
}

chargingStationItem *eNetEditorDatabase::findChargingStationById(const QString &IdToSearch)
{
    return dynamic_cast<chargingStationItem *>(csTable->findItemById(IdToSearch));
}

vehicleTypeItem *eNetEditorDatabase::findVehicleTypeById(const QString &IdToSearch)
{
    return dynamic_cast<vehicleTypeItem *>(vtTable->findItemById(IdToSearch));
}

vehicleTypeItem *eNetEditorDatabase::getVehicleTypeOfTable(int index)
{
    return dynamic_cast<vehicleTypeItem *>(vtTable->getItemAt(index));
}

flowItem *eNetEditorDatabase::findFlowById(const QString &IdToSearch)
{
    return dynamic_cast<flowItem *>(fTable->findItemById(IdToSearch));
}

vehicleItem *eNetEditorDatabase::findVehicleById(const QString &IdToSearch)
{
    return vTable->findVehicleById(IdToSearch);
}

edgeTypeItem *eNetEditorDatabase::findEdgeTypeById(const QString &IdToSearch)
{
    return dynamic_cast<edgeTypeItem *>(etTable->findItemById(IdToSearch));
}

laneAreaE2DetectorItem *eNetEditorDatabase::findLaneAreaE2DetectorById(const QString &IdToSearch)
{
    return dynamic_cast<laneAreaE2DetectorItem *>(E2Table->findItemById(IdToSearch));
}

multiEntryExitE3DetectorItem *eNetEditorDatabase::findMultiEntryExitE3DetectorById(const QString &IdToSearch)
{
    return dynamic_cast<multiEntryExitE3DetectorItem *>(E3Table->findItemById(IdToSearch));
}

inductionLoopsE1DetectorItem *eNetEditorDatabase::findInductionLoopsE1DetectorById(const QString &IdToSearch)
{
    return dynamic_cast<inductionLoopsE1DetectorItem *>(E1Table->findItemById(IdToSearch));
}

flowMeasureItem *eNetEditorDatabase::findFlowMeasureById(const QString &IdToSearch)
{
    return dynamic_cast<flowMeasureItem *>(fmTable->findItemById(IdToSearch));;
}

distributionFunctionItem *eNetEditorDatabase::findDistributionFunctionById(const QString &IdToSearch)
{
    return dynamic_cast<distributionFunctionItem *>(dfTable->findItemById(IdToSearch));
}

turnRatioItem *eNetEditorDatabase::findTurnRatioById(const QString &IdToSearch)
{
    return dynamic_cast<turnRatioItem *>(trTable->findItemById(IdToSearch));
}

nodeTable *eNetEditorDatabase::getNodeTable() const
{
    return nTable;
}

edgeTable *eNetEditorDatabase::getEdgeTable() const
{
    return eTable;
}

laneTable *eNetEditorDatabase::getLaneTable() const
{
    return lTable;
}

connectionTable *eNetEditorDatabase::getConnectionTable() const
{
    return cTable;
}

prohibitionTable *eNetEditorDatabase::getProhibitionTable() const
{
    return pTable;
}

routeTable *eNetEditorDatabase::getRouteTable() const
{
    return rTable;
}

busStopTable *eNetEditorDatabase::getBusStopTable() const
{
    return bsTable;
}

chargingStationTable *eNetEditorDatabase::getChargingStationTable() const
{
    return csTable;
}

vehicleTypeTable *eNetEditorDatabase::getVehicleTypeTable() const
{
    return vtTable;
}

flowTable *eNetEditorDatabase::getFlowTable() const
{
    return fTable;
}

edgeTypeTable *eNetEditorDatabase::getEdgeTypeTable() const
{
    return etTable;
}

vehicleTable *eNetEditorDatabase::getVehicleTable() const
{
    return vTable;
}

inductionLoopsE1DetectorTable *eNetEditorDatabase::getInductionLoopsE1Table() const
{
    return E1Table;
}

laneAreaE2DetectorTable *eNetEditorDatabase::getLaneAreaE2Table() const
{
    return E2Table;
}

multiEntryExitE3DetectorTable *eNetEditorDatabase::getMultiEntryExitE3Table() const
{
    return E3Table;
}

flowMeasureTable *eNetEditorDatabase::getFlowMeasureTable() const
{
    return fmTable;
}

distributionFunctionTable *eNetEditorDatabase::getDistributionFunctionTable() const
{
    return dfTable;
}

turnRatioIntervalTable *eNetEditorDatabase::getTurnRatioIntervalTable() const
{
    return triTable;
}

turnRatioTable *eNetEditorDatabase::getTurnRatioTable() const
{
    return trTable;
}


// PRIVATE FUNCTIONS

void eNetEditorDatabase::loadNodes(QDomElement rootTable)
{
    // Get list of all nodes
    QDomNodeList listOfNodes = rootTable.elementsByTagName("nodeItem");

    // Declare DOM Node element
    QDomElement nodeElement;

    // Interate over connectionsNodeList
    for(int i = 0; i < listOfNodes.count(); i++)
    {
        // Get node of type "nodeItem" with the atributes
        nodeElement = listOfNodes.at(i).toElement();

        // Insert Node in scene and table
        nodeItem *n = new nodeItem(nodeElement.attribute("id"), nodeElement.attribute("posx").toDouble(), nodeElement.attribute("posy").toDouble(), this);

        // Load posz
        n->setPosz(nodeElement.attribute("posz").toDouble());

        // Load type
        n->setType(static_cast<nodeItemType>(nodeElement.attribute("type").toInt()));

        // Load extra parameter 1 name
        n->setExtraParameter1Name(nodeElement.attribute("extraParameter1Name"));

        // Load extra parameter 1 value
        n->setExtraParameter1Value(nodeElement.attribute("extraParameter1Value"));

        // Load extra parameter 2 name
        n->setExtraParameter2Name(nodeElement.attribute("extraParameter2Name"));

        // Load extra parameter 2 value
        n->setExtraParameter2Value(nodeElement.attribute("extraParameter2Value"));

        // Load extra parameter 3 name
        n->setExtraParameter3Name(nodeElement.attribute("extraParameter3Name"));

        // Load extra parameter 3 value
        n->setExtraParameter3Value(nodeElement.attribute("extraParameter3Value"));

        // Update index of table
        while(n->getItemId().toInt() < nTable->getIndex())
        {
            nTable->updateIndex();
        }
    }
}

void eNetEditorDatabase::loadEdges(QDomElement rootTable)
{
    // Get list of all edges
    QDomNodeList listOfEdges = rootTable.elementsByTagName("edgeItem");

    // Declare DOM edge element
    QDomElement edgeElement;

    // Declare pointers to nodes origin and destiny
    nodeItem *origin;
    nodeItem *destiny;

    // Interate over connectionsedgeList
    for(int i = 0; i < listOfEdges.count(); i++)
    {
        // Get edge of type "edgeItem" with the atributes
        edgeElement = listOfEdges.at(i).toElement();

        // Get node origin of database
        origin = findNodeById(edgeElement.attribute("origin"));

        // Get node origin of database
        destiny = findNodeById(edgeElement.attribute("destiny"));

        // Insert edge in scene and table
        edgeItem *e = new edgeItem(origin, destiny, this);

        // Save atribute type
        //e->setType(edgeElement.attribute("type"));

        // Save atribute priority
        e->setPriority(edgeElement.attribute("priority").toInt());

        // Save atribute spreadType
        //e->setSpreadType(edgeElement.attribute("spreadType"));

        // Save atribute streetName
        e->setStreetName(edgeElement.attribute("streetName"));

        // Load extra parameter 1 name
        e->setExtraParameter1Name(edgeElement.attribute("extraParameter1Name"));

        // Load extra parameter 1 value
        e->setExtraParameter1Value(edgeElement.attribute("extraParameter1Value"));

        // Load extra parameter 2 name
        e->setExtraParameter2Name(edgeElement.attribute("extraParameter2Name"));

        // Load extra parameter 2 value
        e->setExtraParameter2Value(edgeElement.attribute("extraParameter2Value"));

        // Load extra parameter 3 name
        e->setExtraParameter3Name(edgeElement.attribute("extraParameter3Name"));

        // Load extra parameter 3 value
        e->setExtraParameter3Value(edgeElement.attribute("extraParameter3Value"));
    }
}

void eNetEditorDatabase::loadLanes(QDomElement rootTable)
{
    // Get list of all edges
    QDomNodeList listOfLanes = rootTable.elementsByTagName("laneItem");

    // Declare DOM lane element
    QDomElement laneElement;

    // Interate over connectionsedgeList
    for(int i = 0; i < listOfLanes.count(); i++)
    {
        // Get lane of type "laneItem" with the atributes
        laneElement = listOfLanes.at(i).toElement();

        // Try to find
        laneItem *l = findLaneById(laneElement.attribute("laneId"));

        // If lane wasn't founded
        if(l == NULL)
        {
            // Get pointer to edge paret of the database
            edgeItem *parent = findEdgeById(laneElement.attribute("edgeParent"));

            // Create new lane
            l = new laneItem(parent, this);
        }

        // Save atribute speed
        l->setSpeed(laneElement.attribute("speed").toInt());

        // Save atribute width
        l->setWidth(laneElement.attribute("width").toInt());

        // Load extra parameter 1 name
        l->setExtraParameter1Name(laneElement.attribute("extraParameter1Name"));

        // Load extra parameter 1 value
        l->setExtraParameter1Value(laneElement.attribute("extraParameter1Value"));

        // Load extra parameter 2 name
        l->setExtraParameter2Name(laneElement.attribute("extraParameter2Name"));

        // Load extra parameter 2 value
        l->setExtraParameter2Value(laneElement.attribute("extraParameter2Value"));

        // Load extra parameter 3 name
        l->setExtraParameter3Name(laneElement.attribute("extraParameter3Name"));

        // Load extra parameter 3 value
        l->setExtraParameter3Value(laneElement.attribute("extraParameter3Value"));

        /** FALTAN VEHICULOS **/
    }
}

void eNetEditorDatabase::loadConnections(QDomElement rootTable)
{
    // Get list of all edges
    QDomNodeList listOfConnections = rootTable.elementsByTagName("connectionItem");

    // Declare DOM connection element
    QDomElement connectionElement;

    // Interate over connectionsedgeList
    for(int i = 0; i < listOfConnections.count(); i++)
    {
        // Get connection of type "connectionItem" with the atributes
        connectionElement = listOfConnections.at(i).toElement();

        // Get lane Origin
        laneItem *laneOrigin = findLaneById(connectionElement.attribute("laneOrigin"));

        // Get lane Destiny
        laneItem *laneDestiny = findLaneById(connectionElement.attribute("laneDestiny"));

        // Create new conection
        connectionItem *c = new connectionItem(laneOrigin, laneDestiny, this);

        // Set ID
        c->setItemId(connectionElement.attribute("connectionId"));

        // Set Pass
        if(connectionElement.attribute("pass") == "true")
        {
            c->setPass(true);
        }
        else
        {
            c->setPass(false);
        }


        /** FALTA VECTOR OF STATES
        void setVectorOfStates(const QVector<char>& newVectorOfStates);
        */
    }
}

void eNetEditorDatabase::loadProhibitions(QDomElement rootTable)
{

}

void eNetEditorDatabase::loadRoutes(QDomElement rootTable)
{

}

void eNetEditorDatabase::loadTrafficLights(QDomElement rootTable)
{

}

void eNetEditorDatabase::loadBusStops(QDomElement rootTable)
{

}

void eNetEditorDatabase::loadChargingStations(QDomElement rootTable)
{

}

void eNetEditorDatabase::loadVehicleTypes(QDomElement rootTable)
{

}

void eNetEditorDatabase::loadFlows(QDomElement rootTable)
{

}

void eNetEditorDatabase::loadEdgeTypes(QDomElement rootTable)
{

}

void eNetEditorDatabase::loadVehicles(QDomElement rootTable)
{

}

void eNetEditorDatabase::loadDetectors(QDomElement rootTable)
{

}

void eNetEditorDatabase::loadFlowMeasures(QDomElement rootTable)
{

}


