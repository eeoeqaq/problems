#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

//#define LARGE_AMOUNT

#ifdef LARGE_AMOUNT
#define LOOP_COUNT 40000
#else
#define LOOP_COUNT 40
#endif

struct Student
{
	int id;
	bool sex;
	char name[64];
	Student *next;
};

Student *head = nullptr;

void addStudentToList(Student *s)
{
	if (head == nullptr)
	{
		head = s;
		s->next = nullptr;
	}
	else if (s->id <= head->id)
	{
		s->next = head;
		head = s;
	}
	else
	{
		Student *f1 = head->next, *f2 = head;
		//请填写程序
		while(f1->id>s->id && f2->id>s->id &&f1!=nullptr){
			f2=f1;f1=f1->next;
		}
		s->next=f1;f2->next=s;
		//以上两个分支都不成立，说明head指向某个元素，且s的id大于头元素id
		//现有数组已排好序，s应该插入到什么位置，才能维持顺序？
		//f1和f2分别指向链表中两个相邻的元素，这对于“插入”操作有什么帮助？
	}
}

int main()
{
	clock_t startTime, endTime;
	startTime = clock();
	for (int i = 0; i < LOOP_COUNT; i++)
	{
		Student *s = new Student;
		s->id = rand();
		addStudentToList(s);
	}
	endTime = clock();

#ifndef LARGE_AMOUNT
	for (Student *p = head; p != nullptr; p = p->next)
		cout << p->id << " --> ";
	cout << endl;
#endif

	Student *q, *p = head;
	while (p != nullptr)
	{
		q = p;
		p = p->next;
		delete q;
	}

	cout << "Time cost: " << endTime - startTime << endl;
	cout<<"孙锦康_2025302114254"<<endl;
	return 0;
}
