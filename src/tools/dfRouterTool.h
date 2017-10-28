#ifndef DFROUTERTOOL_H
#define DFROUTERTOOL_H

#include "eNetEditorTool.h"


// Declare enum dfRouterInputParameters
enum dfRouterInputParameters
{
    dfRouterInputParameterNetFile,
    dfRouterInputParameterDetectorFiles,
    dfRouterInputParameterMeasureFiles,
};

// Declare enum dfRouterOutputParameters
enum dfRouterOutputParameters
{
    dfRouterOutputParameterPrefixFile,
    dfRouterOutputParameterRoutesFile,
    dfRouterOutputParameterRoutesForAll,
    dfRouterOutputParameterDetectorFile,
    dfRouterOutputParameterDetectorsPoiFile,
    dfRouterOutputParameterEmittersFile,
    dfRouterOutputParameterVtype,
    dfRouterOutputParameterEmittersPoiFile,
    dfRouterOutputParameterVariableSpeedSignFile,
    dfRouterOutputParameterEndRerouteFile,
    dfRouterOutputParameterValidationFile,
    dfRouterOutputParameterValidationAddSources,
};

// Declare enum dfRouterProcessingParameters
enum dfRouterProcessingParameters
{
    dfRouterProcessingParametersGuessEmptyFlows,
    dfRouterProcessingParametersHighwayMode,
    dfRouterProcessingParametersIgnoreInvalidDetectors,
    dfRouterProcessingParametersRevalidateDetectors,
    dfRouterProcessingParametersRevalidateRoutes,
    dfRouterProcessingParametersKeepUnfinishedRoutes,
    dfRouterProcessingParametersKeepLongerRoutes,
    dfRouterProcessingParametersMaxSearchDepth,
    dfRouterProcessingParametersEmissionsOnly,
    dfRouterProcessingParametersDisallowedEdges,
    dfRouterProcessingParametersKeepTurnarounds,
    dfRouterProcessingParametersMinRouteLength,
    dfRouterProcessingParametersTimeFactor,
    dfRouterProcessingParametersTimeOffset,
    dfRouterProcessingParametersTimeStep,
    dfRouterProcessingParametersCalibratorOutput,
    dfRouterProcessingParametersIncludeUnusedRoutes,
    dfRouterProcessingParametersRevalidateFlows,
    dfRouterProcessingParametersRemoveEmptyDetectors,
    dfRouterProcessingParametersStrictSources,
    dfRouterProcessingParametersRespectConcurrentInflows,
    dfRouterProcessingParametersScale,
    dfRouterProcessingParametersDepartlane,
    dfRouterProcessingParametersDepartpos,
    dfRouterProcessingParametersDepartspeed,
    dfRouterProcessingParametersArrivallane,
    dfRouterProcessingParametersArrivalpos,
    dfRouterProcessingParametersArrivalspeed,
    dfRouterProcessingParametersBegin,
    dfRouterProcessingParametersEnd,
    dfRouterProcessingParametersVerbose,
    dfRouterProcessingParametersPrintOptions,
    dfRouterProcessingParametersHelp,
    dfRouterProcessingParametersVersion,
    dfRouterProcessingParametersXmlValidation,
    dfRouterProcessingParametersXmlValidationNet,
    dfRouterProcessingParametersNoWarnings,
    dfRouterProcessingParametersLog,
    dfRouterProcessingParametersMessageLog,
    dfRouterProcessingParametersErrorLog,
    dfRouterProcessingParametersReportEmptyDetectors,
    dfRouterProcessingParametersPrintAbsoluteFlows,
    dfRouterProcessingParametersNoStepLog,
    dfRouterProcessingParametersRandom,
    dfRouterProcessingParametersSeed,
};



class dfRouterTool : public eNetEditorTool
{
public:

    dfRouterTool(eNetEditorMessages *newMessages, eNetEditorMainConfiguration *neweNetEditorC, QObject *parent);


public slots:

    bool createSumoCfgFile(eNetEditorProject *project);

    bool startTool(QVector<QString> *inputParameters, QVector<QString> *outputParameters, QVector<QString> *processingParameters);


private slots:

    void setInputParameters(QVector<QString> *inputParameters);

    void setOutputParameters(QVector<QString> *outputParameters);

    void setProcessingParameters(QVector<QString> *processingParameters);
};

#endif // SUMODFROUTER_H
