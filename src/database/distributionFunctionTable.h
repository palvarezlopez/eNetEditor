#ifndef DISTRIBUTIONFUNCTIONTABLE_H
#define DISTRIBUTIONFUNCTIONTABLE_H

#include "eNetEditorTable.h"


class distributionFunctionTable  : public eNetEditorTable
{
public:

    distributionFunctionTable(const QString &newNameOfTable, distributionFunctionItemConfiguration *distributionFunctionItemC, eNetEditorDatabase *newDatabase);

    ~distributionFunctionTable();



private:
};

#endif // DISTRIBUTIONFUNCTIONTABLE_H
