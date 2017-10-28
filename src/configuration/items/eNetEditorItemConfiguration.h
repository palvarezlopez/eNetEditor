#ifndef ENETEDITORITEMCONFIGURATION_H
#define ENETEDITORITEMCONFIGURATION_H

#include "../eNetEditorConfiguration.h"


/*!
    \brief eNetEditor item Configuration
    \author Pablo Álvarez López
    \date 2015
    \details
 */
class eNetEditorItemConfiguration : public eNetEditorConfiguration
{
public:

    /**
        @brief Constructor of itemsConfiguration
        @details Constructor of itemsConfiguration which load the default parameters of all variables
        of this class
    */
    eNetEditorItemConfiguration();

    /**
        @brief Destructor of itemsConfiguration
        @details Destructor of itemsConfiguration which destroy all variables of this class
    */
    virtual ~eNetEditorItemConfiguration();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getItemAltitude() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getItemTextFont() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getItemTextSize() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QColor &getItemPenColor() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getItemPenSize() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QColor &getItemTextPenColor() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getItemTextPenSize() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getItemFileName() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getItemFileExtension() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QString getItemFileNameWithExtension() const;

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
    const QString &getExtraParameter3Name() const;

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
    void setItemAltitude(qreal newItemAltitude);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    void setItemTextFont(const QString &newItemTextFont);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    void setItemTextSize(qreal newItemTextSize);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    void setItemPenColor(const QString &newItemPenColor);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    void setItemPenSize(qreal newItemPenSize);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    void setItemTextPenColor(const QString &newItemTextPenColor);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    void setItemTextPenSize(qreal newItemTextPenSize);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    void setItemFileName(const QString &newItemFileName);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    void setItemFileExtension(const QString &newItemFileExtension);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    void setExtraParameter1Name(const QString &newExtraParameter1Name);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    void setExtraParameter1Value(const QString &newExtraParameter1Value);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    void setExtraParameter2Name(const QString &newExtraParameter2Name);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    void setExtraParameter2Value(const QString &newExtraParameter2Value);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    void setExtraParameter3Name(const QString &newExtraParameter3Name);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    void setExtraParameter3Value(const QString &newExtraParameter3Value);


private:

    // Altitude of the item in the eNetEditorScene
    qreal itemAltitude;

    // Font of the text in the eNetEditorScene
    QString itemTextFont;

    // Size of the Text in the eNetEditorScene
    qreal itemTextSize;

    // Pen color of the Item in the eNetEditorScene
    QColor itemPenColor;

    // Pen Size of the item in the eNetEditorScene
    qreal itemPenSize;

    // Color of the pen of the text of the item in the eNetEditorScene
    QColor itemTextPenColor;

    // Size of the pen in the eNetEditorScene
    qreal itemTextPenSize;

    // Filename of the file in which the Item will be saved in SUMO Format
    QString itemFileName;

    // Extension of filename
    QString itemFileExtension;

    // Extra parameter 1 name
    QString extraParameter1Name;

    // Extra parameter 1 value
    QString extraParameter1Value;

    // Extra parameter 2 name
    QString extraParameter2Name;

    // Extra parameter 2 value
    QString extraParameter2Value;

    // Extra parameter 3 name
    QString extraParameter3Name;

    // Extra parameter 3 value
    QString extraParameter3Value;
};

#endif // ITEMSCONFIGURATION_H
