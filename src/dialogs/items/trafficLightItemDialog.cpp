#include "trafficLightItemDialog.h"
#include "ui_trafficLightItemDialog.h"

#include "../../database/eNetEditorDatabase.h"
#include "../../database/trafficLightTable.h"

#include "../../project/eNetEditorProject.h"

#include "../../configuration/project/eNetEditorProjectConfiguration.h"

#include "../../configuration/items/trafficLightItemConfiguration.h"

#include "../../items/trafficLightItem.h"
#include "../../items/nodeItem.h"
#include "../../items/edges/edgeItem.h"
#include "../../items/laneItem.h"
#include "../../items/connectionItem.h"


trafficLightItemDialog::trafficLightItemDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorItemDialog(eNetEditorMainW), ui(new Ui::trafficLightItemDialog)
{
    // create UI
    ui->setupUi(this);

    // Set Traffic Light to edit to null
    tl = NULL;
}

trafficLightItemDialog::~trafficLightItemDialog()
{
    // Delete User Interface
    delete ui;
}

void trafficLightItemDialog::resetParameters()
{
    // Set setTmpExtraParameter1Name with the value of the Item
    setTmpExtraParameter1Name(tl->getExtraParameter1Name());

    // Set setTmpExtraParameter1Value with the value of the Item
    setTmpExtraParameter1Value(tl->getExtraParameter1Value());

    // Set setTmpExtraParameter2Name with the value of the Item
    setTmpExtraParameter2Name(tl->getExtraParameter2Name());

    // Set setTmpExtraParameter2Value with the value of the Item
    setTmpExtraParameter2Value(tl->getExtraParameter2Value());

    // Set setTmpExtraParameter3Name with the value of the Item
    setTmpExtraParameter3Name(tl->getExtraParameter3Name());

    // Set setTmpExtraParameter3Value with the value of the Item
    setTmpExtraParameter3Value(tl->getExtraParameter3Value());
}

void trafficLightItemDialog::updateParameters()
{
    // If custom parameter 1 was changed
    if(tl->getExtraParameter1Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter1Name->setText(tl->getExtraParameter1Name());

        // Enable Text
        ui->TextCustomParameter1Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter1Value->setText(tl->getExtraParameter1Value());
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
    if(tl->getExtraParameter2Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter2Name->setText(tl->getExtraParameter2Name());

        // Enable Text
        ui->TextCustomParameter2Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter2Value->setText(tl->getExtraParameter2Value());
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
    if(tl->getExtraParameter3Name() != NULL)
    {
        // Change Button text
        ui->ButtonCustomParameter3Name->setText(tl->getExtraParameter3Name());

        // Enable Text
        ui->TextCustomParameter3Value->setEnabled(true);

        // Change text
        ui->TextCustomParameter3Value->setText(tl->getExtraParameter3Value());
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

void trafficLightItemDialog::openItemDialog(eNetEditorItem *item)
{
    // Set pointer to traffic light
    tl = dynamic_cast<trafficLightItem *>(item);

    // If item is a traffic light
    if(tl)
    {

        // Set ID of Traffic light
        ui->TextID->setText(tl->getItemId());

        // Set passing time
        ui->TextPassingTime->setText(QString::number(tl->getPassingTime()));

        // Set Max gap
        ui->TextMaxGap->setText(QString::number(tl->getMaxGap()));

        // Set detector gap
        ui->TextDetectorGap->setText(QString::number(tl->getDetectorGap()));
        /**
            //Only fill table if the traffic light has Connections
            if(tl->getNodeParent()->getNumberOfConnections() > 0)
            {

            }

            ui->TableTrafficLights->item(0,0)->setData (Qt::BackgroundColorRole ,QColor("#grey"));
        */

        makeTable();
        // Show dialog
        show();
    }
}

void trafficLightItemDialog::makeTable()
{
    // Declare Icons
    QIcon addIcon;
    QIcon removeIcon;
    QIcon semaphoreIcon;
    QIcon durationIcon;

    // Declare map to keep the connection order by linkIndex
    QVector<connectionItem *> connectionOrderedByLinkIndex;

    // Set icons
    addIcon.addFile(QStringLiteral(":/main/add.ico"), QSize(), QIcon::Normal, QIcon::Off);
    removeIcon.addFile(QStringLiteral(":/main/remove.ico"), QSize(), QIcon::Normal, QIcon::Off);
    semaphoreIcon.addFile(QStringLiteral(":/icons/semaphore.jpg"), QSize(), QIcon::Normal, QIcon::Off);
    durationIcon.addFile(QStringLiteral(":/main/duration.ico"), QSize(), QIcon::Normal, QIcon::Off);

    // Clear table
    ui->TableTrafficLights->clear();

    // Set Rows
    ui->TableTrafficLights->setColumnCount(tl->getVectorOfDuration().size() + 2);
    ui->TableTrafficLights->setRowCount(tl->getNodeParent()->getNumberOfConnections() + 2);

    // Update size of connectionOrderedByLinkIndex
    connectionOrderedByLinkIndex.fill(NULL, tl->getNodeParent()->getNumberOfConnections());

    // Get the connections order by linkIndex
    for(QList<connectionItem *>::iterator i = tl->getNodeParent()->iteratorConnectionsBegin(); i != tl->getNodeParent()->iteratorConnectionsEnd(); i++)
    {
        // If the size of vectors (states and duration are different)
        if((*i)->getVectorOfStates().size() < tl->getVectorOfDuration().size())
        {
            // Declare fixVectorOfStates
            QVector<char> fixVectorOfStates;

            // Fill fixVectorOfStates with the rest of states
            fixVectorOfStates.fill('g', tl->getVectorOfDuration().size() - (*i)->getVectorOfStates().size() );

            // Set in the connection the fixVectorOfStates
            (*i)->setVectorOfStates((*i)->getVectorOfStates() + fixVectorOfStates);
        }

        // Insert connection in the connectionOrderedByLinkIndex
        connectionOrderedByLinkIndex[(*i)->getIndexRegardingNode()] = (*i);
    }

    // Fill rows and columns
    for (int i = 0; i < (tl->getNodeParent()->getNumberOfConnections() + 2); i++)
    {
        for (int j = 0; j < (tl->getVectorOfDuration().size() + 2); j++)
        {
            // Create QTableWidgetItem
            QTableWidgetItem *tableItem = new QTableWidgetItem();

            // Configure the first row
            if(i == 0)
            {
                // Set Semaphore icon in the coordinate (0,0)
                if(j == 0)
                {
                    // Set semaphore Icon
                    tableItem->setIcon(semaphoreIcon);

                    // Disable editing
                    tableItem->setFlags(tableItem->flags() ^ Qt::ItemIsEditable);
                }
                // If is the last column
                else if (j == (tl->getVectorOfDuration().size() + 1))
                {
                    // Set add Icon
                    tableItem->setIcon(addIcon);

                    // Disable editing
                    tableItem->setFlags(tableItem->flags() ^ Qt::ItemIsEditable);
                }
                else
                {
                    // Set remove Icon
                    tableItem->setIcon(removeIcon);

                    // Disable editing
                    tableItem->setFlags(tableItem->flags() ^ Qt::ItemIsEditable);
                }
            }
            // Set the second row
            else if (i == 1)
            {
                // If this is the first column, set the duration icon
                if (j == 0)
                {
                    // Set duration row
                    tableItem->setIcon(durationIcon);

                    // Disable editing
                    tableItem->setFlags(tableItem->flags() ^ Qt::ItemIsEditable);
                }
                // Set the rest of durations
                else if (j < tl->getVectorOfDuration().size() + 1)
                {
                    tableItem->setText(QString::number(tl->getVectorOfDuration().at(j - 1)));
                }
            }
            // Set the rest of columns
            else
            {
                // If this is the first column, set the linkIndex
                if (j == 0)
                {
                    // Set linkIndex
                    tableItem->setText(QString::number(i - 2));

                    // Disable editing
                    tableItem->setFlags(tableItem->flags() ^ Qt::ItemIsEditable);
                }
                else if (j < tl->getVectorOfDuration().size() + 1)
                {
                    // if is a phase
                    tableItem->setText(QString(connectionOrderedByLinkIndex[i - 2]->getVectorOfStates().at(j - 1)));
                }


            }

            // Set item in the table
            ui->TableTrafficLights->setItem(i, j, tableItem);
        }
    }
}

void trafficLightItemDialog::on_ButtonAccept_released()
{
    // If custom parameter 1 has been modified
    if(ui->TextCustomParameter1Value->isEnabled())
    {
        // Set name and value of custom parameter 1 in the item
        tl->setExtraParameter1Name(getTmpExtraParameter1Name());
        tl->setExtraParameter1Value(getTmpExtraParameter1Value());
    }

    // If custom parameter 2 has been modified
    if(ui->TextCustomParameter2Value->isEnabled())
    {
        // Set name and value of custom parameter 2 in the item
        tl->setExtraParameter2Name(getTmpExtraParameter2Name());
        tl->setExtraParameter2Value(getTmpExtraParameter2Value());
    }

    // If custom parameter 3 has been modified
    if(ui->TextCustomParameter3Value->isEnabled())
    {
        // Set name and value of custom parameter 3 in the item
        tl->setExtraParameter3Name(getTmpExtraParameter3Name());
        tl->setExtraParameter3Value(getTmpExtraParameter3Value());
    }

    // Emit Signal
    emit dialogClosed(eNetEditorItemDialogCloseAccepted);

    // Close dialog
    close();
}

void trafficLightItemDialog::on_ButtonCancel_released()
{
    // Emit cancel Signal
    emit dialogClosed(eNetEditorItemDialogCloseCanceled);

    // Close dialog
    close();
}

void trafficLightItemDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters in all QWidgets;
    updateParameters();
}

void trafficLightItemDialog::on_ButtonCustomParameter1Name_released()
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

void trafficLightItemDialog::on_ButtonCustomParameter2Name_released()
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

void trafficLightItemDialog::on_ButtonCustomParameter3Name_released()
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

void trafficLightItemDialog::on_TextCustomParameter1Value_textChanged()
{
    setTmpExtraParameter1Value(ui->TextCustomParameter1Value->toPlainText());
}

void trafficLightItemDialog::on_TextCustomParameter2Value_textChanged()
{
    setTmpExtraParameter2Value(ui->TextCustomParameter2Value->toPlainText());
}

void trafficLightItemDialog::on_TextCustomParameter3Value_textChanged()
{
    setTmpExtraParameter3Value(ui->TextCustomParameter3Value->toPlainText());
}

void trafficLightItemDialog::on_TableTrafficLights_itemDoubleClicked(QTableWidgetItem *item)
{
    // If the row is the first row
    if(item->row() == 0)
    {
        // Remove column
        if((item->column() > 0) && (item->column() < tl->getVectorOfDuration().size() + 1))
        {
            // Declare QList of states
            QVector<char> vectorOfStates;

            for (QList<connectionItem *>::iterator i = tl->getNodeParent()->iteratorConnectionsBegin(); i != tl->getNodeParent()->iteratorConnectionsEnd(); i++)
            {
                // Get list of states
                vectorOfStates = (*i)->getVectorOfStates();

                // Update list
                vectorOfStates.removeAt(item->column() - 1);

                // Set new list in the connection
                (*i)->setVectorOfStates(vectorOfStates);
            }

            // Declare QList of durations
            QVector<int> vectorOfDurations;

            // Get list of durations of traffic light
            vectorOfDurations = tl->getVectorOfDuration();

            // Update list Of durations
            vectorOfDurations.removeAt(item->column() - 1);

            // Set new list in the traffic light
            tl->setVectorOfDurations(vectorOfDurations);

            //Remake table
            makeTable();
        }
        // Add column
        else if(item->column() == (tl->getVectorOfDuration().size() + 1))
        {
            // Declare QList of states
            QVector<char> vectorOfStates;

            for (QList<connectionItem *>::iterator i = tl->getNodeParent()->iteratorConnectionsBegin(); i != tl->getNodeParent()->iteratorConnectionsEnd(); i++)
            {
                // Get list of states
                vectorOfStates = (*i)->getVectorOfStates();

                // Update list
                vectorOfStates.push_back('g');

                // Set new list in the connection
                (*i)->setVectorOfStates(vectorOfStates);
            }

            // Declare QList of durations
            QVector<int> vectorOfDurations;

            // Get list of durations of traffic light
            vectorOfDurations = tl->getVectorOfDuration();

            // Update list Of durations
            vectorOfDurations.push_back(tl->getProjectConfiguration()->getTrafficLightItemConfiguration()->getTrafficLightDefaultDuration());

            // Set new list in the traffic light
            tl->setVectorOfDurations(vectorOfDurations);

            //Remake table
            makeTable();
        }
    }
}

void trafficLightItemDialog::on_TableTrafficLights_itemChanged(QTableWidgetItem *item)
{
    if(item->column() > 0 && item->column() < tl->getVectorOfDuration().size() + 1)
    {
        if(item->row() == 1)
        {
            // Declare QList of durations
            QVector<int> vectorOfDurations;

            // Get list of durations of traffic light
            vectorOfDurations = tl->getVectorOfDuration();

            // Update list Of durations
            vectorOfDurations.replace(item->column() - 1, item->text().toInt());

            // Set new list in the traffic light
            tl->setVectorOfDurations(vectorOfDurations);

        }
        else if (item->row() > 1 && (item->row() < tl->getNodeParent()->getNumberOfConnections() + 2))
        {
            // Declare QList of durations
            QVector<char> vectorOfStates;

            // Get list of durations of traffic light
            vectorOfStates = tl->getNodeParent()->getConnectionByIndex(item->row() - 2)->getVectorOfStates();

            // Update list Of durations
            vectorOfStates.replace(item->column() - 1, item->text().at(0).toLatin1());

            // Set new list in the traffic light
            tl->getNodeParent()->getConnectionByIndex(item->row() - 2)->setVectorOfStates(vectorOfStates);
        }
    }
}
