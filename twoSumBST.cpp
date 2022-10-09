/* Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105 */

class Solution {
public:
    void inOrd(TreeNode *root,vector<int>&v){
        if(root!=NULL){
            inOrd(root->left,v);
            v.push_back(root->val);
            inOrd(root->right,v);
        }
    }
    bool findTarget(TreeNode* root, int k) {
       vector<int> v;
        inOrd(root,v);
        if(v.size()==1){
            if(v[0]!=k)
                return false;
        }
        unordered_set<int> s;
        for(int i=0;i<v.size();i++){
            if(s.find(k-v[i])!=s.end())
                return true;
            else
                s.insert(v[i]);
        }
        return false;
    }
};