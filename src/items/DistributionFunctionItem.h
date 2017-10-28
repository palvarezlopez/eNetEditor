#ifndef DISTRIBUTIONFUNCTIONITEM_H
#define DISTRIBUTIONFUNCTIONITEM_H

#include "eNetEditorItem.h"


class distributionFunctionItem : public eNetEditorItem
{
public:

    distributionFunctionItem(edgeItem *newEdgeParent, eNetEditorDatabase *database);

    ~distributionFunctionItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);

    void insertTime(int intervalBegin, int intervalEnd, int numerator, int denominator);

    QString toString();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    edgeItem *getEdgeParent() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getTrafficCount() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getPkwProcent() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getLkwProcent() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getPkwVelocity() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getLkwVelocity() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getSampling() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfIntervals();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QList<QVector<int> > getData();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QList<QVector<int> > getListOfIntervals();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QList<QVector<int> > getListOfFractions();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QList<int> getListOfNumerators();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QList<int> getListOfDenominators();


    // Set functions

    void setTrafficCount(int newNumberOfVehicles);

    void setPkwProcent(qreal newPkwProcent);

    void setPkwVelocity(qreal value);

    void setLkwVelocity(qreal value);

    void setVehicleVelocity(qreal newVehicleVelocity);

    void setData(const QList< QVector<int> > &newData);

    void setSampling(int newSampling);


    // Is functions

    bool isDistributionFunctionvalid();


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // Edge parent of the
    edgeItem *edgeParent;

    // Data of the distribution
    QList< QVector<int> > data;

    // Number of vehicles
    int trafficCount;

    // Procent of pkw
    qreal pkwProcent;

    // Velocity of pkw
    qreal pkwVelocity;

    // Velocity of lkw
    qreal lkwVelocity;

    // Sampling
    int sampling;
};

#endif // DISTRIBUTIONFUNCTIONITEM_H
