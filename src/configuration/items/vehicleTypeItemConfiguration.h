#ifndef VEHICLETYPEITEMCONFIGURATION_H
#define VEHICLETYPEITEMCONFIGURATION_H

#include "eNetEditorItemConfiguration.h"

/*! \enum Vehicle Classes
    All vehicle classes that supports SUMO
*/
enum vehicleClass
{
    vehicleClassUnknown, /*!< Vehicle class "unknown" */
    vehicleClassBicycle, /*!< Vehicle class "bicycle" */
    vehicleClassMoped, /*!< Vehicle class "moped" */
    vehicleClassMotorcycle, /*!< Vehicle class "motorcycle" */
    vehicleClassPrivate, /*!< Vehicle class "private" */
    vehicleClassHov, /*!< Vehicle class "hov" */
    vehicleClassEvehicle, /*!< Vehicle class "evehicle" */
    vehicleClassPassenger, /*!< Vehicle class "passenger" */
    vehicleClassCoach, /*!< Vehicle class "coach"*/
    vehicleClassBus, /*!< Vehicle class "bus" */
    vehicleClassDelivery, /*!< Vehicle class "delivery" */
    vehicleClassTruck, /*!< Vehicle class "truck" */
    vehicleClassTrailer, /*!< Vehicle class ""trailer"" */
    vehicleClassTaxi, /*!< Vehicle class "taxi" */
    vehicleClassEmergency, /*!< Vehicle class ""emergency"" */
    vehicleClassArmy, /*!< Vehicle class "army" */
    vehicleClassRail_urban, /*!< Vehicle class "rail_urban" */
    vehicleClassRail, /*!< Vehicle class "rail" */
    vehicleClassRail_electric, /*!< Vehicle class "rail_electric"*/
    vehicleClassCustom1, /*!< Vehicle class "custom1" */
    vehicleClassCustom2, /*!< Vehicle class "custom2" */
    vehicleClassPedestrian, /*!< Vehicle class "pedestrian" */
    vehicleClassIgnoring, /*!< Vehicle class "ignoring" */
    vehicleClassAuthority, /*!< Vehicle class "authority" */
    vehicleClassVip, /*!< Vehicle class "vip" */
    vehicleClassTram /*!< Vehicle class "tram" */
};


class vehicleTypeItemConfiguration : public eNetEditorItemConfiguration
{
public:

    vehicleTypeItemConfiguration();

    ~vehicleTypeItemConfiguration();

    /**
        @brief Get Vehicle Class value
        @param vClass vehicleClass of the vehicleTypeItem
        @return QString with the corresponding value of vehicleClass
        @details Get the QString value of vehicleClass (Example: vehicleClassPrivate returns "private")
    */
    const QString &getVehicleTypeClassValue(vehicleClass vClass) const;

    /**
        @brief Get Vehicle Shape value
        @param vShape vehicleShape of the vehicleTypeItem
        @return QString with the corresponding value of vehicleShape
        @details Get the QString value of vehicleShape (Example: vehicleShapeMotorcycle returns "Motorcycle")
    */
    const QString &getVehicleTypeShapeValue(vehicleShape vShape) const;

    /**
        @brief Get Vehicle Emission value
        @param eValue vehicleEmission of the vehicle
        @return QString with the corresponding value of vehicleEmission
        @details Get the QString value of vehicleEmission (Example: vehicleEmissionP_7_7 returns "P_7_7")
    */
    const QString &getVehicleTypeEmissionValue(vehicleEmission eValue) const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getVehicleTypeNumberOfVehicleClasses();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    vehicleClass getVehicleTypeDefaultVClass() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultAccel() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultDecel() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultSigma() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultTau() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultLength() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultMinGap() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultMaxSpeed() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultSpeedFactor() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultSpeedDev() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getVehicleTypeDefaultColor() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getVehicleTypeDefaultEmissionClass() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    vehicleShape getVehicleTypeDefaultGuiShape() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultWidth() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getVehicleTypeDefaultFilename() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultImpatience() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getVehicleTypeDefaultLaneChangeModel() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultActBatKap() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultMaxBatKap() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultPowerMax() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultMass() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultFrontSurfaceArea() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultAirDragCoefficient() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultInternalMomentOfInertia() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultRadialDragCoefficient() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultRollDragCoefficient() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultConstantPowerIntake() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultPropulsionEfficiency() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getVehicleTypeDefaultRecuperationEfficiency() const;


private:

    // Vector with the vehicle Class
    QVector<QString> vectorOfVehicleTypeClasses;

    // Vector with the vehicle shapes
    QVector<QString> vectorOfvehicleTypeShapes;

    // Vector with the emissions
    QVector<QString> vectorOfVehicleTypeEmissions;

    // Number of vehicle Classes
    int numberOfVehicleClasses;

    // Default Parameter Default VClass
    vehicleClass vehicleTypeDefaultVClass;

    // Default Parameter Accel
    qreal vehicleTypeDefaultAccel;

    // Default Parameter Decel
    qreal vehicleTypeDefaultDecel;

    // Default Parameter Sigma
    qreal vehicleTypeDefaultSigma;

    // Default Parameter Tau
    qreal vehicleTypeDefaultTau;

    // Default Parameter Lenght
    qreal vehicleTypeDefaultLength;

    // Default Parameter Min Gap
    qreal vehicleTypeDefaultMinGap;

    // Default Parameter Max Speed
    qreal vehicleTypeDefaultMaxSpeed;

    // Default Parameter Speed Factor
    qreal vehicleTypeDefaultSpeedFactor;

    // Default Parameter Speed Dev
    qreal vehicleTypeDefaultSpeedDev;

    // Default Parameter Color
    QString vehicleTypeDefaultColor;

    // Default Parameter Emission Class
    QString vehicleTypeDefaultEmissionClass;

    // Default Parameter Gui Shape
    vehicleShape vehicleTypeDefaultguiShape;

    // Default Parameter Width
    qreal vehicleTypeDefaultWidth;

    // Default Parameter Filename
    QString vehicleTypeDefaultFilename;

    // Default Parameter Impatience
    qreal vehicleTypeDefaultImpatience;

    // Default Parameter Edge Change Model
    QString vehicleTypeDefaultEdgeChangeModel;

    // Default Parameter Act Bat Kap
    qreal vehicleTypeDefaultActBatKap;

    // Default Parameter Max Bat Kap
    qreal vehicleTypeDefaultMaxBatKap;

    // Default Parameter Power Max
    qreal vehicleTypeDefaultPowerMax;

    // Default Parameter Mass
    qreal vehicleTypeDefaultMass;

    // Default Parameter Front Surface Area
    qreal vehicleTypeDefaultFrontSurfaceArea;

    // Default Parameter Coefficiente
    qreal vehicleTypeDefaultAirDragCoefficient;

    // Default Parameter Internal Moment Of Inertia
    qreal vehicleTypeDefaultInternalMomentOfInertia;

    // Default Parameter Radial Drag Coefficient
    qreal vehicleTypeDefaultRadialDragCoefficient;

    // Default Parameter Roll Drag Coefficient
    qreal vehicleTypeDefaultRollDragCoefficient;

    // Default Parameter Constant power Intake
    qreal vehicleTypeDefaultConstantPowerIntake;

    // Default Parameter Propulsion Efficiency
    qreal vehicleTypeDefaultPropulsionEfficiency;

    // Default Parameter Recuperation Efficiency
    qreal vehicleTypeDefaultRecuperationEfficiency;
};

#endif // VEHICLETYPEITEMCONFIGURATION_H
