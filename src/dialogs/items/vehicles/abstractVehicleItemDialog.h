#ifndef ABSTRACTVEHICLEITEMDIALOG_H
#define ABSTRACTVEHICLEITEMDIALOG_H

#include "../eNetEditorItemDialog.h"


class abstractVehicleItemDialog : public eNetEditorItemDialog
{
public:

    abstractVehicleItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    virtual ~abstractVehicleItemDialog();


public slots:

    virtual void resetParameters() = 0;

    virtual void updateParameters() = 0;

    virtual void openItemDialog(eNetEditorItem *item) = 0;


signals:

    void dialogClosed(eNetEditorItemDialogCloseType);


private slots:

    virtual void on_ComboBoxVType_currentTextChanged(const QString &arg1) = 0;

    virtual void on_TextRoute_textChanged() = 0;

    virtual void on_TextLine_textChanged() = 0;

    virtual void on_TextColor_textChanged() = 0;

    virtual void on_TextPersonNumber_textChanged() = 0;

    virtual void on_TextContainerNumber_textChanged() = 0;

    virtual void on_ComboBoxDepartLane_currentTextChanged(const QString &arg1) = 0;

    virtual void on_ComboBoxDepartPos_currentTextChanged(const QString &arg1) = 0;

    virtual void on_ComboBoxDepartSpeed_currentTextChanged(const QString &arg1) = 0;

    virtual void on_ComboBoxArrivalLane_currentTextChanged(const QString &arg1) = 0;

    virtual void on_ComboBoxArrivalPos_currentTextChanged(const QString &arg1) = 0;

    virtual void on_ComboBoxArrivalSpeed_currentTextChanged(const QString &arg1) = 0;

    virtual void on_TextDepartLane_textChanged() = 0;

    virtual void on_TextDepartPos_textChanged() = 0;

    virtual void on_TextDepartSpeed_textChanged() = 0;

    virtual void on_TextArrivalLane_textChanged() = 0;

    virtual void on_TextArrivalPos_textChanged() = 0;

    virtual void on_TextArrivalSpeed_textChanged() = 0;

};

#endif // ENETEDITORVEHICLEITEMDIALOG_H


