#include "gtest/gtest.h"
#include "../Downloader.h"
#include "../GuiDownloader.h"
#include "wx/wx.h"

class TestWindow : public Window
{
    FRIEND_TEST(GuiTest, ObserverTest);
    Downloader* downloader;

public:
    TestWindow(wxWindow *parent, Downloader * d,wxWindowID id = wxID_ANY, const wxString& title = wxT("Downloader"), const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxSize( 462,242 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL) : Window(parent, d, id, title, pos, size, style) {
        downloader=d;
    }
};


class TestApp : public wxApp
{
public:
    TestWindow *window;

    virtual bool OnInit()
    {
        Downloader dload;
        Window *testwindow = new TestWindow(NULL, &dload);
        GuiDownloader gui(&dload, window);
        testwindow->Show( true );
        return true;
    }
};

class GuiTest : public testing::Test
{
protected:
    TestApp *app;
    virtual void SetUp()
    {
        char appname[] = "wxUnitTest.exe";
        int argc = 1;
        char *argv[1] = {appname};
        app = new TestApp();
        wxApp::SetInstance(app);
        wxEntryStart(argc,argv);
        app->OnInit();
    }
    virtual void TearDown()
    {
        //wxTheApp->OnRun();
        app->OnExit();
        wxEntryCleanup();
    }
};
TEST_F(GuiTest, ObserverTest)
{
    Downloader dload;
    Window *window = new Window(NULL, &dload);
    GuiDownloader gui(&dload, window);

    FILE *file1;
    file1 = fopen("/home/giovanni/ClionProjects/Progetto/File1.txt", "r");
    dload.addFile(file1);
    FILE *file2;
    file2 = fopen("/home/giovanni/ClionProjects/Progetto/File2.txt", "r");
    dload.addFile(file2);
    window->setRange(dload.getNumFiles(), dload.getTotalBytes());

    dload.downloadSingleFile();

    ASSERT_EQ(135,window->getBytesValue());
    ASSERT_EQ(1,window->getFilesValue());

    dload.downloadSingleFile();

    ASSERT_EQ(194,window->getBytesValue());
    ASSERT_EQ(2,window->getFilesValue());


}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}