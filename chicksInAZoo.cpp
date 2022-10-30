/* Initially, the zoo have a single chick. A chick gives birth to 2 chicks every day and the life expectancy of a chick is 6 days. Zoo officials want to buy food for chicks so they want to know the number of chicks on an Nth day. Help the officials with this task.
 

Example 1:

Input: N = 2 
Output: 3
Explanation: First day there is only 1 chick.
On second day total number of chicks = 3. 
Example 2:

Input: N = 3
Output: 9
Explanation: First day there is only 1 chick.
On second day total number of chicks = 3.
On third day total number of chicks = 9
 

Your Task:
You don't need to read or print anything, Your task is to complete the function NoOfChicks() which takes N as the input parameter and returns the total no. of chicks on the Nth day.
 

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
 

Constraints:
1 <= N <= 35 */


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	long long int NoOfChicks(int n){
	  long long int popn[36];
	  long long int brth[36];
	  
	  popn[0]=0;popn[1]=1;
	  brth[0]=0;brth[1]=1;
	  
	  for(int i=2;i<=6;i++){
	      brth[i]=2*(popn[i-1]-0);
	      popn[i]=brth[i]+popn[i-1];
	  }
	  
	  for(int i=7;i<=n;i++){
	      brth[i]=2*(popn[i-1]-brth[i-6]);
	      popn[i]=popn[i-1]+brth[i]-brth[i-6];
	  }
	  return popn[n];
	}
};
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}