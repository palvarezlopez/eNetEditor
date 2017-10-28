#ifndef ROUTEDIALOG_H
#define ROUTEDIALOG_H

#include "eNetEditorItemDialog.h"


namespace Ui
{
class routeItemDialog;
}

class routeItemDialog : public eNetEditorItemDialog
{
    Q_OBJECT

public:

    explicit routeItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~routeItemDialog();


public slots:

    void resetParameters();

    void updateParameters();

    void openItemDialog(eNetEditorItem *item);

    void afterFlowItemDialogClosed(eNetEditorItemDialogCloseType closeCode);

    void afterVehicleItemDialog(eNetEditorItemDialogCloseType closeCode);


signals:

    void dialogClosed(eNetEditorItemDialogCloseType);


signals:

    void openFlowItemDialog(eNetEditorItem *);

    void openVehicleItemDialog(eNetEditorItem *);


private slots:

    void on_ButtonAccept_released();

    void on_ButtonCancel_released();

    void on_ButtonReset_released();

    void on_ButtonCustomParameter1Name_released();

    void on_ButtonCustomParameter2Name_released();

    void on_ButtonCustomParameter3Name_released();

    void on_TextCustomParameter1Value_textChanged();

    void on_TextCustomParameter2Value_textChanged();

    void on_TextCustomParameter3Value_textChanged();

    void on_ButtonAddVehicle_released();

    void on_ButtonAddFlow_released();

    void on_ListOfFlows_itemDoubleClicked(QListWidgetItem *item);


    void on_TextColor_textChanged();

private:

    // UI
    Ui::routeItemDialog *ui;

    // Pointer to route
    routeItem *r;

    // Pointer to Vehicle
    vehicleItem *v;

    // Pointer to Flow
    flowItem *f;

    // Temporal color
    QString tmpColor;
};

#endif // ROUTEDIALOG_H
