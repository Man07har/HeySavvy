/* Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
Example 3:


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
 

Constraints:

The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100 */




class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int maxWidth = 0;
        queue<TreeNode*> node_q;
        queue<unsigned long long> index_q;
        node_q.push(root);
        index_q.push(1);
        while (!node_q.empty()) {
            int size = node_q.size();
            unsigned long long leftIndex = index_q.front(), rightIndex = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = node_q.front();
                unsigned long long index = index_q.front();
                node_q.pop();
                index_q.pop();
                rightIndex = index;
                if (curr->left) {
                    node_q.push(curr->left);
                    index_q.push(index * 2);
                }
                if (curr->right) {
                    node_q.push(curr->right);
                    index_q.push(index * 2 + 1);
                }
            }
            maxWidth = max(maxWidth, (int)(rightIndex - leftIndex + 1));
        }
        return maxWidth;
    }
};