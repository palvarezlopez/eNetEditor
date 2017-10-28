#ifndef CHARGINGSTATIONITEMCONFIGURATION_H
#define CHARGINGSTATIONITEMCONFIGURATION_H

#include "../eNetEditorItemConfiguration.h"


class chargingStationItemConfiguration : public eNetEditorItemConfiguration
{
public:

    chargingStationItemConfiguration();

    ~chargingStationItemConfiguration();


    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getChargingStationDefaultStartPos() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getChargingStationDefaultEndPos() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getChargingStationDefaultChrgPower() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getChargingStationDefaultEfficiency() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getChargingStationDefaultChargeInTransit() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getChargingStationDefaultChargeDelay() const;


private:

    // Default Parameter Start position
    qreal chargingStationDefaultStartPos;

    // Default Parameter End position
    qreal chargingStationDefaultEndPos;

    // Default Parameter Charging Power
    qreal chargingStationDefaultChrgPower;

    // Default Parameter Efficiency
    qreal chargingStationDefaultEfficiency;

    // Default Parameter Charge in transit (ATENCION: ¿ES UN BOOLEAN?)
    qreal chargingStationDefaultChargeInTransit;

    // Default Parameter Charge delay
    qreal chargingStationDefaultChargeDelay;
};

#endif // CHARGINGSTATIONITEMCONFIGURATION_H
