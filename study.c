// study.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "malloc.h"
#include "study.h"

int menu()
{
	system("title Student achievement management system");
	printf("*****************************************************\n");
	printf("*                                                   *\n");
	printf("*         Student score management system           *\n");
	printf("*                                                   *\n");
	printf("*****************************************************\n");
	printf("*      Student score management                     *\n");
	printf("*      1.the input results                          *\n");
	printf("*      2.calculate the student average              *\n");
	printf("*      3.calculate the course  average              *\n");
	printf("*      4.sort by descending score                   *\n");
	printf("*      5.sort by student ID in ascending order      *\n");
	printf("*      6.sort by name in the dictionary             *\n");
	printf("*      7.search by student ID                       *\n");
	printf("*      8.search by name                             *\n");
	printf("*      9.delete student information                 *\n");
	printf("*      10.statistic analysis                        *\n");
	printf("*      11.print student scores                      *\n");
	printf("*      12.write to flie                             *\n");
	printf("*      13.read from a file                          *\n");
	printf("*      0.exit                                       *\n");
	printf("*****************************************************\n");
	puts("");
	printf("Please enter your operation:");
	scanf("%d", &choice);
	return choice;
}

int start()
{
	STU *head = (STU*)malloc(sizeof(LEN));
	while (1)
	{
		choice = menu();
		if (choice == 1)
		{
			system("cls");  //清屏
			printf("*****************************************************\n");
			printf("Please enter the number of students(n < %d):\n", STU_NUM);
			scanf("%d", &n);
			printf("Please enter the number of subjects(m <= %d):\n", COURSE_NUM);
			scanf("%d", &m);
		}
		switch (choice)
		{
		case 1:
			printf("Enter student ID, name, subject, grade and credit:\n");
			head = Creat(n, m);
			system("cls");  //清屏
			break;
		case 2:
			system("cls");  //清屏
			averageEveryStudent(head, n, m);
			break;
		case 3:
			system("cls");  //清屏
			averageEveryCourse(head, n, m);
			break;
		case 4:
			system("cls");  //清屏
			puts("");
			printf("#####################################################\n");
			printf("Sort by descending score:\n");
			head = sortByScore(head);
			printAver(head, n);
			break;
		case 5:
			system("cls");  //清屏
			puts("");
			printf("#####################################################\n");
			printf("Sort by student id in ascending order:\n");
			head = sortByNum(head);
			printAver(head, n);
			break;
		case 6:
			system("cls");  //清屏
			puts("");
			printf("#####################################################\n");
			printf("Sort by name in the dictionary:\n");
			head = sortByName(head);
			printAver(head, n);
			break;
		case 7:
			system("cls");  //清屏
			puts("");
			printf("#####################################################\n");
			printf("Enter the ID of the student you want to find:\n");
			searchByNum(head, n, m);
			break;
		case 8:
			system("cls");  //清屏
			puts("");
			printf("#####################################################\n");
			printf("Enter the name of the student you want to find:\n");
			searchByName(head, n, m);
			break;
		case 9:
			system("cls");  //清屏
			puts("");
			printf("#####################################################\n");
			printf("Enter the student ID of the student you want to delete:\n");
			head = deleteNode(head);
			printAver(head, n);
			break;
		case 10:
			system("cls");  //清屏
			statisticAnalysis(head, n, m);
			break;
		case 11:
			system("cls");  //清屏
			puts("");
			print(head, n, m);
			break; 
		case 12:
			system("cls");  //清屏
			writeToFile(head, n, m);
			break;
		case 13:
			system("cls");  //清屏
			head = readFromFile(head, &n, &m);
			break;
		case 0:
			system("cls");  //清屏
			puts("");
			printf("*****************************************************\n");
			printf("End of program!\n");
			printf("*****************************************************\n");
			return 0;
		default:
			system("cls");  //清屏
			puts("");
			printf("*****************************************************\n");
			printf("The input is incorrect. \nPlease enter a number from 0 to 13!\n");
			printf("*****************************************************\n");

		}
	}
}

STU *Creat(int n, int m) {
	STU *head;
	STU *p1, *p2;
	int i, j;
	for (i = 1; i < n + 1; ++ i)
	{
		p1 = (STU *)malloc(LEN);
		printf("Please enter student ID of NO.%d \n", i);
		scanf("%lld", &p1->num);
		printf("Please enter student name of NO.%d\n", i);
		scanf("%s", p1->name);
			
		for (j = 0; j < m; ++ j)
		{
			printf("Please enter subject examination of NO.%d\n", (j + 1));
			scanf("%s", p1->course[j]);
			printf("Please enter score of %s\n", p1->course);
			scanf("%f", &p1->score[j]);
			printf("Please enter credit of %s\n", p1->course);
			scanf("%f", &p1->credit[j]);
		}
		p1->next = NULL;
		if (i == 1)
		{
			head = p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
	}
	return(head);
}

STU *Creat1(int n, int m)
{
	STU *head;
	STU *p1, *p2;
	int i, j;
	for (i = 1; i < n + 1; ++ i)
	{
		p1 = (STU *)malloc(LEN);
		p1->next = NULL;
		if (i == 1)
		{
			head = p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
	}
	return(head);
}

void  averageEveryStudent(STU *head, int n, int m)
{
	STU *p;
	int i, j;
	float creditSum;
	p = head;
	if (head != NULL)
	{
		puts("");
		printf("=====================================================\n");
		for (i = 0; i < n; i++)
		{
			p->sum = 0.0;
			creditSum = 0.0;
			for (j = 0; j < m; j++)
			{
				p->sum += ((p->score[j]) * (p->credit[j]));
				creditSum += p->credit[j];
			}
			p->aver = p->sum / creditSum;
			
			printf("%s's aver =%.2f\n", p->name, p->aver);
				
			p = p->next;
		}
		printf("=====================================================\n");
	}
}

void  averageEveryCourse(STU *head, int n, int m)
{
	STU *p;
	int i, j;
	float sum;
	p = head;
	if (head != NULL)
	{
		printf("=====================================================\n");
		for (i = 0; i < m; ++ i)
		{
			p = head;
			sum = 0.0;
			for (j = 0; j < n; ++ j)
			{
				sum += p->score[i];
				p = p->next;		
			}
			printf("The %s aver =%.2f\n", head->course[i], sum / n);
		}
		printf("=====================================================\n");
	}
}

STU  *sortByScore(STU *head)
{
	STU *p1, *p2;
	STU tmp;
	p2 = head;
	
	while (p2->next != NULL)
	{
		p1 = p2->next;
		while (p1 != NULL)
		{
			if (p2->aver < p1->aver)
			{
				tmp = *p2;
				*p2 = *p1;
				*p1 = tmp;
				tmp.next = p2->next;
				p2->next = p1->next;
				p1->next = tmp.next;
			}
			p1 = p1->next;
		}
		p2 = p2->next;
	}
	return head;
}

STU *sortByNum(STU *head)
{
	STU *p1, *p2;
	STU tmp;
	p2 = head;
	
	while (p2->next != NULL)
	{
		p1 = p2->next;
		while (p1 != NULL)
		{
			if (p2->num > p1->num)
			{
				tmp = *p2;
				*p2 = *p1;
				*p1 = tmp;
				tmp.next = p2->next;
				p2->next = p1->next;
				p1->next = tmp.next;
			}
			p1 = p1->next;
		}
		p2 = p2->next;
	}
	return head;
}

STU  *sortByName(STU *head)
{
	STU *p1, *p2;
	STU tmp;
	p2 = head;
	
	while (p2->next != NULL)
	{
		p1 = p2->next;
		while (p1 != NULL)
		{
			
			if (strcmp(p1->name, p2->name) < 0)
			{
				tmp = *p2;
				*p2 = *p1;
				*p1 = tmp;
				tmp.next = p2->next;
				p2->next = p1->next;
				p1->next = tmp.next;
			}
			p1 = p1->next;
		}
		p2 = p2->next;
	}
	return head;
}

void  searchByNum(STU *head, int n, int m)
{
	long num;
	int i;
	int flag = 1;
	scanf("%lld", &num);
	STU *p;
	p = head;
	if (head != NULL)
	{
		printf("=====================================================\n");	
		do {
			if (p->num == num)
			{
				printf("ID\t\tname\tcourse\tscore\tcredit\taver\n");
				for (i = 0; i < m; ++ i)
				{
					printf("%lld\t%s\t", p->num, p->name);
					printf("%s\t", p->course[i]);
					printf("%.2f\t", p->score[i]);
					printf("%.2f\t", p->credit[i]);
					printf("%.2f\t", p->aver);
					puts("");
				}
				flag = 0;
			}
			p = p->next;
		} while (p != NULL);
		
		if (flag)
			printf("The student ID you entered was not found!\n");
	}
	printf("=====================================================\n");
}

void  searchByName(STU *head, int n, int m)
{
	char name[MAX_LEN];
	int i;
	int flag = 1;
	scanf("%s", name);
	STU *p;
	p = head;
	if (head != NULL)
	{
		printf("=====================================================\n");
		do {
			if (strcmp(name, p->name) == 0)
			{
				printf("ID\t\tname\tcourse\tscore\tcredit\taver\n");
				for (i = 0; i < m; ++ i)
				{
					printf("%lld\t%s\t", p->num, p->name);
					printf("%s\t", p->course[i]);
					printf("%.2f\t", p->score[i]);
					printf("%.2f\t", p->credit[i]);
					printf("%.2f\t", p->aver);
					puts("");
				}
				flag = 0;
			}
			p = p->next;

		} while (p != NULL);
		if (flag)
			printf("The student name you entered was not found!\n");
	}
	printf("=====================================================\n");

}

STU *deleteNode(STU *head)
{
	STU *p1,*p2;
	long tmp;
    p1 = head;
    printf("=====================================================\n");
    if (head->next == NULL)
    {
        printf("The list is empty\n");
        printf("=====================================================\n");
        return NULL;
    }
    
    scanf("%lld", &tmp);
    while(p1->num != tmp && p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }
    if(p1->num == tmp)
    {
        if(p1 == head)
        {
            head = p1->next;
        }
        else
        {
            p2->next = p1->next;
        }
        printf("successfully delete\n");
        n --;
        free(p1);
    }
    else
    {
        printf("The node you want to delete was not found\n");
    }
    printf("=====================================================\n");
	return head;
}

void  statisticAnalysis(STU *head, int n, int m)
{
	int a[9];
	STU *p;
	p = head;
	int i, j, k;
	int temp;
	char ch[MAX_LEN]; 
	
	for (i = 0; i < m; ++ i)
	{
		p = head;
		memset(a, 0, sizeof a);
		
		for (j = 0; j < n; ++ j)
		{
			strcpy(ch, p->course[i]);
			temp = p->score[i];
			
			if (temp < 60.0)
				a[0]++;
			else if (temp < 66.0)
				a[1]++;
			else if (temp < 70.0)
				a[2]++;
			else if (temp < 76.0)
				a[3]++;
			else if (temp < 80.0)
				a[4]++;
			else if (temp < 86.0)
				a[5]++;
			else if (temp < 90.0)
				a[6]++;
			else if (temp < 96.0)
				a[7]++;
			else
				a[8]++;
			p = p->next;
		}
			
		puts("");
		printf("=====================================================\n");
		printf("* course %s:\n", ch);
		printf("* %d students in category E,accounting for %.2f%% of all students\n", a[0], 100.0 * a[0] / n);
		printf("* %d students in category D,accounting for %.2f%% of all students\n", a[1], 100.0 * a[1] / n);
		printf("* %d students in category D+,accounting for %.2f%% of all students\n", a[2], 100.0 * a[2] / n);
		printf("* %d students in category C,accounting for %.2f%% of all students\n", a[3], 100.0 * a[3] / n);
		printf("* %d students in category C+,accounting for %.2f%% of all students\n", a[4], 100.0 * a[4] / n);
		printf("* %d students in category B,accounting for %.2f%% of all students\n", a[5], 100.0 * a[5] / n);
		printf("* %d students in category B+,accounting for %.2f%% of all students\n", a[6], 100.0 * a[6] / n);
		printf("* %d students in category A,accounting for %.2f%% of all students\n", a[7], 100.0 * a[7] / n);
		printf("* %d students in category A+,accounting for %.2f%% of all students\n", a[8], 100.0 * a[8] / n);
		printf("=====================================================\n");

	}
}

void print(STU *head, int n, int m)
{
	STU *p, stu[m];
	int i, j;
	p = head;

	if (head != NULL)
	{
		printf("=====================================================\n");
		printf("ID\t\tname\tcourse\tscore\tcredit\taver\n");
		for (i = 0; i < n; ++ i)
		{	
			for (j = 0; j < m; ++ j)
			{
				printf("%lld\t%s\t", p->num, p->name);
				printf("%s\t", p->course[j]);
				printf("%.2f\t", p->score[j]);
				printf("%.2f\t", p->credit[j]);
				printf("%.2f\t", p->aver);
				puts("");
			}
			p = p->next;
		}
		printf("=====================================================\n");
		printf("If the average score is zero, \nplease enter 2 to calculate the average score\n");
		printf("=====================================================\n");
	}
}

void printAver(STU *head, int n)
{
	STU *p;
	int i;
	p = head;

	if (head != NULL)
	{
		printf("=====================================================\n");
		printf("ID\t\tname\taver\n");
		for (i = 0; i < n; ++ i)
		{
			printf("%lld\t%s\t", p->num, p->name);
			printf("%.2f\t", p->aver);
			puts("");
			p = p->next;
		}
		printf("=====================================================\n");
		printf("If the average score is zero, \nplease enter 2 to calculate the average score\n");
		printf("=====================================================\n");
	}
}

void  writeToFile(STU *head, int n, int m)
{
	STU *p;
	p = head;
	FILE *fp;
	int i;
	puts("");
	printf("=====================================================\n");
	if ((fp = fopen("stu.txt", "w")) == NULL)
	{
		printf("Fail to open stu.txt文件\n");
		return;
	}
	fprintf(fp, "number\tcourse\n");
	fprintf(fp, "%d\t%d\n", n, m);
	fprintf(fp, "ID\t\tname\tcourse\tscore\tcredit\taver\n");
	for (i = 0; i < n; ++ i)
	{
		fprintf(fp, "%lld\t\t%s\t", p->num, p->name);
		fprintf(fp, "%12s\t", p->course[i]);
		fprintf(fp, "%12.2f\t", p->score[i]);
		fprintf(fp, "%12.2f\t\n", p->credit[i]);
	}
	p = p->next;

	printf("Input Successfully!!\n");
	fclose(fp);
	printf("=====================================================\n");

}


//生成了一个新的链表，直接读取存好的数据
STU *readFromFile(STU *head, int *n, int *m)
{
	STU *p;
	FILE *fp;
	int i, j;
	if ((fp = fopen("student.txt", "r")) == NULL)
	{
		printf("Fail to open student.txt\n");
		return NULL;
	}
	fscanf(fp, "%d\t%d\n", n, m);
	head = Creat1(*n, *m);  //创建了一个空链表，并且赋给head
	p = head;
	for (i = 0; i < *n; ++ i)
	{
		fscanf(fp, "%lld", &p->num);
		fscanf(fp, "%s", &p->name);
		for (j = 0; j < *m; ++ j)
		{
			fscanf(fp, "%s", &p->course[j]);
			fscanf(fp, "%f", &p->score[j]);
			fscanf(fp, "%f", &p->credit[j]);
		}
		p = p->next;
	}
	i = *n;
	j = *m;
	printf("Input Successfully!\n");
	fclose(fp);

	print(head, i, j);

	return head;
}


