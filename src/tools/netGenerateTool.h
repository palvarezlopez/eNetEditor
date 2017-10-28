#ifndef NETGENERATETOOL_H
#define NETGENERATETOOL_H

#include "eNetEditorTool.h"


// Declare enum netGenerateInputParameters
enum netGenerateInputParameters
{
    netGenerateInputParameterGrid,
    netGenerateInputParameterGridNumber,
    netGenerateInputParameterGridLength,
    netGenerateInputParameterGridXNumber,
    netGenerateInputParameterGridYNumber,
    netGenerateInputParameterGridXLength,
    netGenerateInputParameterGridYLength,
    netGenerateInputParameterGridAttachLength,
    netGenerateInputParameterSpider,
    netGenerateInputParameterSpiderArmNumber,
    netGenerateInputParameterSpiderCircleNumber,
    netGenerateInputParameterSpiderSpaceRadius,
    netGenerateInputParameterSpiderOmitCenter,
    netGenerateInputParameterRand,
    netGenerateInputParameterRandIterations,
    netGenerateInputParameterRandBidiProbability,
    netGenerateInputParameterRandMaxDistance,
    netGenerateInputParameterRandMinDistance,
    netGenerateInputParameterRandMinAngle,
    netGenerateInputParameterRandNumTries,
    netGenerateInputParameterRandConnectivity,
    netGenerateInputParameterRandNeighborDist1,
    netGenerateInputParameterRandNeighborDist2,
    netGenerateInputParameterRandNeighborDist3,
    netGenerateInputParameterRandNeighborDist4,
    netGenerateInputParameterRandNeighborDist5,
    netGenerateInputParameterRandNeighborDist6,
};

// Declare enum netGenerateOutputParameters
enum netGenerateOutputParameters
{
    netGenerateOutputParameterOutputPrefix,
    netGenerateOutputParameterOutputFile,
    netGenerateOutputParameterPlainOutputPrefix,
    netGenerateOutputParameterJunctionsJoinOutput,
    netGenerateOutputParameterAmitranOutput,
    netGenerateOutputParameterMatsimOutput,
    netGenerateOutputParameterOpendriveOutput,
    netGenerateOutputParameterDlrNavteqOutput,
    netGenerateOutputParameterOutputStreetNames,
    netGenerateOutputParameterOutputOriginalNames,
    netGenerateOutputParameterStreetSignOutput,
};

// Declare enum netGenerateProcessingParameters
enum netGenerateProcessingParameters
{
    netGenerateProcessingParameterTlsSet,
    netGenerateProcessingParameterTlsUnset,
    netGenerateProcessingParameterTlsGuess,
    netGenerateProcessingParameterTlsGuessJoining,
    netGenerateProcessingParameterTlsJoin,
    netGenerateProcessingParameterTlsGreenTime,
    netGenerateProcessingParameterTlsYellowMinDecel,
    netGenerateProcessingParameterTlsYellowPatchSmall,
    netGenerateProcessingParameterTlsYellowTime,
    netGenerateProcessingParameterTlsHalfOffset,
    netGenerateProcessingParameterTlsQuarterOffset,
    netGenerateProcessingParameterTlsProcessingParameterType,
    netGenerateProcessingParameterKeepEdgesMinSpeed,
    netGenerateProcessingParameterRemoveEdgesExplicit,
    netGenerateProcessingParameterKeepEdgesExplicit,
    netGenerateProcessingParameterKeepEdgesInputFile,
    netGenerateProcessingParameterKeepEdgesInBoundary,
    netGenerateProcessingParameterKeepEdgesInGeoBoundary,
    netGenerateProcessingParameterKeepNodesUnregulated,
    netGenerateProcessingParameterKeepNodesUnregulatedExplicit,
    netGenerateProcessingParameterKeepNodesUnregulatedDistrictNodes,
    netGenerateProcessingParameterNoInternalLinks,
    netGenerateProcessingParameterNoTurnarounds,
    netGenerateProcessingParameterNoTurnaroundsTls,
    netGenerateProcessingParameterNoLeftConnections,
    netGenerateProcessingParameterOffsetDisableNormalization,
    netGenerateProcessingParameterOffsetX,
    netGenerateProcessingParameterOffsetY,
    netGenerateProcessingParameterFlipYAxis,
    netGenerateProcessingParameterRoundaboutsGuess,
    netGenerateProcessingParameterLefthand,
    netGenerateProcessingParameterJunctionsJoin,
    netGenerateProcessingParameterJunctionsJoinDist,
    netGenerateProcessingParameterJunctionsCornerDetail,
    netGenerateProcessingParameterCheckLaneFoesRoundabout,
    netGenerateProcessingParameterCheckLaneFoesAll,
    netGenerateProcessingParameterSidewalksGuess,
    netGenerateProcessingParameterSidewalksGuessMaxSpeed,
    netGenerateProcessingParameterSidewalksGuessMinSpeed,
    netGenerateProcessingParameterSidewalksGuessFromPermissions,
    netGenerateProcessingParameterCrossingsGuess,
    netGenerateProcessingParameterTlsJoinDist,
    netGenerateProcessingParameterProcessingParameterLanenumber,
    netGenerateProcessingParameterProcessingParameterSpeed,
    netGenerateProcessingParameterProcessingParameterPriority,
    netGenerateProcessingParameterProcessingParameterSidewalkWidth,
    netGenerateProcessingParameterProcessingParameterJunctionType,
    netGenerateProcessingParameterVerbose,
    netGenerateProcessingParameterPrintOptions,
    netGenerateProcessingParameterHelp,
    netGenerateProcessingParameterVersion,
    netGenerateProcessingParameterXmlValidation,
    netGenerateProcessingParameterXmlValidationNet,
    netGenerateProcessingParameterNoWarnings,
    netGenerateProcessingParameterLog,
    netGenerateProcessingParameterMessageLog,
    netGenerateProcessingParameterErrorLog,
    netGenerateProcessingParameterRandom,
    netGenerateProcessingParameterSeed,
};


class netGenerateTool : public eNetEditorTool
{
public:

    netGenerateTool(eNetEditorMessages *newMessages, eNetEditorMainConfiguration *neweNetEditorC, QObject *parent);


public slots:

    bool createSumoCfgFile(eNetEditorProject *project)
    {
        return false;
    }

    bool startTool(QVector<QString> *inputParameters, QVector<QString> *outputParameters, QVector<QString> *processingParameters);


private slots:

    void setInputParameters(QVector<QString> *inputParameters)
    {
        // Por ahora ignora el warning
        inputParameters;
    }

    void setOutputParameters(QVector<QString> *outputParameters)
    {
        // Por ahora ignora el warning
        outputParameters;
    }

    void setProcessingParameters(QVector<QString> *processingParameters)
    {
        // Por ahora ignora el warning
        processingParameters;
    }
};

#endif // SUMONETGENERATE_H
