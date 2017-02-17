#pragma once
#include <stdio.h>
#include <windows.h>

void setColor(unsigned short ForeColor = 7, unsigned short BackGroundColor = 0)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  //获取当前窗口句柄
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);  //设置颜色
}


//设置光标位置
void SetPos(int x, int y)
{
	COORD pos;
	HANDLE handle;
	pos.X = x;
	pos.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

void display()
{
	SetPos(25,0);
	setColor(10, 0);
	printf_s("******************欢迎使用运动会管理系统******************\n");
	SetPos(20,5);
	setColor(12,0);
	printf_s("账号: \n");
	SetPos(20, 6);
	printf_s("密码: \n");
	setColor(10, 0);
}