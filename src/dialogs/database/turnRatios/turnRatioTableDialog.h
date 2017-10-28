#ifndef TURNPROBABILITIESTABLEDIALOG_H
#define TURNPROBABILITIESTABLEDIALOG_H

#include "../eNetEditorTableDialog.h"


namespace Ui
{
class turnRatioTableDialog;
}

class turnRatioTableDialog : public eNetEditorTableDialog
{
    Q_OBJECT

public:

    explicit turnRatioTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~turnRatioTableDialog();

    turnRatioItemDialog *getTurnRatioItemDialog();


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    // Interface
    Ui::turnRatioTableDialog *ui;

    // Turn Ratio Interval Item Dialog
    turnRatioItemDialog *turnRatioItemD;

    //
    turnRatioTable *turnRatioT;
};

#endif // TURNPROBABILITIESTABLEDIALOG_H
