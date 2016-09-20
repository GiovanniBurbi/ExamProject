//
// Created by giovanni on 19/09/16.
//

#include "Window.h"


void Window::setRange(int f, int b) {
    gaugeFiles->SetRange(f);
    gaugeBytes->SetRange(b);
}

void Window::updateBar(int b) {
    gaugeFiles->SetValue(gaugeFiles->GetValue()+1);
    gaugeBytes->SetValue(gaugeBytes->GetValue()+b);
    Refresh();
}

Window::Window(wxWindow *parent,Downloader* d, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size,
               long style) : MainFrame(parent, id, title, pos, size, style) {
    downloader=d;
}

void Window::OnClickDownload(wxCommandEvent &event) {
    downloader->downloadFiles();
}





