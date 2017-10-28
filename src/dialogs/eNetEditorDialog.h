#ifndef ENETEDITORDIALOG_H
#define ENETEDITORDIALOG_H

#include "../main/eNetEditor.h"


class eNetEditorDialog : public QDialog , public eNetEditor
{
public:

    eNetEditorDialog(eNetEditorMainWindow *neweNetEditorMainW);

    ~eNetEditorDialog();

    eNetEditorMainWindow *geteNetEditorMainWindow();


private:

    eNetEditorMainWindow *eNetEditorMainW;
};

#endif // ENETEDITORDIALOG_H
