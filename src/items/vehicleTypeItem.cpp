#include "vehicleTypeItem.h"

// Configuration
#include "../configuration/project/eNetEditorProjectConfiguration.h"
#include "../configuration/items/vehicleTypeItemConfiguration.h"

// Parameter Manager
#include "../project/itemManagerProject.h"

// Database
#include "../database/eNetEditorDatabase.h"
#include "../database/vehicleTypeTable.h"

// Parameter Manager
#include "../project/itemManagerProject.h"

// Item
#include "vehicles/vehicleItem.h"
#include "vehicles/flowItem.h"


vehicleTypeItem::vehicleTypeItem(const QString &newId, eNetEditorDatabase *database) : eNetEditorItem(database->getVehicleTypeTable())
{
    // Set vehicle ID
    eNetEditorItem::setItemId(newId);

    // Set default
    accel = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultAccel();

    // Set default
    decel = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultDecel();

    // Set default
    sigma = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultSigma();

    // Set default
    tau = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultTau();

    // Set default
    length = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultLength();

    // Set default
    minGap = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultMinGap();

    // Set default
    maxSpeed = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultMaxSpeed();

    // Set default
    speedFactor = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultSpeedFactor();

    // Set default
    speedDev = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultSpeedDev();

    // Set default
    color = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultColor();

    // Set default
    vClass = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultVClass();

    // Set default
    emissionClass = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultEmissionClass();

    // Set default
    guiShape = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultGuiShape();

    // Set default
    width = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultWidth();

    // Set default
    filename = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultFilename();

    // Set default
    impatience = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultImpatience();

    // Set default
    laneChangeModel = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultLaneChangeModel();

    // Set default
    actBatKap = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultActBatKap();

    // Set default
    maxBatKap = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultMaxBatKap();

    // Set default
    powerMax = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultPowerMax();

    // Set default
    mass = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultMass();

    // Set default
    frontSurfaceArea = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultFrontSurfaceArea();

    // Set default
    airDragCoefficient = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultAirDragCoefficient();

    // Set default
    internalMomentOfInertia = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultInternalMomentOfInertia();

    // Set default
    radialDragCoefficient = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultRadialDragCoefficient();

    // Set default
    rollDragCoefficient = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultRollDragCoefficient();

    // Set default
    constantPowerIntake = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultConstantPowerIntake();

    // Set default
    propulsionEfficiency = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultPropulsionEfficiency();

    // Set default
    recuperationEfficiency = getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeDefaultRecuperationEfficiency();

    // By default, a vehicle is removable
    removable = true;

    /*
    // If the id of the new vehicle is ""
    if(vt->getItemId() == "")
    {
        // Set automatic ID
        vt->setItemId(vt->getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeClassValue(vt->getVClass()) + QString::number(nextVehicleTypeIndex.at(vt->getVClass())));
    }
    */
}

vehicleTypeItem::~vehicleTypeItem()
{
    // Create a copy of list of vehicles wich this Vehicle Type as atribute
    QList<vehicleItem *> copyOfListOfVehicles;

    // Iterate over copy of list of vehicles
    for(QList<vehicleItem *>::iterator i = copyOfListOfVehicles.begin(); i != copyOfListOfVehicles.end(); i++)
    {
        // Delete vehicle
        delete (*i);
    }

    // Create a copy of list of flow wich this Vehicle Type as atribute
    QList<flowItem *> copyOfListOfFlows;

    // Iterate over copy of list of flows
    for(QList<flowItem *>::iterator i = copyOfListOfFlows.begin(); i != copyOfListOfFlows.end(); i++)
    {
        // Delete vehicle
        delete (*i);
    }
}

void vehicleTypeItem::make()
{
    // Nothing to make
}

QDomElement vehicleTypeItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("vehicleType");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement vehicleTypeItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;
    QDomElement itemDomElementBat;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("vType");

    // Set attribute accel
    itemDomElement.setAttribute("accel", QString::number(accel));

    // Set attribute
    itemDomElement.setAttribute("decel", QString::number(decel));

    // Set attribute
    itemDomElement.setAttribute("sigma", QString::number(sigma));

    // Set attribute
    itemDomElement.setAttribute("tau", QString::number(tau));

    // Set attribute
    itemDomElement.setAttribute("length", QString::number(length));

    // Set attribute
    itemDomElement.setAttribute("minGap", QString::number(minGap));

    // Set attribute
    itemDomElement.setAttribute("maxSpeed", QString::number(maxSpeed));

    // Set attribute
    itemDomElement.setAttribute("speedFactor", QString::number(speedFactor));

    // Set attribute
    itemDomElement.setAttribute("speedDev", QString::number(speedDev));

    // Set attribute
    itemDomElement.setAttribute("color", color);

    // Set attribute
    itemDomElement.setAttribute("color", getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeClassValue(vClass));

    // Set attribute
    itemDomElement.setAttribute("emissionClass", emissionClass  /*getProjectConfiguration()->getVehicleTypeItemConfiguration()->getVehicleTypeEmissionValue(emissionClass) **/);

    // Set attribute
    itemDomElement.setAttribute("guiShape", QString::number(guiShape));

    // Set attribute
    itemDomElement.setAttribute("width", QString::number(width));

    // Set attribute
    if(filename != "")
    {
        itemDomElement.setAttribute("filename", filename);
    }

    // Set attribute
    itemDomElement.setAttribute("impatience", QString::number(impatience));

    // Set attribute
    itemDomElement.setAttribute("laneChangeModel", laneChangeModel);

    // Set attribute actBatKap
    itemDomElementBat = domDoc->createElement("param");

    // Set key
    itemDomElementBat.setAttribute("key", "actBatKap");

    // Set value
    itemDomElementBat.setAttribute("value", QString::number(actBatKap));

    // Append child
    itemDomElement.appendChild(itemDomElementBat);

    // Set attribute maxBatKap
    itemDomElementBat = domDoc->createElement("param");

    // Set key
    itemDomElementBat.setAttribute("key", "maxBatKap");

    // Set value
    itemDomElementBat.setAttribute("value", QString::number(maxBatKap));

    // Append child
    itemDomElement.appendChild(itemDomElementBat);

    // Set attribute powerMax
    itemDomElementBat = domDoc->createElement("param");

    // Set key
    itemDomElementBat.setAttribute("key", "powerMax");

    // Set value
    itemDomElementBat.setAttribute("value", QString::number(powerMax));

    // Append child
    itemDomElement.appendChild(itemDomElementBat);

    // Set attribute mass
    itemDomElementBat = domDoc->createElement("param");

    // Set key
    itemDomElementBat.setAttribute("key", "mass");

    // Set value
    itemDomElementBat.setAttribute("value", QString::number(mass));

    // Append child
    itemDomElement.appendChild(itemDomElementBat);

    // Set attribute frontSurfaceArea
    itemDomElementBat = domDoc->createElement("param");

    // Set key
    itemDomElementBat.setAttribute("key", "frontSurfaceArea");

    // Set value
    itemDomElementBat.setAttribute("value", QString::number(frontSurfaceArea));

    // Append child
    itemDomElement.appendChild(itemDomElementBat);

    // Set attribute airDragCoefficient
    itemDomElementBat = domDoc->createElement("param");

    // Set key
    itemDomElementBat.setAttribute("key", "airDragCoefficient");

    // Set value
    itemDomElementBat.setAttribute("value", QString::number(airDragCoefficient));

    // Append child
    itemDomElement.appendChild(itemDomElementBat);

    // Set attribute internalMomentOfInertia
    itemDomElementBat = domDoc->createElement("param");

    // Set key
    itemDomElementBat.setAttribute("key", "internalMomentOfInertia");

    // Set value
    itemDomElementBat.setAttribute("value", QString::number(internalMomentOfInertia));

    // Append child
    itemDomElement.appendChild(itemDomElementBat);

    // Set attribute radialDragCoefficient
    itemDomElementBat = domDoc->createElement("param");

    // Set key
    itemDomElementBat.setAttribute("key", "radialDragCoefficient");

    // Set value
    itemDomElementBat.setAttribute("value", QString::number(rollDragCoefficient));

    // Append child
    itemDomElement.appendChild(itemDomElementBat);

    // Set attribute constantPowerIntake
    itemDomElementBat = domDoc->createElement("param");

    // Set key
    itemDomElementBat.setAttribute("key", "constantPowerIntake");

    // Set value
    itemDomElementBat.setAttribute("value", QString::number(constantPowerIntake));

    // Append child
    itemDomElement.appendChild(itemDomElementBat);

    // Set attribute propulsionEfficiency
    itemDomElementBat = domDoc->createElement("param");

    // Set key
    itemDomElementBat.setAttribute("key", "propulsionEfficiency");

    // Set value
    itemDomElementBat.setAttribute("value", QString::number(propulsionEfficiency));

    // Append child
    itemDomElement.appendChild(itemDomElementBat);

    // Set attribute recuperationEfficiency
    itemDomElementBat = domDoc->createElement("param");

    // Set key
    itemDomElementBat.setAttribute("key", "recuperationEfficiency");

    // Set value
    itemDomElementBat.setAttribute("value", QString::number(recuperationEfficiency));

    // Append child
    itemDomElement.appendChild(itemDomElementBat);

    // Return itemDomElement
    return itemDomElement;
}

void vehicleTypeItem::addVehicle(vehicleItem *v)
{
    listOfVehicles.push_back(v);
}

void vehicleTypeItem::removeVehicle(vehicleItem *v)
{
    listOfVehicles.removeAll(v);
}

void vehicleTypeItem::addFlow(flowItem *f)
{
    listOfFlows.push_back(f);
}

void vehicleTypeItem::removeFlow(flowItem *f)
{
    listOfFlows.removeAll(f);
}

qreal vehicleTypeItem::getAccel() const
{
    return accel;
}

qreal vehicleTypeItem::getDecel() const
{
    return decel;
}

qreal vehicleTypeItem::getSigma() const
{
    return sigma;
}

qreal vehicleTypeItem::getTau() const
{
    return tau;
}

qreal vehicleTypeItem::getLength() const
{
    return length;
}

qreal vehicleTypeItem::getMinGap() const
{
    return minGap;
}

qreal vehicleTypeItem::getMaxSpeed() const
{
    return maxSpeed;
}

qreal vehicleTypeItem::getSpeedFactor() const
{
    return speedFactor;
}

qreal vehicleTypeItem::getSpeedDev() const
{
    return speedDev;
}

const QString &vehicleTypeItem::getColor() const
{
    return color;
}

vehicleClass vehicleTypeItem::getVClass() const
{
    return vClass;
}

const QString &vehicleTypeItem::getEmissionClass() const
{
    return emissionClass;
}

vehicleShape vehicleTypeItem::getGuiShape() const
{
    return guiShape;
}

qreal vehicleTypeItem::getWidth() const
{
    return width;
}

const QString &vehicleTypeItem::getImgFilename() const
{
    return filename;
}

qreal vehicleTypeItem::getImpatience() const
{
    return impatience;
}

const QString &vehicleTypeItem::getLaneChangeModel() const
{
    return laneChangeModel;
}

qreal vehicleTypeItem::getActBatKap() const
{
    return actBatKap;
}

qreal vehicleTypeItem::getMaxBatKap() const
{
    return maxBatKap;
}

qreal vehicleTypeItem::getPowerMax() const
{
    return powerMax;
}

qreal vehicleTypeItem::getMass() const
{
    return mass;
}

qreal vehicleTypeItem::getFrontSurfaceArea() const
{
    return frontSurfaceArea;
}

qreal vehicleTypeItem::getAirDragCoefficient() const
{
    return airDragCoefficient;
}

qreal vehicleTypeItem::getInternalMomentOfInertia() const
{
    return internalMomentOfInertia;
}

qreal vehicleTypeItem::getRadialDragCoefficient() const
{
    return radialDragCoefficient;
}

qreal vehicleTypeItem::getRollDragCoefficient() const
{
    return rollDragCoefficient;
}

qreal vehicleTypeItem::getConstantPowerIntake() const
{
    return constantPowerIntake;
}

qreal vehicleTypeItem::getPropulsionEfficiency() const
{
    return propulsionEfficiency;
}

qreal vehicleTypeItem::getRecuperationEfficiency() const
{
    return recuperationEfficiency;
}

int vehicleTypeItem::getNumberOfVehicles()
{
    return listOfVehicles.size();
}

int vehicleTypeItem::getNumberOfFlows()
{
    return listOfFlows.size();
}

vehicleItem *vehicleTypeItem::getFirstVehicle()
{
    if(listOfVehicles.size() > 0)
    {
        return listOfVehicles.first();
    }
    else
    {
        return NULL;
    }
}

flowItem *vehicleTypeItem::getFirstFlow()
{
    if(listOfFlows.size() > 0)
    {
        return listOfFlows.first();
    }
    else
    {
        return NULL;
    }
}

vehicleItem *vehicleTypeItem::getLastVehicle()
{
    if(listOfVehicles.size() > 0)
    {
        return listOfVehicles.last();
    }
    else
    {
        return NULL;
    }
}

flowItem *vehicleTypeItem::getLastFlow()
{
    if(listOfFlows.size() > 0)
    {

        return listOfFlows.last();
    }
    else
    {
        return NULL;
    }
}



void vehicleTypeItem::setAccel(qreal newAccel)
{
    accel = newAccel;
}

void vehicleTypeItem::setDecel(qreal newDecel)
{
    decel = newDecel;
}

void vehicleTypeItem::setSigma(qreal newSigma)
{
    sigma = newSigma;
}

void vehicleTypeItem::setTau(qreal newTau)
{
    tau = newTau;
}

void vehicleTypeItem::setLength(qreal newLength)
{
    length = newLength;
}

void vehicleTypeItem::setMinGap(qreal newMinGap)
{
    minGap = newMinGap;
}

void vehicleTypeItem::setMaxSpeed(qreal newMaxSpeed)
{
    maxSpeed = newMaxSpeed;
}

void vehicleTypeItem::setSpeedFactor(qreal newSpeedFactor)
{
    speedFactor = newSpeedFactor;
}

void vehicleTypeItem::setSpeedDev(qreal newSpeedDev)
{
    speedDev = newSpeedDev;
}

void vehicleTypeItem::setColor(const QString &newColor)
{
    color = newColor;
}

void vehicleTypeItem::setVClass(vehicleClass newVClass)
{
    vClass = newVClass;
}

void vehicleTypeItem::setEmissionClass(const QString &newEmissionClass)
{
    emissionClass = newEmissionClass;
}

void vehicleTypeItem::setGuiShape(vehicleShape newGuiShape)
{
    guiShape = newGuiShape;
}

void vehicleTypeItem::setWidth(qreal newWidth)
{
    width = newWidth;
}

void vehicleTypeItem::setImgFilename(const QString &newFilename)
{
    filename = newFilename;
}

void vehicleTypeItem::setImpatience(qreal newImpatience)
{
    impatience = newImpatience;
}

void vehicleTypeItem::setLaneChangeModel(const QString &newEdgeChangeModel)
{
    laneChangeModel = newEdgeChangeModel;
}

void vehicleTypeItem::setActBatKap(qreal newActBatKap)
{
    actBatKap = newActBatKap;
}

void vehicleTypeItem::setMaxBatKap(qreal newMaxBatKap)
{
    maxBatKap = newMaxBatKap;
}

void vehicleTypeItem::setPowerMax(qreal newPowerMax)
{
    powerMax = newPowerMax;
}

void vehicleTypeItem::setMass(qreal newMass)
{
    mass = newMass;
}

void vehicleTypeItem::setFrontSurfaceArea(qreal newFrontSurfaceArea)
{
    frontSurfaceArea = newFrontSurfaceArea;
}

void vehicleTypeItem::setAirDragCoefficient(qreal newAirDragCoefficient)
{
    airDragCoefficient = newAirDragCoefficient;
}

void vehicleTypeItem::setInternalMomentOfInertia(qreal newInternalMomentOfInertia)
{
    internalMomentOfInertia = newInternalMomentOfInertia;
}

void vehicleTypeItem::setRadialDragCoefficient(qreal newRadialDragCoefficient)
{
    radialDragCoefficient = newRadialDragCoefficient;
}

void vehicleTypeItem::setRollDragCoefficient(qreal newRollDragCoefficient)
{
    rollDragCoefficient = newRollDragCoefficient;
}

void vehicleTypeItem::setConstantPowerIntake(qreal newConstantPowerIntake)
{
    constantPowerIntake = newConstantPowerIntake;
}

void vehicleTypeItem::setPropulsionEfficiency(qreal newPropulsionEfficiency)
{
    propulsionEfficiency = newPropulsionEfficiency;
}

void vehicleTypeItem::setRecuperationEfficiency(qreal newRecuperationEfficiency)
{
    recuperationEfficiency = newRecuperationEfficiency;
}

void vehicleTypeItem::setRemovable(bool newRemovable)
{
    removable = newRemovable;
}

bool vehicleTypeItem::isRemovable()
{
    return removable;
}

void vehicleTypeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Nothing to draw
    Q_UNUSED(painter);
}

void vehicleTypeItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath vehicleTypeItem::shape() const
{
    // This item don't have shape
    return QPainterPath();
}
