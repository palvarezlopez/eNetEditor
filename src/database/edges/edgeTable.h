#ifndef EDGETABLE_H
#define EDGETABLE_H

#include "abstractEdgeTable.h"


class edgeTable : public abstractEdgeTable
{
public:

    // 01 - Función terminada y documentada
    edgeTable(const QString &newNameOfTable, edgeItemConfiguration *edgeItemC, eNetEditorDatabase *newDatabase);

    // 02 - Función terminada y documentada
    ~edgeTable();


    // 08 - Función terminada y documentada
    edgeItem *findEdgeByNodes(nodeItem *nodeOrigin, nodeItem *nodeDestiny);

    // 12 - Función terminada y documentada
    QStringList getIdsOfLanes(edgeItem *e);


private:
};

#endif // edgeTABLE_H
