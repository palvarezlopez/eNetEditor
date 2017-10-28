#ifndef ENETEDITORABOUTDIALOG_H
#define ENETEDITORABOUTDIALOG_H

#include "../eNetEditorDialog.h"


namespace Ui
{
class eNetEditorAboutDialog;
}

class eNetEditorAboutDialog : public eNetEditorDialog
{
    Q_OBJECT

public:

    explicit eNetEditorAboutDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~eNetEditorAboutDialog();


private slots:

    void on_ButtonAccept_released();


private:

    // UI
    Ui::eNetEditorAboutDialog *ui;
};

#endif // ENETEDITORABOUTDIALOG_H
