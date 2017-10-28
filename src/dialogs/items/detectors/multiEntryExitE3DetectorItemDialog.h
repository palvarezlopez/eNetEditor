#ifndef MULTIENTRYEXITDETECTORSE3ITEMDIALOG_H
#define MULTIENTRYEXITDETECTORSE3ITEMDIALOG_H

#include "abstractDetectorItemDialog.h"


namespace Ui
{
class multiEntryExitE3DetectorItemDialog;
}

class multiEntryExitE3DetectorItemDialog : public abstractDetectorItemDialog
{
    Q_OBJECT

public:

    explicit multiEntryExitE3DetectorItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~multiEntryExitE3DetectorItemDialog();


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

    void on_TextPosition_textChanged();

    void on_TextFrequency_textChanged();

    void on_TextFilename_textChanged();


private:

    Ui::multiEntryExitE3DetectorItemDialog *ui;

    multiEntryExitE3DetectorItem *E3;

    // Temporal variable filename
    QString tmpFileName;

    // Temporal variable Pos
    qreal tmpPos;
};

#endif // MULTIENTRYEXITDETECTORSE3ITEMDIALOG_H
