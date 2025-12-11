#include <iostream>
using namespace std;

class clock{
public:
void set_time(int hour=0,int min=0,int sec=0);
void show_time(){
    cout<<hour<<":"<<minute<<":"<<second<<endl;
};
//构造函数：
clock(int new_hour,int new_min,int new_sec);
clock(clock &p);
private:
int hour;int minute;int second;
};

clock::clock(int new_hour,int new_min,int new_sec):hour(new_hour),minute(new_min),second(new_sec){}
clock::clock(clock &p){
    hour=p.hour;
    minute=p.minute;
    second=p.second;    
}

void clock::set_time(int new_hour,int new_min,int new_sec){
    hour =new_hour;
    minute=new_min;
    second=new_sec;
}
struct binary_tree
{   int a;
    int *left_tree;
    int *right_tree;
    //构造函数
    binary_tree(int income,int *left_son_node,int *right_son_node):a(income),left_tree(left_son_node),right_tree(right_son_node){}
};


//友元函数

class a
{
    friend clock
private:
    static int cnt;
    char * name;
public:
 a(/* args */);
     a();
};
a::a(/* args */)
{

}
a::a()
{

}
