#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"

typedef struct item
{
	int id;							//项目代码
	char item_name[10];		//项目名称
	int item_nature;			//项目性质,1代表田赛,2代表径赛
	char item_time[10];			    //比赛时间
	char item_location[10];			//比赛地点
	STUNODE* stu[100] = { NULL };				//参加该项目的某个学生
	//int item_number_of_students;  //参加比赛的学生人数
	float item_grade = 0;			//比赛成绩
	int item_score = 0;				//个人得分;
	item* pNext = NULL;;					//下一个参加该项目的学生个体
}ITEMNODE;

//声明链表的头和尾
ITEMNODE* i_pHead = NULL;
ITEMNODE* i_pEnd = NULL;


//注册一个比赛项目
void register_item(int id, char* item_name, int item_nature, char* item_time, char* item_location) {
	ITEMNODE* pNode = (ITEMNODE*)malloc(sizeof(ITEMNODE));	 //申请一个项目
	pNode->id = id;
	strcpy(pNode->item_name, item_name);
	pNode->item_nature = item_nature;
	strcpy(pNode->item_time, item_time);
	strcpy(pNode->item_location, item_location);

	//头和尾指针都指向首节点
	i_pHead = pNode;
	i_pEnd = pNode;
}


//项目报名
void sign_up_item(STUNODE* pNode, ) {

}