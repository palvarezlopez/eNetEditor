#ifndef NETCONVERTTOOL_H
#define NETCONVERTTOOL_H

#include "eNetEditorTool.h"


// Declare enum netConvertInputParameters
enum netConvertInputParameters
{
    netConvertInputParameterSumoNetFile,
    netConvertInputParameterNodeFiles,
    netConvertInputParameterEdgeFiles,
    netConvertInputParameterConnectionFiles,
    netConvertInputParameterTllogicFiles,
    netConvertInputParameterTypeFiles,
    netConvertInputParameterShapefilePrefix,
    netConvertInputParameterDlrNavteqPrefix,
    netConvertInputParameterOsmFiles,
    netConvertInputParameterOpendriveFiles,
    netConvertInputParameterVisumFile,
    netConvertInputParameterVissimFile,
    netConvertInputParameterRobocupDir,
    netConvertInputParameterMatsimFiles,
    netConvertInputParameterItsumoFiles,
    netConvertInputParameterHeightmapShapefiles,
    netConvertInputParameterHeightmapGeotiff,
};

// Declare enum netConvertOutputParameters
enum netConvertOutputParameters
{
    netConvertOutputParameterOutputPrefix,
    netConvertOutputParameterOutputFile,
    netConvertOutputParameterPlainOutputPrefix,
    netConvertOutputParameterJunctionsJoinOutput,
    netConvertOutputParameterAmitranOutput,
    netConvertOutputParameterMatsimOutput,
    netConvertOutputParameterOpendriveOutput,
    netConvertOutputParameterDlrNavteqOutput,
    netConvertOutputParameterOutputStreetNames,
    netConvertOutputParameterOutputOriginalNames,
    netConvertOutputParameterStreetSignOutput,
};

// Declare enum netConvertProcessingsParameters
enum netConvertProcessingsParameters
{
    netConvertProcessingParameterSimpleProjection,
    netConvertProcessingParameterProjScale,
    netConvertProcessingParameterProjUtm,
    netConvertProcessingParameterProjDhdn,
    netConvertProcessingParameterProj,
    netConvertProcessingParameterProjInverse,
    netConvertProcessingParameterProjDhdnutm,
    netConvertProcessingParameterProjPlainGeo,
    netConvertProcessingParameterTlsDiscardLoaded,
    netConvertProcessingParameterTlsDiscardSimple,
    netConvertProcessingParameterTlsSet,
    netConvertProcessingParameterTlsUnset,
    netConvertProcessingParameterTlsGuess,
    netConvertProcessingParameterTlsTazNodes,
    netConvertProcessingParameterTlsGuessJoining,
    netConvertProcessingParameterTlsJoin,
    netConvertProcessingParameterTlsGreenTime,
    netConvertProcessingParameterTlsYellowMinDecel,
    netConvertProcessingParameterTlsYellowPatchSmall,
    netConvertProcessingParameterTlsYellowTime,
    netConvertProcessingParameterTlsHalfOffset,
    netConvertProcessingParameterTlsQuarterOffset,
    netConvertProcessingParameterTlsProcessingType,
    netConvertProcessingParameterRampsGuess,
    netConvertProcessingParameterRampsMaxRampSpeed,
    netConvertProcessingParameterRampsMinHighwaySpeed,
    netConvertProcessingParameterRampsRampLength,
    netConvertProcessingParameterRampsSet,
    netConvertProcessingParameterRampsNoSplit,
    netConvertProcessingParameterKeepEdgesMinSpeed,
    netConvertProcessingParameterRemoveEdgesExplicit,
    netConvertProcessingParameterKeepEdgesExplicit,
    netConvertProcessingParameterKeepEdgesInputFile,
    netConvertProcessingParameterKeepEdgesPostload,
    netConvertProcessingParameterKeepEdgesInBoundary,
    netConvertProcessingParameterKeepEdgesInGeoBoundary,
    netConvertProcessingParameterKeepEdgesByVclass,
    netConvertProcessingParameterRemoveEdgesByVclass,
    netConvertProcessingParameterKeepEdgesByType,
    netConvertProcessingParameterRemoveEdgesByType,
    netConvertProcessingParameterRemoveEdgesIsolated,
    netConvertProcessingParameterKeepNodesUnregulated,
    netConvertProcessingParameterKeepNodesUnregulatedExplicit,
    netConvertProcessingParameterKeepNodesUnregulatedDistrictNodes,
    netConvertProcessingParameterIgnoreErrors,
    netConvertProcessingParameterIgnoreErrorsConnections,
    netConvertProcessingParameterShowErrorsConnectionsFirstTry,
    netConvertProcessingParameterIgnoreErrorsEdgeType,
    netConvertProcessingParameterLanesFromCapacityNorm,
    netConvertProcessingParameterSpeedInKmh,
    netConvertProcessingParameterPlainExtendEdgeShape,
    netConvertProcessingParameterMatsimKeepLength,
    netConvertProcessingParameterMatsimLanesFromCapacity,
    netConvertProcessingParameterShapefileStreetId,
    netConvertProcessingParameterShapefileFromId,
    netConvertProcessingParameterShapefileToId,
    netConvertProcessingParameterShapefileTypeId,
    netConvertProcessingParameterShapefileUseProcessingsOnFailure,
    netConvertProcessingParameterShapefileAllBidirectional,
    netConvertProcessingParameterShapefileGuessProjection,
    netConvertProcessingParameterVissimJoinDistance,
    netConvertProcessingParameterVissimProcessingSpeed,
    netConvertProcessingParameterVissimSpeedNorm,
    netConvertProcessingParameterVissimReportUnsetSpeeds,
    netConvertProcessingParameterVisumUseTypePriority,
    netConvertProcessingParameterVisumUseTypeLaneno,
    netConvertProcessingParameterVisumUseTypeSpeed,
    netConvertProcessingParameterVisumConnectorSpeeds,
    netConvertProcessingParameterVisumConnectorsLaneNumber,
    netConvertProcessingParameterVisumNoConnectors,
    netConvertProcessingParameterVisumRecomputeLaneNumber,
    netConvertProcessingParameterVisumVerboseWarnings,
    netConvertProcessingParameterOsmSkipDuplicatesCheck,
    netConvertProcessingParameterOsmRailwayOnewayProcessing,
    netConvertProcessingParameterOsmElevation,
    netConvertProcessingParameterOpendriveImportAllLanes,
    netConvertProcessingParameterOpendriveIgnoreWidths,
    netConvertProcessingParameterNoInternalLinks,
    netConvertProcessingParameterDismissVclasses,
    netConvertProcessingParameterNoTurnarounds,
    netConvertProcessingParameterNoTurnaroundsTls,
    netConvertProcessingParameterNoLeftConnections,
    netConvertProcessingParameterGeometrySplit,
    netConvertProcessingParameterGeometryRemove,
    netConvertProcessingParameterGeometryMaxSegmentLength,
    netConvertProcessingParameterGeometryMinDist,
    netConvertProcessingParameterGeometryMaxAngle,
    netConvertProcessingParameterGeometryMinRadius,
    netConvertProcessingParameterGeometryMinRadiusFix,
    netConvertProcessingParameterGeometryJunctionMismatchThreshold,
    netConvertProcessingParameterOffsetDisableNormalization,
    netConvertProcessingParameterOffsetX,
    netConvertProcessingParameterOffsetY,
    netConvertProcessingParameterFlipYAxis,
    netConvertProcessingParameterRoundaboutsGuess,
    netConvertProcessingParameterLefthand,
    netConvertProcessingParameterJunctionsJoin,
    netConvertProcessingParameterJunctionsJoinDist,
    netConvertProcessingParameterJunctionsJoinExclude,
    netConvertProcessingParameterSpeedOffset,
    netConvertProcessingParameterSpeedFactor,
    netConvertProcessingParameterJunctionsCornerDetail,
    netConvertProcessingParameterCheckLaneFoesRoundabout,
    netConvertProcessingParameterCheckLaneFoesAll,
    netConvertProcessingParameterSidewalksGuess,
    netConvertProcessingParameterSidewalksGuessMaxSpeed,
    netConvertProcessingParameterSidewalksGuessMinSpeed,
    netConvertProcessingParameterSidewalksGuessFromPermissions,
    netConvertProcessingParameterCrossingsGuess,
    netConvertProcessingParameterTlsJoinDist,
    netConvertProcessingParameterTlsGuessSignals,
    netConvertProcessingParameterTlsGuessSignalsDist,
    netConvertProcessingParameterProcessingLanenumber,
    netConvertProcessingParameterProcessingSpeed,
    netConvertProcessingParameterProcessingPriority,
    netConvertProcessingParameterProcessingSidewalkWidth,
    netConvertProcessingParameterVerbose,
    netConvertProcessingParameterPrintOptions,
    netConvertProcessingParameterHelp,
    netConvertProcessingParameterVersion,
    netConvertProcessingParameterxmlValidation,
    netConvertProcessingParameterNoWarnings,
    netConvertProcessingParameterLog,
    netConvertProcessingParameterMessageLog,
    netConvertProcessingParameterErrorLog,
    netConvertProcessingParameterRandom,
    netConvertProcessingParameterSeed,
};



class netConvertTool : public eNetEditorTool
{
public:

    netConvertTool(eNetEditorMessages *newMessages, eNetEditorMainConfiguration *neweNetEditorC, QObject *parent);


public slots:

    bool createSumoCfgFile(eNetEditorProject *project);

    bool startTool(QVector<QString> *inputParameters, QVector<QString> *outputParameters, QVector<QString> *processingParameters);


private slots:


    void setInputParameters(QVector<QString> *inputParameters);

    void setOutputParameters(QVector<QString> *outputParameters);

    void setProcessingParameters(QVector<QString> *processingParameters);
};

#endif // NETCONVERT_H
