#ifndef ENETEDITORMESSAGES_H
#define ENETEDITORMESSAGES_H

#include "eNetEditor.h"


// Declare enum consoleMessageType
enum consoleMessageType
{
    consoleMessageTypeNormal,
    consoleMessageTypeWarning,
    consoleMessageTypeError,
};



class eNetEditorMessages : public QObject, public eNetEditor
{
    Q_OBJECT

public:

    explicit eNetEditorMessages(eNetEditorMainWindow *neweNetEditorMainW);

    ~eNetEditorMessages();

    void writeInConsole(const QString &message, consoleMessageType messageType = consoleMessageTypeNormal, bool endOfLine = true);

    void processingStart(const QString &nameOfProcess, bool writeAlsoInConsole = true);

    void processingMessage(const QString &message, bool writeAlsoInConsole = true);

    void processingDone(bool writeAlsoInConsole = true);

    void processingError(bool writeAlsoInConsole = true);

    void processingFinished(bool writeAlsoInConsole = true);

    void toolMessage(const QString &toolName, const QString &message, bool writeAlsoInConsole = true);


private:

    // Pointer to main Window
    eNetEditorMainWindow *eNetEditorMainW;
};

#endif // NETEDITORMESSAGES_H
