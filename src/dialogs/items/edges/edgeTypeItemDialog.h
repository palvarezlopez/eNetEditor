#ifndef EDGETYPEITEMDIALOG_H
#define EDGETYPEITEMDIALOG_H

#include "abstractEdgeItemDialog.h"


namespace Ui
{
class edgeTypeItemDialog;
}

class edgeTypeItemDialog : public abstractEdgeItemDialog
{
    Q_OBJECT

public:

    explicit edgeTypeItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~edgeTypeItemDialog();


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

    void on_TextStartNode_textChanged();

    void on_TextDestinyNode_textChanged();

    void on_TextNumberOfLanes_textChanged();

    void on_TextLenght_textChanged();

    void on_TextPriority_textChanged();

    void on_TextName_textChanged();

private:

    Ui::edgeTypeItemDialog *ui;

    edgeTypeItem *et;
};



#endif // EDGETYPEITEMDIALOG_H
