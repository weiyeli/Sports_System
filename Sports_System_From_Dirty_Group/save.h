#pragma once
#include <stdio.h>

void save() {
	FILE *fp;
	if ((fp = fopen("D:\VSProjects\Sports_System_From_Dirty_Group\Sports_System_From_Dirty_Group", "w")) == NULL) {
		printf_s("Can't open the file\n");
		return;
	}

	printf_s("\n±£¥Ê÷–...Saving the file......\n");
}