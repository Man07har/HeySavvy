/* You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

 

Example 1:


Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
Example 2:


Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
Output: -1
Explanation: We need to eliminate at least two obstacles to find such a walk.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 40
1 <= k <= m * n
grid[i][j] is either 0 or 1.
grid[0][0] == grid[m - 1][n - 1] == 0 */

class Solution {
public: 
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<bool>>> v(n,vector<vector<bool>>(m,vector<bool>(k+1,false)));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},k});
        int steps=0;
        v[0][0][k]==true;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty())
        {
            int size=q.size();
            while(size-->0)
            {
                auto curr=q.front();
                q.pop();
                if(curr.first.first==n-1 && curr.first.second==m-1)
                    return steps;
                for(int i=0;i<4;i++)
                {
                    int rw=curr.first.first+delrow[i];
                    int cl=curr.first.second+delcol[i];
                    int obs=curr.second;
                    
                    if(rw>=0 && rw<n && cl>=0 && cl<m)
                    {
                        if(grid[rw][cl]==0 && !v[rw][cl][obs])
                        {
                            v[rw][cl][obs]=true;
                            q.push({{rw,cl},obs});
                        }
                        else if(grid[rw][cl]==1 && obs>0 && !v[rw][cl][obs-1])
                        {
                            v[rw][cl][obs-1]=true;
                            q.push({{rw,cl},obs-1});
                        }
                    }
                }
            }
            
            steps++;
        }
        return -1;
    }
    
};