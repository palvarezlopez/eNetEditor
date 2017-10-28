#include "scalaProjectDialog.h"
#include "ui_scalaProjectDialog.h"

#include "../../configuration/project/eNetEditorProjectConfiguration.h"

#include "../../project/eNetEditorProject.h"

scalaDialog::scalaDialog(eNetEditorMainWindow *eNetEditorMainW) : abstractProjectDialog(eNetEditorMainW), ui(new Ui::scalaProjectDialog)
{
    // Create GUI
    ui->setupUi(this);

    // By default, pointer prj is NULL
    prj = NULL;
}

scalaDialog::~scalaDialog()
{
    // Delete UI
    delete ui;
}

void scalaDialog::resetParameters()
{

}

void scalaDialog::updateParameters()
{

}

void scalaDialog::openDialog(eNetEditorProject *newPrj)
{
    // If pointer to project is valid
    if(newPrj != NULL)
    {
        // link Project
        prj = newPrj;

        // Set temporal scale
        tmpScale = prj->getScaleMap();

        // Set the slider in the apropiate position
        ui->SliderScale->setSliderPosition(tmpScale);

        // Open Dialog
        show();
    }
}

void scalaDialog::on_SliderScale_sliderMoved(int position)
{
    // Adjust temporal scale to position of slider
    tmpScale = static_cast<openStreetMapPixelMeter>(position);
}

void scalaDialog::on_ButtonAccept_released()
{
    // Set new Scale
    prj->setScaleMap(tmpScale);

    // Close Dialog
    close();
}

void scalaDialog::on_ButtonCancel_released()
{
    // Close dialog
    close();
}

void scalaDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters
    updateParameters();
}
