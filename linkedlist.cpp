#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node* next;
};

class linkedList{
  public:
  void append(Node* node,int data){
    Node* current=node;
    while(current->next!=NULL){
      current=current->next;
    }
    Node*new_node=new Node;
    current->next=new_node;
    new_node->data=data;
  }

  //insert method
  void insert(Node* node,int data){
    if(node==NULL){
      cout<<"ERROR! the given node can not be NULL";
      return;
    }
    Node* new_node=new Node();
    new_node->data=data;
    new_node->next=node->next;
    node->next=new_node;
  }

  //remove method
  void deleteNode(Node* node,int data){
    Node *temp=node;
    Node *prev=NULL;
    if(temp !=NULL && temp->data==data){
      node=temp->next;
      delete temp;
      return;
    }
    while(temp !=NULL && temp->data!=data){
      prev=temp;
      temp=temp->next;
    }
     if(temp==NULL)
      return;
    
    prev->next=temp->next;
    delete temp;
  }

  //display method
  void display(Node* n){
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
  }
};

int main()
{
  linkedList list;
  Node* node1=NULL;
  Node* node2=NULL;
  Node* node3=NULL;
  Node* node4=NULL;
  Node* node5=NULL;
  
  node1 = new Node();
  node2 = new Node();
  node3 = new Node();
  node4 = new Node();
  node5 = new Node();

  node1->data=29; 
  node1->next=node2; 
  
  node2->data=10; 
  node2->next=node3; 
  
  node3->data=-99; 
  node3->next=node4; 

  node4->data=76;
  node4->next=node5;

  node5->data=100;
  node5->next=NULL;

  cout<<"The list with 5 elements : ";
  list.display(node1);
  cout<<endl;

  list.append(node1,87);
  list.append(node1,88);
  cout<<"The list after append elements : ";
  list.display(node1);
  cout<<endl;

  list.insert(node4,11);
  cout<<"The list after insert elements : ";
  list.display(node1);
  cout<<endl;

  list.deleteNode(node1, 87);
  cout<<"The list after delete elements : ";
  list.display(node1);
  }