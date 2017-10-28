#ifndef DETECTORDISTRIBUTIONDIALOG_H
#define DETECTORDISTRIBUTIONDIALOG_H

#include "eNetEditorItemDialog.h"


namespace Ui
{
class distributionFunctionItemDialog;
}

class distributionFunctionItemDialog : public eNetEditorItemDialog
{
    Q_OBJECT

public:

    explicit distributionFunctionItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~distributionFunctionItemDialog();


public slots:

    void resetParameters();

    void updateParameters();

    void openItemDialog(eNetEditorItem *item);


signals:

    void dialogClosed(eNetEditorItemDialogCloseType);


private slots:

    void on_ButtonAccept_released();

    void on_ButtonCancel_released();

    void on_ButtonReset_released();

    void fillTable();

    void plotFunction();

    void plotPKWGraph();

    void plotLKWGraph();

    void plotIntervalGraph();

    void on_ButtonSearchDistributionFunction_released();

    void on_horizontalSlider_sliderMoved(int position);

    void on_TextPKWVelocity_textChanged();

    void on_TextLKWVelocity_textChanged();

    void on_TextTrafficCount_textChanged();

    void on_SpinBoxSampling_valueChanged(int arg1);


private:

    // UI
    Ui::distributionFunctionItemDialog *ui;

    // Pointer to distribution function
    distributionFunctionItem *df;

    // Graphs
    QCPGraph *PKW;
    QCPGraph *LKW;
    QCPGraph *Interval;

    // Temporal data
    QList< QVector<int> > tmpData;

    // Temporal trafficCount
    int tmpTrafficCount;

    // Temporal PKWVelocity
    qreal tmpPKWVelocity;

    // Temporal LKWVelocity
    qreal tmpLKWVelocity;

    // Temporal Procent of PKW
    qreal tmpProcentPKW;

    // Temporal Procent of LKW
    qreal tmpProcentLKW;

    // Temporal Sampling
    int tmpSampling;
};

#endif // DETECTORDISTRIBUTIONDIALOG_H
