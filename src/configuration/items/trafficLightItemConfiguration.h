#ifndef TRAFFICLIGHTITEMCONFIGURATION_H
#define TRAFFICLIGHTITEMCONFIGURATION_H

#include "eNetEditorItemConfiguration.h"


class trafficLightItemConfiguration : public eNetEditorItemConfiguration
{
public:

    trafficLightItemConfiguration();

    ~trafficLightItemConfiguration();

    /**
        @brief Get TrafficLight Type value
        @param tlType trafficLightType of the Traffic Light
        @return QString with the corresponding value of trafficLightType
        @details Get the QString value of trafficLightType (Example: trafficLightTypeStatic returns "static")
    */
    const QString &getTrafficLightTypeValue(trafficLightType tlType) const;


    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getTrafficLightDefaultDuration() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getTrafficLightPhaseGreenPriority() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getTrafficLightPhaseGreen() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getTrafficLightPhaseYellow() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getTrafficLightPhaseRed() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getTrafficLightPhaseBlack() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QColor &getTrafficLightColorGreenPriority() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QColor &getTrafficLightColorGreen() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QColor &getTrafficLightColorYellow() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */

    const QColor &getTrafficLightColorRed() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const trafficLightType &getTrafficLightDefaultType() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getTrafficLightDefaultOffset() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getTrafficLightDefaultMaxGap() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getTrafficLightDefaultPassingTime() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getTrafficLightDefaultDetectorGap() const;


private:

    // Vector with the traffic lights type
    QVector<QString> vectorOfTrafficLightsType;

    // Traffic lights Colors
    QString trafficLightPhaseGreenPriority;
    QString trafficLightPhaseGreen;
    QString trafficLightPhaseYellow;
    QString trafficLightPhaseRed;
    QString trafficLightPhaseBlack;

    // Traffic lights Colors QColor
    QColor trafficLightColorGreenPriority;
    QColor trafficLightColorGreen;
    QColor trafficLightColorYellow;
    QColor trafficLightColorRed;

    // Default Parameter Duration
    int trafficLightDefaultDuration;

    // Default Parameter Type
    trafficLightType trafficLightDefaultType;

    // Default Parameter Offset
    qreal trafficLightDefaultOffset;

    // Default Parameter Maxgap
    qreal trafficLightDefaultMaxGap;

    // Default Parameter Passing Time
    qreal trafficLightDefaultPassingTime;

    // Default Parameter Detector Gap
    qreal trafficLightDefaultDetectorGap;
};

#endif // TRAFFICLIGHTITEMCONFIGURATION_H
