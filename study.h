// study.h
#ifndef _STUDY_H_
#define _STUDY_H_
#include "config.h"

typedef struct Student
{
	long long num;  // 每个学生的学号
	char name[MAX_LEN];  // 每个学生的姓名
	char course[MAX_LEN][COURSE_NUM];  // 每个学生COURSE_NUM门功课的名称，假设每个科目字符长度不超过10 
	float score[COURSE_NUM];  // 每个学生COURSE_NUM门功课的成绩
	float credit[COURSE_NUM];  // 每个学生COURSE_NUM门功课的学分  
	float sum;  // 每个学科的总成绩
	float aver;  // 每个学生的平均成绩
	struct Student *next;
}STU;

int n, m;
int choice;
int start();
int menu();  // 创建菜单
void print(STU *head, int n, int m);  // 打印函数
void printAver(STU *head, int n);
void averageEveryStudent(STU *head, int n, int m);  // 计算每门学生的平均分
void averageEveryCourse(STU *head, int n, int m);  // 计算每个课程的总分和平均分
void searchByNum(STU *head, int n, int m);  // 按学号查询学生排名及其考试成绩
void searchByName(STU *head, int n, int m);  // 按姓名查询学生排名及其考试成绩
void statisticAnalysis(STU *head, int n, int m);  // 按类别及比例输出
void writeToFile(STU *head, int n, int m);  // 将每个学生的纪录信息写入文件
STU *Creat(int n, int m);  // 创建链表并录入信息
STU *Creat1(int n, int m);
STU *sortByScore(STU *head);  // 按每个学生的总分由高到低排出名次表
STU *sortByNum(STU *head);  // 按学号由小到大排出成绩表
STU *sortByName(STU *head);  // 按姓名的字典顺序排出成绩表
STU *deleteNode(STU *head);  // 删除链表中的元素 
STU *readFromFile(STU *head, int *n, int *m);  // 从文件中读出每个学生的纪录信息并显示

#endif

