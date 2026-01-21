#include <iostream>
#include <cstring>
using namespace std;

// 日期类（内嵌子对象）
class date {
public:
    int y, m, d;

    date() : y(0), m(0), d(0) {}
    date(int ny, int nm, int nd) : y(ny), m(nm), d(nd) {}
    // 复制构造
    date(const date& other) : y(other.y), m(other.m), d(other.d) {}

    void show() const {
        cout << y << "-" << m << "-" << d;
    }
};

// 人员类
class people {
    char name[11];
    char number[7];
    char sex[4];
    char id[16];
    date birthday;      // 内嵌子对象（不是指针，所以自动复制、析构）

public:
    // 默认构造
    people() {}

    // 构造函数（聚集方式传入 date）
    people(const char* n, const char* num, const char* s,
           const char* iid, const date& bd)
        : birthday(bd)
    {
        strcpy(name, n);
        strcpy(number, num);
        strcpy(sex, s);
        strcpy(id, iid);
    }

    // 复制构造
    people(const people& p) : birthday(p.birthday)
    {
        strcpy(name, p.name);
        strcpy(number, p.number);
        strcpy(sex, p.sex);
        strcpy(id, p.id);
    }

    // 析构函数
    ~people() {}

    // 内联显示函数
    inline void show(int idx) const {
        cout << "人员 " << idx << " 信息:\n";
        cout << "姓名: " << name << "\n";
        cout << "编号: " << number << "\n";
        cout << "性别: " << sex << "\n";
        cout << "出生日期: ";
        birthday.show();
        cout << "\n身份证号: " << id << "\n\n";
    }
    inline void input(){
        cin.getline(name, 11);
        cin.getline(number, 7);
        cin.getline(sex, 4);
        cin.getline(id, 16);
        int y, m, d;
        cin >> y >> m >> d;
        birthday = date(y, m, d);
        cin.ignore();  // 清空换行符，防止下一次 getline 受影响
    }
};

int main() {
    people p[2];   // people 类对象数组

    // 输入第一个人的信息
    p[0].input();

    // 第二个人为复制构造得到（也可手动输入）
    p[1] = people("李四", "000002", "男", "987654321098765", date(1992, 2, 2));

    // 显示
    p[0].show(1);
    p[1].show(2);

    return 0;
}
