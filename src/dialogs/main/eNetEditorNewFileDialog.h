#ifndef ENETEDITORNEWFILEDIALOG_H
#define ENETEDITORNEWFILEDIALOG_H

#include "../eNetEditorDialog.h"


namespace Ui
{
class eNetEditorNewFileDialog;
}

class eNetEditorNewFileDialog : public eNetEditorDialog
{
    Q_OBJECT

public:

    explicit eNetEditorNewFileDialog(eNetEditorMainWindow *eNetEditorMainW);

    ~eNetEditorNewFileDialog();

public slots:

    void openDialog(eNetEditorMainWindow *newMainWindow);

    void resetParameters();

    void updateParameters();


private slots:

    void on_ButtonAccept_released();

    void on_ButtonCancel_released();

    void on_ButtonReset_released();

    void on_ButtonSearchPath_released();

    void on_ButtonSearchMap_released();

    void on_TextProjectName_textChanged();

    void on_horizontalSlider_sliderMoved(int position);

    void on_QSpinBoxBeginHour_valueChanged(int arg1);

    void on_QSpinBoxBeginMinute_valueChanged(int arg1);

    void on_QSpinBoxBeginSecond_valueChanged(int arg1);

    void on_QSpinBoxEndHour_valueChanged(int arg1);

    void on_QSpinBoxEndMinute_valueChanged(int arg1);

    void on_QSpinBoxEndSecond_valueChanged(int arg1);


private:

    // GUI
    Ui::eNetEditorNewFileDialog *ui;

    // Pointer to netEditor
    eNetEditorMainWindow *mainWindow;

    // Project Name temporal
    QString tmpProjectName;

    // Route Path temporal
    QString tmpFilePath;

    // Route path map temporal
    QString tmpPathMap;

    // Scale temporal
    openStreetMapPixelMeter tmpScale;

    // Temporal map.
    QPixmap tmpMap;

    // pointer to create error messages
    QMessageBox *errorMessage;  /// Should be erased

    // Temporal Start of the simulation
    int tmpTimeStartHour;
    int tmpTimeStartMinute;
    int tmpTimeStartSecond;

    // Temporal Start of the simulation
    int tmpTimeEndHour;
    int tmpTimeEndMinute;
    int tmpTimeEndSecond;
};

#endif // ENETEDITORNEWFILEDIALOG_H
