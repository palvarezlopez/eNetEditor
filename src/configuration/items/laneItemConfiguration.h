#ifndef LANEITEMCONFIGURATION_H
#define LANEITEMCONFIGURATION_H

#include "eNetEditorItemConfiguration.h"


class laneItemConfiguration : public eNetEditorItemConfiguration
{
public:

    laneItemConfiguration();

    ~laneItemConfiguration();

    /**
        @brief Get Lane Width
        @return qreal value of the lane width
        @details Get lane width in the scene. This value is defined in itemsConfiguration.cpp, and cannot
        be changed. By default is 2.
    */
    qreal getLaneWidth() const;

    /**
        @brief Get Lane Offset
        @return qreal value of ane offset
        @details Get lane offset in the scene. This value is defined in itemsConfiguration.cpp, and cannot
        be changed. By default is 1.
    */
    qreal getLaneOffset() const;

    /**
        @brief Get Lane Rect Height
        @return qreal height of the lane Rect
        @details Get lane Rect height in the scene. This value is defined in itemsConfiguration.cpp, and cannot
        be changed. By default is 0.5.
    */
    qreal getLaneRectHeight() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QList<vehicleClass> &getLaneDefaultListOfAllowedVehicles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QList<vehicleClass> &getLaneDefaultListOfDisallowedVehicles() const;

private:

    /** FALTAN EXTRA PARAMETERS */

    // Parameter LaneWidth
    qreal laneWidth;

    // Parameter laneOffset
    qreal laneOffset;

    // Parameter laneRectHeight
    qreal laneRectHeight;

    // Default Parameter list of allowed vehicles
    QList<vehicleClass> laneDefaultListOfAllowedVehicles;

    // Default Parameter list of disallowed vehicles
    QList<vehicleClass> laneDefaultListOfDisallowedVehicles;
};

#endif // LANEITEMCONFIGURATION_H
