/* Given a string S, return the sum of beauty of all its substrings.
The beauty of a string is defined as the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of string "aaac" is 3 - 1 = 2.
Example 1:

Input:
S = "aaac"
Output:
3
Explanation: The substrings with non - zero beauty are ["aaac","aac"] where beauty of "aaac" is 2 and beauty of "aac" is 1.
 

Example 2:

Input:
S = "geeksforgeeks"
Output:
62
Explanation: There are 91 substrings of the given strings. Like, the beauty of substring "geek" is 1. In this way the sum of beauties of all substrings are 62.
Your Task:
You don't need to read input or print anything. Your task is to complete the function beautySum() which takes string S as input paramters and returns the sum of beauty of all its substrings. 

Expected Time Complexity: O(|S|2)
Expected Auxiliary Space: O(1)

Constraints: 
1 ≤ |S| ≤ 500
S only contains lower case alphabets */


class Solution {
  public:
    int beautySum(string s) {
    
        int res = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            vector<int> dp(26);
            for (int j = i; j < n; j++) {
                dp[s[j] - 'a']++;
                int a = 0, b = n;
                for (int k = 0; k < 26; k++) {
                    if (dp[k] > 0) {
                        a = max(a, dp[k]);
                        b = min(b, dp[k]);
                    }
                }
                res += a - b;
            }
        }
        return res;
    }
};