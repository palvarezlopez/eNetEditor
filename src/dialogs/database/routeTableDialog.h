#ifndef ROUTETABLEDIALOG_H
#define ROUTETABLEDIALOG_H

#include "eNetEditorTableDialog.h"


namespace Ui
{
class routeTableDialog;
}

class routeTableDialog : public eNetEditorTableDialog
{
    Q_OBJECT

public:

    explicit routeTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~routeTableDialog();

    // Función terminada y documentada
    routeItemDialog *getRouteItemDialog() const;


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    Ui::routeTableDialog *ui;

    routeItemDialog *routeItemD;

    routeTable *routeT;
};

#endif // ROUTETABLEDIALOG_H
