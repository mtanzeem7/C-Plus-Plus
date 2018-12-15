#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(char& a,char& b){
    char temp_c = a;
    a = b;
    b = temp_c;
}

int main() {
    int i=0,len=0;
	string str;
	
	cin>>str;
	
	
	//while(str[i]!='\0')
	//  i++;
	len = str.length();
	i=-1;
	while(i<len-1)
	   swap(str[++i],str[--len]);
	   
	cout<<"E: "<<str;
	
	return 0;
}