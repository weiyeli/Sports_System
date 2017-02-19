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
	float Mark_Shot;
	Student* pnext;  //指针
} STUNODE;

//声明链表的头和尾
STUNODE* g_pHead = NULL;
STUNODE* g_pEnd = NULL;


//添加学生信息
void AddStuMSG(char* arrStuID, char* arrStuName, int gender, float Mark_Running, float Mark_Jumping, float Mark_Shot)
{
	//检验参数的合法性
	if (NULL == arrStuName|| NULL == arrStuID || Mark_Jumping<0 || Mark_Running<0 || Mark_Shot<0)
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
	pTemp->Mark_Shot = Mark_Shot;
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
	if (NULL == g_pHead || NULL == g_pEnd)
	{
		printf_s("学生信息为空!\n");
		return;
	}


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
		printf_s("%8.2f\t%8.2f\t%8.2f\n", pTemp->Mark_Running, pTemp->Mark_Jumping, pTemp->Mark_Shot);
		
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
	printf_s("%8.2f\t%8.2f\t%8.2f\n", pTemp->Mark_Running, pTemp->Mark_Jumping, pTemp->Mark_Shot);
}



//查找指定的学生
STUNODE* FindSTUByIDOrNmae(char* DATA)
{
	//检测参数的合法性
	if (NULL == DATA)
	{
		//printf_s("输入错误!\n");
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



void ModifyStuData(STUNODE* pTemp)
{
	setColor(10, 0);
	char cOrder = 'q';
	int flag = 1;

	if(NULL == pTemp)
	{
		printf_s("查无此人!\n");
		return;
	}

	showSingleSTU(pTemp);
	printf_s("\n");


	//修改学生信息
	char ID[20]; //学号
	char Name[10];  //学生姓名
	int gender; //性别
	float Mark_Running;
	float Mark_Jumping;
	float Mark_Shot;


	//修改学号
	printf_s("请输入新的学号(无需修改则输入0): ");
	getchar();
	gets_s(ID);
	if (strcmp(ID, "0") != 0) {
		while (flag) {
			printf_s("是否要将学号%s修改为%s？ y/n\n", pTemp->ID, ID);
			scanf_s("%c", &cOrder);
			if (cOrder == 'y') {
				strcpy(pTemp->ID, ID);
				flag = 0;
			} 
		}
		flag = 1;
	}

	//修改姓名
	printf_s("请输入新的姓名(无需修改则输入0): ");
	getchar();
	gets_s(Name);
	if (strcmp(Name, "0") != 0) {
		while (flag) {
			printf_s("是否要将姓名%s修改为%s？ y/n\n", pTemp->Name, Name);
			scanf_s("%c", &cOrder);
			if (cOrder == 'y') {
				strcpy(pTemp->Name, Name);
				flag = 0;
			}
		}
		flag = 1;
	}

	//修改性别
	printf_s("请输入新的性别(无需修改则输入0): ");
	getchar();
	scanf_s("%d", &gender);
	if ( gender!=0 ) {
		while (flag) {
			printf_s("是否要将姓别%d修改为%d？ y/n\n", pTemp->gender, gender);
			scanf_s("%c", &cOrder);
			if (cOrder == 'y') {
				pTemp->gender = gender;
				flag = 0;
			}
		}
		flag = 1;
	}

	//修改100米跑成绩
	printf_s("请输入新的100米跑成绩(无需修改则输入-1): ");
	getchar();
	scanf_s("%f", &Mark_Running);
	if ( Mark_Running!= -1) {
		while (flag) {
			printf_s("是否要将100米跑成绩%.2f秒修改为%.2f秒？ y/n\n", pTemp->Mark_Running, Mark_Running);
			scanf_s("%c", &cOrder);
			if (cOrder == 'y') {
				pTemp->Mark_Running = Mark_Running;
				flag = 0;
			}
		}
		flag = 1;
	}


	//修改跳远成绩
	printf_s("请输入新的跳远成绩(无需修改则输入-1): ");
	getchar();
	scanf_s("%f", &Mark_Jumping);
	if (Mark_Jumping != -1) {
		while (flag) {
			printf_s("是否要将跳远成绩%.2f米修改为%.2f米？ y/n\n", pTemp->Mark_Jumping, Mark_Jumping);
			scanf_s("%c", &cOrder);
			if (cOrder == 'y') {
				pTemp->Mark_Jumping = Mark_Jumping;
				flag = 0;
			}
		}
		flag = 1;
	}

	//修改铅球成绩
	printf_s("请输入新的铅球成绩(无需修改则输入-1): ");
	getchar();
	scanf_s("%f", &Mark_Shot);
	if (Mark_Shot != -1) {
		while (flag) {
			printf_s("是否要将铅球成绩%.2f米修改为%.2f米？ y/n\n", pTemp->Mark_Shot, Mark_Shot);
			scanf_s("%c", &cOrder);
			if (cOrder == 'y') {
				pTemp->Mark_Shot = Mark_Shot;
				flag = 0;
			}
		}
		flag = 1;
	}
}

void DeleteStuData(STUNODE* pNode)
{
	if (NULL == pNode)
	{
		printf_s("查无此人!\n");
		return;
	}

	//只有一个节点
	if (g_pHead == g_pEnd)
	{
		free(g_pHead);
		g_pHead = NULL;
		g_pEnd = NULL;
	}
	// 只有两个节点
	else if (g_pHead->pnext == g_pEnd) {
		//如果传进来的是头
		if (g_pHead == pNode) {
			free(g_pHead);
			g_pHead = g_pEnd;
		}
		//如果传进来的是尾
		if (g_pEnd == pNode) {
			free(g_pEnd);
			g_pEnd = g_pHead;
			g_pHead->pnext = NULL; //小心野指针
		}
		//节点数大于等于三
		else {
			STUNODE* pTemp = g_pHead;

			//判断头
			if (g_pHead == pNode)
			{
				//记住头
				pTemp = g_pHead;
				g_pHead = g_pHead->pnext;
				free(pTemp);
				pTemp = NULL;
				return;
			}

			while (pTemp)
			{
				if (pTemp->pnext == pNode) 
				{

					//判断尾
					if (g_pEnd = pNode)
					{
						//删除
						free(pNode);
						pNode = NULL;
						g_pEnd = pTemp;
						pTemp->pnext = NULL;
						return;
					}

					pTemp->pnext = pNode->pnext;
					free(pNode);
				}
					pTemp = pTemp->pnext;
			}
		}
	}
}
