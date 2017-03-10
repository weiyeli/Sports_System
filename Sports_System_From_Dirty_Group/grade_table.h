#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"


typedef struct grade_table
{
	char stu_id[15];														//ѧ��ѧ��
	char item_id[10];													//��Ŀ���
	int  complete;														//������
	char  grade[10];													//ѧ���ɼ�
	int rank;																//ѧ������
	grade_table* pNext = NULL;									//��һ�ųɼ���
}GRADENODE;

//���������ͷ��β
GRADENODE* t_pHead = NULL;
GRADENODE* t_pEnd = NULL;

//���һ�ųɼ���
void Add_Grade_Table(char* item_id, char* stu_id) {
	//����һ����Ŀ
	GRADENODE* pNode = (GRADENODE*)malloc(sizeof(GRADENODE));

	//�ɼ�����ʼ��
	strcpy(pNode->item_id, item_id);
	strcpy(pNode->stu_id, stu_id);
	strcpy(pNode->grade, "-1");
	pNode->rank = 0;
	pNode->complete = 0;
	pNode->pNext = NULL;

	//���Ϊ�գ�ͷ��βָ�붼ָ���׽ڵ�
	if (NULL == t_pHead || NULL == t_pEnd)
	{
		t_pHead = pNode;
		t_pEnd = pNode;
		pNode->pNext = NULL;
		return;
	}

	GRADENODE* pTemp = t_pHead;		//��������ÿһ���ڵ�
	GRADENODE* tTemp = NULL;			//���ǰ�ýڵ�


	//�������Ϊ��,����Ŀ�����С�������ڵ�
	while (atoi(pNode->item_id) <= atoi(item_id))
	{
		//�������ѧ�ź���Ŀ������ȣ�ֱ���˳�
		if (strcmp(pTemp->item_id, pNode->item_id) == 0 && strcmp(pTemp->stu_id, pNode->stu_id) == 0)
		{
			printf_s("error: �Ѵ��ڸóɼ���!\n");
			return;
		}

		tTemp = pTemp;
		pTemp = pTemp->pNext;

		if (pTemp == NULL)
			break;
	}

	//�պò���ͷ��
	if (pTemp == t_pHead)
	{
		pNode->pNext = pTemp;
		t_pHead = pNode;
		pTemp = NULL;
		return;
	}
	//����β��
	else if (pTemp == NULL) {
		tTemp->pNext = pNode;
		t_pEnd = pNode;
		pNode->pNext = NULL;
		return;
	}

	//�����м�
	else {
		tTemp->pNext = pNode;
		pNode->pNext = pTemp;
	}
	Find_STU_By_ID_Or_Nmae(stu_id)->item_count += 1;
}

//��ʼ���ɼ���
void Initialize_Grade_Table(char* item_id, char* stu_id, int comlete, char* grade, int rank) {
	//����һ����Ŀ
	GRADENODE* pNode = (GRADENODE*)malloc(sizeof(GRADENODE));

	//�ɼ�����ʼ��
	strcpy(pNode->item_id, item_id);
	strcpy(pNode->stu_id, stu_id);
	strcpy(pNode->grade, "-1");
	pNode->rank = 0;
	pNode->complete = 0;
	pNode->pNext = NULL;

	//���Ϊ�գ�ͷ��βָ�붼ָ���׽ڵ�
	if (NULL == t_pHead || NULL == t_pEnd)
	{
		t_pHead = pNode;
		t_pEnd = pNode;
		pNode->pNext = NULL;
		return;
	}

	GRADENODE* pTemp = t_pHead;		//��������ÿһ���ڵ�
	GRADENODE* tTemp = NULL;			//���ǰ�ýڵ�


	//�������Ϊ��,����Ŀ�����С�������ڵ�
	while (atoi(pNode->item_id) <= atoi(item_id))
	{
		//�������ѧ�ź���Ŀ������ȣ�ֱ���˳�
		if (strcmp(pTemp->item_id, pNode->item_id) == 0 && strcmp(pTemp->stu_id, pNode->stu_id) == 0)
		{
			printf_s("error: �Ѵ��ڸóɼ���!\n");
			return;
		}

		tTemp = pTemp;
		pTemp = pTemp->pNext;

		if (pTemp == NULL)
			break;
	}

	//�պò���ͷ��
	if (pTemp == t_pHead)
	{
		pNode->pNext = pTemp;
		t_pHead = pNode;
		pTemp = NULL;
		return;
	}
	//����β��
	else if (pTemp == NULL) {
		tTemp->pNext = pNode;
		t_pEnd = pNode;
		pNode->pNext = NULL;
		return;
	}

	//�����м�
	else {
		tTemp->pNext = pNode;
		pNode->pNext = pTemp;
	}
}


//�ͷųɼ�������
void Free_Grade_LinkedData()
{
	GRADENODE* pTemp = t_pHead;
	while (t_pHead != NULL)
	{
		//��¼�ڵ�
		pTemp = t_pHead;

		//����ƶ�һλ
		t_pHead = t_pHead->pNext;

		//�ͷ�����
		free(pTemp);
	}
}

//����ɼ������ļ���
void Save_Grade_Table_To_File()
{
	FILE* pFile = NULL;
	GRADENODE* pTemp = t_pHead;
	char strBuf[100] = { '\0' };
	char strbuf[15];
	char strScore[20] = { '\0' };

	//�ж������Ƿ�Ϊ��
	if (NULL == t_pHead)
	{
		printf_s("�ɼ���Ϊ��!");
		return;
	}

	//���ļ�
	pFile = fopen("grade.txt", "wb+");
	if (NULL == pFile)
	{
		printf_s("�ļ���ʧ��\n");
		return;
	}


	//�����ļ�ָ��
	while (pTemp)
	{
		//����ѧ��ѧ��
		strcat(strBuf, pTemp->stu_id);
		strcat(strBuf, "#");
		//������Ŀ����
		strcat(strBuf, pTemp->item_id);
		strcat(strBuf, "#");
		//����������
		if (pTemp->complete == 1)
			strcat(strBuf, "1");
		else if (pTemp->complete == 2)
			strcat(strBuf, "2");
		strcat(strBuf, "#");
		//���Ƴɼ�
		strcat(strBuf, pTemp->grade);
		strcat(strBuf, "#");
		//��������
		itoa(pTemp->rank,strbuf,10);
		strcat(strBuf, strbuf);
		strcat(strBuf, "#");

		//д���ļ�
		fwrite(strBuf, 1, strlen(strBuf), pFile);
		fwrite("\r\n", 1, strlen("\r\n"), pFile);

		pTemp = pTemp->pNext;
	}

	//�ر��ļ�
	fclose(pFile);
}

//���ļ��ж�ȡ��Ŀ��Ϣ
void Read_Grade_Table_From_File()
{
	FILE *pFile = fopen("grade.txt", "rb+");
	if (NULL == pFile)
	{
		printf_s("�ļ���ʧ��\n");
		return;
	}

	char strBuf[100] = { '\0' };
	char stu_id[15];														//ѧ��ѧ��
	char item_id[10];													//��Ŀ���
	int  complete;														//������
	char  grade[10];													//ѧ���ɼ�
	int rank;																//ѧ������

	//����ָ�룬��ȡ����
	while (fgets(strBuf, 60, pFile))
	{
		int nCount = 0;
		int i = 0;
		char delims[] = "#";
		char *result = NULL;

		//�ַ����и�
		result = strtok(strBuf, delims);
		strcpy(stu_id, result);

		while (NULL != result)
		{
			//�������оͽ���
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

		//���ļ��е���Ϣ��ӵ�������
		Initialize_Grade_Table(item_id, stu_id, complete, grade, rank);
	}
	fclose(pFile);
}


//����ָ���ĳɼ���
GRADENODE* Find_Grade_Table(char* item_id, char* stu_id)
{
	//�������ĺϷ���
	if (NULL == item_id || NULL == stu_id)
	{
		//printf_s("�������!\n");
		return NULL;
	}

	//�ж������Ƿ�Ϊ��
	if (NULL == t_pHead || NULL == t_pEnd)
	{
		//printf_s("�޴˽ڵ�!\n");
		return NULL;
	}

	//��������
	GRADENODE* pTemp = t_pHead;
	while (pTemp)
	{

		if ((0 == strcmp(pTemp->item_id, item_id)) || (0 == strcmp(pTemp->stu_id, stu_id)))
			return pTemp;
		pTemp = pTemp->pNext;
	}

	//printf_s("���޴˽ڵ�");
	return NULL;
}

//ɾ��ָ���ĳɼ���
void DeleteStuData(GRADENODE* pNode) {
	if (NULL == pNode)
	{
		printf_s("���޴���!\n");
		return;
	}

	//ֻ��һ���ڵ�
	if (t_pHead == t_pEnd)
	{
		//printf_s("����1\n");
		free(t_pHead);
		t_pHead = NULL;
		t_pEnd = NULL;
	}
	// ֻ�������ڵ�
	else if (t_pHead->pNext == t_pEnd) {
		//printf_s("����2\n");
		//�������������ͷ
		if (t_pHead == pNode) {
			free(t_pHead);
			t_pHead = t_pEnd;
		}
		//�������������β
		if (t_pEnd == pNode) {
			free(t_pEnd);
			t_pEnd = t_pHead;
			t_pHead->pNext = NULL; //С��Ұָ��
		}
	}

	//�ڵ������ڵ�����
	else {
		//printf_s("����3\n");
		GRADENODE* pTemp = t_pHead;

		//�ж�ͷ
		if (t_pHead == pNode)
		{
			//��סͷ
			//printf_s("%s���ǲ���1\n", t_pHead->ID);
			pTemp = t_pHead;
			t_pHead = t_pHead->pNext;
			//printf_s("%s���ǲ���2\n", t_pHead->ID);
			free(pTemp);
			pTemp = NULL;
			return;
		}

		//printf_s("%s���ǲ���3\n", pNode->ID);
		while (pTemp)
		{
			if (pTemp->pNext == pNode)
			{

				//�ж�β
				if (t_pEnd == pNode)
				{
					//ɾ��
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

//¼��ѧ����Ϣ
void Record_Stu_Score(char* item_id)
{

}


