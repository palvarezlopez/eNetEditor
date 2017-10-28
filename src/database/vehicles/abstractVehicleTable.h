#ifndef ABSTRACTVEHICLETABLE_H
#define ABSTRACTVEHICLETABLE_H

#include "../eNetEditorTable.h"


class abstractVehicleTable : public eNetEditorTable
{
public:

    abstractVehicleTable(const QString &newNameOfTable, eNetEditorVehicleConfiguration *eNetEditorVehicleC, eNetEditorDatabase *newDatabase);

    virtual ~abstractVehicleTable();


};

#endif // ENETEDITORVEHICLETABLE_H
