#ifndef BUSSTOPITEMCONFIGURATION_H
#define BUSSTOPITEMCONFIGURATION_H

#include "../eNetEditorItemConfiguration.h"


class busStopItemConfiguration : public eNetEditorItemConfiguration
{
public:

    busStopItemConfiguration();

    ~busStopItemConfiguration();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getBusStopDefaultStartPos() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getBusStopDefaultEndPos() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getBusStopDefaultLines() const;


private:

    // Default Parameter StartPos
    qreal busStopDefaultStartPos;

    // Default Parameter End Pos
    qreal busStopDefaultEndPos;

    // Default Parameter Lines
    QString busStopDefaultLines;
};

#endif // BUSSTOPITEMCONFIGURATION_H
