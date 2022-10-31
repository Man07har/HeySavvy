/* Given an array A[ ] of N of  integers, find the index of values that satisfy A + B = C + D where A,B,C & D are integers values in the array.
Note: As there may be multiple pairs satisfying the equation return lexicographically smallest order of  A, B, C and D and return all as -1 if there are no pairs satisfying the equation.

 

Example 1:

Input:
N = 7
A[] = {3, 4, 7, 1, 2, 9, 8}
Output:
0 2 3 5
Explanation:
A[0] + A[2] = 3+7 = 10
A[3] + A[5] = 1+9 = 10
Example 2:

Input:
N = 4
A[] = {424, 12, 31, 7}
Output:
-1 -1 -1 -1
Explanation:
There are no pairs satisfying the equation.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function satisfyEqn() which takes an Integer N and an array A[] of size N as input and returns a vector of 4 integers denoting A, B, C, and D respectively.

 

Expected Time Complexity: O(N2*logN2)
Expected Auxiliary Space: O(N2)

 

Constraints:
1 <= N <= 500
1 <= A[i] <= 105 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
     vector<int> satisfyEqn(int arr[], int n) {
        unordered_map<int,pair<int,int>> mp;
        set<vector<int>> st;
        vector<int> temp(4,-1);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(mp.find(arr[i]+arr[j])!=mp.end()){
                    temp[0]=mp[arr[i]+arr[j]].first;
                    temp[1]=mp[arr[i]+arr[j]].second;
                    temp[2] = i;
                    temp[3] = j;
                    if(temp[0]!=temp[2] && temp[0]!=temp[3] && temp[1]!=temp[2] && temp[1]!=temp[3])
                        st.insert(temp);
                }else
                mp[arr[i]+arr[j]]={i,j};
            }
        }
        if(temp[0]==-1)
            return temp;
        return *(st.begin());
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
