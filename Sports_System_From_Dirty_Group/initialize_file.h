#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Admin
{
	char Account[20];
	char Password[20];
};


void initial_Admin()
{
	FILE *fp;
	if ((fp = fopen("D:\\VSProjects\\Sports_System_From_Dirty_Group\\Sports_System_From_Dirty_Group\\password.txt", "r+")) == NULL) 
	{
		printf_s("Unable to open the file!\n");
		return;
	}
	else {
		Admin admin = {"pesw123","123456"};
		if (fwrite(&admin, sizeof(Admin), 1, fp) != 1)
			printf_s("ÎÄ¼þÐ´Èë´íÎó");
		fclose(fp);

	}
}