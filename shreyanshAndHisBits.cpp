/* Shreyansh has an integer N. He is really curious about the binary representation of integers. He sees that any given integer has a number of set bits. Now he wants to find out that how many positive integers, strictly less than N, have the same number of set bits as N.
He is a little weak in maths. Help him find the number of integers.
Note : Since N takes large values, brute force won't work.

 

Example 1:

Input:
N = 8
Output: 3
Explanation:
Binary representation of 8 : 1000
So the integers less than 8 with 
same number of set bits are : 4, 2, 1
Hence, the result is 3.  
 

Example 2:

Input:
N = 4
Output: 2
Explanation:
Binary representation of 4 : 100
So the integers less than 4 with 
same number of set bits are : 2, 1
So, The result is 2.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function count() which takes the integer N as input parameters and returns the required answer.

Expected Time Complexity: O(log(n))
Expected Auxiliary Space: O(log(n)*log(n))
 

 

Constraints : 
1 <= N <= 10^12 */

class Solution{
    private: 
        long long nCr(long long n, long long r){
            if(r > n){
                return 0;
            }
            long long res = 1;
            for(int i = 0; i < r; i++){
                res *= (n - i);
                res /= (i + 1);
            }
            return res;
        }
    public:
    
        long long count(long long x) {
            if(x == 1){
                return 0;
            }
            long long num = x;
            long long cnt = 0;
            long long i = 0;
            long long ans = 0;
            while(num != 0){
                if((num & 1) == 1){
                    cnt++;
                    ans += nCr(i, cnt);
                }
                i++;
                num >>= 1;
            }
            return ans;
        }
};