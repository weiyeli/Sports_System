#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "competition_item.h"
#include "students.h"


typedef struct grade_table
{
	char stu_id[15];														//学生学号
	char item_id[10];													//项目编号
	int  complete;														//完成情况
	float  grade;															//学生成绩
	int rank;																//学生名次
	grade_table* pNext = NULL;									//下一张成绩单
}GRADENODE;

//声明链表的头和尾
GRADENODE* t_pHead = NULL;
GRADENODE* t_pEnd = NULL;

//添加一张成绩单
void Add_Grade_Table(char* item_id, char* stu_id) {
	//申请一个项目
	GRADENODE* pNode = (GRADENODE*)malloc(sizeof(GRADENODE));

	//成绩单初始化
	strcpy(pNode->item_id, item_id);
	strcpy(pNode->stu_id, stu_id);
	pNode->grade = 0;
	pNode->rank = 0;
	pNode->complete = 0;
	pNode->pNext = NULL;

	//如果为空，头和尾指针都指向首节点
	if (NULL == t_pHead || NULL == t_pEnd)
	{
		t_pHead = pNode;
		t_pEnd = pNode;
		pNode->pNext = NULL;
		return;
	}

	GRADENODE* pTemp = t_pHead;		//用来遍历每一个节点
	GRADENODE* tTemp = NULL;			//标记前置节点


	//如果链表不为空,按项目代码从小到大插入节点
	while (atoi(pNode->item_id) <= atoi(item_id))
	{
		//如果两个学号和项目代码相等，直接退出
		if (strcmp(pTemp->item_id,pNode->item_id)==0 && strcmp(pTemp->stu_id, pNode->stu_id)==0)
		{
			printf_s("error: 已存在该成绩单!\n");
			return;
		}

		tTemp = pTemp;
		pTemp = pTemp->pNext;

		if (pTemp == NULL)
			break;
	}

	//刚好插在头部
	if (pTemp == t_pHead)
	{
		pNode->pNext = pTemp;
		t_pHead = pNode;
		pTemp = NULL;
		return;
	}
	//插在尾部
	else if (pTemp == NULL) {
		tTemp->pNext = pNode;
		t_pEnd = pNode;
		pNode->pNext = NULL;
		return;
	}

	//插在中间
	else {
		tTemp->pNext = pNode;
		pNode->pNext = pTemp;
	}

	//要报名的项目
	ITEMNODE* i_pTemp = Find_Item_By_ID_Or_Nmae(item_id);
	i_pTemp->item_number_of_students++;
	
	//报名的学生
	STUNODE*  s_pTemp = Find_STU_By_ID_Or_Nmae(stu_id);
	s_pTemp->item_count++;
}

