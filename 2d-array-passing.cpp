#include <stdio.h> 
const int M = 3; 
const int N = 3; 

void print(int **arr) 
{ 
	int i, j; 
	arr[0][0]=9;
	
} 
void x(int a[][2]){
    a[0][0] = 11;
}

void y(int *a[2]){
    a[0][0] = 12;
}
// All above function will change the value of [0][0] in original array
int main() 
{ 
    int i,j;
	int **a; 
	int b[2][2] = {1,2,3,4};
	x(b);
	printf("%d \n", b[0][0]);
	int *c[2];
	c[0] = (int *)malloc(2*sizeof(int));
	c[1] = (int *)malloc(2*sizeof(int));
	y(c);
	printf("%d \n", c[0][0]);
	
	a = (int **)malloc(3*sizeof(int));
	for(i=0;i<3;i++)
	  a[i] = (int *)malloc(3*sizeof(int));
	print(a); 
	for (i = 0; i < M; i++) 
	for (j = 0; j < N; j++) 
		printf("%d ", a[i][j]); 
	return 0; 
} 


// Using new 
#include <stdio.h> 
const int M = 3; 
const int N = 3; 

void print(int **arr) 
{ 
	int i, j; 
	arr[0][0]=9;
	
} 
void x(int a[][2]){
    a[0][0] = 11;
}

void y(int *a[2]){
    a[0][0] = 12;
}

void z(int a[]){
    //printf("\d Addr: %d %d",a);
    a[0] = 13;
}

int main() 
{ 
    int i,j;
	int **a; 
	int b[2][2] = {1,2,3,4};
	x(b);
	printf("%d \n", b[0][0]);
	int *c[2];
	//c[0] = (int *)malloc(2*sizeof(int));
	//c[1] = (int *)malloc(2*sizeof(int));
	c[0] = new int[2];
	c[1] = new int[2];
	
	
	
	y(c);
	printf("%d \n", c[0][0]);
	int d[] = {1,2};
	z(d);
	printf("%d \n", d[0]);
	
	//a = (int **)malloc(3*sizeof(int));
	a = new int*[3];
	for(i=0;i<3;i++)
	  //a[i] = (int *)malloc(3*sizeof(int));
	  a[i] = new int[3] ;
	print(a); 
	for (i = 0; i < M; i++) 
	for (j = 0; j < N; j++) 
		printf("%d ", a[i][j]); 
	return 0; 
} 
