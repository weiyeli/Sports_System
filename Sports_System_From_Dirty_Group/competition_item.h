#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"

typedef struct item
{
	char item_id[3];											//项目代码
	char item_name[10];									//项目名称
	int item_nature;										//项目性质,1代表田赛,2代表径赛
	char item_time[10];									//比赛时间
	char item_location[10];								//比赛地点
	STUNODE* item_stu[30] = {NULL};				//参加该项目的某个学生
	//int item_number_of_students;				//参加比赛的学生人数
	float item_grade = 0;								//比赛成绩
	int item_score = 0;									//个人得分;
	item* pNext = NULL;								//下一个比赛项目
}ITEMNODE;

//声明链表的头和尾
ITEMNODE* i_pHead = NULL;
ITEMNODE* i_pEnd = NULL;


//注册一个比赛项目
void register_item(char* item_id, char* item_name, int item_nature, char* item_time, char* item_location) {
	ITEMNODE* pNode = (ITEMNODE*)malloc(sizeof(ITEMNODE));	 //申请一个项目

	strcpy(pNode->item_id, item_id);
	strcpy(pNode->item_name, item_name);
	pNode->item_nature = item_nature;
	strcpy(pNode->item_time, item_time);
	strcpy(pNode->item_location, item_location);

	//如果为空，头和尾指针都指向首节点
	if (NULL == i_pHead || NULL == i_pEnd)
	{
		i_pHead = pNode;
		i_pEnd = pNode;
		pNode->pNext = NULL;
		return;
	}

	ITEMNODE* pTemp = i_pHead;	//用来遍历每一个节点
	ITEMNODE* tTemp = NULL;			//标记前置节点


	//如果链表不为空,按项目代码从小到大插入节点
	while (atoi(pNode->item_id) <= atoi(item_id))
	{
		//如果两个学号相等，直接退出
		if (pTemp->item_id == pNode->item_id)
		{
			printf_s("error: 已存在该项目!\n");
			return;
		}

		tTemp = pTemp;
		pTemp = pTemp->pNext;

		if (pTemp == NULL)
			break;
	}

	//刚好插在头部
	if (pTemp == i_pHead)
	{
		pNode->pNext = pTemp;
		i_pHead = pNode;
		pTemp = NULL;
		return;
	}
	//插在尾部
	else if (pTemp == NULL) {
		tTemp->pNext = pNode;
		i_pEnd = pNode;
		pNode->pNext = NULL;
		return;
	}

	//插在中间
	else {
		tTemp->pNext = pNode;
		pNode->pNext = pTemp;
	}
}


//查找指定的比赛项目
ITEMNODE* Find_Item_By_ID_Or_Nmae(char* DATA)
{
	//检测参数的合法性
	if (NULL == DATA)
	{
		//printf_s("输入错误!\n");
		return NULL;
	}

	//判断链表是否为空
	if (NULL == i_pHead || NULL == i_pEnd)
	{
		//printf_s("无此节点!\n");
		return NULL;
	}

	//遍历链表
	ITEMNODE* pTemp = i_pHead;
	while (pTemp)
	{

		if ((0 == strcmp(pTemp->item_id, DATA)) || (0 == strcmp(pTemp->item_name, DATA)))
			return pTemp;
		pTemp = pTemp->pNext;
	}

	//printf_s("查无此节点");
	return NULL;
}


//项目报名
void sign_up_item(char* stu_data, char* item_data) {

	//要报名的项目
	ITEMNODE* i_pTemp = Find_Item_By_ID_Or_Nmae(item_data);

	//报名的学生
	STUNODE*  s_pTemp = Find_STU_By_ID_Or_Nmae(stu_data);

	//检验参数的合法性
	if (NULL == stu_data || NULL == item_data)
	{
		printf_s("无效的项目或者学生信息!");
		return;
	}

	//学生已报名项目数目检测
	if (s_pTemp->item_count >= 3)
	{
		printf_s("对不起，一人最多只能报名三个比赛项目!");
		return;
	}

	//项目里面的学生数组的指针
	STUNODE** p_strArray = i_pTemp->item_stu;

	//遍历项目中的学生数组
	int i = 0;
	while (p_strArray[i] == NULL)
		i++;

	//将该学生添加到该项目中
	p_strArray[i - 1] = s_pTemp;

	//在学生信息中添加报名的项目

	for (int i=0;i<3;i++)
	{
		if (s_pTemp->item_score[i][0] == -1)
		{
			s_pTemp->item_score[i][0] = atoi(i_pTemp->item_id);
		}
	}
	
}


//释放项目链表
void Free_Item_LinkedData()
{
	ITEMNODE* pTemp = i_pHead;
	while (i_pHead != NULL)
	{
		//记录节点
		pTemp = i_pHead;

		//向后移动一位
		i_pHead = i_pHead->pNext;

		//释放链表
		free(pTemp);
	}
}

//保存比赛信息到文件中
void Save_Item_To_File()
{
	FILE* pFile = NULL;
	ITEMNODE* pTemp = i_pHead;
	char strBuf[60] = { '\0' };
	char strScore[20] = { '\0' };

	//判断链表是否为空
	if (NULL == i_pHead)
	{
		printf_s("项目信息为空!");
		return;
	}

	//打开文件
	pFile = fopen("item.txt", "ab+");
	if (NULL == pFile)
	{
		printf_s("文件打开失败\n");
		return;
	}


	//操作文件指针
	while (pTemp)
	{
		//复制项目代码
		strcat(strBuf, pTemp->item_name);
		strcat(strBuf, "#");
		//复制项目名称
		strcat(strBuf, pTemp->item_name);
		strcat(strBuf, "#");
		//项目性质
		if (pTemp->item_nature == 1)
			strcat(strBuf, "1");
		else if (pTemp->item_nature == 2)
			strcat(strBuf, "2");
		strcat(strBuf, "#");
		//复制比赛时间
		strcat(strBuf, pTemp->item_time);
		strcat(strBuf, "#");
		//复制比赛地点
		strcat(strBuf, pTemp->item_location);
		strcat(strBuf, "#");
		puts(strBuf);
		//复制报名的学生信息


		//写入文件
		fwrite(strBuf, 1, strlen(strBuf), pFile);
		fwrite("\r\n", 1, strlen("\r\n"), pFile);

		pTemp = pTemp->pNext;
	}

	//关闭文件
	fclose(pFile);
}

//显示项目信息
void Show_Com_info()
{
	setColor(10, 0);
	ITEMNODE* pTemp = i_pHead;

	if (NULL == i_pHead | NULL == i_pEnd)
	{
		printf_s("比赛项目信息为空！\n");
		return;
	}

	system("cls");
	printf_s("项目代码\t项目性质\t项目名称\t项目时间\t项目地点\t\n");

	while (pTemp != NULL)
	{
		printf_s("%s\t", pTemp->item_id);
		if (pTemp->item_nature == 1)
			printf_s("田赛\t");
		else if (pTemp->item_nature == 2)
			printf_s("竞赛\t");
		else
			printf_s("\t");
		printf_s("%s\t%d\t%s\t$s\t\n", pTemp->item_name, pTemp->item_nature, pTemp->item_time, pTemp->item_location);

	}
}