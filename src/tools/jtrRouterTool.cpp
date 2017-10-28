#include "jtrRouterTool.h"

// ConfigurationTools
#include "../configuration/tools/jtrRouterToolConfiguration.h"


jtrRouterTool::jtrRouterTool(eNetEditorMessages *newMessages, eNetEditorMainConfiguration *neweNetEditorC, QObject *parent) : eNetEditorTool(newMessages, neweNetEditorC, parent)
{
}



bool jtrRouterTool::startTool(QVector<QString> *inputParameters, QVector<QString> *outputParameters, QVector<QString> *processingParameters)
{
    // Clear execution parameters
    getExecutionParameters();

    return false;
}
