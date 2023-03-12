// (head)[val|next'sPointet] -> [val|next'sPointet] -> [val|null]
// 4 bytes data + 4 bytes address

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next; //self referencial structure

    Node(int x){ //constructor
        data = x;
        next = NULL;
    }
};

void traverse(Node *head);
void search(Node *head, int value);

int main(){
    Node *head = new Node(10); // [10 | null] creation
    Node *tmp1 = new Node(20); // [20 | null]    ||
    Node *tmp2 = new Node(20); // [20 | null]    ||
    Node *tmp3 = new Node(30);

    //linking 
    head -> next = tmp1; //[10 | tmp1's reference]    
    tmp1 -> next = tmp2; //[20 | tmp2's reference]
    tmp2 -> next = tmp3;

    /*
        head -> next = new Node(20);
        head -> next -> next = new Node(30); //another way linking
    */

    //traverse
    Node *access =  head;
    while(access!=NULL){
        cout<< access->data<< " ";
        access = access->next;
    }

    //search
     search(head,30);

    return 0;
}

void search(Node *head, int value){
    int x=1;
    Node *position=head;
    while(position!=NULL){
        if(position->data==value){cout<<"Position "<<x<<endl;break;}
        position = position->next;
        x+=1;
    }
}
  