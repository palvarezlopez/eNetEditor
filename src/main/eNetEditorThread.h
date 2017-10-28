#ifndef ENETEDITORTHREAD_H
#define ENETEDITORTHREAD_H

#include "eNetEditor.h"


class eNetEditorThread : public QThread, public eNetEditor
{
public:

    eNetEditorThread(QObject *parent = 0);

private:
};

#endif // ENETEDITORTHREAD_H
