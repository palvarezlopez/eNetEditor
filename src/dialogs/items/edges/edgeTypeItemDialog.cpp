#include "edgeTypeItemDialog.h"
#include "ui_edgeTypeItemDialog.h"

#include "../../../items/edges/edgeTypeItem.h"


edgeTypeItemDialog::edgeTypeItemDialog(eNetEditorMainWindow *eNetEditorMainW) : abstractEdgeItemDialog(eNetEditorMainW), ui(new Ui::edgeTypeItemDialog)
{
    // Create UI
    ui->setupUi(this);

    // By default pointer is NULL
    et = NULL;
}

edgeTypeItemDialog::~edgeTypeItemDialog()
{
    // Delete UI
    delete ui;
}

void edgeTypeItemDialog::resetParameters()
{
    // Set setTmpExtraParameter1Name with the value of the Item
    setTmpExtraParameter1Name(et->getExtraParameter1Name());

    // Set setTmpExtraParameter1Value with the value of the Item
    setTmpExtraParameter1Value(et->getExtraParameter1Value());

    // Set setTmpExtraParameter2Name with the value of the Item
    setTmpExtraParameter2Name(et->getExtraParameter2Name());

    // Set setTmpExtraParameter2Value with the value of the Item
    setTmpExtraParameter2Value(et->getExtraParameter2Value());

    // Set setTmpExtraParameter3Name with the value of the Item
    setTmpExtraParameter3Name(et->getExtraParameter3Name());

    // Set setTmpExtraParameter3Value with the value of the Item
    setTmpExtraParameter3Value(et->getExtraParameter3Value());
}

void edgeTypeItemDialog::updateParameters()
{
    // Set tmpExtraParameter1Name with the value of the item
    setTmpExtraParameter1Name(et->getExtraParameter1Name());

    // Set tmpExtraParameter1Value with the value of the item
    setTmpExtraParameter1Value(et->getExtraParameter1Value());

    // If custom parameter 1 was changed
    if(et->getExtraParameter1Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter1Name->setText(et->getExtraParameter1Name());

        // Enable Text
        ui->TextCustomParameter1Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter1Value->setText(et->getExtraParameter1Value());
        ui->TextCustomParameter1Value->setAlignment(Qt::AlignCenter);
    }
    else
    {
        // Change Button text to default
        ui->ButtonCustomParameter1Name->setText("Custom parameter 1");

        // Disable Text
        ui->TextCustomParameter1Value->setEnabled(false);

        // Remove Text
        ui->TextCustomParameter1Value->setText("");
        ui->TextCustomParameter1Value->setAlignment(Qt::AlignCenter);
    }

    // Set tmpExtraParameter2Name with the value of the item
    setTmpExtraParameter2Name(et->getExtraParameter2Name());

    // Set tmpExtraParameter2Value with the value of the item
    setTmpExtraParameter2Value(et->getExtraParameter2Value());

    // If custom parameter 2 was changed
    if(et->getExtraParameter2Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter2Name->setText(et->getExtraParameter2Name());

        // Enable Text
        ui->TextCustomParameter2Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter2Value->setText(et->getExtraParameter2Value());
        ui->TextCustomParameter2Value->setAlignment(Qt::AlignCenter);
    }
    else
    {
        // Change Button text to default
        ui->ButtonCustomParameter2Name->setText("Custom parameter 2");

        // Disable Text
        ui->TextCustomParameter2Value->setEnabled(false);

        // Remove Text
        ui->TextCustomParameter2Value->setText("");
        ui->TextCustomParameter2Value->setAlignment(Qt::AlignCenter);
    }

    // Set tmpExtraParameter3Name with the value of the item
    setTmpExtraParameter3Name(et->getExtraParameter3Name());

    // Set tmpExtraParameter3Value with the value of the item
    setTmpExtraParameter3Value(et->getExtraParameter3Value());

    // If custom parameter 3 was changed
    if(et->getExtraParameter3Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter3Name->setText(et->getExtraParameter3Name());

        // Enable Text
        ui->TextCustomParameter3Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter3Value->setText(et->getExtraParameter3Value());
        ui->TextCustomParameter3Value->setAlignment(Qt::AlignCenter);
    }
    else
    {
        // Change Button text to default
        ui->ButtonCustomParameter3Name->setText("Custom parameter 3");

        // Disable Text
        ui->TextCustomParameter3Value->setEnabled(false);

        // Remove Text
        ui->TextCustomParameter3Value->setText("");
        ui->TextCustomParameter3Value->setAlignment(Qt::AlignCenter);
    }
}

void edgeTypeItemDialog::openItemDialog(eNetEditorItem *item)
{
    // Set pointer to edge
    et = dynamic_cast<edgeTypeItem *>(item);

    // If item is an edge
    if(et)
    {
        // Reset parameters
        resetParameters();

        // Update parameters in all QWidgets;
        updateParameters();

        // Show Dialog
        show();
    }
}

void edgeTypeItemDialog::on_ButtonAccept_released()
{
    // Emit Signal
    emit dialogClosed(eNetEditorItemDialogCloseAccepted);

    // Close dialog
    close();
}

void edgeTypeItemDialog::on_ButtonCancel_released()
{
    // Emit cancel Signal
    emit dialogClosed(eNetEditorItemDialogCloseCanceled);

    // Close dialog
    close();
}

void edgeTypeItemDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters in all QWidgets;
    updateParameters();
}

void edgeTypeItemDialog::on_ButtonCustomParameter1Name_released()
{

}

void edgeTypeItemDialog::on_ButtonCustomParameter2Name_released()
{

}

void edgeTypeItemDialog::on_ButtonCustomParameter3Name_released()
{

}

void edgeTypeItemDialog::on_TextCustomParameter1Value_textChanged()
{

}

void edgeTypeItemDialog::on_TextCustomParameter2Value_textChanged()
{

}

void edgeTypeItemDialog::on_TextStartNode_textChanged()
{

}

void edgeTypeItemDialog::on_TextDestinyNode_textChanged()
{

}

void edgeTypeItemDialog::on_TextNumberOfLanes_textChanged()
{

}

void edgeTypeItemDialog::on_TextLenght_textChanged()
{

}

void edgeTypeItemDialog::on_TextPriority_textChanged()
{

}

void edgeTypeItemDialog::on_TextName_textChanged()
{

}


void edgeTypeItemDialog::on_TextCustomParameter3Value_textChanged()
{

}
