#include "eNetEditorItemDialog.h"

eNetEditorItemDialog::eNetEditorItemDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorDialog(eNetEditorMainW)
{
    // Nothing to declare
}

eNetEditorItemDialog::~eNetEditorItemDialog()
{
    // Nothing to erase
}

const QString &eNetEditorItemDialog::getTmpExtraParameter1Name() const
{
    return tmpExtraParameter1Name;
}

const QString &eNetEditorItemDialog::getTmpExtraParameter1Value() const
{
    return tmpExtraParameter1Value;
}

const QString &eNetEditorItemDialog::getTmpExtraParameter2Name() const
{
    return tmpExtraParameter2Name;
}

const QString &eNetEditorItemDialog::getTmpExtraParameter2Value() const
{
    return tmpExtraParameter2Value;
}

const QString &eNetEditorItemDialog::getTmpExtraParameter3Name() const
{
    return tmpExtraParameter3Name;
}

const QString &eNetEditorItemDialog::getTmpExtraParameter3Value() const
{
    return tmpExtraParameter3Value;
}

void eNetEditorItemDialog::setTmpExtraParameter1Name(const QString &newExtraParameter1Name)
{
    tmpExtraParameter1Name = newExtraParameter1Name;
}

void eNetEditorItemDialog::setTmpExtraParameter1Value(const QString &newExtraParameter1Value)
{
    tmpExtraParameter1Value = newExtraParameter1Value;
}

void eNetEditorItemDialog::setTmpExtraParameter2Name(const QString &newExtraParameter2Name)
{
    tmpExtraParameter2Name = newExtraParameter2Name;
}

void eNetEditorItemDialog::setTmpExtraParameter2Value(const QString &newExtraParameter2Value)
{
    tmpExtraParameter2Value = newExtraParameter2Value;
}

void eNetEditorItemDialog::setTmpExtraParameter3Name(const QString &newExtraParameter3Name)
{
    tmpExtraParameter3Name = newExtraParameter3Name;
}

void eNetEditorItemDialog::setTmpExtraParameter3Value(const QString &newExtraParameter3Value)
{
    tmpExtraParameter3Value = newExtraParameter3Value;
}

void eNetEditorItemDialog::closeEvent(QCloseEvent *event)
{
    // Emit eNetEditorItemDialogCloseX
    //emit dialogClosed(eNetEditorItemDialogCloseX);

    // Accept event
    event->accept();
}



