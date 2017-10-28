#include "netConvertToolDialog.h"
#include "ui_netConvertToolDialog.h"

// Project
#include "../../project/eNetEditorProject.h"

// Database
#include "../../database/eNetEditorDatabase.h"

// Tools
#include "../../tools/netConvertTool.h"

// Traffic Light parse
#include "../../parsing/trafficLightParsing.h"

// netEditorConfigurationDialog
#include "../main/eNetEditorConfigurationDialog.h"

// Messages manager
#include "../../main/eNetEditorMessages.h"

// eNetEditor configuration
#include "../../configuration/main/eNetEditorMainConfiguration.h"
#include "../../configuration/tools/netConvertToolConfiguration.h"
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/nodeItemConfiguration.h"
#include "../../configuration/items/edges/edgeItemConfiguration.h"
#include "../../configuration/items/edges/edgeTypeItemConfiguration.h"
#include "../../configuration/items/connectionItemConfiguration.h"
#include "../../configuration/items/trafficLightItemConfiguration.h"


netConvertToolDialog::netConvertToolDialog(eNetEditorMainWindow *neweNetEditorMainW) : eNetEditorToolDialog(neweNetEditorMainW), ui(new Ui::netConvertToolDialog)
{
    // Set UI
    ui->setupUi(this);

    // Create traffic light converter
    tlConverter = new trafficLightConverter(getMessages());

    // Create tool
    netConvertT = new netConvertTool(getMessages(), geteNetEditorConfiguration(), this);

    // Set size of Parameters vectors
    getInputParameters()->fill("", geteNetEditorConfiguration()->getNetConvertConfiguration()->getNumberOfInputParameters());
    getOutputParameters()->fill("", geteNetEditorConfiguration()->getNetConvertConfiguration()->getNumberOfOutputParameters());
    getProcessingParameters()->fill("", geteNetEditorConfiguration()->getNetConvertConfiguration()->getNumberOfProcessingParameters());

    //Connect output
    connect(netConvertT, SIGNAL(readyReadStandardOutput()), this, SLOT(writeNetConvertProcessingMessage()));
}

netConvertToolDialog::~netConvertToolDialog()
{
    // delete UI
    delete ui;

    // Delete tool
    delete netConvertT;

    // Delete traffic light converter
    delete tlConverter;
}

void netConvertToolDialog::openDialog(eNetEditorProject *newProject)
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

void netConvertToolDialog::resetParameters()
{
    // Input parameters

    SumoNetFile = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultSumoNetFile();

    NodeFiles = getProject()->getProjectPath() + "/" + getProject()->getProjectName() + "." + getProject()->getProjectConfiguration()->getNodeItemConfiguration()->getItemFileNameWithExtension();

    EdgeFiles = getProject()->getProjectPath() + "/" + getProject()->getProjectName() + "." + getProject()->getProjectConfiguration()->getEdgeItemConfiguration()->getItemFileNameWithExtension();

    ConnectionFiles = getProject()->getProjectPath() + "/" + getProject()->getProjectName() + "." + getProject()->getProjectConfiguration()->getConnectionItemConfiguration()->getItemFileNameWithExtension();

    TllogicFiles = getProject()->getProjectPath() + "/" + getProject()->getProjectName() + "." + getProject()->getProjectConfiguration()->getTrafficLightItemConfiguration()->getItemFileNameWithExtension();

    TypeFiles = getProject()->getProjectPath() + "/" + getProject()->getProjectName() + "." + getProject()->getProjectConfiguration()->getEdgeTypeItemConfiguration()->getItemFileNameWithExtension();

    OsmFiles = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultOsmFiles();

    OpendriveFiles = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultOpendriveFiles();

    VisumFile = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultVisumFile();

    VissimFile = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultVissimFile();

    RobocupDir = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultRobocupDir();

    MatsimFiles = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultMatsimFiles();

    ItsumoFiles = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultItsumoFiles();

    HeightmapShapefiles = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultHeightmapShapefiles();

    HeightmapGeotiff = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultHeightmapGeotiff();


    // Output parameters

    OutputFile = getProject()->getProjectPath() + "/" + geteNetEditorConfiguration()->getNetConvertConfiguration()->getOutputfolder() + "/" + getProject()->getProjectName() + "." + geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultOutputFile();

    JunctionsJoinOutput = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultJunctionsJoinOutput();

    AmitranOutput = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultAmitranOutput();

    MatsimOutput = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultMatsimOutput();

    OpendriveOutput = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultOpendriveOutput();

    DlrNavteqOutput = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultDlrNavteqOutput();

    OutputStreetNames = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultOutputStreetNames();

    OutputOriginalNames = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultOutputOriginalNames();

    StreetSignOutput = geteNetEditorConfiguration()->getNetConvertConfiguration()->getNetConvertDefaultStreetSignOutput();

    // Processing parameters

    SimpleProjection;

    ProjScale;

    ProjUtm;

    ProjDhdn;

    Proj;

    ProjInverse;

    ProjDhdnutm;

    ProjPlainGeo;

    TlsDiscardLoaded;

    TlsDiscardSimple;

    TlsSet;

    TlsUnset;

    TlsGuess;

    TlsTazNodes;

    TlsGuessJoining;

    TlsJoin;

    TlsGreenTime;

    TlsYellowMinDecel;

    TlsYellowPatchSmall;

    TlsYellowTime;

    TlsHalfOffset;

    TlsQuarterOffset;

    TlsDefaultType;

    RampsGuess;

    RampsMaxRampSpeed;

    RampsMinHighwaySpeed;

    RampsRampLength;

    RampsSet;

    RampsNoSplit;

    KeepEdgesMinSpeed;

    RemoveEdgesExplicit;

    KeepEdgesExplicit;

    KeepEdgesInputFile;

    KeepEdgesPostload;

    KeepEdgesInBoundary;

    KeepEdgesInGeoBoundary;

    KeepEdgesByVclass;

    RemoveEdgesByVclass;

    KeepEdgesByType;

    RemoveEdgesByType;

    RemoveEdgesIsolated;

    KeepNodesUnregulated;

    KeepNodesUnregulatedExplicit;

    KeepNodesUnregulatedDistrictNodes;

    IgnoreErrors;

    IgnoreErrorsConnections;

    ShowErrorsConnectionsFirstTry;

    IgnoreErrorsEdgeType;

    LanesFromCapacityNorm;

    SpeedInKmh;

    PlainExtendEdgeShape;

    MatsimKeepLength;

    MatsimLanesFromCapacity;

    ShapefileStreetId;

    ShapefileFromId;

    ShapefileToId;

    ShapefileTypeId;

    ShapefileUseDefaultsOnFailure;

    ShapefileAllBidirectional;

    ShapefileGuessProjection;

    VissimJoinDistance;

    VissimDefaultSpeed;

    VissimSpeedNorm;

    VissimReportUnsetSpeeds;

    VisumUseTypePriority;

    VisumUseTypeLaneno;

    VisumUseTypeSpeed;

    VisumConnectorSpeeds;

    VisumConnectorsLaneNumber;

    VisumNoConnectors;

    VisumRecomputeLaneNumber;

    VisumVerboseWarnings;

    OsmSkipDuplicatesCheck;

    OsmRailwayOnewayDefault;

    OsmElevation;

    OpendriveImportAllLanes;

    OpendriveIgnoreWidths;

    NoInternalLinks;

    DismissVclasses;

    NoTurnarounds;

    NoTurnaroundsTls;

    NoLeftConnections;

    GeometrySplit;

    GeometryRemove;

    GeometryMaxSegmentLength;

    GeometryMinDist;

    GeometryMaxAngle;

    GeometryMinRadius;

    GeometryMinRadiusFix;

    GeometryJunctionMismatchThreshold;

    OffsetDisableNormalization;

    OffsetX;

    OffsetY;

    FlipYAxis;

    RoundaboutsGuess;

    Lefthand;

    JunctionsJoin;

    JunctionsJoinDist;

    JunctionsJoinExclude;

    SpeedOffset;

    SpeedFactor;

    JunctionsCornerDetail;

    CheckLaneFoesRoundabout;

    CheckLaneFoesAll;

    SidewalksGuess;

    SidewalksGuessMaxSpeed;

    SidewalksGuessMinSpeed;

    SidewalksGuessFromPermissions;

    CrossingsGuess;

    TlsJoinDist;

    TlsGuessSignals;

    TlsGuessSignalsDist;

    DefaultLanenumber;

    DefaultSpeed;

    DefaultPriority;

    DefaultSidewalkWidth;

    Verbose;

    PrintOptions;

    Help;

    Version;

    xmlValidation;

    NoWarnings;

    Log;

    MessageLog;

    ErrorLog;

    Random;

    Seed;
}

void netConvertToolDialog::updateParameters()
{
    // Input parameters

    ui->TextSumoNetFile->setText(SumoNetFile);

    ui->TextNodes->setText(NodeFiles);

    ui->TextEdges->setText(EdgeFiles);

    ui->TextConnections->setText(ConnectionFiles);

    ui->TextTrafficLights->setText(TllogicFiles);

    ui->TextTypeFile->setText(TypeFiles);

    ui->TextOsmFile->setText(OsmFiles);

    ui->TextOpenDriveFile->setText(OpendriveFiles);

    ui->TextVisumFile->setText(VisumFile);

    ui->TextVissimFile->setText(VissimFile);

    ui->TextRobocupDir->setText(RobocupDir);

    ui->TextMatsimFile->setText(MatsimFiles);

    ui->TextItsumoFile->setText(ItsumoFiles);

    ui->TextHeightmapShapeFile->setText(HeightmapShapefiles);

    ui->TextHeightmapGeotiffFile->setText(HeightmapGeotiff);


    // Output parameters

    OutputFile;

    JunctionsJoinOutput;

    AmitranOutput;

    MatsimOutput;

    OpendriveOutput;

    DlrNavteqOutput;

    OutputStreetNames;

    OutputOriginalNames;

    StreetSignOutput;

    // Processing parameters

    SimpleProjection;

    ProjScale;

    ProjUtm;

    ProjDhdn;

    Proj;

    ProjInverse;

    ProjDhdnutm;

    ProjPlainGeo;

    TlsDiscardLoaded;

    TlsDiscardSimple;

    TlsSet;

    TlsUnset;

    TlsGuess;

    TlsTazNodes;

    TlsGuessJoining;

    TlsJoin;

    TlsGreenTime;

    TlsYellowMinDecel;

    TlsYellowPatchSmall;

    TlsYellowTime;

    TlsHalfOffset;

    TlsQuarterOffset;

    TlsDefaultType;

    RampsGuess;

    RampsMaxRampSpeed;

    RampsMinHighwaySpeed;

    RampsRampLength;

    RampsSet;

    RampsNoSplit;

    KeepEdgesMinSpeed;

    RemoveEdgesExplicit;

    KeepEdgesExplicit;

    KeepEdgesInputFile;

    KeepEdgesPostload;

    KeepEdgesInBoundary;

    KeepEdgesInGeoBoundary;

    KeepEdgesByVclass;

    RemoveEdgesByVclass;

    KeepEdgesByType;

    RemoveEdgesByType;

    RemoveEdgesIsolated;

    KeepNodesUnregulated;

    KeepNodesUnregulatedExplicit;

    KeepNodesUnregulatedDistrictNodes;

    IgnoreErrors;

    IgnoreErrorsConnections;

    ShowErrorsConnectionsFirstTry;

    IgnoreErrorsEdgeType;

    LanesFromCapacityNorm;

    SpeedInKmh;

    PlainExtendEdgeShape;

    MatsimKeepLength;

    MatsimLanesFromCapacity;

    ShapefileStreetId;

    ShapefileFromId;

    ShapefileToId;

    ShapefileTypeId;

    ShapefileUseDefaultsOnFailure;

    ShapefileAllBidirectional;

    ShapefileGuessProjection;

    VissimJoinDistance;

    VissimDefaultSpeed;

    VissimSpeedNorm;

    VissimReportUnsetSpeeds;

    VisumUseTypePriority;

    VisumUseTypeLaneno;

    VisumUseTypeSpeed;

    VisumConnectorSpeeds;

    VisumConnectorsLaneNumber;

    VisumNoConnectors;

    VisumRecomputeLaneNumber;

    VisumVerboseWarnings;

    OsmSkipDuplicatesCheck;

    OsmRailwayOnewayDefault;

    OsmElevation;

    OpendriveImportAllLanes;

    OpendriveIgnoreWidths;

    NoInternalLinks;

    DismissVclasses;

    NoTurnarounds;

    NoTurnaroundsTls;

    NoLeftConnections;

    GeometrySplit;

    GeometryRemove;

    GeometryMaxSegmentLength;

    GeometryMinDist;

    GeometryMaxAngle;

    GeometryMinRadius;

    GeometryMinRadiusFix;

    GeometryJunctionMismatchThreshold;

    OffsetDisableNormalization;

    OffsetX;

    OffsetY;

    FlipYAxis;

    RoundaboutsGuess;

    Lefthand;

    JunctionsJoin;

    JunctionsJoinDist;

    JunctionsJoinExclude;

    SpeedOffset;

    SpeedFactor;

    JunctionsCornerDetail;

    CheckLaneFoesRoundabout;

    CheckLaneFoesAll;

    SidewalksGuess;

    SidewalksGuessMaxSpeed;

    SidewalksGuessMinSpeed;

    SidewalksGuessFromPermissions;

    CrossingsGuess;

    TlsJoinDist;

    TlsGuessSignals;

    TlsGuessSignalsDist;

    DefaultLanenumber;

    DefaultSpeed;

    DefaultPriority;

    DefaultSidewalkWidth;

    Verbose;

    PrintOptions;

    Help;

    Version;

    xmlValidation;

    NoWarnings;

    Log;

    MessageLog;

    ErrorLog;

    Random;

    Seed;
}

void netConvertToolDialog::on_ButtonAccept_released()
{
    //Close dialog
    close();

    // Set input parameters
    getInputParameters()->replace(netConvertInputParameterNodeFiles, NodeFiles);
    getInputParameters()->replace(netConvertInputParameterEdgeFiles, EdgeFiles);
    getInputParameters()->replace(netConvertInputParameterConnectionFiles, ConnectionFiles);
    getInputParameters()->replace(netConvertInputParameterTllogicFiles, TllogicFiles);

    // Set output parameters
    getOutputParameters()->replace(netConvertOutputParameterOutputFile, OutputFile);

    // Create directory for output
    QDir().mkpath(getProject()->getProjectPath() + "/" + geteNetEditorConfiguration()->getNetConvertConfiguration()->getOutputfolder());

    // Export database to SUMO Format
    if(getProject()->getDatabase()->exportDatabaseToXML())
    {
        // If the execution of netConvert is sucesfully
        if(netConvertT->startTool(getInputParameters(), getOutputParameters(), getProcessingParameters()) == true)
        {
            // Create cfg file for netConvert
            netConvertT->createSumoCfgFile(getProject());

            //Inf parse traffic Light checkBox is checked
            if(ui->CheckBoxParseTrafficLights->isChecked())
            {
                // Parse Traffic Lights using generated Net
                //if(tlConverter->parseTrafficLights(database, netFilePath, trafficLightFilePath))
                {
                    // Repeat execution With the new traffic lights
                    if(netConvertT->startTool(getInputParameters(), getOutputParameters(), getProcessingParameters()) == true)
                    {
                        // If all container were sucessfully exported, show a information message
                        QMessageBox::information(0, ("Export"), ("Export to SUMO format,execution of NetConverter and parsing of Traffic Ligths sucesfully.\n"), QMessageBox::Ok);
                    }
                    else
                    {
                        // Write processing Error
                        getMessages()->processingError();
                    }
                }
                //else
                {
                    // Finished Process
                    getMessages()->processingError();
                }
            }
            else
            {
                // If all container were sucessfully exported, show a information message
                QMessageBox::information(0, ("Export"), ("Export to SUMO format and execution of NetConverter sucesfully.\n"), QMessageBox::Ok);
            }
        }
        else
        {
            // Error in the execution of net convert
            QMessageBox::critical(0, ("Export"), ("Error in the execution of NetConverter.\nSee Console Log for more details.\n"), QMessageBox::Ok);
        }
    }
}

void netConvertToolDialog::on_ButtonCancel_released()
{
    // Close dialog
    close();
}

void netConvertToolDialog::on_ButtonSearchConnectionsFile_released()
{
    // Open search Dialog
    QString newConnections = QFileDialog::getOpenFileName(
                                 this,
                                 "Open Connections XML",
                                 qApp->applicationDirPath() ,
                                 tr("connections (*.connections.xml)" )
                             );
}

void netConvertToolDialog::on_ButtonSearchEdgesfile_released()
{
    // Open search Dialog
    QString newEdge = QFileDialog::getOpenFileName(
                          this,
                          "Open Edge XML",
                          qApp->applicationDirPath() ,
                          tr("edges (*.edges.xml)" )
                      );
}

void netConvertToolDialog::on_ButtonSearchNodesFile_released()
{
    // Open search Dialog
    QString newNodes = QFileDialog::getOpenFileName(
                           this,
                           "Open Nodes XML",
                           qApp->applicationDirPath() ,
                           tr("nodes (*.nodes.xml)" )
                       );
}



void netConvertToolDialog::on_ButtonSearchTrafficLightsFile_released()
{
    // Open search Dialog
    QString newTrafficLights = QFileDialog::getOpenFileName(
                                   this,
                                   "Open Traffic Lights XML",
                                   qApp->applicationDirPath() ,
                                   tr("traffic lights (*.trafficLights.xml)" )
                               );
}

void netConvertToolDialog::on_ButtonReset_released()
{
    // Reset all parameters of tool
    resetParameters();

    // Update all widgets
    updateParameters();
}

void netConvertToolDialog::writeNetConvertProcessingMessage()
{
    getMessages()->toolMessage("NetConvert", netConvertT->readAllStandardOutput());
}

void netConvertToolDialog::on_TextSumoNetFile_textChanged()
{

}

void netConvertToolDialog::on_ButtonSearchSumoNetFile_released()
{

}

void netConvertToolDialog::on_TextTypeFile_textChanged()
{

}

void netConvertToolDialog::on_ButtonSearchTypeFile_released()
{

}

void netConvertToolDialog::on_ButtonSearchHeightmapGeotiffFile_released()
{

}

void netConvertToolDialog::on_ButtonSearchHeightmapShapeFile_released()
{

}

void netConvertToolDialog::on_ButtonSearchItsumoFile_released()
{

}

void netConvertToolDialog::on_ButtonSearchMatsimFile_released()
{

}

void netConvertToolDialog::on_ButtonSearchOpenDriveFile_released()
{

}

void netConvertToolDialog::on_ButtonSearchOsmFile_released()
{

}

void netConvertToolDialog::on_ButtonSearchRobocupDir_released()
{

}

void netConvertToolDialog::on_ButtonSearchVissimFile_released()
{

}

void netConvertToolDialog::on_ButtonSearchVisumFile_released()
{

}

void netConvertToolDialog::on_TextHeightmapGeotiffFile_textChanged()
{

}

void netConvertToolDialog::on_TextHeightmapShapeFile_textChanged()
{

}

void netConvertToolDialog::on_TextItsumoFile_textChanged()
{

}

void netConvertToolDialog::on_TextMatsimFile_textChanged()
{

}

void netConvertToolDialog::on_TextOpenDriveFile_textChanged()
{

}

void netConvertToolDialog::on_TextOsmFile_textChanged()
{

}

void netConvertToolDialog::on_TextRobocupDir_textChanged()
{

}

void netConvertToolDialog::on_TextVissimFile_textChanged()
{

}

void netConvertToolDialog::on_TextVisumFile_textChanged()
{

}
