#include "eNetEditorProject.h"

// eNet Editor Main
#include "../main/eNetEditorMessages.h"
#include "../dialogs/main/eNetEditorMainWindow.h"

// Configuration
#include "../configuration/project/eNetEditorProjectConfiguration.h"
#include "../configuration/main/eNetEditorMainConfiguration.h"

// eNet Editor View and Scene
#include "eNetEditorScene.h"

// Data base
#include "../database/eNetEditorDatabase.h"

// Parameter Manager
#include "../project/itemManagerProject.h"

// item
#include "../items/turnRatios/turnRatioIntervalItem.h"


eNetEditorProject::eNetEditorProject(const QString &newProjectName, const QString &newPath, const QString &newImageRoute, const openStreetMapPixelMeter &newScaleMap, int newBeginDuration, int newEndDuration, eNetEditorMainWindow *neweNetEditorMainW) : QGraphicsView(neweNetEditorMainW), eNetEditor()
{
    // Set projectName
    projectName = newProjectName;

    // Set path of the project
    projectPath = newPath;

    // Set path of the image
    imagePath = newImageRoute;

    // Set scale of the map
    scaleMap = newScaleMap;

    // link neweNetEditorMainWialog
    eNetEditorMainW = neweNetEditorMainW;

    // Set start of the simulation
    timeBegin = newBeginDuration;

    // Set end of the simulation
    timeEnd = newEndDuration;

    // Create scene
    scene = new eNetEditorScene(this);

    // Add scene to view
    setScene(scene);

    // Load image
    imageMap.load(imagePath);

    // Draw map
    scene->setImageMap();

    // configure graphics
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    //Use ScrollHand Drag Mode to enable Panning
    setDragMode(ScrollHandDrag);

    // Center View in origin
    centerOn(0, 0);

    // Create directory for detectors
    QDir().mkpath(newPath + "/detectors");

    // Set name of view
    setObjectName("View");

    // Enable mouse trackig, to get mouse coordiantes from view
    setMouseTracking(true);
}


eNetEditorProject::eNetEditorProject(const QString &filePath, eNetEditorMainWindow *neweNetEditorMainW) : QGraphicsView(neweNetEditorMainW)
{
    /*
    // Set projectName
    projectName = newProjectName;

    // Set path of the project
    projectPath = newPath;

    // Set path of the image
    imagePath = newImageRoute;

    // Set scale of the map
    scaleMap = newScaleMap;
    */
    // link neweNetEditorMainWialog
    eNetEditorMainW = neweNetEditorMainW;

    // Create scene
    scene = new eNetEditorScene(filePath, this);

    // Add scene to view
    setScene(scene);

    // Load image
    imageMap.load(imagePath);

    // Draw map
    scene->setImageMap();

    // configure graphics
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    //Use ScrollHand Drag Mode to enable Panning
    setDragMode(ScrollHandDrag);

    // Center View in origin
    centerOn(0, 0);
    /**
        // if don't exist directory for detectors
        if(QDir(loadedPath + "/detectors").exists() == false)
        {
            // Make detector path
            QDir().mkpath(loadedPath + "/detectors");
        }
    **/
    // Set name of view
    setObjectName("View");

    // Enable mouse trackig, to get mouse coordiantes from view
    setMouseTracking(true);
}

eNetEditorProject::~eNetEditorProject()
{
    // Delete created scene
    delete scene;
}

void eNetEditorProject::addTurnRatioInterval(turnRatioIntervalItem *tri)
{
    listOfTurnRatioIntervals.push_back(tri);
}

void eNetEditorProject::removeTurnRatioInterval(turnRatioIntervalItem *tri)
{
    listOfTurnRatioIntervals.removeAll(tri);
}

// GET FUNCTIONS

const QString &eNetEditorProject::getProjectName() const
{
    return projectName;
}

const QString &eNetEditorProject::getProjectPath() const
{
    return projectPath;
}

const QString &eNetEditorProject::getImagePath() const
{
    return imagePath;
}

const openStreetMapPixelMeter &eNetEditorProject::getScaleMap() const
{
    return scaleMap;
}

int eNetEditorProject::getTimeBegin() const
{
    return timeBegin;
}

int eNetEditorProject::getTimeEnd() const
{
    return timeEnd;
}

const QPixmap &eNetEditorProject::getImageMap() const
{
    return imageMap;
}

flagOperation eNetEditorProject::getFlag() const
{
    return scene->getFlag();
}

eNetEditorMainWindow *eNetEditorProject::geteNetEditorMainWindow() const
{
    return eNetEditorMainW;
}

eNetEditorScene *eNetEditorProject::geteNetEditorScene() const
{
    return scene;
}

eNetEditorDatabase *eNetEditorProject::getDatabase() const
{
    return scene->getDatabase();
}

itemManagerProject *eNetEditorProject::getParameterManager() const
{
    return scene->getParameterManager();
}

eNetEditorProjectConfiguration *eNetEditorProject::getProjectConfiguration() const
{
    return eNetEditorMainW->geteNetEditorConfiguration()->getProjectConfiguration();
}

bool eNetEditorProject::isSaved()
{
    return scene->getDatabase()->isSaved();
}

bool eNetEditorProject::isIntervalValid(int intervalBegin, int intervalEnd, turnRatioIntervalItem *triToCheck)
{
    // If interval are the same
    if (intervalBegin == intervalEnd)
    {
        // Interval not valid, then return false
        return false;
    }
    else
    {
        // Iterate over list of turnRatioIntervalItem
        for(QList<turnRatioIntervalItem *>::iterator i = listOfTurnRatioIntervals.begin(); i != listOfTurnRatioIntervals.end(); i++)
        {
            // If turnRatioIntervalItem is different of given turnRatioIntervalItem
            if((*i) != triToCheck)
            {
                // Check if interval is valid
                if((*i)->getIntervalBegin() < intervalBegin && (*i)->getIntervalEnd() > intervalBegin)
                {
                    return false;
                }
                else if((*i)->getIntervalBegin() < intervalEnd && (*i)->getIntervalEnd() > intervalEnd)
                {
                    return false;
                }
                else if ((*i)->getIntervalBegin() >= intervalBegin && (*i)->getIntervalEnd() <= intervalEnd)
                {
                    return false;
                }
            }
        }

        // Interval valid, then return true
        return true;
    }
}

void eNetEditorProject::scrollContentsBy(int dx, int dy)
{
    // Call QGraphicsView
    QGraphicsView::scrollContentsBy(dx, dy);

    // Set scrolling boolean flag of scene true
    scene->setScrolling(true);
}

void eNetEditorProject::wheelEvent(QWheelEvent *event)
{
    // Set Transformation Anchor for zoom
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    // Scale the view / do the zoom
    double scaleFactor = 1.15;

    if(event->delta() > 0)
    {
        // Zoom in
        scale(scaleFactor, scaleFactor);
    }
    else
    {
        // Zooming out
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }
}

void eNetEditorProject::setProjectName(const QString &newProjectName)
{
    projectName = newProjectName;
}

void eNetEditorProject::setProjectPath(const QString &newProjectPath)
{
    projectPath = newProjectPath;
}

void eNetEditorProject::setImagePath(const QString &newImagePath)
{
    imagePath = newImagePath;
}

void eNetEditorProject::setScaleMap(const openStreetMapPixelMeter &newScaleMap)
{
    scaleMap = newScaleMap;

    scene->getDatabase()->setScaleInTable(eNetEditorMainW->geteNetEditorConfiguration()->getProjectConfiguration() ->getOpenStreetMapPixelMeterValue(scaleMap));
}

void eNetEditorProject::setTimeBegin(int newTimeBegin)
{
    timeBegin = newTimeBegin;
}

void eNetEditorProject::setTimeEnd(int newTimeEnd)
{
    timeEnd = newTimeEnd;
}

void eNetEditorProject::setMap(const QPixmap &newImageMap)
{
    imageMap = newImageMap;
}

void eNetEditorProject::setFlag(flagOperation newFlag)
{
    // Set new flag
    scene->setFlag(newFlag);
}

void eNetEditorProject::setShowLabels(bool value)
{
    // Change show label parameter
    getParameterManager()->setShowLabelAllItems(value);

    // Update scene
    scene->update();
}

void eNetEditorProject::setShowIcons(bool value)
{
    // Change show Icon parameter
    getParameterManager()->setShowIconAllItems(value);

    // Update scene
    scene->update();
}


bool eNetEditorProject::load(const QString &Path)
{
    Path;
    return true;
}

bool eNetEditorProject::save()
{
    return getDatabase()->save();
}

bool eNetEditorProject::saveAs(const QString &newProjectPath)
{
    // Change project path
    projectPath = newProjectPath;

    // Save project
    return scene->getDatabase()->save();
}

bool eNetEditorProject::closeProject()
{
    //Check if the project is saved
    if (!getDatabase()->isSaved())
    {
        // create messageBox
        QMessageBox messageBox;

        // Configure message box to ask if save project
        messageBox.setIcon(QMessageBox::Question);
        messageBox.setText("The project " + getProjectName() + " ist not saved.");
        messageBox.setInformativeText("Do you want save before close?");
        messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        messageBox.setDefaultButton(QMessageBox::Yes);

        // Save election of the user
        int election = messageBox.exec();

        // If the aswer is yes
        if(election == QMessageBox::Yes)
        {
            // Save project and return true (if the save was sucesfully)
            return save();
        }
        else if(election == QMessageBox::No)
        {
            // Close without saving, then return true
            return true;
        }
        else
        {
            // Close process canceled, then return false
            return false ;
        }
    }
    else
    {
        // Project saved, then return true
        return true;
    }
}
