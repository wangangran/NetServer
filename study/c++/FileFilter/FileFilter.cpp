/*************************************************************
*	Copyright (c)2012, ����������Ϣ�������޹�˾
*	All rights reserved.
*
*	�ļ����ƣ�	CheckFileDeep.c
*	�ļ���ʶ��	
*	ժ    Ҫ��	�ļ���ȼ��ӿ�ʵ��
*
*	��ǰ�汾��	
*	������ڣ�	
*
*	��	  ע��	
*
*	�޸ļ�¼��	
*	�޸����ڣ�  
*	��    �ߣ�  
*	�޸����ݣ�  
*
***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include "FileFilter.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <string>

#define log_error_fmt
#define log_debug_fmt
#define log_info_fmt
#define log_warn_fmt

//extern log4cplus::Logger logs;

/***************************************************************
*  �ļ���ȼ��
*  ����1 ��ʾͨ��Ч�飬������ʾ��ͨ������ʧ��
****************************************************************/

int CheckFileHead(const char *az_filePathname, const void *a_head, size_t a_headLen)
{
	char lz_buf[64] = {0};
	FILE *l_fd;
	if ((l_fd = fopen(az_filePathname, "rb")) == NULL)
	{
		log_error_fmt("open %s failed!%s", az_filePathname, strerror(errno));
		return -1;
	}
	//	log_debug_fmt("az_filePathname=[%s],l_fd=[%p]", az_filePathname, l_fd);

	if (fread(lz_buf, 1, a_headLen, l_fd) != a_headLen)
	{
		fclose(l_fd);
		return -1;
	}
	fclose(l_fd);
	log_debug_fmt("-az_filePathname--%s---a_head-%X,-------lz_buf-%X", az_filePathname, a_head, lz_buf);
	if (memcmp(a_head, lz_buf, a_headLen))
		return 0;
	return 1;
}

int CheckBufferHead(const char *buffer, const void *a_head, size_t a_headLen)
{
	if (NULL == buffer || NULL == a_head)
		return -1;

	if (memcmp(a_head, buffer, a_headLen))
		return 0;

	return 1;
}

//JPEG (jpg)���ļ�ͷ��FFD8FF
int CheckJpgDeep(const char *az_filePathname)
{
	char lc_head[] = {0xFF, 0xD8, 0xFF};

	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckPngDeep(const char *az_filePathname)
{
	char lc_head[] = {0x89, 0x50, 0x4E, 0x47};

	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckRarDeep(const char *az_filePathname)
{
	char lc_head[] = {0x52, 0x61, 0x72, 0x21};

	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckZipDeep(const char *az_filePathname)
{
	char lc_head[] = {0x50, 0x4B, 0x03, 0x04, 0x14, 0x00, 0x00, 0x00, 0x08, 0x00};
	log_debug_fmt("------CheckZipDeep----%s----", az_filePathname);
	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckDocDeep(const char *az_filePathname)
{
	char lc_head[] = {0xD0, 0xCF, 0x11, 0xE0, 0xA1, 0xB1, 0x1A, 0xE1};
	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckDocxDeep(const char *az_filePathname)
{
	char lc_head1[] = {0x50, 0x4B, 0x03, 0x04, 0x14, 0x00, 0x06, 0x00, 0x08, 0x00};
	char lc_head2[] = {0x50, 0x4B, 0x03, 0x04, 0x0A, 0x00, 0x00, 0x00, //wps�µ�docx
					   0x00, 0x00, 0x87, 0x4E, 0xE2, 0x40, 0x00, 0x00};
	if (1==CheckFileHead(az_filePathname, lc_head1, sizeof(lc_head1)))
		return 1;
	log_debug_fmt("------CheckDocxDeep--------");
	return CheckFileHead(az_filePathname, lc_head2, sizeof(lc_head2));
}

int CheckDocxDeep1(const char *az_filePathname)
{
	char lc_head[] = {0x50, 0x4B, 0x03, 0x04, 0x14, 0x00, 0x06, 0x00};
	const char *lzp_flag = "[Content_Types].xml"; // 0x1e
	char lz_buf[64] = {0};
	FILE *l_fd;
	int l_read;

	if ((l_fd = fopen(az_filePathname, "rb")) == NULL)
	{
		log_error_fmt("open %s failed!%s", az_filePathname, strerror(errno));
		return 0;
	}

	l_read = fread(lz_buf, 1, sizeof(lz_buf), l_fd);

	if (l_read == 0)
	{
		fclose(l_fd);
		return 0;
	}

	if (l_read != sizeof(lz_buf))
	{
		fclose(l_fd);
		return 0;
	}
	fclose(l_fd);

	if (memcmp(lc_head, lz_buf, sizeof(lc_head)))
		return 0;

	if (memcmp(lzp_flag, lz_buf + 0x1e, strlen(lzp_flag)))
		return 0;

	return 1;
}

int CheckPptDeep(const char *az_filePathname)
{
	log_info_fmt("-----------az_filePathname %s", az_filePathname);
	char lc_head[] = {0xD0, 0xCF, 0x11, 0xE0, 0xA1, 0xB1, 0x1A, 0xE1};
	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckPptxDeep(const char *az_filePathname)
{
	log_info_fmt("-----------az_filePathname %s", az_filePathname);
	char lc_head1[] = {0x50, 0x4B, 0x03, 0x04, 0x14, 0x00, 0x06, 0x00};
	char lc_head2[] = {0x50, 0x4B, 0x03, 0x04, 0x0A, 0x00, 0x00, 0x00, // wps�µ�pptx
					   0x00, 0x00, 0x87, 0x4E, 0xE2, 0x40, 0x00, 0x00};
	if (1==CheckFileHead(az_filePathname, lc_head1, sizeof(lc_head1)))
		return 1;
	return CheckFileHead(az_filePathname, lc_head2, sizeof(lc_head2));
}

int CheckXlsDeep(const char *az_filePathname)
{

	char lc_head[] = {0xD0, 0xCF, 0x11, 0xE0, 0xA1, 0xB1, 0x1A, 0xE1};
	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckXlsxDeep(const char *az_filePathname)
{
	char lc_head1[] = {0x50, 0x4B, 0x03, 0x04, 0x14, 0x00, 0x06, 0x00};
	char lc_head2[] = {0x50, 0x4B, 0x03, 0x04, 0x0A, 0x00, 0x00, 0x00, //wps�µ�xlsx
					   0x00, 0x00, 0x87, 0x4E, 0xE2, 0x40, 0x00, 0x00};
	if (1==CheckFileHead(az_filePathname, lc_head1, sizeof(lc_head1)))
		return 1;
	return CheckFileHead(az_filePathname, lc_head2, sizeof(lc_head2));
}

int CheckMp2Deep(const char *az_filePathname)
{
	char lc_head[] = {0xFF, 0xFD};

	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckMp3Deep(const char *az_filePathname)
{
	char lc_head[] = {0x49, 0x44};
	char lz_buf[64] = {0};
	FILE *l_fd;

	if ((l_fd = fopen(az_filePathname, "rb")) == NULL)
	{
		log_error_fmt("open %s failed!%s", az_filePathname, strerror(errno));
		return 0;
	}

	if (fread(lz_buf, 1, sizeof(lc_head), l_fd) != sizeof(lc_head))
	{
		fclose(l_fd);
		return 0;
	}
	fclose(l_fd);

	if (!memcmp(lc_head, lz_buf, sizeof(lc_head)))
		return 1;

	//if((lz_buf[0] == 0xff) && (lz_buf[1] >= 0xfe))
	if ((lz_buf[0] == (char)0xff) && (lz_buf[1] >= (char)0xf0))
		return 1;

	return 0;
}

int CheckMpgDeep(const char *az_filePathname)
{
	char lc_head1[] = {0x00, 0x00, 0x01, 0xB3};
	char lc_head2[] = {0x00, 0x00, 0x01, 0xBA};

	if (1==CheckFileHead(az_filePathname, lc_head1, sizeof(lc_head1)))
		return 1;

	return CheckFileHead(az_filePathname, lc_head2, sizeof(lc_head2));
}

int CheckMpegDeep(const char *az_filePathname)
{
	char lc_head1[] = {0x00, 0x00, 0x01, 0xB3};
	char lc_head2[] = {0x00, 0x00, 0x01, 0xBA};

	if (1==CheckFileHead(az_filePathname, lc_head1, sizeof(lc_head1)))
		return 1;

	return CheckFileHead(az_filePathname, lc_head2, sizeof(lc_head2));
}

int CheckMovDeep(const char *az_filePathname)
{
	char lc_head1[] = {0x6d, 0x6f, 0x6f, 0x76};
	char lc_head2[] = {0x66, 0x74, 0x79, 0x70}; // 4�ֽں�ʼ
	char lz_buf[64] = {0};
	FILE *l_fd;

	if (1==CheckFileHead(az_filePathname, lc_head1, sizeof(lc_head1)))
		return 1;

	// head2
	if ((l_fd = fopen(az_filePathname, "rb")) == NULL)
	{
		log_error_fmt("open %s failed!%s", az_filePathname, strerror(errno));
		return 0;
	}

	if (fread(lz_buf, 1, sizeof(lc_head2) + 4, l_fd) != sizeof(lc_head2) + 4)
	{
		fclose(l_fd);
		return 0;
	}
	fclose(l_fd);

	if (!memcmp(lc_head2, lz_buf + 4, sizeof(lc_head2)))
		return 1;

	return 0;
}

int CheckVobDeep(const char *az_filePathname)
{
	char lc_head[] = {0x00, 0x00, 0x01, 0xBA};

	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckWavDeep(const char *az_filePathname)
{
	char lc_head1[] = {0x57, 0x41, 0x56, 0x45};
	char lc_head2[] = {0x52, 0x49, 0x46, 0x46};

	if (1==CheckFileHead(az_filePathname, lc_head1, sizeof(lc_head1)))
		return 1;

	return CheckFileHead(az_filePathname, lc_head2, sizeof(lc_head2));
}

int CheckWmaDeep(const char *az_filePathname)
{
	char lc_head[] = {0x30, 0x26, 0xb2, 0x75, 0x8E, 0x66, 0xCf, 0x11, 0xA6, 0xD9};

	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckWmvDeep(const char *az_filePathname)
{
	char lc_head[] = {0x30, 0x26, 0xb2, 0x75, 0x8E, 0x66, 0xCf, 0x11, 0xA6, 0xD9};

	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckAviDeep(const char *az_filePathname)
{
	char lc_head1[] = {0x41, 0x56, 0x49, 0x20};
	char lc_head2[] = {0x52, 0x49, 0x46, 0x46};

	if (1==CheckFileHead(az_filePathname, lc_head1, sizeof(lc_head1)))
		return 1;

	return CheckFileHead(az_filePathname, lc_head2, sizeof(lc_head2));
}

int CheceExeDeep(const char *az_filePathname)
{
	char lc_head[] = {0x4D, 0x5A, 0x90, 0x00, 0x03};
	char lc_head2[] = {0x4D, 0x5A, 0x50, 0x00, 0x02}; //���⴦����exe����������ǰ׺ͷ
	log_debug_fmt("-----------az_filePathname %s", az_filePathname);
	int ret1 = CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
	int ret2 = CheckFileHead(az_filePathname, lc_head2, sizeof(lc_head2));
	if (ret1 == 1 || ret2 == 1)
	{
		return 1;
	}
	return 0;
}

int CheckMxfDeep(const char *az_filePathname)
{
	char lc_head[] = {0x06, 0x0e, 0x2b, 0x34};

	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckWpsDeep(const char *az_filePathname)
{
	char lc_head[] = {0xD0, 0xCF, 0x11, 0xE0, 0xA1, 0xB1, 0x1A, 0xE1, 0x06, 0x09, 0x02};

	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckEtDeep(const char *az_filePathname)
{
	char lc_head[] = {0xD0, 0xCF, 0x11, 0xE0, 0xA1, 0xB1, 0x1A, 0xE1, 0x20, 0x08, 0x02};
	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckDpsDeep(const char *az_filePathname)
{
	char lc_head[] = {0xD0, 0xCF, 0x11, 0xE0, 0xA1, 0xB1, 0x1A, 0xE1, 0x10, 0x8D, 0x81, 0x64, 0x9B, 0x4F, 0xCF};
	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckS48Deep(const char *az_filePathname)
{
	char lc_head[] = {0xFF, 0xFD};
	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckBwfDeep(const char *az_filePathname)
{
	char lc_head[] = {0x52, 0x49, 0x46, 0x46};
	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckBz2Deep(const char *az_filePathname)
{
	char lc_head[] = {0x42, 0x5A, 0x68, 0x39, 0x31, 0x41, 0x59};
	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckgzDeep(const char *az_filePathname)
{
	char lc_head[] = {0x1F, 0x8B, 0x08, 0x00};
	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int Checkelf32Deep(const char *az_filePathname)
{
	char lc_head[] = {0x7f, 0x45, 0x4c, 0x46, 0x01};
	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int Checkelf64Deep(const char *az_filePathname)
{
	char lc_head[] = {0x7f, 0x45, 0x4c, 0x46, 0x02};
	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckbinDeep(const char *az_filePathname)
{
	char lc_head[] = {0x1F, 0x8B, 0x08, 0x00};
	return CheckFileHead(az_filePathname, lc_head, sizeof(lc_head));
}

int CheckFix(const char *az_filePathname, char *realFix)
{

	std::string suffix = "";
	int pos = -1;
	bool hasFix = false;

	std::string az_strPathname = std::string(az_filePathname);
	pos = az_strPathname.rfind('.');
	if (pos >= 0)
	{
		suffix = az_strPathname.substr(pos);
		hasFix = true;
	}

	struct stat statbuf;
	stat(az_filePathname, &statbuf);
	int size = statbuf.st_size;

	if (size < 2) //���ļ���С�ļ�ֻ��ע��ʱ�ĺ�׺
	{
		strcpy(realFix, suffix.c_str());
		return 1;
	}

	if (NULL == az_filePathname || NULL == realFix)
		return -1;

	if (1 == CheckS48Deep(az_filePathname))
	{
		strcpy(realFix, ".s48");
		return 1;
	}
	else if (1 == CheckBwfDeep(az_filePathname))
	{
		if( suffix.compare(".bwf") == 0)
		{
			strcpy(realFix, ".bwf");
		}
		else
		{
			strcpy(realFix, ".wav");
		}
		return 1;
	}
	else if (1 == CheckDocDeep(az_filePathname))
	{
		if ((suffix.compare(".doc") == 0) || (suffix.compare(".xls") == 0) ||
			(suffix.compare(".ppt") == 0) || (suffix.compare(".dps") == 0) ||
			(suffix.compare(".dpt") == 0) || (suffix.compare(".et") == 0)  ||
			(suffix.compare(".ett") == 0) || (suffix.compare(".wps") == 0) ||
			(suffix.compare(".wpt") == 0))  //����wps�ĸ��Ը�ʽ��office�Ĳ���x(doc xls ppt)��Ϊһ��
		{

			strcpy(realFix, suffix.c_str());
			log_info_fmt("-----------realFix %s", realFix);
			return 1;
		}
		strcpy(realFix, ".doc");
		return 1;
	}
	else if (1 == CheckDocxDeep(az_filePathname))
	{
		if ((suffix.compare(".docx") == 0) || (suffix.compare(".xlsx") == 0) ||
			(suffix.compare(".pptx") == 0))
		{

			strcpy(realFix, suffix.c_str());
			return 1;
		}
		strcpy(realFix, ".docx");
		return 1;
	}
	else if (1 == CheckRarDeep(az_filePathname))
	{
		strcpy(realFix, ".rar");
		return 1;
	}
	else if (1 == CheckZipDeep(az_filePathname))
	{
		if (suffix.compare(".zip") == 0)
		{
			strcpy(realFix, ".zip");
		}
		else
		{
			strcpy(realFix, ".apk");
		}
		return 1;
	}
	else if (1 == CheceExeDeep(az_filePathname))
	{
		if( suffix.compare(".exe") == 0)
		{
			strcpy(realFix, ".exe");
		}
		else
		{
			strcpy(realFix, ".dll");
		}
		return 1;
	}
	else if (1 == CheckWpsDeep(az_filePathname))
	{
		strcpy(realFix, ".wps");
		return 1;
	}
	else if (1 == CheckEtDeep(az_filePathname))
	{
		strcpy(realFix, ".et");
		return 1;
	}
	else if (1 == CheckDpsDeep(az_filePathname))
	{
		strcpy(realFix, ".dps");
		return 1;
	}
	else if (1 == CheckBz2Deep(az_filePathname))
	{
		strcpy(realFix, ".tar.bz2");
		return 1;
	}	
	else if (1 == CheckgzDeep(az_filePathname))
	{
		strcpy(realFix, ".tar.gz");
		return 1;
	}		
	else if(1 == Checkelf32Deep(az_filePathname))
	{
		strcpy(realFix, ".elf32");
		return 1;
	}
	else if(1 == Checkelf64Deep(az_filePathname))
	{
		strcpy(realFix, ".elf64");
		return 1;
	}
	else
	{
		if (hasFix)
		{
			strcpy(realFix, suffix.c_str());
			return 1;
		}
		else
		{
			log_warn_fmt("[%s],no fix", az_filePathname);
			return -1;
		}
		//	strcpy(realFix, ".txt");
		//	return 1;
	}

	return 0;
}

/*
int main()
{
	//CheckWpsDeep("D:\\Temp\\1.wps");
	//CheckEtDeep("D:\\Temp\\111.et");
	CheckDpsDeep("D:\\Temp\\da.dps");
	printf("y.mp3[%d]\n", CheckMp3Deep("./y.mp3"));
	printf("n.mp3[%d]\n\n", CheckMp3Deep("./n.mp3"));
	

	printf("y.doc[%d]\n", CheckDocDeep("./y.doc"));
	printf("n.doc[%d]\n\n", CheckDocDeep("./n.doc"));
	
	printf("y.s48[%d]\n", CheckS48Deep("./y.s48"));
	printf("n.s48[%d]\n\n", CheckS48Deep("./n.s48"));
	
	printf("y.wav[%d]\n", CheckWavDeep("./y.wav"));
	printf("n.wav[%d]\n\n", CheckWavDeep("./n.wav"));
	
	printf("y.avi[%d]\n", CheckAviDeep("./y.avi"));
	printf("n.avi[%d]\n\n", CheckAviDeep("./n.avi"));

}
*/
