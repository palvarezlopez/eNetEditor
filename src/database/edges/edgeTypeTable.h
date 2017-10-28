#ifndef EDGETYPETABLE_H
#define EDGETYPETABLE_H

#include "abstractEdgeTable.h"


class edgeTypeTable : public abstractEdgeTable
{
public:

    // 01 - Función terminada y documentada
    edgeTypeTable(const QString &newNameOfTable, edgeTypeItemConfiguration *edgeTypeItemC, eNetEditorDatabase *newDatabase);

    // 03 - Función terminada y documentada
    ~edgeTypeTable();


private:
};

#endif // TYPESTABLE_H
