/* Given N nodes of a tree and a list of edges. Find the minimum number of nodes to be selected to light up all the edges of the tree.
An edge lights up when at least one node at the end of the edge is selected.


Example 1:

Input:
N = 6
edges[] = {(1,2), (1,3), (2,4), (3,5), (3,6)}
Output: 2
Explanation: Selecting nodes 2 and 3 lights
up all the edges.
Example 2:

Input:
N = 3
arr[] = {(1,2), (1,3)}
Output: 1
Explanation: Selecting Node 1 
lights up all the edges.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function countVertex() which takes the number of nodes N, and the list of edges as input parameters and returns the minimum number of nodes selected.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 105
1 ≤ edges ≤ N
Given graph is a valid tree. */


class Solution{

  public:

    int ans=0;

    int dfs(int node, int par,vector<vector<int>> &adj){

        int ones=0,twos=0;

        for(int child : adj[node]){

            if(child!=par){

                int ret=dfs(child,node,adj);

                

                switch(ret){

                    case 0 : {ones++;break;}

                    case 1 : {twos++;break;}

                }

            }

        }

        

        if(ones>0){

            ans++;

            return 1;

        }

        if(twos>0){

            return 0;    

        }

        return 0;

    }

    

    int countVertex(int n, vector<vector<int>>edges){

        vector<vector<int>> adj(n);

        for(auto v : edges){

            adj[v[0]-1].push_back(v[1]-1);

            adj[v[1]-1].push_back(v[0]-1);

        }

        

        int state=dfs(0,-1,adj);

        return ans;

    }

};