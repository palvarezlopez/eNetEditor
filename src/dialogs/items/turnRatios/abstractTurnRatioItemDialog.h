#ifndef ABSTRACTTURNRATIOITEMDIALOG_H
#define ABSTRACTTURNRATIOITEMDIALOG_H

#include "../eNetEditorItemDialog.h"


class abstractTurnRatioItemDialog : public eNetEditorItemDialog
{
public:

    abstractTurnRatioItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    virtual ~abstractTurnRatioItemDialog();


public slots:

    virtual void resetParameters() = 0;

    virtual void updateParameters() = 0;

    virtual void openItemDialog(eNetEditorItem *item) = 0;


signals:

    void dialogClosed(eNetEditorItemDialogCloseType);


private slots:

    virtual void on_ButtonAccept_released() = 0;

    virtual void on_ButtonCancel_released() = 0;

    virtual void on_ButtonReset_released() = 0;


};

#endif // ABSTRACTTURNRATIOITEMDIALOG_H
