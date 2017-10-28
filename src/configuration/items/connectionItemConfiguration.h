#ifndef CONNECTIONITEMCONFIGURATION_H
#define CONNECTIONITEMCONFIGURATION_H

#include "eNetEditorItemConfiguration.h"


class connectionItemConfiguration : public eNetEditorItemConfiguration
{
public:

    connectionItemConfiguration();

    ~connectionItemConfiguration();

    /**
        @brief Get Connection Direction value
        @param cDirection connectionDirection of the connection
        @return QString with the corresponding value of connectionDirectionStraight
        @details Get the QString value of connectionDirection (Example: connectionDirectionStraight returns "S")
    */
    const QString &getConnectionDirectionValue(connectionDirection cDirection) const;

    /**
        @brief Get Connection State value
        @param cState connectionState of the connection
        @return char with the corresponding value of connectionState
        @details Get the char value of connectionState (Example: connectionStateRed returns "r")
    */
    char getConnectionStatesValue(connectionState cState) const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    bool getConnectionDefaultPass() const;


private:

    // Vector with the connection directions
    QVector<QString> vectorOfConnectionDirections;

    // Vector
    QVector<char> vectorOfConnectionStates;

    // Default Parameter Pass
    bool connectionDefaultPass;
};

#endif // CONNECTIONITEMCONFIGURATION_H
