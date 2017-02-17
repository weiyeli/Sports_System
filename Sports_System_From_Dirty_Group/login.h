#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "display.h"

int Password_judge(char* account, char* password)
{
	FILE *fp;
	if ((fp = fopen("D:\\VSProjects\\Sports_System_From_Dirty_Group\\Sports_System_From_Dirty_Group\\password.txt", "r+")) == NULL) {
		perror("D:\\VSProjects\\Sports_System_From_Dirty_Group\\Sports_System_From_Dirty_Group\\password.txt");
		exit(1);
	}

	char Account[20];
	char Password[20];
	fscanf(fp,"%s%s",Account,Password );
	if (strcmp(account, Account) == 0 & strcmp(password, Password) == 0)
	{
		return 1;
	}
	else return 0;
}


void Login()
{	
	//切换到输入界面
	char Account[20];
	char Password[20];

	//scanf_s("%s", Account); //为什么错，不明觉厉
	gets_s(Account);
	//puts(Account);
	//getchar();
	SetPos(25, 6);
	gets_s(Password);
	//puts(Password);
	//scanf_s("%s",Password);

	int s = Password_judge(Account, Password);  //s用作密码是否正确的判断
	printf_s("%d",s);

}

