#ifndef TRAFFICLIGHTSTABLE_H
#define TRAFFICLIGHTSTABLE_H

#include "eNetEditorTable.h"


class trafficLightTable : public eNetEditorTable
{
public:

    // 01 - Función terminada y documentada
    trafficLightTable(const QString &newNameOfTable, trafficLightItemConfiguration *trafficLightItemC, eNetEditorDatabase *newDatabase);

    // 02 - Función terminada y documentada
    ~trafficLightTable();

    // 07 - Función terminada y documentada
    trafficLightItem *findTrafficLightById(const QString &idToSearch) const;


private:

    // Container with the Traffic Lights
    QList<trafficLightItem *> tlTable;


};

#endif // LIGHTSTABLE_H
