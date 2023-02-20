/* Given a triangular pyramid with its vertices marked as O, A, B and C and a number N, the task is to find the number of ways such that a person starting from the origin O initially, reaches back to the origin in N steps. In a single step, a person can go to any of its adjacent vertices.

Lightbox


Example 1:

Input:
N = 1
Output: 0
Explanation: The minimum length of
a cyclic path is 2.
Example 2:

Input:
N = 2
Output: 3
Explanation: The three paths are :
O-A-O, O-B-O, O-C-O

Your Task:  
You don't need to read input or print anything. Your task is to complete the function countPaths() which takes an integer N as input parameter and returns the number of possible paths. Since the answer may be big, return it modulo (10^9+7). 

*/

class Solution{   

public:

    long long int mod=1e9+7;

    int countPaths(int n){

        if(n==1){

            return 0;

        }

        if(n==2){

            return 3;

        }

        if(n==3){

            return 6;

        }

        if(n==4){

            return 21;

        }

        vector<long long int> dp(n+1,0);

        dp[1]=0;

        dp[2]=3;

        dp[3]=6;

        dp[4]=21;

        

 

        for(long int i=5;i<=n;i++){

            dp[i]=((2*dp[i-1])%mod+(dp[i-2]*dp[2])%mod)%mod;

        }

        // cout<<dp[20]%mod<<endl;

        return dp[n];

    }

};