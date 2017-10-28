#ifndef EDGETYPETABLEDIALOG_H
#define EDGETYPETABLEDIALOG_H

#include "abstractEdgeTableDialog.h"


namespace Ui
{
class edgeTypeTableDialog;
}

class edgeTypeTableDialog : public abstractEdgeTableDialog
{
    Q_OBJECT

public:

    explicit edgeTypeTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~edgeTypeTableDialog();

    edgeTypeItemDialog *getEdgeTypeItemDialog();


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    Ui::edgeTypeTableDialog *ui;

    edgeTypeItemDialog *edgeTypeItemD;

    edgeTypeTable *edgeTypeT;
};

#endif // EDGETYPETABLEDIALOG_H
