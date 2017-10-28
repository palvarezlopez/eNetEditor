#ifndef TRAFFICLIGHTCONVERTER_H
#define TRAFFICLIGHTCONVERTER_H

#include "../main/eNetEditor.h"

class trafficLightConverter : public eNetEditor
{
public:

    trafficLightConverter(eNetEditorMessages *newMessages);

    ~trafficLightConverter();

    bool parseTrafficLights(eNetEditorDatabase *database, const QString &netPath, const QString &trafficLightPath);


private:

    void setLinkIndexAutomatic(eNetEditorDatabase *database, QDomElement rootOfNetfile);

    QVector<QString> parseTrafficLightsPhases(trafficLightItem *tl);

    // Pointer to messages
    eNetEditorMessages *messages;
};

#endif // TRAFFICLIGHTCONVERTER_H
