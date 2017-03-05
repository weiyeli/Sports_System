#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"
#include <Windows.Applicationmodel.Activation.h>

int college;  //学院
char ID[20]; //学号
char Name[10];  //学生姓名
int gender; //性别
char bOrder = 'q';
char sOrder[20];
int flag = 1;


void Show_Menu_Stu()
{
	system("cls");
	printf_s("*************************运动会管理系统*************************\n");
	printf_s("***********************本系统操作指令如下***********************\n");
	printf_s("1. 报名项目\n");
	printf_s("2. 退选项目\n");
	printf_s("3. 查看比赛安排\n");
	printf_s("4. 查看比赛结果\n");
	printf_s("5. 查看个人得分\n");
	printf_s("6. 查看学院得分\n");
	printf_s("10. 退出系统\n");
	printf_s("*****************************************************************\n\n");
	printf_s("输入指令咯\n");
}

void ReturnToMainMenu() {
	printf_s("是否返回主页面: y/n\n");
	//getchar();
	scanf_s("%c", &bOrder);
	if (bOrder == 'y')
		Show_Menu_Stu();
	else flag = 0;
}


void Show_Stu_Main_Page()
{
	while (flag) {
		setColor(10, 0);
		int iOrder = -1;
		Show_Menu_Stu();
		setColor(6, 0);
		scanf_s("%d", &iOrder);

		switch (iOrder)
		{
		case 1: {
			while (flag)
			{
				//添加学生信息
				printf_s("输入学院(工1医2法3): ");
				getchar();
				scanf_s("%d",&college);
				printf_s("输入学号: ");
				getchar();
				gets_s(ID);
				printf_s("输入姓名: ");
				gets_s(Name);
				printf_s("输入性别(男1/女0): ");
				scanf_s("%d", &gender);
				getchar();
				AddStuMSG(college,ID, Name, gender);
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