#ifndef INDUCTIONLOOPSDETECTORE1ITEMDIALOG_H
#define INDUCTIONLOOPSDETECTORE1ITEMDIALOG_H

#include "abstractDetectorItemDialog.h"


namespace Ui
{
class inductionLoopsE1DetectorItemDialog;
}

class inductionLoopsE1DetectorItemDialog : public abstractDetectorItemDialog
{
    Q_OBJECT

public:

    explicit inductionLoopsE1DetectorItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~inductionLoopsE1DetectorItemDialog();


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

    void on_CheckBoxFriendlyPosition_toggled(bool checked);

    void on_CheckBoxSplitByType_toggled(bool checked);


private:

    // UI
    Ui::inductionLoopsE1DetectorItemDialog *ui;

    // Pointer to item
    inductionLoopsE1DetectorItem *E1;

    // Temporal variable filename
    QString tmpFileName;

    // Temporal variable Pos
    qreal tmpPos;

    // Temporal variable frequency
    qreal tmpFrecuency;

    // Temporal variable friendly pos
    bool tmpFriendlyPos;

    // Temporal variable Split By Type
    bool tmpSplitByType;

};

#endif // INDUCTIONLOOPSDETECTORE1ITEMDIALOG_H
