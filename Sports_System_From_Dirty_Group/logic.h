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
	if (NULL == arrStuName|| NULL == arrStuID || Mark_Jumping<0 || Mark_Running<0 || Mark_shot<0)
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

	//接在链表尾部上
	if (NULL == g_pHead || NULL == g_pEnd)
	{
		g_pHead = pTemp;
		g_pEnd = pTemp;
	}
	else {
		g_pEnd->pnext = pTemp;	//链接
		g_pEnd = pTemp;  //移动
	}

	/*接在链表头部上
	if (g_pHead == NULL || g_pEnd == NULL)
	{
		g_pHead = pTemp;
		g_pEnd = pTemp;
	}
	else{
		pTemp->pnext = g_pHead;
		g_pHead = pTemp;
	}
	*/
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

//显示所有学生信息
void ShowStuData()
{
	setColor(10, 0);
	STUNODE* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		system("cls");
		printf_s("  学号\t\t姓名\t\t性别\t\t跑步\t\t跳远 \t\t铅球\n");
		printf_s("%10s\t%4s\t",pTemp->ID, pTemp->Name);
		char* sOrder_Male = "男";
		char* sOrder_Female = "女";
		if (pTemp->gender == 1)
			printf_s("%8s\t",sOrder_Male);
		else printf_s("%8s\t",sOrder_Female);
		printf_s("%8.2f\t%8.2f\t%8.2f\n", pTemp->Mark_Running, pTemp->Mark_Jumping, pTemp->Mark_shot);
		
		//往下走一步
		pTemp = pTemp->pnext;
	}
}

//显示指定学生信息
void showSingleSTU(STUNODE* pTemp)
{
	if (NULL == pTemp)
	{
		printf_s("查无此人!\n");
		return;
	}

	system("cls");
	printf_s("  学号\t\t姓名\t\t性别\t\t跑步\t\t跳远 \t\t铅球\n");
	printf_s("%10s\t%4s\t", pTemp->ID, pTemp->Name);
	char* sOrder_Male = "男";
	char* sOrder_Female = "女";
	if (pTemp->gender == 1)
		printf_s("%8s\t", sOrder_Male);
	else printf_s("%8s\t", sOrder_Female);
	printf_s("%8.2f\t%8.2f\t%8.2f\n", pTemp->Mark_Running, pTemp->Mark_Jumping, pTemp->Mark_shot);
}



//查找指定的学生
STUNODE* FindSTUByIDOrNmae(char* DATA)
{
	//检测参数的合法性
	if (NULL == DATA)
	{
		printf_s("学号输入错误!\n");
		return NULL;
	}

	//判断链表是否为空
	if (NULL == g_pHead || NULL == g_pEnd)
	{
		//printf_s("无此节点!\n");
		return NULL;
	}

	//遍历链表
	STUNODE* pTemp = g_pHead;
	while (pTemp)
	{

		if ((0 == strcmp(pTemp->ID, DATA)) || (0 == strcmp(pTemp->Name, DATA)))
			return pTemp;
		pTemp = pTemp->pnext;
	}

	printf_s("查无此节点");
	return NULL;
}
