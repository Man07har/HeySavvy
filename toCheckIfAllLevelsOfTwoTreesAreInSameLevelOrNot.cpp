/* Given two binary trees, the task is to check if each of their levels are anagrams of each other or not. 

Example 1:

Input:

Output: 1
Explanation: 
Tree 1:
Level 0 : 1
Level 1 : 3, 2
Level 2 : 5, 4

Tree 2:
Level 0 : 1
Level 1 : 2, 3
Level 2 : 4, 5

As we can clearly see all the levels of above two binary trees 
are anagrams of each other, hence return true.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function areAnagrams() which takes the root of two trees as input and returns an 1 if all the levels are anagrams, else returns 0 as output.
 

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N <= 104
1 <= tree.val <= 109 */

class Solution{
    public:
    vector<vector<int>> bfs(Node *root){
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int n=q.size();
            vector<int> v;
            while(n--){
                auto b = q.front();q.pop();
                v.push_back(b->data);
                if(b->left) q.push(b->left);
                if(b->right) q.push(b->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
    bool areAnagrams(Node *root1, Node *root2)
    {
        auto a = bfs(root1);
        auto b = bfs(root2);
        if(a.size() != b.size()) return false;
        for(int i=0;i<a.size();i++){
            unordered_map<int,int> c,d;
            for(auto j:a[i]) c[j]++;
            for(auto j:b[i]) d[j]++;
            if(c != d) return false;
        }
        return true;
    }
};