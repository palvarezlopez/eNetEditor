#ifndef ENETEDITORITEMITEM_H
#define ENETEDITORITEMITEM_H

#include "../main/eNetEditor.h"

class eNetEditorItem : public QGraphicsItem, public eNetEditor
{
public:

    // Constructor has to be called at end of each constructor item: myItem(parameters...) : netEditorItem() {...}
    eNetEditorItem(eNetEditorTable *newItemTable, const QString &newFirstColor = "white", QString newSecondColor = "black");

    // Each type of item has their own destructor
    virtual ~eNetEditorItem();

    virtual void make() = 0;

    virtual QDomElement saveItem(QDomDocument *domDoc) = 0;

    virtual QDomElement exportItemToXML(QDomDocument *domDoc) = 0;

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
    QRectF boundingRect() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QPen &getItemPen() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QFont &getItemFontText() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QPen &getItemPenText() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QStaticText &getItemLabel() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QColor &getItemColorSelected() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QColor &getItemColorMarked() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QColor &getItemFirstColor() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QColor &getItemSecondColor() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getExtraParameter1Name() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getExtraParameter1Value() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getExtraParameter2Name() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getExtraParameter2Value() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getExtraParameter3Value() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getExtraParameter3Name() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    eNetEditorTable *getItemTable() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    eNetEditorDatabase *getDatabase() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    eNetEditorScene *geteNetEditorScene() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    eNetEditorProject *getProject() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    itemManagerProject *getParameterManager() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    eNetEditorProjectConfiguration *getProjectConfiguration() const;


    // COMMON SET FUNCTIONS

    virtual void setItemId(const QString &newId);

    void setItemLabel(const QString &newId);

    void setBoundingRect(const QRectF &newBoundingRect);

    void setItemPen(const QColor &color, qreal penSize);

    void setItemPenColor(const QColor &color);

    void setItemPenSize(qreal penSize);

    void setItemPenText(const QColor &color, qreal penSize);

    void setItemFontText(const QString &textFont, qreal textSize, bool improveEfficiency = false);

    void setItemFirstColor(const QString &newFirstColor);

    void setItemSecondColor(const QString &newSecondColor);

    void setItemSelectable(bool value);

    void setItemMarked(bool value);

    void setItemGraphical(bool value, qreal newAltitude = 0);

    void setExtraParameter1Name(const QString &newExtraParameter1Name);

    void setExtraParameter1Value(const QString &newExtraParameter1Value);

    void setExtraParameter2Name(const QString &newExtraParameter2Name);

    void setExtraParameter2Value(const QString &newExtraParameter2Value);

    void setExtraParameter3Name(const QString &newExtraParameter3Name);

    void setExtraParameter3Value(const QString &newExtraParameter3Value);


    // COMMON IS FUNCTIONS

    bool isItemSelectable() const;

    bool isItemMarked() const;

    bool isItemMouseIn() const;

    bool isItemGraphical() const;


protected:

    // Each type of item has seir own paint function
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;

    // Each type of item has their own mouseMoveEvent Function
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    // HoverEnterEvent is common for all items
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);

    // HoverLeaveEvent is common for all items
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    // Each type of item has their own shape Function
    virtual QPainterPath shape() const = 0;


private:

    // Table of Item
    eNetEditorTable *itemTable;

    // QT Parameter 01 - ItemID
    QString id;

    // QT Parameter 03 - Label of the item to increase performance of drawing
    QStaticText label;

    // QT Parameter 04 - Bounding rect of the item
    QRectF boundingRectItem;

    // QT Parameter 05 - Size of contour of Item
    QPen penItem;

    // QT Parameter 06 - Font of the text Item
    QFont fontText;

    // QT Parameter 07 - Size of contour of text
    QPen penText;

    // QT Parameter 08 - Selected Color
    QColor selectedColor;

    // QT Parameter 09 - Marked Color
    QColor markedColor;

    // QT Parameter 10 - First color
    QColor firstColor;

    // QT Parameter 11 - Second color (When the mouse is out of item, or blocked)
    QColor secondColor;

    // QT Parameter 12 - Boolean to check if the item is marked (Always in green)
    bool isMarked;

    // QT Parameter 13 - Boolean to check if the item is marked (Green if mouse over item)
    bool isSelectable;

    // QT Parameter 14 - Boolean to check if the mouse is over the item
    bool isMouseIn;

    // QT Parameter 14 - Boolean to check if item is an graphical element
    bool graphical;

    // SUMO Extra parameter Name 1
    QString extraParameter1Name;

    // SUMO Extra parameter Value 1
    QString extraParameter1Value;

    // SUMO Extra parameter Name 2
    QString extraParameter2Name;

    // SUMO Extra parameter Value 2
    QString extraParameter2Value;

    // SUMO Extra parameter Name 3
    QString extraParameter3Name;

    // SUMO Extra parameter Value 3
    QString extraParameter3Value;
};

#endif // NETEDITORITEM_H
