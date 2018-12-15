#include<iostream>

using namespace std;

void swap(char& a,char& b){
    char tmp = a;
    a = b;
    b = a;
}

int main(){
    char str[] = "My name is mohammed tanzeem";
    char c = str[0];
    int i=0,j=0;
    
    while(str[i]!='\0'){
        
        if(str[i+1]==' '||str[i+1]=='\0'){
            int k = i;
            while(j<i){
                char tmp = str[j];
                str[j] = str[i];
                str[i]  = tmp;
                i--;
                j++;
                //cout<<str<<endl;
            }
            j = k+2;
            i = k+1;
            
        }
        i++;
        
    }
    j=0;
    //cout<<"str: "<<str<<endl;
    i--;
    while(j<i){
                char tmp = str[j];
                str[j] = str[i-1];
                str[i-1]  = tmp;
                
                i--;
                j++;
                
    }
    
    
    cout <<"j: "<< str << endl;
    
}