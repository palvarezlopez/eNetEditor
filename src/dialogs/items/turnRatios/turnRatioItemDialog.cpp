#include "turnRatioItemDialog.h"
#include "ui_turnRatioItemDialog.h"

// Plot Graph
#include "../../../extern/QCustomPlot.h"

// Configuration
#include "../../../configuration/project/eNetEditorProjectConfiguration.h"
#include "../../../configuration/items/turnRatios/turnRatioIntervalItemConfiguration.h"

// Database
#include "../../../database/eNetEditorDatabase.h"
#include "../../../database/edges/edgeTable.h"
#include "../../../database/turnRatios/turnRatioIntervalTable.h"
#include "../../../database/turnRatios/turnRatioTable.h"

// Project
#include "../../../project/eNetEditorProject.h"

// Table Dialog
#include "../../database/turnRatios/turnRatioIntervalTableDialog.h"
#include "../../database/turnRatios/turnRatioTableDialog.h"

// Item dialog
#include "../../items/turnRatios/turnRatioIntervalDialog.h"

// Main Windows
#include "../../main/eNetEditorMainWindow.h"

// Item
#include "../../../items/nodeItem.h"
#include "../../../items/edges/edgeItem.h"
#include "../../../items/turnRatios/turnRatioIntervalItem.h"
#include "../../../items/turnRatios/turnRatioItem.h"


turnRatioItemDialog::turnRatioItemDialog(eNetEditorMainWindow *eNetEditorMainW) : abstractTurnRatioItemDialog(eNetEditorMainW), ui(new Ui::turnRatioItemDialog)
{
    // Create UI
    ui->setupUi(this);
}

turnRatioItemDialog::~turnRatioItemDialog()
{
    // Delete UI
    delete ui;
}

void turnRatioItemDialog::resetParameters()
{
    //QCPGraph

    // Set pointer to temporal turnRatioIntervalItem
    turnRatioInterval = NULL;

    // Set Pinter to edge from
    edgeFrom = NULL;

    // Set triTemporal to NULL
    turnRatioInterval = NULL;
}

void turnRatioItemDialog::updateParameters()
{
    // Clear interval table
    clearGraph();

    // Clear layout Sliders
    clearLayourSliders();

    // Fill interval table
    fillIntervalTable();

    // Clear edgeFrom Table
    ui->listOfFromEdge->clear();

    // Enable Plott legend
    ui->graphTurnRatios->legend->setVisible(false);

    // Set graph front
    ui->graphTurnRatios->legend->setFont(QFont("Helvetica", 9));

    // Set locale to english
    ui->graphTurnRatios->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));

    // Disable autotickStep
    ui->graphTurnRatios->yAxis->setAutoTickStep(false);

    // Set tickstep to one hour 0.1
    ui->graphTurnRatios->yAxis->setTickStep(0.1);

    // Set sub-ticket to 0.05
    ui->graphTurnRatios->yAxis->setSubTickCount(2);

    // Set minimum value for y axis
    ui->graphTurnRatios->yAxis->setRangeLower(0);

    // Set maximun value for y axis
    ui->graphTurnRatios->yAxis->setRangeUpper(1);

    // configure bottom axis to show date and time instead of number:
    ui->graphTurnRatios->xAxis->setTickLabelType(QCPAxis::ltNumber);

    // Show label
    ui->graphTurnRatios->xAxis->setLabel("Edge from:");

    // Disable autotickStep
    ui->graphTurnRatios->xAxis->setAutoTickStep(false);

    // Set tickstep to one hour (3600s)
    ui->graphTurnRatios->xAxis->setTickStep(1);

    // Set sub-ticket to 15 minutes (15*4 = 1 Hour)
    ui->graphTurnRatios->xAxis->setSubTickCount(4);

    // Minimum value is 0 hours
    ui->graphTurnRatios->xAxis->setRangeLower(0);

    // Maximun value is 24 = 0 hours
    ui->graphTurnRatios->xAxis->setRangeUpper(24);

    // Set time format
    ui->graphTurnRatios->xAxis->setDateTimeFormat("hh");

    // Plot function
    ui->graphTurnRatios->replot();
}

void turnRatioItemDialog::openItemDialog(eNetEditorItem *item)
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



void turnRatioItemDialog::on_ButtonAccept_released()
{
    // Close Dialog
    close();
}

void turnRatioItemDialog::on_ButtonCancel_released()
{
    qDebug() << "TERMINAR";

    // Close Dialog
    close();
}

void turnRatioItemDialog::on_ButtonReset_released()
{
    resetParameters();

    updateParameters();
}

void turnRatioItemDialog::on_listOfFromEdge_itemClicked(QListWidgetItem *item)
{
    // Find edge From in database using ID of List
    edgeItem *tmpEdgeFrom = dynamic_cast<edgeItem *>(n->getDatabase()->getEdgeTable()->findItemById(item->text()));

    // If founded edge is differnt of keeped edge
    if (tmpEdgeFrom != edgeFrom)
    {
        // Set pointer to selected edge from
        edgeFrom = tmpEdgeFrom;

        // Clear graph
        clearGraph();

        // Clear layour slider
        clearLayourSliders();

        // Plot graph
        plotEdgeGraph();

        // Set Slidres
        fillLayoutSliders();
    }
}

void turnRatioItemDialog::on_listOfInterval_itemClicked(QListWidgetItem *item)
{
    // Get turn ratio interval of list
    turnRatioIntervalItem *tmpTurnRatioInterval = dynamic_cast<turnRatioIntervalItem *>(n->getDatabase()->getTurnRatioIntervalTable()->findItemById(item->text()));

    // If selected turn ratio interval is different of the keeped in pointer
    if(tmpTurnRatioInterval != turnRatioInterval)
    {
        // Clear graph
        clearGraph();

        // Clear layout sliders
        clearLayourSliders();

        // Set pointer to turn ratio interval
        turnRatioInterval = tmpTurnRatioInterval;

        // Fill edge From Table
        fillEdgeFromTable();
    }

}

void turnRatioItemDialog::probabilityChanged(int value)
{
    // Declare pointer to turn Ratio
    turnRatioItem *tr = NULL;

    // Declare iterator over list of probabilities
    int index = 0;

    // Iterate over list of Probabilities of turnRatioItem
    for(QList< QPair< QSlider *, turnRatioItem *> >::iterator i = listOfSlider.begin(); i != listOfSlider.end(); i++)
    {
        // If values in both list are different
        if((*i).first->value() != listOfProbabilities.at(index))
        {
            // Keep pointer to turn ratio
            tr = (*i).second;

            // Set iterator at end of list
            i = listOfSlider.end() - 1;
        }
        else
        {
            // Update index
            index++;
        }
    }

    // If turn ratio changed was founded
    if(tr)
    {
        // Update value
        listOfProbabilities[index] = listOfSlider.at(index).first->value();

        // Declare list of turn Ratios item
        QList<turnRatioItem *> listOfNonBlockedTurnRatios;

        // Iterate over non-bloqued turn Ratios of turn Ratio Interval Parent
        for(QList<turnRatioItem *>::iterator i = tr->getTurnRatioIntervalParent()->iteratorTurnRatiosBegin(); i != tr->getTurnRatioIntervalParent()->iteratorTurnRatiosEnd(); i++)
        {
            // If iterator have the same edgeFrom and is0nt bloqued:
            if(((*i)->getEdgeFrom() == tr->getEdgeFrom()) && ((*i)->isProbabilityBlocked() == false))
            {
                // Add turn ratio to listOfNonBlockedTurnRatios
                listOfNonBlockedTurnRatios.push_back(*i);
            }
        }

        // Declare qreal to keep sumatorial of all non.bloked probabilities
        qreal sumatorial = 0;

        // Iterate over listOfNonBlockedTurnRatios
        for(QList<turnRatioItem *>::iterator i = listOfNonBlockedTurnRatios.begin(); i != listOfNonBlockedTurnRatios.end(); i++)
        {
            // Get sumatorial
            sumatorial += (*i)->getProbability();
        }

        // Set new probability of turn Ratio
        tr->setProbability(qreal(value) / 100);

        // Substrae new probability of the sumatorial
        sumatorial -= tr->getProbability();

        // If there are exactly two  turn ratios
        if (listOfNonBlockedTurnRatios.size() == 2)
        {
            // Remove founded turn Ratio of list
            listOfNonBlockedTurnRatios.removeAll(tr);

            // Get sumatorial
            listOfNonBlockedTurnRatios.first()->setProbability(1 - (tr->getProbability()));
        }
        // If there are more than two turn ratios
        else if(listOfNonBlockedTurnRatios.size() > 2)
        {
            // Calculate probability of every turn ratio
            sumatorial /= (listOfNonBlockedTurnRatios.size() - 1);

            qDebug() << "sumatorial3: " << sumatorial;

            // Iterate over listOfNonBlockedTurnRatios
            for(QList<turnRatioItem *>::iterator i = listOfNonBlockedTurnRatios.begin(); i != listOfNonBlockedTurnRatios.end(); i++)
            {
                if((*i) != tr)
                {
                    // Get sumatorial
                    (*i)->setProbability(sumatorial);
                }
            }
        }

        for(QList< QPair< QSlider *, turnRatioItem *> >::iterator i = listOfSlider.begin(); i != listOfSlider.end(); i++)
        {
            if((*i).second != tr)
            {
                (*i).first->setValue(((*i).second->getProbability() * 100));
            }
        }
    }
}

void turnRatioItemDialog::probabilityBlocked(bool value)
{
    // Declare pointer to turn Ratio
    turnRatioItem *tr = NULL;

    // Declare iterator over list of Booleans
    int index = 0;

    // Iterate over list of Probabilities of turnRatioItem
    for(QList< QPair< QCheckBox *, turnRatioItem *> >::iterator  i = listOfCheckBox.begin(); i != listOfCheckBox.end(); i++)
    {
        // If values in both list are different
        if((*i).first->isChecked() != listOfBooleans.at(index))
        {
            // Keep pointer to turn ratio
            tr = (*i).second;

            // Set iterator at end of list
            i = listOfCheckBox.end() - 1;
        }
        else
        {
            // Update index
            index++;
        }
    }

    // If turn ratio changed was founded
    if(tr)
    {
        // Update value
        listOfBooleans[index] = listOfCheckBox.at(index).first->isChecked();

        qDebug() << tr->getEdgeFrom()->getItemId() << "-" << tr->getEdgeTo()->getItemId();
    }
}

void turnRatioItemDialog::fillIntervalTable()
{
    // Clear UI listOfInterval
    ui->listOfInterval->clear();

    // Iterate over Turn Ratio Intervals of node
    for(QList<eNetEditorItem *>::iterator i = n->getDatabase()->getTurnRatioIntervalTable()->iteratorTableBegin(); i != n->getDatabase()->getTurnRatioIntervalTable()->iteratorTableEnd(); i++)
    {
        // Add if to list
        ui->listOfInterval->addItem(new QListWidgetItem((*i)->getItemId()));
    }

    // Set Label
    ui->LabelInterval->setText("Intervals: " + QString::number(n->getDatabase()->getTurnRatioIntervalTable()->getNumberOfItems()));
    ui->LabelInterval->setAlignment(Qt::AlignCenter);
}

void turnRatioItemDialog::fillEdgeFromTable()
{
    // Clear UI listOfInterval
    ui->listOfFromEdge->clear();

    // Iterate over incomings edges of node
    for (QList<edgeItem *>::iterator i = n->iteratorIncomingEdgesBegin(); i != n->iteratorIncomingEdgesEnd(); i++)
    {
        // Add if to list
        ui->listOfFromEdge->addItem(new QListWidgetItem((*i)->getItemId()));
    }

    // Set Label
    ui->LabelFromEdge->setText("Incoming edges: " + QString::number(n->getNumberOfIncomingEdges()));
    ui->LabelFromEdge->setAlignment(Qt::AlignCenter);
}

void turnRatioItemDialog::clearGraph()
{
    // If listOfGraphs isn't empty
    if(listOfGraphs.size() > 0)
    {
        // Clear graphs of scene
        for(QList<QCPGraph *>::iterator i = listOfGraphs.begin(); i != listOfGraphs.end(); i++)
        {
            // Remove graphs from widget
            ui->graphTurnRatios->removeGraph(*i);
        }
    }

    // Clear list of Graphs
    listOfGraphs.clear();
}

void turnRatioItemDialog::plotEdgeGraph()
{
    // Clear Graph
    clearGraph();

    // Declare Data vector
    QVector<qreal> x, y;

    // Turn Ratio
    QList<turnRatioItem *> listOfTurnRatios;

    // Set bot label
    ui->graphTurnRatios->xAxis->setLabel("Edge from: " + edgeFrom->getItemId());

    // Declare temporal turnRatioIntervalItem
    turnRatioIntervalItem *triAux = NULL;

    // Iterate over turnRatioIntervalItem of node
    for(QList<eNetEditorItem *>::iterator i = n->getDatabase()->getTurnRatioIntervalTable()->iteratorTableBegin(); i != n->getDatabase()->getTurnRatioIntervalTable()->iteratorTableEnd(); i++)
    {
        // Cast turnRatioInterval
        triAux = dynamic_cast<turnRatioIntervalItem *>(*i);

        // Clear Data vectors
        x.clear();

        // Set data of vector X
        x.push_back(triAux->getIntervalBegin() / 3600);
        x.push_back(triAux->getIntervalEnd() / 3600);

        listOfTurnRatios.clear();

        // Get list of turn Turn ratios of edge from
        listOfTurnRatios = triAux->getListOfTurnRatioByEdgeFrom(edgeFrom);

        for(QList<turnRatioItem *>::iterator j = listOfTurnRatios.begin(); j != listOfTurnRatios.end(); j++)
        {
            // Clear vector y of data
            y.clear();

            // Add Probability asociated to edge
            y.push_back((*j)->getProbability());
            y.push_back((*j)->getProbability());

            // Create new graph
            QCPGraph *edgeGraph = ui->graphTurnRatios->addGraph();

            /// Declare pen (Has to be declared in configuration
            QPen pen;

            pen.setColor("red");

            edgeGraph->setPen(pen);

            edgeGraph->setName("Edge " + (*j)->getEdgeTo()->getItemId());

            edgeGraph->setLineStyle(QCPGraph::lsLine);

            edgeGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));

            edgeGraph->rescaleAxes(true);

            edgeGraph->setData(x, y);
            /*
                        if(i == n->iteratorTurnRatioIntervalsBegin())
                        {
                            edgeGraph->addToLegend();
                        }
                        else
                        {
                            edgeGraph->removeFromLegend();
                        }
            */
            // Add new Graph to list of graphs
            listOfGraphs.push_back(edgeGraph);
        }

    }

    if(listOfGraphs.size() > 0)
    {
        ui->graphTurnRatios->legend->setVisible(true);
    }
    else
    {
        ui->graphTurnRatios->legend->setVisible(false);
    }

    // Plot function
    ui->graphTurnRatios->replot();
}

void turnRatioItemDialog::fillLayoutSliders()
{
    // If edgeFrom exists
    if(edgeFrom != NULL)
    {
        // Declare pointer for creating new elements
        QLabel *edgeLabel;
        QHBoxLayout *layoutSlider;
        QSlider *slider;
        QCheckBox *checkBoxBlocked;

        // Remove vertical Spacer
        ui->LayoutEdgeToSliders->removeItem(ui->verticalSpacer);

        // Declare list of turn Ratiose
        QList<turnRatioItem *> listOfTurnRatios;

        // Get list of turn Turn ratios of edge from
        listOfTurnRatios = turnRatioInterval->getListOfTurnRatioByEdgeFrom(edgeFrom);

        // Declare counter for the name of objects
        int counterName = 0;

        // Iterate over list of edges to
        for(QList<turnRatioItem *>::iterator i = listOfTurnRatios.begin(); i != listOfTurnRatios.end(); i++)
        {
            // Create new Edge Label
            edgeLabel = new QLabel(ui->scrollAreaWidgetContents);

            // Set object name
            edgeLabel->setObjectName(QStringLiteral("LabelEdgeTo"));

            // Set text oflabel
            edgeLabel->setText("To edge: " + (*i)->getEdgeTo()->getItemId());

            // Add widget to layoutslider
            ui->LayoutEdgeToSliders->addWidget(edgeLabel);

            // Create Horizontal Box Layout
            layoutSlider = new QHBoxLayout();

            // Set Horizontal Box Layout Object name
            layoutSlider->setObjectName("LayoutSlider" + QString::number(counterName));

            // Declare Slider
            slider = new QSlider(ui->scrollAreaWidgetContents);

            // Set slider name
            slider->setObjectName("SliderEdge" + QString::number(counterName));

            // Set minimun range of slider
            slider->setMinimum(0);

            // Set maximum  range of slider
            slider->setMaximum(100);

            // Set position of slider (Probability of turn ratio)
            slider->setSliderPosition(int((*i)->getProbability() * 100));

            // Set orientation of slider
            slider->setOrientation(Qt::Horizontal);

            // Add Slider to Horizontal Layout
            layoutSlider->addWidget(slider);

            // Declare CheckBox
            checkBoxBlocked = new QCheckBox(ui->scrollAreaWidgetContents);

            // Set Object name(Blocking of turn ratio Probability)
            checkBoxBlocked->setObjectName("CheckBoxBlock" + QString::number(counterName));

            // Set checkbox Bloqued
            checkBoxBlocked->setChecked((*i)->isProbabilityBlocked());

            // Add Checkbox to Horixontal Layout
            layoutSlider->addWidget(checkBoxBlocked);

            // Add Horizontal Layout to LayoutEdgeToSliders
            ui->LayoutEdgeToSliders->addLayout(layoutSlider);

            // Connect Slider
            connect(slider, SIGNAL(valueChanged(int)), this, SLOT(probabilityChanged(int)));

            // Connect Checkbox
            connect(checkBoxBlocked, SIGNAL(toggled(bool)), this, SLOT(probabilityBlocked(bool)));

            // Adde label to list of QLabels
            listOfLabelEdgeTo.push_back(edgeLabel);

            // Add Horiontal Box Layout to list of QHBoxLayouts
            listOfBoxLayout.push_back(layoutSlider);

            // Add Slider to list of QSliders
            listOfSlider.push_back(QPair< QSlider *, turnRatioItem *> (slider, (*i)));

            // Add checkBox to list of QCheckBoxs
            listOfCheckBox.push_back(QPair< QCheckBox *, turnRatioItem *>(checkBoxBlocked, (*i)));

            // Add Probability to list
            listOfProbabilities.push_back(slider->value());

            // Add Boolean to list
            listOfBooleans.push_back(checkBoxBlocked->isChecked());

            // Update counter name
            counterName++;
        }

        // Add Vertical Spacer
        ui->LayoutEdgeToSliders->addItem(ui->verticalSpacer);
    }
}

void turnRatioItemDialog::clearLayourSliders()
{
    // Interate over list with QLabels
    for(QList<QLabel *>::iterator i = listOfLabelEdgeTo.begin(); i != listOfLabelEdgeTo.end(); i++)
    {
        // Remove Item of layout
        ui->LayoutEdgeToSliders->addWidget(*i);

        // Delete item
        delete (*i);
    }

    // Clear list with QLabels
    listOfLabelEdgeTo.clear();

    // CInterate over with QSliders
    for(QList< QPair< QSlider *, turnRatioItem *> >::iterator i = listOfSlider.begin(); i != listOfSlider.end(); i++)
    {

        disconnect((*i).first, SIGNAL(sliderMoved(int)), this, SLOT(probabilityChanged(int)));

        // Delete item
        delete (*i).first;
    }

    // Clear list with QSliders
    listOfSlider.clear();

    // Interate over with QCheckBoxs
    for(QList< QPair< QCheckBox *, turnRatioItem *> >::iterator i = listOfCheckBox.begin(); i != listOfCheckBox.end(); i++)
    {
        // Disconnect checkboxBLoqued
        disconnect((*i).first, SIGNAL(toggled(bool)), this, SLOT(probabilityBlocked(bool)));

        // Delete item
        delete (*i).first;
    }

    // Clear list with QSliders
    listOfCheckBox.clear();

    // Interate over with QHBoxLayouts
    for(QList<QHBoxLayout *>::iterator i = listOfBoxLayout.begin(); i != listOfBoxLayout.end(); i++)
    {
        // Remove Item of layout
        ui->LayoutEdgeToSliders->removeItem(*i);

        // Delete item
        delete (*i);
    }

    // Clear list with QSliders
    listOfBoxLayout.clear();

    // Clear list of probabilities
    listOfProbabilities.clear();

    // Clear list of booleans
    listOfBooleans.clear();
}
