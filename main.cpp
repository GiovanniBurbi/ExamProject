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
    file1 = fopen("/home/giovanni/ClionProjects/Progetto/file.txt", "r");
    dload.addFile(file1);
    FILE *file2;
    file2 = fopen("/home/giovanni/ClionProjects/Progetto/file.txt", "r");
    dload.addFile(file2);
    FILE *file;
    file = fopen("/home/giovanni/ClionProjects/Progetto/file.txt", "r");
    dload.addFile(file);
    FILE *file3;
    file3 = fopen("/home/giovanni/ClionProjects/Progetto/file.txt", "r");
    dload.addFile(file3);
    FILE *file4;
    file4 = fopen("/home/giovanni/ClionProjects/Progetto/file.txt", "r");
    dload.addFile(file4);
    FILE *file5;
    file5 = fopen("/home/giovanni/ClionProjects/Progetto/file.txt", "r");
    dload.addFile(file5);
    FILE *file6;
    file6 = fopen("/home/giovanni/ClionProjects/Progetto/file.txt", "r");
    dload.addFile(file6);
    FILE *file7;
    file7 = fopen("/home/giovanni/ClionProjects/Progetto/file.txt", "r");
    dload.addFile(file7);
    FILE *file8;
    file8 = fopen("/home/giovanni/ClionProjects/Progetto/file.txt", "r");
    dload.addFile(file8);
    FILE *file9;
    file9 = fopen("/home/giovanni/ClionProjects/Progetto/file.txt", "r");
    dload.addFile(file9);
    FILE *file10;
    file10 = fopen("/home/giovanni/ClionProjects/Progetto/file.txt", "r");
    dload.addFile(file10);
    window->setRange(dload.getNumFiles(), dload.getTotalBytes());
//    dload.downloadSingleFile();
    window->Show(true);
    MainLoop();
    return true;
}

