#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logic.h"
#include <windows.h>
#include <Windows.Applicationmodel.Activation.h>

char ID[20]; //ѧ��
char Name[10];  //ѧ������
int gender; //�Ա�
float Mark_Running;
float Mark_Jumping;
float Mark_shot;
char bOrder = 'q';
char sOrder[20];
int flag = 1;

void setColor(unsigned short ForeColor = 7, unsigned short BackGroundColor = 0)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  //��ȡ��ǰ���ھ��
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);  //������ɫ
}


//���ù��λ��
void SetPos(int x, int y)
{
	COORD pos;
	HANDLE handle;
	pos.X = x;
	pos.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

void login_page()
{
	SetPos(25, 0);
	setColor(10, 0);
	printf_s("******************��ӭʹ���˶������ϵͳ******************\n");
	SetPos(20, 5);
	setColor(12, 0);
	printf_s("�˺�: \n");
	SetPos(20, 6);
	printf_s("����: \n");
	setColor(10, 0);
}

void Show_Menu()
{
	system("cls");
	printf_s("*************************�˶������ϵͳ*************************\n");
	printf_s("***********************��ϵͳ����ָ������***********************\n");
	printf_s("1. ����һ��ѧ����Ϣ\n");
	printf_s("2. ����ָ����ѧ����Ϣ(����/ѧ��)\n");
	printf_s("3. �޸�ָ��ѧ������Ϣ\n");
	printf_s("4. ����ѧ����Ϣ���ļ���\n");
	printf_s("5. ��ȡ�ļ��е�ѧ����Ϣ\n");
	printf_s("6. ɾ��ָ��ѧ������Ϣ\n");
	printf_s("7. �ָ�ɾ����ѧ����Ϣ\n");
	printf_s("8. ��ʾ��Ŀ�������\n");
	printf_s("9. ��ʾ����ѧ����Ϣ\n");
	printf_s("10. �˳�ϵͳ\n");
	printf_s("*****************************************************************\n\n");
	printf_s("����ָ�\n");
}

void ReturnToMainMenu() {
	printf_s("�Ƿ񷵻���ҳ��: y/n\n");
	//getchar();
	scanf_s("%c", &bOrder);
	if (bOrder == 'y')
		Show_Menu();
	else flag = 0;
}


void Show_Main_Page()
{
	while (flag) {
		setColor(10, 0);
		int iOrder = -1;
		Show_Menu();
		setColor(6, 0);
		scanf_s("%d", &iOrder);

		switch (iOrder)
		{
		case 1: {
			while (flag)
			{
				//���ѧ����Ϣ
				printf_s("����ѧ��: ");
				getchar();
				gets_s(ID);
				printf_s("��������: ");
				gets_s(Name);
				printf_s("�����Ա�(��1/Ů0): ");
				scanf_s("%d", &gender);
				printf_s("����100�׳ɼ�(��λ: ��),δ�μ���������: ");
				scanf_s("%f", &Mark_Running);
				printf_s("������Զ�ɼ�(��λ: ��),δ�μ���������: ");
				scanf_s("%f", &Mark_Jumping);
				printf_s("����Ǧ��ɼ�(��λ: ��)��δ�μ���������: ");
				scanf_s("%f", &Mark_shot);
				getchar();
				AddStuMSG(ID, Name, gender, Mark_Running, Mark_Jumping, Mark_shot);
				printf_s("�Ƿ��������: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					ReturnToMainMenu();
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
				printf_s("������ѧ����ѧ�Ż�������: \n");
				getchar();
				gets_s(sOrder);
				showSingleSTU(FindSTUByIDOrNmae(sOrder));
				printf_s("�Ƿ������ѯ: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					ReturnToMainMenu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}


		case 3: {
			while (flag)
			{
				printf_s("������Ҫ�޸���Ϣ��ѧ��ѧ�Ż�����: ");
				getchar();
				gets_s(sOrder);
				ModifyStuData(FindSTUByIDOrNmae(sOrder));
				printf_s("�Ƿ�����޸�: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					ReturnToMainMenu();
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
			ReturnToMainMenu();
			break;
		}

				//��ȡ�ļ���Ϣ
		case 5: {
			printf_s("��ȡ�ɹ�\n");
			getchar();
			ReturnToMainMenu();
			break;
		}

		case 6: {
			while (flag)
			{
				printf_s("������Ҫɾ����ѧ��ѧ�Ż�����: ");
				getchar();
				gets_s(sOrder);
				char a = 'q';
				showSingleSTU(FindSTUByIDOrNmae(sOrder));
				printf_s("\nȷ��Ҫɾ������ѧ����Ϣ��? y/n\n");
				scanf_s("%c", &a);
				if (a == 'y') {
					DeleteStuData(FindSTUByIDOrNmae(sOrder));
					printf_s("ɾ���ɹ�!\n");

				}
				getchar();
				printf_s("�Ƿ����ɾ��: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					ReturnToMainMenu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}

		case 9: {
			ShowStuData();
			getchar();
			ReturnToMainMenu();
			break;
		}

		case 10: {
			flag = 0;
			break;
		}

		default: {
			printf_s("ָ������!\n");
			getchar();
			ReturnToMainMenu();
			break;
		}

		}
	}

	SaveStuToFile();
	FreeLinkedData();
}