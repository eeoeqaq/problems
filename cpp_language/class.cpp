#include <iostream>
#include<algorithm>
using namespace std;

class clock{
public:
void set_time(int hour=0,int min=0,int sec=0);
void show_time(){
    cout<<hour<<":"<<minute<<":"<<second<<endl;
};
//构造函数
clock(int new_hour,int new_min,int new_sec);
//复制构造函数
clock(const clock &p);
//移动构造函数
clock(clock&& a):second(move(a.second)),
minute(move(a.minute)),hour(move(a.hour)){}
//成员函数重载运算符
bool operator<(const clock& a)const;
clock& operator++();
clock operator++(int);
//友元函数重载运算符
friend bool operator>(const clock& a,const clock&b);
//一个转换函数
operator myclock();
private:
int hour;int minute;int second;
};

class myclock: public clock{
    int a,b;
    public:
    myclock():clock(0,0,0),a(0),b(0){}
    myclock(int a1,int b1):clock(0,0,0),a(a1),b(b1){}
};

clock::operator myclock(){
    return myclock(hour, minute);
}

int main(){
    myclock a;
    clock&& k=move(a);
    clock b(k);
}

clock::clock(int new_hour,int new_min,int new_sec):hour(new_hour),minute(new_min),second(new_sec){}
clock::clock(const clock &p){
    hour=p.hour;
    minute=p.minute;
    second=p.second;    
}

clock::clock(clock&& a){

}

bool clock::operator<(const clock& a)const{
    if(this->hour<a.hour){
        return true;
    }else if(this->minute<a.minute){
        return true;
    }else if(this->second<a.second){
        return true;
    }
    return false;
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
    binary_tree(int income,int *left_son_node,int *right_son_node):
    a(income),left_tree(left_son_node),right_tree(right_son_node){}
};

bool operator>(const clock& a,const clock&b){
    if(a.hour>b.hour){
        return true;
    }else if(a.minute>b.minute){
        return true;
    }else if(a.second>b.second){
        return true;
    }
    return false;
}

clock& clock::operator++(){
    second++;
    if(second>=60){
        second-=60;
        minute++;
        if(minute>=60){
            minute-=60;
            hour++;
            if(hour>=24){
                hour-=24;
            }
        }
    }
    return *this;
}

clock clock::operator++(int){
    clock old=*this;
    ++(*this);
    return old;
}


class s{
    public:
    string a;
    //移动构造函数
    s()=delete;
    s(s && s1):a(move(s1.a)){}
};
void * a;
auto x=static_cast<int *>(a);
s s1;
s s2(move(s1));