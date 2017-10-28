#ifndef EDGEITEMCONFIGURATION_H
#define EDGEITEMCONFIGURATION_H

#include "abstractEdgeItemConfiguration.h"

/*! \enum Edge Spread Type
    All spread type of Edge Item
*/
enum edgeSpreadType
{
    edgeSpreadTypeCenter, /*!< Edge spread type "center" */
    edgeSpreadTypeRight, /*!< Edge spread type "right" */
};

/*!
    \brief Edge Item Configuration
    \author Pablo Álvarez López
    \date 2015
    \details This class keeps the default configuration of edges
 */
class edgeItemConfiguration : public eNetEditorEdgeConfiguration
{
public:

    /**
        @brief Constructor of edgeItemConfiguration
        @details Constructor of edgeItemConfiguration which load the common default parameters of all edges
    */
    edgeItemConfiguration();

    /**
        @brief Destructor of eNetEditorDetectorItemConfiguration
        @details Destructor of eNetEditorDetectorItemConfiguration which destroy all created variables of this class
    */
    ~edgeItemConfiguration();

    /**
        @brief Get Edge Spread Type Value
        @param index enum of type edgeSpreadType
        @return QString with the value of each edgeSpreadType
        @details Returns the QString representation of each edgeSpreadType (For example, edgeSpreadTypeCenter returns "center")
    */
    const QString &getEdgeSpreadTypeValue(edgeSpreadType index);

    /**
        @brief Get Edge Width
        @return qreal width of the edge
        @details By default is 2.
    */
    qreal getEdgeWidth() const;

    /**
        @brief Get Edge Offset
        @return qreal value of the edge offset
        @details By default is 0.5.
    */
    qreal getEdgeOffset() const;

    /**
        @brief Get Edge Icon Offset
        @return qreal value of icon offset in the edge
        @details By default is 0.3.
    */
    qreal getEdgeIconOffset() const;

    /**
        @brief Get Edge Item default Shape
        @return QString with the shape of the edge
        @details Not implemented in this version, and by default is ""
    */
    QString getEdgeItemDefaultShape() const;

    /**
        @brief Get Edge Item Default Spread Type
        @return enum of type edgeSpreadType with the code of the corresponding spread type
        @details By default is "right"
    */
    edgeSpreadType getEdgeItemDefaultSpreadTyp() const;

    /**
        @brief Get Edge Item Default Widht
        @return qeal with the edge widht
        @details By default is 3.
    */
    qreal getEdgeItemDefaultWidth() const;

    /**
        @brief Get Edge Item Default Name
        @return QString with the street name
        @details By default is ""
    */
    QString getEdgeItemDefaultName() const;

    /**
        @brief Get Edge Item Default EndOffset
        @return qreal with the end offset of edge
        @details By default is  -1 which adds nothing).
    */
    qreal getEdgeItemDefaultEndOffset() const;


private:

    // Default Parameter list of edge Spread types
    QVector<QString> vectorOfEdgeSpreadTypes;

    // Default Parameter Width
    qreal edgeWidth;

    // Default Parameter Offset
    qreal edgeOffset;

    // Default Parameter IconOffset (Quitar)
    qreal edgeIconOffset;

    // Edge Item default
    QString edgeItemDefaultShape;

    // Edge Item default Spread Typ
    edgeSpreadType edgeItemDefaultSpreadTyp;

    // Edge Item default Width
    qreal edgeItemDefaultWidth;

    // Edge Item default Name
    QString edgeItemDefaultName;

    // Edge Item default EndOffset
    qreal edgeItemDefaultEndOffset;
};

#endif // EDGEITEMCONFIGURATION_H
