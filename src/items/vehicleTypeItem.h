#ifndef VEHICLETYPEITEM_H
#define VEHICLETYPEITEM_H

#include "eNetEditorItem.h"

class vehicleTypeItem : public eNetEditorItem
{
public:

    vehicleTypeItem(const QString &newId, eNetEditorDatabase *database);

    ~vehicleTypeItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);

    void addVehicle(vehicleItem *v);

    void removeVehicle(vehicleItem *v);

    void clearVehicle()
    {

    }

    void addFlow(flowItem *f);

    void removeFlow(flowItem *f);

    void clearFlow()
    {

    }

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getAccel() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getDecel() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getSigma() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getTau() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getLength() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getMinGap() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getMaxSpeed() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getSpeedFactor() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getSpeedDev() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getColor() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    vehicleClass getVClass() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getEmissionClass() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    vehicleShape getGuiShape() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getWidth() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getImgFilename() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getImpatience() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getLaneChangeModel() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getActBatKap() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getMaxBatKap() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getPowerMax() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getMass() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getFrontSurfaceArea() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getAirDragCoefficient() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getInternalMomentOfInertia() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getRadialDragCoefficient() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getRollDragCoefficient() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getConstantPowerIntake() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getPropulsionEfficiency() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getRecuperationEfficiency() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfVehicles();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfFlows();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    vehicleItem *getFirstVehicle();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    flowItem *getFirstFlow();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    vehicleItem *getLastVehicle();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    flowItem *getLastFlow();

    // SET FUNCTIONS

    void setAccel(qreal newAccel);

    void setDecel(qreal newDecel);

    void setSigma(qreal newSigma);

    void setTau(qreal newTau);

    void setLength(qreal newLength);

    void setMinGap(qreal newMinGap);

    void setMaxSpeed(qreal newMaxSpeed);

    void setSpeedFactor(qreal newSpeedFactor);

    void setSpeedDev(qreal newSpeedDev = 0.0);

    void setColor(const QString &newColor = "0,0,1");

    void setVClass(vehicleClass newVClass);

    void setEmissionClass(const QString &newEmissionClass);

    void setGuiShape(vehicleShape newGuiShape);

    void setWidth(qreal newWidth);

    void setImgFilename(const QString &newFilename);

    void setImpatience(qreal newImpatience);

    void setLaneChangeModel(const QString &newEdgeChangeModel);

    void setActBatKap(qreal newActBatKap);

    void setMaxBatKap(qreal newMaxBatKap);

    void setPowerMax(qreal newPowerMax);

    void setMass(qreal newMass);

    void setFrontSurfaceArea(qreal newFrontSurfaceArea);

    void setAirDragCoefficient(qreal newAirDragCoefficient);

    void setInternalMomentOfInertia(qreal newInternalMomentOfInertia);

    void setRadialDragCoefficient(qreal newRadialDragCoefficient);

    void setRollDragCoefficient(qreal newRollDragCoefficient);

    void setConstantPowerIntake(qreal newConstantPowerIntake);

    void setPropulsionEfficiency(qreal newPropulsionEfficiency);

    void setRecuperationEfficiency(qreal newRecuperationEfficiency);

    void setRemovable(bool newRemovable);


    // IS FUNCTION

    bool isRemovable();


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // List of vehicles wich this Vehicle Type atribute
    QList<vehicleItem *> listOfVehicles;

    // List of flow wich this Vehicle Type atribute
    QList<flowItem *> listOfFlows;

    // SUMO Parameter 02 - accel - The acceleration ability of vehicles of this type (in m/s^2)
    qreal accel;

    // SUMO Parameter 03 - decel - The deceleration ability of vehicles of this type (in m/s^2)
    qreal decel;

    // SUMO Parameter 04 - sigma Car-following model parameter, see below
    qreal sigma;

    // SUMO Parameter 05 - tau - Car-following model parameter
    qreal tau;

    // SUMO Parameter 06 - length - The vehicle's netto-length (length) (in m)
    qreal length;

    // SUMO Parameter 07 - minGap - Empty space after leader [m]
    qreal minGap;

    // SUMO Parameter 08 - maxSpeed - The vehicle's maximum velocity (in m/s)
    qreal maxSpeed;

    // SUMO Parameter 09 - speedFactor - The vehicles expected multiplicator for edge speed limits
    qreal speedFactor;

    // SUMO Parameter 10 - speedDev - The deviation of the speedFactor
    qreal speedDev;

    // SUMO Parameter 11 - color - This vehicle type's color
    QString color;

    // SUMO Parameter 12 - vClass - An abstract vehicle class (see below)
    vehicleClass vClass;

    // SUMO Parameter 13 - emission Class - An abstract emission class
    QString emissionClass;

    // SUMO Parameter 14 - guiShape - How this vehicle is rendered (Will be implemented in other version)
    vehicleShape guiShape;

    // SUMO Parameter 15 - width - The vehicle's width [m] (only used for drawing)
    qreal width;

    // SUMO Parameter 16 - filename - Image file for rendering vehicles of this type (should be grayscale to allow functional coloring)
    QString filename;

    // SUMO Parameter 17 - impatience - Willingess of drivers to impede vehicles with higher priority.
    qreal impatience;

    // SUMO Parameter 18 - edge Change Model - Edge changing model name
    QString laneChangeModel;

    // SUMO Parameter 19 - Actual battery capacity
    qreal actBatKap;

    // SUMO Parameter 20 - Max battery capacity
    qreal maxBatKap;

    // SUMO Parameter 21 - Power Max
    qreal powerMax;

    // SUMO Parameter 22 - Mass of vehicle
    qreal mass;

    // SUMO Parameter 23 - Front surface area
    qreal frontSurfaceArea;

    // SUMO Parameter 24 - Air drag coefficient
    qreal airDragCoefficient;

    // SUMO Parameter 25 - Internal moment of inertia
    qreal internalMomentOfInertia;

    // SUMO Parameter 26 - Radial drag coefficient
    qreal radialDragCoefficient;

    // SUMO Parameter 27 - Roll drag coefficient
    qreal rollDragCoefficient;

    // SUMO Parameter 28 - Constant power intake
    qreal constantPowerIntake;

    // SUMO Parameter 29 - Propulsion Efficienciy
    qreal propulsionEfficiency;

    // SUMO Parameter 30 - Recuperation efficiency
    qreal recuperationEfficiency;

    // QT Parameter 01 - Vehicle is removable
    bool removable;
};

#endif // VEHICLETYPE_H
