#ifndef ENETEDITORLOADINGDIALOG_H
#define ENETEDITORLOADINGDIALOG_H

#include "../eNetEditorDialog.h"


namespace Ui
{
class eNetEditorLoadingDialog;
}

class eNetEditorLoadingDialog : public eNetEditorDialog
{
    Q_OBJECT

public:

    explicit eNetEditorLoadingDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~eNetEditorLoadingDialog();


private:

    Ui::eNetEditorLoadingDialog *ui;
};

#endif // ENETEDITORLOADINGDIALOG_H
