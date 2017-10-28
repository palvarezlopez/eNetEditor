#include "cadytsToolConfiguration.h"

cadytsToolConfiguration::cadytsToolConfiguration() : eNetEditorToolConfiguration(0, 0, 0 /** arreglar **/)
{
    // Set default values

    setOutputfolder("cadyts");

    cadytsDefaultClasspath = "cadytsSumoController.jar";

    cadytsDefaultSteps = 100;

    cadytsDefaultScaled = 2;

    cadytsDefaultNumberOfIterations = 85;

    cadytsDefaultVariance = 1;

    cadytsDefaultPreparatoryIterations = 5;

    cadytsDefaultFlowEvaluationFiles = "cadytsFlowEvaulation";

    cadytsDefaultFitTrafficCounts = false;

    cadytsDefaultDeviation = 25;

    cadytsDefaultOverrideDepartTimes = false;

    cadytsDefaulPrefixODMatrixFilesVisum = "cadytsODMatrix";

    cadytsDefaultPostfitAtacched = "-CLONE";

    cadytsDefaultWritteSummary = false;

    cadytsDefaultWritteTripinfos = false;
}

cadytsToolConfiguration::~cadytsToolConfiguration()
{
    // Nothing to erase
}

const QString &cadytsToolConfiguration::getCadytsDefaultRouteFile() const
{
    return cadytsDefaultRouteFile;
}

const QString &cadytsToolConfiguration::getCadytsDefaultFlowsFile() const
{
    return cadytsDefaultFlowsFile;
}

const QString &cadytsToolConfiguration::getCadytsDefaultClasspath() const
{
    return cadytsDefaultClasspath;
}

int cadytsToolConfiguration::getCadytsDefaultSteps() const
{
    return cadytsDefaultSteps;
}

int cadytsToolConfiguration::getCadytsDefaultScaled() const
{
    return cadytsDefaultScaled;
}

int cadytsToolConfiguration::getCadytsDefaultNumberOfIterations() const
{
    return cadytsDefaultNumberOfIterations;
}

qreal cadytsToolConfiguration::getCadytsDefaultVariance() const
{
    return cadytsDefaultVariance;
}

int cadytsToolConfiguration::getCadytsDefaultPreparatoryIterations() const
{
    return cadytsDefaultPreparatoryIterations;
}

const QString &cadytsToolConfiguration::getCadytsDefaultFlowEvaluationFiles() const
{
    return cadytsDefaultFlowEvaluationFiles;
}

bool cadytsToolConfiguration::getCadytsDefaultFitTrafficCounts() const
{
    return cadytsDefaultFitTrafficCounts;
}

qreal cadytsToolConfiguration::getCadytsDefaultDeviation() const
{
    return cadytsDefaultDeviation;
}

bool cadytsToolConfiguration::getCadytsDefaultOverrideDepartTimes() const
{
    return cadytsDefaultOverrideDepartTimes;
}

const QString &cadytsToolConfiguration::getCadytsDefaulPrefixODMatrixFilesVisum() const
{
    return cadytsDefaulPrefixODMatrixFilesVisum;
}

const QString &cadytsToolConfiguration::getCadytsDefaultPostfitAtacched() const
{
    return cadytsDefaultPostfitAtacched;
}

bool cadytsToolConfiguration::getCadytsDefaultWritteSummary() const
{
    return cadytsDefaultWritteSummary;
}

bool cadytsToolConfiguration::getCadytsDefaultWritteTripinfos() const
{
    return cadytsDefaultWritteTripinfos;
}

void cadytsToolConfiguration::setCadytsDefaultRouteFile(const QString &value)
{
    cadytsDefaultRouteFile = value;
}

void cadytsToolConfiguration::setCadytsDefaultFlowsFile(const QString &value)
{
    cadytsDefaultFlowsFile = value;
}

void cadytsToolConfiguration::setCadytsDefaultClasspath(const QString &value)
{
    cadytsDefaultClasspath = value;
}

void cadytsToolConfiguration::setCadytsDefaultSteps(int value)
{
    cadytsDefaultSteps = value;
}

void cadytsToolConfiguration::setCadytsDefaultScaled(int value)
{
    cadytsDefaultScaled = value;
}

void cadytsToolConfiguration::setCadytsDefaultNumberOfIterations(int value)
{
    cadytsDefaultNumberOfIterations = value;
}

void cadytsToolConfiguration::setCadytsDefaultVariance(qreal value)
{
    cadytsDefaultVariance = value;
}
void cadytsToolConfiguration::setCadytsDefaultPreparatoryIterations(int value)
{
    cadytsDefaultPreparatoryIterations = value;
}

void cadytsToolConfiguration::setCadytsDefaultFlowEvaluationFiles(const QString &value)
{
    cadytsDefaultFlowEvaluationFiles = value;
}

void cadytsToolConfiguration::setCadytsDefaultFitTrafficCounts(bool value)
{
    cadytsDefaultFitTrafficCounts = value;
}

void cadytsToolConfiguration::setCadytsDefaultDeviation(qreal value)
{
    cadytsDefaultDeviation = value;
}

void cadytsToolConfiguration::setCadytsDefaultOverrideDepartTimes(bool value)
{
    cadytsDefaultOverrideDepartTimes = value;
}

void cadytsToolConfiguration::setCadytsDefaulPrefixODMatrixFilesVisum(const QString &value)
{
    cadytsDefaulPrefixODMatrixFilesVisum = value;
}

void cadytsToolConfiguration::setCadytsDefaultPostfitAtacched(const QString &value)
{
    cadytsDefaultPostfitAtacched = value;
}

void cadytsToolConfiguration::setCadytsDefaultWritteSummary(bool value)
{
    cadytsDefaultWritteSummary = value;
}

void cadytsToolConfiguration::setCadytsDefaultWritteTripinfos(bool value)
{
    cadytsDefaultWritteTripinfos = value;
}
