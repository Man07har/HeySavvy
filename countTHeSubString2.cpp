/* Given a string S. The task is to count the number of substrings which contains equal number of lowercase and uppercase letters. 

Example 1:

Input:
S = "gEEk"
Output: 3
Explanation: There are 3 substrings of
the given string which satisfy the
condition. They are "gE", "gEEk" and "Ek".
Example 2:

Input:
S = "WomensDAY"
Output: 4
Explanation: There are 4 substrings of 
the given string which satisfy the
condition. They are "Wo", "ensDAY", 
"nsDA" and "sD"
Your Task:
The task is to complete the function countSubstring() which takes the string S as input parameter and returns the number of substrings which contains equal number of uppercase and lowercase letters.

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ |S| ≤ 103*/


int countSubstring(string S)
    {
        // code here
        int ans=0;
        for(int i=0;i<S.length();i++) {
            int l=0,u=0;
            for(int j=i;j<S.length();j++) {
                if(S[j]>='A' && S[j]<='Z') {
                    u++;
                } else {
                    l++;
                }
                if(l==u) ans++;
            }
        }
        return ans;
    }