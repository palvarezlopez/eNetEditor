#ifndef FLOWMEASUREITEMDIALOG_H
#define FLOWMEASUREITEMDIALOG_H

#include "eNetEditorItemDialog.h"


namespace Ui
{
class flowMeasureItemDialog;
}

class flowMeasureItemDialog : public eNetEditorItemDialog
{
    Q_OBJECT

public:

    explicit flowMeasureItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~flowMeasureItemDialog();


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

    void on_TextID_textChanged();

    void on_TextDetector_textChanged();

    void on_TextTime_textChanged();

    void on_TextQPKW_textChanged();

    void on_TextVPKW_textChanged();

    void on_TextQLKW_textChanged();

    void on_TextVLKW_textChanged();



private:

    // UI
    Ui::flowMeasureItemDialog *ui;

    // Pointer to flowMeasureItem
    flowMeasureItem *fm;
};

#endif // FLOWMEASUREITEMDIALOG_H
