#include <bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node*next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;
public:

    List(){
        head = tail = NULL;
    }
    
    void push_front(int val){
        Node* newNode = new Node(val);  // dynamic - it persists even after function ends
        // Node newNode(val);  // static - it deleted after getting out of function

        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }


    void push_back(int val){
        Node * newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            return;
        }
        Node * temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        if(head==NULL) return;
        Node * temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }


    void insert(int val, int pos){
        if(pos < 0){
            return;
        }
        if(pos ==0){
           push_front(val);
           return;
        }
        Node *newNode = new Node(val);
        Node*temp = head;
        int count = 0;
        while (count != pos-1)
        {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }


    int search(int val){
        int count = 0;
        Node * temp = head;
        while (temp->next != NULL)
        {
            if(temp->data == val) {
                return count;
            }
         temp = temp->next;
         count++;   
        }
        
        return -1;
    }

   void printLL(){
    Node *temp = head;

    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
   }
    
};


int main() {
  List ll;
  ll.push_front(1);
  ll.push_front(2);
  ll.push_front(3);


  ll.push_back(23);
  ll.push_back(123);
  ll.push_back(45);


  ll.pop_front();


  ll.pop_back();

  ll.insert(456, 2);
  ll.printLL();
}