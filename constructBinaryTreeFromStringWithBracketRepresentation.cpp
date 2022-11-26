/* Construct a binary tree from a string consisting of parenthesis and integers. The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the roots value and a pair of parenthesis contains a child binary tree with the same structure. Always start to construct the left child node of the parent first if it exists.

Example 1:

Input: "1(2)(3)" 
Output: 2 1 3
Explanation:
           1
          / \
         2   3
Explanation: first pair of parenthesis contains 
left subtree and second one contains the right 
subtree. Inorder of above tree is "2 1 3".
Example 2:

Input: "4(2(3)(1))(6(5))"
Output: 3 2 1 4 5 6
Explanation:
           4
         /   \
        2     6
       / \   / 
      3   1 5   
Your Task:
You don't need to read input or print anything. Your task is to complete the function treeFromString() which takes a string str as input parameter and returns the root node of the tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 <= |str| <= 105 */

class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        // code here
        int lb =0, up = str.size()-1;
        if(lb<=up)
        {
            string s= "";
            int i;
            for(i=0;i<str.size();i++)
            {
                if(str[i]=='(')    
                {
                    lb = i+1;
                    break;
                    
                }
                else
                s+=str[i];
            }
            int val = stoi(s);
            Node *root = new Node(val);
            if(i==str.size())
            return root;
            int open =1, left;
        
            for(int i=lb;i<str.size();i++)
            {
                if(str[i]=='(')
                open++;
                else if(str[i]==')')
                open--;
                if(open==0)
                {
                    left = i;
                    break;
                }
            }
            root->left = treeFromString(str.substr(lb, left-lb));
            if(up>=left+2)
            root->right = treeFromString(str.substr(left+2,up-left-2 ));
            return root;
        }
        return nullptr;

}