#include "netConvertTool.h"

// ConfigurationTools
#include "../configuration/main/eNetEditorMainConfiguration.h"
#include "../configuration/tools/netConvertToolConfiguration.h"
#include "../configuration/project/eNetEditorProjectConfiguration.h"
#include "../configuration/items/vehicles/flowItemConfiguration.h"
#include "../configuration/items/vehicles/vehicleItemConfiguration.h"
#include "../configuration/items/vehicleTypeItemConfiguration.h"
#include "../configuration/items/stops/busStopItemConfiguration.h"
#include "../configuration/items/stops/chargingStationItemConfiguration.h"
#include "../configuration/items/routeItemConfiguration.h"

// Project
#include "../project/eNetEditorProject.h"

// messages
#include "../main/eNetEditorMessages.h"


netConvertTool::netConvertTool(eNetEditorMessages *newMessages, eNetEditorMainConfiguration *neweNetEditorC, QObject *parent) : eNetEditorTool(newMessages, neweNetEditorC, parent)
{
    // Noting to doing
}



bool netConvertTool::startTool(QVector<QString> *inputParameters, QVector<QString> *outputParameters, QVector<QString> *processingParameters)
{
    // Clear execution parameters
    getExecutionParameters()->clear();

    // Write start of processing
    getMessages()->processingStart("netConvert");

    // Set input parameters
    setInputParameters(inputParameters);

    // Set output parameters
    setOutputParameters(outputParameters);

    // Set parameters parameters
    setProcessingParameters(processingParameters);

    // Write list of parameters in console
    getMessages()->writeInConsole("list of parameters of netConvert: " + geteNetEditorConfiguration()->getNetConvertConfiguration()->getExecutablePath() + (*getExecutionParameters()));

    // Start process
    start(geteNetEditorConfiguration()->getNetConvertConfiguration()->getExecutablePath() + (*getExecutionParameters()));

    // Start loop (will be automatic stopped after ejecution)
    startLoop();

    // Create QFileInfo with the output path
    QFileInfo netFile(outputParameters->at(netConvertOutputParameterOutputFile));

    // If a net File was created (In other words, netConvert was sucesfully executed)
    if(netFile.exists())
    {
        // Finished Process
        getMessages()->processingFinished();

        // The execution was sucesfully, then return true
        return true;
    }
    else
    {
        // Finished Process
        getMessages()->processingError();

        // There are an error in the execution, then return false
        return false;
    }
}

void netConvertTool::setInputParameters(QVector<QString> *inputParameters)
{

    // Set netConvert Input Parameter Sumo Net File
    getExecutionParameters()->append(" --node-files " + inputParameters->at(netConvertInputParameterNodeFiles));

    // Set netConvert Input Parameter Edge Files
    getExecutionParameters()->append(" --edge-files " + inputParameters->at(netConvertInputParameterEdgeFiles));

    // Set netConvert Input Parameter Connection Files
    getExecutionParameters()->append(" --connection-files " + inputParameters->at(netConvertInputParameterConnectionFiles));

    // Set netConvert Input Parameter Tllogic Files
    getExecutionParameters()->append(" --tllogic-files " + inputParameters->at(netConvertInputParameterTllogicFiles));

    // Set net Convert Input Parameter Type Files
    //getExecutionParameters()->append(" --type-files " + inputParameters->at(netConvertInputParameterTypeFiles));
}

void netConvertTool::setOutputParameters(QVector<QString> *outputParameters)
{
    // Check if the output exist
    if(QFile(outputParameters->at(netConvertOutputParameterOutputFile)).exists())
    {
        // If exist, remove it
        QFile::remove(outputParameters->at(netConvertOutputParameterOutputFile));
    }

    // Set netConvert Output Parameter Output File
    getExecutionParameters()->append(" --output-file " + outputParameters->at(netConvertOutputParameterOutputFile));
}

void netConvertTool::setProcessingParameters(QVector<QString> *processingParameters)
{

}

bool netConvertTool::createSumoCfgFile(eNetEditorProject *project)
{
    // Declare QString with the file
    QString filepath = project->getProjectPath() + "/" + geteNetEditorConfiguration()->getNetConvertConfiguration()->getOutputfolder() + "/" + project->getProjectName() + ".netConvert.sumocfg";

    // Create a new Qfile from path
    QFile file(filepath);

    // Check if the file exist
    if(file.exists())
    {
        // If exist, remove it
        QFile::remove(filepath);
    }

    // Set open parameters
    file.open(QIODevice::WriteOnly);

    // Try to open file
    if(!file.error())
    {
        // Create XML stream writer
        QXmlStreamWriter xmlWriter(&file);

        // Set autoformating
        xmlWriter.setAutoFormatting(true);

        // Write start of document
        xmlWriter.writeStartDocument();

        // Write open Label
        xmlWriter.writeStartElement("configuration");

        // Write input Label
        xmlWriter.writeStartElement("input");

        // Write net-file
        xmlWriter.writeStartElement("net-file");
        xmlWriter.writeAttribute("value", project->getProjectPath() + "/" + geteNetEditorConfiguration()->getNetConvertConfiguration()->getOutputfolder() + "/" + project->getProjectName() + "." + geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultOutputFile());
        xmlWriter.writeEndElement();

        // Write route-files
        xmlWriter.writeStartElement("route-files");
        xmlWriter.writeAttribute("value", project->getProjectPath() + "/" + project->getProjectName() + "." + project->getProjectConfiguration()->getRouteItemConfiguration()->getItemFileNameWithExtension() + " " +
                                 project->getProjectPath() + "/" + project->getProjectName() + "." + project->getProjectConfiguration()->getVehicleTypeItemConfiguration()->getItemFileNameWithExtension() + " " +
                                 project->getProjectPath() + "/" + project->getProjectName() + "." + project->getProjectConfiguration()->getVehicleItemConfiguration()->getItemFileNameWithExtension() + " " +
                                 project->getProjectPath() + "/" + project->getProjectName() + "." + project->getProjectConfiguration()->getFlowItemConfiguration()->getItemFileNameWithExtension());
        xmlWriter.writeEndElement();


        // Write additional-files
        xmlWriter.writeStartElement("additional-files");
        xmlWriter.writeAttribute("value", project->getProjectPath() + "/" + project->getProjectName() + "." + project->getProjectConfiguration()->getBusStopItemConfiguration()->getItemFileNameWithExtension() + " " +
                                 project->getProjectPath() + "/" + project->getProjectName() + "." + project->getProjectConfiguration()->getChargingStationItemConfiguration()->getItemFileNameWithExtension());
        xmlWriter.writeEndElement();

        // Write input end
        xmlWriter.writeEndElement();

        // Write time Label
        xmlWriter.writeStartElement("time");

        // Write time begin value
        xmlWriter.writeStartElement("begin");
        xmlWriter.writeAttribute("value", QString::number(project->getTimeBegin()));
        xmlWriter.writeEndElement();

        // Write time begin value
        xmlWriter.writeStartElement("end");
        xmlWriter.writeAttribute("value", QString::number(project->getTimeEnd()));
        xmlWriter.writeEndElement();

        // Write time tag end
        xmlWriter.writeEndElement();

        // Write output tag
        xmlWriter.writeStartElement("output");

        // Write tripinfo-output
        xmlWriter.writeStartElement("tripinfo-output");
        xmlWriter.writeAttribute("value", "tripinfo.xml");  /// CAMBIAR
        xmlWriter.writeEndElement();

        // Write battery-output
        xmlWriter.writeStartElement("battery-output");
        xmlWriter.writeAttribute("value", "battery.xml");   /// CAMBIAR
        xmlWriter.writeEndElement();

        // Write output tag close
        xmlWriter.writeEndElement();

        // Write configuration tag close
        xmlWriter.writeEndElement();

        // Close stream
        file.close();

        // configuration exported sucesfully, then return true
        return true;
    }
    else
    {
        // If there are an error opening the file, then return false
        return false;
    }
}


