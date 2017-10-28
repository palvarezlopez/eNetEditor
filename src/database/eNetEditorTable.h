#ifndef ENETEDITORTABLE_H
#define ENETEDITORTABLE_H

#include "eNetEditorDatabase.h"


class  eNetEditorTable : public eNetEditor
{
public:

    eNetEditorTable(const QString &newNameOfTable, eNetEditorItemConfiguration *newItemConfiguration, eNetEditorDatabase *newDatabase);

    virtual ~eNetEditorTable();

    void loadTable(QDomDocument *domDoc);

    /// Habría que borrar esa tableId
    QDomElement saveTable(const QString &tableId, QDomDocument *domDoc);

    bool exportTableToXML();

    void addeNetEditorItem(eNetEditorItem *item);

    void eraseeNetEditorItem(eNetEditorItem *item);

    eNetEditorItem *findItemById(const QString &idToSearch) const;

    eNetEditorItem *getItemAt(int index);

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getTableName();

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    int getNumberOfItems() const;

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
    eNetEditorScene *geteNetEditorScene() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    eNetEditorProject *getProject() const;

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
    eNetEditorMessages *getMessages() const;

    // Iterators

    QList<eNetEditorItem *>::iterator iteratorTableBegin();

    QList<eNetEditorItem *>::iterator iteratorTableEnd();

private:

    // Pointer to dataBase
    eNetEditorDatabase *database;

    // Pointer to itemConfiguration
    eNetEditorItemConfiguration *itemConfiguration;

    // Name of table
    QString tableName;

    // List with the items
    QList<eNetEditorItem *> itemTable;
};

#endif // NETEDITORTABLE_H
