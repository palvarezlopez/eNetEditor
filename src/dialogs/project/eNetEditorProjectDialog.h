#ifndef ENETEDITORPROJECTDIALOG_H
#define ENETEDITORPROJECTDIALOG_H

#include "abstractProjectDialog.h"


namespace Ui
{
class eNetEditorProjectDialog;
}

class eNetEditorProjectDialog : public abstractProjectDialog
{
    Q_OBJECT

public:

    explicit eNetEditorProjectDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~eNetEditorProjectDialog();


public slots:

    void openDialog(eNetEditorProject *newProject);

    void resetParameters();

    void updateParameters();

    void afterTurnRatioIntervalDialogClosed(eNetEditorItemDialogCloseType closeCode);


private slots:

    void on_TextProjectName_textChanged();

    void on_TextPath_textChanged();

    void on_TextImagePath_textChanged();

    void on_TextDescription_textChanged();

    void on_ButtonReset_released();

    void on_ButtonAccept_released();

    void on_ButtonCancel_released();

    void on_QSpinBoxBeginHour_valueChanged(int arg1);

    void on_QSpinBoxBeginMinute_valueChanged(int arg1);

    void on_QSpinBoxBeginSecond_valueChanged(int arg1);

    void on_QSpinBoxEndHour_valueChanged(int arg1);

    void on_QSpinBoxEndMinute_valueChanged(int arg1);

    void on_QSpinBoxEndSecond_valueChanged(int arg1);

    void on_ButtonSearchPath_released();

    void on_ButtonSearchMap_released();

    void on_horizontalSlider_sliderMoved(int position);

    void on_ButtonAddInterval_released();

    void on_ListTurnRatioIntervals_itemDoubleClicked(QListWidgetItem *item);

    void fillListOfTurnRatios();


private:

    // UI
    Ui::eNetEditorProjectDialog *ui;

    // Pointer to turnRatioIntervalItem
    turnRatioIntervalItem *tri;

    // Temporal ProjectName
    QString tmpProjectName;

    // Temporal Path of the project
    QString tmpProjectPath;

    // Temporal Path of the image
    QString tmpImagePath;

    // Temporal Scale
    openStreetMapPixelMeter tmpScaleMap;

    // Temporal Start of the simulation
    int tmpTimeStartHour;
    int tmpTimeStartMinute;
    int tmpTimeStartSecond;

    // Temporal Start of the simulation
    int tmpTimeEndHour;
    int tmpTimeEndMinute;
    int tmpTimeEndSecond;
};

#endif // ENETEDITOReNetEditorProjectDialog_H
