#pragma once
#include "competition_item.h"
#include "students.h"
#include "grade_table.h"

////查看项目报名情况
//void Show_Item_Sign_UP_Situation(char* item_data)
//{
//	//要报名的项目
//	ITEMNODE* i_pTemp = Find_Item_By_ID_Or_Nmae(item_data);
//	char* stubuf;
//
//	system("cls");
//	setColor(12, 0);
//
//}

//从成绩表中查询项目报名情况
void Find_Item_From_Grade_Table(char* DATA)
{
	//检测参数的合法性
	if (NULL == DATA)
	{
		//printf_s("输入错误!\n");
		return;
	}

	//判断链表是否为空
	if (NULL == t_pHead || NULL == t_pEnd)
	{
		//printf_s("无此节点!\n");
		return;
	}

	system("cls");
	setColor(12, 0);
	printf_s("\t报名项目: %s\t\t报名人数: %d\n\n", Find_Item_By_ID_Or_Nmae(DATA)->item_name, Find_Item_By_ID_Or_Nmae(DATA)->item_number_of_students);
	printf_s("编号\t\t学院\t\t学号\t\t姓名\n");
	//遍历链表
	GRADENODE* pTemp = t_pHead;
	while (pTemp)
	{
		int i = 0;
		//找到了该项目的成绩单
		if (strcmp(DATA, pTemp->item_id) == 0)
		{
			printf_s("%d\t\t", i);
			if (Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->college == 1)
				printf_s("工学院\t\t");
			else if (Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->college == 2)
				printf_s("医学院\t\t");
			else if (Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->college == 3)
				printf_s("法学院\t\t");

			printf_s("%10s\t\t%s\t\t\n", Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->ID, Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->Name);
		}
		pTemp = pTemp->pNext;
	}

}
