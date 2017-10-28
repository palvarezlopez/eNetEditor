#ifndef PROHIBITIONITEM_H
#define PROHIBITIONITEM_H

#include "eNetEditorItem.h"


class prohibitionItem : public eNetEditorItem
{
public:

    prohibitionItem(edgeItem *newEdgeProhibitionOrigin, edgeItem *newEdgeProhibitionDestiny, eNetEditorDatabase *database);

    ~prohibitionItem();

    void make();

    QDomElement saveItem(QDomDocument *domDoc);

    QDomElement exportItemToXML(QDomDocument *domDoc);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    edgeItem *getEdgeProhibitionOrigin() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    edgeItem *getEdgeProhibitionDestiny() const;


    // SET FUNCTIONS

    void setItemId(const QString &newId = "");


protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QPainterPath shape() const;


private:

    // SUMO Parameter 01 - Pointer to lane prohibited origin
    edgeItem *edgeProhibitionOrigin;

    // SUMO Parameter 02 - Pointer to lane prohibited destiny
    edgeItem *edgeProhibitionDestiny;

    // QT Parameter 01 - Path with the shape of prohibition
    QGraphicsPathItem connectionPath;

    // QT Parameter 02 - Componente of the prohibition |---| (A B C D E)
    QLineF lineA;

    // QT Parameter 03 - Componente of the prohibition |---| (A B C D E)
    QLineF lineB;

    // QT Parameter 04 - Componente of the prohibition |---| (A B C D E)
    //QLineF lineC Not necessary now;

    // QT Parameter 03 - Componente of the prohibition |---| (A B C D E)
    QLineF lineD;

    // QT Parameter 03 - Componente of the prohibition |---| (A B C D E)
    QLineF lineE;

    // QT Parameter 05 - Node parent of the connection (Node-EdgeOrigin-nodeParent-EdgeDestiny-Node)
    nodeItem *nodeParent;

};

#endif // PROHIBITION_H
