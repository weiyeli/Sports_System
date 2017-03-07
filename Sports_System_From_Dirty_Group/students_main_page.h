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

void Return_To_Main_Menu() {
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
				
				printf_s("是否继续报名: y/n\n");
				scanf_s("%c",&bOrder);
				if (bOrder != 'y'){
					Return_To_Main_Menu();
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
				Show_Single_STU(Find_STU_By_ID_Or_Nmae(sOrder));
				printf_s("是否继续查询: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					Return_To_Main_Menu();
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
				Modify_Stu_Data(Find_STU_By_ID_Or_Nmae(sOrder));
				printf_s("是否继续修改: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					Return_To_Main_Menu();
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
			Return_To_Main_Menu();
			break;
		}
		
		//读取文件信息
		case 5: {
			printf_s("读取成功\n");
			getchar();
			Return_To_Main_Menu();
			break;
		}

		case 6: {
			while (flag)
			{
				printf_s("请输入要删除的学生学号或姓名: ");
				getchar();
				gets_s(sOrder);
				char a = 'q';
				Show_Single_STU(Find_STU_By_ID_Or_Nmae(sOrder));
				printf_s("\n确定要删除这条学生信息吗? y/n\n");
				scanf_s("%c", &a);
				if (a == 'y') {
					DeleteStuData(Find_STU_By_ID_Or_Nmae(sOrder));
					printf_s("删除成功!\n");

				}
				getchar();
				printf_s("是否继续删除: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					Return_To_Main_Menu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}
		
		case 9: {
			Show_Stu_Data();
			getchar();
			Return_To_Main_Menu();
			break;
		}

		case 10: {
			flag = 0;
			break;
		}

		default: {
			printf_s("指令有误!\n");
			getchar();
			Return_To_Main_Menu();
			break;
		}
			
		}
	}

	Save_Stu_To_File();
	Free_Stu_LinkedData();
}