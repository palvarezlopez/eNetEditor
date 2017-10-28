#ifndef CADYTSTOOL_H
#define CADYTSTOOL_H

#include "eNetEditorTool.h"


// Declare enum cadytsInputParameters
enum cadytsInputParameters
{
    cadytsInputParameterRouteFile,
    cadytsInputParameterFlowsFile,
    cadytsInputParameterClasspath,
};

// Declare enum cadytsOutputParameters
enum cadytsOutputParameters
{
    cadytsOutputParameterFlowEvaluationFiles,
};

// Declare enum cadytsProcessingParameters
enum cadytsProcessingParameters
{
    cadytsProcessingParameterSteps,
    cadytsProcessingParameterScaled,
    cadytsProcessingParameterNumberOfIterations,
    cadytsProcessingParameterVariance,
    cadytsProcessingParameterPreparatoryIterations,
    cadytsProcessingParameterFitTrafficCounts,
    cadytsProcessingParameterDeviation,
    cadytsProcessingParameterOverrideDepartTimes,
    cadytsProcessingParameterPrefixODMatrixFilesVisum,
    cadytsProcessingParameterPostfitAtacched,
    cadytsProcessingParameterWritteSummary,
    cadytsProcessingParameterWritteTripinfos,
};


class cadytsTool : public eNetEditorTool
{
public:

    cadytsTool(eNetEditorMessages *newMessages, eNetEditorMainConfiguration *neweNetEditorC, QObject *parent);

    ~cadytsTool();


public slots:

    bool createSumoCfgFile(eNetEditorProject *project)
    {
        return false;
    }

    bool startTool(QVector<QString> *inputParameters, QVector<QString> *outputParameters, QVector<QString> *processingParameters);


private slots:

    void setInputParameters(QVector<QString> *inputParameters)
    {
        // Por ahora ignora el warning;
        inputParameters;
    }

    void setOutputParameters(QVector<QString> *outputParameters)
    {
        // Por ahora ignora el warning;
        outputParameters;
    }

    void setProcessingParameters(QVector<QString> *processingParameters)
    {
        // Por ahora ignora el warning;
        processingParameters;
    }
};

#endif // CADYTS_H
