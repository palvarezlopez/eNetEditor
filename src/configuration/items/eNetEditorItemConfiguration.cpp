#include "eNetEditorItemConfiguration.h"


eNetEditorItemConfiguration::eNetEditorItemConfiguration() : eNetEditorConfiguration()
{
    // Set default item altitude
    itemAltitude = 0;

    // Set default Item Text Font
    itemTextFont = "arial";

    // Set default Item Text Size
    itemTextSize = 1;

    // Set default Item Pen Color
    itemPenColor = QColor("black");

    // Set default Pen Size
    itemPenSize = 1;

    // Set default Text Pen Color
    itemTextPenColor = QColor("white");

    // Set default Item Pen Size
    itemTextPenSize = 0;

    // Set default Item Filename
    itemFileName = "undefinied";

    // Set default extra parameter 1 name
    extraParameter1Name = "";

    // Set default extra parameter 1 value
    extraParameter1Value = "";

    // Set default extra parameter 2 name
    extraParameter2Name = "";

    // Set default extra parameter 2 value
    extraParameter2Value = "";

    // Set default extra parameter 3 name
    extraParameter3Name = "";

    // Set default extra parameter 3 value
    extraParameter3Value = "";
}

eNetEditorItemConfiguration::~eNetEditorItemConfiguration()
{
    // Nothing to erase
}

qreal eNetEditorItemConfiguration::getItemAltitude() const
{
    return itemAltitude;
}

const QString &eNetEditorItemConfiguration::getItemTextFont() const
{
    return itemTextFont;
}

qreal eNetEditorItemConfiguration::getItemTextSize() const
{
    return itemTextSize;
}

const QColor &eNetEditorItemConfiguration::getItemPenColor() const
{
    return itemPenColor;
}

qreal eNetEditorItemConfiguration::getItemPenSize() const
{
    return itemPenSize;
}

const QColor &eNetEditorItemConfiguration::getItemTextPenColor() const
{
    return itemTextPenColor;
}

qreal eNetEditorItemConfiguration::getItemTextPenSize() const
{
    return itemTextPenSize;
}

const QString &eNetEditorItemConfiguration::getItemFileName() const
{
    return itemFileName;
}

const QString &eNetEditorItemConfiguration::getItemFileExtension() const
{
    return itemFileExtension;
}

QString eNetEditorItemConfiguration::getItemFileNameWithExtension() const
{
    return itemFileName + "." + itemFileExtension;
}

const QString &eNetEditorItemConfiguration::getExtraParameter1Name() const
{
    return extraParameter1Name;
}

const QString &eNetEditorItemConfiguration::getExtraParameter1Value() const
{
    return extraParameter1Value;
}

const QString &eNetEditorItemConfiguration::getExtraParameter2Name() const
{
    return extraParameter2Name;
}

const QString &eNetEditorItemConfiguration::getExtraParameter2Value() const
{
    return extraParameter2Value;
}

const QString &eNetEditorItemConfiguration::getExtraParameter3Name() const
{
    return extraParameter3Name;
}

const QString &eNetEditorItemConfiguration::getExtraParameter3Value() const
{
    return extraParameter3Value;
}

void eNetEditorItemConfiguration::setItemAltitude(qreal newItemAltitude)
{
    itemAltitude = newItemAltitude;
}

void eNetEditorItemConfiguration::setItemTextFont(const QString &newItemTextFont)
{
    itemTextFont = newItemTextFont;
}

void eNetEditorItemConfiguration::setItemTextSize(qreal newItemTextSize)
{
    itemTextSize = newItemTextSize;
}

void eNetEditorItemConfiguration::setItemPenColor(const QString &newItemPenColor)
{
    itemPenColor.setNamedColor(newItemPenColor);
}

void eNetEditorItemConfiguration::setItemPenSize(qreal newItemPenSize)
{
    itemPenSize = newItemPenSize;
}

void eNetEditorItemConfiguration::setItemTextPenColor(const QString &newItemTextPenColor)
{
    itemTextPenColor.setNamedColor(newItemTextPenColor);
}

void eNetEditorItemConfiguration::setItemTextPenSize(qreal newItemTextPenSize)
{
    itemTextPenSize = newItemTextPenSize;
}

void eNetEditorItemConfiguration::setItemFileName(const QString &newItemFileName)
{
    itemFileName = newItemFileName;
}

void eNetEditorItemConfiguration::setItemFileExtension(const QString &newItemFileExtension)
{
    itemFileExtension = newItemFileExtension;
}

void eNetEditorItemConfiguration::setExtraParameter1Name(const QString &newExtraParameter1Name)
{
    extraParameter1Name = newExtraParameter1Name;
}

void eNetEditorItemConfiguration::setExtraParameter1Value(const QString &newExtraParameter1Value)
{
    extraParameter1Value = newExtraParameter1Value;
}

void eNetEditorItemConfiguration::setExtraParameter2Name(const QString &newExtraParameter2Name)
{
    extraParameter2Name = newExtraParameter2Name;
}

void eNetEditorItemConfiguration::setExtraParameter2Value(const QString &newExtraParameter2Value)
{
    extraParameter2Value = newExtraParameter2Value;
}

void eNetEditorItemConfiguration::setExtraParameter3Name(const QString &newExtraParameter3Name)
{
    extraParameter3Name = newExtraParameter3Name;
}

void eNetEditorItemConfiguration::setExtraParameter3Value(const QString &newExtraParameter3Value)
{
    extraParameter3Value = newExtraParameter3Value;
}
