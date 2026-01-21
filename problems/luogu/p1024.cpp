#include <iostream>
using namespace std;

double a,b,c,d;

double f(double x){
    return a*x*x*x+b*x*x+c*x+d;
}

int main() {
    cin>>a>>b>>c>>d;
    int i=-100;double m,n;
    for(;i<100;i++){
        m=i;n=i+1;
        if(f(m)==0){
            printf("%.2f",m);
            cout<<" ";
        }
        if((f(m)*f(n))<0){
            while((n-m)>0.001){
                f(m)*f((m+n)/2)>0?m=(m+n)/2:n=(m+n)/2;
            }
            printf("%.2f",n);
            cout<<" ";
        }
    }
    return 0;
}