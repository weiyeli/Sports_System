
#include <stdio.h>
#include "login_page.h"
#include <windows.h>

//һЩ��ֵ�ȫ�ֱ�����������
//int flag = 1;


void Show_Tea_Menu()
{
	system("cls");
	printf_s("*************************�˶������ϵͳ*************************\n");
	printf_s("*************************�װ�������ʦ����*************************\n");
	printf_s("***********************��ϵͳ����ָ������***********************\n");
	printf_s("1. ��������\n");
	printf_s("2. ¼������ɼ�\n");
	printf_s("3. �鿴�������\n");
	printf_s("4. �鿴������Ŀ��Ϣ\n");
	printf_s("5. ������\n");
	printf_s("6. ������\n");
	printf_s("7. ������\n");
	printf_s("8. ������\n");
	printf_s("9. ������\n");
	printf_s("10. �˳�ϵͳ\n");
	printf_s("*****************************************************************\n\n");
	printf_s("����ָ�\n");
}

void ReturnToTeaMainMenu() {
	printf_s("�Ƿ񷵻���ҳ��: y/n\n");
	//getchar();
	scanf_s("%c", &bOrder);
	if (bOrder == 'y')
		Show_Tea_Menu();
	else flag = 0;
}

void Show_Tea_Main_Page()
{
	/*while (flag) {
		setColor(10, 0);
		int iOrder = -1;
		setColor(6, 0);
		scanf_s("%d", &iOrder);

		switch (iOrder)
		{
		case 2: {


		}
		}
	}*/
}