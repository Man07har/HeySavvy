/*  Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
Note: You can only move left, right, up and down, and only through cells that contain 1.

Example 1:

Input:
N=3, M=4
A=[[1,0,0,0], 
   [1,1,0,1],
   [0,1,1,1]]
X=2, Y=3 
Output:
5
Explanation:
The shortest path is as follows:
(0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3).
Example 2:

Input:
N=3, M=4
A=[[1,1,1,1],
   [0,0,0,1],
   [0,0,0,1]]
X=0, Y=3
Output:
3
Explanation:
The shortest path is as follows:
(0,0)->(0,1)->(0,2)->(0,3).
Your Task:
You don't need to read input or print anything. Your task is to complete the function shortestDistance() which takes the integer N, M, X, Y, and the 2D binary matrix A as input parameters and returns the minimum number of steps required to go from (0,0) to (X, Y).If it is impossible to go from (0,0) to (X, Y),then function returns -1. If value of the cell (0,0) is 0 (i.e  A[0][0]=0) then return -1.

Expected Time Complexity:O(N*M)
Expected Auxillary Space:O(N*M)

Constraints:
1 <= N,M <= 250
0 <= X < N
0 <= Y < M
0 <= A[i][j] <= 1*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0]==0) return -1;
        vector<vector<int>> visit(N,vector<int>(M,0));
        visit[0][0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        int row[]={-1,0,1,0},col[]={0,1,0,-1};
        while(!q.empty())
        {
            int i=q.front().first,j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nrow=i+row[k],ncol=j+col[k];
                if(nrow>=0&&nrow<N&&ncol>=0&&ncol<M&&A[nrow][ncol]!=0)
                {
                    if(visit[nrow][ncol]==0)
                    {
                        A[nrow][ncol]=A[i][j]+1;
                        visit[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                    else
                    {
                        if(A[nrow][ncol]>A[i][j]+1)
                        {
                            A[nrow][ncol]=A[i][j]+1;
                            q.push({nrow,ncol});
                        }
                    }
                    
                }
            }
        }
        return visit[X][Y]==1?A[X][Y]-1:-1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
