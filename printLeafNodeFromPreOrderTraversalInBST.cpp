/* Given a preorder traversal of a BST, find the leaf nodes of the tree without building the tree.


Example 1:

Input:
N = 2
arr = {2,1}
Output: {1}
Explaination: 1 is the only leaf node.

Example 2:

Input:
N = 3
Arr = {3, 2, 4}
Output: {2, 4}
Explaination: 2, 4 are the leaf nodes.

Your Task:
You don't need to read input or print anything. Your task is to complete the function leafNodes() which takes the array arr[] and its size N as input parameters and returns the leaf nodes of the tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 103
1 ≤ arr[i] ≤ 103 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  unordered_map<int,int>mp;
  
  void solve(int &i,int n,int arr[],vector<int>&in,int l,int r,vector<int>&ans){
      if(i>=n||l>r)return;
      if(l==r){
          ans.push_back(arr[i]);
      }
  int ind=mp[arr[i]];
  i++;
      solve(i,n,arr,in,l,ind-1,ans);
      
      solve(i,n,arr,in,ind+1,r,ans);

      return;
  }
    vector<int> leafNodes(int arr[],int n) {
        vector<int>in(n);
        
       for(int i=0;i<n;i++)in[i]=arr[i];
       sort(in.begin(),in.end());
       
       for(int i=0;i<n;i++)mp[in[i]]=i;
       
       vector<int>ans;
       int i=0;
       solve(i,n,arr,in,0,n-1,ans);
       return ans;
        
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
