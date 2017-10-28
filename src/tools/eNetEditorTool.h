#ifndef NETEDITORTOOL_H
#define NETEDITORTOOL_H

#include "../main/eNetEditor.h"


class eNetEditorTool : public QProcess, public eNetEditor
{
public:

    eNetEditorTool(eNetEditorMessages *newMessages, eNetEditorMainConfiguration *neweNetEditorC, QObject *parent);

    ~eNetEditorTool();

public slots:

    virtual bool createSumoCfgFile(eNetEditorProject *project) = 0;

    virtual bool startTool(QVector<QString> *inputParameters, QVector<QString> *outputParameters, QVector<QString> *processingParameters) = 0;

    void startLoop();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    eNetEditorMessages *getMessages() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    eNetEditorMainConfiguration *geteNetEditorConfiguration() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    QString *getExecutionParameters() const;


    // IS FUNCTIONS

    bool is64bits();


private slots:

    virtual void setInputParameters(QVector<QString> *inputParameters) = 0;

    virtual void setOutputParameters(QVector<QString> *outputParameters) = 0;

    virtual void setProcessingParameters(QVector<QString> *processingParameters) = 0;


private:

    // Pointer to Messages manager
    eNetEditorMessages *messages;

    // Pointer to eNetEditorConfiguration
    eNetEditorMainConfiguration *eNetEditorC;

    // String to keep parameters before execution
    QString *executionParameters;

    // Loop for waitings
    QEventLoop waitLoop;
};

#endif // SUMOEXTERNAL_H
