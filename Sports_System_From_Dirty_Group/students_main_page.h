#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"
#include "competition_item.h"
#include "login_operate.h"
#include "college.h"
#include "Show_Item_Sign_Up_Situation.h"
#include "grade_table.h"
#include <Windows.Applicationmodel.Activation.h>

//全局变量
char item_id[10];		//比赛代码
char stu_ID[15];			//学生学号				
char bOrder = 'q';
char sOrder[20];
char account[20];
int flag = 1;

//得到当前的账号
void get_Cur_Acc(char* account)
{
	strcpy(account, account);
}

void Show_Menu_Stu()
{
	system("cls");
	printf_s("*************************运动会管理系统*************************\n");
	printf_s("***********************本系统操作指令如下***********************\n");
	printf_s("1. 报名项目\n");
	printf_s("2. 退选项目\n");
	printf_s("3. 查看报名情况\n");
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
				Show_Com_info();
				getchar();
				printf_s("请输入要报名的比赛代码: ");
				gets_s(item_id);
				printf_s("请输入学号: ");
				gets_s(stu_ID);

				////安全性判断
				//if (strcmp(stu_ID, account) != 0)
				//{
				//	printf_s("哥，这不是你的学号。。。\n");
				//	break;
				//}

				char a = 'q';
				printf_s("\n确定要报名%s吗? y/n\n", Find_Item_By_ID_Or_Nmae(item_id)->item_name);
				scanf_s("%c", &a);
				if (a == 'y') {
					Sign_Up_Item(item_id, stu_ID);
					printf_s("报名成功!\n");
				}
				getchar();
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
				printf_s("请输入要退选的项目代码: ");
				getchar();
				gets_s(item_id);
				printf_s("请输入你的学号: ");
				gets_s(stu_ID);
				char a = 'q';
				printf_s("\n确定要退选吗? y/n\n");
				scanf_s("%c", &a);
				if (a == 'y') {
					DeleteStuData(Find_Grade_Table(item_id, stu_ID));
					printf_s("退选成功!\n");

				}
				getchar();
				printf_s("是否继续操作: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					Return_To_Main_Menu();
					flag = 0;
				}	
			}
			flag = 1;
			break;
		}

		//查看比赛报名情况
		case 3: {
			while (flag)
			{
				getchar();
				printf_s("请输入要查询的项目代码: ");
				gets_s(item_id);
				Find_Item_From_Grade_Table(item_id);
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
}