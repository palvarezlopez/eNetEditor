#include "dfRouterTool.h"

// ConfigurationTools
#include "../configuration/main/eNetEditorMainConfiguration.h"
#include "../configuration/tools/dfRouterToolConfiguration.h"
#include "../configuration/tools/netConvertToolConfiguration.h"
#include "../configuration/project/eNetEditorProjectConfiguration.h"
#include "../configuration/items/stops/busStopItemConfiguration.h"
#include "../configuration/items/stops/chargingStationItemConfiguration.h"

//Project
#include "../project/eNetEditorProject.h"

// Messages
#include "../main/eNetEditorMessages.h"


dfRouterTool::dfRouterTool(eNetEditorMessages *newMessages, eNetEditorMainConfiguration *neweNetEditorC, QObject *parent) : eNetEditorTool(newMessages, neweNetEditorC, parent)
{
}

bool dfRouterTool::createSumoCfgFile(eNetEditorProject *project)
{
    // Declare QString with the file
    QString filepath = project->getProjectPath() + "/" + geteNetEditorConfiguration()->getDfRouterConfiguration()->getOutputfolder() + "/" + project->getProjectName() + ".dfRouter.sumocfg";

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
        xmlWriter.writeAttribute("value", project->getProjectPath() + "/" + geteNetEditorConfiguration()->getDfRouterConfiguration()->getOutputfolder() + "/" + project->getProjectName() + "." + geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultOutputRoutesFile() + " " +
                                 project->getProjectPath() + "/" + geteNetEditorConfiguration()->getDfRouterConfiguration()->getOutputfolder() + "/" + project->getProjectName() + "." + geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultOutputEmittersFile());
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

bool dfRouterTool::startTool(QVector<QString> *inputParameters, QVector<QString> *outputParameters, QVector<QString> *processingParameters)
{
    // Clear execution parameters
    getExecutionParameters()->clear();

    // Write start of processing
    getMessages()->processingStart("dfRouter");

    // Set input parameters
    setInputParameters(inputParameters);

    // Set output parameters
    setOutputParameters(outputParameters);

    // Set parameters parameters
    setProcessingParameters(processingParameters);

    // Write list of parameters in console
    getMessages()->writeInConsole( "list of parameters of dfRouter: " + geteNetEditorConfiguration()->getDfRouterConfiguration()->getExecutablePath() + (*getExecutionParameters()));

    // Start process
    start(geteNetEditorConfiguration()->getDfRouterConfiguration()->getExecutablePath() + (*getExecutionParameters()));

    // Start loop (will be automatic stopped after ejecution)
    startLoop();

    // Check if the output contains the word Success
    if(readAllStandardError() == "")
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

void dfRouterTool::setInputParameters(QVector<QString> *inputParameters)
{
    // Set input parameter net
    if(inputParameters->at(dfRouterInputParameterNetFile) != "")
    {
        // Clear execution parameters
        getExecutionParameters()->append(" --net-file " + inputParameters->at(dfRouterInputParameterNetFile));
    }

    // Set input parameter detector
    if(inputParameters->at(dfRouterInputParameterDetectorFiles) != "")
    {
        getExecutionParameters()->append(" --detector-files " + inputParameters->at(dfRouterInputParameterDetectorFiles));
    }

    // Set input parameter measures
    if(inputParameters->at(dfRouterInputParameterMeasureFiles) != "")
    {
        getExecutionParameters()->append(" --measure-files " + inputParameters->at(dfRouterInputParameterMeasureFiles));
    }
}

void dfRouterTool::setOutputParameters(QVector<QString> *outputParameters)
{
    /*  EliminarPrefijo
        // Set output parameter dfRouterOutputParameterPrefixFile
        if(outputParameters->at(dfRouterOutputParameterPrefixFile) != "")
        {
            getExecutionParameters()->append(" --output-prefix " + outputParameters->at(dfRouterOutputParameterPrefixFile));
        }
    */

    // Set output parameter dfRouterOutputParameterRoutesFile
    if(outputParameters->at(dfRouterOutputParameterRoutesFile) != "")
    {
        // Check if dfRouterOutputParameterRoutesFile exist
        if(QFile(outputParameters->at(dfRouterOutputParameterRoutesFile)).exists())
        {
            // If exist, remove it
            QFile::remove(outputParameters->at(dfRouterOutputParameterRoutesFile));
        }
        // Append name of parameter and value
        getExecutionParameters()->append(" --routes-output " + outputParameters->at(dfRouterOutputParameterRoutesFile));
    }

    // Set output parameter dfRouterOutputParameterRoutesForAll
    if(outputParameters->at(dfRouterOutputParameterRoutesForAll) != "")
    {
        getExecutionParameters()->append(" --routes-for-all " + outputParameters->at(dfRouterOutputParameterRoutesForAll));
    }

    // Set output parameter dfRouterOutputParameterDetectorFile
    if(outputParameters->at(dfRouterOutputParameterDetectorFile) != "")
    {
        // Check if dfRouterOutputParameterDetectorFile exist
        if(QFile(outputParameters->at(dfRouterOutputParameterDetectorFile)).exists())
        {
            // If exist, remove it
            QFile::remove(outputParameters->at(dfRouterOutputParameterDetectorFile));
        }

        // Append name of parameter and value
        getExecutionParameters()->append(" --detector-output " + outputParameters->at(dfRouterOutputParameterDetectorFile));
    }

    // Set output parameter dfRouterOutputParameterDetectorsPoiFile
    if(outputParameters->at(dfRouterOutputParameterDetectorsPoiFile) != "")
    {
        // Check if dfRouterOutputParameterDetectorFile exist
        if(QFile(outputParameters->at(dfRouterOutputParameterDetectorsPoiFile)).exists())
        {
            // If exist, remove it
            QFile::remove(outputParameters->at(dfRouterOutputParameterDetectorsPoiFile));
        }

        // Append name of parameter and value
        getExecutionParameters()->append(" --detectors-poi-output " + outputParameters->at(dfRouterOutputParameterDetectorsPoiFile));
    }

    // Set output parameter dfRouterOutputParameterEmittersFile
    if(outputParameters->at(dfRouterOutputParameterEmittersFile) != "")
    {
        // Check if dfRouterOutputParameterDetectorFile exist
        if(QFile(outputParameters->at(dfRouterOutputParameterEmittersFile)).exists())
        {
            // If exist, remove it
            QFile::remove(outputParameters->at(dfRouterOutputParameterEmittersFile));
        }

        // Append name of parameter and value
        getExecutionParameters()->append(" --emitters-output " + outputParameters->at(dfRouterOutputParameterEmittersFile));
    }

    // Set output parameter dfRouterOutputParameterVtype
    if(outputParameters->at(dfRouterOutputParameterVtype) != "")
    {
        getExecutionParameters()->append(" --vtype " + outputParameters->at(dfRouterOutputParameterVtype));
    }

    // Set output parameter dfRouterOutputParameterEndRerouteFile
    if(outputParameters->at(dfRouterOutputParameterEndRerouteFile) != "")
    {
        // Check if dfRouterOutputParameterEndRerouteFile exist
        if(QFile(outputParameters->at(dfRouterOutputParameterEndRerouteFile)).exists())
        {
            // If exist, remove it
            QFile::remove(outputParameters->at(dfRouterOutputParameterEndRerouteFile));
        }

        // Append name of parameter and value
        getExecutionParameters()->append(" --end-reroute-output " + outputParameters->at(dfRouterOutputParameterEndRerouteFile));
    }

    // Set output parameter dfRouterOutputParameterVariableSpeedSignFile
    if(outputParameters->at(dfRouterOutputParameterVariableSpeedSignFile) != "")
    {
        // Check if dfRouterOutputParameterVariableSpeedSignFile exist
        if(QFile(outputParameters->at(dfRouterOutputParameterVariableSpeedSignFile)).exists())
        {
            // If exist, remove it
            QFile::remove(outputParameters->at(dfRouterOutputParameterVariableSpeedSignFile));
        }

        // Append name of parameter and value
        getExecutionParameters()->append(" --variable-speed-sign-output " + outputParameters->at(dfRouterOutputParameterVariableSpeedSignFile));
    }

    // Set output parameter dfRouterOutputParameterEmittersPoiFile
    if(outputParameters->at(dfRouterOutputParameterEmittersPoiFile) != "")
    {
        // Check if dfRouterOutputParameterValidationFile exist
        if(QFile(outputParameters->at(dfRouterOutputParameterEmittersPoiFile)).exists())
        {
            // If exist, remove it
            QFile::remove(outputParameters->at(dfRouterOutputParameterEmittersPoiFile));
        }

        // Append name of parameter and value
        getExecutionParameters()->append(" --emitters-poi-output " + outputParameters->at(dfRouterOutputParameterEmittersPoiFile));
    }

    // Set output parameter dfRouterOutputParameterValidationFile
    if(outputParameters->at(dfRouterOutputParameterValidationFile) != "")
    {
        // Check if dfRouterOutputParameterValidationFile exist
        if(QFile(outputParameters->at(dfRouterOutputParameterValidationFile)).exists())
        {
            // If exist, remove it
            QFile::remove(outputParameters->at(dfRouterOutputParameterValidationFile));
        }

        // Append name of parameter and value
        getExecutionParameters()->append(" --validation-output " + outputParameters->at(dfRouterOutputParameterValidationFile));
    }

    // Set output parameter dfRouterOutputParameterValidationAddSources
    if(outputParameters->at(dfRouterOutputParameterValidationAddSources) != "")
    {
        getExecutionParameters()->append(" --validation-output.add-sources " + outputParameters->at(dfRouterOutputParameterValidationAddSources));
    }
}

void dfRouterTool::setProcessingParameters(QVector<QString> *processingParameters)
{
    // Set Parameter dfRouterProcessingParametersGuessEmptyFlows
    getExecutionParameters()->append(" --guess-empty-flows " + processingParameters->at(dfRouterProcessingParametersGuessEmptyFlows));

    // Set Parameter dfRouterProcessingParametersHighwayMode
    getExecutionParameters()->append(" --highway-mode " + processingParameters->at(dfRouterProcessingParametersHighwayMode));

    // Set Parameter dfRouterProcessingParametersIgnoreInvalidDetectors
    getExecutionParameters()->append(" --ignore-invalid-detectors " + processingParameters->at(dfRouterProcessingParametersIgnoreInvalidDetectors));

    // Set Parameter dfRouterProcessingParametersRevalidateDetectors
    getExecutionParameters()->append(" --revalidate-detectors " + processingParameters->at(dfRouterProcessingParametersRevalidateDetectors));

    // Set Parameter dfRouterProcessingParametersRevalidateRoutes
    getExecutionParameters()->append(" --revalidate-routes " + processingParameters->at(dfRouterProcessingParametersRevalidateRoutes));

    // Set Parameter dfRouterProcessingParametersKeepUnfinishedRoutes
    getExecutionParameters()->append(" --keep-unfinished-routes " + processingParameters->at(dfRouterProcessingParametersKeepUnfinishedRoutes));

    // Set Parameter dfRouterProcessingParametersKeepLongerRoutes
    getExecutionParameters()->append(" --keep-longer-routes " + processingParameters->at(dfRouterProcessingParametersKeepLongerRoutes));

    // Set Parameter dfRouterProcessingParametersMaxSearchDepth
    if(processingParameters->at(dfRouterProcessingParametersMaxSearchDepth) != "")
    {
        getExecutionParameters()->append(" --max-search-depth " + processingParameters->at(dfRouterProcessingParametersMaxSearchDepth));
    }

    // Set Parameter dfRouterProcessingParametersEmissionsOnly
    getExecutionParameters()->append(" --emissions-only " + processingParameters->at(dfRouterProcessingParametersEmissionsOnly));

    // Set Parameter dfRouterProcessingParametersDisallowedEdges
    if(processingParameters->at(dfRouterProcessingParametersDisallowedEdges) != "")
    {
        getExecutionParameters()->append(" --disallowed-edges " + processingParameters->at(dfRouterProcessingParametersDisallowedEdges));
    }

    // Set Parameter dfRouterProcessingParametersKeepTurnarounds
    getExecutionParameters()->append(" --keep-turnarounds " + processingParameters->at(dfRouterProcessingParametersKeepTurnarounds));

    // Set Parameter dfRouterProcessingParametersMinRouteLength
    if(processingParameters->at(dfRouterProcessingParametersMinRouteLength) != "")
    {
        getExecutionParameters()->append(" --min-route-length " + processingParameters->at(dfRouterProcessingParametersMinRouteLength));
    }

    // Set Parameter dfRouterProcessingParametersTimeFactor
    if(processingParameters->at(dfRouterProcessingParametersTimeFactor) != "")
    {
        getExecutionParameters()->append(" --time-factor " + processingParameters->at(dfRouterProcessingParametersTimeFactor));
    }

    // Set Parameter dfRouterProcessingParametersTimeOffset
    if(processingParameters->at(dfRouterProcessingParametersTimeOffset) != "")
    {
        getExecutionParameters()->append(" --time-offset " + processingParameters->at(dfRouterProcessingParametersTimeOffset));
    }

    // Set Parameter dfRouterProcessingParametersTimeStep
    if(processingParameters->at(dfRouterProcessingParametersTimeStep) != "")
    {
        getExecutionParameters()->append(" --time-step " + processingParameters->at(dfRouterProcessingParametersTimeStep));
    }

    // Set Parameter dfRouterProcessingParametersCalibratorOutput
    getExecutionParameters()->append(" --calibrator-output " + processingParameters->at(dfRouterProcessingParametersCalibratorOutput));

    // Set Parameter dfRouterProcessingParametersIncludeUnusedRoutes
    getExecutionParameters()->append(" --include-unused-routes " + processingParameters->at(dfRouterProcessingParametersIncludeUnusedRoutes));

    // Set Parameter dfRouterProcessingParametersRevalidateFlows
    getExecutionParameters()->append(" --revalidate-flows " + processingParameters->at(dfRouterProcessingParametersRevalidateFlows));

    // Set Parameter dfRouterProcessingParametersRemoveEmptyDetectors
    getExecutionParameters()->append(" --remove-empty-detectors " + processingParameters->at(dfRouterProcessingParametersRemoveEmptyDetectors));

    // Set Parameter dfRouterProcessingParametersStrictSources
    getExecutionParameters()->append(" --strict-sources " + processingParameters->at(dfRouterProcessingParametersStrictSources));

    // Set Parameter dfRouterProcessingParametersRespectConcurrentInflows
    getExecutionParameters()->append(" --respect-concurrent-inflows " + processingParameters->at(dfRouterProcessingParametersRespectConcurrentInflows));

    // Set Parameter dfRouterProcessingParametersScale
    if(processingParameters->at(dfRouterProcessingParametersScale) != "")
    {
        getExecutionParameters()->append(" --scale " + processingParameters->at(dfRouterProcessingParametersScale));
    }

    // Set Parameter dfRouterProcessingParametersDepartlane
    if(processingParameters->at(dfRouterProcessingParametersDepartlane) != "")
    {
        getExecutionParameters()->append(" --departlane " + processingParameters->at(dfRouterProcessingParametersDepartlane));
    }

    // Set Parameter dfRouterProcessingParametersDepartpos
    if(processingParameters->at(dfRouterProcessingParametersDepartpos) != "")
    {
        getExecutionParameters()->append(" --departpos " + processingParameters->at(dfRouterProcessingParametersDepartpos));
    }

    // Set Parameter dfRouterProcessingParametersDepartspeed
    if(processingParameters->at(dfRouterProcessingParametersDepartspeed) != "")
    {
        getExecutionParameters()->append(" --departspeed " + processingParameters->at(dfRouterProcessingParametersDepartspeed));
    }

    // Set Parameter dfRouterProcessingParametersArrivallane
    if(processingParameters->at(dfRouterProcessingParametersArrivallane) != "")
    {
        getExecutionParameters()->append(" --arrivallane " + processingParameters->at(dfRouterProcessingParametersArrivallane));
    }

    // Set Parameter dfRouterProcessingParametersArrivalpos
    if(processingParameters->at(dfRouterProcessingParametersArrivalpos) != "")
    {
        getExecutionParameters()->append(" --arrivalpos " + processingParameters->at(dfRouterProcessingParametersArrivalpos));
    }

    // Set Parameter dfRouterProcessingParametersArrivalspeed
    if(processingParameters->at(dfRouterProcessingParametersArrivalspeed) != "")
    {
        getExecutionParameters()->append(" --arrivalspeed " + processingParameters->at(dfRouterProcessingParametersArrivalspeed));
    }

    // Set time parameters dfRouterProcessingParametersBegin
    if(processingParameters->at(dfRouterProcessingParametersBegin) != "")
    {
        getExecutionParameters()->at(dfRouterProcessingParametersBegin);
    }

    // Set time parameters dfRouterProcessingParametersEnd
    if(processingParameters->at(dfRouterProcessingParametersEnd) != "")
    {
        getExecutionParameters()->at(dfRouterProcessingParametersEnd);
    }

    // Set Parameter dfRouterProcessingParametersVerbose
    getExecutionParameters()->append(" --verbose " + processingParameters->at(dfRouterProcessingParametersVerbose));

    // Set Parameter dfRouterProcessingParametersPrintOptions
    getExecutionParameters()->append(" --print-options " + processingParameters->at(dfRouterProcessingParametersPrintOptions));

    // Set Parameter dfRouterProcessingParametersHelp
    getExecutionParameters()->append(" --help " + processingParameters->at(dfRouterProcessingParametersHelp));

    // Set Parameter dfRouterProcessingParametersVersion
    getExecutionParameters()->append(" --version " + processingParameters->at(dfRouterProcessingParametersVersion));

    // Set Parameter dfRouterProcessingParametersXmlValidation
    if(processingParameters->at(dfRouterProcessingParametersXmlValidation) != "")
    {
        getExecutionParameters()->append(" --xml-validation " + processingParameters->at(dfRouterProcessingParametersXmlValidation));
    }

    // Set Parameter dfRouterProcessingParametersXmlValidationNet
    if(processingParameters->at(dfRouterProcessingParametersXmlValidationNet) != "")
    {
        getExecutionParameters()->append(" --xml-validation.net " + processingParameters->at(dfRouterProcessingParametersXmlValidationNet));
    }

    // Set Parameter dfRouterProcessingParametersNoWarnings
    getExecutionParameters()->append(" --no-warnings " + processingParameters->at(dfRouterProcessingParametersNoWarnings));

    // Set Parameter dfRouterProcessingParametersLog
    if(processingParameters->at(dfRouterProcessingParametersLog) != "")
    {
        getExecutionParameters()->append(" --log " + processingParameters->at(dfRouterProcessingParametersLog));
    }

    // Set Parameter dfRouterProcessingParametersMessageLog
    if(processingParameters->at(dfRouterProcessingParametersMessageLog) != "")
    {
        getExecutionParameters()->append(" --message-log " + processingParameters->at(dfRouterProcessingParametersMessageLog));
    }

    // Set Parameter dfRouterProcessingParametersErrorLog
    if(processingParameters->at(dfRouterProcessingParametersErrorLog) != "")
    {
        getExecutionParameters()->append(" --error-log " + processingParameters->at(dfRouterProcessingParametersErrorLog));
    }

    // Set Parameter dfRouterProcessingParametersReportEmptyDetectors
    getExecutionParameters()->append(" --report-empty-detectors " + processingParameters->at(dfRouterProcessingParametersReportEmptyDetectors));

    // Set Parameter dfRouterProcessingParametersPrintAbsoluteFlows
    getExecutionParameters()->append(" --print-absolute-flows " + processingParameters->at(dfRouterProcessingParametersPrintAbsoluteFlows));

    // Set Parameter dfRouterProcessingParametersNoStepLog
    getExecutionParameters()->append(" --no-step-log " + processingParameters->at(dfRouterProcessingParametersNoStepLog));

    // Set Parameter dfRouterProcessingParametersRandom
    getExecutionParameters()->append(" --random " + processingParameters->at(dfRouterProcessingParametersRandom));

    // Set Parameter dfRouterProcessingParametersSeed
    if(processingParameters->at(dfRouterProcessingParametersSeed) != "")
    {
        getExecutionParameters()->append(" --seed " + processingParameters->at(dfRouterProcessingParametersSeed));
    }
}
