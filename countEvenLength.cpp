/* Given a number n, find count of all binary sequences of length 2n such that sum of first n bits is same as sum of last n bits.
The anwer can be very large. So, you have to return answer modulo 109+7.

Example:

Input: n = 2
Output: 6
Explanation: There are 6 sequences of length 
2*n, the sequences are 0101, 0110, 1010, 1001, 
0000 and 1111.
Example:

Input: n = 1
Output: 2
Explanation: There are 2 sequence of length 
2*n, the sequence are 00 and 11.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function compute_value() which takes n as input parameter and returns count of all binary sequence of length 2*n such that sum of first n bits is same as sum of last n bits modulo 109 + 7.
 

Expected Time Complexity: O(n * log(n))
Expected Space Complexity:  O(1)
 

Constraints:
1 <= n <= 105 */


class Solution {
    public:
	int m = 1e9+7;
	long long binpow(long long a, long long b) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
    long long inv(int n) {
        return binpow(n, m-2);
    }
	int compute_value(int n)
	{
	    long long ans = 1, num = 1, den = 1, cur = n;
	    for(int i = 1, j = n; i <= n; i++, j--) 
	    {
	        num = (num * j) % m;
	        den = (den * i) % m;
	        
	        long long temp = (num * inv(den)) % m;
	        temp = binpow(temp, 2);
	        ans = (ans + temp) % m;
	    }
	    return (int)ans;
	}
};