//
// Created by giovanni on 15/09/16.
//

#include "GuiDownloader.h"

void GuiDownloader::update() {

    window->updateBar(subject->getBytes());
}