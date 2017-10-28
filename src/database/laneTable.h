#ifndef LANETABLE_H
#define LANETABLE_H

#include "eNetEditorTable.h"


class laneTable : public eNetEditorTable
{
public:

    // 01 - Función terminada y documentada
    laneTable(const QString &newNameOfTable, laneItemConfiguration *laneItemC, eNetEditorDatabase *newDatabase);

    // 02 - Función terminada y documentada
    ~laneTable();


    // 19 - Función terminada y documentada
    laneItem *findLaneByEdge(edgeItem *parent) const;


private:
};

#endif // LANETABLE_H
