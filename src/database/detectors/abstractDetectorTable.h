#ifndef DETECTORTABLE_H
#define DETECTORTABLE_H

#include "../eNetEditorTable.h"


class abstractDetectorTable : public eNetEditorTable
{
public:

    // 01 - Función terminada y documentada
    abstractDetectorTable(const QString &newNameOfTable, eNetEditorDetectorConfiguration *eNetEditorDetectorItemC, eNetEditorDatabase *newDatabase);

    // 03 - Función terminada y documentada
    virtual ~abstractDetectorTable();


    void resetIndex();

    void updateIndex();

    void setIndex(int newIndex);


private:

    int index;
};

#endif // DETECTORTABLE_H
