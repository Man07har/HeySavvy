#include<iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
} 
node* generateNewNode(int data){
node *newNode=new node();
newNode->data=data;
newNode->left=newNode->right=NULL;
return newNode;
}

int main(){
    return 0;
}