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

int main(){
    Node *head = new Node(10); // [10 | null]
    Node *tmp1 = new Node(20); // [20 | null]
    Node *tmp2 = new Node(20); // [20 | null]

    //linking 
    head -> next = tmp1; //[10 | tmp1's address]    
    tmp1 -> next = tmp2; //[20 | tmp2's address]

    /*
        head -> next = new Node(20);
        head -> next -> next = new Node(30);
    */

    Node *access =  head;
    while(1){
        cout<< access->data<< " ";
        if(access->next==NULL){break;}
        access = access->next;
    }

     

    return 0;
}
  