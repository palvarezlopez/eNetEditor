#ifndef SCALAPROJECTDIALOG_H
#define SCALAPROJECTDIALOG_H

#include "abstractProjectDialog.h"


namespace Ui
{
class scalaProjectDialog;
}

class scalaDialog : public abstractProjectDialog
{
    Q_OBJECT

public:

    explicit scalaDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~scalaDialog();


public slots:

    void resetParameters();

    void updateParameters();

    void openDialog(eNetEditorProject *newPrj);


private slots:

    void on_ButtonAccept_released();

    void on_ButtonCancel_released();

    void on_ButtonReset_released();

    void on_SliderScale_sliderMoved(int position);


private:

    // GUI
    Ui::scalaProjectDialog *ui;

    // Pointer to project
    eNetEditorProject *prj;

    // Temporal Scale
    openStreetMapPixelMeter tmpScale;
};

#endif // SCALAPROJECTDIALOG_H
