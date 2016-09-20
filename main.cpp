#include "wx/wx.h"
#include "Downloader.h"
#include "GuiDownloader.h"


class Myapp : public wxApp {
public:

    virtual bool OnInit() override;
};

wxIMPLEMENT_APP(Myapp);

bool Myapp::OnInit() {

    Downloader dload;
    Window *window = new Window(NULL, &dload);
    GuiDownloader gui(&dload, window);

    FILE *file1;
    file1 = fopen("/home/giovanni/ClionProjects/Progetto/File1.txt", "r");
    dload.addFile(file1);
    FILE *file2;
    file2 = fopen("/home/giovanni/ClionProjects/Progetto/File2.txt", "r");
    dload.addFile(file2);
    FILE *file3;
    file3 = fopen("/home/giovanni/ClionProjects/Progetto/File3.txt", "r");
    dload.addFile(file3);
    FILE *file4;
    file4 = fopen("/home/giovanni/ClionProjects/Progetto/File4.txt", "r");
    dload.addFile(file4);
    window->setRange(dload.getNumFiles(), dload.getTotalBytes());
    window->Show(true);
    MainLoop();
    return true;
}

