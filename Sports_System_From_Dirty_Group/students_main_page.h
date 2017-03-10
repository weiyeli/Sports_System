#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"
#include "competition_item.h"
#include "login_operate.h"
#include "college.h"
#include "Show_Item_Sign_Up_Situation.h"
#include "grade_table.h"
#include <Windows.Applicationmodel.Activation.h>

//ȫ�ֱ���
char item_id[10];		//��������
char stu_ID[15];			//ѧ��ѧ��				
char bOrder = 'q';
char sOrder[20];
char account[20];
int flag = 1;

//�õ���ǰ���˺�
void get_Cur_Acc(char* account)
{
	strcpy(account, account);
}

void Show_Menu_Stu()
{
	system("cls");
	printf_s("*************************�˶������ϵͳ*************************\n");
	printf_s("***********************��ϵͳ����ָ������***********************\n");
	printf_s("1. ������Ŀ\n");
	printf_s("2. ��ѡ��Ŀ\n");
	printf_s("3. �鿴�������\n");
	printf_s("4. �鿴�������\n");
	printf_s("5. �鿴���˵÷�\n");
	printf_s("6. �鿴ѧԺ�÷�\n");
	printf_s("10. �˳�ϵͳ\n");
	printf_s("*****************************************************************\n\n");
	printf_s("����ָ�\n");
}

void Return_To_Main_Menu() {
	printf_s("�Ƿ񷵻���ҳ��: y/n\n");
	//getchar();
	scanf_s("%c", &bOrder);
	if (bOrder == 'y')
		Show_Menu_Stu();
	else flag = 0;
}


void Show_Stu_Main_Page()
{
	while (flag) {
		setColor(10, 0);
		int iOrder = -1;
		Show_Menu_Stu();
		setColor(6, 0);
		scanf_s("%d", &iOrder);

		switch (iOrder)
		{
		case 1: {
			while (flag)
			{
				Show_Com_info();
				getchar();
				printf_s("������Ҫ�����ı�������: ");
				gets_s(item_id);
				printf_s("������ѧ��: ");
				gets_s(stu_ID);

				////��ȫ���ж�
				//if (strcmp(stu_ID, account) != 0)
				//{
				//	printf_s("�磬�ⲻ�����ѧ�š�����\n");
				//	break;
				//}

				char a = 'q';
				printf_s("\nȷ��Ҫ����%s��? y/n\n", Find_Item_By_ID_Or_Nmae(item_id)->item_name);
				scanf_s("%c", &a);
				if (a == 'y') {
					Sign_Up_Item(item_id, stu_ID);
					printf_s("�����ɹ�!\n");
				}
				getchar();
				printf_s("�Ƿ��������: y/n\n");
				scanf_s("%c",&bOrder);
				if (bOrder != 'y'){
					Return_To_Main_Menu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}

		case 2:
		{
			while (flag)
			{
				printf_s("������Ҫ��ѡ����Ŀ����: ");
				getchar();
				gets_s(item_id);
				printf_s("���������ѧ��: ");
				gets_s(stu_ID);
				char a = 'q';
				printf_s("\nȷ��Ҫ��ѡ��? y/n\n");
				scanf_s("%c", &a);
				if (a == 'y') {
					DeleteStuData(Find_Grade_Table(item_id, stu_ID));
					printf_s("��ѡ�ɹ�!\n");

				}
				getchar();
				printf_s("�Ƿ��������: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					Return_To_Main_Menu();
					flag = 0;
				}	
			}
			flag = 1;
			break;
		}

		//�鿴�����������
		case 3: {
			while (flag)
			{
				getchar();
				printf_s("������Ҫ��ѯ����Ŀ����: ");
				gets_s(item_id);
				Find_Item_From_Grade_Table(item_id);
				printf_s("�Ƿ������ѯ: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					Return_To_Main_Menu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}

		//����ѧ����Ϣ
		case 4: {
			printf_s("����ɹ�\n");
			getchar();
			Return_To_Main_Menu();
			break;
		}
		
		//��ȡ�ļ���Ϣ
		case 5: {
			printf_s("��ȡ�ɹ�\n");
			getchar();
			Return_To_Main_Menu();
			break;
		}

		case 6: {
			while (flag)
			{
				
				printf_s("�Ƿ����ɾ��: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					Return_To_Main_Menu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}
		
		case 9: {
			Show_Stu_Data();
			getchar();
			Return_To_Main_Menu();
			break;
		}

		case 10: {
			flag = 0;
			break;
		}

		default: {
			printf_s("ָ������!\n");
			getchar();
			Return_To_Main_Menu();
			break;
		}
			
		}
	}
}