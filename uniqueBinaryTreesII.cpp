/* Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

 

Example 1:


Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:

Input: n = 1
Output: [[1]] */


class Solution {
public:
    
    vector<TreeNode*> build(int start, int end){
        if(start>end) return {NULL};
        if(start==end) return {new TreeNode(start)};
        
        vector<TreeNode*> ans;
        for(int i=start;i<=end;i++){
            // inorder of BST is sorted i.e left -> root-> right
            vector<TreeNode*> left=build(start,i-1);
            vector<TreeNode*> right=build(i+1,end);
            
            // building all possible combinations with left having smaller than root & right having bigger values than root
            for(TreeNode* l : left){
                for(TreeNode* r : right){
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return build(1,n);
    }
};