/* You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

 

Example 1:


Input: n = 3
Output: 5
Explanation: The five different ways are show above.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 1000 */


class Solution {
public:
    int numTilings(int N) {
        int mod = 1000000007;
        int dp[N+1][2];
        dp[0][1] = 1, dp[0][0] = 0;
        dp[1][1] = 1, dp[1][0] = 0;
        
        for(int i=2; i<N+1; i++){
            dp[i][1] = ((dp[i-1][1] + dp[i-2][1])%mod + (dp[i-1][0])%mod)%mod;
            dp[i][0] = ((dp[i-2][1]*2)%mod + (dp[i-1][0])%mod)%mod;
        }
        return dp[N][1];
    }
};