#ifndef CHARGINGSTATIONTABLEDIALOG_H
#define CHARGINGSTATIONTABLEDIALOG_H

#include "../eNetEditorTableDialog.h"


namespace Ui
{
class chargingStationTableDialog;
}

class chargingStationTableDialog : public eNetEditorTableDialog
{
    Q_OBJECT

public:

    explicit chargingStationTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~chargingStationTableDialog();

    // Función terminada y documentada
    chargingStationItemDialog *getChargingStationItemDialog() const;


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    Ui::chargingStationTableDialog *ui;

    chargingStationItemDialog *chargingStationItemD;

    chargingStationTable *chargingStationT;
};

#endif // CHARGINGSTATIONTABLEDIALOG_H
