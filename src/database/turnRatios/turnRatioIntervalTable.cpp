#include "turnRatioIntervalTable.h"

// Configuration
#include "../../configuration/items/turnRatios/turnRatioIntervalItemConfiguration.h"

// Items
#include "../../items/turnRatios/turnRatioIntervalItem.h"


turnRatioIntervalTable::turnRatioIntervalTable(const QString &newNameOfTable, turnRatioIntervalItemConfiguration *newTurnRatioIntervalItemConfiguration, eNetEditorDatabase *newDatabase) : abstractTurnRatioTable(newNameOfTable, newTurnRatioIntervalItemConfiguration, newDatabase)
{

}

turnRatioIntervalTable::~turnRatioIntervalTable()
{
    // Nothing to erase
}

void turnRatioIntervalTable::orderByInterval()
{
    // Declare a list of turnRatioIntervalItems
    QList<turnRatioIntervalItem *> listOfTurnRatioIntervalItem;

    // Declare auxiliar turnRatioIntervalItems
    turnRatioIntervalItem *triAux1, *triAux2;

    // While table isn't empty
    while(getNumberOfItems() > 0)
    {
        // Get first item of table
        triAux1 = dynamic_cast<turnRatioIntervalItem *>(getItemAt(0));

        // Iterate over table
        for(QList<eNetEditorItem *>::iterator i = iteratorTableBegin(); i != iteratorTableEnd(); i++)
        {
            // Cast item table to turnRatioIntervalItem
            triAux2 = dynamic_cast<turnRatioIntervalItem *>(*i);

            // If getIntervalBegin of casted item is bigger than triAux1
            if(triAux2->getIntervalBegin() > triAux1->getIntervalBegin())
            {
                // Set value of triAux2 in triAux1
                triAux1 = triAux2;
            }
        }

        // Erase triAux1 of table
        eraseeNetEditorItem(triAux1);

        // Add triAux1 to listOfTurnRatioIntervalItem
        listOfTurnRatioIntervalItem.push_back(triAux1);
    }

    // Now listOfTurnRatioIntervalItem is sort, then all element sould be inserted in table
    for(QList<turnRatioIntervalItem *>::iterator i = listOfTurnRatioIntervalItem.begin(); i != listOfTurnRatioIntervalItem.end(); i++)
    {
        // Add item of listOfTurnRatioIntervalItem to table
        addeNetEditorItem(*i);
    }
}
