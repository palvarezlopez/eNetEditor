#ifndef ENETEDITORPROJECT_H
#define ENETEDITORPROJECT_H

#include "../main/eNetEditor.h"


class eNetEditorProject : public QGraphicsView, public eNetEditor
{
public:

    eNetEditorProject(const QString &newProjectName, const QString &newFilePath, const QString &newImageRoute, const openStreetMapPixelMeter &newScaleMap, int newBeginDuration, int newEndDuration, eNetEditorMainWindow *neweNetEditorMainW);

    eNetEditorProject(const QString &filePath, eNetEditorMainWindow *neweNetEditorMainW);

    ~eNetEditorProject();

    void addTurnRatioInterval(turnRatioIntervalItem *tri);

    void removeTurnRatioInterval(turnRatioIntervalItem *tri);


    // FILE FUNCTIONS

    bool load(const QString &Path);

    bool save();

    bool saveAs(const QString &newProjectPath);

    bool closeProject();


    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getProjectName() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getProjectPath() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getImagePath() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const openStreetMapPixelMeter &getScaleMap() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getTimeBegin() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getTimeEnd() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QPixmap &getImageMap() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    flagOperation getFlag() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    eNetEditorMainWindow *geteNetEditorMainWindow() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    eNetEditorScene *geteNetEditorScene() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    eNetEditorDatabase *getDatabase() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    itemManagerProject *getParameterManager() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    eNetEditorProjectConfiguration *getProjectConfiguration() const;

    // SET FUNCTIONS

    void setProjectName(const QString &newProjectName);

    void setProjectPath(const QString &newProjectPath);

    void setImagePath(const QString &newImagePath);

    void setScaleMap(const openStreetMapPixelMeter &newScaleMap);

    void setTimeBegin(int newTimeBegin);

    void setTimeEnd(int newTimeEnd);

    void setMap(const QPixmap &newImageMap);

    void setFlag(flagOperation newFlag);

    void setShowLabels(bool value);

    void setShowIcons(bool value);

    // IS FUNCTIONS

    bool isSaved();

    bool isIntervalValid(int intervalBegin, int intervalEnd, turnRatioIntervalItem *triToCheck);


protected:

    void scrollContentsBy(int dx, int dy);

    void wheelEvent(QWheelEvent *event);


private:

    // Pointer to eNetEditorMainWindow
    eNetEditorMainWindow *eNetEditorMainW;

    // Scene of the project
    eNetEditorScene *scene;

    // ProjectName
    QString projectName;

    // Path of the project
    QString projectPath;

    // Path of the image
    QString imagePath;

    // Scale
    openStreetMapPixelMeter scaleMap;

    // Start of the simulation
    int timeBegin;

    // Start of the simulation
    int timeEnd;

    // Pixmax with the image
    QPixmap imageMap;

    // List of turn Ratio Intervals
    QList<turnRatioIntervalItem *> listOfTurnRatioIntervals;
};

#endif // PROJECTTABLE_H
