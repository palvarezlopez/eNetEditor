#ifndef SUMOTOOL_H
#define SUMOTOOL_H

#include "eNetEditorTool.h"

// Declare enum sumoInputParameters
enum sumoInputParameters
{
    sumoInputParameterNetFile,
    sumoInputParameterRouteFiles,
    sumoInputParameterAdditionalFiles,
    sumoInputParameterWeightFiles,
    sumoInputParameterWeightAttribute,
    sumoInputParameterLoadState,
    sumoInputParameterLoadStateOffset,
};

// Declare enum sumoOutputParameters
enum sumoOutputParameters
{
    sumoOutputParameterOutputPrefix,
    sumoOutputParameterNetstateDump,
    sumoOutputParameterNetstateDumpEmptyEdges,
    sumoOutputParameterNetstateDumpPrecision,
    sumoOutputParameterEmissionOutput,
    sumoOutputParameterFcdOutput,
    sumoOutputParameterFcdOutputGeo,
    sumoOutputParameterFcdOutputSignals,
    sumoOutputParameterFullOutput,
    sumoOutputParameterQueueOutput,
    sumoOutputParameterVtkOutput,
    sumoOutputParameterAmitranOutput,
    sumoOutputParameterSummaryOutput,
    sumoOutputParameterTripinfoOutput,
    sumoOutputParameterTripinfoOutputWriteUnfinished,
    sumoOutputParameterVehrouteOutput,
    sumoOutputParameterVehrouteOutputExitTimes,
    sumoOutputParameterVehrouteOutputLastRoute,
    sumoOutputParameterVehrouteOutputSorted,
    sumoOutputParameterVehrouteOutputDua,
    sumoOutputParameterVehrouteOutputIntendedDepart,
    sumoOutputParameterVehrouteOutputWriteUnfinished,
    sumoOutputParameterLinkOutput,
    sumoOutputParameterBtOutput,
    sumoOutputParameterSaveStateTimes,
    sumoOutputParameterSaveStatePrefix,
    sumoOutputParameterSaveStateFiles,
};

// Declare enum sumoProcessingParameters
enum sumoProcessingParameters
{
    sumoProcessingParameterBegin,
    sumoProcessingParameterEnd,
    sumoProcessingParameterStepLength,
    sumoProcessingParameterRouteSteps,
    sumoProcessingParameterNoInternalLinks,
    sumoProcessingParameterIgnoreJunctionBlocker,
    sumoProcessingParameterIgnoreAccidents,
    sumoProcessingParameterIgnoreRouteErrors,
    sumoProcessingParameterMaxNumVehicles,
    sumoProcessingParameterScale,
    sumoProcessingParameterTimeToTeleport,
    sumoProcessingParameterTimeToTeleportHighways,
    sumoProcessingParameterMaxDepartDelay,
    sumoProcessingParameterSloppyInsert,
    sumoProcessingParameterEagerInsert,
    sumoProcessingParameterRandomDepartOffset,
    sumoProcessingParameterLanechangeAllowSwap,
    sumoProcessingParameterLanechangeDuration,
    sumoProcessingParameterLanechangeOvertakeRight,
    sumoProcessingParameterPedestrianModel,
    sumoProcessingParameterPedestrianStripingStripeWidth,
    sumoProcessingParameterPedestrianStripingDawdling,
    sumoProcessingParameterPedestrianStripingJamtime,
    sumoProcessingParameterRoutingAlgorithm,
    sumoProcessingParameterWeightsRandomFactor,
    sumoProcessingParameterDeviceReroutingProbability,
    sumoProcessingParameterDeviceReroutingExplicit,
    sumoProcessingParameterDeviceReroutingDeterministic,
    sumoProcessingParameterDeviceReroutingPeriod,
    sumoProcessingParameterDeviceReroutingPrePeriod,
    sumoProcessingParameterDeviceReroutingAdaptationWeight,
    sumoProcessingParameterDeviceReroutingAdaptationInterval,
    sumoProcessingParameterDeviceReroutingWithTaz,
    sumoProcessingParameterDeviceReroutingInitWithLoadedWeights,
    sumoProcessingParameterDeviceReroutingShortestPathFile,
    sumoProcessingParameterDeviceReroutingThreads,
    sumoProcessingParameterDeviceReroutingOutput,
    sumoProcessingParameterVerbose,
    sumoProcessingParameterPrintOptions,
    sumoProcessingParameterHelp,
    sumoProcessingParameterVersion,
    sumoProcessingParameterXmlValidation,
    sumoProcessingParameterXmlValidationNet,
    sumoProcessingParameterNoWarnings,
    sumoProcessingParameterLog,
    sumoProcessingParameterMessageLog,
    sumoProcessingParameterErrorLog,
    sumoProcessingParameterNoDurationLog,
    sumoProcessingParameterNoStepLog,
    sumoProcessingParameterPhemlightPath,
    sumoProcessingParameterDeviceEmissionsProbability,
    sumoProcessingParameterDeviceEmissionsExplicit,
    sumoProcessingParameterDeviceEmissionsDeterministic,
    sumoProcessingParameterDeviceBtreceiverProbability,
    sumoProcessingParameterDeviceBtreceiverExplicit,
    sumoProcessingParameterDeviceBtreceiverDeterministic,
    sumoProcessingParameterDeviceBtreceiverRange,
    sumoProcessingParameterDeviceBtreceiverAllRecognitions,
    sumoProcessingParameterDeviceBtreceiverOfftime,
    sumoProcessingParameterDeviceBtsenderProbability,
    sumoProcessingParameterDeviceBtsenderExplicit,
    sumoProcessingParameterDeviceBtsenderDeterministic,
    sumoProcessingParameterDeviceExampleExplicit,
    sumoProcessingParameterDeviceExampleParameter,
    sumoProcessingParameterRemotePort,
    sumoProcessingParameterRandom,
    sumoProcessingParameterSeed,
};


class sumoTool : public eNetEditorTool
{
public:

    sumoTool(eNetEditorMessages *newMessages, eNetEditorMainConfiguration *neweNetEditorC, QObject *parent);


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

#endif // SUMOTOOL_H
