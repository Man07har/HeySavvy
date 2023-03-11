/* Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

 

Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []
 

Constraints:

The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105 */

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);
        ListNode* middle = getMiddle(head);
        TreeNode* root = new TreeNode(middle->val);
        root->right = sortedListToBST(middle->next);
        middle->next = NULL;
        root->left = sortedListToBST(head);
        return root;
    }
    
    ListNode* getMiddle(ListNode* head){
        //if(head == NULL || head->next==NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if(prev!=NULL) prev->next = NULL;
        return slow;
    }
};