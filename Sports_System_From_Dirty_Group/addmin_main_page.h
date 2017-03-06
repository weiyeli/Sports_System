#pragma once
#include <stdio.h>
#include <windows.h>
#include "competition_item.h"


//全局变量
char id[3];							//项目代码
char item_name[10];		//项目名称
int item_nature;			//项目性质,1代表田赛,2代表径赛
char item_time[10];			    //比赛时间
char item_location[10];			//比赛地点

void Show_Admin_Menu()
{
	system("cls");
	printf_s("*************************运动会管理系统*************************\n");
	printf_s("***********************欢迎你尊贵的管理员***********************\n");
	printf_s("***********************本系统操作指令如下***********************\n");
	printf_s("1. 增加一个运动员信息\n");
	printf_s("2. 查找指定的学生信息(姓名/学号)\n");
	printf_s("3. 修改指定学生的信息\n");
	printf_s("4. 增加比赛项目\n");
	printf_s("5. 增加裁判\n");
	printf_s("6. 控制参赛\n");
	printf_s("7. 查看学院得分\n");
	printf_s("8. 显示项目比赛情况\n");
	printf_s("9. 显示所有学生信息\n");
	printf_s("10. 退出系统\n");
	printf_s("*****************************************************************\n\n");
	printf_s("输入指令咯\n");
}

void Return_To_Admin_Main_Menu() {
	printf_s("是否返回主页面: y/n\n");
	//getchar();
	scanf_s("%c", &bOrder);
	if (bOrder == 'y')
		Show_Admin_Menu();
	else flag = 0;
}


void Show_Admin_Main_Page()
{
	while (flag) {
		setColor(10, 0);
		int iOrder = -1;
		Show_Admin_Menu();
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
				scanf_s("%d", &college);
				printf_s("输入学号: ");
				getchar();
				gets_s(ID);
				printf_s("输入姓名: ");
				gets_s(Name);
				printf_s("输入性别(男1/女0): ");
				scanf_s("%d", &gender);
				getchar();
				Add_Stu_MSG(college, ID, Name, gender);
				printf_s("是否继续输入: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					Return_To_Admin_Main_Menu();
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
				//showSingleSTU(FindSTUByIDOrNmae(sOrder));
				printf_s("是否继续查询: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					//ReturnToMainMenu();
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
				//ModifyStuData(FindSTUByIDOrNmae(sOrder));
				printf_s("是否继续修改: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					//ReturnToMainMenu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}

				//保存学生信息
		case 4: {
			getchar();
			printf_s("输入比赛项目代码: ");
			scanf_s("%d", &id);
			printf_s("输入比赛名称: ");
			getchar();
			gets_s(item_name);
			printf_s("输入比赛性质(1田赛2径赛): ");
			scanf_s("%d", &item_nature);
			getchar();
			printf_s("输入比赛时间: ");
			gets_s(item_time);
			//puts(item_time);
			printf_s("输入比赛地点: ");
			gets_s(item_location);
			//puts(item_location); 
			register_item(id, item_name, item_nature, item_time, item_location);
			printf_s("是否继续输入: y/n\n");
			scanf_s("%c", &bOrder);
			if (bOrder != 'y') {
				Return_To_Admin_Main_Menu();
				flag = 0;
			}
		}

				//读取文件信息
		case 5: {
			
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
					Return_To_Admin_Main_Menu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}

		case 9: {
			
		}

		case 10: {
			flag = 0;
			break;
		}

		default: {
			printf_s("指令有误!\n");
			getchar();
			Return_To_Admin_Main_Menu();
			break;
		}

		}
	}

	//SaveStuToFile();
	Free_Admin_LinkedData();
}