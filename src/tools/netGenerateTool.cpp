#include "netGenerateTool.h"

// ConfigurationTools
#include "../configuration/tools/netGenerateToolConfiguration.h"


netGenerateTool::netGenerateTool(eNetEditorMessages *newMessages, eNetEditorMainConfiguration *neweNetEditorC, QObject *parent) : eNetEditorTool(newMessages, neweNetEditorC, parent)
{

}

bool netGenerateTool::startTool(QVector<QString> *inputParameters, QVector<QString> *outputParameters, QVector<QString> *processingParameters)
{
    // Clear execution parameters
    getExecutionParameters();

    return false;
}
