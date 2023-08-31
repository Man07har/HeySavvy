/* Given an AVL tree and N values to be deleted from the tree. Write a function to delete a given value from the tree. All the N values which needs to be deleted are passed one by one as input data by driver code itself, you are asked to return the root of modified tree after deleting the value.

Example 1:

Tree =
        4
      /   \
     2     6
    / \   / \
   1   3 5   7

N = 4
Values to be deleted = {4,1,3,6}

Input: Value to be deleted = 4
Output:
        5
      /   \
     2     6
    / \     \
   1   3     7

Input: Value to be deleted = 1
Output:
        5
      /   \
     2     6
      \     \
       3     7

Input: Value to be deleted = 3
Output:
        5
      /   \
     2     6
            \
             7

Input: Value to be deleted = 6
Output:
        5
      /   \
     2     7

Your Task:
You dont need to read input or print anything. Complete the function delelteNode() which takes the root of the tree and the value of the node to be deleted as input parameters and returns the root of the modified tree.

Note: The tree will be checked after each deletion.
If it violates the properties of balanced BST, an error message will be printed followed by the inorder traversal of the tree at that moment.
If instead all deletion are successful, inorder traversal of tree will be printed.
If every single node is deleted from tree, 'null' will be printed.

Expected Time Complexity: O(height of tree)
Expected Auxiliary Space: O(height of tree)

Constraints:
1 ≤ N ≤ 500 */

void storeAllNodes(Node *root, vector<int> &nodes, int &key)
{
    // using dfs
    if (root == NULL)
        return;
    // calling recursion
    if (root->left)
    {
        storeAllNodes(root->left, nodes, key);
    }
    if (root->data != key)
        nodes.push_back(root->data);
    if (root->right)
    {
        storeAllNodes(root->right, nodes, key);
    }
}

Node *constructAVLTree(vector<int> &nodes, int l, int r)
{
    // base case
    if (l > r)
    {
        return NULL;
    }
    // calling recursion
    int m = (r + l) / 2;
    Node *ret = new Node(nodes[m]);
    ret->left = constructAVLTree(nodes, l, m - 1);
    ret->right = constructAVLTree(nodes, m + 1, r);
    return ret;
}

Node *deleteNode(Node *root, int key)
{
    vector<int> nodes;
    // using preorder dfs to store all nodes in sorted order
    storeAllNodes(root, nodes, key);
    Node *ret = constructAVLTree(nodes, 0, nodes.size() - 1);
    return ret;
}