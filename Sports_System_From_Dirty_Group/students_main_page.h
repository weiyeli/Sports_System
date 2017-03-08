#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"
#include "competition_item.h"
#include <Windows.Applicationmodel.Activation.h>

//ȫ�ֱ���
char item_id[3];			//��������
char stu_id[15];			//ѧ��ѧ��				
char bOrder = 'q';
char sOrder[20];
int flag = 1;


void Show_Menu_Stu()
{
	system("cls");
	printf_s("*************************�˶������ϵͳ*************************\n");
	printf_s("***********************��ϵͳ����ָ������***********************\n");
	printf_s("1. ������Ŀ\n");
	printf_s("2. ��ѡ��Ŀ\n");
	printf_s("3. �鿴��������\n");
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
		Read_Item_From_File();
		Read_STU_From_File();
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
				printf_s("������ѧ��");
				gets_s(stu_id);
				Sign_Up_Item(stu_id, item_id);
				printf_s("�����ɹ�!");
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
				return;
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


		case 3: {
			while (flag)
			{
				return;
				printf_s("�Ƿ�����޸�: y/n\n");
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
				return;
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

	Save_Stu_To_File();
	Free_Stu_LinkedData();
	Free_Item_LinkedData(); 
}