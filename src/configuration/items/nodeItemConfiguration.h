#ifndef NODEITEMCONFIGURATION_H
#define NODEITEMCONFIGURATION_H

#include "eNetEditorItemConfiguration.h"


class nodeItemConfiguration : public eNetEditorItemConfiguration
{
public:

    nodeItemConfiguration();

    ~nodeItemConfiguration();

    /**
        @brief Get Node Signal Icon
        @param type nodeItemType of the nodeItem
        @return Pointer to QPixmax with the node signal Icon
        @details get a pointer to a QPixmax with the icon corresponding to nodeItemType type
    */
    QPixmap *NodeSignalIcon(nodeItemType type) const;

    /**
        @brief Get Node Type value
        @param type nodeItemType of the nodeItem
        @return QString with the corresponding value of nodeItemType
        @details Get the QString value of nodeItemType (Example: nodeItemTypePriority returns "priority")
    */
    const QString &getNodeTypeValue(nodeItemType type) const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    qreal getNodeDefaultPosz() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    nodeItemType getNodeDefaultType() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNodeDefaultExtraParameter1Name() const;


private:

    // Map with the node icons
    QMap<nodeItemType, QPixmap *> mapOfNodeIcons;

    // Vector with the type of nodes
    QVector<QString> vectorOfNodeTypes;

    // Default Parameter posz
    qreal nodeDefaultPosz;

    // Default Parameter Type
    nodeItemType nodeDefaultType;
};

#endif // NODEITEMCONFIGURATION_H
