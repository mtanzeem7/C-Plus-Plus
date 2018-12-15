#include<iostream>
#include<stack>

using namespace std;

int is_number(char c){
    if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')
      return 1;
}

int prec(char a){
    if(a=='+'||a=='-')
      return 1;
    if(a=='*'||a=='/')
      return 2;
    if(a=='^')
      return 3;
      
    return 0;
}

int main(){
   char str[] = "a+b*(c^d-e)^(f+g*h)-i";
   stack<char> st;
   int i=0;
   char* post = new char[sizeof(str)];
   int j=0;
   
   while(str[i]!='\0'){
       if(str[i]=='(')
         st.push(str[i]);
       else if(str[i]>='a'&&str[i]<='z' || str[i]>='A'&&str[i]<='Z'){
         post[j++] = str[i];
         cout<<"oprnd: "<<str[i]<<endl;
       }
        
       else if(str[i]==')'){
           cout<<"Right Bracket occurs"<<endl;
           while(!st.empty()&&st.top()!='('){
               post[j++]=st.top();
               cout<<"pop: "<<st.top()<<endl;
               st.pop();
               
           }
           
           cout<<"pop: "<<st.top()<<endl;
           st.pop();
       }
       else{
           cout<<"operator occurs"<<endl;
           while(!st.empty()&&prec(st.top())>=prec(str[i]) ){
               post[j++] = st.top();
               cout<<"pop: "<<st.top()<<endl;
               st.pop();
           }
           st.push(str[i]);
           cout<<"push: "<<str[i]<<endl;
       }
       i++;
   }
   
   while(!st.empty()){
       post[j++] = st.top();
       st.pop();
   }
   
   cout << post << endl;
   
   stack<char> st1;
   i=0;
   while(post[i]!='\0'){
       if(post[i]>='a'&&post[i]<='z' || post[i]>='A'&&post[i]<='Z')
         st.push(post[i]);
       else{
          
       }
       i++;
   }
   
    
}