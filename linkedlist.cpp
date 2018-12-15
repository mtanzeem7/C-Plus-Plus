#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

void reverse(Node** head){
    Node* ptr = *head;
    Node* prev = nullptr;
    
    while(ptr!=nullptr){
        Node* tmp = ptr->next;
        ptr->next = prev;
        
        prev = ptr;
        ptr = tmp;
    }
    
    *head = prev;
}

void insert(Node** head){
    
}

class list{
    public:
       Node* head;
       list(){
           head = nullptr;
       }
       
       void insert(int data){
           Node* new_node = new Node(data);
           new_node->next = head;
           head = new_node;
           
       }
       
       void del(int data){
           Node* ptr = head;
           if(ptr->data==data){
               Node* tmp = head;
               head = ptr->next;
               
               delete tmp;
           }
           
           while(ptr->next!=nullptr){
              if(ptr->next->data==data){
                  Node* tmp = ptr->next;
                  ptr->next = ptr->next->next;
                  
                  delete tmp;
              }
              
              if(ptr->next!=nullptr)
                ptr = ptr->next;
              else
                break;
           }
              
           
       }
       
       
       
       void reverse(){
           Node* ptr = head;
           Node *prev = nullptr;
           while(ptr!=nullptr){
               Node* temp = ptr->next;
               ptr->next = prev;
               
               prev = ptr;
               ptr = temp;
               
           }
           head = prev;
       }
       
       void print(){
           Node* ptr = head;
           while(ptr!=nullptr){
               cout << ptr->data <<" " ;
               ptr = ptr->next;
               
           }
       }
       
};


int main(){
    list l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.print();
    //l.reverse();
    l.del(1);
    l.del(4);
    l.del(3);
    l.print();
    
}