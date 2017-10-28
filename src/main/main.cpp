// Include eNetEditor application
#include "eNetEditor.h"


int main(int argc, char *argv[])
{
    // Create QApplication
    QApplication application(argc, argv);

    // Create eNetEditor Application
    eNetEditor eNetEditorApplication;

    // Execute eNetEditorApplication and return application code
    return eNetEditorApplication.execute(application);
}
