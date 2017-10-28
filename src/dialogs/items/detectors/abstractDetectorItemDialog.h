#ifndef DETECTORDIALOG_H
#define DETECTORDIALOG_H

#include "../eNetEditorItemDialog.h"


class abstractDetectorItemDialog : public eNetEditorItemDialog
{
    Q_OBJECT

public:

    abstractDetectorItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    virtual ~abstractDetectorItemDialog();


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

    virtual void on_ButtonCustomParameter1Name_released() = 0;

    virtual void on_ButtonCustomParameter2Name_released() = 0;

    virtual void on_ButtonCustomParameter3Name_released() = 0;

    virtual void on_TextCustomParameter1Value_textChanged() = 0;

    virtual void on_TextCustomParameter2Value_textChanged() = 0;

    virtual void on_TextCustomParameter3Value_textChanged() = 0;
};

#endif // DETECTORDIALOG_H
