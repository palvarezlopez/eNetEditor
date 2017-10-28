#include "eNetEditorMessages.h"

// Main window
#include "../dialogs/main/eNetEditorMainWindow.h"

// ProcessingDialog
#include "../dialogs/main/eNetEditorProcessingDialog.h"


eNetEditorMessages::eNetEditorMessages(eNetEditorMainWindow *neweNetEditorMainW) : QObject(neweNetEditorMainW),  eNetEditor()
{
    // Set pointer to main window
    eNetEditorMainW = neweNetEditorMainW;
}

eNetEditorMessages::~eNetEditorMessages()
{
    // Nothing to erase
}

void eNetEditorMessages::writeInConsole(const QString &message, consoleMessageType messageType, bool endOfLine)
{
    // Set color (Yellow if isn't normal, warning or error)
    if (messageType == consoleMessageTypeNormal)
    {
        eNetEditorMainW->getConsole()->setTextColor(QColor("black"));
    }
    else if (messageType == consoleMessageTypeWarning)
    {
        eNetEditorMainW->getConsole()->setTextColor(QColor("orange"));
    }
    else if (messageType == consoleMessageTypeError)
    {
        eNetEditorMainW->getConsole()->setTextColor(QColor("red"));
    }

    // If end of line is activated
    if(endOfLine)
    {
        // Add string to console without erasing the writter above.
        eNetEditorMainW->getConsole()->append(message);
    }
    else
    {
        // Add string to console without erasing the writter above.
        eNetEditorMainW->getConsole()->append(message + "arreglar esto");
    }
}

void eNetEditorMessages::processingStart(const QString &nameOfProcess, bool writeAlsoInConsole)
{
    // Start processing Dialog
    eNetEditorMainW->getProcessingDialog()->processingStart(nameOfProcess);

    // If flag writeAlsoInConsole is enabled
    if(writeAlsoInConsole)
    {
        // Write the same information in the console
        writeInConsole("Process " + nameOfProcess + " started");
    }
}

void eNetEditorMessages::processingMessage(const QString &message, bool writeAlsoInConsole)
{
    // Write message in processing Dialog
    eNetEditorMainW->getProcessingDialog()->processingMessage(message);

    if(writeAlsoInConsole)
    {
        // Write the same information in the console
        writeInConsole("processing " + message + "...", consoleMessageTypeNormal, false);
    }
}

void eNetEditorMessages::processingDone(bool writeAlsoInConsole)
{
    // Write message in processing Dialog
    eNetEditorMainW->getProcessingDialog()->processingDone();

    if(writeAlsoInConsole)
    {
        // Write the same information in the console
        writeInConsole("done.");
    }
}

void eNetEditorMessages::processingError(bool writeAlsoInConsole)
{
    // Write message in processing Dialog
    eNetEditorMainW->getProcessingDialog()->processingError();

    if(writeAlsoInConsole)
    {
        // Write the same information in the console
        writeInConsole("error!", consoleMessageTypeError);
    }
}

void eNetEditorMessages::processingFinished(bool writeAlsoInConsole)
{
    // Write message in processing Dialog
    eNetEditorMainW->getProcessingDialog()->processingFinished();

    if(writeAlsoInConsole)
    {
        // Write the same information in the console
        writeInConsole("finished.");
    }
}

void eNetEditorMessages::toolMessage(const QString &toolName, const QString &message, bool writeAlsoInConsole)
{
    // Declare a copy of newMessage
    QString clearedMessage(message);

    // Clear character \r
    clearedMessage.remove(QChar('\r'));

    // Clear character\n
    clearedMessage.remove(QChar('\n'));


    // Write message in processing Dialog
    eNetEditorMainW->getProcessingDialog()->toolMessage(toolName, clearedMessage);

    if(writeAlsoInConsole)
    {
        // Write the same information in the console
        writeInConsole(toolName + ": " + clearedMessage);
    }
}

