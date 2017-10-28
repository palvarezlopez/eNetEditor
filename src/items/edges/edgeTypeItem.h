#ifndef EDGETYPEITEM_H
#define EDGETYPEITEM_H

#include "abstractEdgeItem.h"


class edgeTypeItem : public abstractEdgeItem
{
public:

    explicit edgeTypeItem(const QString &newId, eNetEditorDatabase *database);

    ~edgeTypeItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QStringList *getAllow() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QStringList *getDisallow() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumLanes() const;

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
    qreal getSpeed() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getSidewalkWidth() const;


    void setAllow(const QStringList &newAllow);

    void setDisallow(const QStringList &newDisallow);

    void SetDiscard(bool value);

    void setNumLanes(int newNumLanes);

    void setOneway(bool value);

    void setPriority(int newPriority);

    void setSpeed(qreal newSpeed);

    void setSidewalkWidth(qreal newSidewalkWidth);


    // IS FUNCTIONS

    bool isDiscard() const;

    bool isOneway() const;


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // SUMO Parameter 02 - List of allowed vehicles
    QStringList *allow;

    // SUMO Parameter 03 - List of disallowed vehicles
    QStringList *disallow;

    // SUMO Parameter 04 - If "true", edges of that type are not imported.
    bool discard;

    // SUMO Parameter 05 - Number of lanes of the edge
    int numLanes;

    // SUMO Parameter 06 - If "true", only the edge for one direction is created during the import
    bool oneway;

    // SUMO Parameter 07 -  A number, which determines the priority between different road types.
    int priority;

    // SUMO Parameter 08 -  The default (implicit) speed limit in m/s.
    qreal speed;

    // SUMO Parameter 09 -  The default width for added sidewalks (defaults to -1 which disables extra sidewalks).
    qreal sidewalkWidth;
};

#endif // TYPE_H
