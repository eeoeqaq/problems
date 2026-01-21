//employee.h

#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

class Employee {
private:
    char name[30];                //姓名
    char street[30];              //街道地址
    char city[18];                //城市
    char zip[7];                  //邮编
public:
    Employee(const char* n, const char* str, const char* ct,const char* z);   //构造函数
    void setName(char* n);                             //改变类中表示姓名属性的字符数组类型的数据成员
    void display();                                    //显示姓名、街道地址、城市和邮编

};
#endif // _EMPLOYEE_H_