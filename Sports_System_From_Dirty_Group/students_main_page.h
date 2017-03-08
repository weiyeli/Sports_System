#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"
#include "competition_item.h"
#include <Windows.Applicationmodel.Activation.h>

//全局变量
char item_id[3];			//比赛代码
char stu_id[15];			//学生学号				
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
		Read_Item_From_File();
		Read_STU_From_File();
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
				printf_s("请输入学号");
				gets_s(stu_id);
				Sign_Up_Item(stu_id, item_id);
				printf_s("报名成功!");
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
				return;
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
				return;
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
				return;
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
	Free_Item_LinkedData(); 
}