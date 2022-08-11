//reversing of the linked list
#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;

} *head;
struct node * reverse(){
    node *temp=NULL;
    node *temp2;
    temp2=head->next;
    head->next=temp;
    temp=head;
    head=temp2;

}
int main(){
node *newNode;
newNode=reverse();
return 0;
}