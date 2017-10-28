#include "eNetEditor.h"

// Net Editor main Dialog
#include "../dialogs/main/eNetEditorMainWindow.h"

eNetEditor::eNetEditor()
{
    eNetEditorVersion = "1.0";

    eNetEditorRevision = "250";
}

eNetEditor::~eNetEditor()
{
    // Nothing to declare
}

int eNetEditor::execute(const QApplication &application)
{
    // Create eNetEditorMainWindow
    eNetEditorMainWindow mainWindow;

    // Open main windows
    mainWindow.openDialog();

    // Return result of execution
    return application.exec();
}

const QString &eNetEditor::geteNetEditorVersion() const
{
    return eNetEditorVersion;
}

const QString &eNetEditor::geteNetEditorRevision() const
{
    return eNetEditorRevision;
}
