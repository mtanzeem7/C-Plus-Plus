#include <iostream>
using namespace std;

int min(int a,int b,int c){
    int min;
    if(a>b) min = b;
    else min = a;
    
    if(c>min) return min;
    else return c;
    
}

int** d;// new int[5][7];
//topdown DP approach
int min_distance(char* str1,char* str2, int m,int n){
    
    if(m==0)
      return n;
    if(n==0)
      return m;
    
    if(str1[m-1]==str2[n-1]){
        if(d[m][n]==-1)
        d[m][n]=min_distance(str1,str2,m-1,n-1);
        
    }
    else{
    
    d[m][n] = 1+min(min_distance(str1,str2,m,n-1),
                 min_distance(str1,str2,m-1,n),
                 min_distance(str1,str2,m-1,n-1));
    }
    
    return d[m][n];
}

//bottom up DP approach

int min_d(char* str1,char* str2,int m,int n){
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            
            
            if(str1[i-1]==str2[j-1])
              d[i][j] = d[i-1][j-1];
            
            else 
                d[i][j] = 1+min(d[i-1][j-1],d[i-1][j],d[i][j-1]);
            
        }
    }
    
    return d[m][n];
}

int main() {
	char str1[] = "sunday";
	char str2[] = "saturday";
	d = (int **)new int[7];
	for(int i=0;i<7;i++){
	   d[i] = (int *)new int[9];
	   for(int j=0;j<9;j++){
	   if(i==0)
	     d[i][j] = j;
	   else if(j==0)
	     d[i][j] = i;
	   else
	      d[i][j]=-1;
	   }
	   
	}
	
	cout<<min_d(str1,str2,6,8);
	
	return 0;
}