#include <iostream>
using namespace std;

class A{
    public:
	static int a;//静态成员变量
	static int b(int i);//静态成员函数
	int c;//成员变量
	int d(int i);//成员函数
};

int A::a=100;
int* p = &A::a; 
//语法：函数指针
int (*pf)(int) = &A::b;
//作用域下的变量指针
int A::* px= &A::c;
//作用域下的函数指针
int (A::*pf2)(int)=&A::d;

int main() {
    
    A examp{100};
    cout<<examp.*px;//100
    A* pa=&examp;
    cout<<pa->*px;//100
    int bf=(examp.*pf2)(1000);
    int bf=(pa->*pf2)(1000);

    return 0;
}


int * a=nullptr;