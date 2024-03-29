/* Given a binary matrix mat[][] of dimensions NxM such that 1 denotes land and 0 denotes water. Find the number of closed islands in the given matrix.

Note: A closed island is a group of 1s surrounded by only 0s on all the boundaries (except diagonals). In simple words, a closed island is an island whose none of the 1s lie on the edges of the matrix.

Example 1:

Input:
N = 5, M = 8
mat[][] = {{0, 0, 0, 0, 0, 0, 0, 1}, 
           {0, 1, 1, 1, 1, 0, 0, 1}, 
           {0, 1, 0, 1, 0, 0, 0, 1}, 
           {0, 1, 1, 1, 1, 0, 1, 0}, 
           {1, 0, 0, 0, 0, 1, 0, 1}}
Output:
2
Explanation:
mat[][] = {{0, 0, 0, 0, 0, 0, 0, 1}, 
           {0, 1, 1, 1, 1, 0, 0, 1}, 
           {0, 1, 0, 1, 0, 0, 0, 1}, 
           {0, 1, 1, 1, 1, 0, 1, 0}, 
           {1, 0, 0, 0, 0, 1, 0, 1}} 
There are 2 closed islands. The islands in dark are closed because they are completely surrounded by 0s (water). There are two more islands in the last column of the matrix, but they are not completely surrounded by 0s. Hence they are not closed islands. 
Example 2:

Input:
N = 3, M = 3
mat[][] = {{1, 0, 0},
           {0, 1, 0},
           {0, 0, 1}}
Output: 
1
Explanation:
mat[][] = {{1, 0, 0},
          {0, 1, 0},
          {0, 0, 1}}
There is just a one closed island.
Your task:
You dont need to read input or print anything. Your task is to complete the function closedIslands() which takes two integers N and M, and a 2D binary matrix mat as input parameters and returns the number of closed islands.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(N*M)

Constraints:
1 ≤ N,M ≤ 500 */

class Solution {
    public:
    bool solve(vector<vector<int>>&mat,int i,int j,int n,int m){
        if(i>=n||i<0||j<0||j>=m)return false;
        if(mat[i][j]==0||mat[i][j]==2)return true;
        mat[i][j]=2;
        bool l=solve(mat,i-1,j,n,m);
        bool r=solve(mat,i+1,j,n,m);
        bool u=solve(mat,i,j-1,n,m);
        bool d=solve(mat,i,j+1,n,m);
        return l&&r&&u&&d;
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
     int ans=0;
      for(int i=0;i<N;i++){
          for(int j=0;j<M;j++){
              if(matrix[i][j]==1){
                  if(solve(matrix,i,j,N,M)){
                      ans++;
                      
                  }
              }
          }
      }
      return ans;
    }
};