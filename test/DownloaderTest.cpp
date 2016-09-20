//
// Created by giovanni on 16/09/16.
//
#include <gtest/gtest.h>
#include "../Downloader.h"
#include <cstdio>


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