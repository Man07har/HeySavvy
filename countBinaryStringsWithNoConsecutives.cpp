/* Given an integer N. Your task is to find the number of binary strings of length N having no consecutive 1s.
As the number can be large, return the answer modulo 10^9+7.

Example 1:

Input:
N = 3
Output:
5
Explanation:
All the binary strings of length 3 having
no consecutive 1s are "000", "001", "101",
"100" and "010".
Example 2:

Input: 
N = 2
Output:
3
Explanation: 
All the binary strings of length 2 having no 
consecutive 1s are "10", "00" and "01".
Your Task:
You dont need to read input or print anything. Complete the function countStrings() which takes the integer N as the input parameter, and returns the number of binary strings of length N with no consecutive 1s.

Expected Time Complexity: O(log(N))
Expected Auxiliary Space: O(Height of the recursive call stack)

Constraints:
1 ≤ N ≤ 1018 */


class Solution {
  public:
    long long int mod = 1e9+7;
    
    vector<vector<int>> multiply(vector<vector<int>> A1,vector<vector<int>> A2)
    {
        vector<vector<int>> res = {{0,0},{0,0}};
        for(int k=0;k<2;k++)
        {
            for(int i=0;i<2;i++)
            {
                long long int sum = 0;
                for(int j=0;j<2;j++)
                {
                    sum += ((long long int)A1[k][j]*A2[j][i]);
                }
                res[k][i] = sum%mod;
            }
        }
        return res;
        
    }
    
    int pow(vector<vector<int>> &A,long long int N)
    {
        vector<vector<int>> res = {{1,1},{1,1}};
        while(N)
        {
            if(N%2) 
            {
                res = multiply(res,A);
                N--;
            }
            A = multiply(A,A);
            N /= 2;
        }
        return res[0][1]%mod;
    }
    
    int countStrings(long long int N) {
        vector<vector<int>> A = {{1,1},{1,0}};
        return pow(A,N+1);
    }
};