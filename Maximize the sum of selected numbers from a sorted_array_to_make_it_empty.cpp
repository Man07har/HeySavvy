/* Given a array of N numbers, we need to maximize the sum of selected numbers. At each step, you need to select a number Ai, delete one occurrence of Ai-1 (if exists), and Ai each from the array. Repeat these steps until the array gets empty. The problem is to maximize the sum of the selected numbers.

Note: Numbers need to be selected from maximum to minimum.

Example 1:

Input : arr[ ] = {1, 2, 2, 2, 3, 4}
Output : 10
Explanation:
We select 4, so 4 and 3 are deleted leaving us with {1,2,2,2}.
Then we select 2, so 2 & 1 are deleted. We are left with{2,2}.
We select 2 in next two steps, thus the sum is 4+2+2+2=10.

Example 2:

Input : arr[ ] = {1, 2, 3} 
Output :  4
Explanation: We select 3, so 3 and 2 are deleted leaving us with {1}. Then we select 1, 0 doesn't exist so we delete 1. thus the sum is 3+1=4.
 

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function maximizeSum() that takes an array (arr), sizeOfArray (n), and return the maximum sum of the selected numbers. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 105
 */

#include <bits/stdc++.h> 
using namespace std; 
  


class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
      unordered_map<int,int> m;
        
        for(int i = 0; i < n; i++) {
            m[a[i]]++;
        }
        
        int ans = 0;     
        for(int i = n-1; i >= 0; i--) {
            auto it1 = m.find(a[i]);
            if(it1 == m.end()) continue;         
            auto it = m.find(a[i]-1);
            if(it != m.end()) {
                int oc = min(it->second,m[a[i]]);
                ans += a[i]*oc;
                m[a[i]] -= oc;
                m[a[i]-1] -= oc;
                if(m[a[i]] <= 0) m.erase(a[i]);
                if(m[a[i]-1] <= 0) m.erase(a[i]-1);
            }
            else {
                ans += a[i]*m[a[i]];
                m[a[i]] = 0;             
            }         
        }
        return ans;    
    }

};






int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}



