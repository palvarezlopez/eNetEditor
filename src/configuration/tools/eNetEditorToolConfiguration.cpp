#include "eNetEditorToolConfiguration.h"

#include "cadytsToolConfiguration.h"
#include "dfRouterToolConfiguration.h"
#include "duaRouterToolConfiguration.h"
#include "jtrRouterToolConfiguration.h"
#include "netConvertToolConfiguration.h"
#include "netGenerateToolConfiguration.h"
#include "sumoToolConfiguration.h"

eNetEditorToolConfiguration::eNetEditorToolConfiguration(int newNumberOfInputParameters, int newNumberOfOutputParameters, int newNumberOfProcessingParameters) : eNetEditorConfiguration()
{
    // Set number of imput parameters
    numberOfInputParameters = newNumberOfInputParameters;

    // Set number of output parameters
    numberOfOutputParameters = newNumberOfOutputParameters;

    // Set number of processing parameters
    numberOfProcessingParameters = newNumberOfProcessingParameters;
}

eNetEditorToolConfiguration::~eNetEditorToolConfiguration()
{
    // Noting to erase
}

const QString &eNetEditorToolConfiguration::getExecutablePath() const
{
    return executablePath;
}

int eNetEditorToolConfiguration::getNumberOfInputParameters() const
{
    return numberOfInputParameters;
}

int eNetEditorToolConfiguration::getNumberOfOutputParameters() const
{
    return numberOfOutputParameters;
}

int eNetEditorToolConfiguration::getNumberOfProcessingParameters() const
{
    return numberOfProcessingParameters;
}

void eNetEditorToolConfiguration::setExecutablePath(const QString &newExecutablePath)
{
    executablePath = newExecutablePath;
}

const QString &eNetEditorToolConfiguration::getOutputfolder() const
{
    return outputfolder;
}

void eNetEditorToolConfiguration::setOutputfolder(const QString &newOutputfolder)
{
    outputfolder = newOutputfolder;
}
