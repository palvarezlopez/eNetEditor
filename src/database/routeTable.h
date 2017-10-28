#ifndef ROUTETABLE_H
#define ROUTETABLE_H

#include "eNetEditorTable.h"


class routeTable : public eNetEditorTable
{
public:

    // 01 - Función terminada y documentada
    routeTable(const QString &newNameOfTable, routeItemConfiguration *routeItemC, eNetEditorDatabase *newDatabase);

    // 03 - Función terminada y documentada
    ~routeTable();

    // 13 - Función terminada y documentada
    routeItem *findRouteById(const QString &idToSearch) const;


private:

    // Container with the Prohibitions
    QList<routeItem *> rTable;
};

#endif // ROUTETABLE_H
