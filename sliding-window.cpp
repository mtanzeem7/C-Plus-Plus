#include <iostream>
#include <deque>
using namespace std;

int max_window(int a[],int k,int n){
    
    cout<<"n: "<<n<<endl;
    int i;
    deque<int> q(k);
    
    for(i=0;i<k;i++){
        while(!q.empty()&&a[i]>q.back())
          q.pop_back();
        q.push_back(i);
        
    }
    
    while(i<n){
        cout<<a[q.front()]<<" ";
        //if max(front element) element is out of window(i.e. q.front <= i-k)
        // remove it from q.
        if(!q.empty()&&q.front()<=i-k)
          q.pop_front();
        while(!q.empty()&&a[i]>=a[q.back()])
          q.pop_back();
          
        q.push_back(i);
        i++;
    }
    cout<<a[q.front()]<<" ";
    return 1;
}

//brute force
int max_w(int a[],int k,int n){
    int x = 0,i=0,max=-999,j=0;
    
    while(i<=n-k){
        max=a[i];
        j=0;
        while(j<k){
            if(a[i+j]>=max)
              max=a[i+j];
            j++;
            
        }
        cout<<max<<" "<<endl;
        i++;
    }
    
    return 1;
}

int main() {
	int a[] = {12, 1, 78, 90, 57, 89, 56};
	int k = 3;
	int n = sizeof(a)/sizeof(a[0]);
	max_window(a,k,n);
	return 0;
}