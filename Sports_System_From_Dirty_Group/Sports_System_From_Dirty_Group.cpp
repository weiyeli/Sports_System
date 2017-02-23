// Sports_System_From_Dirty_Group.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include "display.h"
#include "login.h"
#include "initialize_file.h"
#include "logic.h"
#define MAX 1000

int main()
{
	ReadSTUFromFile();
	display();
	Login();
}

