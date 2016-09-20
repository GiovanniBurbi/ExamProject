//
// Created by giovanni on 15/09/16.
//

#include "Downloader.h"

bool Downloader::done= false;

void Downloader::subscribe(Observer *o) {
    observers.push_back(o);

}

void Downloader::unsubscribe(Observer *o) {
    observers.push_back(o);

}

void Downloader::notify() {
    for(auto i=observers.begin();i!=observers.end();i++)
        (*i)->update();

}

void Downloader::downloadFiles() {
    if(!done) {
        while(getNumFiles()>0) {
            notify();
            fclose(*files.begin());
            files.pop_front();
        }
        done = true;
    }
}

void Downloader::addFile(FILE* file) {
    if(file!= nullptr)
        files.push_back(file);
}

unsigned long int Downloader::getNumFiles() const {
    return files.size();
}

int Downloader::getTotalBytes() const {
    int sum=0;
    for(auto itr=files.begin();itr!=files.end();itr++){
        fseek(*itr,0,SEEK_END);
        sum+=ftell(*itr);
    }
    return sum;
}

int Downloader::getBytes() const {
    fseek(*files.begin(),0,SEEK_END);
    return ftell(*files.begin());
}
