// Sports_System_From_Dirty_Group.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include "display.h"
#define MAX 1000


struct Student
{
	char ID[20]; //学号
	char Name[10];  //学生姓名
	bool gender; //性别
	float Mark_Running;
	float Mark_Juming;
	float Mark_shot;
	float Credits; //积分
};

struct Student students[100];



int main()
{
	display();
}

