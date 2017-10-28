#include "flowMeasureItemDialog.h"
#include "ui_flowMeasureItemDialog.h"

#include "../../items/flowMeasureItem.h"

flowMeasureItemDialog::flowMeasureItemDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorItemDialog(eNetEditorMainW), ui(new Ui::flowMeasureItemDialog)
{
    // Create UI
    ui->setupUi(this);

    // By default, flowMeasureItem is NULL
    fm = NULL;
}

flowMeasureItemDialog::~flowMeasureItemDialog()
{
    // Delete UI
    delete ui;
}

void flowMeasureItemDialog::resetParameters()
{

}

void flowMeasureItemDialog::updateParameters()
{

}

void flowMeasureItemDialog::openItemDialog(eNetEditorItem *item)
{
    // Set pointer to flow measure
    fm = dynamic_cast<flowMeasureItem *>(item);

    // If item is a flow measure
    if(fm)
    {
        // Open Dialog
        show();
    }
}

void flowMeasureItemDialog::on_TextID_textChanged()
{

}

void flowMeasureItemDialog::on_TextDetector_textChanged()
{

}

void flowMeasureItemDialog::on_TextTime_textChanged()
{

}

void flowMeasureItemDialog::on_TextQPKW_textChanged()
{

}

void flowMeasureItemDialog::on_TextVPKW_textChanged()
{

}

void flowMeasureItemDialog::on_TextQLKW_textChanged()
{

}

void flowMeasureItemDialog::on_TextVLKW_textChanged()
{

}

void flowMeasureItemDialog::on_ButtonAccept_released()
{

    // Emit Signal
    emit dialogClosed(eNetEditorItemDialogCloseAccepted);

    // Close dialog
    close();
}

void flowMeasureItemDialog::on_ButtonCancel_released()
{
    // Emit cancel Signal
    emit dialogClosed(eNetEditorItemDialogCloseCanceled);

    // Close dialog
    close();
}

void flowMeasureItemDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters in all QWidgets;
    updateParameters();
}
