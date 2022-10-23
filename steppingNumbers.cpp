/* A number is called a stepping number if all adjacent digits have an absolute difference of 1, e.g. '321' is a Stepping Number while 421 is not. Given two integers n and m, find the count of all the stepping numbers in the range [n, m].

Example 1:

Input: n = 0, m = 21
Output: 13
Explanation: Stepping no's are 0 1 2 3 4 5
6 7 8 9 10 12 21
Example 2:

Input: n = 10, m = 15
Output: 2
Explanation: Stepping no's are 10, 12

Your Task:  
You don't need to read input or print anything. Your task is to complete the function steppingNumbers() which takes the integer n and integer m as input parameters and returns the number of stepping numbers in the range between n and m.

Expected Time Complexity: O(log(M))
Expected Auxiliary Space: O(SN) where SN is the number of stepping numbers in the range


Constraints:
0 ≤ N < M ≤ 107 */
class Solution{
public:
    int solve(int num, int n, int m){
        int ans=0;
        if(num>m) return 0;
        
        if(num>=n && num<=m) ans++;
        int last= num%10;
        if(last!=0){
            ans+= solve((num*10) + (last-1), n, m);
        }
        if(last!=9){
            ans+= solve((num*10)+ (last+1), n, m);
        }
        return ans;
    }

    int steppingNumbers(int n, int m){
        int ans=0;
        if(n==0) ans++;
        for(int i=1;i<=9;i++){
            ans+= solve(i, n, m);
        }
        return ans;
    }
};