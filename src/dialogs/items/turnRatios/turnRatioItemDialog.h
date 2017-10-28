#ifndef TURNRATIOINTERVALITEMDIALOG_H
#define TURNRATIOINTERVALITEMDIALOG_H

#include "abstractTurnRatioItemDialog.h"


namespace Ui
{
class turnRatioItemDialog;
}

class turnRatioItemDialog : public abstractTurnRatioItemDialog
{
    Q_OBJECT

public:

    explicit turnRatioItemDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~turnRatioItemDialog();


public slots:

    void resetParameters();

    void updateParameters();

    void openItemDialog(eNetEditorItem *item);


signals:

    void dialogClosed(eNetEditorItemDialogCloseType);


private slots:

    virtual void on_ButtonAccept_released();

    virtual void on_ButtonCancel_released();

    virtual void on_ButtonReset_released();

    void on_listOfFromEdge_itemClicked(QListWidgetItem *item);

    void on_listOfInterval_itemClicked(QListWidgetItem *item);

    void probabilityChanged(int value);

    void probabilityBlocked(bool value);

    void fillIntervalTable();

    void fillEdgeFromTable();

    void clearGraph();

    void plotEdgeGraph();

    void clearLayourSliders();

    void fillLayoutSliders();


private:

    // UI
    Ui::turnRatioItemDialog *ui;

    // Pointer to node
    nodeItem *n;

    // Pointer to temporal turnRatioIntervalItem
    turnRatioIntervalItem *turnRatioInterval;

    // Pointer to edge from
    edgeItem *edgeFrom;

    // List Of Graphs
    QList<QCPGraph *> listOfGraphs;

    // List with QLabels
    QList<QLabel *> listOfLabelEdgeTo;

    // List with QHBoxLayouts
    QList<QHBoxLayout *> listOfBoxLayout;

    // List with QSliders and their turnRatioItem
    QList< QPair< QSlider *, turnRatioItem *> > listOfSlider;

    // List with QCheckBoxs and their turnRatioItem
    QList< QPair< QCheckBox *, turnRatioItem *> > listOfCheckBox;

    // List with Probabilities of turnRatioItem
    QList<int> listOfProbabilities;

    // List with Booleans of turnRatioItem
    QList<bool> listOfBooleans;

};

#endif // TURNRATIOINTERVALITEMDIALOG_H
