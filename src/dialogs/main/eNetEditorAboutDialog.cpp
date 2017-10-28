#include "eNetEditorAboutDialog.h"
#include "ui_eNetEditorAboutDialog.h"

eNetEditorAboutDialog::eNetEditorAboutDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorDialog(eNetEditorMainW), ui(new Ui::eNetEditorAboutDialog)
{
    // Create UI
    ui->setupUi(this);
}

eNetEditorAboutDialog::~eNetEditorAboutDialog()
{
    // Delete UI
    delete ui;
}

void eNetEditorAboutDialog::on_ButtonAccept_released()
{
    // Close Dialog
    close();
}
