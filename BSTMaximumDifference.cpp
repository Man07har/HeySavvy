/* You are given a Binary Search Tree and a target value. You must find the maximum difference between the sum of node data from root to target and from target to a child leaf node (target exclusive). Initially, you are at the root node.
Note: If the target node is not present in the tree then return -1.

Example 1:

Input:


Target = 20
Output: 10
Explanation: From root to target the sum of node data is 25 and from target to the children leaf nodes the sums of the node data are 15 and 25. So, the maximum difference will be (25-15) = 10.
Example 2:

Input:

Target = 50
Output: -1
Explanation: The target node is not present in the tree.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxDifferenceBST() which takes BST(you are given the root node of the BST ) and target as input, and returns an interger value as the required answer. If the target is not present in the BST then return -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(H), H - Height of the Tree.


Constraints:
1 <= n < 10^4
1 <= node.data < 10^5
1 <= target < 10^5 */


class Solution
{
public:
    Node* res;
    int res2;
    int ans;
    void search(Node *root,int target,int cur)
    {
        if(!root)return;
        if(target==root->data)
        {
            res=root;
            res2=cur;
            return ;
        }
        else if(target<root->data)
            search(root->left,target,cur+root->data);
        else  
            search(root->right,target,cur+root->data);
    }
    void preorder(Node *root,int sum)
    {
        if(!root)return;
        if(root->left==NULL && root->right==NULL)
        {
            sum+=root->data;
            ans=max(ans,(res2-(sum-res->data)));
        }
        sum+=root->data;
        preorder(root->left,sum);
        preorder(root->right,sum);
    }
    int maxDifferenceBST(Node *root,int target)
    {
        res=NULL;
        res2=0;
        ans=-1000000000;
        int cur=0;
        search(root,target,cur);
        if(res==NULL)
        {
            return -1;
        }
        root=res;
        int sum=0;
        preorder(root,sum);
        return ans;
    }
};