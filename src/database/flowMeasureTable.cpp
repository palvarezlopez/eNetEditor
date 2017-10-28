#include "flowMeasureTable.h"

// Configuration
#include "../configuration/items/flowMeasureItemConfiguration.h"

// Items
#include"../items/flowMeasureItem.h"


flowMeasureTable::flowMeasureTable(const QString &newNameOfTable, flowMeasureItemConfiguration *flowMeasureItemC, eNetEditorDatabase *newDatabase) : eNetEditorTable(newNameOfTable, flowMeasureItemC, newDatabase)
{

}

flowMeasureTable::~flowMeasureTable()
{

}

bool flowMeasureTable::exportTableToCSV(const QString &tablePath)
{
    // Create Qfile with the file path
    QFile file(tablePath);

    // check if file exits
    if (file.exists())
    {
        // If exist, remove it
        QFile::remove(tablePath);
    }

    // Set open parameters
    file.open(QIODevice::WriteOnly);

    // Try to open file
    if(!file.error())
    {
        // Create stream
        QTextStream stream( &file );

        // Stream header
        stream << "Detector;Time;qPKW;vPKW;qLKW;vLKW\r\n";

        // Iterate over table
        for(QList<eNetEditorItem *>::iterator i = iteratorTableBegin(); i != iteratorTableEnd(); i++)
        {
            // cast flowMeasureItem and write CSV
            stream << dynamic_cast<flowMeasureItem *>(*i)->toString() << "\r\n";
        }

        // Close stream
        file.close();

        // Table of items exported sucesfully, then return true
        return true;
    }
    else
    {
        // If there are an error open the file, then return false
        return false;
    }

    return true;
}
