#ifndef BUSSTOPDIALOG_H
#define BUSSTOPDIALOG_H

#include "../eNetEditorItemDialog.h"


namespace Ui
{
class busStopItemDialog;
}

class busStopItemDialog : public eNetEditorItemDialog
{
    Q_OBJECT

public:

    explicit busStopItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~busStopItemDialog();


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

    void on_TextStartPosition_textChanged();

    void on_TextEndPosition_textChanged();

    void on_TextLines_textChanged();


private:

    // UI Dialog
    Ui::busStopItemDialog *ui;

    // Pointer to Bus Station
    busStopItem *bs;

    // Temporal variable StartPosition
    qreal tmpStartPosition;

    // Temporal variable EndPosition
    qreal tmpEndPosition;

    // Temporal variable tmpLines
    QString tmpLines;
};

#endif // BUSSTOPDIALOG_H
