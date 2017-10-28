#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include "eNetEditorItemDialog.h"


namespace Ui
{
class connectionItemDialog;
}

class connectionItemDialog : public eNetEditorItemDialog
{
    Q_OBJECT

public:

    explicit connectionItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~connectionItemDialog();


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

    void on_ButtonEditTLStates_released();


private:

    // Dialog UI
    Ui::connectionItemDialog *ui;

    // Pointer to connection
    connectionItem *c;

    // Temporal variable pass
    bool tmpPass;

    // Temporal vector of states
    QVector<char> vectorOfStates;
};

#endif // CONNECTIONDIALOG_H
