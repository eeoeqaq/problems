#include<iostream>
#include<cstring>
using namespace std;
const int LEN=100;
int a[LEN],b[LEN],c[LEN];

void initialize (int k[]){
    for(int i=0;i<LEN;i++){
        k[i]=0;
    }
}

void read(int *a){
        char k[LEN];
        scanf("%s",k);
        int len=strlen(k);
        for( int i=0;i<len;i++){
            a[i]=k[len-i-1]-'0';    
        }
}
void print (int *a){
    int i=LEN-1;
    for(;;i--){
        if(a[i]!=0) break;
    }
    for(;i>=0;i--){ 
        putchar(a[i]+'0');
    }
    cout<<endl;
}

void sum(int *a,int *b, int *c){
    initialize(c);
    for(int i=0;i<LEN;i++){
        c[i]=a[i]+b[i];
    }
    for(int i=0;i<LEN;i++){
        if(c[i]>=10){
            c[i+1]+=(int)(c[i]/10);
            c[i]%=10;
        }
    }
}

void partial_sub(int *a,int *b,int *c){
    //要求a>b
    initialize(c);
    for(int i=0;i<LEN;i++){
        c[i]=a[i]-b[i];
    }
    for(int i=0;i<LEN;i++){
        if(c[i]<0){
        c[i]+=10;
        c[i+1]-=1;
        }
    }
}

void int_mul(int *a,int b,int *c){
    initialize(c);
    for(int i=0;i<LEN;i++){
        c[i]=a[i]*b;
    }
    for(int i=0;i<LEN-1;i++){
        c[i+1]+=c[i]/10;
        c[i]%=10;
    } 
}



/*void sub(int *a,int *b,int *c){
    initialize(c);
    if(strlen((char*)a)>strlen((char*)b)){
    partial_sub(a,b,c);
    }
    if(strlen((char*)a)<strlen((char*)b)){
    partial_sub(b,a,c);

    }
}*/

void two_mul(int a[],int b[],int c[]){
    initialize(c);
    for(int i=0;i<LEN;i++){
        for(int j=0;j<=i;j++){
            c[i]+=a[j]*b[i-j];
        }
    }
    
    for(int i=0;i<LEN-1;i++){
        
        c[i+1]+=c[i]/10;
        c[i]%=10;

    }
}


int main(){
    read(a);
    read(b);
    print(a); 
    //read(b);
    //print(b); 
    //partial_sub(a,b,c);
    //print(c); 
    int d;
    cin>>d;
    two_mul(a,b,c);
    print(c); 
    system("pause");
}



