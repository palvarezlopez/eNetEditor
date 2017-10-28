#include "turnRatioIntervalDialog.h"
#include "ui_turnRatioIntervalDialog.h"

#include "../../../project/eNetEditorProject.h"

#include "../../../database/eNetEditorDatabase.h"

#include "../../../items/turnRatios/turnRatioIntervalItem.h"
#include "../../../items/nodeItem.h"


turnRatioIntervalDialog::turnRatioIntervalDialog(eNetEditorMainWindow *eNetEditorMainW) : abstractTurnRatioItemDialog(eNetEditorMainW), ui(new Ui::turnRatioIntervalDialog)
{
    // Create UI
    ui->setupUi(this);
}

turnRatioIntervalDialog::~turnRatioIntervalDialog()
{
    // Delete UI
    delete ui;
}

void turnRatioIntervalDialog::resetParameters()
{
    // Reset parameters
    tmpIntervalBegin = tri->getIntervalBegin();
    tmpIntervalEnd = tri->getIntervalEnd();
}

void turnRatioIntervalDialog::updateParameters()
{
    // Reset QSpinBoxBeginHour Spinbox
    ui->QSpinBoxBeginHour->setValue(tri->getIntervalBeginHour());

    // Reset QSpinBoxBeginMinute Spinbox
    ui->QSpinBoxBeginMinute->setValue(tri->getIntervalBeginMinute());

    // Reset QSpinBoxBeginSecond Spinbox
    ui->QSpinBoxBeginSecond->setValue(tri->getIntervalBeginSecond());

    // Reset QSpinBoxEndHour Spinbox
    ui->QSpinBoxEndHour->setValue(tri->getIntervalEndHour());

    // Reset QSpinBoxEndMinute Spinbox
    ui->QSpinBoxEndMinute->setValue(tri->getIntervalEndMinute());

    // Reset QSpinBoxEndSecond Spinbox
    ui->QSpinBoxEndSecond->setValue(tri->getIntervalEndSecond());

    // If end hour is 24 Hours
    if(tri->getIntervalEndHour() == 24)
    {
        // Block QSpinBox endMinute and endSecond
        ui->QSpinBoxEndMinute->setSingleStep(0);
        ui->QSpinBoxEndSecond->setSingleStep(0);
    }
    else
    {
        // Unblock QSpinBox endMinute and endSecond
        ui->QSpinBoxEndMinute->setSingleStep(1);
        ui->QSpinBoxEndSecond->setSingleStep(1);
    }
}

void turnRatioIntervalDialog::openItemDialog(eNetEditorItem *item)
{
    // Set pointer to turnRatioIntervalItem
    tri = dynamic_cast<turnRatioIntervalItem *>(item);

    // If item is a Node
    if(tri)
    {
        // Reset parameters
        resetParameters();

        // Update parameters in all QWidgets;
        updateParameters();

        // Show Dialog
        show();
    }
}

void turnRatioIntervalDialog::on_ButtonAccept_released()
{
    // If intervals is valid
    if(tri->getProject()->isIntervalValid(tmpIntervalBegin, tmpIntervalEnd, tri) == true)
    {
        // Set Time Begin
        tri->setIntervalBegin(tmpIntervalBegin);

        // Set Time Begin
        tri->setIntervalEnd(tmpIntervalEnd);

        // Emit eNetEditorItemDialogCloseAccepted
        emit dialogClosed(eNetEditorItemDialogCloseAccepted);

        // Close Dialog
        close();
    }
    else
    {
        qDebug() << "SHOW ERROR DIALOG";
    }
}

void turnRatioIntervalDialog::on_ButtonCancel_released()
{
    // Emit eNetEditorItemDialogCloseAccepted
    emit dialogClosed(eNetEditorItemDialogCloseCanceled);

    // Close Dialog
    close();
}

void turnRatioIntervalDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters in all QWidgets;
    updateParameters();
}

void turnRatioIntervalDialog::on_QSpinBoxBeginHour_valueChanged(int arg1)
{
    tmpIntervalBegin = ((arg1 * 3600) + (ui->QSpinBoxBeginMinute->value() * 60) + ui->QSpinBoxBeginSecond->value());
}

void turnRatioIntervalDialog::on_QSpinBoxBeginMinute_valueChanged(int arg1)
{
    tmpIntervalBegin = ((ui->QSpinBoxBeginHour->value() * 3600) + (arg1 * 60) + ui->QSpinBoxBeginSecond->value());
}

void turnRatioIntervalDialog::on_QSpinBoxBeginSecond_valueChanged(int arg1)
{
    tmpIntervalBegin = ((ui->QSpinBoxBeginHour->value() * 3600) + (ui->QSpinBoxBeginMinute->value() * 60) + arg1);
}

void turnRatioIntervalDialog::on_QSpinBoxEndHour_valueChanged(int arg1)
{
    // If new value is 24
    if(arg1 == 24)
    {
        // Set manually tmpIntervalEnd to maximum
        tmpIntervalEnd = 86400;

        // Reset QSpinBox endMinute and endSecond
        ui->QSpinBoxEndMinute->setValue(0);
        ui->QSpinBoxEndSecond->setValue(0);

        // Block QSpinBox endMinute and endSecond
        ui->QSpinBoxEndMinute->setSingleStep(0);
        ui->QSpinBoxEndSecond->setSingleStep(0);
    }
    else
    {
        // Calculate interval End
        tmpIntervalEnd = ((arg1 * 3600) + (ui->QSpinBoxEndMinute->value() * 60) + ui->QSpinBoxEndSecond->value());

        // Unblock QSpinBox endMinute and endSecond
        ui->QSpinBoxEndMinute->setSingleStep(1);
        ui->QSpinBoxEndSecond->setSingleStep(1);
    }
}

void turnRatioIntervalDialog::on_QSpinBoxEndMinute_valueChanged(int arg1)
{
    tmpIntervalEnd = ((ui->QSpinBoxEndHour->value() * 3600) + (arg1 * 60) + ui->QSpinBoxEndSecond->value());
}

void turnRatioIntervalDialog::on_QSpinBoxEndSecond_valueChanged(int arg1)
{
    tmpIntervalEnd = ((ui->QSpinBoxEndHour->value() * 3600) + (ui->QSpinBoxEndMinute->value() * 60) + arg1);
}
