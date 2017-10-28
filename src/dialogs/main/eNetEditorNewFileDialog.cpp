#include "eNetEditorNewFileDialog.h"
#include "ui_eNetEditorNewFileDialog.h"

#include <QFileDialog>
#include <fstream>
#include <QMessageBox>

// netEditor
#include "eNetEditorMainWindow.h"

// Project
#include "../../project/eNetEditorProject.h"

// Messages
#include "../../main/eNetEditorMessages.h"

// Configuration
#include "../../configuration/main/eNetEditorMainConfiguration.h"
#include "../../configuration/project/eNetEditorProjectConfiguration.h"



eNetEditorNewFileDialog::eNetEditorNewFileDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorDialog(eNetEditorMainW), ui(new Ui::eNetEditorNewFileDialog)
{
    // Set GUI
    ui->setupUi(this);
}

eNetEditorNewFileDialog::~eNetEditorNewFileDialog()
{
    delete ui;
}

void eNetEditorNewFileDialog::openDialog(eNetEditorMainWindow *newMainWindow)
{
    // If the pointer to netEditor is valid
    if(newMainWindow != NULL)
    {
        // Link netEditor
        mainWindow = newMainWindow;

        // Reset Parameters
        resetParameters();

        // Update Parameters
        updateParameters();

        // Show dialog
        show();
    }
}

void eNetEditorNewFileDialog::resetParameters()
{
    // Set default name
    tmpProjectName = mainWindow->geteNetEditorConfiguration()->getProjectConfiguration()->getDefaultProjectName();

    // By default, path route is not selected
    tmpFilePath = "not selected";

    // By default, pathMap is not selected
    tmpPathMap = "not selected";

    // By default, the value of the scale is 0
    tmpScale = static_cast<openStreetMapPixelMeter>(17);

    // Set temporal Start of the simulation
    tmpTimeStartHour = 0;
    tmpTimeStartMinute = 0;
    tmpTimeStartSecond = 0;

    // Set temporal End of the simulation
    tmpTimeEndHour = 24;
    tmpTimeEndMinute = 0;
    tmpTimeEndSecond = 0;
}

void eNetEditorNewFileDialog::updateParameters()
{
    // Set TextProjectName
    ui->TextProjectName->setText(tmpProjectName);

    // Set Textpath
    ui->TextPath->setText(tmpFilePath);

    // Set Map File
    ui->TextMapFile->setText(tmpPathMap);

    // Set Scale
    ui->horizontalSlider->setValue(tmpScale);

    // Set temporal Start of the simulation
    ui->QSpinBoxBeginHour->setValue(0);
    ui->QSpinBoxBeginMinute->setValue(0);
    ui->QSpinBoxBeginSecond->setValue(0);

    // Set temporal End of the simulation
    ui->QSpinBoxEndHour->setValue(24);
    ui->QSpinBoxEndMinute->setValue(0);
    ui->QSpinBoxEndSecond->setValue(0);

    // Block QSpinBoxEndMinute
    ui->QSpinBoxEndMinute->setSingleStep(0);

    // Block QSpinBoxEndSecond
    ui->QSpinBoxEndSecond->setSingleStep(0);
}


void eNetEditorNewFileDialog::on_ButtonCancel_released()
{
    // Close dialog
    close();
}

void eNetEditorNewFileDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters
    updateParameters();
}

void eNetEditorNewFileDialog::on_ButtonAccept_released()
{
    // Create temporal pixmap
    QPixmap tmp;

    // Try to load image of the route
    tmp.load(tmpPathMap);

    // If path route was not selected
    if(tmpFilePath == "not selected")
    {
        // Show error message
        QMessageBox::critical(this, tr("Path"), tr("Directory for the project not specified.\n"), QMessageBox::Ok);
    }
    // If image route was not selected
    else if(tmpPathMap == "not selected")
    {
        // Show error message
        QMessageBox::critical(this, tr("Image not selected"), tr("Image file not specified.\n"), QMessageBox::Ok);
    }
    else if(tmp.isNull())
    {
        // Show error message
        QMessageBox::critical(this, tr("Image"), tr("Image format not valid.\n"), QMessageBox::Ok);
    }
    else
    {
        // Calculate durations
        int durationBegin = (tmpTimeStartHour * 3600) + (tmpTimeStartMinute * 60) + tmpTimeStartSecond;
        int durationEnd = (tmpTimeEndHour * 3600) + (tmpTimeEndMinute * 60) + tmpTimeEndSecond;

        // Create file with the path of new project
        QFile temporalFileProject(tmpFilePath + "/" + tmpProjectName +  mainWindow->geteNetEditorConfiguration()->getProjectConfiguration()->getDefaultProjectExtensionFile());

        // If the file exists
        if (temporalFileProject.exists())
        {
            // Create question message box asking if the existent project has to be overwritted
            QMessageBox messageBox;
            messageBox.setIcon(QMessageBox::Question);
            messageBox.setText("The project " + tmpProjectName + " exist.");
            messageBox.setInformativeText("Do you want to overwrite?");
            messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            messageBox.setDefaultButton(QMessageBox::No);

            // If the answer is yes
            if(messageBox.exec() == QMessageBox::Yes)
            {
                // Create project overwriting the existent project
                mainWindow->createNewProject(tmpProjectName, tmpFilePath, tmpPathMap, durationBegin, durationEnd, tmpScale);

                // Close Dialog
                close();
            }
        }
        // else if file not exist
        else
        {
            // Create project
            mainWindow->createNewProject(tmpProjectName, tmpFilePath, tmpPathMap, durationBegin, durationEnd, tmpScale);

            // Close Dialog
            close();
        }
    }
}

void eNetEditorNewFileDialog::on_ButtonSearchPath_released()
{
    // Get route of the directory
    QString newPathRoute = QFileDialog::getExistingDirectory
                           (
                               this,
                               "Project directory",
                               mainWindow->geteNetEditorConfiguration()->getProjectConfiguration()->getDefaultProjectFolder()
                           );

    // If directory is valid
    if(!newPathRoute.isEmpty())
    {
        tmpFilePath = newPathRoute;
        ui->TextPath->setText(tmpFilePath + "/" + tmpProjectName + mainWindow->geteNetEditorConfiguration()->getProjectConfiguration()->getDefaultProjectExtensionFile());
    }
}

void eNetEditorNewFileDialog::on_ButtonSearchMap_released()
{
    // Open search Dialog
    QString newpathMap = QFileDialog::getOpenFileName
                         (
                             this,
                             "Open Image File",
                             mainWindow->geteNetEditorConfiguration()->getProjectConfiguration()->getDefaultProjectFolder(),
                             tr("JPEG (*.jpg *.jpeg);;PNG (*.png);;BMP (*.bmp);;All files (*.*)" )
                         );

    // If some file was selected
    if(!newpathMap.isEmpty())
    {
        // Set the path
        tmpPathMap = newpathMap;
        ui->TextMapFile->setText(tmpPathMap);
    }
}

void eNetEditorNewFileDialog::on_TextProjectName_textChanged()
{
    // ATENCION: SOLO PERMITIR CARACTERES VALIDOS, BORRAR COSAS COMO eñes ,\n y demás.

    tmpProjectName = ui->TextProjectName->toPlainText();

    if(tmpFilePath != "not selected")
    {
        ui->TextPath->setText(tmpFilePath + "/" + tmpProjectName + mainWindow->geteNetEditorConfiguration()->getProjectConfiguration()->getDefaultProjectExtensionFile());
    }
}


void eNetEditorNewFileDialog::on_horizontalSlider_sliderMoved(int position)
{
    // Set new Scale
    tmpScale = static_cast<openStreetMapPixelMeter>(position);

    // Update Label Scale
    ui->LabelScale->setText("scale: " + QString::number(position));
    ui->LabelScale->setAlignment(Qt::AlignRight | Qt::AlignHCenter);
}

void eNetEditorNewFileDialog::on_QSpinBoxBeginHour_valueChanged(int arg1)
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

void eNetEditorNewFileDialog::on_QSpinBoxBeginMinute_valueChanged(int arg1)
{
    // Set tmpTimeStartHour
    tmpTimeStartMinute = arg1;
}

void eNetEditorNewFileDialog::on_QSpinBoxBeginSecond_valueChanged(int arg1)
{
    // Set tmpTimeStartSecond
    tmpTimeStartSecond = arg1;
}

void eNetEditorNewFileDialog::on_QSpinBoxEndHour_valueChanged(int arg1)
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

void eNetEditorNewFileDialog::on_QSpinBoxEndMinute_valueChanged(int arg1)
{
    // Set tmpTimeEndMinute
    tmpTimeEndMinute = arg1;
}

void eNetEditorNewFileDialog::on_QSpinBoxEndSecond_valueChanged(int arg1)
{
    // Set tmpTimeEndSecond
    tmpTimeEndSecond = arg1;
}
