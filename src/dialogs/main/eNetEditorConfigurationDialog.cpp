#include "eNetEditorConfigurationDialog.h"
#include "ui_eNetEditorConfigurationDialog.h"

// Main WIndow
#include "eNetEditorMainWindow.h"

// Configuration managers
#include "../../configuration/main/eNetEditorMainConfiguration.h"

// Configuration Tool
#include "../../configuration/tools/eNetEditorToolConfiguration.h"
#include "../../configuration/tools/sumoToolConfiguration.h"
#include "../../configuration/tools/netConvertToolConfiguration.h"
#include "../../configuration/tools/netGenerateToolConfiguration.h"
#include "../../configuration/tools/dfRouterToolConfiguration.h"
#include "../../configuration/tools/duaRouterToolConfiguration.h"
#include "../../configuration/tools/jtrRouterToolConfiguration.h"
#include "../../configuration/tools/cadytsToolConfiguration.h"


eNetEditorConfigurationDialog::eNetEditorConfigurationDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorDialog(eNetEditorMainW), ui(new Ui::eNetEditorConfigurationDialog)
{
    // Create GUI
    ui->setupUi(this);

    // Set all Path fields.
    ui->TextPathSimulator->setText(geteNetEditorMainWindow()->geteNetEditorConfiguration()->getSumoConfiguration()->getExecutablePath());
    ui->TextPathNetconvert->setText(geteNetEditorMainWindow()->geteNetEditorConfiguration()->getNetConvertConfiguration()->getExecutablePath());
    ui->TextPathNetgenerate->setText(geteNetEditorMainWindow()->geteNetEditorConfiguration()->getNetGenerateConfiguration()->getExecutablePath());
    ui->TextPathDfrouter->setText(geteNetEditorMainWindow()->geteNetEditorConfiguration()->getDfRouterConfiguration()->getExecutablePath());
    ui->TextPathDuarouter->setText(geteNetEditorMainWindow()->geteNetEditorConfiguration()->getDuaRouterConfiguration()->getExecutablePath());
    ui->TextPathJtrrouter->setText(geteNetEditorMainWindow()->geteNetEditorConfiguration()->getJtrRouterConfiguration()->getExecutablePath());
    ui->TextPathCadyts->setText(geteNetEditorMainWindow()->geteNetEditorConfiguration()->getCadytsConfiguration()->getExecutablePath());
}

eNetEditorConfigurationDialog::~eNetEditorConfigurationDialog()
{
    // Delete UI
    delete ui;
}

void eNetEditorConfigurationDialog::openDialog()
{
    // Open dialog
    show();
}



void eNetEditorConfigurationDialog::on_ButtonSearchSimulator_released()
{
    // Declare temporal String
    QString pathSimulatorTmp;

    // Open search dialog
    pathSimulatorTmp = QFileDialog::getOpenFileName(
                           this,
                           "Open Simulator executable",
                           QApplication::applicationDirPath() ,
                           tr("Sumo32 (sumo.exe), Sumo64 (sumo64D.exe)")
                       );

    // If the button cancel was not pressed
    if(pathSimulatorTmp != NULL)
    {
        // Set pathSimulator on the thex box
        ui->TextPathSimulator->setText(pathSimulatorTmp);
    }
}

void eNetEditorConfigurationDialog::on_ButtonSearchNetconvert_released()
{
    // Declare temporal path for NetCOnvert
    QString pathNetconvertTmp;

    // Open search dialog
    pathNetconvertTmp = QFileDialog::getOpenFileName(
                            this,
                            "Open Netconvert executable",
                            QApplication::applicationDirPath() ,
                            tr("NetConvert32 (netconvert.exe), netconvert64 (netconvert64D.exe)")
                        );

    // If the button cancel was not pressed
    if(pathNetconvertTmp != NULL)
    {
        // Set pathNetconvert on the thex box
        ui->TextPathNetconvert->setText(pathNetconvertTmp);
    }
}

void eNetEditorConfigurationDialog::on_ButtonSearchNetgenerate_released()
{
    // Declare temporal path
    QString pathNetgenerateTmp;

    // Open search dialog
    pathNetgenerateTmp = QFileDialog::getOpenFileName(
                             this,
                             "Open Netgenerate executable",
                             QApplication::applicationDirPath() ,
                             tr("NetGenerate32 (netgenerate.exe), NetGenerate64 (netgenerate64D.exe)")
                         );

    // If the button cancel was not pressed
    if(pathNetgenerateTmp != NULL)
    {
        // Set pathNetgenerate on the thex box
        ui->TextPathNetgenerate->setText(pathNetgenerateTmp);
    }

}

void eNetEditorConfigurationDialog::on_ButtonSearchDfrouter_released()
{
    // Declare temporal path
    QString pathDfrouterTmp;

    // Open search dialog
    pathDfrouterTmp = QFileDialog::getOpenFileName(
                          this,
                          "Open PathDFRouter executable",
                          QApplication::applicationDirPath() ,
                          tr("PathDFRoute32 (dfrouter.exe), PathDFRoute64 (dfrouter64D.exe)")
                      );

    // If the button cancel was not pressed
    if(pathDfrouterTmp != NULL)
    {
        // Set pathDfrouter on the thex box
        ui->TextPathDfrouter->setText(pathDfrouterTmp);
    }
}

void eNetEditorConfigurationDialog::on_ButtonSearchDuarouter_released()
{
    // Declare temporal path
    QString pathDuarouterTmp;

    // Open search dialog
    pathDuarouterTmp = QFileDialog::getOpenFileName(
                           this,
                           "Open DuaRouter executable",
                           QApplication::applicationDirPath() ,
                           tr("DuaRouter32 (duarouter.exe), DuaRouter64 (duarouter64D.exe)")
                       );

    // If the button cancel was not pressed
    if(pathDuarouterTmp != NULL)
    {
        // Set pathDuarouter on the thex box
        ui->TextPathDuarouter->setText(pathDuarouterTmp);
    }
}

void eNetEditorConfigurationDialog::on_ButtonSearchJtrrouter_released()
{
    // Declare temporal path
    QString pathJtrrouterTmp;

    // Open search dialog
    pathJtrrouterTmp = QFileDialog::getOpenFileName(
                           this,
                           "Open JtrRouter executable",
                           QApplication::applicationDirPath() ,
                           tr("JtrRouter32 (jtrrouter.exe), JtrRouter64 (jtrrouter64D.exe)")
                       );

    // If the button cancel was not pressed
    if(pathJtrrouterTmp != NULL)
    {
        // Set pathJtrrouter on the thex box
        ui->TextPathJtrrouter->setText(pathJtrrouterTmp);
    }
}

void eNetEditorConfigurationDialog::on_ButtonSearchCadyts_released()
{
    // Declare temporal path
    QString pathCadytsTmp;

    // Open search dialog
    pathCadytsTmp = QFileDialog::getOpenFileName(
                        this,
                        "Open Cadyts executable",
                        QApplication::applicationDirPath() ,
                        tr("Cadyts (cadytsIterate.py)")
                    );

    // If the button cancel was not pressed
    if(pathCadytsTmp != NULL)
    {
        // Set Cadyts on the thex box
        ui->TextPathCadyts->setText(pathCadytsTmp);
    }
}

void eNetEditorConfigurationDialog::on_ButtonAccept_released()
{
    // Update the path of all tools
    geteNetEditorMainWindow()->geteNetEditorConfiguration()->getSumoConfiguration()->setExecutablePath(ui->TextPathSimulator->toPlainText());

    geteNetEditorMainWindow()->geteNetEditorConfiguration()->getNetConvertConfiguration()->setExecutablePath(ui->TextPathNetconvert->toPlainText());

    geteNetEditorMainWindow()->geteNetEditorConfiguration()->getNetGenerateConfiguration()->setExecutablePath(ui->TextPathNetgenerate->toPlainText());

    geteNetEditorMainWindow()->geteNetEditorConfiguration()->getDfRouterConfiguration()->setExecutablePath(ui->TextPathDfrouter->toPlainText());

    geteNetEditorMainWindow()->geteNetEditorConfiguration()->getDuaRouterConfiguration()->setExecutablePath(ui->TextPathDuarouter->toPlainText());

    geteNetEditorMainWindow()->geteNetEditorConfiguration()->getJtrRouterConfiguration()->setExecutablePath(ui->TextPathJtrrouter->toPlainText());

    geteNetEditorMainWindow()->geteNetEditorConfiguration()->getCadytsConfiguration()->setExecutablePath(ui->TextPathCadyts->toPlainText());

    // Close dialog
    close();
}
