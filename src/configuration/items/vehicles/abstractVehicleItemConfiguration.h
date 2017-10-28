#ifndef ABSTRACTVEHICLECONFIGURATION_H
#define ABSTRACTVEHICLECONFIGURATION_H

#include "../eNetEditorItemConfiguration.h"


/*!
    \brief eNetEditor Vehicle Configuration
    \author Pablo Álvarez López
    \date 2015
    \details This abstract class keeps the common default configuration of flowItem and vehicleItem
 */
class eNetEditorVehicleConfiguration : public eNetEditorItemConfiguration
{
public:

    /**
        @brief Constructor of eNetEditorVehicleConfiguration
        @details Constructor of eNetEditorVehicleConfiguration which load the common default parameters of all edges
    */
    eNetEditorVehicleConfiguration();

    /**
        @brief Destructor of eNetEditorVehicleConfiguration
        @details Destructor of eNetEditorVehicleConfiguration which destroy all created variables of this class
    */
    ~eNetEditorVehicleConfiguration();

    /**
        @brief Get Vehicle Default color
        @return QString with the color of vehicle
        @details By default color is ""
    */
    const QString &getVehicleDefaultColor() const;

    /**
        @brief Get Vehicle Default Depart
        @return int with the vehicle depart
        @details By default is 0
    */
    int getVehicleDefaultDepart() const;

    /**
        @brief Get Vehicle Default Depart Lane
        @return QString with the depart lane
        @details By default is "first"
    */
    const QString &getVehicleDefaultDepartLane() const;

    /**
        @brief Get Vehicle Default Depart Pos
        @return vehicleStartPos enum with the depart Pos
        @details By default is "0"
    */
    const QString &getVehicleDefaultDepartPos() const;

    /**
        @brief Get Vehicle Default Depart Speed
        @return QString with the depart speed
        @details By default is "0"
    */
    const QString &getVehicleDefaultDepartSpeed() const;

    /**
        @brief Get Vehicle Default Arrival Lane
        @return QString with the arrival lane
        @details By default is "0"
    */
    const QString &getVehicleDefaultArrivalLane() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getVehicleDefaultArrivalPos() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getVehicleDefaultArrivalSpeed() const;
    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getVehicleDefaultLine() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getVehicleDefaultPersonNumber() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getVehicleDefaultContainerNumber() const;


private:

    // Vector with the start positions
    QVector<QString> vectorOfVehicleStartPositions;

    // Default Parameter Color
    QString vehicleDefaultColor;

    // Default Parameter Depart Pos
    QString vehicleDefaultDepartPos;

    // Default Parameter Depart Lane
    QString vehicleDefaultDepartLane;

    // Default Parameter Depart Speed
    QString vehicleDefaultDepartSpeed;

    // Default Parameter Arrival Lane
    QString vehicleDefaultArrivalLane;

    // Default Parameter Arrival Pos
    QString vehicleDefaultArrivalPos;

    // Default Parameter Arrival Speed
    QString vehicleDefaultArrivalSpeed;

    // Default Parameter Line
    QString vehicleDefaultLine;

    // Default Parameter Person Number
    int vehicleDefaultPersonNumber;

    // Default Parameter ContainterNumber
    int vehicleDefaultContainerNumber;
};

#endif // ENETEDITORVEHICLECONFIGURATION_H
