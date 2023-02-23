/*. You are given a matrix grid of n x  m size consisting of values 0 and 1. A value of 1 means that you can enter that cell and 0 implies that entry to that cell is not allowed.

You start at the upper-left corner of the grid (1, 1) and you have to reach the bottom-right corner (n, m) such that you can only move in the right or down direction from every cell.

Your task is to calculate the total number of ways of reaching the target modulo (109+7).
Note: The first (1, 1) and last cell (n, m) of the grid can also be 0


Example 1:

Input:
n = 3, m = 3
grid[][] = {{1, 1, 1};
            {1, 0, 1};
            {1, 1, 1}}
Output:
2
Explanation:
1 1 1
1 0 1
1 1 1
This is one possible path.
1 1 1
1 0 1
1 1 1
This is another possible path.
Example 2:

Input:
n = 1, m = 3
grid = {{1, 0, 1}}
Output :
0
Explanation:
There is no possible path to reach the end.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function uniquePaths() which takes 2 integers n, and m, and a matrix of size n*m as input and returns the number of unique paths from cell (1,1) to (n,m) modulo (109+7)


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)


Constraints:
1 ≤ n*m ≤ 106. */



class Solution {
    int mod=1e9+7;
  public:
    int uniquePaths(int r, int c, vector<vector<int>> &grid) {
        if(grid[0][0]==0 or grid[r-1][c-1]==0){
            return 0;
        }
        int dp[r][c];
        dp[0][0]=1;
        //fill the first row
        for(int p=1;p<c;p++){
            if(grid[0][p]==0){
                dp[0][p]=0;
            }else{
                dp[0][p]=dp[0][p-1];
            }
            
        }
        //fill the first col
        for(int p=1;p<r;p++){
            if(grid[p][0]==0){
                dp[p][0]=0;
            }else{
                dp[p][0]=dp[p-1][0];
            }
        }
        //fill the rest
        for(int a=1;a<r;a++){
            for(int b=1;b<c;b++){
                if(grid[a][b]==0){
                    dp[a][b]=0;
                }else{
                    dp[a][b]=(dp[a-1][b]%mod+dp[a][b-1]%mod)%mod;
                }
            }
        }
        return dp[r-1][c-1]%mod;
        
    }
};
