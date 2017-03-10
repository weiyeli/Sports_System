
#include <stdio.h>
#include "login_page.h"
#include <windows.h>

//一些奇怪的全局变量，好气啊
//int flag = 1;


void Show_Tea_Menu()
{
	system("cls");
	printf_s("*************************运动会管理系统*************************\n");
	printf_s("*************************亲爱的于老师您好*************************\n");
	printf_s("***********************本系统操作指令如下***********************\n");
	printf_s("1. 报名裁判\n");
	printf_s("2. 录入比赛成绩\n");
	printf_s("3. 查看比赛结果\n");
	printf_s("4. 查看所有项目信息\n");
	printf_s("5. 待开发\n");
	printf_s("6. 待开发\n");
	printf_s("7. 待开发\n");
	printf_s("8. 待开发\n");
	printf_s("9. 待开发\n");
	printf_s("10. 退出系统\n");
	printf_s("*****************************************************************\n\n");
	printf_s("输入指令咯\n");
}

void ReturnToTeaMainMenu() {
	printf_s("是否返回主页面: y/n\n");
	//getchar();
	scanf_s("%c", &bOrder);
	if (bOrder == 'y')
		Show_Tea_Menu();
	else flag = 0;
}

void Show_Tea_Main_Page()
{
	/*while (flag) {
		setColor(10, 0);
		int iOrder = -1;
		setColor(6, 0);
		scanf_s("%d", &iOrder);

		switch (iOrder)
		{
		case 2: {


		}
		}
	}*/
}