/* A Hamiltonian path, is a path in an undirected graph that visits each vertex exactly once. Given an undirected graph, the task is to check if a Hamiltonian path is present in it or not.

Example 1:

Input:
N = 4, M = 4
Edges[][]= { {1,2}, {2,3}, {3,4}, {2,4} }
Output:
1 
Explanation: 
There is a hamiltonian path: 
1 -> 2 -> 3 -> 4 
Example 2:

Input:
N = 4, M = 3 
Edges[][] = { {1,2}, {2,3}, {2,4} } 
Output: 
0 
Explanation: 
It can be proved that there is no 
hamiltonian path in the given graph
Your task:
You don't need to read input or print anything. Your task is to complete the function check() which takes the N (the number of vertices), M (Number of edges) and the list of Edges[][] (where Edges[i] denotes the undirected Edge between vertices Edge[i][0] and Edges[i][1] ) as input parameter and returns true (boolean value) if the graph contains Hamiltonian path,otherwise returns false. 


Expected Time Complexity: O(N!).
Expected Auxiliary Space: O(N+M).


Constraints:
1 ≤ N ≤ 10
1 ≤ M ≤ 15
Size of Edges[i] is 2
1 ≤ Edges[i][0],Edges[i][1] ≤ N */

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool flag =false;
    void solve(vector<int>adj[],int i, int N, vector<int>&vis){
        if(vis[i])
        return;
        vis[i]=1;
        int check=accumulate(vis.begin(), vis.end(),0);
        if(check==N+1)
        flag=true;
        for(auto x:adj[i]){
            solve(adj,x,N,vis);
        }
        vis[i]=0;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<int> adj[N+1];
        for(int i=0;i<M;i++){
            adj[Edges[i][0]].push_back(Edges[i][1]);
            adj[Edges[i][1]].push_back(Edges[i][0]);
        }
        vector<int> vis(N+1,0);
        vis[0]=1;
        for(int i=1;i<=N;i++){
            if(!flag)
            solve(adj,i,N,vis);
            else return true;
        }
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends