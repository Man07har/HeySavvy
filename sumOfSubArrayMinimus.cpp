/* Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104 */

class Solution {
  static constexpr int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {  
      stack<int> s;
      
      int n = arr.size();
      long sum = 0;
      vector<int> dp(n); 
      
      for (int i = 0; i < n; i++) {
        
        while (!s.empty() && arr[s.top()] >= arr[i]) 
          s.pop();
        
        if (s.size()) {
        
          int prev = s.top();
          dp[i] = dp[prev] + (i - prev)*arr[i];
          
        } else 
          dp[i] = (i+1)*arr[i];
        
    
        sum = (sum + dp[i]) % MOD;
        
        s.push(i); 
      }
      
      return (int) sum;
    }
};