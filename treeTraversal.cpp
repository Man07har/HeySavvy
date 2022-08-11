//Inorder traversal
#include<iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
/* struct node* preOrder()
{
    node *newNode;
    int item;
    newNode->left=preOrder();
    cout<<" "<<newNode->data;
    newNode->right=preOrder();
} */
/* struct node* postOrder()
{
    node *newNode;
    int item;
    newNode->left=postOrder();
    newNode->right=postOrder();
    cout<<" "<<newNode->data;
}*/
/* struct node *inOrder()
{
    node *newNode;
    cout<<" "<<newNode->data;
    newNode->left=inOrder();
    newNode->right=inOrder();
} */