/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.*/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* node = dummyHead;

        int carry = 0;
        for (ListNode *i = l1, *j = l2; i != nullptr || j != nullptr;) {
            int sum = carry;
            sum += (i == nullptr ? 0 : i->val);
            sum += (j == nullptr ? 0 : j->val);

            node->next = new ListNode(sum % 10);
            node = node->next;

            carry = sum / 10;
            i = (i == nullptr ? i : i->next);
            j = (j == nullptr ? j : j->next);
        }

        if (carry != 0) {
            node->next = new ListNode(carry);
        }
        return dummyHead->next;
    }
};