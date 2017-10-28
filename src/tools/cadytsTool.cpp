#include "cadytsTool.h"

// ConfigurationTools
#include "../configuration/tools/cadytsToolConfiguration.h"


cadytsTool::cadytsTool(eNetEditorMessages *newMessages, eNetEditorMainConfiguration *neweNetEditorC, QObject *parent) : eNetEditorTool(newMessages, neweNetEditorC, parent)
{
}

cadytsTool::~cadytsTool()
{

}

bool cadytsTool::startTool(QVector<QString> *inputParameters, QVector<QString> *outputParameters, QVector<QString> *processingParameters)
{
    // Clear execution parameters
    getExecutionParameters();

    return false;
}
