#include <iostream>
#include <gtest/gtest.h>
#include "FileFilter.h"

TEST(FileFilter, FileZip) {
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.et"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.png"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckZipDeep("file/zip-其他/测试文件.zip"));
}

TEST(FileFilter, FileBwf) {
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.et"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.png"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckBwfDeep("file/bwf-其他/测试文件.zip"));
}

TEST(FileFilter, FileDoc) {
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.et"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.png"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckDocDeep("file/doc-其他/测试文件.zip"));
}

TEST(FileFilter, FileDocx) {
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.et"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.png"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckDocxDeep("file/docx-其他/测试文件.zip"));
}

TEST(FileFilter, FileDps) {
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.et"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.png"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckDpsDeep("file/dps-其他/测试文件.zip"));
}
TEST(FileFilter, FileEt) {
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.et"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.png"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckEtDeep("file/et-其他/测试文件.zip"));
}

TEST(FileFilter, FileExe) {
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.apk"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.bin"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.doc"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.docx"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.dps"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.et"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.exe"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.png"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.rar"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.s48"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.txt"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.wps"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.xls"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheceExeDeep("file/exe-其他/测试文件.zip"));
}
/*
TEST(FileFilter, FilePdf) {
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.et"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.png"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckZipDeep("file/pdf-其他/测试文件.zip"));
}
*/
TEST(FileFilter, FilePptx) {
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.et"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.png"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckPptxDeep("file/pptx-其他/测试文件.zip"));
}

TEST(FileFilter, FilePpt) {
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.et"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.png"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckPptDeep("file/ppt-其他/测试文件.zip"));
}

TEST(FileFilter, FileRar) {
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.et"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.png"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckRarDeep("file/rar-其他/测试文件.zip"));
}

TEST(FileFilter, FileS48) {
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.et"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.png"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckS48Deep("file/s48-其他/测试文件.zip"));
}
/*
TEST(FileFilter, FileTxt) {
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.et"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.png"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckZipDeep("file/txt-其他/测试文件.zip"));
}
*/
TEST(FileFilter, FileWps) {
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.et"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.png"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckWpsDeep("file/wps-其他/测试文件.zip"));
}

TEST(FileFilter, FileXls) {
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.et"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.png"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckXlsDeep("file/xls-其他/测试文件.zip"));
}

TEST(FileFilter, FileXlsx) {
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.et"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.png"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckXlsxDeep("file/xlsx-其他/测试文件.zip"));
}

TEST(FileFilter, FilePng) {
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.et"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.png"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckPngDeep("file/png-其他/测试文件.zip"));
}

TEST(FileFilter, FileJpg) {
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.et"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.png"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckJpgDeep("file/jpg-其他/测试文件.zip"));
}
/*
TEST(FileFilter, FileBin) {
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.apk"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.bin"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.bwf"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.doc"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.docx"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.dps"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.elf32"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.elf64"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.et"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.exe"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.jpg"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.pdf"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.png"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.ppt"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.pptx"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.rar"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.s48"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.slf32"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.txt"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.wps"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.xls"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.xlsx"));
    EXPECT_EQ(1, CheckZipDeep("file/bin-其他/测试文件.zip"));
}
*/
TEST(FileFilter, FileElf32) {
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.apk"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.bin"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.bwf"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.doc"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.docx"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.dps"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.elf32"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.elf64"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.et"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.exe"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.jpg"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.pdf"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.png"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.ppt"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.pptx"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.rar"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.s48"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.slf32"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.txt"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.wps"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.xls"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.xlsx"));
    EXPECT_EQ(1, Checkelf32Deep("file/elf32-其他/测试文件.zip"));
}

TEST(FileFilter, FileElf64) {
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.apk"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.bin"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.bwf"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.doc"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.docx"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.dps"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.elf32"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.elf64"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.et"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.exe"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.jpg"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.pdf"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.png"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.ppt"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.pptx"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.rar"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.s48"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.slf32"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.txt"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.wps"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.xls"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.xlsx"));
    EXPECT_EQ(1, Checkelf64Deep("file/elf64-其他/测试文件.zip"));
}

GTEST_API_ int main(int argc, char **argv) {
    std::cout << "Running main() from gtest_main.cc\n";
    
    testing::InitGoogleTest(&argc, argv);                           // 解析命令行中的GoogleTest参数，它允许用户通过多样的命令行参数来控制测试程序的行为（即定制命令行参数的行为）
    return RUN_ALL_TESTS();                                         // 将会搜索不同的Test Case和不同的源文件中所有已经存在测试案例，然后运行它们，所有Test都成功时返回1，否则返回0。
}