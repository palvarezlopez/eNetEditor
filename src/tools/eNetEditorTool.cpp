#include "eNetEditorTool.h"

// Database
#include "../database/eNetEditorDatabase.h"

// Messages
#include "../main/eNetEditorMessages.h"

// ConfigurationTools
#include "../configuration/tools/eNetEditorToolConfiguration.h"

eNetEditorTool::eNetEditorTool(eNetEditorMessages *newMessages, eNetEditorMainConfiguration *neweNetEditorC, QObject *parent) : QProcess(parent), eNetEditor()
{
    // Set pointer to messages
    messages = newMessages;

    // Set pointer to configuration
    eNetEditorC = neweNetEditorC;

    // Connect Loop with Signal of finish
    connect(this, SIGNAL(finished(int, QProcess::ExitStatus)), &waitLoop, SLOT(quit()));

    // Change process channel
    setProcessChannelMode(QProcess::SeparateChannels);

    // Create executionParameters
    executionParameters = new QString();
}

eNetEditorTool::~eNetEditorTool()
{
    // If process is running
    if(pid() > 0)
    {
        // Terminate process inmediately
        terminate();
    }

    // Delete executionParameters
    delete executionParameters;
}

void eNetEditorTool::startLoop()
{
    waitLoop.exec();
}

eNetEditorMessages *eNetEditorTool::getMessages() const
{
    return messages;
}

eNetEditorMainConfiguration *eNetEditorTool::geteNetEditorConfiguration() const
{
    return eNetEditorC;
}

QString *eNetEditorTool::getExecutionParameters() const
{
    return executionParameters;
}
