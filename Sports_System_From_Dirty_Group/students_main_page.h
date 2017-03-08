#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"
#include <Windows.Applicationmodel.Activation.h>

int college;  //Ñ§Ôº
char ID[20]; //Ñ§ºÅ
char Name[10];  //Ñ§ÉúĞÕÃû
int gender; //ĞÔ±ğ
char bOrder = 'q';
char sOrder[20];
int flag = 1;


void Show_Menu_Stu()
{
	system("cls");
	printf_s("*************************ÔË¶¯»á¹ÜÀíÏµÍ³*************************\n");
	printf_s("***********************±¾ÏµÍ³²Ù×÷Ö¸ÁîÈçÏÂ***********************\n");
	printf_s("1. ±¨ÃûÏîÄ¿\n");
	printf_s("2. ÍËÑ¡ÏîÄ¿\n");
	printf_s("3. ²é¿´±ÈÈü°²ÅÅ\n");
	printf_s("4. ²é¿´±ÈÈü½á¹û\n");
	printf_s("5. ²é¿´¸öÈËµÃ·Ö\n");
	printf_s("6. ²é¿´Ñ§ÔºµÃ·Ö\n");
	printf_s("10. ÍË³öÏµÍ³\n");
	printf_s("*****************************************************************\n\n");
	printf_s("ÊäÈëÖ¸Áî¿©\n");
}

void Return_To_Main_Menu() {
	printf_s("ÊÇ·ñ·µ»ØÖ÷Ò³Ãæ: y/n\n");
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
<<<<<<< HEAD
				Show_Com_info();
				printf_s("ÇëÊäÈëÒª±¨ÃûµÄ±ÈÈü´úÂë: ");
				gets_s(item_id);
				printf_s("ÇëÊäÈëÑ§ºÅ");
				gets_s(ID);
				Sign_Up_Item(ID,item_id);
=======
				
>>>>>>> parent of 084bebe... å¥½å¤šBugå•Š
				printf_s("ÊÇ·ñ¼ÌĞø±¨Ãû: y/n\n");
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
				printf_s("ÇëÊäÈëÑ§ÉúµÄÑ§ºÅ»òÕßĞÕÃû: \n");
				getchar();
				gets_s(sOrder);
				Show_Single_STU(Find_STU_By_ID_Or_Nmae(sOrder));
				printf_s("ÊÇ·ñ¼ÌĞø²éÑ¯: y/n\n");
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
				printf_s("ÇëÊäÈëÒªĞŞ¸ÄĞÅÏ¢µÄÑ§ÉúÑ§ºÅ»òĞÕÃû: ");
				getchar();
				gets_s(sOrder);
				Modify_Stu_Data(Find_STU_By_ID_Or_Nmae(sOrder));
				printf_s("ÊÇ·ñ¼ÌĞøĞŞ¸Ä: y/n\n");
				scanf_s("%c", &bOrder);
				if (bOrder != 'y') {
					Return_To_Main_Menu();
					flag = 0;
				}
			}
			flag = 1;
			break;
		}

		//±£´æÑ§ÉúĞÅÏ¢
		case 4: {
			printf_s("±£´æ³É¹¦\n");
			getchar();
			Return_To_Main_Menu();
			break;
		}
		
		//¶ÁÈ¡ÎÄ¼şĞÅÏ¢
		case 5: {
			printf_s("¶ÁÈ¡³É¹¦\n");
			getchar();
			Return_To_Main_Menu();
			break;
		}

		case 6: {
			while (flag)
			{
				printf_s("ÇëÊäÈëÒªÉ¾³ıµÄÑ§ÉúÑ§ºÅ»òĞÕÃû: ");
				getchar();
				gets_s(sOrder);
				char a = 'q';
				Show_Single_STU(Find_STU_By_ID_Or_Nmae(sOrder));
				printf_s("\nÈ·¶¨ÒªÉ¾³ıÕâÌõÑ§ÉúĞÅÏ¢Âğ? y/n\n");
				scanf_s("%c", &a);
				if (a == 'y') {
					DeleteStuData(Find_STU_By_ID_Or_Nmae(sOrder));
					printf_s("É¾³ı³É¹¦!\n");

				}
				getchar();
				printf_s("ÊÇ·ñ¼ÌĞøÉ¾³ı: y/n\n");
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
			printf_s("Ö¸ÁîÓĞÎó!\n");
			getchar();
			Return_To_Main_Menu();
			break;
		}
			
		}
	}

	Save_Stu_To_File();
	Free_Stu_LinkedData();
}