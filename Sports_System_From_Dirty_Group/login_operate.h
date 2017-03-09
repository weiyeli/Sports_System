#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "login_page.h"
#include "students_main_page.h"
#include "teachers_main_page.h"
#include "addmin_main_page.h"


//��ֵ�ȫ�ֱ���
char Account[20];
char Password[20];
char Property;
FILE *fp = NULL;
char filebuf[30];
char user_info;


int read_from_file(FILE* pFile, char* account,char* password);

int Password_judge(char* account, char* password, char property)
{
	user_info = property;
	//�ж��˻�����
	switch (property)
	{
	case '1': {
		FILE *pFile = fopen("students_password.txt", "rb+");
		if (NULL == pFile)
		{
			printf_s("�ļ���ʧ��\n");
			return 0;
		}

		//�����ļ�ָ�룬��ȡ����
		int s = read_from_file(pFile, account, password);
		return s;
		break;
	}

	case '2': {
		FILE *pFile = fopen("teachers_password.txt", "rb+");
		if (NULL == pFile)
		{
			printf_s("�ļ���ʧ��\n");
			return 0;
		}

		//�����ļ�ָ�룬��ȡ����
		int s = read_from_file(pFile, account, password);
		return s;
		break;
	}

	case 'x': {
		FILE *pFile = fopen("admin_password.txt", "rb+");
		if (NULL == pFile)
		{
			printf_s("�ļ���ʧ��\n");
			return 0;
		}

		//�����ļ�ָ�룬��ȡ����
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
	get_Cur_Acc(Account);
	SetPos(25, 6);
	gets_s(Password);
	SetPos(50,7);
	Property = getchar();
	getchar();
}


void Login()
{	
	read_account_password_property();

	int s = Password_judge(Account, Password,Property);  //s���������Ƿ���ȷ���ж�
	if (s == 0)
	{
		SetPos(20,8);
		printf_s("������˺Ŵ�������������!");
		read_account_password_property();
	}

	if (s == 1)
	{
		if (user_info == '1')
			Show_Stu_Main_Page();
		if (user_info == '2')
			Show_Tea_Main_Page();
		if (user_info == 'x')
			Show_Admin_Main_Page();
	}
}

//�ļ���ȡ����
int read_from_file(FILE* pFile, char* account, char* password) 
{
	while (fgets(filebuf, 30, pFile)) {
		int nCount = 0;
		char delims[] = "#";
		char *result = NULL;

		//�ַ����и�
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