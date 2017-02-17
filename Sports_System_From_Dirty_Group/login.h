#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "display.h"
#include "main_page.h"

int Password_judge(char* account, char* password)
{
	/*FILE *fp;
	if ((fp = fopen("D:\\VSProjects\\Sports_System_From_Dirty_Group\\Sports_System_From_Dirty_Group\\password.txt", "r+")) == NULL) {
		perror("D:\\VSProjects\\Sports_System_From_Dirty_Group\\Sports_System_From_Dirty_Group\\password.txt");
		exit(1);
	}*/

	char* Account = "pesw123";
	char* Password = "123456";
	//fscanf(fp,"%s%s",Account,Password );
	if (strcmp(account, Account) == 0 & strcmp(password, Password) == 0)
	{
		return 1;
	}
	else return 0;
}

char Account[20];
char Password[20];

void read_account_password()
{
	SetPos(25, 5);
	gets_s(Account);
	SetPos(25, 6);
	gets_s(Password);
}


void Login()
{	
	read_account_password();

	int s = Password_judge(Account, Password);  //s用作密码是否正确的判断
	if (s == 0)
	{
		SetPos(20,7);
		printf_s("密码或账号错误，请重新输入!");
		read_account_password();
	}

	if (s == 1)
	{
		Show_Main_Page();
	}
}

