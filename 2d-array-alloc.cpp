#include <iostream>
using namespace std;

int** alloc2Darray(int m,int n){
    int** arr =(int**) malloc(m*sizeof(int*));
    for(int i=0;i<m;i++)
      arr[i] = (int*)malloc(n*sizeof(int));
    
    return arr;
    
}

int** alloc2Darray1(int m,int n){
    int** arr = (int**)malloc(m*sizeof(int*)+m*n*sizeof(int*));
    if(arr==NULL)
      cout<<"Error while memory alloc";
      
    //int* buf = (int*)(arr+);
    
    for(int i=0;i<m;i++)
       arr[i] = (int *)(arr+m) + i*n;
    
    return arr;
}

int main() {
    //int** a = alloc2Darray1(4,5);
    //int** a = alloc2Darray1(4,5);
	int a[4][5];
	cout<<&a<<" "<<endl;
	cout<<a<<" "<<endl;
	cout<<*a<<" "<<endl;
	cout<<**a<<" "<<endl;
	for(int i=0;i<4;i++)
	  cout<<a[i]<<" ";
	
	for(int i=0;i<4;i++){
	    cout<<endl;
	  for(int j=0;j<5;j++){
	     a[i][j]=1;
	     cout<<a[i][j]<<" ";
	  }
	}
	
	return 0;
}
