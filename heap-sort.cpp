#include <iostream>
using namespace std;

class Heap{
    int *arr;
    int size;
    public:
    Heap(int* a,int n){
        
        arr = a;
        size = n;
        makeheap();
        
    }
    void makeheap(){
        for(int i=size/2;i>=0;i--){
            heapify(arr,i,size);
        }
        
        
    }
    
    void sort(){
        for(int i=size-1;i>=0;i--){
           int tmp = arr[0];
           arr[0] = arr[i];
           arr[i] = tmp;
           
           heapify(arr,0,i);
            
        }
        
    }
    
    
    
    
    
    
    
    void heapify(int* a,int x,int n){
        int l = 2*x+1;
        int r = 2*x+2;
        int max = x;
        if(l<n&&a[l]>a[x])
           max = l;
        if(r<n&&a[r]>a[max])
           max = r;
        if(max!=x){
            int tmp = a[x];
            a[x] = a[max];
            a[max] = tmp;
            
            heapify(a,max,n);
        }
    }
    
    void prnt(){
        for(int i=0;i<size;i++)
          cout<<arr[i]<<" ";
    }
    
    
};

int main() {
	int a[] = {1,3,5,7,9,0,8,6,4,2};
	Heap heap(a,sizeof(a)/sizeof(a[0]));
	heap.prnt();
	heap.sort();
	cout<<endl;
	heap.prnt();
	
	
	
	
	return 0;
}