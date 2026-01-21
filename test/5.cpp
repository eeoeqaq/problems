#include <iostream>
using namespace std;

class car ;
class boat;

int getWeight(const car& a, const boat& b);

class boat {
    public:
    int weight;
    boat (int a):weight(a) {};
    friend int getWeight(const car& a, const boat& b);
};
class car{
    public:
    int weight ;
    car (int a):weight(a){};
    friend int getWeight(const car& a, const boat& b);
};

int getWeight(const car& a, const boat& b) {
    return a.weight + b.weight;
}
int main() {
    int a,b;
    cin>>a>>b;
    car c=car(a);
    boat d=boat(b);
    int e=getWeight(c,d);
    cout<<e;
    return 0;
}