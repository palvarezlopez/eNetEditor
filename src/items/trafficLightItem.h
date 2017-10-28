#ifndef TRAFFICLIGHTITEM_H
#define TRAFFICLIGHTITEM_H

#include "eNetEditorItem.h"


class trafficLightItem : public eNetEditorItem
{
public:

    trafficLightItem(nodeItem *newNodeParent, eNetEditorDatabase *database);

    ~trafficLightItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getItemId() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const trafficLightType &getType() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getProgramID() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getOffset() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getMaxGap() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getPassingTime() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getDetectorGap() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    nodeItem *getNodeParent() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QVector<int> &getVectorOfDuration(); /** cambiar a puntero **/


    // Set functions

    void setItemId(const QString &newID = "");

    void setType(const trafficLightType &newType);

    void setProgramID(const QString &newProgramID);

    void setOffset(int newOffset);

    void setMaxGap(int newMaxGap);

    void setPassingTime(int newPassingTime);

    void setDetectorGap(int newDetectorGap);

    void setDuration(int pos, int value);

    void setVectorOfDurations(const QVector<int> &newVectorOfDurations);


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // SUMO Parameter 02 - Type of Traffic light
    trafficLightType type;

    // SUMO Parameter 03 - ID Of program
    QString ProgramID;

    // SUMO Parameter 04 - Offset of traffic light
    int offset;

    // SUMO Parameter 05 - Max gap
    int maxGap;

    // SUMO Parameter 06 - Passing time
    int passingTime;

    // SUMO Parameter 07 - Detector gap
    int detectorGap;

    // QT Parmameter 01 - pointer to node
    nodeItem *nodeParent;

    // QT Parameter 02 - Vector with the duration of each state
    QVector<int> vectorOfDuration;
};

#endif // TRAFFICLIGHT_H
