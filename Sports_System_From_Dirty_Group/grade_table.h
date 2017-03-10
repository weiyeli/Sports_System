#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"


typedef struct grade_table
{
	char stu_id[15];														//学生学号
	char item_id[10];													//项目编号
	int  complete;														//完成情况
	char  grade[10];															//学生成绩
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
	strcpy(pNode->grade, "-1");
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
}

//初始化成绩单
void Initialize_Grade_Table(char* item_id, char* stu_id, int comlete, char* grade, int rank) {
	//申请一个项目
	GRADENODE* pNode = (GRADENODE*)malloc(sizeof(GRADENODE));

	//成绩单初始化
	strcpy(pNode->item_id, item_id);
	strcpy(pNode->stu_id, stu_id);
	strcpy(pNode->grade, "-1");
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
		if (strcmp(pTemp->item_id, pNode->item_id) == 0 && strcmp(pTemp->stu_id, pNode->stu_id) == 0)
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
}


//释放成绩单链表
void Free_Grade_LinkedData()
{
	GRADENODE* pTemp = t_pHead;
	while (t_pHead != NULL)
	{
		//记录节点
		pTemp = t_pHead;

		//向后移动一位
		t_pHead = t_pHead->pNext;

		//释放链表
		free(pTemp);
	}
}

//保存成绩单到文件中
void Save_Grade_Table_To_File()
{
	FILE* pFile = NULL;
	GRADENODE* pTemp = t_pHead;
	char strBuf[100] = { '\0' };
	char strbuf[15];
	char strScore[20] = { '\0' };

	//判断链表是否为空
	if (NULL == t_pHead)
	{
		printf_s("成绩单为空!");
		return;
	}

	//打开文件
	pFile = fopen("grade.txt", "wb+");
	if (NULL == pFile)
	{
		printf_s("文件打开失败\n");
		return;
	}


	//操作文件指针
	while (pTemp)
	{
		//复制学生学号
		strcat(strBuf, pTemp->stu_id);
		strcat(strBuf, "#");
		//复制项目代码
		strcat(strBuf, pTemp->item_id);
		strcat(strBuf, "#");
		//复制完成情况
		if (pTemp->complete == 1)
			strcat(strBuf, "1");
		else if (pTemp->complete == 2)
			strcat(strBuf, "2");
		strcat(strBuf, "#");
		//复制成绩
		strcat(strBuf, pTemp->grade);
		strcat(strBuf, "#");
		//复制名次
		itoa(pTemp->rank,strbuf,10);
		strcat(strBuf, strbuf);
		strcat(strBuf, "#");

		//写入文件
		fwrite(strBuf, 1, strlen(strBuf), pFile);
		fwrite("\r\n", 1, strlen("\r\n"), pFile);

		pTemp = pTemp->pNext;
	}

	//关闭文件
	fclose(pFile);
}

//从文件中读取项目信息
void Read_Grade_Table_From_File()
{
	FILE *pFile = fopen("grade.txt", "rb+");
	if (NULL == pFile)
	{
		printf_s("文件打开失败\n");
		return;
	}

	char strBuf[100] = { '\0' };
	char stu_id[15];														//学生学号
	char item_id[10];													//项目编号
	int  complete;														//完成情况
	char  grade[10];													//学生成绩
	int rank;																//学生名次

	//操作指针，读取函数
	while (fgets(strBuf, 60, pFile))
	{
		int nCount = 0;
		int i = 0;
		char delims[] = "#";
		char *result = NULL;

		//字符串切割
		result = strtok(strBuf, delims);
		strcpy(stu_id, result);

		while (NULL != result)
		{
			//读到换行就结束
			if (strcmp(result, "\r\n") == 0)
				break;

			result = strtok(NULL, delims);


			if (0 == nCount)
				strcpy(item_id, result);

			if (1 == nCount) {
				complete = atoi(result);
				//printf_s("%d\n", gender);
			}
			if (2 == nCount)
			{
				strcpy(grade, result);
				//printf_s("%f\n", Mark_Running);
			}
			if (3 == nCount) {
				rank = atoi(result);
			}
			nCount++;

		}

		//将文件中的信息添加到链表中
		Initialize_Grade_Table(stu_id, item_id, complete, grade, rank);
	}
	fclose(pFile);
}


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
	printf_s("\t报名项目: %s\t报名人数: \t\n\n",Find_Item_By_ID_Or_Nmae(DATA)->item_name, Find_Item_By_ID_Or_Nmae(DATA)->item_number_of_students);
	printf_s("编号\t\t学院\t\t学号\t\t姓名\n");
	//遍历链表
	GRADENODE* pTemp = t_pHead;
	while (pTemp)
	{
		int i = 0;
		//找到了该项目的成绩单
		if (strcmp(DATA, pTemp->item_id) == 0)
		{
			printf_s("%d\t\t",i);
			if (Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->college == 1)
				printf_s("工学院\t\t");
			else if (Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->college == 2)
				printf_s("医学院\t\t");
			else if (Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->college == 3)
				printf_s("法学院\t\t");

			printf_s("%10s\t\t%4s\t\t\n", Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->ID, Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->Name);
		}
		pTemp = pTemp->pNext;
	}
	
	printf_s("成绩单不存在!\n");
}

