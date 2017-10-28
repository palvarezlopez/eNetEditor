#include "dfRouterToolDialog.h"
#include "ui_dfRouterToolDialog.h"

// Project
#include "../../project/eNetEditorProject.h"
// Database
#include "../../database/eNetEditorDatabase.h"

// Configuration
#include "../../configuration/main/eNetEditorMainConfiguration.h"
#include "../../configuration/tools/dfRouterToolConfiguration.h"
#include "../../configuration/tools/netConvertToolConfiguration.h"
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/flowMeasureItemConfiguration.h"
#include "../../configuration/items/detectors/inductionLoopsE1DetectorItemConfiguration.h"

// DfRouter
#include "../../tools/dfRouterTool.h"


dfRouterToolDialog::dfRouterToolDialog(eNetEditorMainWindow *neweNetEditorMainW) : eNetEditorToolDialog(neweNetEditorMainW), ui(new Ui::dfRouterToolDialog)
{
    // Set UI
    ui->setupUi(this);

    // Crate dfRouter Tool
    dfRouterT = new dfRouterTool(getMessages(), geteNetEditorConfiguration(), this);

    // Set the size of the list with the input parameters
    getInputParameters()->fill("", geteNetEditorConfiguration()->getDfRouterConfiguration()->getNumberOfInputParameters());

    // Set the size of the list with the output parameters
    getOutputParameters()->fill("", geteNetEditorConfiguration()->getDfRouterConfiguration()->getNumberOfOutputParameters());

    // Set the size of the list with the configuration parameters
    getProcessingParameters()->fill("", geteNetEditorConfiguration()->getDfRouterConfiguration()->getNumberOfProcessingParameters());
}

dfRouterToolDialog::~dfRouterToolDialog()
{
    // Delete UI
    delete ui;

    // Delete tool
    delete dfRouterT;
}

void dfRouterToolDialog::openDialog(eNetEditorProject *newProject)
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

void dfRouterToolDialog::resetParameters()
{
    // Set default variable Loads the SUMO-network FILE
    inputNetFile = getProject()->getProjectPath() + "/" + geteNetEditorConfiguration()->getNetConvertConfiguration()->getOutputfolder() + "/" + getProject()->getProjectName() + "." + geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultOutputFile();

    // Set default variable Loads detector descriptions from FILE
    inputInductionLoopsE1DetectorFiles = getProject()->getProjectPath() + "/" + getProject()->getProjectName() + "." +  geteNetEditorConfiguration()->getProjectConfiguration()->getInductionLoopsE1DetectorItemConfiguration()->getInductionLoopsE1DetectorItemDefaultDetectorDefinitionsFileNameWithExtension();

    // Set default variable Loads detector flows from FILE(s)
    inputMeasureFiles = getProject()->getProjectPath() + "/" + getProject()->getProjectName() + "." +  geteNetEditorConfiguration()->getProjectConfiguration()->getFlowMeasureItemConfiguration()->getItemFileNameWithExtension();

    // Set default variable Prefix which is applied to all output files. The special string 'TIME' is replaced by the current time.
    outputPrefixFile = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultOutputPrefixFile();

    // Set default variable Saves computed routes to FILE
    outputRoutesFile = getProject()->getProjectPath() + "/" + geteNetEditorConfiguration()->getDfRouterConfiguration()->getOutputfolder() + "/" + getProject()->getProjectName() + "." + geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultOutputRoutesFile() + "." + outputPrefixFile;

    // Set default variable Forces DFROUTER to compute routes for in-between detectors; default: false
    outputRoutesForAll = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultOutputRoutesForAll();

    // Set default variable Saves typed detectors to FILE
    outputDetectorFile = getProject()->getProjectPath() + "/" + geteNetEditorConfiguration()->getDfRouterConfiguration()->getOutputfolder() + "/" + getProject()->getProjectName() + "." + geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultOutputDetectorFile() + "." + outputPrefixFile;

    // Set default variable Saves detector positions as pois to FILE
    outputDetectorsPoiFile = getProject()->getProjectPath() + "/" + geteNetEditorConfiguration()->getDfRouterConfiguration()->getOutputfolder() + "/" + getProject()->getProjectName() + "." + geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultOutputDetectorsPoiFile() + "." + outputPrefixFile;

    // Set default variable Saves emitter definitions for source detectors to FILE
    outputEmittersFile = getProject()->getProjectPath() + "/" + geteNetEditorConfiguration()->getDfRouterConfiguration()->getOutputfolder() + "/" + getProject()->getProjectName() + "." + geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultOutputEmittersFile() + "." + outputPrefixFile;

    // Set default variable Add vehicle types to the emitters file (PKW, LKW); default: false
    outputVtype = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultOutputVtype();

    // Set default variable Saves emitter positions as pois to FILE
    outputEmittersPoiFile = getProject()->getProjectPath() + "/" + geteNetEditorConfiguration()->getDfRouterConfiguration()->getOutputfolder() + "/" + getProject()->getProjectName() + "." + geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultOutputEmittersPoiFile() + "." + outputPrefixFile;

    // Set default variable Saves variable seed sign definitions for sink detectors to FILE
    outputVariableSpeedSignFile = getProject()->getProjectPath() + "/" + geteNetEditorConfiguration()->getDfRouterConfiguration()->getOutputfolder() + "/" + getProject()->getProjectName() + "." + geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultOutputVariableSpeedSignFile() + "." + outputPrefixFile;

    // Set default variable Saves rerouter definitions for sink detectors to FILE
    outputEndRerouteFile = getProject()->getProjectPath() + "/" + geteNetEditorConfiguration()->getDfRouterConfiguration()->getOutputfolder() + "/" +  getProject()->getProjectName() + "." + geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultOutputEndRerouteFile() + "." + outputPrefixFile;

    // Set default variable Saves validation
    outputValidationFile = getProject()->getProjectPath() + "/" + geteNetEditorConfiguration()->getDfRouterConfiguration()->getOutputfolder() + "/" + getProject()->getProjectName() + "." + geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultOutputValidationFile() + "." + outputPrefixFile;

    // Set default variable Add sources to output default: false
    outputValidationAddSources = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultOutputValidationAddSources();

    // Set default variable Derive missing flow values from upstream or downstream (not working!); default: false
    guessEmptyFlows = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultGuessEmptyFlows();

    // Set default variable Switches to highway-mode; default: false
    highwayMode = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultHighwayMode();

    // Set default variable Only warn about unparseable detectors; default: false
    ignoreInvalidDetectors = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultIgnoreInvalidDetectors();

    // Set default variable Recomputes detector types even if given; default: false
    revalidateDetectors = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultRevalidateDetectors();

    // Set default variable Recomputes routes even if given; default: false
    revalidateRoutes = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultRevalidateRoutes();

    // Set default variable Keeps routes even if they have exhausted max-search-depth; default: false
    keepUnfinishedRoutes = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultKeepUnfinishedRoutes();

    // Set default variable Keeps routes even if a shorter one exists; default: false
    keepLongerRoutes = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultKeepLongerRoutes();

    // Set default variable Number of edges to follow a route without passing a detector; default: 30
    maxSearchDepth = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultMaxSearchDepth();

    // Set default variable Writes only emission times; default: false
    emissionsOnly = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultEmissionsOnly();

    // Set default variable Do not route on these edges
    disallowedEdges = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultDisallowedEdges();

    // Set default variable Allow turnarounds as route continuations; default: false
    keepTurnarounds = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultKeepTurnarounds();

    // Set default variable Minimum distance in meters between start and end node of every route; default: -1
    minRouteLength = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultMinRouteLength();

    // Set default variable Multiply flow times with TIME to get seconds; default: 60
    timeFactor = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultTimeFactor();

    // Set default variable Subtracts TIME seconds from (scaled) flow times; default: 0
    timeOffset = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultTimeOffset();

    // Set default variable Expected distance between two successive data sets; default: 60
    timeStep = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultTimeStep();

    // Set default variable Write calibrators to FILE; default: false
    calibratorOutput = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultCalibratorOutput();

    // Set default variable Include unused routes; default: false
    includeUnusedRoutes = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultIncludeUnusedRoutes();

    // Set default variable Revalidate flows; default: false
    revalidateFlows = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultRevalidateFlows();

    // Set default variable Removes empty detectors from the list; default: false
    removeEmptyDetectors = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultRemoveEmptyDetectors();

    // Set default variable Strict sources; default: false
    strictSources = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultStrictSources();

    // Set default variable Try to determine further inflows to an inbetween detector when computing split probabilities; default: false
    respectConcurrentInflows = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultRespectConcurrentInflows();

    // Set default variable Scale factor for flows; default: 1
    scale = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultScale();

    // Set default variable Assigns a default depart lane
    departlane = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultDepartlane();

    // Set default variable Assigns a default depart position
    departpos = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultDepartpos();

    // Set default variable Assigns a default depart speed
    departspeed = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultDepartspeed();

    // Set default variable Assigns a default arrival lane
    arrivallane = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultArrivallane();

    // Set default variable Assigns a default arrival position
    arrivalpos = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultArrivalpos();

    // Set default variable Assigns a default arrival speed
    arrivalspeed = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultArrivalspeed();

    // Set default variable Defines the begin time; Previous defs will be discarded; default: 0
    begin = getProject()->getTimeBegin();

    // Set default variable Defines the end time; Later defs will be discarded; Defaults to one day; default: 86400
    end = getProject()->getTimeEnd();

    // Set default variable Switches to verbose output; default: false
    verbose = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultVerbose();

    // Set default variable Prs option values before processing; default: false
    printOptions = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultPrintOptions();

    // Set default variable Prs this screen; default: false
    help = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultHelp();

    // Set default variable Prs the current version; default: false
    version = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultVersion();

    // Set default variable Set schema validation scheme of XML inputs ("never", "auto" or "always"); default: auto
    xmlValidation = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultXmlValidation();

    // Set default variable Set schema validation scheme of SUMO network inputs ("never", "auto" or "always"); default: never
    xmlValidationNet = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultXmlValidationNet();

    // Set default variable Disables output of warnings; default: false
    noWarnings = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultNoWarnings();

    // Set default variable Writes all messages to FILE (implies verbose)
    log = getProject()->getProjectPath() + "/" + getProject()->getProjectName() + "." + geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultLog();

    // Set default variable Writes all non-error messages to FILE (implies verbose)
    messageLog = getProject()->getProjectPath() + "/" + getProject()->getProjectName() + "." + geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultMessageLog();

    // Set default variable Writes all warnings and errors to FILE
    errorLog = getProject()->getProjectPath() + "/" + getProject()->getProjectName() + "." + geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultErrorLog();

    // Set default variable Lists detectors with no flow (enable -v); default: false
    reportEmptyDetectors = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultReportEmptyDetectors();

    // Set default variable Prs aggregated detector flows; default: false
    printAbsoluteFlows = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultPrintAbsoluteFlows();

    // Set default variable Disable console output of route parsing step; default: false
    noStepLog = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultNoStepLog();

    // Set default variable Initialises the random number generator with the current system time; default: false
    random = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultRandom();

    // Set default variable Initialises the random number generator with the given value; default: 23423
    seed = geteNetEditorConfiguration()->getDfRouterConfiguration()->getDfRouterDefaultSeed();
}

void dfRouterToolDialog::updateParameters()
{
    ui->TextSumoNetwork->setText(inputNetFile);

    ui->TextDetectorFiles->setText(inputInductionLoopsE1DetectorFiles);

    ui->TextMeasureFiles->setText(inputMeasureFiles);

    ui->TextRoutesOutput->setText(outputRoutesFile);

    ui->CheckBoxRoutesForAll->setChecked(outputRoutesForAll);

    ui->TextDetectorOutput->setText(outputDetectorFile);

    ui->TextDetectorsPoiOutput->setText(outputDetectorsPoiFile);

    ui->TextEmmitersOutput->setText(outputEmittersFile);

    ui->CheckBoxVType->setChecked(outputVtype);

    ui->TextEmmitersPoiOutput->setText(outputEmittersPoiFile);

    ui->TextVariableSpdSignOutput->setText(outputVariableSpeedSignFile);

    ui->TextEndRerouteOutput->setText(outputEndRerouteFile);

    ui->TextValidationOutput->setText(outputValidationFile);

    ui->CheckBoxValidationOutputAddSource->setChecked(outputValidationAddSources);

    ui->CheckBoxGuessEmptyFlows->setChecked(guessEmptyFlows);

    ui->CheckBoxHighwayMode->setChecked(highwayMode);

    ui->CheckBoxIgnoreInvalidDetectors->setChecked(ignoreInvalidDetectors);

    ui->CheckBoxRevalidateDetectors->setChecked(revalidateDetectors);

    ui->CheckBoxRevalidateRoutes->setChecked(revalidateRoutes);

    ui->CheckBoxKeepUnfinishedRoutes->setChecked(keepUnfinishedRoutes);

    ui->CheckBoxKeepLongerRoutes->setChecked(keepLongerRoutes);

    ui->TextMaxSearchDepth->setText(QString::number(maxSearchDepth));

    ui->CheckBoxEmissionsOnly->setChecked(emissionsOnly);

    ui->TextDisallowedEdges->setText(disallowedEdges);

    ui->CheckBoxKeepturnAorunds->setChecked(keepTurnarounds);

    ui->TextMinRouteLenght->setText(QString::number(minRouteLength));

    ui->TextTimeFactor->setText(QString::number(timeFactor));

    ui->TextTimeOffset->setText(QString::number(timeOffset));

    ui->TextTimeStep->setText(QString::number(timeStep));

    ui->CheckBoxCalibratorOutput->setChecked(calibratorOutput);

    ui->CheckBoxIncludeUnusedRoutes->setChecked(includeUnusedRoutes);

    ui->CheckBoxRevalidateFlows->setChecked(revalidateFlows);

    ui->CheckBoxRemoveEmptyDetectors->setChecked(removeEmptyDetectors);

    ui->CheckBoxStrictSources->setChecked(strictSources);

    ui->CheckBoxRespectConcurrenceInflows->setChecked(respectConcurrentInflows);

    ui->TextScale->setText(QString::number(scale));

    ui->TextDepartLane->setText(departlane);

    ui->TextDepartPos->setText(departpos);

    ui->TextDepartSpeed->setText(departspeed);

    ui->TextArrivalLane->setText(arrivallane);

    ui->TextArrivalPos->setText(arrivalpos);

    ui->TextArrivalSpeed->setText(arrivalspeed);

    ui->TextTimeBegin->setText(QString::number(begin));

    ui->TextTimeEnd->setText(QString::number(end));

    ui->CheckBoxVerbose->setChecked(verbose);

    ui->CheckBoxPrintOptions->setChecked(printOptions);

    ui->CheckBoxHelp->setChecked(help);

    ui->CheckBoxVersion->setChecked(version);

    ui->ComboBoxXmlValidation->setCurrentText(xmlValidation);

    ui->CheckBoxNoWarnings->setChecked(noWarnings);

    ui->TextLog->setText(log);

    ui->TextMessageLog->setText(messageLog);

    ui->TextErrorLog->setText(errorLog);

    ui->CheckBoxReportEmptyDetectors->setChecked(reportEmptyDetectors);

    ui->CheckBoxPrintAbsoluteLogs->setChecked(printAbsoluteFlows);

    ui->CheckBoxNoStepLog->setChecked(noStepLog);

    ui->CheckBoxRandom->setChecked(random);

    ui->TextSeed->setText(QString::number(seed));
}

void dfRouterToolDialog::setInputParameters()
{
    // Set net file in the input parameters vector
    getInputParameters()->replace(dfRouterInputParameterNetFile, inputNetFile);

    // Set detector file in the input parameters vector
    getInputParameters()->replace(dfRouterInputParameterDetectorFiles, inputInductionLoopsE1DetectorFiles);

    // Set Measure file in the input parameters vector
    getInputParameters()->replace(dfRouterInputParameterMeasureFiles, inputMeasureFiles);
}

void dfRouterToolDialog::setOutputParameters()
{
    // Set file in the ouput parameter vector
    getOutputParameters()->replace(dfRouterOutputParameterPrefixFile, outputPrefixFile);

    // Set file in the ouput parameter vector
    getOutputParameters()->replace(dfRouterOutputParameterRoutesFile, outputRoutesFile);

    // Set file in the ouput parameter vector
    if(outputRoutesForAll)
    {
        getOutputParameters()->replace(dfRouterOutputParameterRoutesForAll, "true");
    }
    else
    {
        getOutputParameters()->replace(dfRouterOutputParameterRoutesForAll, "false");
    }

    // Set file in the ouput parameter vector
    getOutputParameters()->replace(dfRouterOutputParameterDetectorFile, outputDetectorFile);

    // Set file in the ouput parameter vector
    getOutputParameters()->replace(dfRouterOutputParameterDetectorsPoiFile, outputDetectorsPoiFile);

    // Set file in the ouput parameter vector
    getOutputParameters()->replace(dfRouterOutputParameterEmittersFile, outputEmittersFile);

    // Set file in the ouput parameter vector
    if (outputVtype)
    {
        getOutputParameters()->replace(dfRouterOutputParameterVtype, "true");
    }
    else
    {
        getOutputParameters()->replace(dfRouterOutputParameterVtype, "false");
    }

    // Set file in the ouput parameter vector
    getOutputParameters()->replace(dfRouterOutputParameterEmittersPoiFile, outputEmittersPoiFile);

    // Set file in the ouput parameter vector
    getOutputParameters()->replace(dfRouterOutputParameterVariableSpeedSignFile, outputVariableSpeedSignFile);

    // Set file in the ouput parameter vector
    getOutputParameters()->replace(dfRouterOutputParameterEndRerouteFile, outputEndRerouteFile);

    // Set file in the ouput parameter vector
    getOutputParameters()->replace(dfRouterOutputParameterValidationFile, outputValidationFile);

    // Set file in the ouput parameter vector
    if(outputValidationAddSources)
    {
        getOutputParameters()->replace(dfRouterOutputParameterValidationAddSources, "true");
    }
    else
    {
        getOutputParameters()->replace(dfRouterOutputParameterValidationAddSources, "false");
    }
}

void dfRouterToolDialog::setProcessingParameters()
{
    // Set guess empty Flows
    if(guessEmptyFlows)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersGuessEmptyFlows, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersGuessEmptyFlows, "false");
    }

    // Set highway mode
    if(highwayMode)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersHighwayMode, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersHighwayMode, "false");
    }

    // Set ignore invalid detectors
    if(ignoreInvalidDetectors)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersIgnoreInvalidDetectors, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersIgnoreInvalidDetectors, "false");
    }

    // Set revalidate detectors
    if(revalidateDetectors)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersRevalidateDetectors, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersRevalidateDetectors, "false");
    }

    // Set revalidate routes
    if(revalidateRoutes)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersRevalidateRoutes, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersRevalidateRoutes, "false");
    }

    // Set keep unfinished routes
    if(keepUnfinishedRoutes)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersKeepUnfinishedRoutes, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersKeepUnfinishedRoutes, "false");
    }

    // Set keep longer routes
    if(keepLongerRoutes)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersKeepLongerRoutes, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersKeepLongerRoutes, "false");
    }

    // Set max search depth
    getProcessingParameters()->replace(dfRouterProcessingParametersMaxSearchDepth, QString::number(maxSearchDepth));

    // Set Emission only
    if(emissionsOnly)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersEmissionsOnly, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersEmissionsOnly, "false");
    }

    // Set disallowedEdges
    getProcessingParameters()->replace(dfRouterProcessingParametersDisallowedEdges, disallowedEdges);

    // Set keep turnarounds
    if(keepTurnarounds)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersKeepTurnarounds, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersKeepTurnarounds, "false");
    }

    // Set minRouteLength
    getProcessingParameters()->replace(dfRouterProcessingParametersMinRouteLength, QString::number(minRouteLength));

    // Set Time factor
    getProcessingParameters()->replace(dfRouterProcessingParametersTimeFactor, QString::number(timeFactor));

    // Set time offset
    getProcessingParameters()->replace(dfRouterProcessingParametersTimeOffset, QString::number(timeOffset));

    // set timestep
    getProcessingParameters()->replace(dfRouterProcessingParametersTimeStep, QString::number(timeStep * 60));

    // Set calibratoroutput
    if(calibratorOutput)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersCalibratorOutput, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersCalibratorOutput, "false");
    }

    // Set calibratorOutput
    if(calibratorOutput)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersCalibratorOutput, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersCalibratorOutput, "false");
    }

    // Set include unused routes
    if(includeUnusedRoutes)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersIncludeUnusedRoutes, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersIncludeUnusedRoutes, "false");
    }

    // Set revalidate flows
    if(revalidateFlows)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersRevalidateFlows, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersRevalidateFlows, "false");
    }

    // Set remove empty detectors
    if(removeEmptyDetectors)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersRemoveEmptyDetectors, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersRemoveEmptyDetectors, "false");

    }

    // Set strict sources
    if(strictSources)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersStrictSources, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersStrictSources, "true");
    }

    // Set respect concurrent in flows
    if(respectConcurrentInflows)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersRespectConcurrentInflows, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersRespectConcurrentInflows, "false");
    }

    // Set Scale
    getProcessingParameters()->replace(dfRouterProcessingParametersScale, QString::number(scale));

    // Set parameter departLane
    getProcessingParameters()->replace(dfRouterProcessingParametersDepartlane, departlane);

    // Set parameter departPos
    getProcessingParameters()->replace(dfRouterProcessingParametersDepartpos, departpos);

    // Set parameter departSpeed
    getProcessingParameters()->replace(dfRouterProcessingParametersDepartspeed, departspeed);

    // Set parameter arrivalLane
    getProcessingParameters()->replace(dfRouterProcessingParametersArrivallane, arrivallane);

    // Set parameter arrivalPos
    getProcessingParameters()->replace(dfRouterProcessingParametersArrivalpos, arrivalpos);

    // Set parameter arrivalSpeed
    getProcessingParameters()->replace(dfRouterProcessingParametersArrivalspeed, arrivalspeed);

    // Set time begin
    getProcessingParameters()->replace(dfRouterProcessingParametersBegin, QString::number(begin));

    // Set time end
    getProcessingParameters()->replace(dfRouterProcessingParametersEnd, QString::number(end));

    // Set verbose
    if(verbose)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersVerbose, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersVerbose, "false");
    }

    // Set print options
    if(printOptions)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersPrintOptions, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersPrintOptions, "false");
    }

    // Set help
    if(help)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersHelp, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersHelp, "false");
    }

    // Set version
    if(version)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersVersion, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersVersion, "false");
    }

    // Set xmlValidation
    getProcessingParameters()->replace(dfRouterProcessingParametersXmlValidation, xmlValidation);

    // Set xmlValidationNet
    getProcessingParameters()->replace(dfRouterProcessingParametersXmlValidationNet, xmlValidationNet);

    // Set noWarnings
    if(noWarnings)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersNoWarnings, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersNoWarnings, "false");
    }

    // Set log
    getProcessingParameters()->replace(dfRouterProcessingParametersLog, log);

    // set MessageLog
    getProcessingParameters()->replace(dfRouterProcessingParametersMessageLog, messageLog);

    getProcessingParameters()->replace(dfRouterProcessingParametersErrorLog, errorLog);

    // Set reportEmptyDetectors
    if(reportEmptyDetectors)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersReportEmptyDetectors, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersReportEmptyDetectors, "false");
    }

    // Set printAbsoluteFlows
    if(printAbsoluteFlows)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersPrintAbsoluteFlows, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersPrintAbsoluteFlows, "false");
    }

    // Set noStepLog
    if(noStepLog)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersNoStepLog, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersNoStepLog, "false");
    }

    // Set Random
    if(random)
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersRandom, "true");
    }
    else
    {
        getProcessingParameters()->replace(dfRouterProcessingParametersRandom, "false");
    }

    // Set seed
    getProcessingParameters()->replace(dfRouterProcessingParametersSeed, QString::number(seed));
}

void dfRouterToolDialog::on_ButtonSearchDetectorFiles_released()
{
    /** ACABAR **/
}

void dfRouterToolDialog::on_ButtonSearchMeasureFiles_released()
{
    /** ACABAR **/
}

void dfRouterToolDialog::on_ButtonSearchSumoNetwork_released()
{
    /** ACABAR **/
}

void dfRouterToolDialog::on_TextDetectorFiles_textChanged()
{
    inputInductionLoopsE1DetectorFiles = ui->TextDetectorFiles->toPlainText();
}

void dfRouterToolDialog::on_TextMeasureFiles_textChanged()
{
    inputMeasureFiles = ui->TextMeasureFiles->toPlainText();
}

void dfRouterToolDialog::on_TextSumoNetwork_textChanged()
{
    inputNetFile = ui->TextSumoNetwork->toPlainText();
}

void dfRouterToolDialog::on_TextTimeBegin_textChanged()
{

}

void dfRouterToolDialog::on_TextTimeEnd_textChanged()
{

}

void dfRouterToolDialog::on_TextDisallowedEdges_textChanged()
{

}

void dfRouterToolDialog::on_TextMaxSearchDepth_textChanged()
{

}

void dfRouterToolDialog::on_TextMinRouteLenght_textChanged()
{

}

void dfRouterToolDialog::on_TextScale_textChanged()
{

}

void dfRouterToolDialog::on_TextTimeFactor_textChanged()
{

}

void dfRouterToolDialog::on_TextTimeOffset_textChanged()
{

}

void dfRouterToolDialog::on_TextTimeStep_textChanged()
{

}

void dfRouterToolDialog::on_ButtonSearchDetectorOutput_released()
{
    /** ACABAR **/
}

void dfRouterToolDialog::on_ButtonSearchDetectorsPoiOutput_released()
{
    /** ACABAR **/
}

void dfRouterToolDialog::on_ButtonSearchEmmitersOutput_released()
{
    /** ACABAR **/
}

void dfRouterToolDialog::on_ButtonSearchEmmitersPoiOutput_released()
{
    /** ACABAR **/
}

void dfRouterToolDialog::on_ButtonSearchEndRerouteOutput_released()
{
    /** ACABAR **/
}

void dfRouterToolDialog::on_ButtonValidationOutput_released()
{
    /** ACABAR **/
}

void dfRouterToolDialog::on_ButtonVariableSpdOutput_released()
{
    /** ACABAR **/
}

void dfRouterToolDialog::on_TextDetectorOutput_textChanged()
{

}

void dfRouterToolDialog::on_TextDetectorsPoiOutput_textChanged()
{

}

void dfRouterToolDialog::on_TextEmmitersOutput_textChanged()
{

}

void dfRouterToolDialog::on_TextEmmitersPoiOutput_textChanged()
{

}

void dfRouterToolDialog::on_TextEndRerouteOutput_textChanged()
{

}

void dfRouterToolDialog::on_TextRoutesOutput_textChanged()
{

}

void dfRouterToolDialog::on_TextValidationOutput_textChanged()
{

}

void dfRouterToolDialog::on_TextVariableSpdSignOutput_textChanged()
{

}

void dfRouterToolDialog::on_TextArrivalLane_textChanged()
{

}

void dfRouterToolDialog::on_TextArrivalPos_textChanged()
{

}

void dfRouterToolDialog::on_TextArrivalSpeed_textChanged()
{

}

void dfRouterToolDialog::on_TextDepartLane_textChanged()
{

}

void dfRouterToolDialog::on_TextDepartPos_textChanged()
{

}

void dfRouterToolDialog::on_TextDepartSpeed_textChanged()
{

}

void dfRouterToolDialog::on_TextSeed_textChanged()
{

}

void dfRouterToolDialog::on_ButtonAccept_released()
{
    // Set input parameters
    setInputParameters();

    // Set output parameters
    setOutputParameters();

    // Set processing parameters
    setProcessingParameters();

    // Close dialog
    close();

    // Export database
    getProject()->getDatabase()->exportDatabaseToXML();

    // Create directory for output
    QDir().mkpath(getProject()->getProjectPath() + "/" + geteNetEditorConfiguration()->getDfRouterConfiguration()->getOutputfolder());

    // Create configuration file for dfRouter
    dfRouterT->createSumoCfgFile(getProject());

    // Execute dfRoutet
    dfRouterT->startTool(getInputParameters(), getOutputParameters(), getProcessingParameters());
}

void dfRouterToolDialog::on_ButtonCancel_released()
{
    // Close dialog
    close();
}

void dfRouterToolDialog::on_ButtonReset_released()
{
    // Reset all parameters of tool
    resetParameters();

    // Update all widgets
    updateParameters();
}

void dfRouterToolDialog::on_CheckBoxRandom_toggled(bool checked)
{
    random = checked;
}

void dfRouterToolDialog::on_ButtonSearchErrorLog_released()
{
    /** ACABAR **/
}

void dfRouterToolDialog::on_ButtonSearchLog_released()
{
    /** ACABAR **/
}

void dfRouterToolDialog::on_ButtonSearchMessageLog_released()
{
    /** ACABAR **/
}

void dfRouterToolDialog::on_ComboBoxXmlValidation_currentTextChanged(const QString &arg1)
{
    xmlValidation = arg1;
}

void dfRouterToolDialog::on_ComboBoxXmlValidationNet_currentTextChanged(const QString &arg1)
{
    xmlValidationNet = arg1;
}

void dfRouterToolDialog::on_TextErrorLog_textChanged()
{
    errorLog = ui->TextErrorLog->toPlainText();
}

void dfRouterToolDialog::on_TextLog_textChanged()
{
    log = ui->TextLog->toPlainText();
}

void dfRouterToolDialog::on_TextMessageLog_textChanged()
{
    messageLog = ui->TextMessageLog->toPlainText();
}

void dfRouterToolDialog::on_CheckBoxHelp_toggled(bool checked)
{
    help = checked;
}

void dfRouterToolDialog::on_CheckBoxNoStepLog_toggled(bool checked)
{
    noStepLog = checked;
}

void dfRouterToolDialog::on_CheckBoxNoWarnings_toggled(bool checked)
{
    noWarnings = checked;
}

void dfRouterToolDialog::on_CheckBoxPrintAbsoluteLogs_toggled(bool checked)
{
    printAbsoluteFlows = checked;
}

void dfRouterToolDialog::on_CheckBoxPrintOptions_toggled(bool checked)
{
    printOptions = checked;
}

void dfRouterToolDialog::on_CheckBoxReportEmptyDetectors_toggled(bool checked)
{
    reportEmptyDetectors = checked;
}

void dfRouterToolDialog::on_CheckBoxVerbose_toggled(bool checked)
{
    verbose = checked;
}

void dfRouterToolDialog::on_CheckBoxVersion_toggled(bool checked)
{
    version = checked;
}

void dfRouterToolDialog::on_ButtonRoutesOutput_released()
{
    /** terminar **/
}

void dfRouterToolDialog::on_CheckBoxRoutesForAll_toggled(bool checked)
{
    outputRoutesForAll = checked;
}

void dfRouterToolDialog::on_CheckBoxVType_toggled(bool checked)
{
    outputVtype = checked;
}

void dfRouterToolDialog::on_CheckBoxValidationOutputAddSource_toggled(bool checked)
{
    outputValidationAddSources = checked;
}

void dfRouterToolDialog::on_CheckBoxCalibratorOutput_toggled(bool checked)
{
    calibratorOutput = checked;
}

void dfRouterToolDialog::on_CheckBoxEmissionsOnly_toggled(bool checked)
{
    emissionsOnly = checked;
}

void dfRouterToolDialog::on_CheckBoxGuessEmptyFlows_toggled(bool checked)
{
    guessEmptyFlows = checked;
}

void dfRouterToolDialog::on_CheckBoxHighwayMode_toggled(bool checked)
{
    highwayMode = checked;
}

void dfRouterToolDialog::on_CheckBoxIgnoreInvalidDetectors_toggled(bool checked)
{
    ignoreInvalidDetectors = checked;
}

void dfRouterToolDialog::on_CheckBoxIncludeUnusedRoutes_toggled(bool checked)
{
    includeUnusedRoutes = checked;
}

void dfRouterToolDialog::on_CheckBoxKeepLongerRoutes_toggled(bool checked)
{
    keepLongerRoutes = checked;
}

void dfRouterToolDialog::on_CheckBoxKeepUnfinishedRoutes_toggled(bool checked)
{
    keepUnfinishedRoutes = checked;
}

void dfRouterToolDialog::on_CheckBoxKeepturnAorunds_toggled(bool checked)
{
    keepTurnarounds = checked;
}

void dfRouterToolDialog::on_CheckBoxRemoveEmptyDetectors_toggled(bool checked)
{
    removeEmptyDetectors = checked;
}

void dfRouterToolDialog::on_CheckBoxRespectConcurrenceInflows_toggled(bool checked)
{
    respectConcurrentInflows = checked;
}

void dfRouterToolDialog::on_CheckBoxRevalidateDetectors_toggled(bool checked)
{
    revalidateDetectors = checked;
}

void dfRouterToolDialog::on_CheckBoxRevalidateFlows_toggled(bool checked)
{
    revalidateFlows = checked;
}

void dfRouterToolDialog::on_CheckBoxRevalidateRoutes_toggled(bool checked)
{
    revalidateRoutes = checked;
}

void dfRouterToolDialog::on_CheckBoxStrictSources_toggled(bool checked)
{
    strictSources = checked;
}
