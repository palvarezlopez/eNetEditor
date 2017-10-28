#ifndef MULTIENTRYEXITDETECTORSE3ITEMCONFIGURATION_H
#define MULTIENTRYEXITDETECTORSE3ITEMCONFIGURATION_H

#include "abstractDetectorItemConfiguration.h"


/*!
    \brief Multi Entry Exit E3 Detector item Configuration
    \author Pablo Álvarez López
    \date 2015
    \details This class keeps the default configuration of multi entry exit E3 detectors
 */
class multiEntryExitE3DetectorItemConfiguration : public eNetEditorDetectorConfiguration
{
public:

    /**
        @brief Constructor of multiEntryExitE3DetectorItemConfiguration
        @details Constructor of multiEntryExitE3DetectorItemConfiguration which load the specific default parameters of all multi entry exit E3 detectors
    */
    multiEntryExitE3DetectorItemConfiguration();

    /**
        @brief Destructor of multiEntryExitE3DetectorItemConfiguration
        @details Destructor of multiEntryExitE3DetectorItemConfiguration which destroy all created variables of this class
    */
    ~multiEntryExitE3DetectorItemConfiguration();
};

#endif // MULTIENTRYEXITDETECTORSE3ITEMCONFIGURATION_H
