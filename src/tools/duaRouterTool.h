#ifndef DUAROUTERTOOL_H
#define DUAROUTERTOOL_H

#include "eNetEditorTool.h"


// Declar enum duaRouterInputParameters
enum duaRouterInputParameters
{
    duaRouterInputParameterNetFile,
    duaRouterInputParameterAdditionalFiles,
    duaRouterInputParameterAlternativeFiles,
    duaRouterInputParameterFlowFiles,
    duaRouterInputParameterWeightFiles,
    duaRouterInputParameterLaneWeightFiles,
    duaRouterInputParameterWeightAttribute,
    duaRouterInputParameterPhemlightPath,
    duaRouterInputParameterTripFiles,
    duaRouterInputParameterRouteFiles,
};

// Declare enum duaRouterOutputParameters
enum duaRouterOutputParameters
{
    duaRouterOutputParameterOutputPrefix,
    duaRouterOutputParameterOutputFile,
    duaRouterOutputParameterVtypeOutput,
    duaRouterOutputParameterExitTimes,
};

// Declar enum duaRouterProcessingParameters
enum duaRouterProcessingParameters
{
    duaRouterProcessingParameterIgnoreErrors,
    duaRouterProcessingParameterUnsortedInput,
    duaRouterProcessingParameterRouteSteps,
    duaRouterProcessingParameterRandomizeFlows,
    duaRouterProcessingParameterMaxAlternatives,
    duaRouterProcessingParameterRemoveLoops,
    duaRouterProcessingParameterRepair,
    duaRouterProcessingParameterWeightsInterpolate,
    duaRouterProcessingParameterWithTaz,
    duaRouterProcessingParameterRoutingAlgorithm,
    duaRouterProcessingParameterWeightPeriod,
    duaRouterProcessingParameterRoutingThreads,
    duaRouterProcessingParameterWeightsExpand,
    duaRouterProcessingParameterGawronBeta,
    duaRouterProcessingParameterGawronA,
    duaRouterProcessingParameterKeepAllRoutes,
    duaRouterProcessingParameterSkipNewRoutes,
    duaRouterProcessingParameterLogit,
    duaRouterProcessingParameterRouteChoiceMethod,
    duaRouterProcessingParameterLogitBeta,
    duaRouterProcessingParameterLogitGamma,
    duaRouterProcessingParameterLogitTheta,
    duaRouterProcessingParameterDepartlane,
    duaRouterProcessingParameterDepartpos,
    duaRouterProcessingParameterDepartspeed,
    duaRouterProcessingParameterArrivallane,
    duaRouterProcessingParameterArrivalpos,
    duaRouterProcessingParameterArrivalspeed,
    duaRouterProcessingParameterDefaultsOverride,
    duaRouterProcessingParameterBegin,
    duaRouterProcessingParameterEnd,
    duaRouterProcessingParameterVerbose,
    duaRouterProcessingParameterPrintOptions,
    duaRouterProcessingParameterHelp,
    duaRouterProcessingParameterVersion,
    duaRouterProcessingParameterXmlValidation,
    duaRouterProcessingParameterXmlValidationNet,
    duaRouterProcessingParameterNoWarnings,
    duaRouterProcessingParameterLog,
    duaRouterProcessingParameterMessageLog,
    duaRouterProcessingParameterErrorLog,
    duaRouterProcessingParameterStatsPeriod,
    duaRouterProcessingParameterNoStepLog,
    duaRouterProcessingParameterRandom,
    duaRouterProcessingParameterSeed,
};


class duaRouterTool : public eNetEditorTool
{
public:

    duaRouterTool(eNetEditorMessages *newMessages, eNetEditorMainConfiguration *neweNetEditorC, QObject *parent);


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

#endif // SUMODUAROUTER_H
