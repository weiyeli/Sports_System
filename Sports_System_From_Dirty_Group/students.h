#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students_main_page.h"

typedef struct Student
{
	char ID[12];					  //学号
	char Name[10];				  //学生姓名
	int gender;					  //性别
	int college;	                  //所属学院
	int item_score[3][2];		 //报名的项目代码和成绩
	int item_count = 0;		 //记录已报名项目的数目
	Student* pnext;		     //指针
} STUNODE;

char strBuf[60] = { '\0' };
int stu_college;					//学院
char stu_id[10];					//学号
char stu_name[10];				//学生姓名
int stu_gender;					 //性别

//声明链表的头和尾
STUNODE* g_pHead = NULL;
STUNODE* g_pEnd = NULL;


//添加学生信息
void Add_Stu_MSG(int college, char* arrStuID, char* arrStuName, int gender)
{
	//检验参数的合法性
	if (NULL == arrStuName|| NULL == arrStuID)
	{
		printf_s("学生信息有误");
		return;
	}

	//逻辑
	//创建一个节点
	STUNODE* pNode = (STUNODE*)malloc(sizeof(STUNODE));
	//节点成员初始化
	strcpy(pNode->ID, arrStuID);
	strcpy(pNode->Name, arrStuName);
	pNode->gender = gender;
	pNode->college = college;
	pNode->pnext = NULL;

	//接在链表尾部上
	//如果链表为空
	if (NULL == g_pHead || NULL == g_pEnd)
	{
		g_pHead = pNode;
		g_pEnd = pNode;
		return;
	}

	STUNODE* pTemp = g_pHead; //用来遍历每一个节点
	STUNODE* tTemp = NULL;	//标记前置节点


	//如果链表不为空,按学号从小到大插入节点
 	while ( atoi(pNode->ID) <= atoi(arrStuID))
	{
		//如果两个学号相等，直接退出
		if (pTemp->ID == pNode->ID)
		{
			printf_s("error: 已存在该学号的学生!\n");
			return;
		}

		tTemp = pTemp;
		pTemp = pTemp->pnext;

		if (pTemp == NULL)
			break;
	}

	//刚好插在头部
	if (pTemp == g_pHead)
	{
		pNode->pnext = pTemp;
		g_pHead = pNode;
		pTemp = NULL;
		return;
	}
	//插在尾部
	else if (pTemp == NULL){
		tTemp->pnext = pNode;
		g_pEnd = pNode;
		pNode->pnext = NULL;
		return;
	}

	//插在中间
	else {
		tTemp->pnext = pNode;
		pNode->pnext = pTemp;
	}
	//else {
	//	g_pEnd->pnext = pNode;	//链接
	//	g_pEnd = pNode;  //移动
	//}

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

void Free_Stu_LinkedData()
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
void Show_Stu_Data()
{
	setColor(10, 0);
	STUNODE* pTemp = g_pHead;

	if (NULL == g_pHead || NULL == g_pEnd)
	{
		printf_s("学生信息为空!\n");
		return;
	}

	system("cls");
	printf_s(" 学院\t\t学号\t\t\t姓名\t\t性别\n");

	while (pTemp != NULL)
	{
		if (pTemp->college == 1)
			printf_s("工学院\t\t");
		else if (pTemp->college == 2)
			printf_s("医学院\t\t");
		else if (pTemp->college == 3)
			printf_s("法学院\t\t");
		
		printf_s("%10s\t\t%4s\t\t",pTemp->ID, pTemp->Name);
		char* sOrder_Male = "男";
		char* sOrder_Female = "女";
		if (pTemp->gender == 1)
			printf_s("%4s\n", sOrder_Male);
		else printf_s("%4s\n", sOrder_Female);
		
		//往下走一步
		pTemp = pTemp->pnext;
	}
}

//显示指定学生信息
void Show_Single_STU(STUNODE* pTemp)
{
	if (NULL == pTemp)
	{
		printf_s("查无此人!\n");
		return;
	}

	setColor(10, 0);
	system("cls");
	printf_s(" 学院\t\t学号\t\t姓名\t\t性别\n");
	if (pTemp->college == 1)
		printf_s("工学院\t\t");
	else if (pTemp->college == 2)
		printf_s("医学院\t\t");
	else if (pTemp->college == 3)
		printf_s("法学院\t\t");
	printf_s("%10s\t%4s\t\t", pTemp->ID, pTemp->Name);
	char* sOrder_Male = "男";
	char* sOrder_Female = "女";
	if (pTemp->gender == 1)
		printf_s("%4s\n", sOrder_Male);
	else printf_s("%4s\n", sOrder_Female);
}



//查找指定的学生
STUNODE* Find_STU_By_ID_Or_Nmae(char* DATA)
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

	//printf_s("查无此节点");
	return NULL;
}



void Modify_Stu_Data(STUNODE* pTemp)
{
	setColor(10, 0);
	char cOrder = 'q';
	int flag = 1;

	if (NULL == pTemp)
	{
		printf_s("查无此人!\n");
		return;
	}

	Show_Single_STU(pTemp);
	printf_s("\n");


	//修改学生信息
	int college;			//学院
	char ID[10];			//学号
	char Name[10];    //学生姓名
	int gender;		   //性别

	//修改学院
	printf_s("请输入新的学院(工1医2法3--无需修改则输入0): ");
	getchar();
	scanf_s("%d", &college);
	if (college != 0) {
		while (flag) {
			printf_s("是否要将学院编码%d修改为%d？ y/n\n", pTemp->college, college);
			scanf_s("%c", &cOrder);
			if (cOrder == 'y') {
				pTemp->college = college;
				flag = 0;
			}
		}
		flag = 1;
	}

	//修改学号
	printf_s("请输入新的学号(无需修改则输入0): ");
	getchar();
	scanf_s("%s",&ID);
	if (ID!= 0) {
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
	if (gender != 0) {
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
}
	
//删除学生信息
	void DeleteStuData(STUNODE* pNode) {
		if (NULL == pNode)
		{
			printf_s("查无此人!\n");
			return;
		}

		//只有一个节点
		if (g_pHead == g_pEnd)
		{
			//printf_s("我是1\n");
			free(g_pHead);
			g_pHead = NULL;
			g_pEnd = NULL;
		}
		// 只有两个节点
		else if (g_pHead->pnext == g_pEnd) {
			//printf_s("我是2\n");
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
		}

		//节点数大于等于三
		else {
			//printf_s("我是3\n");
			STUNODE* pTemp = g_pHead;

			//判断头
			if (g_pHead == pNode)
			{
				//记住头
				//printf_s("%s我是测试1\n", g_pHead->ID);
				pTemp = g_pHead;
				g_pHead = g_pHead->pnext;
				//printf_s("%s我是测试2\n", g_pHead->ID);
				free(pTemp);
				pTemp = NULL;
				return;
			}

			//printf_s("%s我是测试3\n", pNode->ID);
			while (pTemp)
			{
				if (pTemp->pnext == pNode)
				{

					//判断尾
					if (g_pEnd == pNode)
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
					return;
				}
				pTemp = pTemp->pnext;
			}
		}
	}


//保存信息到文件中
void Save_Stu_To_File()
{
	FILE* pFile = NULL;
	STUNODE* pTemp = g_pHead;
	char strBuf[60] = {'\0'};
	char strScore[20] = { '\0' };

	//判断链表是否为空
	if (NULL == g_pHead)
	{
		printf_s("学生信息为空!");
		return;
	}

	//打开文件
	pFile = fopen("students.txt","wb+");
	if (NULL == pFile)
	{
		printf_s("文件打开失败\n");
		return;
	}


	//操作文件指针
	while (pTemp)
	{
		//复制学院
		if (pTemp->college == 1)
			strcat(strBuf, "1");
		else if (pTemp->college == 2)
			strcat(strBuf, "2");
		else if (pTemp->college == 3)
			strcat(strBuf, "3");
		strcat(strBuf, "#");
		//学号复制进去
		strcat(strBuf, pTemp->ID);
		strcat(strBuf,"#");
		//姓名
		strcat(strBuf,pTemp->Name);
		strcat(strBuf, "#");
		//性别
		//itoa(pTemp->gender,strScore,10);
		if (pTemp->gender==0)
			strcat(strBuf, "0");
		else strcat(strBuf, "1");
		//strcat(strBuf,strScore);
		strcat(strBuf, "#");

		//写入文件
		fwrite(strBuf, 1 , strlen(strBuf) , pFile );
		fwrite("\r\n",1,strlen("\r\n"),pFile);

		pTemp = pTemp->pnext;	
	}

	//关闭文件
	fclose(pFile);
}


//读取文件中的学生信息
void Read_STU_From_File()
{
	FILE *pFile = fopen("students.txt","rb+");
	if (NULL == pFile)
	{
		printf_s("文件打开失败\n");
		return;
	}


	//操作指针，读取函数
	while (fgets(strBuf, 60, pFile))
	{
		int nCount = 0;
		char delims[] = "#";
		char *result = NULL;

		//字符串切割
		result = strtok(strBuf, delims);
		stu_college = atoi(result);

		while (NULL != result)
		{
			//读到换行就结束
			if (strcmp(result,"\r\n")==0)
				break;

			result = strtok(NULL, delims);
			if (0 == nCount)
				strcpy(stu_id,result);

			if (1 == nCount) 
				strcpy(stu_name,result);
			
			if (2 == nCount)		
				stu_gender = atoi(result);
		
			nCount++;

		}

		//将文件中的信息添加到链表中
		Add_Stu_MSG(stu_college, stu_id, stu_name, stu_gender);
	}
	fclose(pFile);
}
