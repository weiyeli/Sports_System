#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "competition_item.h"
#include "students.h"


typedef struct grade_table
{
	char stu_id[15];														//ѧ��ѧ��
	char item_id[10];													//��Ŀ���
	int  complete;														//������
	float  grade;															//ѧ���ɼ�
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
	pNode->grade = 0;
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
		if (strcmp(pTemp->item_id,pNode->item_id)==0 && strcmp(pTemp->stu_id, pNode->stu_id)==0)
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

	//Ҫ��������Ŀ
	ITEMNODE* i_pTemp = Find_Item_By_ID_Or_Nmae(item_id);
	i_pTemp->item_number_of_students++;
	
	//������ѧ��
	STUNODE*  s_pTemp = Find_STU_By_ID_Or_Nmae(stu_id);
	s_pTemp->item_count++;
}

