#ifndef FLOWMEASUREITEMCONFIGURATION_H
#define FLOWMEASUREITEMCONFIGURATION_H

#include "eNetEditorItemConfiguration.h"


class flowMeasureItemConfiguration : public eNetEditorItemConfiguration
{
public:

    flowMeasureItemConfiguration();

    ~flowMeasureItemConfiguration();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getFlowMeasureDefaultTime() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getFlowMeasureDefaultQPKW() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getFlowMeasureDefaultVPKW() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getFlowMeasureDefaultQLKW() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getFlowMeasureDefaultVLKW() const;


private:

    // Default Parameter Time
    int flowMeasureDefaultTime;

    // Default Parameter qPKW
    qreal flowMeasureDefaultQPKW;

    // Default Parameter vPKW
    qreal flowMeasureDefaultVPKW;

    // Default Parameter qLKW
    qreal flowMeasureDefaultQLKW;

    // Default Parameter vLKW
    qreal flowMeasureDefaultVLKW;
};

#endif // FLOWMEASUREITEMCONFIGURATION_H
