/* You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operator.You need to return an array of size k.

 

Example 1:

Input: n = 4
m = 5
k = 4
A = {{1,1},{0,1},{3,3},{3,4}}

Output: 1 1 2 2
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011
 

 

Example 2:

Input: n = 4
m = 5
k = 4
A = {{0,0},{1,1},{2,2},{3,3}}

Output: 1 2 3 4
Explanation:
0.  00000
    00000
    00000
    00000
1.  10000
    00000
    00000
    00000
2.  10000
    01000
    00000
    00000
3.  10000
    01000
    00100
    00000
4.  10000
    01000
    00100
    00010
 

Your Task:
You don't need to read or print anything. Your task is to complete the function numOfIslands() which takes an integer n denoting no. of rows in the matrix, an integer m denoting the number of columns in the matrix and a 2D array of size k denoting  the number of operators.

Expected Time Complexity: O(m * n)
Expected Auxiliary Space: O(m * n)

Constraints:

1 <= n,m <= 100
1 <= k <= 1000 */

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void dfs(int i, int j, int n, int m , vector<vector<int>> &temp)
    {
       
        if(temp[i][j]!= 1) return;
          
          temp[i][j] = -1;  
          
          if(i-1>=0)
          dfs(i-1,j,n,m,temp);     
          if(i+1<n)
          dfs(i+1,j,n,m,temp);  
          if(j-1>=0)
          dfs(i,j-1,n,m,temp);
          if(j+1<m)
          dfs(i,j+1,n,m,temp);     
        
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {


         vector<vector<int>> mat(n, vector<int>(m,0));         

         vector<int> ans;
 
         int ct = 0;


          for(int i=0;i<op.size();i++)
           {
  
                mat[op[i][0]][op[i][1]] = 1;
        
               vector<vector<int>> temp = mat;  


                for(int j=0;j<n;j++)
                {
                   for(int k=0;k<m;k++)
                    {
                  
                     if(temp[j][k]==1 && temp[j][k]!=-1)
                     {
                         dfs(j,k,n,m,temp);
                        
                         ct++;
                     }
                 
                   }
            
                }
               ans.push_back(ct);
               temp.clear();
               ct=0;
           }
         return ans;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

