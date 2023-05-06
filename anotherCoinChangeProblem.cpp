/* Given three integers n, k, target, and an array of coins of size n. Find if it is possible to make a change of target cents by using an infinite supply of each coin but the total number of coins used must be exactly equal to k.

Example 1:

Input:
n = 5, k = 3, target = 11
coins = {1, 10, 5, 8, 6}

Output: 
1

Explanation: 
2 coins of 5 and 1 coins of 1 can be used 
to make change of 11 i.e. 11 => 5+5+1.
Example 2:

Input:
n = 3, k = 5, target = 25
coins = {7, 2, 4}

Output:
1

Explanation:
3 coins 7, 2 coins of 2 can be used to
make change of 25 i.e. 25 => 7+7+7+2+2.
Your Task:
This is a function problem. You only need to complete the function makeChanges() that 3 integers n, k, target, and an array coins as parameters and return True or False.

Expected Time Complexity: O(n*k*target)
Expected Space Complexity: O(k*target)

Constraints:
1 <= n, k, coins[i] <= 100
1 <= target <= 1000 */


class Solution {
  public:
    bool dp[1001][101];
    bool makeChanges(int n, int k, int target, vector<int> &coins) {
        sort(coins.begin(), coins.end());
        memset(dp, true, sizeof(dp));
        func(n-1, k, target, coins);
    }
    bool func(int cur, int k, int x, vector<int> &arr) {
        if(k == 0 && x == 0) return true;
        if(cur < 0) return false;
        if(!dp[x][k]) return dp[x][k];
        
        for(int i = 0; i <= k && arr[cur]*i <= x; i++){
            if(func(cur-1, k-i, x-arr[cur]*i, arr)) return true;
        }
        return dp[x][k] = false;
    }
};