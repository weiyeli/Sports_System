#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"
#include <Windows.Applicationmodel.Activation.h>

char ID[20]; //学号
char Name[10];  //学生姓名
int gender; //性别
float Mark_Running;
float Mark_Jumping;
float Mark_shot;
char bOrder = 'q';
char sOrder[20];
int flag = 1;


void Show_Menu()
{
	system("cls");
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
	printf_s("9. 显示所有学生信息\n");
	printf_s("10. 退出系统\n");
	printf_s("*****************************************************************\n\n");
	printf_s("输入指令咯\n");
}

void ReturnToMainMenu() {
	printf_s("是否返回主页面: y/n\n");
	//getchar();
	scanf_s("%c", &bOrder);
	if (bOrder == 'y')
		Show_Menu();
	else flag = 0;
}


void Show_Main_Page()
{
	while (flag) {
		setColor(10, 0);
		int iOrder = -1;
		Show_Menu();
		setColor(6, 0);
		scanf_s("%d", &iOrder);

		switch (iOrder)
		{
		case 1: {
			while (flag)
			{
				//添加学生信息
				printf_s("输入学号: ");
				getchar();
				gets_s(ID);
				printf_s("输入姓名: ");
				gets_s(Name);
				printf_s("输入性别(男1/女0): ");
				scanf_s("%d", &gender);
				printf_s("输入100米成绩(单位: 秒),未参加则输入零: ");
				scanf_s("%f", &Mark_Running);
				printf_s("输入跳远成绩(单位: 米),未参加则输入零: ");
				scanf_s("%f", &Mark_Jumping);
				printf_s("输入铅球成绩(单位: 米)，未参加则输入零: ");
				scanf_s("%f", &Mark_shot);
				getchar();
				AddStuMSG(ID, Name, gender, Mark_Running, Mark_Jumping, Mark_shot);
				printf_s("是否继续输入: y/n\n");
				scanf_s("%c",&bOrder);
				if (bOrder != 'y'){
					ReturnToMainMenu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}

		case 2:
		{
			while (flag)
			{
				printf_s("请输入学生的学号或者姓名: \n");
				getchar();
				gets_s(sOrder);
				showSingleSTU(FindSTUByIDOrNmae(sOrder));
				printf_s("是否继续查询: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					ReturnToMainMenu();
					flag = 0;
				}	
			}
			flag = 1;
			break;
		}


		case 3: {
			while (flag)
			{
				printf_s("请输入要修改信息的学生学号或姓名: ");
				getchar();
				gets_s(sOrder);
				ModifyStuData(FindSTUByIDOrNmae(sOrder));
				printf_s("是否继续修改: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					ReturnToMainMenu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}

		//保存学生信息
		case 4: {
			printf_s("保存成功\n");
			getchar();
			ReturnToMainMenu();
			break;
		}
		
		//读取文件信息
		case 5: {
			printf_s("读取成功\n");
			getchar();
			ReturnToMainMenu();
			break;
		}

		case 6: {
			while (flag)
			{
				printf_s("请输入要删除的学生学号或姓名: ");
				getchar();
				gets_s(sOrder);
				char a = 'q';
				showSingleSTU(FindSTUByIDOrNmae(sOrder));
				printf_s("\n确定要删除这条学生信息吗? y/n\n");
				scanf_s("%c", &a);
				if (a == 'y') {
					DeleteStuData(FindSTUByIDOrNmae(sOrder));
					printf_s("删除成功!\n");

				}
				getchar();
				printf_s("是否继续删除: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					ReturnToMainMenu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}
		
		case 9: {
			ShowStuData();
			getchar();
			ReturnToMainMenu();
			break;
		}

		case 10: {
			flag = 0;
			break;
		}

		default: {
			printf_s("指令有误!\n");
			getchar();
			ReturnToMainMenu();
			break;
		}
			
		}
	}

	SaveStuToFile();
	FreeLinkedData();
}