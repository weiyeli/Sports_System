
#include <stdio.h>
#include "login_page.h"
#include <windows.h>

//一些奇怪的全局变量，好气啊



void Show_Tea_Menu()
{
	system("cls");
	printf_s("*************************运动会管理系统*************************\n");
	printf_s("*************************亲爱的老师您好*************************\n");
	printf_s("***********************本系统操作指令如下***********************\n");
	printf_s("1. 增加一个学生信息\n");
	printf_s("2. 查找指定的学生信息(姓名/学号)\n");
	printf_s("3. 修改指定学生的信息\n");
	printf_s("4. 保存学生信息到文件中\n");
	printf_s("5. 读取文件中的学生信息\n");
	printf_s("6. 删除指定学生的信息\n");
	printf_s("7. 恢复删除的学生信息\n");
	printf_s("8. 显示项目比赛情况\n");
	printf_s("9. 显示所有学生信息\n");
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
	while (flag) {
		setColor(10, 0);
		int iOrder = -1;
		Show_Tea_Menu();
		setColor(6, 0);
	}
}