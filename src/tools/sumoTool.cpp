#include "sumoTool.h"

// ConfigurationTools
#include "../configuration/tools/sumoToolConfiguration.h"


sumoTool::sumoTool(eNetEditorMessages *newMessages, eNetEditorMainConfiguration *neweNetEditorC, QObject *parent) : eNetEditorTool(newMessages, neweNetEditorC, parent)
{
}

bool sumoTool::startTool(QVector<QString> *inputParameters, QVector<QString> *outputParameters, QVector<QString> *processingParameters)
{
    // Clear execution parameters
    getExecutionParameters();

    return false;
}
