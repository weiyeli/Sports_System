#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Student
{
	char ID[20]; //学号
	char Name[10];  //学生姓名
	int gender; //性别
	float Mark_Running;
	float Mark_Jumping;
	float Mark_shot;
	Student* pnext;  //指针
} STUNODE;

//声明链表的头和尾
STUNODE* g_pHead = NULL;
STUNODE* g_pEnd = NULL;


//添加学生信息
void AddStuMSG(char* arrStuID, char* arrStuName, int gender, float Mark_Running, float Mark_Jumping, float Mark_shot)
{
	//检验参数的合法性
	if (arrStuName == NULL || arrStuID == NULL || Mark_Jumping<0 || Mark_Running<0 || Mark_shot<0)
	{
		printf_s("学生信息有误");
		return;
	}

	//逻辑
	//创建一个节点
	STUNODE* pTemp = (STUNODE*)malloc(sizeof(STUNODE));
	//节点成员初始化
	strcpy(pTemp->ID, arrStuID);
	strcpy(pTemp->Name, arrStuName);
	pTemp->Mark_Jumping = Mark_Jumping;
	pTemp->Mark_Running = Mark_Running;
	pTemp->Mark_shot = Mark_shot;
	pTemp->pnext = NULL;

	//接在链表上
	if (g_pHead == NULL || g_pEnd == NULL)
	{
		g_pHead = pTemp;
		g_pEnd = pTemp;
	}
	else {
		g_pEnd->pnext = pTemp;	//链接
		g_pEnd = pTemp;  //移动
	}
}

void FreeLinkedData()
{
	STUNODE* pTemp = g_pHead;
	while (g_pHead != NULL)
	{
		//记录节点
		pTemp = g_pHead;

		//向后移动一位
		g_pHead = g_pHead->pnext;

		//释放链表
		free(pTemp);
	}
}

//显示学生信息
void ShowStuData()
{
	STUNODE* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		printf_s("学号        姓名       性别        跑步       跳远       铅球");
		printf_s("%s     %s",pTemp->ID, pTemp->Name);
		if (pTemp->gender == 1)
			printf_s("男");
		else printf_s("女");
		printf_s("%f     %f      %f", pTemp->Mark_Running, pTemp->Mark_Jumping, pTemp->Mark_shot);
		
		//往下走一步
		pTemp = pTemp->pnext;
	}
}