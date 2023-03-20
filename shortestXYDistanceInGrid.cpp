/* Give a N*M grid of characters 'O', 'X', and 'Y'. Find the minimum Manhattan distance between a X and a Y.

Manhattan Distance :
| row_index_x - row_index_y | + | column_index_x - column_index_y |


Example 1:

Input:
N = 4, M = 4
grid  = {{X, O, O, O}
         {O, Y, O, Y}
         {X, X, O, O}
         {O, Y, O, O}}
Output:
1
Explanation:
{{X, O, O, O}
{O, Y, O, Y}
{X, X, O, O}
{O, Y, O, O}}
The shortest X-Y distance in the grid is 1.
One possible such X and Y are marked in bold
in the above grid.
Example 2:

Input:
N = 3, M = 3
grid = {{X, X, O}
        {O, O, Y}
        {Y, O, O}}
Output :
2
Explanation:
{{X, X, O}
 {O, O, Y}
 {Y, O, O}}
The shortest X-Y distance in the grid is 2.
One possible such X and Y are marked in bold
in the above grid.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function shortestXYDist() which takes two integers N, and M and an 2D list of size N*M as input and returns the shortest Manhattan Distance between a X and a Y.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(N*M)


Constraints:
1 ≤ N*M ≤ 105 

There exists at least one 'X' and at least one 'Y' in the grid. */


class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        
        vector<pair<int,int>>x,y;
        int ans=1e9;
        
        for(int p=0;p<n;p++){
            for(int q=0;q<m;q++){
                if(grid[p][q]=='X'){
                    x.push_back({p,q});
                }
                else if(grid[p][q]=='Y'){
                    y.push_back({p,q});
                }
            }
        }
        for(int p=0;p<x.size();p++){
            for(int q=0;q<y.size();q++){
                ans=min(ans,abs(x[p].first-y[q].first)+abs(x[p].second-y[q].second));
            }
            if(ans==1){
                return ans;
            }
        }
        return ans;
    }
};