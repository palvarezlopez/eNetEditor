#ifndef ABSTRACTEDGECONFIGURATION_H
#define ABSTRACTEDGECONFIGURATION_H

#include "../eNetEditorItemConfiguration.h"


/*!
    \brief eNetEditor Edge Configuration
    \author Pablo Álvarez López
    \date 2015
    \details This abstract class keeps the common default configuration of edgeItem and edgeTypeItem
 */
class eNetEditorEdgeConfiguration : public eNetEditorItemConfiguration
{
public:

    /**
        @brief Constructor of edgeItemConfiguration
        @details Constructor of edgeItemConfiguration which load the common default parameters of all edges
    */
    eNetEditorEdgeConfiguration();

    /**
        @brief Destructor of eNetEditorDetectorItemConfiguration
        @details Destructor of eNetEditorDetectorItemConfiguration which destroy all created variables of this class
    */
    ~eNetEditorEdgeConfiguration();

    /**
        @brief Get Edge Default Priority
        @return int with the priority of edge
        @details By default is 2.
    */
    int getEdgeDefaultPriority() const;

    /**
        @brief Get Edge Default Speed
        @return qreal with the speed of edge
        @details By default is 2.
    */
    qreal getEdgeDefaultSpeed() const;

    /**
        @brief Get Edge Sidewalk Width
        @return qreal with the sidewalk width
        @details By default is 2.
    */
    qreal getEdgeDefaultSidewalkWidth() const;


private:

    // Default Parameter Priority
    int edgeDefaultPriority;

    // Default Parameter Speed
    qreal edgeDefaultSpeed;

    // Default Parameter SidewalkWidth
    qreal edgeDefaultSidewalkWidth;

};

#endif // ENETEDITOREDGECONFIGURATION_H
