#ifndef ROUTEITEMCONFIGURATION_H
#define ROUTEITEMCONFIGURATION_H

#include "eNetEditorItemConfiguration.h"


class routeItemConfiguration : public eNetEditorItemConfiguration
{
public:

    routeItemConfiguration();

    ~routeItemConfiguration();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QString getRouteDefaultColor() const;


private:

    // Default Parameter Color
    QString routeDefaultColor;

};

#endif // ROUTEITEMCONFIGURATION_H
