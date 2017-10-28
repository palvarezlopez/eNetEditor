#ifndef EDGEDIALOG_H
#define EDGEDIALOG_H

#include "abstractEdgeItemDialog.h"


namespace Ui
{
class edgeItemDialog;
}

class edgeItemDialog : public abstractEdgeItemDialog
{
    Q_OBJECT

public:

    explicit edgeItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~edgeItemDialog();


public slots:

    void resetParameters();

    void updateParameters();

    distributionFunctionItemDialog *getDetectorDistributionDialog() const;

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

    void on_TextStartNode_textChanged();

    void on_TextDestinyNode_textChanged();

    void on_TextNumberOfLanes_textChanged();

    void on_TextLenght_textChanged();

    void on_TextPriority_textChanged();

    void on_TextName_textChanged();

    void on_ButtonFlowMeasure_released();

    void on_ListOfLanes_itemDoubleClicked(QListWidgetItem *item);

    void on_ListOfRoutes_itemDoubleClicked(QListWidgetItem *item);

    void on_ComboBoxSpreadType_currentIndexChanged(int index);

    void on_ComboBoxEdgeType_currentIndexChanged(int index);


private:

    // User Interface
    Ui::edgeItemDialog *ui;

    // Pointer to edge
    edgeItem *e;

    // Dialog with the distribution
    distributionFunctionItemDialog *detectorDistributionD;

    // SUMO Parameter 01 - Type of edge
    edgeTypeItem *tmpType;

    // SUMO Parameter 02 - Priority
    int tmpPriority;

    // Edge Parameter 01 - SpreadType
    edgeSpreadType tmpSpreadType;

    // Edge Parameter 02 - Street Name
    QString tmpStreetName;
};

#endif // edgeDIALOG_H
