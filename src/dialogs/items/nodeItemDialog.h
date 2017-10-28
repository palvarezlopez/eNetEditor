#ifndef NODEDIALOG_H
#define NODEDIALOG_H

#include "eNetEditorItemDialog.h"


namespace Ui
{
class nodeItemDialog;
}

class nodeItemDialog : public eNetEditorItemDialog
{
    Q_OBJECT

public:

    explicit nodeItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~nodeItemDialog();


public slots:

    void resetParameters();

    void updateParameters();

    void openItemDialog(eNetEditorItem *item);


signals:

    void dialogClosed(eNetEditorItemDialogCloseType);


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

    void on_ComboBoxType_currentIndexChanged(int index);

    void on_CheckBoxBlocked_clicked();

    void on_ButtonEditTurnRatios_released();

    void on_ButtonEditTrafficLight_released();

    void on_ListIncomingEdges_itemDoubleClicked(QListWidgetItem *item);

    void on_ListOutcomingEdges_itemDoubleClicked(QListWidgetItem *item);

    void on_ListConnections_itemDoubleClicked(QListWidgetItem *item);

    void on_ListTurnRatios_itemDoubleClicked(QListWidgetItem *item);

private:

    // Interface
    Ui::nodeItemDialog *ui;

    // Pointer to node
    nodeItem *n;

    // Node parameter 01 - posx
    qreal tmpPosx;

    // Node parameter 02 - posy
    qreal tmpPosy;

    // Node parameter 03 - posz
    qreal tmpPosz;

    // Node parameter 04 - type
    nodeItemType tmpType;
};

#endif // NODEDIALOG_H
