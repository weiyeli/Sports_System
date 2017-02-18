#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "logic.h"
#include <Windows.Applicationmodel.Activation.h>

char ID[20]; //学号
char Name[10];  //学生姓名
int gender; //性别
float Mark_Running;
float Mark_Jumping;
float Mark_shot;


void Show_Main_Page()
{
	system("cls");

	int iOrder = -1;
	printf_s("*************************运动会管理系统*************************\n");
	printf_s("***********************本系统操作指令如下***********************\n");
	printf_s("1. 增加一个学生信息\n");
	printf_s("2. 查找指定的学生信息(姓名/学号)\n");
	printf_s("3. 修改指定学生的信息\n");
	printf_s("4. 保存学生信息到文件中\n");
	printf_s("5. 读取文件中的学生信息\n");
	printf_s("6. 删除指定学生的信息\n");
	printf_s("7. 恢复删除的学生信息\n");
	printf_s("8. 显示项目比赛情况\n");
	printf_s("9. 显示所有学生成绩\n");
	printf_s("10. 退出系统\n");
	printf_s("*****************************************************************\n\n");

	setColor(6, 0);
	printf_s("输入指令咯\n");
	scanf_s("%d",&iOrder);

	switch (iOrder)
	{
	case 1: 
		//添加学生信息
		printf_s("输入学号: ");
		getchar();
		gets_s(ID);
		printf_s("输入姓名: ");
		gets_s(Name);
		printf_s("输入性别(男1/女0): ");
		scanf_s("%d",&gender);
		printf_s("输入跑步成绩,未参加则输入零: ");
		scanf_s("%f",&Mark_Running);
		printf_s("输入跳远成绩,未参加则输入零: ");
		scanf_s("%f", &Mark_Jumping);
		printf_s("输入铅球成绩，未参加则输入零: ");
		scanf_s("%f", &Mark_shot);

		AddStuMSG(ID,Name,gender,Mark_Running, Mark_Jumping, Mark_shot);

		break;
	default:
		printf_s("指令有误!\n");
		break;
	}
}