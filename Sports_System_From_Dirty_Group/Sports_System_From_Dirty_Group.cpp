// Sports_System_From_Dirty_Group.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include "login_page.h"
#include "login_operate.h"
#include "initialize_file.h"
#include "students.h"
#define MAX 1000

int main()
{
	ReadSTUFromFile();
	display();
	Login();
}

