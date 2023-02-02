/* Given a maze with N cells. Each cell may have multiple entry points but not more than one exit(i.e entry/exit points are unidirectional doors like valves).
You are given an array Edge[] of N integers, where Edge[i] contains the cell number that can be reached from of cell i in one step. Edge[i] is -1 if the ith cell doesn't have an exit. 
The task is to find the largest sum of a cycle in the maze(Sum of a cycle is the sum of the cell indexes of all cells present in that cycle).

Note:The cells are named with an integer value from 0 to N-1. If there is no cycle in the graph then return -1.

Example 1:

Input:
N = 4
Edge[] = {1, 2, 0, -1}
Output: 3
Explanation: 
There is only one cycle in the graph.
(i.e 0->1->2->0)
Sum of the cell index in that cycle 
= 0 + 1 + 2 = 3.
Example 2:

Input:
N = 4 
Edge[] = {2, 0, -1, 2}
Output: -1
Explanation:
1 -> 0 -> 2 <- 3
There is no cycle in the graph.

Your task:
You dont need to read input or print anything. Your task is to complete the function largestSumCycle() which takes the integer N denoting the number of cells and the array Edge[] as input parameters and returns the sum of the largest sum cycle in the maze.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
-1 < Edge[i] < N
Edge[i] != i */


class Solution
{
    
  private:
    unordered_map<int,vector<int>> adj;
    vector<int> disc,low;
    vector<bool> presentStack;
    long long ans=-1;
    stack<int> myStack;
  public:
  
  void dfs(int u, int &timer){
      low[u]=timer;
      disc[u]=timer;
      timer++;
      presentStack[u]=true;
      myStack.push(u);
      
      for(auto x:adj[u]){
          if(disc[x]==-1){
              dfs(x,timer);
              low[u]=min(low[u],low[x]);
          }
          else if(presentStack[x]){
              low[u]=min(low[u],disc[x]);
          }
      }
      
      if(low[u]==disc[u]){
          long long temp=0;
          while(myStack.top()!=u){
              temp+=myStack.top();
              presentStack[myStack.top()]=false;
              myStack.pop();
          }
          presentStack[myStack.top()]=false;
          temp+=myStack.top();
          myStack.pop();
          if(temp>u){
              ans=max(ans,temp);
          }
      }
      
  }
  
  long long largestSumCycle(int N, vector<int> edge)
  {
    // code here
    for(int i=0;i<N;i++){
        if(edge[i]!=-1){
            adj[i].push_back(edge[i]);
        }
    }
    
    disc.resize(N,-1);
    low.resize(N,-1);
    presentStack.resize(N,false);
    
    for(int i=0;i<N;i++){
        if(disc[i]==-1){
            int timer=0;
            dfs(i,timer);
        }
    }
    return ans;
  }
};