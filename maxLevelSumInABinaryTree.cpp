/* Given a Binary Tree having positive and negative nodes. Find the maximum sum of a level in the given Binary Tree.

Example 1:

Input :               
             4
          /    \
         2     -5
        / \    / \
      -1   3  -2  6

Output: 6

Explanation :
Sum of all nodes of 0'th level is 4
Sum of all nodes of 1'th level is -3
Sum of all nodes of 2'th level is 6
Hence maximum sum is 6

Example 2:

Input :          
            1
          /   \
         2     3
        / \     \
       4   5     8
                / \
               6   7  

Output :  17

Explanation: Maximum sum is at level 2.

Your Task:  
You dont need to read input or print anything. Complete the function maxLevelSum() which takes root node as input parameter and returns the maximum sum of any horizontal level in the given Binary Tree.

Expected Time Complexity: O(N), where N is no of node.
Expected Auxiliary Space: O(W), Where W is the max width of the tree.


Constraints:
1 ≤ N ≤ 104 */


int maxLevelSum(Node* root) {
       queue<Node*> q;
            q.push(root);

            int maxSum=INT_MIN;

            while(!q.empty()) {
                int size=q.size();

		    //Current Level Sum..
                int levelSum=0;

                for(int i=0; i<size; i++) {
                    Node* nn=q.front();
                    q.pop();

                    levelSum += nn->data;

                    if(nn->left != NULL) {
                        q.push(nn->left);
                    }
                    if(nn->right != NULL) {
                        q.push(nn->right);
                    }
                }

		   //Maximum Level Sum..
                maxSum=max(maxSum, levelSum);
            }

            return maxSum;
    }