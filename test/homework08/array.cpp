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
	int age;
	bool sex;
	char name[64];
};

Student *arr = nullptr;
int arrSize = 0;	//数组中元素个数
int arrCapacity = 0;	//数组容量

//当原先的数组已经塞满，就需要调用本函数扩容，以容纳继续插入的元素
void expandArray()
{
	if (arrCapacity == 0)
	{
		arrCapacity = 1;
		arr = new Student[arrCapacity];
	}
	else
	{
		int newCapacity = arrCapacity * 2;
		Student *newArr = new Student[newCapacity];
		//请填写程序
		//上面已新建两倍容量的数组，newArr指向它
		memcpy(newArr,arr,sizeof(*arr));
		//新数组仍为空，arr仍指向旧的数组，请考虑要做什么
		arr = newArr;
		arrCapacity = newCapacity;
	}
}

void addStudentToArray(Student *s)
{
	if (arrSize == arrCapacity)
		expandArray();
	int index;
	for (index = 0; index < arrSize; index++)
		if (arr[index].id > s->id)
			break;
	//请填写程序
	//如果数组已满，上面已经完成扩容，所以此处不必担心容量问题
	for(int i=arrSize;i>=index;i--){
		arr[i+1]=arr[i];
	}
	arr[index]=*s;
	arrSize+=1;

	//现有数组已排好序，index表示什么？
	//找到插入位置后，还要把后面的所有元素向后拉一格，为s腾出格子
}

int main()
{
	clock_t startTime, endTime;
	startTime = clock();
	for (int i = 0; i < LOOP_COUNT; i++)
	{
		Student *s = new Student;
		s->id = rand();
		s->age = 20;
		addStudentToArray(s);
		delete s;
	}
	endTime = clock();

#ifndef LARGE_AMOUNT
	for (int i = 0; i < arrSize; i++)
		cout << arr[i].id << " --> ";
	cout << endl;
#endif

	delete[] arr;

	cout << "Array capacity: " << arrCapacity << endl
		 << "Array size: " << arrSize << endl;
	cout << "Time cost: " << endTime - startTime << endl;
	cout<<"孙锦康_2025302114254"<<endl;
	return 0;
}




/*非常抱歉，
我的调试输出系统有些问题！！
暂时不能贴出结果。*/