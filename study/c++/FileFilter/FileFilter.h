#ifndef __CHECK_FILE_DEEP__
#define __CHECK_FILE_DEEP__


int CheckJpgDeep(const char *az_filePathname);
int CheckPngDeep(const char *az_filePathname);
int CheckRarDeep(const char *az_filePathname);
int CheckZipDeep(const char *az_filePathname);
int CheckDocDeep(const char *az_filePathname);
int CheckDocxDeep(const char *az_filePathname);
int CheckPptDeep(const char *az_filePathname);
int CheckPptxDeep(const char *az_filePathname);
int CheckXlsDeep(const char *az_filePathname);
int CheckXlsxDeep(const char *az_filePathname);

int CheckMp2Deep(const char *az_filePathname);
int CheckMp3Deep(const char *az_filePathname);
int CheckMpgDeep(const char *az_filePathname);
int CheckMpegDeep(const char *az_filePathname);
int CheckMovDeep(const char *az_filePathname);
int CheckVobDeep(const char *az_filePathname);
int CheckWavDeep(const char *az_filePathname);
int CheckWmaDeep(const char *az_filePathname);
int CheckWmvDeep(const char *az_filePathname);
int CheckAviDeep(const char *az_filePathname);
int CheckMxfDeep(const char *az_filePathname);

int CheckWpsDeep(const char *az_filePathname);
int CheckEtDeep(const char *az_filePathname);
int CheckDpsDeep(const char *az_filePathname);
int CheceExeDeep(const char *az_filePathname);
int CheckBwfDeep(const char *az_filePathname);
int CheckS48Deep(const char *az_filePathname);

int Checkelf32Deep(const char *az_filePathname);
int Checkelf64Deep(const char *az_filePathname);

int CheckFix(const char *az_filePathname,char *realFix);


#endif     // __CHECK_FILE_DEEP__
