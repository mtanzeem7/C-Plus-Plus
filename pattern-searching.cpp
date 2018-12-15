#include <iostream>
using namespace std;

int pattern(char* text,char* pat){
    int i = 0,j=0,k;
    
    while(text[i]!='\0'){
        j=0;
        k=i;
        while(pat[j]!='\0'){
            if(pat[j]!=text[i])
              break;
            j++;
            i++;
        }
        if(pat[j]=='\0')
          cout<<"Pattern at : "<<k<<endl;
        i=k+1;
    }
    
}


int main() {
	char text[] = "AABAACAADAABAABA";
	char pat[] = "AABA";
	
	pattern(text,pat);
	
	return 0;
}