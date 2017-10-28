#ifndef PROHIBITIONDIALOG_H
#define PROHIBITIONDIALOG_H

#include "eNetEditorItemDialog.h"


namespace Ui
{
class prohibitionItemDialog;
}

class prohibitionItemDialog : public eNetEditorItemDialog
{
    Q_OBJECT

public:

    explicit prohibitionItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~prohibitionItemDialog();


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


private:

    // UI
    Ui::prohibitionItemDialog *ui;

    // Pointer to prohibition to edit
    prohibitionItem *p;
};

#endif // PROHIBITIONDIALOG_H
