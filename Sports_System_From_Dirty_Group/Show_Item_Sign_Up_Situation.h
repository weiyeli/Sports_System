#pragma once
#include "competition_item.h"
#include "students.h"
#include "grade_table.h"

////�鿴��Ŀ�������
//void Show_Item_Sign_UP_Situation(char* item_data)
//{
//	//Ҫ��������Ŀ
//	ITEMNODE* i_pTemp = Find_Item_By_ID_Or_Nmae(item_data);
//	char* stubuf;
//
//	system("cls");
//	setColor(12, 0);
//
//}

//�ӳɼ����в�ѯ��Ŀ�������
void Find_Item_From_Grade_Table(char* DATA)
{
	//�������ĺϷ���
	if (NULL == DATA)
	{
		//printf_s("�������!\n");
		return;
	}

	//�ж������Ƿ�Ϊ��
	if (NULL == t_pHead || NULL == t_pEnd)
	{
		//printf_s("�޴˽ڵ�!\n");
		return;
	}

	system("cls");
	setColor(12, 0);
	printf_s("\t������Ŀ: %s\t\t��������: %d\n\n", Find_Item_By_ID_Or_Nmae(DATA)->item_name, Find_Item_By_ID_Or_Nmae(DATA)->item_number_of_students);
	printf_s("���\t\tѧԺ\t\tѧ��\t\t����\n");
	//��������
	GRADENODE* pTemp = t_pHead;
	while (pTemp)
	{
		int i = 0;
		//�ҵ��˸���Ŀ�ĳɼ���
		if (strcmp(DATA, pTemp->item_id) == 0)
		{
			printf_s("%d\t\t", i);
			if (Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->college == 1)
				printf_s("��ѧԺ\t\t");
			else if (Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->college == 2)
				printf_s("ҽѧԺ\t\t");
			else if (Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->college == 3)
				printf_s("��ѧԺ\t\t");

			printf_s("%10s\t\t%s\t\t\n", Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->ID, Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->Name);
		}
		pTemp = pTemp->pNext;
	}

}
