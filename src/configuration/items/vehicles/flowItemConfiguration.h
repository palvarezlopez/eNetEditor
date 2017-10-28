#ifndef FLOWITEMCONFIGURATION_H
#define FLOWITEMCONFIGURATION_H

#include "abstractVehicleItemConfiguration.h"


class flowItemConfiguration : public eNetEditorVehicleConfiguration
{
public:

    flowItemConfiguration();

    ~flowItemConfiguration();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getFlowBegin() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getFlowEnd() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getFlowVehsPerHour() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getFlowPeriod() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getFlowProbability() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getFlowNumber() const;


private:

    // Default parameter begin
    qreal begin;

    // Default parameter end
    qreal end;

    // Default parameter vehsPerHour
    qreal vehsPerHour;

    // Default parameter period
    qreal period;

    // Default parameter probability
    qreal probability;

    // Default parameter number
    int number;
};

#endif // FLOWITEMCONFIGURATION_H
