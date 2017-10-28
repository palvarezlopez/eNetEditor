#include "eNetEditorMainConfiguration.h"

#include "../items/eNetEditorItemConfiguration.h"
#include "../project/eNetEditorProjectConfiguration.h"

#include "../tools/cadytsToolConfiguration.h"
#include "../tools/dfRouterToolConfiguration.h"
#include "../tools/duaRouterToolConfiguration.h"
#include "../tools/jtrRouterToolConfiguration.h"
#include "../tools/netConvertToolConfiguration.h"
#include "../tools/netGenerateToolConfiguration.h"
#include "../tools/sumoToolConfiguration.h"


eNetEditorMainConfiguration::eNetEditorMainConfiguration() : eNetEditorConfiguration()
{
    // Create projectConfiguration
    projectConfig = new eNetEditorProjectConfiguration();

    // Create all tools configurations
    cadytsC = new cadytsToolConfiguration();
    dfRouterC = new dfRouterToolConfiguration();
    duaRouterC = new duaRouterToolConfiguration();
    jtrRouterC = new jtrRouterToolConfiguration();
    netConvertC = new netConvertToolConfiguration();
    netGenerateC = new netGenerateToolConfiguration();
    sumoC = new sumoToolConfiguration();

    // Set NetEditor version
    eNetEditorVersion = "1.0";

    // Set NetEditor version
    eNetEditorRevision = "120";

    // Load configuration
    loadeNetEditorConfiguration();
}

eNetEditorMainConfiguration::~eNetEditorMainConfiguration()
{
    // Save configuration before exit
    SaveeNetEditorConfiguration();

    // Delete projectConfig
    delete projectConfig;

    // Delete all tools
    delete cadytsC;
    delete dfRouterC;
    delete duaRouterC;
    delete jtrRouterC;
    delete netConvertC;
    delete netGenerateC;
    delete sumoC;
}

void eNetEditorMainConfiguration::loadeNetEditorConfiguration()
{
    //Declare String aux
    QString aux;

    // Create a new Qfile from path
    QFile file(QApplication::applicationDirPath() + "/config.cfg");

    // Set open parameters
    file.open(QIODevice::ReadOnly);

    // If the file cannot be opened
    if(file.error())
    {
        // If the file don't exist
        QMessageBox::critical(0, ("Configuration file"), ("Error opening config.cfg. A new config file will be created.\n"), QMessageBox::Ok);
    }
    else
    {
        // Create Stream
        QDataStream stream(&file);

        // Load parameters from stream
        stream >> aux;
        sumoC->setExecutablePath(aux);

        stream >> aux;
        netConvertC->setExecutablePath(aux);

        stream >> aux;
        netGenerateC->setExecutablePath(aux);

        stream >> aux;
        dfRouterC->setExecutablePath(aux);

        stream >> aux;
        duaRouterC->setExecutablePath(aux);

        stream >> aux;
        jtrRouterC->setExecutablePath(aux);

        stream >> aux;
        cadytsC->setExecutablePath(aux);

        // Close file
        file.close();
    }
}

void eNetEditorMainConfiguration::SaveeNetEditorConfiguration()
{
    // Create a new Qfile from path
    QFile file(QApplication::applicationDirPath() + "/config.cfg");

    //Declare String aux
    QString aux;

    // Set open parameters
    file.open(QIODevice::WriteOnly);

    // If the file cannot be opened
    if(file.error())
    {
        // If the file don't exist
        QMessageBox::critical(0, ("Configuration file"), ("Error saving the Net Editor configuration. Check if the config file is being using.\n"), QMessageBox::Ok);
    }
    else
    {
        // Create Stream
        QDataStream stream(&file);

        // Load parameters from stream
        aux = sumoC->getExecutablePath();
        stream << aux;

        aux = netConvertC->getExecutablePath();
        stream << aux;

        aux = netGenerateC->getExecutablePath();
        stream << aux;

        aux = dfRouterC->getExecutablePath();
        stream << aux;

        aux = duaRouterC->getExecutablePath();
        stream << aux;

        aux = jtrRouterC->getExecutablePath();
        stream << aux;

        aux = cadytsC->getExecutablePath();
        stream << aux;

        // Close file
        file.close();
    }
}

const QString &eNetEditorMainConfiguration::geteNetEditorVersion() const
{
    return eNetEditorVersion;
}

const QString &eNetEditorMainConfiguration::geteNetEditorRevision() const
{
    return eNetEditorRevision;
}

eNetEditorProjectConfiguration *eNetEditorMainConfiguration::getProjectConfiguration() const
{
    return projectConfig;
}

cadytsToolConfiguration *eNetEditorMainConfiguration::getCadytsConfiguration() const
{
    return cadytsC;
}

dfRouterToolConfiguration *eNetEditorMainConfiguration::getDfRouterConfiguration() const
{
    return dfRouterC;
}

duaRouterToolConfiguration *eNetEditorMainConfiguration::getDuaRouterConfiguration() const
{
    return duaRouterC;
}

jtrRouterToolConfiguration *eNetEditorMainConfiguration::getJtrRouterConfiguration() const
{
    return jtrRouterC;
}

netConvertToolConfiguration *eNetEditorMainConfiguration::getNetConvertConfiguration() const
{
    return netConvertC;
}

netGenerateToolConfiguration *eNetEditorMainConfiguration::getNetGenerateConfiguration() const
{
    return netGenerateC;
}

sumoToolConfiguration *eNetEditorMainConfiguration::getSumoConfiguration() const
{
    return sumoC;
}
