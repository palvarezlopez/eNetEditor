#include "vehicleItemConfiguration.h"

vehicleItemConfiguration::vehicleItemConfiguration() : eNetEditorVehicleConfiguration()
{
    // Set item Extension
    setItemFileExtension("xml");

    // Set filename
    setItemFileName("vehicles");

    // Set vehicle defaults values
    vehicleDefaultDepart = 0;
}

vehicleItemConfiguration::~vehicleItemConfiguration()
{
    // Nothing to erase
}

int vehicleItemConfiguration::getVehicleDefaultDepart() const
{
    return vehicleDefaultDepart;
}
