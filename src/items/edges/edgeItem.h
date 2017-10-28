#ifndef EDGEITEM_H
#define EDGEITEM_H

#include "abstractEdgeItem.h"

/// FALTA shape


class edgeItem : public abstractEdgeItem
{
public:

    explicit edgeItem(nodeItem *newOrigin, nodeItem *newDestiny, eNetEditorDatabase *database);

    ~edgeItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);

    void updateEdgeLabel();

    void addLane(laneItem *l);

    void removeLane(laneItem *l);

    void clearLanes(bool dontRemoveFirstLane = true);

    void addRoute(routeItem *r);

    void removeRoute(routeItem *r);

    void clearRoutes();

    void addInductionLoopsE1Detector(inductionLoopsE1DetectorItem *E1);

    void removeInductionLoopsE1Detector(inductionLoopsE1DetectorItem *E1);

    void clearInductionLoopsE1Detector();

    void addLaneAreaE2Detector(laneAreaE2DetectorItem *E2);

    void removeLaneAreaE2Detector(laneAreaE2DetectorItem *E2);

    void clearLaneAreaE2Detector();

    void addMultiEntryExitE3Detector(multiEntryExitE3DetectorItem *E3);

    void removeMultiEntryExitE3Detector(multiEntryExitE3DetectorItem *E3);

    void clearMultiEntryExitE3Detector();

    void addFlowMeasure(flowMeasureItem *fm);

    void removeFlowMeasure(flowMeasureItem *fm);

    void clearFlowMeasure();

    void addTurnRatioFrom(turnRatioItem *tr);

    void removeTurnRatioFrom(turnRatioItem *tr);

    void clearTurnRatioFrom();

    void addTurnRatioTo(turnRatioItem *tr);

    void removeTurnRatioTo(turnRatioItem *tr);

    void clearTurnRatioTo();


    // GET FUNCTIONS

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    nodeItem *getNodeOrigin() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    nodeItem *getNodeDestiny() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    edgeTypeItem *getType() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfLanes() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getSpeed() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getPriority() const;

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
    edgeSpreadType getSpreadType() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getStreetName() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    laneItem *getLane(int index);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    routeItem *getRoute(int index);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QLineF getExternalLine() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QLineF getCentralLine() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QLineF getInternalLine() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getDistanceBetweenCenters() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    distributionFunctionItem *getDistributionFunction() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfRoutes() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfInductionLoopsE1Detectors() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfFlowMeasures() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    laneItem *getLaneByIndex(int index) const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    laneItem *getFirstLane() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    laneItem *getLastLane() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    routeItem *getFirstRoute() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    routeItem *getLastRoute() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    inductionLoopsE1DetectorItem *getFirstInductionLoopsE1Detector() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    inductionLoopsE1DetectorItem *getLastInductionLoopsE1Detector() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    flowMeasureItem *getFirstFlowMeasure() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    flowMeasureItem *getLastFlowMeasure() const;


    // SET FUNCTIONS

    void setItemId(const QString &newId = "");

    void setType(edgeTypeItem *newType);

    void setSpeed(qreal newSpeed);

    void setPriority(const int newPriority);

    void setSpreadType(edgeSpreadType newSpreadType);

    void setStreetName(const QString &newStreetName);

    void setDistributionFunction(distributionFunctionItem *newFunction);


    // Iterator functions

    QList<laneItem *>::iterator iteratorLanesBegin();

    QList<laneItem *>::iterator iteratorLanesEnd();

    QList<routeItem *>::iterator iteratorRoutesBegin();

    QList<routeItem *>::iterator iteratorRoutesEnd();

    QList<inductionLoopsE1DetectorItem *>::iterator iteratorInductionLoopsE1Begin();

    QList<inductionLoopsE1DetectorItem *>::iterator iteratorInductionLoopsE1End();

    QList<flowMeasureItem *>::iterator iteratorFlowMeasureBegin();

    QList<flowMeasureItem *>::iterator iteratorFlowMeasureEnd();

    QList<turnRatioItem *>::iterator iteratorTurnRatioFromBegin();

    QList<turnRatioItem *>::iterator iteratorTurnRatioFromEnd();

    QList<turnRatioItem *>::iterator iteratorTurnRatioToBegin();

    QList<turnRatioItem *>::iterator iteratorTurnRatioToEnd();


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // SUMO Parameter 01 - Id (Not editable, format:  <origin->id()>to<destiny->id()> )
    // Derivable from parameters SUMO 02 and SUMO 03

    // SUMO Parameter 02 - From (Not modificable)
    nodeItem *nodeOrigin;

    // SUMO Parameter 03 - To (Not modificable)
    nodeItem *nodeDestiny;

    // SUMO Parameter 04 - Type of edge
    edgeTypeItem *type;

    // SUMO Parameter 05 - Num of lanes
    // Derivable from list of lanes

    // SUMO Parameter 06 - Speed
    qreal speed;

    // SUMO Parameter 07 - Priority
    int priority;

    // SUMO Parameter 08 - Length
    // Derivable from centralLine;

    // SUMO Parameter 09 - Shape
    QString shapeParameter;

    // SUMO Parameter 10 - SpreadType
    edgeSpreadType spreadType;

    // SUMO Parameter 11 - allow
    // Implemeneted in each lane

    // SUMO Parameter 12 - disallow
    // Implemeneted in each lane

    // SUMO Parameter 13 - Street Name
    QString name;

    // SUMO Parameter 14 - End Offset
    qreal endOffset;

    // SUMO Parameter 15 - Sidewalk Width
    qreal sidewalkWidth;

    // QT Parameter 01 - List whit the lanes of edge.
    QList<laneItem *> listOfLanes;

    // QT Parameter 02 - List with the routes that contains this edge
    QList<routeItem *> listOfRoutes;

    // QT Parameter 03 - List with the Induction Loops E1 Detectors that contains this edge
    QList<inductionLoopsE1DetectorItem *> listOfE1;

    // QT Parameter 04 - List with the lane Area E2 Detectors that contains this edge
    QList<laneAreaE2DetectorItem *> listOfE2;

    // QT Parameter 05 - List with the Multi Entry Exit E3 Detectors that contains this edge
    QList<multiEntryExitE3DetectorItem *> listOfE3;

    // QT Parameter 06 - List with the flow measures relatives to this edge
    QList<flowMeasureItem *> listOfFlowMeasures;

    // QT Parameter 07 - List with the turn Ratios from this edge
    QList<turnRatioItem *> listOfTurnRatiosFrom;

    // QT Parameter 07 - List with the turn Ratios to this edge
    QList<turnRatioItem *> listOfTurnRatiosTo;

    // QT Parameter 08 - Rect that form the lane
    QRectF edgeRect;

    // QT Parameter 09 - Distance between centers of nodeOrigin and NodeDestiny
    qreal distanceBetweenCenters;

    // QT Parameter 10 - Rect with the icon
    QRectF iconRect;

    // QT Parameter 11 - Distribution function
    distributionFunctionItem *distributionFunction;
};

#endif // edge_H
