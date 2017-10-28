#include "duaRouterTool.h"

// ConfigurationTools
#include "../configuration/main/eNetEditorMainConfiguration.h"

#include "../configuration/tools/duaRouterToolConfiguration.h"

// Messages
#include "../main/eNetEditorMessages.h"


duaRouterTool::duaRouterTool(eNetEditorMessages *newMessages, eNetEditorMainConfiguration *neweNetEditorC, QObject *parent) : eNetEditorTool(newMessages, neweNetEditorC, parent)
{
}

bool duaRouterTool::startTool(QVector<QString> *inputParameters, QVector<QString> *outputParameters, QVector<QString> *processingParameters)
{
    // Clear execution parameters
    getExecutionParameters();

    // Write start of processing
    getMessages()->processingStart("duaROuter");

    // Set trip command
    if(inputParameters->at(duaRouterInputParameterTripFiles) != "")
    {
        getExecutionParameters()->append(" --trip-files " + inputParameters->at(duaRouterInputParameterTripFiles));
    }

    // Set flow command
    if(inputParameters->at(duaRouterInputParameterFlowFiles) != "")
    {
        getExecutionParameters()->append(" --flow-files " + inputParameters->at(duaRouterInputParameterFlowFiles));
    }

    // Set additional command
    if(inputParameters->at(duaRouterInputParameterAdditionalFiles) != "")
    {
        getExecutionParameters()->append(" --additional-files " + inputParameters->at(duaRouterInputParameterAdditionalFiles));
    }

    // Set output command
    if(outputParameters->at(duaRouterOutputParameterOutputFile) != "")
    {
        getExecutionParameters()->append(" --output-file " + outputParameters->at(duaRouterOutputParameterOutputFile));
    }

    qDebug() << "list of parameters: " << geteNetEditorConfiguration()->getDuaRouterConfiguration()->getExecutablePath() + (*getExecutionParameters());

    // Start process
    start(geteNetEditorConfiguration()->getDuaRouterConfiguration()->getExecutablePath() + (*getExecutionParameters()));

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

