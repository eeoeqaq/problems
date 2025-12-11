//#include <stdio.h>
#include<vector>
#include <iostream>
using namespace std;
int main()
{
	int q;
	int j=q+10;
	printf("%d",j);
	
	int arr[]={1,3,2,5,4};
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
		cout<<arr[i]<<" ";
	}
	
	for (int element:arr){
		cout<<element<<" ";
	}
}
