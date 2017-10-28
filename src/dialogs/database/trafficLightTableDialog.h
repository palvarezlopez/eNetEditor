#ifndef TRAFFICLIGHTTABLEDIALOG_H
#define TRAFFICLIGHTTABLEDIALOG_H

#include "eNetEditorTableDialog.h"


namespace Ui
{
class trafficLightTableDialog;
}

class trafficLightTableDialog : public eNetEditorTableDialog
{
    Q_OBJECT

public:

    explicit trafficLightTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~trafficLightTableDialog();

    // Función terminada y documentada
    trafficLightItemDialog *getTrafficLightItemDialog() const;


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    // Interface
    Ui::trafficLightTableDialog *ui;

    // Traffic Light Item Dialog
    trafficLightItemDialog *trafficLightItemD;

    trafficLightTable *trafficLightT;
};

#endif // TRAFFICLIGHTDIALOG_H
