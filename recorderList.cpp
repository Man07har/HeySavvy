/* Given a singly linked list: A0→A1→...→An-2→An-1, reorder it to: A0→An-1→A1→An-2→A2→An-3→...
For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

Note: It is recommended do this in-place without altering the node's values.

Example 1:

Input:
LinkedList: 1->2->3
Output: 1 3 2
Explanation:
Here n=3, so the correct
order is A0→A2→A1
Example 2:

Input:
Explanation: 1->7->3->4
Output: 1 4 7 3
Explanation:
Here n=4, so the correct
order is A0→A3→A1→A2
Your Task:
The task is to complete the function reorderList() which should reorder the list as required. The reorder list is automatically printed by the driver's code.

Note: Try to solve without using any auxilliary space.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 5*105
1 <= A[ i ] <= 105 */

class Solution{ 
private:
    Node* reverse(Node *start){
        Node *prev=NULL,*curr=start;
        while(curr!=NULL){
            Node *tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        return prev;
    }
public:
    void reorderList(Node* head) {
        Node *slow=head,*fast=head->next;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        Node *t1=reverse(slow->next);
        slow->next=NULL;
        Node *t2=head;
        while(t1!=NULL&&t2!=NULL){
            Node *tmp=t2->next;
            Node *tmp1=t1->next;
            t2->next=t1;
            t1->next=tmp;
            t2=tmp;
            t1=tmp1;
        }
    }
};