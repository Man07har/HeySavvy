/*  Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

Example 1:

Input: n = 3, r = 2
Output: 3
Explaination: 3C2 = 3. 
Example 2:

Input: n = 2, r = 4
Output: 0
Explaination: r is greater than n.
Your Task:
You do not need to take input or print anything. Your task is to complete the function nCr() which takes n and r as input parameters and returns nCr modulo 109+7..

Expected Time Complexity: O(n*r)
Expected Auxiliary Space: O(r)

Constraints:
1 ≤ n ≤ 1000
1 ≤ r ≤ 800 */


class Solution{
    
    const int mod = 1e9+7;
    int binaryexp(int x, int n) {
        if(n == 0) return 1;
        int temp = binaryexp(x, n/2);
        if(n%2 == 0) return (1LL *temp * temp)%mod;
        else return (((1LL*temp*temp)%mod)*x)%mod;
    }
    
public:
    int nCr(int n, int r){
        if(r > n) return 0;
        if(r == n) return 1;
        long long ans = 1;
        //first calculating the numerator
        for(int i = 1; i<=r; i++) {
            ans = (ans*1LL*(i+(n-r)))%mod;
        }
        //now calculating the final ans by dividing the ans with the terms in denominator 
        for(int i = 1; i<=r; i++) {
            int inv = binaryexp(i, mod-2);
            ans = ((ans%mod) * (inv%mod))%mod;
        }
        return ans;
    }
};