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
	char  grade[10];													//学生成绩
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
	Find_STU_By_ID_Or_Nmae(stu_id)->item_count += 1;
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
		Initialize_Grade_Table(item_id, stu_id, complete, grade, rank);
	}
	fclose(pFile);
}


//查找指定的成绩单
GRADENODE* Find_Grade_Table(char* item_id, char* stu_id)
{
	//检测参数的合法性
	if (NULL == item_id || NULL == stu_id)
	{
		//printf_s("输入错误!\n");
		return NULL;
	}

	//判断链表是否为空
	if (NULL == t_pHead || NULL == t_pEnd)
	{
		//printf_s("无此节点!\n");
		return NULL;
	}

	//遍历链表
	GRADENODE* pTemp = t_pHead;
	while (pTemp)
	{

		if ((0 == strcmp(pTemp->item_id, item_id)) || (0 == strcmp(pTemp->stu_id, stu_id)))
			return pTemp;
		pTemp = pTemp->pNext;
	}

	//printf_s("查无此节点");
	return NULL;
}

//删除指定的成绩表
void DeleteStuData(GRADENODE* pNode) {
	if (NULL == pNode)
	{
		printf_s("查无此人!\n");
		return;
	}

	//只有一个节点
	if (t_pHead == t_pEnd)
	{
		//printf_s("我是1\n");
		free(t_pHead);
		t_pHead = NULL;
		t_pEnd = NULL;
	}
	// 只有两个节点
	else if (t_pHead->pNext == t_pEnd) {
		//printf_s("我是2\n");
		//如果传进来的是头
		if (t_pHead == pNode) {
			free(t_pHead);
			t_pHead = t_pEnd;
		}
		//如果传进来的是尾
		if (t_pEnd == pNode) {
			free(t_pEnd);
			t_pEnd = t_pHead;
			t_pHead->pNext = NULL; //小心野指针
		}
	}

	//节点数大于等于三
	else {
		//printf_s("我是3\n");
		GRADENODE* pTemp = t_pHead;

		//判断头
		if (t_pHead == pNode)
		{
			//记住头
			//printf_s("%s我是测试1\n", t_pHead->ID);
			pTemp = t_pHead;
			t_pHead = t_pHead->pNext;
			//printf_s("%s我是测试2\n", t_pHead->ID);
			free(pTemp);
			pTemp = NULL;
			return;
		}

		//printf_s("%s我是测试3\n", pNode->ID);
		while (pTemp)
		{
			if (pTemp->pNext == pNode)
			{

				//判断尾
				if (t_pEnd == pNode)
				{
					//删除
					free(pNode);
					pNode = NULL;
					t_pEnd = pTemp;
					pTemp->pNext = NULL;
					return;
				}

				pTemp->pNext = pNode->pNext;
				free(pNode);
				return;
			}
			pTemp = pTemp->pNext;
		}
	}
}

//录入学生信息
void Record_Stu_Score(char* item_id)
{

}


