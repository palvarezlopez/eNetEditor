#include "nodeItemDialog.h"
#include "ui_nodeItemDialog.h"

// Database
#include "../../database/eNetEditorDatabase.h"

// eNetEditor configuration
#include "../../configuration/items/eNetEditorItemConfiguration.h"

// Project
#include "../../project/eNetEditorProject.h"

// Main Window
#include "../../dialogs/main/eNetEditorMainWindow.h"

// Turnratio Table Dialog
#include "../../dialogs/database/turnRatios/turnRatioTableDialog.h"

// Turn Ratio Item Dialog
#include "../../dialogs/items/turnRatios/turnRatioItemDialog.h"

// items
#include "../../items/nodeItem.h"
#include "../../items/edges/edgeItem.h"


nodeItemDialog::nodeItemDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorItemDialog(eNetEditorMainW), ui(new Ui::nodeItemDialog)
{
    // Create UI
    ui->setupUi(this);
}

nodeItemDialog::~nodeItemDialog()
{
    // Delete GUI
    delete ui;
}

void nodeItemDialog::resetParameters()
{
    // Set temporal pos x
    tmpPosx = n->getPosx();

    // Set temporal pos y
    tmpPosy = n->getPosy();

    // Set temporal pos z
    tmpPosz = n->getPosz();

    // Set temporal type
    tmpType = n->getType();

    // Set setTmpExtraParameter1Name with the value of the Item
    setTmpExtraParameter1Name(n->getExtraParameter1Name());

    // Set setTmpExtraParameter1Value with the value of the Item
    setTmpExtraParameter1Value(n->getExtraParameter1Value());

    // Set setTmpExtraParameter2Name with the value of the Item
    setTmpExtraParameter2Name(n->getExtraParameter2Name());

    // Set setTmpExtraParameter2Value with the value of the Item
    setTmpExtraParameter2Value(n->getExtraParameter2Value());

    // Set setTmpExtraParameter3Name with the value of the Item
    setTmpExtraParameter3Name(n->getExtraParameter3Name());

    // Set setTmpExtraParameter3Value with the value of the Item
    setTmpExtraParameter3Value(n->getExtraParameter3Value());
}

void nodeItemDialog::updateParameters()
{
    // Set node Id
    ui->TextNodeID->setText(n->getItemId());
    ui->TextNodeID->setAlignment(Qt::AlignCenter);

    // Set pos x
    ui->TextPosx->setText(QString::number(tmpPosx));
    ui->TextPosx->setAlignment(Qt::AlignCenter);

    // Set pos y
    ui->TextPosy->setText(QString::number(tmpPosy));
    ui->TextPosy->setAlignment(Qt::AlignCenter);

    // Set pos z
    ui->TextPosz->setText(QString::number(tmpPosz));
    ui->TextPosz->setAlignment(Qt::AlignCenter);

    // Set Type
    ui->ComboBoxType->setCurrentIndex(tmpType);

    // Declare list of incomingsEdges
    QStringList idsIncomingsEdges;

    // Get List of incomings Edges
    for (QList<edgeItem *>::iterator i = n->iteratorIncomingEdgesBegin(); i != n->iteratorIncomingEdgesEnd(); i++)
    {
        idsIncomingsEdges << (*i)->getItemId();
    }

    // Set number of incomings edges in the Label
    ui->LabelIncomingEdges->setText("Incomings edges: " + QString::number(idsIncomingsEdges.size()));
    ui->LabelIncomingEdges->setAlignment(Qt::AlignCenter);

    // Clear list
    ui->ListIncomingEdges->clear();

    // Set list of incomings Edges
    for (QStringList::iterator i = idsIncomingsEdges.begin(); i != idsIncomingsEdges.end(); i++)
    {
        ui->ListIncomingEdges->addItem(new QListWidgetItem("Edge Id = " + (*i)));
    }

    // Declare List of outcomings Edges
    QStringList idsOutcomingsEdges;

    // Get List of outcomings Edges
    for (QList<edgeItem *>::iterator i = n->iteratorOutcomingEdgesBegin(); i != n->iteratorOutcomingEdgesEnd(); i++)
    {
        idsOutcomingsEdges << (*i)->getItemId();
    }

    // Set number of incomings edges in the Label
    ui->LabelOutcomingEdges->setText("Outcomings edges: " + QString::number(idsOutcomingsEdges.size()));
    ui->LabelOutcomingEdges->setAlignment(Qt::AlignCenter);

    // Clear list
    ui->ListOutcomingEdges->clear();

    // Set list of outcomings Edges
    for (QStringList::iterator i = idsOutcomingsEdges.begin(); i != idsOutcomingsEdges.end(); i++)
    {
        ui->ListOutcomingEdges->addItem(new QListWidgetItem("Edge Id = " + (*i)));
    }

    // Set blocked
    //ui->CheckBoxBlocked->setChecked(n->setBl());

    // If custom parameter 1 was changed
    if(n->getExtraParameter1Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter1Name->setText(n->getExtraParameter1Name());

        // Enable Text
        ui->TextCustomParameter1Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter1Value->setText(n->getExtraParameter1Value());
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

    // If custom parameter 2 was changed
    if(n->getExtraParameter2Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter2Name->setText(n->getExtraParameter2Name());

        // Enable Text
        ui->TextCustomParameter2Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter2Value->setText(n->getExtraParameter2Value());
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

    // If custom parameter 3 was changed
    if(n->getExtraParameter3Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter3Name->setText(n->getExtraParameter3Name());

        // Enable Text
        ui->TextCustomParameter3Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter3Value->setText(n->getExtraParameter3Value());
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

void nodeItemDialog::openItemDialog(eNetEditorItem *item)
{
    // Set pointer to node
    n = dynamic_cast<nodeItem *>(item);

    // If item is a Node
    if(n)
    {
        // Reset parameters
        resetParameters();

        // Update parameters in all QWidgets;
        updateParameters();

        // Show Dialog
        show();
    }
}

void nodeItemDialog::on_ButtonAccept_released()
{
    // Set new posx in the node
    n->setPosx(tmpPosx);

    // Set new posy in the node
    n->setPosy(tmpPosy);

    // Set new posz in the node
    n->setPosz(tmpPosz);

    // Set new type in the node
    n->setType(tmpType);

    // If custom parameter 1 has been modified
    if(ui->TextCustomParameter1Value->isEnabled())
    {
        // Set name and value of custom parameter 1 in the item
        n->setExtraParameter1Name(getTmpExtraParameter1Name());
        n->setExtraParameter1Value(getTmpExtraParameter1Value());
    }

    // If custom parameter 2 has been modified
    if(ui->TextCustomParameter2Value->isEnabled())
    {
        // Set name and value of custom parameter 2 in the item
        n->setExtraParameter2Name(getTmpExtraParameter2Name());
        n->setExtraParameter2Value(getTmpExtraParameter2Value());
    }

    // If custom parameter 3 has been modified
    if(ui->TextCustomParameter3Value->isEnabled())
    {
        // Set name and value of custom parameter 3 in the item
        n->setExtraParameter3Name(getTmpExtraParameter3Name());
        n->setExtraParameter3Value(getTmpExtraParameter3Value());
    }

    // Set blocking
    //n->SetBlocked(ui->CheckBoxBlocked->isChecked());

    // Emit Signal
    emit dialogClosed(eNetEditorItemDialogCloseAccepted);

    //Close Windows
    close();
}

void nodeItemDialog::on_ButtonCancel_released()
{
    // Emit cancel Signal
    emit dialogClosed(eNetEditorItemDialogCloseCanceled);

    // Close dialog
    close();
}

void nodeItemDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters in all QWidgets;
    updateParameters();
}

void nodeItemDialog::on_ComboBoxType_currentIndexChanged(int index)
{
    // Set Selected Type of Node in the temporal variable
    tmpType = static_cast<nodeItemType>(index);
}

void nodeItemDialog::on_ButtonCustomParameter1Name_released()
{
    // Get QString with the name of parameter
    setTmpExtraParameter1Name(QInputDialog::getText(this, "Custom parameter 1", "Name of custom parameter 1"));

    // If tmpExtraParameter1Name != ""
    if(getTmpExtraParameter1Name() != "")
    {
        // Enable custom parameter value
        ui->TextCustomParameter1Value->setEnabled(true);

        // Set text in button
        ui->ButtonCustomParameter1Name->setText(getTmpExtraParameter1Name());
    }
    else
    {
        // Disable custom parameter value
        ui->TextCustomParameter1Value->setEnabled(false);

        // Clear text
        ui->TextCustomParameter1Value->setText("");

        // Set text in button
        ui->ButtonCustomParameter1Name->setText("Custom parameter 1");
    }
}

void nodeItemDialog::on_ButtonCustomParameter2Name_released()
{
    // Get QString with the name of parameter
    setTmpExtraParameter2Name(QInputDialog::getText(this, "Custom parameter 2", "Name of custom parameter 2"));

    // If tmpExtraParameter2Name != ""
    if(getTmpExtraParameter2Name() != "")
    {
        // Enable custom parameter value
        ui->TextCustomParameter2Value->setEnabled(true);

        // Set text in button
        ui->ButtonCustomParameter2Name->setText(getTmpExtraParameter2Name());
    }
    else
    {
        // Disable custom parameter value
        ui->TextCustomParameter2Value->setEnabled(false);

        // Clear text
        ui->TextCustomParameter2Value->setText("");

        // Set text in button
        ui->ButtonCustomParameter2Name->setText("Custom parameter 2");
    }
}

void nodeItemDialog::on_ButtonCustomParameter3Name_released()
{
    // Get QString with the name of parameter
    setTmpExtraParameter3Name(QInputDialog::getText(this, "Custom parameter 3", "Name of custom parameter 3"));

    // If tmpExtraParameter3Name != ""
    if(getTmpExtraParameter3Name() != "")
    {
        // Enable custom parameter value
        ui->TextCustomParameter3Value->setEnabled(true);

        // Set text in button
        ui->ButtonCustomParameter3Name->setText(getTmpExtraParameter3Name());
    }
    else
    {
        // Disable custom parameter value
        ui->TextCustomParameter3Value->setEnabled(false);

        // Clear text
        ui->TextCustomParameter3Value->setText("");

        // Set text in button
        ui->ButtonCustomParameter3Name->setText("Custom parameter 3");
    }
}

void nodeItemDialog::on_TextCustomParameter1Value_textChanged()
{
    setTmpExtraParameter1Value(ui->TextCustomParameter1Value->toPlainText());
}

void nodeItemDialog::on_TextCustomParameter2Value_textChanged()
{
    setTmpExtraParameter2Value(ui->TextCustomParameter2Value->toPlainText());
}

void nodeItemDialog::on_TextCustomParameter3Value_textChanged()
{
    setTmpExtraParameter3Value(ui->TextCustomParameter3Value->toPlainText());
}

void nodeItemDialog::on_CheckBoxBlocked_clicked()
{
    // IF CheckBoxBlocked is enabled
    if (ui->CheckBoxBlocked->isChecked())
    {
        // Disable all position texts
        ui->TextPosx->setEnabled(false);
        ui->TextPosy->setEnabled(false);
        ui->TextPosz->setEnabled(false);
    }
    else
    {
        // enable all position texts
        ui->TextPosx->setEnabled(true);
        ui->TextPosy->setEnabled(true);
        ui->TextPosz->setEnabled(true);
    }
}

void nodeItemDialog::on_ButtonEditTurnRatios_released()
{
    // Open Turn rations dialog
    n->getProject()->geteNetEditorMainWindow()->getTurnRatioTableDialog()->getTurnRatioItemDialog()->openItemDialog(n);
}

void nodeItemDialog::on_ButtonEditTrafficLight_released()
{

}

void nodeItemDialog::on_ListIncomingEdges_itemDoubleClicked(QListWidgetItem *item)
{

}

void nodeItemDialog::on_ListOutcomingEdges_itemDoubleClicked(QListWidgetItem *item)
{

}

void nodeItemDialog::on_ListConnections_itemDoubleClicked(QListWidgetItem *item)
{

}

void nodeItemDialog::on_ListTurnRatios_itemDoubleClicked(QListWidgetItem *item)
{

}
