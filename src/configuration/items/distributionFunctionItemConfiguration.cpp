#include "distributionFunctionItemConfiguration.h"

distributionFunctionItemConfiguration::distributionFunctionItemConfiguration() : eNetEditorItemConfiguration()
{
    // Set item Extension
    setItemFileExtension("xml");

    // Set filename
    setItemFileName("distributionfunctions");

    // Set default parameters
    distributionFunctionDefaultTrafficCount = 1000;
    distributionFunctionDefaultPkwProcent = 0.9;
    distributionFunctionDefaultPKWVelocity = 5;
    distributionFunctionDefaultLKWVelocity = 5;
    sampling = 60;
}

distributionFunctionItemConfiguration::~distributionFunctionItemConfiguration()
{
    // Nothing to erase
}

int distributionFunctionItemConfiguration::getDistributionFunctionDefaultTrafficCount()
{
    return distributionFunctionDefaultTrafficCount;
}

qreal distributionFunctionItemConfiguration::getDistributionFunctionDefaultPkwProcent()
{
    return distributionFunctionDefaultPkwProcent;
}

qreal distributionFunctionItemConfiguration::getDistributionFunctionDefaultLkwProcent()
{
    return (1 - distributionFunctionDefaultPkwProcent);
}

qreal distributionFunctionItemConfiguration::getDistributionFunctionDefaultPKWVelocity()
{
    return distributionFunctionDefaultPKWVelocity;
}

qreal distributionFunctionItemConfiguration::getDistributionFunctionDefaultLKWVelocity()
{
    return distributionFunctionDefaultLKWVelocity;
}

int distributionFunctionItemConfiguration::getDistributionFunctionDefaultSampling()
{
    return sampling;
}
