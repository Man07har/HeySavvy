/* You are given a matrix of dimension n*n. All the cells are initially, zero. You are given Q queries, which contains 4 integers a b c d where (a,b) is the TOP LEFT cell and (c,d) is the Bottom Right cell of a submatrix. Now, all the cells of this submatrix have to be incremented by one. After all the Q queries have been performed. Your task is to find the final resulting Matrix.
Note : Zero-Based Indexing is used for cells of the matrix. 
 

Example 1:

Input: n = 6, q = 6,
Queries = {
{4,0,5,3},
{0,0,3,4},
{1,2,1,2},
{1,1,2,3},
{0,0,3,1},
{1,0,2,4}}.
Output: 
2 2 1 1 1 0
3 4 4 3 2 0 
3 4 3 3 2 0
2 2 1 1 1 0
1 1 1 1 0 0
1 1 1 1 0 0
Explanation:After incrementing all the
sub-matrices of given queries we will 
get the final output.

 

 

Example 2:

Input: n = 4, q = 2,
Queries = {
{0,0,3,3},
{0,0,2,2}}.
Output: 
2 2 2 1 
2 2 2 1  
2 2 2 1 
1 1 1 1 
Explanation:After incrementing all the
sub-matrices of given queries we will
get the final output.
Your Task:
You don't need to read or print anything. Your task is to complete the function solveQueries() which takes n and Queries and input parameter and returns a matrix after performing all the queries.
 

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)
 

Constraints:
1 <= n <= 1000
0 <= a <= c < n
0 <= b <= d < n
1 <= No. of Queries <= 1000 */
class Solution {
  public:
  vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {

        // Code here

        vector<vector<int>> ans(n,vector<int>(n,0));

        

        for(auto t:  Queries){

            int a=t[0] ;

            int b=t[1] ;

            int c=t[2] ;

            int d=t[3] ;

            for(int j=a;j<=c;j++){

                for(int k=b;k<=d;k++){

                    ans[j][k]++;

                }

            }

        }

        return ans;

    }
};