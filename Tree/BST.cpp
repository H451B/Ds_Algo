#include <bits/stdc++.h>
using namespace std;

struct Node{
    int date;
    Node* left;
    Node* right;
};

//create new node
Node* GetNewNode(int data){
    Node* newNode = new Node();
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

//insert
void Insert(Node** root, int data){
    if(*root==NULL){
        *root=GetNewNode(data);
    }else if(data<=root->data){
        root->left=Insert(root->left,data); //recursion
    }else{
        root->right=Insert(root->right,data);
    } 
}

void Search(Node* root,int data){
    if(root==null) return false;
    else if(root->data==data) return true;
    else if(data<=root->data) return Search(root->left,data);
    else{return Search(root->right,data);}
}

int main(){
    //NON LINEAR
    //employee tree based on management(TREE)
    //NODES -> ROOT - PARENT - CHILDREN - LEAF(last)
    //N nodes - n-1 edges
    //DEPTH of node - root->0 - root to x-1
    //HEIGHT of node - x+1 to last node
    // APPICATION FILES, SEARCH/DELETION(bst), TRIE(dictionary), NETWORK ROUTING
    
    //BINARY SEARCH TREE (search,insert,remove->logn) //better than likned,array
    //left_side(less) right_side(greater)
    //All node created in HEAP(dynamic memory,malloc/new)
    
    // Implementation
    Node* rootPtr;
    root = NULL;
    
    Insert(root,15); //root
    Insert(root,10); //less than root so left [[leftaddr][root]]
    Insert(root,20); //greater than root so right [[root][rightaddr]]
    Insert(root,19); //call1 root->right | call2 root->left | insert
    
    search(root,19);

    return 0;
}
