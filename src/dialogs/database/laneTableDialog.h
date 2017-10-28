#ifndef LANETABLEDIALOG_H
#define LANETABLEDIALOG_H

#include "eNetEditorTableDialog.h"


namespace Ui
{
class laneTableDialog;
}

class laneTableDialog : public eNetEditorTableDialog
{
    Q_OBJECT

public:

    explicit laneTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~laneTableDialog();

    // Función terminada y documentada
    laneItemDialog *getLaneItemDialog() const;


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    Ui::laneTableDialog *ui;

    laneItemDialog *laneItemD;

    laneTable *laneT;
};



#endif // LANETABLEDIALOG_H
