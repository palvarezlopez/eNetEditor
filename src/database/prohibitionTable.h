#ifndef PROHIBITIONTABLE_H
#define PROHIBITIONTABLE_H

#include "eNetEditorTable.h"


class prohibitionTable : public eNetEditorTable
{
public:

    // 01 - Función terminada y documentada
    prohibitionTable(const QString &newNameOfTable, prohibitionItemConfiguration *prohibitionItemC, eNetEditorDatabase *newDatabase);

    // 02 - Función terminada y documentada
    ~prohibitionTable();

    // 08 - Función terminada y documentada
    prohibitionItem *findProhibitionByComponents(edgeItem *edgeOrigin, edgeItem *edgeDestiny);



private:
};

#endif // PROHIBITIONTABLE_H
