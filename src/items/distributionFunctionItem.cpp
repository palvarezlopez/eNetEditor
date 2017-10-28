#include "distributionFunctionItem.h"

// Configuration
#include "../configuration/project/eNetEditorProjectConfiguration.h"
#include "../configuration/items/distributionFunctionItemConfiguration.h"

// Parameter Manager
#include "../project/itemManagerProject.h"

// Database
#include "../database/eNetEditorDatabase.h"
#include "../database/distributionFunctionTable.h"

// Project
#include "../project/eNetEditorProject.h"

//Item
#include "edges/edgeItem.h"
#include "laneItem.h"
#include "flowMeasureItem.h"
#include "detectors/inductionLoopsE1DetectorItem.h"


distributionFunctionItem::distributionFunctionItem(edgeItem *newEdgeParent, eNetEditorDatabase *database) : eNetEditorItem(database->getDistributionFunctionTable())
{
    // Link edge parent
    edgeParent = newEdgeParent;

    // Set Item ID
    setItemId("distributionF_" + edgeParent->getItemId());

    // Set default number of vehicles
    trafficCount = getProjectConfiguration()->getDistributionFunctionItemConfiguration()->getDistributionFunctionDefaultTrafficCount();

    // Set default procent of pkw
    pkwProcent = getProjectConfiguration()->getDistributionFunctionItemConfiguration()->getDistributionFunctionDefaultPkwProcent();

    // Set default velocity of pkw
    pkwVelocity = getProjectConfiguration()->getDistributionFunctionItemConfiguration()->getDistributionFunctionDefaultPKWVelocity();

    // Set default velocity of lkw
    lkwVelocity = getProjectConfiguration()->getDistributionFunctionItemConfiguration()->getDistributionFunctionDefaultLKWVelocity();

    // Set default sampling
    sampling = getProjectConfiguration()->getDistributionFunctionItemConfiguration()->getDistributionFunctionDefaultSampling();

    // Set distribution function
    edgeParent->setDistributionFunction(this);
}

distributionFunctionItem::~distributionFunctionItem()
{
    // Remove distribution function
    edgeParent->setDistributionFunction(NULL);
}

void distributionFunctionItem::make()
{
    // Drop existent flow measures associated with this distribution functtion
    while(edgeParent->getNumberOfFlowMeasures() > 0)
    {
        delete (edgeParent->getFirstFlowMeasure());
    }

    // Calculate procent
    qreal procentInEachDetector = qreal(1) / getEdgeParent()->getNumberOfLanes();

    // Iterate over data
    for(QList< QVector<int> >::iterator i = data.begin(); i != data.end(); i++)
    {
        // If flow measure is in the range of time of simulation
        if(((*i).at(0) >= getProject()->getTimeBegin()) && (*i).at(0) <= (getProject()->getTimeEnd()))
        {
            // Calculate fraccion
            qreal value = qreal((*i).at(2)) / qreal((*i).at(3));

            // Iterate over lanes
            for(int j = 0; j < getEdgeParent()->getNumberOfLanes(); j++)
            {
                // get Lane
                laneItem *l = getEdgeParent()->getLane(j);

                // Insert flow measure in first E1 detector
                flowMeasureItem *fm = new flowMeasureItem(l->getFirstInductionLoopsE1Detector(), getDatabase());

                // set Time
                fm->setTime((*i).at(0));

                // Set qPKW
                fm->setQPKW(trafficCount * procentInEachDetector * value * getPkwProcent());

                // Set vPKW
                fm->setVPKW(pkwVelocity);

                // Set qLKW
                fm->setQLKW(trafficCount * procentInEachDetector * value * getLkwProcent());

                // Set vLKW
                fm->setVLKW(lkwVelocity);
            }
        }
    }
}

QDomElement distributionFunctionItem::saveItem(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("distributionFunction");

    // Return itemDomElement
    return itemDomElement;
}

QDomElement distributionFunctionItem::exportItemToXML(QDomDocument *domDoc)
{
    // Declare QDomElement
    QDomElement itemDomElement;

    // Create QDomElement with the corresponding type
    itemDomElement = domDoc->createElement("distributionFunction");

    /** Pendiente **/

    // Return itemDomElement
    return itemDomElement;
}

void distributionFunctionItem::insertTime(int intervalBegin, int intervalEnd, int numerator, int denominator)
{
    // Insert new values
    QVector<int> dataToInsert;

    // Insert interval begin
    dataToInsert.push_back(intervalBegin);

    // Insert interval end
    dataToInsert.push_back(intervalEnd);

    // Insert numerator
    dataToInsert.push_back(numerator);

    // Insert denominator
    dataToInsert.push_back(denominator);

    // insert value in list
    data.push_back(dataToInsert);
}

QString distributionFunctionItem::toString()
{
    // Declare QString to keep function
    QString functionString;

    // Declare integers to transform time
    int beginIntervalNumberOfHours;
    int beginIntervalNumberOfMinutes;
    int endIntervalNumberOfHours;
    int endIntervalNumberOfMinutes;

    // Save data of function in the string with the correspond format
    for(QList< QVector<int> >::iterator i = data.begin(); i != data.end(); i++)
    {
        // Calculate number of hours in the begin interval
        beginIntervalNumberOfHours = (*i).at(0) / 60;

        // Calculate number of minutes in the end interval
        beginIntervalNumberOfMinutes = (*i).at(0) - (beginIntervalNumberOfHours * 60);

        // Calculate number of hours in the end interval
        endIntervalNumberOfHours = (*i).at(1) / 60;

        // Calculate number of minutes in the end interval
        endIntervalNumberOfMinutes = (*i).at(1) - (endIntervalNumberOfHours * 60);

        // Update String
        functionString += ( QString::number(beginIntervalNumberOfHours) + ":" +
                            QString::number(beginIntervalNumberOfMinutes) + "-" +
                            QString::number(endIntervalNumberOfHours) + ":" +
                            QString::number(endIntervalNumberOfMinutes) + "-" +
                            QString::number((*i).at(2)) + "/" +
                            QString::number((*i).at(3)) + "\n");
    }

    // Return functionString
    return functionString;
}

edgeItem *distributionFunctionItem::getEdgeParent() const
{
    return edgeParent;
}

int distributionFunctionItem::getTrafficCount() const
{
    return trafficCount;
}

qreal distributionFunctionItem::getPkwProcent() const
{
    return pkwProcent;
}

qreal distributionFunctionItem::getLkwProcent() const
{
    return (1 - pkwProcent);
}

qreal distributionFunctionItem::getPkwVelocity() const
{
    return pkwVelocity;
}

qreal distributionFunctionItem::getLkwVelocity() const
{
    return lkwVelocity;
}

int distributionFunctionItem::getSampling() const
{
    return sampling;
}

int distributionFunctionItem::getNumberOfIntervals()
{
    return data.size();
}

QList< QVector<int> > distributionFunctionItem::getData()
{
    return data;
}

QList< QVector<int> > distributionFunctionItem::getListOfIntervals()
{
    // Declare list of intervals
    QList< QVector<int> > listOfIntervals;

    // Iterate over data
    for(QList< QVector<int> >::iterator i = data.begin(); i != data.end(); i++)
    {
        // Declare interval
        QVector<int> interval;

        // Fill interval
        interval.push_back((*i).at(0));
        interval.push_back((*i).at(1));

        // Add interval to list of intervals
        listOfIntervals.push_back(interval);
    }

    // Return list of intervals
    return listOfIntervals;
}

QList< QVector<int> >  distributionFunctionItem::getListOfFractions()
{
    // Declare list of fractions
    QList< QVector<int> >  listOfFraction;

    // Iterate over data
    for(QList< QVector<int> >::iterator i = data.begin(); i != data.end(); i++)
    {
        // Declare fraction
        QVector<int> fraction;

        // Fill fraction
        fraction.push_back((*i).at(2));
        fraction.push_back((*i).at(3));

        // Add interval to list of fractions
        listOfFraction.push_back(fraction);
    }

    // Return list of fractions
    return listOfFraction;
}

QList<int> distributionFunctionItem::getListOfNumerators()
{
    // Declare list of Numerators
    QList<int> listOfNumerators;

    // Interate over list
    for(QList< QVector<int> >::iterator i = data.begin(); i != data.end(); i++)
    {
        // Insert numerator in list
        listOfNumerators.push_back((*i).at(2));
    }

    // Return list of Numerators
    return listOfNumerators;
}

QList<int> distributionFunctionItem::getListOfDenominators()
{
    // Declare list of Denominators
    QList<int> listOfDenominators;

    // Iterate over data
    for(QList< QVector<int> >::iterator i = data.begin(); i != data.end(); i++)
    {
        // Insert denominator in list
        listOfDenominators.push_back((*i).at(3));
    }

    // Return list of Denominators
    return listOfDenominators;
}

void distributionFunctionItem::setTrafficCount(int newNumberOfVehicles)
{
    trafficCount = newNumberOfVehicles;
}

void distributionFunctionItem::setPkwProcent(qreal newPkwProcent)
{
    pkwProcent = newPkwProcent;
}

void distributionFunctionItem::setData(const QList< QVector<int> > &newData)
{
    data = newData;
}

void distributionFunctionItem::setSampling(int newSampling)
{
    sampling = newSampling;
}

void distributionFunctionItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Ignore warnings
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Nothing to draw
    Q_UNUSED(painter);
}

void distributionFunctionItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Due the position is defined by the nodes, this event is ignored
    event->ignore();
}

QPainterPath distributionFunctionItem::shape() const
{
    // This item don't have shape
    return QPainterPath();
}

void distributionFunctionItem::setLkwVelocity(qreal value)
{
    lkwVelocity = value;
}

void distributionFunctionItem::setPkwVelocity(qreal value)
{
    pkwVelocity = value;
}

bool distributionFunctionItem::isDistributionFunctionvalid()
{
    qDebug() << "OVERFLOW PROBLEM";

    // Declare long int values
    long long int multiplicationOfDenominators = 1;
    long long int sumatorialOfNumerators = 0;

    // Get multiplicatorial of all denominators
    for(QList< QVector<int> >::iterator i = data.begin(); i != data.end(); i++)
    {
        qDebug() << (*i).at(3) << " - " << multiplicationOfDenominators;

        multiplicationOfDenominators *= (*i).at(3);
    }

    // get sumatorial of all: multiplicationOfDenominators / denominator * numerator
    for(QList< QVector<int> >::iterator i = data.begin(); i != data.end(); i++)
    {
        sumatorialOfNumerators += (multiplicationOfDenominators / (((*i).at(3)) * ((*i).at(2))));
    }

    qDebug() << multiplicationOfDenominators << " " << sumatorialOfNumerators;

    // If multiplicationOfDenominators and sumatorialOfNumerators have the same values
    if (multiplicationOfDenominators == sumatorialOfNumerators)
    {
        // Function valid, then return true
        return true;
    }
    else
    {
        // Function not valid, then return false
        return false;
    }
}

