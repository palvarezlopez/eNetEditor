#ifndef VEHICLESTABLEDIALOG_H
#define VEHICLESTABLEDIALOG_H

#include "../eNetEditorTableDialog.h"


namespace Ui
{
class vehicleTableDialog;
}

class vehicleTableDialog : public eNetEditorTableDialog
{
    Q_OBJECT

public:

    explicit vehicleTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~vehicleTableDialog();

    vehicleItemDialog *getVehicleItemDialog();


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    // Interface
    Ui::vehicleTableDialog *ui;

    // vehicle Item Dialog
    vehicleItemDialog *vehicleItemD;

    vehicleTable *vehicleT;
};

#endif // VEHICLESTABLEDIALOG_H
