#include "eNetEditorDialog.h"

#include "main/eNetEditorMainWindow.h"


eNetEditorDialog::eNetEditorDialog(eNetEditorMainWindow *neweNetEditorMainW) : QDialog(neweNetEditorMainW), eNetEditor()
{
    // Set pointer to main window
    eNetEditorMainW = neweNetEditorMainW;
}

eNetEditorDialog::~eNetEditorDialog()
{
    // Nothing to remove
}

eNetEditorMainWindow *eNetEditorDialog::geteNetEditorMainWindow()
{
    return eNetEditorMainW;
}

