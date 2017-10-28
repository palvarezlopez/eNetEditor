#ifndef INDUCTIONLOOPSDETECTORE1ITEMCONFIGURATION_H
#define INDUCTIONLOOPSDETECTORE1ITEMCONFIGURATION_H

#include "abstractDetectorItemConfiguration.h"


/*!
    \brief induction Loops E1 Detector item Configuration
    \author Pablo Álvarez López
    \date 2015
    \details This class keeps the default configuration of induction loops E1 detectors
 */
class inductionLoopsE1DetectorItemConfiguration : public eNetEditorDetectorConfiguration
{
public:

    /**
        @brief Constructor of inductionLoopsE1DetectorItemConfiguration
        @details Constructor of inductionLoopsE1DetectorItemConfiguration which load the specific default parameters of all induction loops E1 detectors
    */
    inductionLoopsE1DetectorItemConfiguration();

    /**
        @brief Destructor of inductionLoopsE1DetectorItemConfiguration
        @details Destructor of inductionLoopsE1DetectorItemConfiguration which destroy all created variables of this class
    */
    ~inductionLoopsE1DetectorItemConfiguration();

    /**
        @brief Get Induction Loops E1 Item Default Detector Definition Filename
        @return QString with the default detector definition filename
        @details By default is "detectorDefinitions".
    */
    const QString &getInductionLoopsE1DetectorItemDefaultDetectorDefinitionsFileName();

    /**
        @brief Get Induction Loops E1 Item Default Detector Definition Extension
        @return QString with the default detector definition extension
        @details By default is "xml".
    */
    const QString &getInductionLoopsE1DetectorItemDefaultDetectorDefinitionsExtension();

    /**
        @brief Get Induction Loops E1 Item Default Detector Definition Filename with extension
        @return QString with the default detector definition filename with extension
        @details By default is "detectorDefinitions.xml".
    */
    QString getInductionLoopsE1DetectorItemDefaultDetectorDefinitionsFileNameWithExtension();

    /**
        @brief Get Induction Loops E1 Item Default Friendly Pos
        @return boolean with the value true if friendly pos is enabled, false in other case
        @details By default is false.
    */
    bool getInductionLoopsE1DetectorItemDefaultFriendlyPos() const;

    /**
        @brief Get Induction Loops E1 Item Default Split By Type
        @return boolean with the value true if split by type is enabled, false in other case
        @details By default is false.
    */
    bool getInductionLoopsE1DetectorItemDefaultSplitByType() const;


private:

    // InductionLoopsE1DetectorItem default parameter detector definition filename
    QString inductionLoopsE1DetectorItemDefaultDetectorDefinitionsFileName;

    // InductionLoopsE1DetectorItem default parameter detector definition extension
    QString inductionLoopsE1DetectorItemDefaultDetectorDefinitionsExtension;

    // InductionLoopsE1DetectorItem default parameter friendly pos
    bool inductionLoopsE1DetectorItemDefaultFriendlyPos;

    // InductionLoopsE1DetectorItem default parameter split by type
    bool inductionLoopsE1DetectorItemDefaultSplitByType;
};

#endif // INDUCTIONLOOPSDETECTORE1ITEMCONFIGURATION_H
