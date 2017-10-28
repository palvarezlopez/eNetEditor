#include "inductionLoopsE1DetectorTable.h"

// Project
#include "../../project/eNetEditorProject.h"

// Configuration
#include "../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../configuration/items/detectors/inductionLoopsE1DetectorItemConfiguration.h"

// Items
#include "../../items/detectors/inductionLoopsE1DetectorItem.h"
#include "../../items/laneItem.h"


inductionLoopsE1DetectorTable::inductionLoopsE1DetectorTable(const QString &newNameOfTable, inductionLoopsE1DetectorItemConfiguration *inductionLoopsE1DetectorItemC, eNetEditorDatabase *newDatabase) : abstractDetectorTable(newNameOfTable, inductionLoopsE1DetectorItemC, newDatabase)
{
    /*
    // Set default Pos
    pos = getItemsConfiguration()->get->getDetectorDefaultPos();

    // Set default frecuency
    frequency = getItemConfiguration()->getDetectorDefaultFrequency();

    // Set default filename
    fileName = getItemConfiguration()->getDetectorDefaultFileName();
    */
}

inductionLoopsE1DetectorTable::~inductionLoopsE1DetectorTable()
{

}

bool inductionLoopsE1DetectorTable::exportDetectorDefinitionsToXML()
{
    // Create QString with filePath of detector definitions
    QString filePath = getProject()->getProjectPath() + "/" + getProject()->getProjectName() + "." + getProject()->getProjectConfiguration()->getInductionLoopsE1DetectorItemConfiguration()->getInductionLoopsE1DetectorItemDefaultDetectorDefinitionsFileNameWithExtension();

    // Create Qfile with the file path of detector definitions
    QFile file(filePath);

    // check if file exits
    if (file.exists())
    {
        // If exist, remove it
        QFile::remove(filePath);
    }

    // Set open parameters
    file.open(QIODevice::WriteOnly);

    // Try to open file
    if(!file.error())
    {
        // Create QDomDocument
        QDomDocument *domDoc = new QDomDocument();

        // Declare QDomElement to keep atributes
        QDomElement domElementTable;
        QDomElement domElementItem;

        // Pointer to InductionLoopE1 Detector
        inductionLoopsE1DetectorItem *E1;

        // Create Element with the corresponding tag (detectorDefinitions)
        domElementTable = domDoc->createElement("detectorDefinitions");

        // Iterate over table of InductionLoopE1
        for(QList<eNetEditorItem *>::iterator i = iteratorTableBegin(); i != iteratorTableEnd(); i++)
        {
            // Cast Item to E1
            E1 = dynamic_cast<inductionLoopsE1DetectorItem *>(*i);

            // Create QDomElement with the corresponding type
            domElementItem = domDoc->createElement("detectorDefinition");

            // Set detector ID
            domElementItem.setAttribute("id", E1->getItemId());

            // Set detector lane
            domElementItem.setAttribute("lane", E1->getLaneParent()->getItemId());

            // Set detector position
            domElementItem.setAttribute("pos", QString::number(E1->getPosDetector()));

            // Append domElementItem child to domElementTable
            domElementTable.appendChild(domElementItem);
        }

        // Append domElementTable child to general document
        domDoc->appendChild(domElementTable);

        // Create TexStream with the file
        QTextStream out(&file);

        // Save file using textStream
        out << domDoc->toString();

        // Delete domDoc
        delete domDoc;

        // Close stream
        file.close();

        // Detector definitions exported sucesfully, then return true
        return true;
    }
    else
    {
        // If there are an error open the file, then return false
        return false;
    }
}
