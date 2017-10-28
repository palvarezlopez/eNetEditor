#ifndef NETEDITORUNDOREDO_H
#define NETEDITORUNDOREDO_H

#include "../main/eNetEditor.h"

class projectOperation;

// Declare enum NetEditorAction
enum eNetEditorAction
{
    eNetEditorActionCommit,
    eNetEditorActionRollBack,
    eNetEditorActionAddItem,
    eNetEditorActionRemoveItem,
    eNetEditorActionMoveItem,
    eNetEditorActionMoveItemBack,
    eNetEditorActionChangeParameterItem,
    eNetEditorActionReverseParameterItem
};
/*
// Class netEditor Operation
struct projectOperation
{
    // Type of operation to UNDO
    int operationTyp;

    // Item ID to apply the operation ("node", "edge", "lane"...)
    QString itemID;

    // List of attributes of item
    QString attributes;
};
*/

class undoRedoProject
{
public:

    undoRedoProject(eNetEditorDatabase *newDatabase, eNetEditorMessages *newMessages);

    ~undoRedoProject();

    void addOperation(eNetEditorItem *item, eNetEditorAction operationType, QString attributeChanged = QString(), QString attributeValueChanged = QString());

    void commit();

    void redo();

    bool empty();


private:

    // La idea de este es que cada vez que se lleve a cabo una
    // operacion (Add, remove, etc..) la operación sea añadida
    // al stack con addOperation, tras lo cual se ejecutará manualmente
    // un commit(). Si queremos añadir varias operaciones consecutivas
    // solo hay que usar tantas veces como haga falta addOperation
    // y luego cerrar con commit().
    //
    // Para deshacer una operación hay que llamar a redo(), que deshará
    // las operaciones hasta que encuentre un commit

    // Stack with the operations
    QStack<projectOperation *> operationsStack;

    // Pointer to database
    eNetEditorDatabase *database;

    // Pointer to Messages
    eNetEditorMessages *messages;
};

#endif // NETEDITORUNDOREDO_H
