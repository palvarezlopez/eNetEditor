#include "eNetEditorProcessingDialog.h"
#include "ui_eNetEditorProcessingDialog.h"

eNetEditorProcessingDialog::eNetEditorProcessingDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorDialog(eNetEditorMainW), ui(new Ui::eNetEditorProcessingDialog)
{
    // Create UI
    ui->setupUi(this);
}

eNetEditorProcessingDialog::~eNetEditorProcessingDialog()
{
    // Delete UI
    delete ui;
}

void eNetEditorProcessingDialog::openDialog()
{
    // Simply open dialog
    show();
}

void eNetEditorProcessingDialog::processingStart(const QString &newProcessName)
{
    // If the previous process was not finished
    if(processName != "")
    {
        // If all container were sucessfully exported, show a information message
        QMessageBox::warning(0, ("Processing"), ("Warning: The process " + processName + "isn't finished.\n"), QMessageBox::Ok);
    }

    // Open Dialog (If wasn't already opened)
    if(isVisible() == false)
    {
        openDialog();
    }

    // Save processName
    processName = newProcessName;

    // Show message
    ui->TextInformation->insertPlainText("process " + newProcessName + " started\n");

    // Lock button
    setButtonBlocked(true);
}

void eNetEditorProcessingDialog::processingMessage(const QString &message)
{
    // write message
    ui->TextInformation->insertPlainText("processing " + message + "... ");
}

void eNetEditorProcessingDialog::processingDone()
{
    // Write done message
    ui->TextInformation->insertPlainText("done.\n");
}

void eNetEditorProcessingDialog::processingError()
{
    // Write error message
    ui->TextInformation->insertPlainText("error!\n");

    // clear nameOfProcess
    processName = "";

    // Unlock button
    setButtonBlocked(false);
}

void eNetEditorProcessingDialog::processingFinished()
{
    // Write finish information
    ui->TextInformation->insertPlainText("finished process " + processName + ".\n");

    // clear nameOfProcess
    processName = "";

    // Unlock button
    setButtonBlocked(false);
}

void eNetEditorProcessingDialog::toolMessage(const QString &tool, const QString &message)
{
    // write message
    ui->TextInformation->insertPlainText(tool + ": " + message + "\n");
}

void eNetEditorProcessingDialog::setButtonBlocked(bool value)
{
    // Enable or disable accept button
    ui->ButtonAccept->setDisabled(value);
}

void eNetEditorProcessingDialog::on_ButtonAccept_released()
{
    // Close when accept
    close();
}
