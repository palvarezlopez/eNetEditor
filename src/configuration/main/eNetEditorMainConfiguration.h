#ifndef ENETEDITORMAINCONFIGURATION_H
#define ENETEDITORMAINCONFIGURATION_H

#include "../eNetEditorConfiguration.h"


/*!
    \brief eNetEditor main configuration
    \author Pablo Álvarez López
    \date 2015
    \pre A config.cfg file should exists, in other case a new config.cfg will be created
    \details Class to keep the all parameters of eNetEditor, including configuration and default
    parameters of project, tools and items
 */
class eNetEditorMainConfiguration : public eNetEditorConfiguration
{
public:

    /**
        @brief Constructor of eNetEditorConfiguration
        @details Default constructor of eNetEditorConfiguration, which build
        the toolsConfiguration and projectConfiguration, and load automatically
        the configuration using the function loadeNetEditorConfiguration()

    */
    eNetEditorMainConfiguration();

    /**
        @brief Destructor of eNetEditorConfiguration
        @details Destructor of the class eNetEditorConfiguration, toolsConfiguration and
        projectConfiguration. Before destruction calls the function SaveeNetEditorConfiguration()
    */
    ~eNetEditorMainConfiguration();

    /**
        @brief Load eNetEditor configuration
        @details Load configuration of eNetEditor keeped in config.cfg file. Is automatically
        called by eNetEditorConfiguration(), but can be called manually.
    */
    void loadeNetEditorConfiguration();

    /**
        @brief Save eNetEditor configuration
        @details Save configuration of eNetEditor in config.cfg file. Is automatically
        called by ~eNetEditorConfiguration(), but can be called manually.
    */
    void SaveeNetEditorConfiguration();

    /**
        @brief Get eNetEditor version
        @return QString with the actual version of eNetEditor
        @details Get actual version of eNetEditor
    */
    const QString &geteNetEditorVersion() const;

    /**
        @brief Get eNetEditor revision
        @return QString with the actual revision of eNetEditor
        @details Get actual revision of eNetEditor
    */
    const QString &geteNetEditorRevision() const;

    /**
        @brief Get projectConfiguration
        @return pointer to projectConfiguration
        @details Get pointer to projectConfiguration, which have parameters relative
        to eNetEditor project and items.
    */
    eNetEditorProjectConfiguration *getProjectConfiguration() const;

    /**
        @brief Get cadytsConfiguration
        @return pointer to cadytsConfiguration
        @details Get pointer to cadytsConfiguration, which have parameters relative
        to cadyts tool.
    */
    cadytsToolConfiguration *getCadytsConfiguration() const;

    /**
        @brief Get dfRouterConfiguration
        @return pointer to dfRouterConfiguration
        @details Get pointer to dfRouterConfiguration, which have parameters relative
        to dfRouter tool.
    */
    dfRouterToolConfiguration *getDfRouterConfiguration() const;

    /**
        @brief Get duaRouterConfiguration
        @return pointer to dfRouterConfiguration
        @details Get pointer to duaRouterConfiguration, which have parameters relative
        to duaRouter tool.
    */
    duaRouterToolConfiguration *getDuaRouterConfiguration() const;

    /**
        @brief Get jtrRouterConfiguration
        @return pointer to jtrRouterConfiguration
        @details Get pointer to jtrRouterConfiguration, which have parameters relative
        to jtrRouter tool.
    */
    jtrRouterToolConfiguration *getJtrRouterConfiguration() const;

    /**
        @brief Get netConvertConfiguration
        @return pointer to netConvertConfiguration
        @details Get pointer to netConvertConfiguration, which have parameters relative
        to netConvert tool.
    */
    netConvertToolConfiguration *getNetConvertConfiguration() const;

    /**
        @brief Get netGenerateConfiguration
        @return pointer to netGenerateConfiguration
        @details Get pointer to netGenerateConfiguration, which have parameters relative
        to netGenerate tool.
    */
    netGenerateToolConfiguration *getNetGenerateConfiguration() const;

    /**
        @brief Get sumoConfiguration
        @return pointer to sumoConfiguration
        @details Get pointer to sumoConfiguration, which have parameters relative
        to sumo tool.
    */
    sumoToolConfiguration *getSumoConfiguration() const;


private:

    // eNetEditor version
    QString eNetEditorVersion;

    // eNetEditor version
    QString eNetEditorRevision;

    // Pointer to project configuration
    eNetEditorProjectConfiguration *projectConfig;

    // Pointer to tool configurations
    cadytsToolConfiguration *cadytsC;
    dfRouterToolConfiguration *dfRouterC;
    duaRouterToolConfiguration *duaRouterC;
    jtrRouterToolConfiguration *jtrRouterC;
    netConvertToolConfiguration *netConvertC;
    netGenerateToolConfiguration *netGenerateC;
    sumoToolConfiguration *sumoC;
};

#endif // ENETEDITORMAINCONFIGURATION_H
