#ifndef ENETEDITORPROCESSINGDIALOG_H
#define ENETEDITORPROCESSINGDIALOG_H

#include "../eNetEditorDialog.h"


namespace Ui
{
class eNetEditorProcessingDialog;
}


class eNetEditorProcessingDialog : public eNetEditorDialog
{
    Q_OBJECT

public:

    explicit eNetEditorProcessingDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~eNetEditorProcessingDialog();


public slots:

    void openDialog();

    void processingStart(const QString &newProcessName);

    void processingMessage(const QString &message);

    void processingDone();

    void processingError();

    void processingFinished();

    void toolMessage(const QString &tool, const QString &message);


    void setButtonBlocked(bool value);

private slots:

    void on_ButtonAccept_released();


private:

    // Interface
    Ui::eNetEditorProcessingDialog *ui;

    // Name of the actual process
    QString processName;
};

#endif // ENETEDITORPROCESSINGDIALOG_H
