//
// Created by giovanni on 16/09/16.
//
#include <gtest/gtest.h>
#include "../Downloader.h"
#include "../GuiDownloader.h"




TEST(Downloader, TestaddFiles){
    Downloader dload;
    FILE* file1;
    file1=fopen("/home/giovanni/ClionProjects/Progetto/File1.txt","r");
    dload.addFile(file1);
    FILE* file2;
    file2=fopen("/home/giovanni/ClionProjects/Progetto/File1.txt","r");
    dload.addFile(file2);
    ASSERT_EQ(2, dload.getNumFiles());
}

TEST(Downloader, TestDownload){
    Downloader dload;
    FILE* file1;
    file1=fopen("/home/giovanni/ClionProjects/Progetto/File1.txt","r");
    dload.addFile(file1);
    FILE* file2;
    file2=fopen("/home/giovanni/ClionProjects/Progetto/File1.txt","r");
    dload.addFile(file2);
    dload.downloadFiles();
    ASSERT_EQ(0,dload.getNumFiles());

}

TEST(Downloader, TestGetByte){
    Downloader dload;
    FILE* file1;
    file1=fopen("/home/giovanni/ClionProjects/Progetto/File1.txt","r");
    dload.addFile(file1);
    FILE* file2;
    file2=fopen("/home/giovanni/ClionProjects/Progetto/File2.txt","r");
    dload.addFile(file2);
    ASSERT_EQ(194,dload.getTotalBytes());

}

TEST(Downloader, TestObserver){
    Downloader dload;
    Window *window = new Window(NULL, &dload);
    GuiDownloader gui(&dload, window);

    FILE *file1;
    file1 = fopen("/home/giovanni/ClionProjects/Progetto/File1.txt", "r");
    dload.addFile(file1);
    FILE *file2;
    file2 = fopen("/home/giovanni/ClionProjects/Progetto/File2.txt", "r");
    dload.addFile(file2);
    ASSERT_EQ(194,dload.getTotalBytes());

    dload.downloadSingleFile();

    ASSERT_EQ(135,window->getBytesValue());
    ASSERT_EQ(1,window->getFilesValue());

    dload.downloadSingleFile();

    ASSERT_EQ(194,window->getBytesValue());
    ASSERT_EQ(2,window->getFilesValue());

}