/* Given a binary tree. The task is to find the maximum GCD of the siblings of this tree. You have to return the value of the node whose two immediate children has the maximum gcd.
If there are multiple such nodes, return the node which has the maximum value.

Siblings: Nodes with the same parent are called siblings.

GCD (Greatest Common Divisor) of two positive integers is the largest positive integer that divides both numbers without a remainder.

Note:
Return 0 if input tree is empty i.e level of tree is -1.
Consider those nodes which have a sibling.
Return 0 if no such pair of siblings found.
 

Example 1:

Input:
              4
            /   \
           5     2
                /  \
               3    1
              /  \
             6   12

Output: 3
Explanation: For the above tree, the maximum
GCD for the siblings is formed for nodes 6 and 12
for the children of node 3.
 

Example 2:

Input: 
            1
          /   \
        3      5
      /  \    /  \
     6    9  4    8

Output: 5
Explanation: For the above tree, the maximum
GCD for the siblings is formed for nodes 4 and 8
for the children of node 5.
 

Your Task:
You don't need to take input. Just complete the function maxGCD() that takes the root node as a parameter and returns the value of the node whose two immediate children has the maximum gcd.

 

Expected Time Complexity: O(|Number of nodes|) .
Expected Auxiliary Space: O(1) .

 

Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105 */

int maxGCD( Node* root)

    {

        //code here

        int maxgcd=0;

        queue<Node*> q;

        if(root==NULL){

            return 0;

        }

        q.push(root);

        int ans=0;

        while(q.size()){

            auto curr=q.front();

            q.pop();

            int flag1=0,flag2=0;

            if(curr->left){

                q.push(curr->left);

                flag1=1;

            }

            if(curr->right){

                q.push(curr->right);

                flag2=1;

            }

            if(flag1 && flag2){

                int currgcd=__gcd(curr->left->data,curr->right->data);

                if(currgcd>=maxgcd){

                    maxgcd=currgcd;

                    ans=curr->data;

                }

            }

        }

        return ans;

    }