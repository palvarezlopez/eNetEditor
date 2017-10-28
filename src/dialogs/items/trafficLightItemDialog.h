#ifndef TRAFFICLIGHTDIALOG_H
#define TRAFFICLIGHTDIALOG_H

#include "eNetEditorItemDialog.h"


namespace Ui
{
class trafficLightItemDialog;
}

class trafficLightItemDialog : public eNetEditorItemDialog
{
    Q_OBJECT

public:

    explicit trafficLightItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~trafficLightItemDialog();


public slots:

    void resetParameters();

    void updateParameters();

    void openItemDialog(eNetEditorItem *item);


signals:

    void dialogClosed(eNetEditorItemDialogCloseType);


private slots:

    void makeTable();

    void on_ButtonAccept_released();

    void on_ButtonCancel_released();

    void on_ButtonReset_released();

    void on_ButtonCustomParameter1Name_released();

    void on_ButtonCustomParameter2Name_released();

    void on_ButtonCustomParameter3Name_released();

    void on_TextCustomParameter1Value_textChanged();

    void on_TextCustomParameter2Value_textChanged();

    void on_TextCustomParameter3Value_textChanged();

    void on_TableTrafficLights_itemDoubleClicked(QTableWidgetItem *item);

    void on_TableTrafficLights_itemChanged(QTableWidgetItem *item);


private:

    // UI
    Ui::trafficLightItemDialog *ui;

    // Pointer to traffic light to edit
    trafficLightItem *tl;
};

#endif // TRAFFICLIGHTDIALOG_H
