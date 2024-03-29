/* Given a linked list and a number k. You have to reverse first part of linked list with k nodes and the second part with n-k nodes.

Example 1:

Input: 1 -> 2 -> 3 -> 4 -> 5
k = 2
Output: 2 -> 1 -> 5 -> 4 -> 3
Explanation: As k = 2 , so the first part 2
nodes: 1 -> 2 and the second part with 3 nodes:
3 -> 4 -> 5. Now after reversing the first part: 
2 -> 1 and the second part: 5 -> 4 -> 3.
So the output is: 2 -> 1 -> 5 -> 4 -> 3
Example 2:

Input: 1 -> 2 -> 4 -> 3
k = 3
Output: 4 -> 2 -> 1 -> 3
Explanation: As k = 3 , so the first part 
3 nodes: 4 -> 2 -> 1 and the second part
with 1 nodes: 3. Now after reversing the 
first part: 1 -> 2 -> 4 and the 
second part: 3. So the output is: 1 -> 2 -> 4 -> 3
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function reverse() which takes head node of the linked list and a integer k as input parameters and returns head node of the linked list after reversing both parts. 


Constraints:
1 <= N <= 105 
1 <= k < N 

Expected Time Complexity: O(N)
Expected Space Complexity: O(1) */


class Solution
{
public:

    Node *reverse(Node *head) 
    {
        Node *p = head, *pre = NULL, *nxt;
        
        while(p) {
            nxt = p->next;
            p->next = pre;
            
            pre = p;
            p = nxt;
        }
        
        return pre;
    }
   
    Node *reverse(Node *head, int k)
    {
        if(!head) return NULL;
        
        Node *first = head, *p = head, *prev;
        int i = 0;
        while(p and i < k) {
            prev = p;
            p = p->next;
            i++;
        }
        prev->next = NULL;
        
        first = reverse(first);
        Node *second = p;
        second = reverse(second);
        
        p = first;
        while(p->next) p = p->next;
        p->next = second;
        
        return first;
    }
};