#include "eNetEditorLoadingDialog.h"
#include "ui_eNetEditorLoadingDialog.h"

eNetEditorLoadingDialog::eNetEditorLoadingDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorDialog(eNetEditorMainW), ui(new Ui::eNetEditorLoadingDialog)
{
    ui->setupUi(this);
}

eNetEditorLoadingDialog::~eNetEditorLoadingDialog()
{
    delete ui;
}
