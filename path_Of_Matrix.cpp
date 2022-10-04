/* The task is to count all the possible paths from top left to bottom right of a m X n matrix with the constraints that from each cell you can either move only to right or down.

Example 1:

Input: m = 2, n = 2
Output: 2 
Explanation: Two possible ways are
RD and DR.  

Example 2:

Input: m = 3, R = 3
Output: 6
Explanation: Six possible ways are
RRDD, DDRR, RDDR, DRRD, RDRD, DRDR. 

Your Task:  
You dont need to read input or print anything. Complete the function numberOfPaths() which takes m and n as input parameter and returns count all the possible paths.The answer may be very large, compute the answer modulo 109 + 7.


Expected Time Complexity: O(m*n)
Expected Auxiliary Space: O(m*n)

Constraints:
1 <= m <=100
1 <= n <=100 */

class Solution {

    long long int f(int i,int j,int m,int n,vector<vector<long long int>> &dp){

        if(i==0 && j==0) return 1;

        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        long long int ans= 0 ;

        ans = (ans+ f(i,j-1,m,n,dp))%1000000007;

        ans = (ans+ f(i-1,j,m,n,dp))%1000000007;

        return dp[i][j] = ans%1000000007;

    }

  public:

    long long int numberOfPaths(int m, int n){

        // code here

        vector<vector<long long int>> dp(m+1,vector<long long int>(n+1,-1));

        return f(m-1,n-1,m,n,dp);

    }

 

};