//#pragma once
//#include <stdio.h>
//#include <stdlib.h>
//#include "grade_table.h"
//#include "students.h"
//#include <string.h>
//
//using std::string;
//
//int score_gong = 0;
//int score_yi = 0;
//int score_fa = 0;
//
////������ת��Ϊ����
//int rank_to_score(int a)
//{
//	if (a == 1)
//		return 5;
//	else if (a == 2)
//		return 3;
//	else if (a == 3)
//		return 1;
//	else
//		return 0;
//}
//
////����ѧԺ����
//void update_score_college()
//{
//	score_fa = score_gong = score_yi = 0;
//	GRADENODE* pTemp = t_pHead;
//
//	if (NULL == t_pHead || NULL == t_pEnd)
//		return;
//	while (pTemp != NULL)
//	{
//		if (Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->college == 1)
//			score_gong += rank_to_score(pTemp->rank);
//		else if (Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->college == 2)
//			score_yi += rank_to_score(pTemp->rank);
//		else if (Find_STU_By_ID_Or_Nmae(pTemp->stu_id)->college == 3)
//			score_fa += rank_to_score(pTemp->rank);
//		//������һ��
//		pTemp = pTemp->pNext;
//	}
//}
//
////���ת��ΪѧԺ
//string num_to_college(int a)
//{
//	if (a == 1)
//		return "��ѧԺ";
//	else if (a == 2)
//		return "ҽѧԺ";
//	else if (a == 3)
//		return "��ѧԺ";
//
//}
//
////��ʾѧԺ����
//void Show_Score_College()
//{
//	int a[2] = { 1,score_gong };
//	int b[2] = { 2,score_yi };
//	int c[2] = { 3,score_fa };
//	int tmp;
//	for (int i = 0; i < 3; i++)
//	{
//		if (a[1] > b[1])
//		{
//			tmp = a[1];
//			a[1] = b[1];
//			b[1] = tmp;
//			tmp = a[0];
//			a[0] = b[0];
//			b[0] = tmp;
//		}
//		if (b[1] > c[1])
//		{
//			tmp = b[1];
//			b[1] = c[1];
//			c[1] = tmp;
//			tmp = b[0];
//			b[0] = c[0];
//			c[0] = tmp;
//		}
//	}
//	printf_s(" ����\t\tѧԺ\t\t�ܵ÷�\t\t\n");
//	printf_s("1\t\t&s\t\t&d\t\t\n", num_to_college(a[0]), a[1]);
//	printf_s("2\t\t&s\t\t&d\t\t\n", num_to_college(b[0]), b[1]);
//	printf_s("3\t\t&s\t\t&d\t\t\n", num_to_college(c[0]), c[1]);
//
//}