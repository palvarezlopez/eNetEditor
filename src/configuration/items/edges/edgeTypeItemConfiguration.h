#ifndef EDGETYPEITEMCONFIGURATION_H
#define EDGETYPEITEMCONFIGURATION_H

#include "abstractEdgeItemConfiguration.h"


/*!
    \brief Edge Type Item Configuration
    \author Pablo Álvarez López
    \date 2015
    \details This class keeps the default configuration of edge types
 */
class edgeTypeItemConfiguration : public eNetEditorEdgeConfiguration
{
public:

    /**
        @brief Constructor of edgeTypeItemConfiguration
        @details Constructor of edgeTypeItemConfiguration which load the common default parameters of all edges
    */
    edgeTypeItemConfiguration();

    /**
        @brief Destructor of edgeTypeItemConfiguration
        @details Destructor of edgeTypeItemConfiguration which destroy all created variables of this class
    */
    ~edgeTypeItemConfiguration();

    /**
        @brief Get Edge Item Default OneWay
        @return true if oneWay is enabled, false in other case
        @details By default is false
    */
    bool getOneway() const;

    /**
        @brief Get EdgeType Item Default Discard
        @return true if discard is enabled, false in other case
        @details By default is false
    */
    bool getDiscard() const;


private:

    // Default Parameter discard
    bool discard;

    // Default Parameter oneway
    bool oneway;

};

#endif // EDGETYPEITEMCONFIGURATION_H
