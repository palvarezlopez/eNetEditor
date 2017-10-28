#ifndef DISTRIBUTIONFUNCTIONITEMCONFIGURATION_H
#define DISTRIBUTIONFUNCTIONITEMCONFIGURATION_H

#include "eNetEditorItemConfiguration.h"


class distributionFunctionItemConfiguration : public eNetEditorItemConfiguration
{
public:

    distributionFunctionItemConfiguration();

    ~distributionFunctionItemConfiguration();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getDistributionFunctionDefaultTrafficCount();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getDistributionFunctionDefaultPkwProcent();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getDistributionFunctionDefaultLkwProcent();


    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getDistributionFunctionDefaultPKWVelocity();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getDistributionFunctionDefaultLKWVelocity();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getDistributionFunctionDefaultSampling();

private:

    // Number of vehicles
    int distributionFunctionDefaultTrafficCount;

    // Procent of pkw
    qreal distributionFunctionDefaultPkwProcent;

    // Procent of lkw
    // Derivable from distributionFunctionDefaultPkwProcent;

    // Vehicle velocity
    qreal distributionFunctionDefaultPKWVelocity;

    // Vehicle velocity
    qreal distributionFunctionDefaultLKWVelocity;

    // Sampling
    int sampling;
};

#endif // DISTRIBUTIONFUNCTIONITEMCONFIGURATION_H
