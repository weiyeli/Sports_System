// Sports_System_From_Dirty_Group.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include "login_page.h"
#include "login_operate.h"
#include "initialize_file.h"
#include "students.h"
#include "grade_table.h"
#define MAX 1000

int main()
{
	Read_Item_From_File();
	Read_STU_From_File();
	Read_Grade_Table_From_File();
	display();
	Login();
	Save_Grade_Table_To_File();
	Save_Item_To_File();
	Save_Stu_To_File();
	Free_Stu_LinkedData();
	Free_Item_LinkedData();
	Free_Grade_LinkedData();
}

