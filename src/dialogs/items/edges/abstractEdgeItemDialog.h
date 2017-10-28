#ifndef ABSTRACTEDGEITEMDIALOG_H
#define ABSTRACTEDGEITEMDIALOG_H

#include "../eNetEditorItemDialog.h"


class abstractEdgeItemDialog : public eNetEditorItemDialog
{
public:

    abstractEdgeItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    virtual ~abstractEdgeItemDialog();


private slots:

    virtual void on_ButtonAccept_released() = 0;

    virtual void on_ButtonCancel_released() = 0;

    virtual void on_ButtonReset_released() = 0;

    virtual void on_ButtonCustomParameter1Name_released() = 0;

    virtual void on_ButtonCustomParameter2Name_released() = 0;

    virtual void on_ButtonCustomParameter3Name_released() = 0;

    virtual void on_TextCustomParameter1Value_textChanged() = 0;

    virtual void on_TextCustomParameter2Value_textChanged() = 0;

    virtual void on_TextCustomParameter3Value_textChanged() = 0;

    virtual void on_TextStartNode_textChanged() = 0;

    virtual void on_TextDestinyNode_textChanged() = 0;

    virtual void on_TextNumberOfLanes_textChanged() = 0;

    virtual void on_TextLenght_textChanged() = 0;

    virtual void on_TextPriority_textChanged() = 0;

    virtual void on_TextName_textChanged() = 0;
};

#endif // ENETEDITOREDGEITEMDIALOG_H
