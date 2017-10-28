#ifndef LANEAREADETECTORE2ITEMDIALOG_H
#define LANEAREADETECTORE2ITEMDIALOG_H

#include "abstractDetectorItemDialog.h"


namespace Ui
{
class laneAreaE2DetectorItemDialog;
}

class laneAreaE2DetectorItemDialog : public abstractDetectorItemDialog
{
    Q_OBJECT

public:

    explicit laneAreaE2DetectorItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~laneAreaE2DetectorItemDialog();


signals:

    void dialogClosed(eNetEditorItemDialogCloseType);


public slots:

    void resetParameters();

    void updateParameters();

    void openItemDialog(eNetEditorItem *item);


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

    Ui::laneAreaE2DetectorItemDialog *ui;

    laneAreaE2DetectorItem *E2;

    // Temporal variable filename
    QString tmpFileName;

    // Temporal variable Pos
    qreal tmpPos;
};

#endif // LANEAREADETECTORE2ITEMDIALOG_H
