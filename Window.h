//
// Created by giovanni on 19/09/16.
//

#ifndef PROGETTO_WINDOW_H
#define PROGETTO_WINDOW_H

#include "FrameProgetto.h"
#include "Downloader.h"

class Window : public MainFrame {

public:

    Window(wxWindow *parent,Downloader* d, wxWindowID id = wxID_ANY, const wxString& title = wxT("Downloader"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 462,242 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL);

    void setRange (int f, int b);
    void updateBar(int b);
    virtual void OnClickDownload(wxCommandEvent &event) override;

private:
    Downloader* downloader;
};


#endif //PROGETTO_WINDOW_H
