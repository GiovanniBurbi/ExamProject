//
// Created by giovanni on 15/09/16.
//

#ifndef PROGETTO_DOWNLOADER_H
#define PROGETTO_DOWNLOADER_H

#include <list>
#include <deque>
#include "Subject.h"
#include "cstdio"


class Downloader : public Subject {

public:

    virtual void subscribe(Observer *o) override;
    virtual void unsubscribe(Observer *o) override;
    virtual void notify() override;

    void downloadFiles();
    void addFile(FILE* file);
    unsigned long int getNumFiles() const;
    int getTotalBytes() const;
    int getBytes() const;


private:
    std::list<Observer*> observers;
    std::deque<FILE*> files;
    static bool done;
};


#endif //PROGETTO_DOWNLOADER_H
