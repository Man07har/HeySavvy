/* Ishaan has been given a task by his teacher. He needs to find the Nth term of a series. His teacher gives him some examples to help him out (Refer examples below). He is a bit weak in pattern searching so to help him his teacher told him that the Nth term is related to prime numbers. The Nth term is the difference of N and the closest prime number to N. Help him find the Nth term for a given N.
 

Example 1:

Input: N = 10
Output: 1
Explanation: Closest prime to 10 is 11.
Example 2:

Input: N = 7
Output: 0
Explanation: Closest prime to 7 is 7.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function NthTerm() which takes N as input paramater and returns Nth term.
 

Expected Time Complexity: O(N* √ N)
Expected Space Complexity: O(1)

Constraints:
1 <= N <= 100000 */

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

	class Solution
{
    public:
    bool isPrime(int n) {
        if(n < 2) {
            return false;
        }
        
        for(int i=2;i<=sqrt(n);i++) {
            if(n % i == 0) {
                return false;
            }
        }
        
        return true;
    }
    int NthTerm(int N)
    {
        // code here
        int x = N;
        
        int i=0;
        while(true) {
            if(isPrime(x-i)) {
                return N - (x-i);
            }
            
            if(isPrime(x+i)) {
                return (x+i) - N;
            }
            
             i++;
        }
    }
    
   
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		int ans = obj.NthTerm(N);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends