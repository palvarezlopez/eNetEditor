#ifndef ENETEDITORTOOLCONFIGURATION_H
#define ENETEDITORTOOLCONFIGURATION_H

#include "../eNetEditorConfiguration.h"


class eNetEditorToolConfiguration : public eNetEditorConfiguration
{
public:

    eNetEditorToolConfiguration(int newNumberOfInputParameters, int newNumberOfOutputParameters, int newNumberOfProcessingParameters);

    ~eNetEditorToolConfiguration();

    const QString &getExecutablePath() const;

    const QString &getOutputfolder() const;

    int getNumberOfInputParameters() const;

    int getNumberOfOutputParameters() const;

    int getNumberOfProcessingParameters() const;

    void setExecutablePath(const QString &newExecutablePath);

    void setOutputfolder(const QString &newOutputfolder);

private:

    QString executablePath;

    QString outputfolder;

    int numberOfInputParameters;

    int numberOfOutputParameters;

    int numberOfProcessingParameters;

};

#endif // TOOLSCONFIGURATION_H
