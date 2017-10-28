#include "distributionFunctionItemDialog.h"
#include "ui_distributionFunctionItemDialog.h"

// QCustomPlot
#include "../../extern/QCustomPlot.h"

// Project
#include "../../project/eNetEditorProject.h"

// Database
#include "../../database/eNeteditorDatabase.h"

// Items
#include "../../items/edges/edgeItem.h"
#include "../../items/detectors/inductionLoopsE1DetectorItem.h"
#include "../../items/distributionFunctionItem.h"
#include "../../items/laneItem.h"
#include "../../items/flowMeasureItem.h"


distributionFunctionItemDialog::distributionFunctionItemDialog(eNetEditorMainWindow *eNetEditorMainW) : eNetEditorItemDialog(eNetEditorMainW), ui(new Ui::distributionFunctionItemDialog)
{
    // Create UI
    ui->setupUi(this);

    // By default, distributionFunction pointer is NULL
    df = NULL;

    // By default, traffic count is 0
    tmpTrafficCount = 0;

    // By default, PKWVelocity is 0
    tmpPKWVelocity = 0;

    // By default, LKWVelocity is 0
    tmpLKWVelocity = 0;

    // By default, sampling is 0
    tmpSampling = 0;

    // Ad graphs to scene
    PKW = ui->PlotDistributionFunction->addGraph();
    LKW = ui->PlotDistributionFunction->addGraph();
    Interval = ui->PlotDistributionFunction->addGraph();
}

distributionFunctionItemDialog::~distributionFunctionItemDialog()
{
    // Delete UI
    delete ui;
}

void distributionFunctionItemDialog::resetParameters()
{
    // Set temporal Data
    tmpData = df->getData();

    // Set temporal traffic count
    tmpTrafficCount = df->getTrafficCount();

    // Set temporal PKW Velocity
    tmpPKWVelocity = df->getPkwVelocity();

    // Set temporal LKW Veocity
    tmpLKWVelocity = df->getLkwVelocity();

    // Set default Procent of PKW
    tmpProcentPKW = df->getPkwProcent();

    // Set default Procent of LKW
    tmpProcentLKW = df->getLkwProcent();

    // Set default sampling
    tmpSampling = df->getSampling();
}

void distributionFunctionItemDialog::updateParameters()
{
    // Set edge count in Label
    ui->TextDistributionFunctionID->setText(df->getItemId());
    ui->TextDistributionFunctionID->setAlignment(Qt::AlignCenter);

    // Set traffic count
    ui->TextTrafficCount->setText(QString::number(tmpTrafficCount));
    ui->TextTrafficCount->setAlignment(Qt::AlignCenter);

    // Set PKW Velocity
    ui->TextPKWVelocity->setText(QString::number(tmpPKWVelocity));
    ui->TextPKWVelocity->setAlignment(Qt::AlignCenter);

    // Set LKW velocity
    ui->TextLKWVelocity->setText(QString::number(tmpLKWVelocity));
    ui->TextLKWVelocity->setAlignment(Qt::AlignCenter);

    // Set Sampling
    ui->SpinBoxSampling->setValue(tmpSampling);

    // Set Slider
    ui->horizontalSlider->setSliderPosition(tmpProcentPKW * 100);

    // Set Label
    ui->LabelProcent->setText("PKW: " + QString::number(tmpProcentPKW * 100) + "% - LKW: " + QString::number(tmpProcentLKW * 100) + "%");
    ui->LabelProcent->setAlignment(Qt::AlignCenter);

    // FillTable
    fillTable();
}

void distributionFunctionItemDialog::openItemDialog(eNetEditorItem *item)
{
    // Set pointer to distribution function
    df = dynamic_cast<distributionFunctionItem *>(item);

    // If item is a distribution function
    if(df)
    {
        // Reset parameters
        resetParameters();

        // Update parameters in all QWidgets;
        updateParameters();

        // Open Dialog
        show();
    }
}

void distributionFunctionItemDialog::fillTable()
{
    // clear Table
    ui->TableDistributionFunction->setColumnCount(0);
    ui->TableDistributionFunction->setRowCount(0);

    // Set size of table
    ui->TableDistributionFunction->setColumnCount(5);
    ui->TableDistributionFunction->setRowCount(tmpData.size());

    // Get QString to keep interval
    QString intervalA;  /// Not needed
    QString intervalB;  /// Not needed

    // Int for calculate time

    // Calculate number of hours in the begin interval
    int intervalNumberOfHours;

    // Calculate number of minutes in the end interval
    int intervalNumberOfMinutes;

    // Counter with the position in the table
    int counter = 0;

    // Fill Table
    for(QList< QVector<int> >::iterator i = tmpData.begin(); i != tmpData.end(); i++)
    {
        // Calculate number of hours in the begin interval
        intervalNumberOfHours = (*i).at(0) / 60;

        // Calculate number of minutes in the end interval
        intervalNumberOfMinutes = (*i).at(0) - (intervalNumberOfHours * 60);

        // Create interval
        intervalA = QString::number(intervalNumberOfHours) + ":" + QString::number(intervalNumberOfMinutes);

        // Declare QTableWidgetItem and set first interval
        QTableWidgetItem *tableItemInterval1 = new QTableWidgetItem(intervalA);

        // Calculate number of hours in the begin interval
        intervalNumberOfHours = (*i).at(1) / 60;

        // Calculate number of minutes in the end interval
        intervalNumberOfMinutes = (*i).at(1) - (intervalNumberOfHours * 60);

        // Create interval
        intervalB = QString::number(intervalNumberOfHours) + ":" + QString::number(intervalNumberOfMinutes);

        // Declare QTableWidgetItem and set second interval
        QTableWidgetItem *tableItemInterval2 = new QTableWidgetItem(intervalB);

        // Declare QTableWidgetItem and set numerator
        QTableWidgetItem *tableItemNumerator = new QTableWidgetItem(QString::number((*i).at(2)));

        // Declare QTableWidgetItem and set denominator
        QTableWidgetItem *tableItemDenominator = new QTableWidgetItem(QString::number((*i).at(3)));

        // Declare QTableWidgetItem and set value of fraction
        QTableWidgetItem *tableItemValue = new QTableWidgetItem(QString::number(qreal((*i).at(2)) / qreal((*i).at(3))));

        // Set QTableWidgetItem in the table
        ui->TableDistributionFunction->setItem(counter, 0, tableItemInterval1);
        ui->TableDistributionFunction->setItem(counter, 1, tableItemInterval2);
        ui->TableDistributionFunction->setItem(counter, 2, tableItemNumerator);
        ui->TableDistributionFunction->setItem(counter, 3, tableItemDenominator);
        ui->TableDistributionFunction->setItem(counter, 4, tableItemValue);

        // Update counter
        counter++;
    }

    // Plot Table
    plotFunction();
}

void distributionFunctionItemDialog::plotFunction()
{
    // Declare Qreal to keep the maximal y value
    qreal maxy = 0;
    qreal maxyAux = 0;

    // Iterate over the date
    for(QList< QVector<int> >::iterator i = tmpData.begin(); i != tmpData.end(); i++)
    {
        // calculate maxyAux
        maxyAux = qreal((*i).at(2)) / qreal((*i).at(3));

        // If maxyAux > maxy was founded
        if(maxyAux > maxy)
        {
            // Assing maxyAux to maxy
            maxy = maxyAux;
        }
    }

    // Plot graph LKW
    plotPKWGraph();

    // Plot graph LKW
    plotLKWGraph();

    // Plot interval graph
    plotIntervalGraph();

    // Enable Plott legend
    ui->PlotDistributionFunction->legend->setVisible(true);

    // Set graph front
    ui->PlotDistributionFunction->legend->setFont(QFont("Helvetica", 9));

    // Set locale to english
    ui->PlotDistributionFunction->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));

    // Set minimum value for y axis
    ui->PlotDistributionFunction->yAxis->setRangeLower(0);

    // Set maximun value for y axis
    if(maxy == 0 || maxy ==  1)
    {
        ui->PlotDistributionFunction->yAxis->setRangeUpper(1);
    }
    else
    {
        ui->PlotDistributionFunction->yAxis->setRangeUpper(maxy * 1.1);

    }

    // configure bottom axis to show date and time instead of number:
    ui->PlotDistributionFunction->xAxis->setTickLabelType(QCPAxis::ltNumber);

    // Disable autotickStep
    ui->PlotDistributionFunction->xAxis->setAutoTickStep(false);

    // Set tickstep to one hour (3600s
    ui->PlotDistributionFunction->xAxis->setTickStep(1);

    // Set sub-ticket to 15 minutes (15*4 = 1 Hour)
    ui->PlotDistributionFunction->xAxis->setSubTickCount(4);

    // Minimum value is 0 hours
    ui->PlotDistributionFunction->xAxis->setRangeLower(0);

    // Maximun value is 24 = 0 hours
    ui->PlotDistributionFunction->xAxis->setRangeUpper(24);

    // Set time format
    ui->PlotDistributionFunction->xAxis->setDateTimeFormat("hh");

    // Plot function
    ui->PlotDistributionFunction->replot();
}

void distributionFunctionItemDialog::plotPKWGraph()
{
    // Declare list with the values
    QVector<qreal> x, y;

    // Clear data of PKW
    PKW->clearData();

    // If tmpData isn't empty
    if(tmpData.empty() == false)
    {
        // Fill values
        for(QList< QVector<int> >::iterator i = tmpData.begin(); i != tmpData.end(); i++)
        {
            // Set X axis value
            x.push_back((*i).at(0) / qreal(60));

            // Set Y axis value
            y.push_back(qreal((*i).at(2)) / qreal((*i).at(3)) * tmpProcentPKW);
        }

        // Set last X axis value
        x.push_back(tmpData.last().at(1) * qreal(1) / qreal(60));

        // Set last Y axis value
        y.push_back(qreal(tmpData.first().at(2)) / qreal(tmpData.first().at(3)) * tmpProcentPKW);
    }

    /// Declare pen (Has to be declared in configuration
    QPen pen;

    pen.setColor(QColor("red"));

    PKW->setPen(pen);

    PKW->setName("PKW");

    PKW->setLineStyle(QCPGraph::lsLine);

    PKW->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));

    PKW->rescaleAxes(true);

    PKW->setData(x, y);
}

void distributionFunctionItemDialog::plotLKWGraph()
{
    // Declare list with the values
    QVector<qreal> x, y;

    // Clear data of LKW
    LKW->clearData();

    // If tmpData isn't empty
    if(tmpData.empty() == false)
    {
        // Fill values
        for(QList< QVector<int> >::iterator i = tmpData.begin(); i != tmpData.end(); i++)
        {
            // Set X axis value
            x.push_back((*i).at(0) / qreal(60));

            // Set Y axis value
            y.push_back(qreal((*i).at(2)) / qreal((*i).at(3)) * tmpProcentLKW);
        }

        // Set last X axis value
        x.push_back(tmpData.last().at(1));

        // Set last Y axis value
        y.push_back(qreal(tmpData.first().at(2)) / qreal(tmpData.first().at(3)) * tmpProcentLKW);
    }

    /// Declare pen (Has to be declared in configuration
    QPen pen;

    pen.setColor(QColor("black"));

    LKW->setPen(pen);

    LKW->setName("LKW");

    LKW->setLineStyle(QCPGraph::lsLine);

    LKW->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));

    LKW->rescaleAxes(true);

    LKW->setData(x, y);
}

void distributionFunctionItemDialog::plotIntervalGraph()
{
    // Declare data container
    QVector<qreal> x, y;

    // Clear data of Interval
    Interval->clearData();

    // If tmpData isn't empty
    if(tmpData.empty() == false)
    {
        // If procenf of PKWs is more than procent of LKW
        if(tmpProcentPKW > tmpProcentLKW)
        {
            // Iterate over PKW data
            for(QCPDataMap::iterator i = PKW->data()->begin(); i != PKW->data()->end(); i++)
            {
                // If the value of PKW data is in the interval of time
                if((i.key()) >= (df->getProject()->getTimeBegin() / qreal(3600)) && (i.key()) <= (df->getProject()->getTimeEnd() / qreal(3600)))
                {
                    // Set X axis
                    x.push_back(i.key());

                    // Set Y Axis
                    y.push_back(i.value().value);
                }
            }

        }
        else
        {
            // Iterate over LKW data
            for(QCPDataMap::iterator i = LKW->data()->begin(); i != LKW->data()->end(); i++)
            {
                // If the value of LKW data is in the interval of time
                if(((i.key()) >= df->getProject()->getTimeBegin()) && ((i.key()) <= df->getProject()->getTimeEnd()))
                {
                    // Set X axis
                    x.push_back(i.key());

                    // Set Y Axis
                    y.push_back(i.value().value);
                }
            }
        }
    }

    /// Declare pen (Has to be declared in configuration
    QPen pen;

    pen.setColor(QColor("blue"));

    Interval->setPen(pen);

    Interval->setName("Interval");

    Interval->setBrush(QBrush(QColor(0, 0, 255, 70)));

    Interval->setLineStyle(QCPGraph::lsLine);

    Interval->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));

    Interval->rescaleAxes(true);

    Interval->setData(x, y);
}

void distributionFunctionItemDialog::on_ButtonSearchDistributionFunction_released()
{
    // Open search Dialog
    QString distributionFunctionFile = QFileDialog::getOpenFileName(
                                           this,
                                           "Open distribution function file",
                                           df->getDatabase()->getProject()->getProjectPath() ,
                                           tr("distribution function file (*.*)" )
                                       );

    // If file was selected
    if(distributionFunctionFile != "")
    {
        // Load distribution function finle
        QFile distributionFunctionClose(distributionFunctionFile);

        // If loading was sucesfully
        if(distributionFunctionClose.open(QIODevice::ReadOnly))
        {
            // Delclare strings
            QString dataReaded;
            QString dataReadedWithoutSpaces;
            QString dataInterval1hour;
            QString dataInterval1minute;
            QString dataInterval2hour;
            QString dataInterval2minute;
            QString dataNumerator;
            QString dataDenominator;

            // Clear temporal distribution function
            tmpData.clear();

            // Declare stream
            QTextStream stream(&distributionFunctionClose);

            /** NOTA: Sería conveniente mejorar este metodo usando un interador
             * sobre dataReadedWithoutSpaces **/

            // While stream isn't at end of file
            while(!stream.atEnd())
            {
                // Clear all strings
                dataReaded.clear();
                dataReadedWithoutSpaces.clear();
                dataInterval1hour.clear();
                dataInterval1minute.clear();
                dataInterval2hour.clear();
                dataInterval2minute.clear();
                dataNumerator.clear();
                dataDenominator.clear();

                // Read line of file
                dataReaded = stream.readLine();

                // Clear Spaces
                while(!dataReaded.isEmpty())
                {
                    // If first character != " "
                    if(dataReaded.at(0) != ' ')
                    {
                        dataReadedWithoutSpaces.append(dataReaded.at(0));
                    }

                    // Remover first character
                    dataReaded.remove(0, 1);
                }

                // Extract first interval hour
                while(dataReadedWithoutSpaces.at(0) != ':')
                {
                    // Extract first interval hour
                    dataInterval1hour.push_back(dataReadedWithoutSpaces.at(0));

                    // Remover first character
                    dataReadedWithoutSpaces.remove(0, 1);
                }

                // Remover character ':'
                dataReadedWithoutSpaces.remove(0, 1);

                // Extract first interval minute
                while(dataReadedWithoutSpaces.at(0) != '-')
                {
                    // Extract first interval minute
                    dataInterval1minute.push_back(dataReadedWithoutSpaces.at(0));

                    // Remover first character
                    dataReadedWithoutSpaces.remove(0, 1);
                }

                // Remover character '-'
                dataReadedWithoutSpaces.remove(0, 1);

                // Extract second interval hour
                while(dataReadedWithoutSpaces.at(0) != ':')
                {
                    // Extract first interval hour
                    dataInterval2hour.push_back(dataReadedWithoutSpaces.at(0));

                    // Remover first character
                    dataReadedWithoutSpaces.remove(0, 1);
                }

                // Remover character ':'
                dataReadedWithoutSpaces.remove(0, 1);

                // Extract second interval minute
                while(dataReadedWithoutSpaces.at(0) != ';')
                {
                    // Extract first interval minute
                    dataInterval2minute.push_back(dataReadedWithoutSpaces.at(0));

                    // Remover first character
                    dataReadedWithoutSpaces.remove(0, 1);
                }

                // Remover character ';'
                dataReadedWithoutSpaces.remove(0, 1);

                // Extract numerator
                while(dataReadedWithoutSpaces.at(0) != '/')
                {
                    // Extract first interval minute
                    dataNumerator.push_back(dataReadedWithoutSpaces.at(0));

                    // Remover first character
                    dataReadedWithoutSpaces.remove(0, 1);
                }

                // Remover character '/'
                dataReadedWithoutSpaces.remove(0, 1);

                // Extract denominator
                while(!dataReadedWithoutSpaces.isEmpty())
                {
                    // Extract first interval minute
                    dataDenominator.push_back(dataReadedWithoutSpaces.at(0));

                    // Remover first character
                    dataReadedWithoutSpaces.remove(0, 1);

                }

                // Create date
                QVector<int> dateToInsert;

                // Fill date
                dateToInsert.push_back((dataInterval1hour.toInt() * 60) + dataInterval1minute.toInt());
                dateToInsert.push_back((dataInterval2hour.toInt() * 60) + dataInterval2minute.toInt());
                dateToInsert.push_back(dataNumerator.toInt());
                dateToInsert.push_back(dataDenominator.toInt());

                // insert date in tmpData
                tmpData.push_back(dateToInsert);
            }

            // Close file
            distributionFunctionClose.close();

            // Fill table
            fillTable();
        }
        else
        {
            qDebug() << "Error abriendo file";
        }
    }
}

void distributionFunctionItemDialog::on_ButtonAccept_released()
{
    // Set distribution function
    df->setData(tmpData);

    // Set trafficCount
    df->setTrafficCount(tmpTrafficCount);

    // Set PKWVelocity
    df->setPkwVelocity(tmpPKWVelocity);

    // Set LKWVelocity
    df->setLkwVelocity(tmpLKWVelocity);

    // Set Procent of PKW
    df->setPkwProcent(tmpProcentPKW);

    // set Sampling
    df->setSampling(tmpSampling);

    // Create flow measures
    df->make();

    // Emit Signal
    emit dialogClosed(eNetEditorItemDialogCloseAccepted);

    // Close Dialog
    close();
}

void distributionFunctionItemDialog::on_ButtonCancel_released()
{
    // Emit cancel Signal
    emit dialogClosed(eNetEditorItemDialogCloseCanceled);

    // Close dialog without saving
    close();
}

void distributionFunctionItemDialog::on_ButtonReset_released()
{
    // Reset parameters
    resetParameters();

    // Update parameters in all QWidgets;
    updateParameters();
}

void distributionFunctionItemDialog::on_horizontalSlider_sliderMoved(int position)
{
    // Set procent of PKW
    tmpProcentPKW = position * 0.01;

    // Set procent of LKW
    tmpProcentLKW = 1 - tmpProcentPKW;

    // Set Label
    ui->LabelProcent->setText("PKW: " + QString::number(tmpProcentPKW * 100) + "% - LKW: " + QString::number(tmpProcentLKW * 100) + "%");
    ui->LabelProcent->setAlignment(Qt::AlignCenter);

    // Replot function
    plotFunction();
}

void distributionFunctionItemDialog::on_TextPKWVelocity_textChanged()
{
    tmpPKWVelocity = ui->TextPKWVelocity->toPlainText().toDouble();
}

void distributionFunctionItemDialog::on_TextLKWVelocity_textChanged()
{
    tmpLKWVelocity = ui->TextLKWVelocity->toPlainText().toDouble();
}

void distributionFunctionItemDialog::on_TextTrafficCount_textChanged()
{
    tmpTrafficCount = ui->TextTrafficCount->toPlainText().toDouble();
}

void distributionFunctionItemDialog::on_SpinBoxSampling_valueChanged(int arg1)
{
    tmpSampling = arg1;
}
