#include "edgeItemDialog.h"
#include "ui_edgeItemDialog.h"

#include "../distributionFunctionItemDialog.h"

#include "../../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../../configuration/items/edges/edgeItemConfiguration.h"


#include "../../../database/eNetEditorDatabase.h"

#include "../../../items/edges/edgeItem.h"
#include "../../../items/edges/edgeTypeItem.h"
#include "../../../items/nodeItem.h"
#include "../../../items/distributionFunctionItem.h"


edgeItemDialog::edgeItemDialog(eNetEditorMainWindow *eNetEditorMainW) : abstractEdgeItemDialog(eNetEditorMainW), ui(new Ui::edgeItemDialog)
{
    // Create UI
    ui->setupUi(this);

    // Create distributionFunctionItemDialo
    detectorDistributionD = new distributionFunctionItemDialog(eNetEditorMainW);

    // Set edge pointer to null
    e = NULL;
}

edgeItemDialog::~edgeItemDialog()
{
    // Delete UI
    delete ui;

    // Delete distributionFunctionItemDialo
    delete detectorDistributionD;
}

void edgeItemDialog::resetParameters()
{
    // Priority can be changed
    tmpPriority = e->getPriority();

    // Streetname can be changed
    tmpStreetName = e->getStreetName();

    // Type can be changed
    tmpType = e->getType();

    // tmpSpreadtype can be changed
    tmpSpreadType = e->getSpreadType();

    // Set setTmpExtraParameter1Name with the value of the Item
    setTmpExtraParameter1Name(e->getExtraParameter1Name());

    // Set setTmpExtraParameter1Value with the value of the Item
    setTmpExtraParameter1Value(e->getExtraParameter1Value());

    // Set setTmpExtraParameter2Name with the value of the Item
    setTmpExtraParameter2Name(e->getExtraParameter2Name());

    // Set setTmpExtraParameter2Value with the value of the Item
    setTmpExtraParameter2Value(e->getExtraParameter2Value());

    // Set setTmpExtraParameter3Name with the value of the Item
    setTmpExtraParameter3Name(e->getExtraParameter3Name());

    // Set setTmpExtraParameter3Value with the value of the Item
    setTmpExtraParameter3Value(e->getExtraParameter3Value());
}

void edgeItemDialog::updateParameters()
{
    // Set edge ID
    ui->TextNodeID->setText(e->getItemId());
    ui->TextNodeID->setAlignment(Qt::AlignCenter);

    // Set start node
    ui->TextStartNode->setText(e->getNodeOrigin()->getItemId());
    ui->TextStartNode->setAlignment(Qt::AlignCenter);

    // Set destiny node
    ui->TextDestinyNode->setText(e->getNodeDestiny()->getItemId());
    ui->TextDestinyNode->setAlignment(Qt::AlignCenter);

    // Set lenght
    ui->TextLenght->setText(QString::number(e->getLength()));
    ui->TextLenght->setAlignment(Qt::AlignCenter);

    // Set number of lanes
    ui->TextNumberOfLanes->setText(QString::number(e->getNumberOfLanes()));
    ui->TextNumberOfLanes->setAlignment(Qt::AlignCenter);

    // Set priority
    ui->TextPriority->setText(QString::number(tmpPriority));
    ui->TextPriority->setAlignment(Qt::AlignCenter);

    // Set Street name
    ui->TextName->setText(tmpStreetName);
    ui->TextName->setAlignment(Qt::AlignCenter);

    // Set Type
    if(tmpType != NULL)
    {
        ui->ComboBoxType->setCurrentText(tmpType->getItemId());
    }

    // Set SpreadType
    ui->ComboBoxSpreadType->setCurrentText(e->getProjectConfiguration()->getEdgeItemConfiguration()->getEdgeSpreadTypeValue(tmpSpreadType));

    // Set tmpExtraParameter1Name with the value of the item
    setTmpExtraParameter1Name(e->getExtraParameter1Name());

    // Set tmpExtraParameter1Value with the value of the item
    setTmpExtraParameter1Value(e->getExtraParameter1Value());

    // If custom parameter 1 was changed
    if(e->getExtraParameter1Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter1Name->setText(e->getExtraParameter1Name());

        // Enable Text
        ui->TextCustomParameter1Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter1Value->setText(e->getExtraParameter1Value());
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
    setTmpExtraParameter2Name(e->getExtraParameter2Name());

    // Set tmpExtraParameter2Value with the value of the item
    setTmpExtraParameter2Value(e->getExtraParameter2Value());

    // If custom parameter 2 was changed
    if(e->getExtraParameter2Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter2Name->setText(e->getExtraParameter2Name());

        // Enable Text
        ui->TextCustomParameter2Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter2Value->setText(e->getExtraParameter2Value());
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
    setTmpExtraParameter3Name(e->getExtraParameter3Name());

    // Set tmpExtraParameter3Value with the value of the item
    setTmpExtraParameter3Value(e->getExtraParameter3Value());

    // If custom parameter 3 was changed
    if(e->getExtraParameter3Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter3Name->setText(e->getExtraParameter3Name());

        // Enable Text
        ui->TextCustomParameter3Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter3Value->setText(e->getExtraParameter3Value());
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

    // Get List of Lanes
    QStringList idsLanes = e->getDatabase()->getIdsOfLanes(e);

    // Set number of incomings edges in the Label
    ui->LabelListOfLanes->setText("Lanes: " + QString::number(idsLanes.size()));
    ui->LabelListOfLanes->setAlignment(Qt::AlignCenter);

    // Clear list
    ui->ListOfLanes->clear();

    // Set list of lanes in the UI
    for (QStringList::iterator i = idsLanes.begin(); i != idsLanes.end(); i++)
    {
        ui->ListOfLanes->addItem(new QListWidgetItem("Lane Id = " + (*i)));
    }
}

void edgeItemDialog::openItemDialog(eNetEditorItem *item)
{
    // Set pointer to edge
    e = dynamic_cast<edgeItem *>(item);

    // If item is an edge
    if(e)
    {
        // Reset parameters
        resetParameters();

        // Update parameters in all QWidgets;
        updateParameters();

        // Show Dialog
        show();
    }
}

void edgeItemDialog::on_ButtonAccept_released()
{
    // Set new type
    e->setType(tmpType);

    // Set new priority
    e->setPriority(tmpPriority);

    // Set new spread type
    e->setSpreadType(tmpSpreadType);

    // Set new Street name
    e->setStreetName(tmpStreetName);

    // Set new extra parameter 1
    if(ui->TextCustomParameter1Value->isEnabled())
    {
        e->setExtraParameter1Name(getTmpExtraParameter1Name());
        e->setExtraParameter1Value(getTmpExtraParameter1Value());
    }

    // Set new extra parameter 2
    if(ui->TextCustomParameter2Value->isEnabled())
    {
        e->setExtraParameter2Name(getTmpExtraParameter2Name());
        e->setExtraParameter2Value(getTmpExtraParameter2Value());
    }

    // Set new extra parameter 3
    if(ui->TextCustomParameter3Value->isEnabled())
    {
        e->setExtraParameter3Name(getTmpExtraParameter3Name());
        e->setExtraParameter3Value(getTmpExtraParameter3Value());
    }

    // Emit Signal
    emit dialogClosed(eNetEditorItemDialogCloseAccepted);

    // Close when all parameters were saved
    close();
}

void edgeItemDialog::on_ButtonCancel_released()
{
    // Emit cancel Signal
    emit dialogClosed(eNetEditorItemDialogCloseCanceled);

    // Close without saving
    close();
}

void edgeItemDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters in all QWidgets;
    updateParameters();
}

void edgeItemDialog::on_ButtonCustomParameter1Name_released()
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

void edgeItemDialog::on_ButtonCustomParameter2Name_released()
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

void edgeItemDialog::on_ButtonCustomParameter3Name_released()
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

void edgeItemDialog::on_TextCustomParameter1Value_textChanged()
{
    setTmpExtraParameter1Value(ui->TextCustomParameter1Value->toPlainText());
}

void edgeItemDialog::on_TextCustomParameter2Value_textChanged()
{
    setTmpExtraParameter2Value(ui->TextCustomParameter2Value->toPlainText());
}

void edgeItemDialog::on_TextCustomParameter3Value_textChanged()
{
    setTmpExtraParameter3Value(ui->TextCustomParameter3Value->toPlainText());
}

void edgeItemDialog::on_TextStartNode_textChanged()
{

}

void edgeItemDialog::on_TextDestinyNode_textChanged()
{

}

void edgeItemDialog::on_TextNumberOfLanes_textChanged()
{

}

void edgeItemDialog::on_TextLenght_textChanged()
{

}

void edgeItemDialog::on_TextPriority_textChanged()
{
    tmpPriority = ui->TextPriority->toPlainText().toInt();
}

void edgeItemDialog::on_TextName_textChanged()
{
    tmpStreetName = ui->TextName->toPlainText();
}

distributionFunctionItemDialog *edgeItemDialog::getDetectorDistributionDialog() const
{
    return detectorDistributionD;
}

void edgeItemDialog::on_ButtonFlowMeasure_released()
{
    detectorDistributionD->openItemDialog(e->getDistributionFunction());
}

void edgeItemDialog::on_ListOfLanes_itemDoubleClicked(QListWidgetItem *item)
{

}

void edgeItemDialog::on_ListOfRoutes_itemDoubleClicked(QListWidgetItem *item)
{

}

void edgeItemDialog::on_ComboBoxSpreadType_currentIndexChanged(int index)
{
    tmpSpreadType = static_cast<edgeSpreadType>(index);
}

void edgeItemDialog::on_ComboBoxEdgeType_currentIndexChanged(int index)
{

}
