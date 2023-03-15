/* Given two strings s1 and s2, The task is to convert s1 into a palindrome such that s1 contain s2 as a substring in a minimum number of operation.
In a single operation, we can replace any word of s1 with any character.

Note: If it is not possible to convert s1 such that it is a palindrome as well as contains substring of s2, then return -1.

Example 1:

Input:
s1="abaa" s2="bb"
Output: 1
Explanation:
we can replace s1[2]='a' with 'b'.
So the new s1 will be like "abba",
having s2 as a substring.
Example 2:

Input:
s1="abbd" s2="mr"
Output: 4
Explanation:
1st: s1="mrbd" --> 2 operations (this is the 
minimum operation to make s2 a substring of s1) 
2nd: s1="mrrm" --> 2 operations 
(this is the minimum operation to make s1 palindrome)
Your Task: 
You don't need to read input or print anything. Complete the function specialPalindrome() which takes the two strings s1 and s2 as input parameters. Return the minimum number of operations needs to convert s1 such that it is a palindrome and having s2 as a substring in s1.

Expected Time Complexity: O(N*M) [N: size of s1 and M: size of s2]
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ |s2| ≤ |s1| ≤  1000 */


int specialPalindrome(string a, string b){
        int ans=INT_MAX;
        for(int i=0;i<=a.length()-b.length();i++) {
            int val = f(a,b,i,i+b.length()-1);
            if(val!=-1) ans=min(ans,val);
        }
        if(ans==INT_MAX) ans=-1;
        return ans;
    }
    int f(string a,string b,int strt,int end) {
        int ans=0;
        for(int i=0,j=a.length()-1;i<=j;i++,j--) {
            if(i>=strt && i<=end) {
                if(j>=strt && j<=end) {
                    if(b[i-strt]!=b[j-strt]) return -1;
                    if(a[i]!=b[i-strt]) ans++;
                    if(a[j]!=b[j-strt] && i!=j) ans++;
                } else {
                    if(a[i]!=b[i-strt]) ans++;
                    if(b[i-strt]!=a[j] && i!=j) ans++;
                }
            } else {
                if(j>=strt && j<=end) {
                    if(a[j]!=b[j-strt]) ans++;
                    if(b[j-strt]!=a[i] && i!=j) ans++;
                } else {
                    if(a[i]!=a[j]) ans++;
                }
            }
        }
        return ans;
    }