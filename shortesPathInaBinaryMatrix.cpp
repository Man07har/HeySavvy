/* Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1 */

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        
        if(grid[0][0]==1)return -1;
        
        if(grid[0][0]==0 && grid.size()==1 && grid[0].size()==1)return 1;
        
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid.size(),false));
        visited[0][0]=true;
        while(!q.empty())
        {
            pair<int,int>p = q.front().first; 
            int x = p.first; 
            int y= p.second; 
            int lengthOfPath = q.front().second; 
            q.pop();
            
            vector<pair<int,int>>neighbours = {{0,1}, {0,-1}, {1,0}, {-1,0},
                                               {1,1}, {-1,-1}, {1,-1}, {-1,1}};
            
            for(pair<int,int>neighbour: neighbours)
            {
                int newx = neighbour.first + x;
                int newy = neighbour.second+ y;
                
         if(newx>=0 && newy>=0 && newx<grid.size() && newy<grid[0].size() && grid[newx][newy]==0 && !visited[newx][newy]){

                    q.push({{newx,newy},lengthOfPath+1});
                    visited[newx][newy] = true;
                    
                    if(newx==grid.size()-1 && newy==grid[0].size()-1)
                     return lengthOfPath+1;
           
                }      
            }
        }
        
        return -1;
        
    }
};