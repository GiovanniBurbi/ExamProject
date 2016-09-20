//
// Created by giovanni on 15/09/16.
//

#ifndef PROGETTO_GUIDOWNLOADER_H
#define PROGETTO_GUIDOWNLOADER_H


#include "Observer.h"
#include "Downloader.h"
#include "Window.h"

class GuiDownloader : public Observer {

public:

    GuiDownloader(Downloader* s, Window* w) : subject(s), window(w) {
        subject->subscribe(this);
    }

    virtual ~GuiDownloader(){
        subject->unsubscribe(this);
    }

    virtual void update() override;

private:
    Downloader* subject;
    Window* window;
};


#endif //PROGETTO_GUIDOWNLOADER_H
