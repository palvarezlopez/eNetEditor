#ifndef JTRROUTERTOOL_H
#define JTRROUTERTOOL_H

#include "eNetEditorTool.h"


// Declare enum jtrRouterInputParameters
enum jtrRouterInputParameters
{
    jtrRouterInputParameterNetFile,
    jtrRouterInputParameterAdditionalFiles,
    jtrRouterInputParameterAlternativeFiles,
    jtrRouterInputParameterFlowFiles,
    jtrRouterInputParameterTurnRatioFiles,
};

// Declare enum jtrRouterOutputParameters
enum jtrRouterOutputParameters
{
    jtrRouterOutputParameterOutputPrefix,
    jtrRouterOutputParameterOutputFile,
    jtrRouterOutputParameterVtypeOutput,
    jtrRouterOutputParameterExitTimes,
};

// Declare enum jtrRouterProcessingParameters
enum jtrRouterProcessingParameters
{
    jtrRouterProcessingParameterIgnoreErrors,
    jtrRouterProcessingParameterUnsortedInput,
    jtrRouterProcessingParameterRouteSteps,
    jtrRouterProcessingParameterRandomizeFlows,
    jtrRouterProcessingParameterMaxAlternatives,
    jtrRouterProcessingParameterRemoveLoops,
    jtrRouterProcessingParameterRepair,
    jtrRouterProcessingParameterWeightsInterpolate,
    jtrRouterProcessingParameterWithTaz,
    jtrRouterProcessingParameterRoutingThreads,
    jtrRouterProcessingParameterMaxEdgesFactor,
    jtrRouterProcessingParameterTurnProcessingParameters,
    jtrRouterProcessingParameterSinkEdges,
    jtrRouterProcessingParameterAcceptAllDestinations,
    jtrRouterProcessingParameterIgnoreVclasses,
    jtrRouterProcessingParameterAllowLoops,
    jtrRouterProcessingParameterDepartlane,
    jtrRouterProcessingParameterDepartpos,
    jtrRouterProcessingParameterDepartspeed,
    jtrRouterProcessingParameterArrivallane,
    jtrRouterProcessingParameterArrivalpos,
    jtrRouterProcessingParameterArrivalspeed,
    jtrRouterProcessingParameterDefaultsOverride,
    jtrRouterProcessingParameterBegin,
    jtrRouterProcessingParameterEnd,
    jtrRouterProcessingParameterVerbose,
    jtrRouterProcessingParameterPrintOptions,
    jtrRouterProcessingParameterHelp,
    jtrRouterProcessingParameterVersion,
    jtrRouterProcessingParameterXmlValidation,
    jtrRouterProcessingParameterXmlValidationNet,
    jtrRouterProcessingParameterNoWarnings,
    jtrRouterProcessingParameterLog,
    jtrRouterProcessingParameterMessageLog,
    jtrRouterProcessingParameterErrorLog,
    jtrRouterProcessingParameterStatsPeriod,
    jtrRouterProcessingParameterNoStepLog,
    jtrRouterProcessingParameterRandom,
    jtrRouterProcessingParameterSeed,
};



class jtrRouterTool : public eNetEditorTool
{
public:

    jtrRouterTool(eNetEditorMessages *newMessages, eNetEditorMainConfiguration *neweNetEditorC, QObject *parent);


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

#endif // SUMOJTRROUTER_H
