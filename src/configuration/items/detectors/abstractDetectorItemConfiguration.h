#ifndef ABSTRACTDETECTORITEMCONFIGURATION_H
#define ABSTRACTDETECTORITEMCONFIGURATION_H

#include "../eNetEditorItemConfiguration.h"


/*!
    \brief eNetEditor Detector Configuration
    \author Pablo Álvarez López
    \date 2015
    \details This abstract class keeps the default configuration of inductionLoopsE1DetectorItem, laneAreaE2DetectorItem and multiEntryExitE3DetectorItem
 */
class eNetEditorDetectorConfiguration : public eNetEditorItemConfiguration
{
public:

    /**
        @brief Constructor of eNetEditorDetectorConfiguration
        @details Constructor of eNetEditorDetectorConfiguration which load the common default parameters of all detectors
    */
    eNetEditorDetectorConfiguration();

    /**
        @brief Destructor of eNetEditorDetectorConfiguration
        @details Destructor of eNetEditorDetectorConfiguration which destroy all created variables of this class
    */
    ~eNetEditorDetectorConfiguration();

    /**
        @brief Get Detector Default Position
        @return qreal with the deafult position of detector in lane
        @details By default is 0.
    */
    qreal getDetectorDefaultPos() const;

    /**
        @brief Get Detector Default Frequency
        @return int with the default frequency of detector
        @details By default is 1.
    */
    int getDetectorDefaultFrequency() const;

    /**
        @brief Get Detector Default Filename Output
        @return QString with the default filename output of a detector
        @details By default is "".
    */
    const QString &getDetectorDefaultFileNameOutput() const;


private:

    // Detector Default Pos
    qreal detectorDefaultPos;

    // Detector Default Frequency
    int detectorDefaultFrequency;

    // Detector Default Filename Output
    QString detectorDefaultFileNameOutput;
};

#endif // ENETEDITORDETECTORITEMCONFIGURATION_H
