#include "jtrRouterToolDialog.h"
#include "ui_jtrRouterToolDialog.h"

// Configuration
#include "../../configuration/tools/jtrRouterToolConfiguration.h"
#include "../../configuration/tools/netConvertToolConfiguration.h"
#include "../../configuration/main/eNetEditorMainConfiguration.h"

// Project
#include "../../project/eNetEditorProject.h"

// Database
#include "../../database/eNetEditorDatabase.h"

// jtrRouter Tool
#include "../../tools/jtrRouterTool.h"


jtrRouterToolDialog::jtrRouterToolDialog(eNetEditorMainWindow *neweNetEditorMainW) : eNetEditorToolDialog(neweNetEditorMainW), ui(new Ui::jtrRouterToolDialog)
{
    // Set UI
    ui->setupUi(this);

    // Create tool
    jtrRouterT = new jtrRouterTool(getMessages(), geteNetEditorConfiguration(), this);
}

jtrRouterToolDialog::~jtrRouterToolDialog()
{
    // Delete UI
    delete ui;

    // Delete Tool
    delete jtrRouterT;
}

void jtrRouterToolDialog::openDialog(eNetEditorProject *newProject)
{
    // If pointer to project isn't NULL
    if(newProject != NULL)
    {
        // Link project
        setProject(newProject);

        // Reset parameters
        resetParameters();

        // Update Parameters in all Textbox, Checkboxs, etc...
        updateParameters();

        // Open Dialog
        show();
    }
}

void jtrRouterToolDialog::resetParameters()
{
    // Input

    netFile = getProject()->getProjectPath() + "/" + geteNetEditorConfiguration()->getNetConvertConfiguration()->getOutputfolder() + "/" + getProject()->getProjectName() + "." + geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultOutputFile();

    additionalFiles;

    alternativeFiles;

    flowFiles;

    turnRatioFiles;

    // Oputput

    outputFile;

    vtypeOutput;

    exitTimes;

    // Processing

    ignoreErrors = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultIgnoreErrors();

    unsortedInput = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultUnsortedInput();

    routeSteps = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultRouteSteps();

    randomizeFlows = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultRandomizeFlows();

    maxAlternatives = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultMaxAlternatives();

    removeLoops = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultRemoveLoops();

    repair = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultRepair();

    weightsInterpolate = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultWeightsInterpolate();

    withTaz = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultWithTaz();

    routingThreads = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultRoutingThreads();

    maxEdgesFactor = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultMaxEdgesFactor();

    turnDefaults = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultTurnDefaults();

    sinkEdges = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultSinkEdges();

    acceptAllDestinations = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultAcceptAllDestinations();

    ignoreVclasses = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultIgnoreVclasses();

    allowLoops = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultAllowLoops();

    // Depart

    departlane = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultDepartlane();

    departpos = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultDepartpos();

    departspeed = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultDepartspeed();

    arrivallane = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultArrivallane();

    arrivalpos = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultArrivalpos();

    arrivalspeed = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultArrivalspeed();

    defaultsOverride = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultDefaultsOverride();

    begin = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultBegin();

    end = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultEnd();

    // Report

    verbose = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultVerbose();

    printOptions = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultPrintOptions();

    help = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultHelp();

    version = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultVersion();

    xmlValidation = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultXmlValidation();

    xmlValidationNet = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultXmlValidationNet();

    noWarnings = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultNoWarnings();

    log = "";

    messageLog = "";

    errorLog = "";

    statsPeriod = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultStatsPeriod();

    noStepLog = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultNoStepLog();

    random = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultRandom();

    seed = geteNetEditorConfiguration()->getJtrRouterConfiguration()->getJtrRouterDefaultSeed();
}

void jtrRouterToolDialog::updateParameters()
{
    // Input

    ui->TextSumoNetwork->setText(netFile);

    ui->TextAdditionalFiles->setText(additionalFiles);

    ui->TextAlternativeFiles->setText(alternativeFiles);

    ui->TextFlowFiles->setText(flowFiles);

    ui->TextTurnRatioFiles->setText(turnRatioFiles);

    // Oputput

    ui->TextOutput->setText(outputFile);

    ui->TextVTypeOutput->setText(vtypeOutput);

    ui->CheckBoxExitTimes->setChecked(exitTimes);

    // Processing

    ui->CheckBoxIgnoreErrors->setChecked(ignoreErrors);

    ui->CheckBoxUnsortedInput->setChecked(unsortedInput);

    ui->TextRouteSteps->setText(QString::number(routeSteps));

    ui->CheckBoxRandomizeFlows->setChecked(randomizeFlows);

    ui->TextMaxAlternatives->setText(QString::number(maxAlternatives));

    ui->CheckBoxRemoveLoops->setChecked(removeLoops);

    ui->CheckBoxRepair->setChecked(repair);

    ui->CheckBoxWeightsInterpolate->setChecked(weightsInterpolate);

    ui->CheckBoxWidthTaz->setChecked(withTaz);

    ui->TextRoutingThreads->setText(QString::number(routingThreads));

    ui->TextMaxEdgeFactor->setText(QString::number(maxEdgesFactor));

    ui->TextTurnDefaults->setText(turnDefaults);

    ui->TextSinkEdges->setText(sinkEdges);

    ui->CheckBoxAcceptAllDestinations->setChecked(acceptAllDestinations);

    ui->CheckBoxIgnoreVClasses->setChecked(ignoreVclasses);

    ui->CheckBoxAllowLoops->setChecked(allowLoops);

    // Depart

    ui->TextDepartLane->setText(departlane);

    ui->TextDepartPos->setText(departpos);

    ui->TextDepartSpeed->setText(departspeed);

    ui->TextArrivalLane->setText(arrivallane);

    ui->TextArrivalPos->setText(arrivalpos);

    ui->TextArrivalSpeed->setText(arrivalspeed);

    ui->CheckBoxDefaultOverride->setChecked(defaultsOverride);

    ui->TextTimeBegin->setText(QString::number(begin));

    ui->TextTimeEnd->setText(QString::number(end));

    // Report

    ui->CheckBoxVerbose->setChecked(verbose);

    ui->CheckBoxPrintOptions->setChecked(printOptions);

    ui->CheckBoxHelp->setChecked(help);

    ui->CheckBoxVersion->setChecked(version);

    ui->ComboBoxXmlValidation->setCurrentText(xmlValidation);

    ui->ComboBoxXmlValidationNet->setCurrentText(xmlValidationNet);

    ui->CheckBoxNoWarnings->setChecked(noWarnings);

    ui->TextLog->setText(log);

    ui->TextMessageLog->setText(messageLog);

    ui->TextErrorLog->setText(errorLog);

    ui->TextStatsPeriod->setText(QString::number(statsPeriod));

    ui->CheckBoxNoStepLog->setChecked(noStepLog);

    ui->CheckBoxRandom->setChecked(random);

    ui->TextSeed->setText(QString::number(seed));
}

void jtrRouterToolDialog::setInputParameters()
{

}

void jtrRouterToolDialog::setOutputParameters()
{

}

void jtrRouterToolDialog::setProcessingParameters()
{

}

void jtrRouterToolDialog::on_ButtonAccept_released()
{

}

void jtrRouterToolDialog::on_ButtonCancel_released()
{
    // Close dialog
    close();
}

void jtrRouterToolDialog::on_ButtonReset_released()
{
    // Reset all parameters of tool
    resetParameters();

    // Update all widgets
    updateParameters();
}

void jtrRouterToolDialog::on_TextSumoNetwork_textChanged()
{
    netFile = ui->TextSumoNetwork->toPlainText();
}

void jtrRouterToolDialog::on_TextAdditionalFiles_textChanged()
{
    additionalFiles = ui->TextAdditionalFiles->toPlainText();
}

void jtrRouterToolDialog::on_TextAlternativeFiles_textChanged()
{
    alternativeFiles = ui->TextAlternativeFiles->toPlainText();
}

void jtrRouterToolDialog::on_TextFlowFiles_textChanged()
{
    flowFiles = ui->TextFlowFiles->toPlainText();
}

void jtrRouterToolDialog::on_TextTurnRatioFiles_textChanged()
{
    turnRatioFiles = ui->TextTurnRatioFiles->toPlainText();
}

void jtrRouterToolDialog::on_ButtonSearchSumoNetwork_released()
{
    /** Falta **/
}

void jtrRouterToolDialog::on_ButtonSearchAdditional_released()
{
    /** Falta **/
}

void jtrRouterToolDialog::on_ButtonSearchAlternativeFiles_released()
{
    /** Falta **/
}

void jtrRouterToolDialog::on_ButtonSearchFlowFiles_released()
{
    /** Falta **/
}

void jtrRouterToolDialog::on_ButtonSearchTurnRatioFiles_released()
{
    /** Falta **/
}

void jtrRouterToolDialog::on_TextDepartLane_textChanged()
{
    departlane = ui->TextDepartLane->toPlainText();
}

void jtrRouterToolDialog::on_TextDepartPos_textChanged()
{
    departpos = ui->TextDepartPos->toPlainText();
}

void jtrRouterToolDialog::on_TextDepartSpeed_textChanged()
{
    departspeed = ui->TextDepartSpeed->toPlainText();
}

void jtrRouterToolDialog::on_TextArrivalLane_textChanged()
{
    arrivallane = ui->TextArrivalLane->toPlainText();
}

void jtrRouterToolDialog::on_TextArrivalPos_textChanged()
{
    arrivalpos = ui->TextArrivalPos->toPlainText();
}

void jtrRouterToolDialog::on_TextArrivalSpeed_textChanged()
{
    arrivalspeed = ui->TextArrivalSpeed->toPlainText();
}

void jtrRouterToolDialog::on_TextTimeBegin_textChanged()
{
    begin = ui->TextTimeBegin->toPlainText().toInt();
}

void jtrRouterToolDialog::on_TextTimeEnd_textChanged()
{
    end = ui->TextTimeEnd->toPlainText().toInt();
}

void jtrRouterToolDialog::on_TextSeed_textChanged()
{
    seed = ui->TextSeed->toPlainText().toInt();
}

void jtrRouterToolDialog::on_CheckBoxRandom_toggled(bool checked)
{
    random = checked;
}

void jtrRouterToolDialog::on_TextOutput_textChanged()
{
    outputFile = ui->TextOutput->toPlainText();
}

void jtrRouterToolDialog::on_TextVTypeOutput_textChanged()
{
    vtypeOutput = ui->TextVTypeOutput->toPlainText();
}

void jtrRouterToolDialog::on_ButtonOutput_released()
{
    /** Falta **/
}

void jtrRouterToolDialog::on_ButtonSearchVTypeOutput_released()
{
    /** Falta **/
}

void jtrRouterToolDialog::on_CheckBoxExitTimes_toggled(bool checked)
{
    exitTimes = checked;
}

void jtrRouterToolDialog::on_TextLog_textChanged()
{
    log = ui->TextLog->toPlainText();
}

void jtrRouterToolDialog::on_TextMessageLog_textChanged()
{
    messageLog = ui->TextMessageLog->toPlainText();
}

void jtrRouterToolDialog::on_TextErrorLog_textChanged()
{
    errorLog = ui->TextErrorLog->toPlainText();
}

void jtrRouterToolDialog::on_ButtonSearchLog_released()
{
    /** Falta **/
}

void jtrRouterToolDialog::on_ButtonSearchMessageLog_released()
{
    /** Falta **/
}

void jtrRouterToolDialog::on_ButtonSearchErrorLog_released()
{
    /** Falta **/
}

void jtrRouterToolDialog::on_CheckBoxVerbose_toggled(bool checked)
{
    verbose = checked;
}

void jtrRouterToolDialog::on_CheckBoxVersion_toggled(bool checked)
{
    version = checked;
}

void jtrRouterToolDialog::on_CheckBoxPrintOptions_toggled(bool checked)
{
    printOptions = checked;
}

void jtrRouterToolDialog::on_CheckBoxNoStepLog_toggled(bool checked)
{
    noStepLog = checked;
}

void jtrRouterToolDialog::on_CheckBoxHelp_toggled(bool checked)
{
    help = checked;
}

void jtrRouterToolDialog::on_CheckBoxNoWarnings_toggled(bool checked)
{
    noWarnings = checked;
}

void jtrRouterToolDialog::on_TextStatsPeriod_textChanged()
{
    statsPeriod = ui->TextStatsPeriod->toPlainText().toInt();
}

void jtrRouterToolDialog::on_ComboBoxXmlValidation_editTextChanged(const QString &arg1)
{
    xmlValidation = arg1;
}

void jtrRouterToolDialog::on_ComboBoxXmlValidationNet_currentTextChanged(const QString &arg1)
{
    xmlValidationNet = arg1;
}

void jtrRouterToolDialog::on_TextRouteSteps_textChanged()
{
    routeSteps = ui->TextRouteSteps->toPlainText().toInt();
}

void jtrRouterToolDialog::on_TextMaxAlternatives_textChanged()
{
    maxAlternatives = ui->TextMaxAlternatives->toPlainText().toInt();
}

void jtrRouterToolDialog::on_TextRoutingThreads_textChanged()
{
    routingThreads = ui->TextRoutingThreads->toPlainText().toInt();
}

void jtrRouterToolDialog::on_TextMaxEdgeFactor_textChanged()
{
    maxEdgesFactor = ui->TextMaxEdgeFactor->toPlainText().toDouble();
}

void jtrRouterToolDialog::on_TextTurnDefaults_textChanged()
{
    turnDefaults = ui->TextTurnDefaults->toPlainText();
}

void jtrRouterToolDialog::on_TextSinkEdges_textChanged()
{
    sinkEdges = ui->TextSinkEdges->toPlainText().toInt();
}

void jtrRouterToolDialog::on_CheckBoxIgnoreErrors_toggled(bool checked)
{
    ignoreErrors = checked;
}

void jtrRouterToolDialog::on_CheckBoxUnsortedInput_toggled(bool checked)
{
    unsortedInput = checked;
}

void jtrRouterToolDialog::on_CheckBoxRandomizeFlows_toggled(bool checked)
{
    randomizeFlows = checked;
}

void jtrRouterToolDialog::on_CheckBoxRemoveLoops_toggled(bool checked)
{
    removeLoops = checked;
}

void jtrRouterToolDialog::on_CheckBoxRepair_toggled(bool checked)
{
    repair = checked;
}

void jtrRouterToolDialog::on_CheckBoxWeightsInterpolate_toggled(bool checked)
{
    weightsInterpolate = checked;
}

void jtrRouterToolDialog::on_CheckBoxWidthTaz_toggled(bool checked)
{
    withTaz = checked;
}

void jtrRouterToolDialog::on_CheckBoxAcceptAllDestinations_toggled(bool checked)
{
    acceptAllDestinations = checked;
}

void jtrRouterToolDialog::on_CheckBoxIgnoreVClasses_toggled(bool checked)
{
    ignoreVclasses = checked;
}

void jtrRouterToolDialog::on_CheckBoxAllowLoops_toggled(bool checked)
{
    allowLoops = checked;
}

void jtrRouterToolDialog::on_CheckBoxDefaultOverride_toggled(bool checked)
{
    defaultsOverride = checked;
}
