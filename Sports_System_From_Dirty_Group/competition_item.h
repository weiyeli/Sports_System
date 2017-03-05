
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"

typedef struct item
{
	int id;							//项目代码
	char item_name[10];		//项目名称
	int item_nature;			//项目性质,1代表田赛,2代表径赛
	char item_time[10];			    //比赛时间
	char item_location[10];			//比赛地点
	STUNODE* stu[100] = { NULL };				//参加该项目的某个学生
	//int item_number_of_students;  //参加比赛的学生人数
	float item_grade = 0;			//比赛成绩
	int item_score = 0;				//个人得分;
	item* pNext = NULL;;					//下一个参加该项目的学生个体
}ITEMNODE;

//声明链表的头和尾
ITEMNODE* i_pHead = NULL;
ITEMNODE* i_pEnd = NULL;


//注册一个比赛项目
void register_item(int id, char* item_name, int item_nature, char* item_time, char* item_location) {
	ITEMNODE* pNode = (ITEMNODE*)malloc(sizeof(ITEMNODE));	 //申请一个项目
	pNode->id = id;
	strcpy(pNode->item_name, item_name);
	pNode->item_nature = item_nature;
	strcpy(pNode->item_time, item_time);
	strcpy(pNode->item_location, item_location);

	//头和尾指针都指向首节点
	i_pHead = pNode;
	i_pEnd = pNode;
}


//项目报名
void sign_up_item(STUNODE* pNode) {
	return;
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

	system("cls");
	printf_s(" 学院\t\t学号\t\t姓名\t\t性别\n");

	while (pTemp != NULL)
	{
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

	//printf_s("查无此节点");
	return NULL;
}



void ModifyStuData(STUNODE* pTemp)
{
	setColor(10, 0);
	char cOrder = 'q';
	int flag = 1;

	if (NULL == pTemp)
	{
		printf_s("查无此人!\n");
		return;
	}

	showSingleSTU(pTemp);
	printf_s("\n");


	//修改学生信息
	int college;			//学院
	char ID[20];			//学号
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
void SaveStuToFile()
{
	FILE* pFile = NULL;
	STUNODE* pTemp = g_pHead;
	char strBuf[60] = { '\0' };
	char strScore[20] = { '\0' };

	//判断链表是否为空
	if (NULL == g_pHead)
	{
		printf_s("学生信息为空!");
		return;
	}

	//打开文件
	pFile = fopen("students.txt", "wb+");
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
		strcpy(strBuf, pTemp->ID);
		strcat(strBuf, "#");
		//姓名
		strcat(strBuf, pTemp->Name);
		strcat(strBuf, "#");
		//性别
		//itoa(pTemp->gender,strScore,10);
		if (pTemp->gender == 0)
			strcat(strBuf, "0");
		else strcat(strBuf, "1");
		//strcat(strBuf,strScore);
		strcat(strBuf, "#");

		//写入文件
		fwrite(strBuf, 1, strlen(strBuf), pFile);
		fwrite("\r\n", 1, strlen("\r\n"), pFile);

		pTemp = pTemp->pnext;
	}

	//关闭文件
	fclose(pFile);
}


//读取文件中的学生信息
void ReadSTUFromFile()
{
	FILE *pFile = fopen("students.txt", "rb+");
	if (NULL == pFile)
	{
		printf_s("文件打开失败\n");
		return;
	}

	char strBuf[60] = { '\0' };
	int college;			//学院
	char ID[20];			//学号
	char Name[10];    //学生姓名
	int gender;		   //性别

					   //操作指针，读取函数
	while (fgets(strBuf, 60, pFile))
	{
		int nCount = 0;
		char delims[] = "#";
		char *result = NULL;

		//字符串切割
		result = strtok(strBuf, delims);
		college = atoi(result);

		while (NULL != result)
		{
			//读到换行就结束
			if (strcmp(result, "\r\n") == 0)
				break;

			result = strtok(NULL, delims);
			if (0 == nCount)
				strcpy(ID, result);
			//puts(Name);

			if (1 == nCount) {
				strcpy(Name, result);
				//printf_s("%d\n", gender);
			}
			if (2 == nCount)
			{
				gender = atoi(result);
				//printf_s("%f\n", Mark_Running);
			}
			nCount++;

		}

		//将文件中的信息添加到链表中
		AddStuMSG(college, ID, Name, gender);
	}
	fclose(pFile);
}