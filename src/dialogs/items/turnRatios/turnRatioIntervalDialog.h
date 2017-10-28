#ifndef TURNRATIONEWINTERVAL_H
#define TURNRATIONEWINTERVAL_H

#include "abstractTurnRatioItemDialog.h"


namespace Ui
{
class turnRatioIntervalDialog;
}

class turnRatioIntervalDialog : public abstractTurnRatioItemDialog
{
    Q_OBJECT

public:

    explicit turnRatioIntervalDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~turnRatioIntervalDialog();


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

    void on_QSpinBoxBeginHour_valueChanged(int arg1);

    void on_QSpinBoxBeginMinute_valueChanged(int arg1);

    void on_QSpinBoxBeginSecond_valueChanged(int arg1);

    void on_QSpinBoxEndHour_valueChanged(int arg1);

    void on_QSpinBoxEndMinute_valueChanged(int arg1);

    void on_QSpinBoxEndSecond_valueChanged(int arg1);


private:

    // UI
    Ui::turnRatioIntervalDialog *ui;

    // Pointer to turnRatioIntervalItem
    turnRatioIntervalItem *tri;

    // temporal begin interval
    int tmpIntervalBegin;
    int tmpIntervalEnd;
};

#endif // TURNRATIONEWINTERVAL_H
