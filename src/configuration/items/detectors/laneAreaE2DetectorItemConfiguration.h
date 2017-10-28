#ifndef LANEAREADETECTORE2ITEMCONFIGURATION_H
#define LANEAREADETECTORE2ITEMCONFIGURATION_H

#include "abstractDetectorItemConfiguration.h"


/*!
    \brief Lane Area E2 Detector item Configuration
    \author Pablo Álvarez López
    \date 2015
    \details This class keeps the default configuration of lane area E2 detectors
 */
class laneAreaE2DetectorItemConfiguration : public eNetEditorDetectorConfiguration
{
public:

    /**
        @brief Constructor of laneAreaE2DetectorItemConfiguration
        @details Constructor of laneAreaE2DetectorItemConfiguration which load the specific default parameters of all lane area E2 detectors
    */
    laneAreaE2DetectorItemConfiguration();

    /**
        @brief Destructor of laneAreaE2DetectorItemConfiguration
        @details Destructor of laneAreaE2DetectorItemConfiguration which destroy all created variables of this class
    */
    ~laneAreaE2DetectorItemConfiguration();

    /**
        @brief Get Lane Area E2 Detector Item Default Friendly Pos
        @return boolean with the value true if friendlyPos is enabled, false in other case
        @details By default is false.
    */
    bool getLaneAreaE2DetectorItemDefaultFriendlyPos();

    /**
        @brief Get Lane Area E2 Detector Item Default Cont
        @return boolean with the value true if cont is enabled, false in other case
        @details By default is false.
    */
    bool getLaneAreaE2DetectorItemDefaultCont();

    /**
        @brief Get Lane Area E2 Detector Item Default Time Threshold
        @return int with the value of time threshold
        @details By default is 1.
    */
    int getLaneAreaE2DetectorItemDefaultTimeThreshold();

    /**
        @brief Get Lane Area E2 Detector Item Default Speed Threshold
        @return qreal with the vaue of speed threshold
        @details By default is 5/3.6.
    */
    qreal getLaneAreaE2DetectorItemDefaultSpeedThreshold();

    /**
        @brief Get Lane Area E2 Detector Item Default Jam Threshold
        @return qreal with the value of jam threshold
        @details By default is 10.
    */
    qreal getLaneAreaE2DetectorItemDefaultJamThreshold();


private:

    // LaneAreaE2DetectorItem defautl paramter friendlyPos
    bool laneAreaE2DetectorItemDefaultFriendlyPos;

    // LaneAreaE2DetectorItem default parameter cont
    bool laneAreaE2DetectorItemDefaultCont;

    // LaneAreaE2DetectorItem default parameter time threshold
    int laneAreaE2DetectorItemDefaultTimeThreshold;

    // LaneAreaE2DetectorItem default parameter speed threshold
    qreal laneAreaE2DetectorItemDefaultSpeedThreshold;

    // LaneAreaE2DetectorItem default parameter jam threshold
    qreal laneAreaE2DetectorItemDefaultJamThreshold;
};

#endif // LANEAREADETECTORE2ITEMCONFIGURATION_H
