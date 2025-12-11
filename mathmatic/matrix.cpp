#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class matrix {
    int r,c;
    vector<vector<int>> content;
public:
    matrix(int a,int b):r(a),c(b),content(a, vector<int>(b)) {};
    matrix(const matrix& a);
    matrix operator+(const matrix &b)const;
    matrix operator*(const matrix &b)const;
    matrix& operator=(const matrix &b);
    void input();
    void print();
    int& operator()(int i,int j);
    int operator()(int i,int j)const;
    friend ostream& operator<<(ostream& os,const matrix &a);
    friend istream& operator>>(istream& is,matrix &a);
};

matrix::matrix(const matrix& a){
    *this=a;
}

int& matrix::operator()(int i,int j){
    if(i<0||j<0||i>=r||j>=c){
        cout << "警告：矩阵下标越界 (" << i << "," << j << ")\n";
        static int dummy = 0;  // 返回一个引用以保证程序继续
        return dummy;
    }
    return content[i][j];
};

int matrix::operator()(int i,int j)const {
    if(i<0||j<0||i>=r||j>=c){
        cout << "警告：矩阵下标越界 (" << i << "," << j << ")\n";
        static int dummy = 0;  // 返回一个引用以保证程序继续
        return dummy;
    }
    return content[i][j];
};

matrix matrix::operator+(const matrix &b)const{
    if(this->c!=b.c||r!=b.r){
        cout<<"ERROR!"<<endl;
        return matrix(0,0); 
    }
    matrix ans(b.r,b.c);
    for(int i=0;i<b.r;i++){
        for(int j=0;j<b.c;j++){
            ans(i,j)=(*this)(i,j)+b(i,j);
        }
    }
    return ans;
};

matrix& matrix::operator=(const matrix& b){    
    r=b.r;
    c=b.c;
    content.resize(r);
    for (vector<int> & r1 :content ){
        r1.resize(c);
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            content[i][j]=b.content[i][j];
        }
    }
    return *this;
};

matrix matrix::operator*(const matrix& b)const{
    if (c!=b.r){
        cout<<"ERROR!"<<endl;
        return matrix(0,0);
    }
    matrix ans(r,b.c);
    for(int i=0;i<r;i++){
        for(int j=0;j<b.c;j++){
            for (int k=0;k<c;k++){
                ans(i,j)+=(*this)(i,k)*b(k,j);
            }
        }
    }
    return ans;
};

void matrix::input(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>this->content[i][j];
        }
    }
};

void matrix::print(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<setw(4)<<this->content[i][j]<<' ';
        }
        cout<<endl;
    }
}

ostream& operator<<(ostream& os,const matrix &a){
    for (int i=0;i<a.r;i++){
        for(int j=0;j<a.c;j++){
            os<<a(i,j)<<' ';
        }
        os<<'\n';
    }
    return os;
}

istream& operator>>(istream& is,matrix &a){
    is>>a.c>>a.r;
    a.content.resize(a.r);
    for(vector<int>& c : a.content){
        c.resize(a.c);
    }
    for (int i=0;i<a.r;i++){
        for(int j=0;j<a.c;j++){
            is>>a(i,j);
        }
    }
    return is;
}

int main() {
    int c1,c2,r1,r2;
    cin>>r1>>c1;
    matrix a(r1,c1);
    a.input();
    cin>>r2>>c2;
    matrix b(r2,c2);
    b.input();
    /*matrix d=a+b;
    d.print();
    matrix c=a*b;
    c.print();*/
    cout<<a(0,0)<<endl;
    cout<<a*b;
    cout<<a+b;
    cout<<(a=b)<<endl;
    return 0;
}