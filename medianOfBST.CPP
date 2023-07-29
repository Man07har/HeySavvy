/* interview questions. Solve every day to ace the upcoming Placement Season !
Given a Binary Search Tree of size N, find the Median of its Node values.

Example 1:

Input:
       6
     /   \
   3      8   
 /  \    /  \
1    4  7    9
Output: 6
Explanation: Inorder of Given BST will be:
1, 3, 4, 6, 7, 8, 9. So, here median will 6.

Example 2:

Input:
       6
     /   \
   3      8   
 /   \    /   
1    4   7   
Output: 5
Explanation:Inorder of Given BST will be:
1, 3, 4, 6, 7, 8. So, here median will
(4 + 6)/2 = 10/2 = 5.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findMedian() which takes the root of the Binary Search Tree as input and returns the Median of Node values in the given BST.
Median of the BST is:

If number of nodes are even: then median = (N/2 th node + (N/2)+1 th node)/2
If number of nodes are odd : then median = (N+1)/2th node.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).


Constraints:
1<=N<=10000

  */


 int countnode(Node* root){
    if(!root){
        return 0;
    }
    else{
        return 1 + countnode(root->left) + countnode(root->right);
    }
}
void findnode(Node* root, int &c, int &val){
    if(!root){
        return;
    }
    else{
        findnode(root->left, c, val);
        c--;
        if(c == 0){
            val = root->data;
        }
        findnode(root->right, c, val);
    }
}
float findMedian(struct Node *root)
{
      //Code here
      int N = countnode(root);
      if(N % 2){
          int val = -1, c = (N + 1) / 2;
          findnode(root, c, val);
          return (float)val;
      }
      else{
          int val = -1,val2 = -1,c = N / 2;
          findnode(root, c, val);
          c = N / 2 + 1;
          findnode(root, c, val2);
          float ans = (float)(val + val2) / (2.0);
          return ans;
      }
}