#ifndef VEHICLETYPETABLEDIALOG_H
#define VEHICLETYPETABLEDIALOG_H

#include "eNetEditorTableDialog.h"


namespace Ui
{
class vehicleTypeTableDialog;
}

class vehicleTypeTableDialog : public eNetEditorTableDialog
{
    Q_OBJECT

public:

    explicit vehicleTypeTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~vehicleTypeTableDialog();

    // Función terminada y documentada
    vehicleTypeItemDialog *getVehicleTypeItemDialog() const;


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);

private:

    // Interface
    Ui::vehicleTypeTableDialog *ui;

    // Vehicle Type Item Dialog
    vehicleTypeItemDialog *vehicleTypeItemD;

    //
    vehicleTypeTable *vehicleTypeT;

    // Pointer to new vehicle
    vehicleTypeItem *vt;
};

#endif // VEHICLETYPETABLEDIALOG_H
