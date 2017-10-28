#ifndef VEHICLEITEMCONFIGURATION_H
#define VEHICLEITEMCONFIGURATION_H

#include "abstractVehicleItemConfiguration.h"


class vehicleItemConfiguration : public eNetEditorVehicleConfiguration
{
public:

    vehicleItemConfiguration();

    ~vehicleItemConfiguration();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getVehicleDefaultDepart() const;


private:

    // Default Parameter Depart
    int vehicleDefaultDepart;
};

#endif // VEHICLEITEMCONFIGURATION_H
