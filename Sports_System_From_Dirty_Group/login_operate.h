#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "login_page.h"
#include "main_page.h"


char Account[20];
char Password[20];
char Property;
FILE *fp = NULL;
char filebuf[30];

int read_from_file(FILE* pFile, char* account,char* password);

int Password_judge(char* account, char* password, char property)
{
	//判断账户属性
	switch (property)
	{
	case '1': {
		FILE *pFile = fopen("students_password.txt", "rb+");
		if (NULL == pFile)
		{
			printf_s("文件打开失败\n");
			return 0;
		}

		//操作文件指针，读取函数
		int s = read_from_file(pFile, account, password);
		return s;
		break;
	}

	case '2': {
		FILE *pFile = fopen("teachers_password.txt", "rb+");
		if (NULL == pFile)
		{
			printf_s("文件打开失败\n");
			return 0;
		}

		//操作文件指针，读取函数
		int s = read_from_file(pFile, account, password);
		return s;
		break;
	}

	case 'x': {
		FILE *pFile = fopen("admin_password.txt", "rb+");
		if (NULL == pFile)
		{
			printf_s("文件打开失败\n");
			return 0;
		}

		//操作文件指针，读取函数
		int s = read_from_file(pFile, account, password);
		return s;
		break;
	}

	default:
		break;
	}

}


void read_account_password_property()
{
	SetPos(25, 5);
	gets_s(Account);
	SetPos(25, 6);
	gets_s(Password);
	SetPos(25,7);
	Property = getchar();
	getchar();
}


void Login()
{	
	read_account_password_property();

	int s = Password_judge(Account, Password,Property);  //s用作密码是否正确的判断
	if (s == 0)
	{
		SetPos(20,8);
		printf_s("密码或账号错误，请重新输入!");
		read_account_password_property();
	}

	if (s == 1)
	{
		Show_Main_Page();
	}
}

//文件读取函数
int read_from_file(FILE* pFile, char* account, char* password) 
{
	while (fgets(filebuf, 30, pFile)) {
		int nCount = 0;
		char delims[] = "#";
		char *result = NULL;

		//字符串切割
		result = strtok(filebuf, delims);
		if (strcmp(account, result) == 0) {
			result = strtok(filebuf, delims);
			if (strcmp(account, result) == 0) {
				return 1;
			}
		}

	}
	return 0;
}