#include "eNetEditorImportNetDialog.h"
#include "ui_eNetEditorImportNetDialog.h"

eNetEditorImportNetDialog::eNetEditorImportNetDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorDialog(eNetEditorMainW), ui(new Ui::eNetEditorImportNetDialog)
{
    // Create UI
    ui->setupUi(this);
}

eNetEditorImportNetDialog::~eNetEditorImportNetDialog()
{
    delete ui;
}
