/* Given a binary tree, count the number of Single Valued Subtrees. A Single Valued Subtree is one in which all the nodes have same value. 

Example 1

Input :

              5

             / \

            1   5

           / \   \

          5   5   5

Output : 4

Explanation : 

There are 4 subtrees with single values.

Example 2:

Input:

              5

             / \

            4   5

           / \   \

          4   4   5   

Output: 5

Explanation: 

There are five subtrees with single values.

Your task :

You don't have to read input or print anything. Your task is to complete the function singlevalued() which takes the root of the tree as input and returns the count of single valued subtrees.

 

Expected Time Complexity : O(n)

Expected Auxiliary Space : O(n)

 

Constraints :

1 <= n <= 10^5 */

class Solution

{

    public:

    pair<bool,int> fun(Node* root){

        if(!root){

            return {true,0};

        }

        pair<bool,int> leftans=fun(root->left);

        pair<bool,int> rightans=fun(root->right);

        if(leftans.first&&rightans.first){

            bool compLeft=true,compRight=true;

            if(leftans.second){

                compLeft=(root->left->data==root->data);

            }

            if(rightans.second){

                compRight=(root->right->data==root->data);

            }

            if(compLeft&&compRight){

                return {true,leftans.second+rightans.second+1};

            }

            else{

                return {false,leftans.second+rightans.second};

            }

        }

        else{

            return {false,leftans.second+rightans.second};

        }

    }

    int singlevalued(Node *root)

    {

        auto ans=fun(root);

        return ans.second;

    }

    

};
