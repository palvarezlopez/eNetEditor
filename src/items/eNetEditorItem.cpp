#include "eNetEditorItem.h"

// eNetEditor Dialog
#include "../dialogs/main/eNetEditorMainWindow.h"

// eNetEditorScene
#include "../project/eNetEditorScene.h"

// Configuration
#include "../configuration/main/eNetEditorMainConfiguration.h"

// Table
#include "../database/eNetEditorTable.h"

// DataBase
#include "../database/eNetEditorDatabase.h"

// Project
#include "../project/eNetEditorProject.h"

// Parameter Manager
#include "../project/itemManagerProject.h"


eNetEditorItem::eNetEditorItem(eNetEditorTable *newItemTable, const QString &newFirstColor, QString newSecondColor) : QGraphicsItem(), eNetEditor()
{
    // Link Table
    itemTable = newItemTable;

    // By default, all item are movables
    setFlag(QGraphicsItem::ItemIsMovable, true);

    // By default, all item aren't selectables
    setFlag(QGraphicsItem::ItemIsSelectable, false);

    // Accept hover eventos (for the color change)
    setAcceptHoverEvents(true);

    // Set Selected Color
    selectedColor.setNamedColor("lightgreen");

    // Set Marked Color
    markedColor.setNamedColor("yellow");

    // Set firstColor
    firstColor.setNamedColor(newFirstColor);

    // Set secondColor
    secondColor.setNamedColor(newSecondColor);

    // By default, the item isn't origin
    isMarked = false;

    // By default, the mouse is over the item
    isMouseIn = false;

    // By default, item isn't selectable
    isSelectable = false;

    // By default item isn't graphical
    graphical = false;

    // Insert item in table
    getItemTable()->addeNetEditorItem(this);
}

eNetEditorItem::~eNetEditorItem()
{
    // Erase item of table
    getItemTable()->eraseeNetEditorItem(this);
}

const QString &eNetEditorItem::getItemId() const
{
    return id;
}

QRectF eNetEditorItem::boundingRect() const
{
    return boundingRectItem;
}

const QPen &eNetEditorItem::getItemPen() const
{
    return penItem;
}

const QFont &eNetEditorItem::getItemFontText() const
{
    return fontText;
}

const QPen &eNetEditorItem::getItemPenText() const
{
    return penText;
}

const QStaticText &eNetEditorItem::getItemLabel() const
{
    return label;
}

const QColor &eNetEditorItem::getItemColorSelected() const
{
    return selectedColor;
}

const QColor &eNetEditorItem::getItemColorMarked() const
{
    return markedColor;
}

const QColor &eNetEditorItem::getItemFirstColor() const
{
    return firstColor;
}

const QColor &eNetEditorItem::getItemSecondColor() const
{
    return secondColor;
}

const QString &eNetEditorItem::getExtraParameter1Name() const
{
    return extraParameter1Name;
}

const QString &eNetEditorItem::getExtraParameter1Value() const
{
    return extraParameter1Value;
}

const QString &eNetEditorItem::getExtraParameter2Name() const
{
    return extraParameter2Name;
}

const QString &eNetEditorItem::getExtraParameter2Value() const
{
    return extraParameter2Value;
}

const QString &eNetEditorItem::getExtraParameter3Value() const
{
    return extraParameter3Value;
}

const QString &eNetEditorItem::getExtraParameter3Name() const
{
    return extraParameter3Name;
}

eNetEditorTable *eNetEditorItem::getItemTable() const
{
    return itemTable;
}

eNetEditorDatabase *eNetEditorItem::getDatabase() const
{
    return itemTable->getDatabase();
}

eNetEditorScene *eNetEditorItem::geteNetEditorScene() const
{
    return itemTable->getDatabase()->geteNetEditorScene();
}

eNetEditorProject *eNetEditorItem::getProject() const
{
    return itemTable->getDatabase()->geteNetEditorScene()->getProject();
}

itemManagerProject *eNetEditorItem::getParameterManager() const
{
    return itemTable->getDatabase()->geteNetEditorScene()->getProject()->getParameterManager();
}

eNetEditorProjectConfiguration *eNetEditorItem::getProjectConfiguration() const
{
    return itemTable->getDatabase()->geteNetEditorScene()->getProject()->geteNetEditorMainWindow()->geteNetEditorConfiguration()->getProjectConfiguration();
}

void eNetEditorItem::setItemId(const QString &newId)
{
    id = newId;
}

void eNetEditorItem::setItemLabel(const QString &newId)
{
    label.setText(newId);
}

void eNetEditorItem::setBoundingRect(const QRectF &newBoundingRect)
{
    // Prepare change in the geometry item
    prepareGeometryChange();

    // Set bounding Rect
    boundingRectItem = newBoundingRect;

    // Update scene
    update();
}

void eNetEditorItem::setItemPen(const QColor &color, qreal penSize)
{
    penItem = QPen(color, penSize, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
}

void eNetEditorItem::setItemPenColor(const QColor &color)
{
    penItem = QPen(color, penItem.widthF(), Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
}

void eNetEditorItem::setItemPenSize(qreal penSize)
{
    penItem = QPen(penItem.brush(), penSize, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
}

void eNetEditorItem::setItemPenText(const QColor &color, qreal penSize)
{
    penText = QPen(color, penSize, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
}

void eNetEditorItem::setItemFontText(const QString &textFont, qreal textSize, bool improveEfficiency)
{
    // Set font
    fontText.setFamily(textFont);

    // Set size
    fontText.setPointSizeF(textSize);

    // If improveEfficiency is enabled
    if(improveEfficiency)
    {
        // Set style strategy as default
        fontText.setStyleStrategy(QFont::PreferDefault);
    }
    else
    {
        // Set font as bitmap (more efficient)
        fontText.setStyleStrategy(QFont::PreferBitmap);
    }
}

void eNetEditorItem::setItemFirstColor(const QString &newFirstColor)
{
    firstColor = newFirstColor;
}

void eNetEditorItem::setItemSecondColor(const QString &newSecondColor)
{
    secondColor = newSecondColor;
}

void eNetEditorItem::setItemSelectable(bool value)
{
    // Change graphics item selected flag.
    isSelectable = value;
}

void eNetEditorItem::setItemMarked(bool value)
{
    isMarked = value;
}

void eNetEditorItem::setItemGraphical(bool value, qreal newAltitude)
{
    // Set value
    graphical = value;

    // If item is graphical
    if(graphical == true)
    {
        // Add element to scene
        getItemTable()->getDatabase()->geteNetEditorScene()->addItem(this);

        // set ZValue
        setZValue(newAltitude);
    }
}

void eNetEditorItem::setExtraParameter1Name(const QString &newExtraParameter1Name)
{
    extraParameter1Name = newExtraParameter1Name;
}

void eNetEditorItem::setExtraParameter1Value(const QString &newExtraParameter1Value)
{
    extraParameter1Value = newExtraParameter1Value;
}

void eNetEditorItem::setExtraParameter2Name(const QString &newExtraParameter2Name)
{
    extraParameter2Name = newExtraParameter2Name;
}

void eNetEditorItem::setExtraParameter2Value(const QString &newExtraParameter2Value)
{
    extraParameter2Value = newExtraParameter2Value;
}

void eNetEditorItem::setExtraParameter3Name(const QString &newExtraParameter3Name)
{
    extraParameter3Name = newExtraParameter3Name;
}

void eNetEditorItem::setExtraParameter3Value(const QString &newExtraParameter3Value)
{
    extraParameter3Value = newExtraParameter3Value;
}

bool eNetEditorItem::isItemSelectable() const
{
    return isSelectable;
}

bool eNetEditorItem::isItemMarked() const
{
    return isMarked;
}

bool eNetEditorItem::isItemMouseIn() const
{
    return isMouseIn;
}

bool eNetEditorItem::isItemGraphical() const
{
    return graphical;
}

void eNetEditorItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Call QGraphicsItem event
    QGraphicsItem::mouseMoveEvent(event);
}

void eNetEditorItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    // If the mouse enter in the node
    if(event->isAccepted())
    {
        // Set flag isMouseIn enabled
        isMouseIn = true;
    }
}

void eNetEditorItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    // If the mouse leave the node
    if(event->isAccepted())
    {
        // Set flag isMouseIn disabled
        isMouseIn = false;
    }
}
