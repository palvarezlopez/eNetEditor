#ifndef BUSSTOPTABLEDIALOG_H
#define BUSSTOPTABLEDIALOG_H

#include "../eNetEditorTableDialog.h"


namespace Ui
{
class busStopTableDialog;
}

class busStopTableDialog : public eNetEditorTableDialog
{
    Q_OBJECT

public:

    explicit busStopTableDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~busStopTableDialog();

    // Función terminada y documentada
    busStopItemDialog *getBusStopItemDialog() const;


public slots:

    void openTableDialog(eNetEditorTable *table);

    void updateTable();


private slots:

    void on_Table_doubleClicked(const QModelIndex &index);

    void on_ButtonClose_released();

    void afterItemDialogClosed(eNetEditorItemDialogCloseType closeCode);


private:

    Ui::busStopTableDialog *ui;

    busStopItemDialog *busStopItemD;

    busStopTable *busStopT;
};

#endif // BUSSTOPTABLEDIALOG_H
