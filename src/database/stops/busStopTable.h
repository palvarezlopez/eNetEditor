#ifndef BUSSTOPTABLE_H
#define BUSSTOPTABLE_H

#include "../eNetEditorTable.h"


class busStopTable : public eNetEditorTable
{
public:

    // 01 - Función terminada y documentada
    busStopTable(const QString &newNameOfTable, busStopItemConfiguration *busStopItemC, eNetEditorDatabase *newDatabase);

    // 02 - Función terminada y documentada
    ~busStopTable();


private:
};

#endif // BUSSTOPTABLE_H
