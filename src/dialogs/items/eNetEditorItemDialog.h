#ifndef ENETEDITORITEMDIALOG_H
#define ENETEDITORITEMDIALOG_H

#include "../eNetEditorDialog.h"


// Enum eNetEditorItemDialogCloseType
enum eNetEditorItemDialogCloseType
{
    eNetEditorItemDialogCloseAccepted,
    eNetEditorItemDialogCloseCanceled,
    eNetEditorItemDialogCloseX
};


class eNetEditorItemDialog : public eNetEditorDialog
{
public:

    eNetEditorItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    virtual ~eNetEditorItemDialog();

    const QString &getTmpExtraParameter1Name() const;

    const QString &getTmpExtraParameter1Value() const;

    const QString &getTmpExtraParameter2Name() const;

    const QString &getTmpExtraParameter2Value() const;

    const QString &getTmpExtraParameter3Name() const;

    const QString &getTmpExtraParameter3Value() const;

    void setTmpExtraParameter1Name(const QString &newExtraParameter1Name);

    void setTmpExtraParameter1Value(const QString &newExtraParameter1Value);

    void setTmpExtraParameter2Name(const QString &newExtraParameter2Name);

    void setTmpExtraParameter2Value(const QString &newExtraParameter2Value);

    void setTmpExtraParameter3Name(const QString &newExtraParameter3Name);

    void setTmpExtraParameter3Value(const QString &newExtraParameter3Value);


public slots:

    virtual void resetParameters() = 0;

    virtual void updateParameters() = 0;

    virtual void openItemDialog(eNetEditorItem *item) = 0;

    virtual void closeEvent(QCloseEvent *event);


signals:

    void dialogClosed(eNetEditorItemDialogCloseType);


private slots:

    virtual void on_ButtonAccept_released() = 0;

    virtual void on_ButtonCancel_released() = 0;

    virtual void on_ButtonReset_released() = 0;


private:

    // Extra parameter 1 name
    QString tmpExtraParameter1Name;

    // Extra parameter 1 value
    QString tmpExtraParameter1Value;

    // Extra parameter 2 name
    QString tmpExtraParameter2Name;

    // Extra parameter 2 value
    QString tmpExtraParameter2Value;

    // Extra parameter 3 name
    QString tmpExtraParameter3Name;

    // Extra parameter 3 value
    QString tmpExtraParameter3Value;
};

#endif // ENETEDITORITEMDIALOG_H
