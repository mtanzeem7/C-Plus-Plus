#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
        
    }
};

class Bst{
    
    public:
    Node *root;
    Bst(){
        root = NULL;
    }
    void insert(int data){
        Node *new_node = new Node(data);
        if(root==NULL)
           root = new_node;
        else{
            Node* ptr = root;
            Node* prev = NULL;
            while(ptr!=NULL){
                //prev = ptr;
                if(data<=ptr->data){
                    if(ptr->left!=NULL)
                      ptr = ptr->left;
                    else{
                      ptr->left = new_node;
                      break;
                    }
                }
                else{
                    if(ptr->right!=NULL)
                       ptr = ptr->right;
                    else{
                       ptr->right = new_node;
                       break;
                    }
                }
            }
        }
        
    }
    
    void in_order(Node* ptr){
        if(ptr==NULL)
        return;
        
        in_order(ptr->left);
        std::cout << ptr->data <<" ";
        in_order(ptr->right);
        
    }
    
    void print(){
        if(root!=NULL)
          in_order(root);
    }
    
    
};

int is_bst(Node* ptr,int min, int max){
    if(ptr==NULL)
    return true;
    
    if(ptr->data>=min && ptr->data<=max)
      return (is_bst(ptr->left,min,ptr->data) && is_bst(ptr->right,ptr->data,max));
    else
      return false;
    
}

int max(int a,int b){
    if(a>=b)
      return a;
    else
      return b;
}

int is_bal(Node* ptr,int& is_b){
    
    
    if(ptr==NULL){
        return 0;
    }
    
    int lh = is_bal(ptr->left,is_b);
    int rh = is_bal(ptr->right,is_b);
    
    if(lh-rh>1 || rh-lh>1){
        is_b = 0;
        return 0;
    }
    
    return max(lh,rh)+1;
}

int kth_smallest(Node* ptr,int* k){
    if(ptr==NULL)
      return -1;
    
    kth_smallest(ptr->left,k);
    (*k)--;
    if(*k==0){
     cout<<ptr->data;
     return 0;
    }
    kth_smallest(ptr->right,k);
}

int kth_largest(Node* ptr, int& k){
    if(ptr==NULL)
      return -1;
    kth_largest(ptr->right,k);
    k--;
    if(k==0){
    cout<<ptr->data;
    return 0;
    }
    kth_largest(ptr->left,k);
}

int main() {
	Bst tree;
	tree.insert(5);
	tree.insert(3);
	tree.insert(7);
	tree.insert(8);
	//tree.root->data = 1;
	int k = 1;
	
	tree.print();
	cout<<is_bst(tree.root,-1,99999)<<endl;
	//kth_smallest(tree.root,&k);
	cout<<endl;
	//kth_largest(tree.root,k);
	int is_b = 1;
	is_bal(tree.root,is_b);
	cout<<"is_bal: "<<is_bal<<endl;
	
	return 0;
}