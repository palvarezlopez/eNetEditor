#ifndef ENETEDITORIMPORTNETDIALOG_H
#define ENETEDITORIMPORTNETDIALOG_H

#include "../eNetEditorDialog.h"


namespace Ui
{
class eNetEditorImportNetDialog;
}

class eNetEditorImportNetDialog : public eNetEditorDialog
{
    Q_OBJECT

public:

    explicit eNetEditorImportNetDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~eNetEditorImportNetDialog();


private:

    // UI
    Ui::eNetEditorImportNetDialog *ui;
};

#endif // ENETEDITORIMPORTNETDIALOG_H
