#include "duaRouterToolDialog.h"
#include "ui_duaRouterToolDialog.h"

// Project
#include "../../project/eNetEditorProject.h"

// Database
#include "../../database/eNetEditorDatabase.h"

// duaRouter Tool
#include "../../tools/duaRouterTool.h"


duaRouterToolDialog::duaRouterToolDialog(eNetEditorMainWindow *neweNetEditorMainW) : eNetEditorToolDialog(neweNetEditorMainW), ui(new Ui::duaRouterToolDialog)
{
    // Set UI
    ui->setupUi(this);

    // Create tool
    duaRouterT = new duaRouterTool(getMessages(), geteNetEditorConfiguration(), this);
}

duaRouterToolDialog::~duaRouterToolDialog()
{
    // Delete UI
    delete ui;

    // Delete tool
    delete duaRouterT;
}

void duaRouterToolDialog::openDialog(eNetEditorProject *newProject)
{
    // If pointer to project isn't NULL
    if(newProject != NULL)
    {
        // Link project
        setProject(newProject);

        // Reset parameters
        resetParameters();

        // Update Parameters in all Textbox, Checkboxs, etc...
        updateParameters();

        // Open Dialog
        show();
    }
}

void duaRouterToolDialog::on_ButtonSearchAdditionalFiles_released()
{

}

void duaRouterToolDialog::on_ButtonSearchAlternativeFiles_released()
{

}

void duaRouterToolDialog::on_ButtonSearchFlowFiles_released()
{

}

void duaRouterToolDialog::on_ButtonSearchLaneWeightFiles_released()
{

}

void duaRouterToolDialog::on_ButtonSearchPhemlightPath_released()
{

}

void duaRouterToolDialog::on_ButtonSearchRouteFiles_released()
{

}

void duaRouterToolDialog::on_ButtonSearchSumoNetwork_released()
{

}

void duaRouterToolDialog::on_ButtonSearchTripFiles_released()
{

}

void duaRouterToolDialog::on_ButtonSearchWeightAttribute_released()
{

}

void duaRouterToolDialog::on_ButtonSearchWeightFiles_released()
{

}

void duaRouterToolDialog::on_TextAdditionalFiles_textChanged()
{

}

void duaRouterToolDialog::on_TextAlternativeFiles_textChanged()
{

}

void duaRouterToolDialog::on_TextFlowFiles_textChanged()
{

}

void duaRouterToolDialog::on_TextLaneWeightFiles_textChanged()
{

}

void duaRouterToolDialog::on_TextPhemlightPath_textChanged()
{

}

void duaRouterToolDialog::on_TextRouteFiles_textChanged()
{

}

void duaRouterToolDialog::on_TextSumoNetwork_textChanged()
{

}

void duaRouterToolDialog::on_TextTripFiles_textChanged()
{

}

void duaRouterToolDialog::on_TextWeightAttribute_textChanged()
{

}

void duaRouterToolDialog::on_TextWeightFiles_textChanged()
{

}

void duaRouterToolDialog::on_ButtonSearchOutputFIle_released()
{

}

void duaRouterToolDialog::on_ButtonSearchVTypeOutput_released()
{

}

void duaRouterToolDialog::on_TextOutputFile_textChanged()
{

}

void duaRouterToolDialog::on_TextVTypeOutput_textChanged()
{

}

void duaRouterToolDialog::on_TextArrivalLane_textChanged()
{

}

void duaRouterToolDialog::on_TextArrivalPos_textChanged()
{

}

void duaRouterToolDialog::on_TextArrivalSpeed_textChanged()
{

}

void duaRouterToolDialog::on_TextDepartLane_textChanged()
{

}

void duaRouterToolDialog::on_TextDepartPos_textChanged()
{

}

void duaRouterToolDialog::on_TextDepartSpeed_textChanged()
{

}

void duaRouterToolDialog::on_TextTimeBegin_textChanged()
{

}

void duaRouterToolDialog::on_TextTimeEnd_textChanged()
{

}

void duaRouterToolDialog::on_TextLogitBeta_textChanged()
{

}

void duaRouterToolDialog::on_TextLogitGanma_textChanged()
{

}

void duaRouterToolDialog::on_TextLogitTheta_textChanged()
{

}

void duaRouterToolDialog::on_TextMaxAlternatives_textChanged()
{

}

void duaRouterToolDialog::on_TextRouteChoiceMethod_textChanged()
{

}

void duaRouterToolDialog::on_TextRouteSteps_textChanged()
{

}

void duaRouterToolDialog::on_TextRoutingAlgorithm_textChanged()
{

}

void duaRouterToolDialog::on_TextRoutingThreads_textChanged()
{

}

void duaRouterToolDialog::on_TextWeightPeriod_textChanged()
{

}

void duaRouterToolDialog::on_TextSeed_textChanged()
{

}

void duaRouterToolDialog::on_ButtonAccept_released()
{

}

void duaRouterToolDialog::on_ButtonCancel_released()
{
    // Close dialog
    close();
}

void duaRouterToolDialog::on_ButtonReset_released()
{
    // Reset all parameters of tool
    resetParameters();

    // Update all widgets
    updateParameters();
}
