// study.h
#ifndef _STUDY_H_
#define _STUDY_H_
#include "config.h"

typedef struct Student
{
	long long num;  // ÿ��ѧ����ѧ��
	char name[MAX_LEN];  // ÿ��ѧ��������
	char course[MAX_LEN][COURSE_NUM];  // ÿ��ѧ��COURSE_NUM�Ź��ε����ƣ�����ÿ����Ŀ�ַ����Ȳ�����10 
	float score[COURSE_NUM];  // ÿ��ѧ��COURSE_NUM�Ź��εĳɼ�
	float credit[COURSE_NUM];  // ÿ��ѧ��COURSE_NUM�Ź��ε�ѧ��  
	float sum;  // ÿ��ѧ�Ƶ��ܳɼ�
	float aver;  // ÿ��ѧ����ƽ���ɼ�
	struct Student *next;
}STU;

int n, m;
int choice;
int start();
int menu();  // �����˵�
void print(STU *head, int n, int m);  // ��ӡ����
void printAver(STU *head, int n);
void averageEveryStudent(STU *head, int n, int m);  // ����ÿ��ѧ����ƽ����
void averageEveryCourse(STU *head, int n, int m);  // ����ÿ���γ̵��ֺܷ�ƽ����
void searchByNum(STU *head, int n, int m);  // ��ѧ�Ų�ѯѧ���������俼�Գɼ�
void searchByName(STU *head, int n, int m);  // ��������ѯѧ���������俼�Գɼ�
void statisticAnalysis(STU *head, int n, int m);  // ����𼰱������
void writeToFile(STU *head, int n, int m);  // ��ÿ��ѧ���ļ�¼��Ϣд���ļ�
STU *Creat(int n, int m);  // ��������¼����Ϣ
STU *Creat1(int n, int m);
STU *sortByScore(STU *head);  // ��ÿ��ѧ�����ܷ��ɸߵ����ų����α�
STU *sortByNum(STU *head);  // ��ѧ����С�����ų��ɼ���
STU *sortByName(STU *head);  // ���������ֵ�˳���ų��ɼ���
STU *deleteNode(STU *head);  // ɾ�������е�Ԫ�� 
STU *readFromFile(STU *head, int *n, int *m);  // ���ļ��ж���ÿ��ѧ���ļ�¼��Ϣ����ʾ

#endif

