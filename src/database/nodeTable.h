#ifndef NODETABLE_H
#define NODETABLE_H

#include "eNetEditorTable.h"


class nodeTable : public eNetEditorTable
{
public:

    // 01 - Función terminada y documentada
    nodeTable(const QString &newNameOfTable, nodeItemConfiguration *nodeItemC, eNetEditorDatabase *newDatabase);

    // 02 - Función terminada y documentada
    ~nodeTable();

    // 11 - Función terminada y documentada
    QStringList getIdsOfIncomingsEdges(nodeItem *n);

    // 12 - Función terminada y documentada
    QStringList getIdsOfOutcomingsEdges(nodeItem *n);

    int getIndex();

    // 11 Función terminada y documentada
    void setMapPixelMeter(qreal newMapPixelMeter);

    void updateIndex();


private:

    // Pixel meter of the map
    qreal mapPixelMeter;

    // Index
    int index;
};

#endif // NODETABLE_H
