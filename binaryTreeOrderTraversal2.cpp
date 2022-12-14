/* Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) return {};
        queue<TreeNode*> nodeQueue;
        stack<TreeNode*> nodeStack;
        map<TreeNode*, int> nodeMap;
        nodeMap[root] = 0;
        nodeQueue.push(root);
        while(!nodeQueue.empty()) {
            auto node = nodeQueue.front();
            nodeQueue.pop();
            nodeStack.push(node);
            auto l = node->left;
            auto r = node->right;
            auto level = nodeMap[node] + 1;
            if (r != NULL) {
                nodeMap[r] = level;
                nodeQueue.push(r);
            }
            if (l != NULL) {
                nodeMap[l] = level;
                nodeQueue.push(l);
            }
        }
        int maxLevel = nodeMap[nodeStack.top()];
        vector<vector<int>> res(maxLevel + 1);
        while(!nodeStack.empty()) {
            auto node = nodeStack.top();
            nodeStack.pop();
            auto level = maxLevel - nodeMap[node];
            res[level].push_back(node->val);
        }
        return res;
    }
};