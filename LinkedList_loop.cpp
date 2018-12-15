#include <iostream>

struct Node{
    int data;
    struct Node *next;
    
};

void push(Node** head, int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

class List{
    
    public:
    Node *head;
    List(){
        head = NULL;
    }
    
    void push(int data){
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = head;
        head = new_node;
    }
    
    void print(){
        Node* tmp = head;
        while(tmp!=NULL){
        std::cout<<tmp->data<<" ";
        tmp = tmp->next;
        }
    }
    
    void reverse(){
        Node* ptr = head;
        Node* prev = NULL;
        
        while(ptr!=NULL){
            Node* tmp = ptr->next;
            ptr->next = prev;
            
            prev = ptr;
            ptr = tmp;
            
        }
        head = prev;
        
    }
    
    bool isLoop(){
        Node *ptr1,*ptr2;
        //ptr1 = head;
        if(head!=NULL and head->next!=NULL){
        ptr1 = head;
        ptr2 = head->next;
        }
        else
         return true;
         
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1==ptr2)
              return true;
            
            if(ptr1->next!=NULL)
            ptr1 = ptr1->next;
            else
            return false;
            if(ptr2->next!=NULL && ptr2->next->next!=NULL)
            ptr2 = ptr2->next->next;
            else
            return false;
            
        }
        return false;
    }
};

int main() {
    List l;
    for(int i=0;i<10;i++)
    l.push(i);
    
    //l.head->next->next->next->next->next->next->next = l.head->next->next;
    //std::cout<<"Loop: "<<l.isLoop();
    l.reverse();
    l.print();
    
    
	//Node *head;
	//push(&head,1);
	//push(&head,2);
	//std::cout<<head->data<<" "<<head->next->data;
	
	return 0;
}