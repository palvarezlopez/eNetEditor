#include "eNetEditorProjectDialog.h"
#include "ui_eNetEditorProjectDialog.h"

// Main Window
#include "../main/eNetEditorMainWindow.h"

// Turn ratio interval table dialog
#include "../database/turnRatios/turnRatioIntervalTableDialog.h"

// Turn ratio interval dialog
#include "../items/turnRatios/turnRatioIntervalDialog.h"

// Project
#include "../../project/eNetEditorProject.h"

// Database
#include "../../database/eNetEditorDatabase.h"

// Table
#include "../../database/turnRatios/turnRatioIntervalTable.h"

// Turn ratio interval item
#include "../../items/turnRatios/turnRatioIntervalItem.h"


eNetEditorProjectDialog::eNetEditorProjectDialog(eNetEditorMainWindow *eNetEditorMainW) : abstractProjectDialog(eNetEditorMainW), ui(new Ui::eNetEditorProjectDialog)
{
    // Create UI
    ui->setupUi(this);

    // By default pointer to turn Ratio Interval is nULL
    tri = NULL;
}

eNetEditorProjectDialog::~eNetEditorProjectDialog()
{
    // Delete UI
    delete ui;
}

void eNetEditorProjectDialog::openDialog(eNetEditorProject *newProject)
{
    // If project is valid
    if(newProject != NULL)
    {
        // Link project
        setProject(newProject);

        // Reset parameters
        resetParameters();

        // Update parameters in all dialogs
        updateParameters();

        //Show dialog
        show();
    }
}

void eNetEditorProjectDialog::resetParameters()
{
    // Set temporal ProjectName
    tmpProjectName = getProject()->getProjectName();

    // Set temporal Path of the project
    tmpProjectPath = getProject()->getProjectPath();

    // Set temporal Path of the image
    tmpImagePath = getProject()->getImagePath();

    // Set temporal Scale
    tmpScaleMap = getProject()->getScaleMap();

    // Set temporal Start of the simulation
    tmpTimeStartHour = getProject()->getTimeBegin() / 3600;
    tmpTimeStartMinute = (getProject()->getTimeBegin() - (tmpTimeStartHour * 3600)) / 60;
    tmpTimeStartSecond = getProject()->getTimeBegin() - (tmpTimeStartHour * 3600) - (tmpTimeStartMinute * 60);

    // Set temporal End of the simulation
    tmpTimeEndHour = getProject()->getTimeEnd() / 3600;
    tmpTimeEndMinute = (getProject()->getTimeEnd() - (tmpTimeEndHour * 3600)) / 60;
    tmpTimeEndSecond = getProject()->getTimeEnd() - (tmpTimeEndHour * 3600) - (tmpTimeEndMinute * 60);
}

void eNetEditorProjectDialog::updateParameters()
{
    // Set temporal ProjectName
    ui->TextProjectName->setText(tmpProjectName);
    ui->TextProjectName->setAlignment(Qt::AlignCenter);

    // Set temporal Path of the project
    ui->TextPath->setText(tmpProjectPath);
    ui->TextPath->setAlignment(Qt::AlignLeft);

    // Set temporal Path of the image
    ui->TextImagePath->setText(tmpImagePath);
    ui->TextImagePath->setAlignment(Qt::AlignLeft);

    // Set temporal Scale
    ///ui->TextScale->setText(QString::number(tmpScaleMap));
    ///ui->TextScale->setAlignment(Qt::AlignLeft);

    // Set temporal Start of the simulation
    ui->QSpinBoxBeginHour->setValue(tmpTimeStartHour);
    ui->QSpinBoxBeginMinute->setValue(tmpTimeStartMinute);

    // Set temporal Start of the simulation
    ui->QSpinBoxEndHour->setValue(tmpTimeEndHour);
    ui->QSpinBoxEndMinute->setValue(tmpTimeEndMinute);

    /** Falta descripcion **/

    // Fill listOfTurnRatios
    fillListOfTurnRatios();
}

void eNetEditorProjectDialog::afterTurnRatioIntervalDialogClosed(eNetEditorItemDialogCloseType closeCode)
{
    // If close code was eNetEditorItemDialogCloseAccepted
    if(closeCode == eNetEditorItemDialogCloseAccepted)
    {
        // fill list of TurnRatios
        fillListOfTurnRatios();

        // Set pointer tri to null
        tri = NULL;
    }
    else
    {
        // If previously a new Turn Ratio Interval was created
        if(tri != NULL)
        {
            // Delete created Turn Ratio Interval
            delete tri;

            // Set pointer to NULL
            tri = NULL;
        }

    }
}

void eNetEditorProjectDialog::on_TextProjectName_textChanged()
{

}

void eNetEditorProjectDialog::on_TextPath_textChanged()
{

}

void eNetEditorProjectDialog::on_TextImagePath_textChanged()
{

}

void eNetEditorProjectDialog::on_TextDescription_textChanged()
{

}

void eNetEditorProjectDialog::on_ButtonReset_released()
{
    // Reste all parameters
    resetParameters();

    // Update all parameters
    updateParameters();
}

void eNetEditorProjectDialog::on_ButtonAccept_released()
{
    // Set new StartTime
    getProject()->setTimeBegin((tmpTimeStartHour * 3600) + (tmpTimeStartMinute * 60) + tmpTimeStartSecond);

    // Set new EndTime
    getProject()->setTimeEnd((tmpTimeEndHour * 3600) + (tmpTimeEndMinute * 60) + tmpTimeEndSecond);

    // Close dialog
    close();
}

void eNetEditorProjectDialog::on_ButtonCancel_released()
{
    // Close dialog
    close();
}

void eNetEditorProjectDialog::on_QSpinBoxBeginHour_valueChanged(int arg1)
{
    // Set tmpTimeStartHour
    tmpTimeStartHour = arg1;

    // If simulation start at 24 Hours
    if(tmpTimeStartHour == 24)
    {
        // Set QSpinBoxBeginMinute to 0
        ui->QSpinBoxBeginMinute->setValue(0);

        // Set QSpinBoxBeginSecond to 0
        ui->QSpinBoxBeginSecond->setValue(0);

        // Block QSpinBoxBeginMinute
        ui->QSpinBoxBeginMinute->setSingleStep(0);

        // Block QSpinBoxBeginSecond
        ui->QSpinBoxBeginSecond->setSingleStep(0);
    }
    else
    {
        // Unblck QSpinBoxBeginMinute
        ui->QSpinBoxBeginMinute->setSingleStep(1);

        // Block QSpinBoxBeginSecond
        ui->QSpinBoxBeginSecond->setSingleStep(1);
    }
}

void eNetEditorProjectDialog::on_QSpinBoxBeginMinute_valueChanged(int arg1)
{
    // Set tmpTimeStartHour
    tmpTimeStartMinute = arg1;
}

void eNetEditorProjectDialog::on_QSpinBoxBeginSecond_valueChanged(int arg1)
{
    // Set tmpTimeStartSecond
    tmpTimeStartSecond = arg1;
}

void eNetEditorProjectDialog::on_QSpinBoxEndHour_valueChanged(int arg1)
{
    // Set tmpTimeEndHour
    tmpTimeEndHour = arg1;

    // If simulation start at 24 Hours
    if(tmpTimeEndHour == 24)
    {
        // Set QSpinBoxEndMinute to 0
        ui->QSpinBoxEndMinute->setValue(0);

        // Set QSpinBoxEndSecond to 0
        ui->QSpinBoxEndSecond->setValue(0);

        // Block QSpinBoxEndMinute
        ui->QSpinBoxEndMinute->setSingleStep(0);

        // Block QSpinBoxEndSecond
        ui->QSpinBoxEndSecond->setSingleStep(0);
    }
    else
    {
        // Unblck QSpinBoxEndMinute
        ui->QSpinBoxEndMinute->setSingleStep(1);

        // Block QSpinBoxEndSecond
        ui->QSpinBoxEndSecond->setSingleStep(1);
    }
}

void eNetEditorProjectDialog::on_QSpinBoxEndMinute_valueChanged(int arg1)
{
    // Set tmpTimeEndMinute
    tmpTimeEndMinute = arg1;
}

void eNetEditorProjectDialog::on_QSpinBoxEndSecond_valueChanged(int arg1)
{
    // Set tmpTimeEndSecond
    tmpTimeEndSecond = arg1;
}

void eNetEditorProjectDialog::on_ButtonSearchPath_released()
{

}

void eNetEditorProjectDialog::on_ButtonSearchMap_released()
{

}

void eNetEditorProjectDialog::on_horizontalSlider_sliderMoved(int position)
{

}

void eNetEditorProjectDialog::on_ButtonAddInterval_released()
{
    // Create new Turn ratio interval
    turnRatioIntervalItem *tri = new turnRatioIntervalItem(getProject()->getDatabase());

    // Open dialog with created turn Ratio
    geteNetEditorMainWindow()->getTurnRatioIntervalTableDialog()->getTurnRatioIntervalDialog()->openItemDialog(tri);
}

void eNetEditorProjectDialog::on_ListTurnRatioIntervals_itemDoubleClicked(QListWidgetItem *item)
{

}

void eNetEditorProjectDialog::fillListOfTurnRatios()
{
    // Clear list of Turn Ratios
    ui->ListTurnRatioIntervals->clear();

    // Iterate over turn Ratios of dataabse
    for(QList<eNetEditorItem *>::iterator i = getProject()->getDatabase()->getTurnRatioIntervalTable()->iteratorTableBegin(); i != getProject()->getDatabase()->getTurnRatioIntervalTable()->iteratorTableEnd(); i++)
    {
        // Add ID
        ui->ListTurnRatioIntervals->addItem(new QListWidgetItem((*i)->getItemId()));
    }
}
