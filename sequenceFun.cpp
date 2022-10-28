/* You don't need to read or print anything, Your task is to complete the function NthTerm() which takes n as input parameter and returns value at nth position of the given sequence modulo 109 + 7.
 

Expected Time Complexity:  O(n)
Expected Space Complexity: O(1)
 

Constraints:
1 <= n <= 104 */



#include<bits/stdc++.h>
using namespace std;



class Solution {

 public:

 int NthTerm(int n){


     int mod = 1e9+7;

 

     vector<long long int> dp(n+1,0);

 

     dp[0]=1;

 

     dp[1]=2;

 

     

     for(int i=2;i<=n;i++){


         dp[i]=((dp[i-1]*i)%mod + 1)%mod;

     }
     return dp[n]%mod;
 }

 

};
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
