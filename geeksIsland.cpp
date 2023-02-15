/* Geeks Island is represented by an N * M matrix mat. The island is touched by the Indian Ocean from the top and left edges and the Arabian Sea from the right and bottom edges. Each element of the matrix represents the height of the cell.

Due to the rainy season, the island receives a lot of rainfall, and the water can flow in four directions(up, down, left, or right) from one cell to another one with height equal or lower.

You need to find the number of cells from where water can flow to both the Indian Ocean and the Arabian Sea.

Example 1:

Input:
N = 5, M = 5
mat[][] =    {{1, 3, 3, 2, 4},
               {4, 5, 6, 4, 4},
               {2, 4, 5, 3, 1},
               {6, 7, 1, 4, 5},
               {6, 1, 1, 3, 4}}
Output:
8
Explanation:
Indian    ~   ~   ~   ~   ~
Ocean  ~  1   3   3   2  (4) *
        ~  4   5  (6) (4) (4) *
        ~  2   4  (5)  3   1  *
        ~ (6) (7)  1   4   5  *
        ~ (6)  1   1   3   4  *           
           *   *   *   *   * Arabian Sea
Water can flow to both ocean and sea from the cells
denoted by parantheses().For example at index(1,2), the height of that island is 6. If a water drop falls on that island, water can flow to up direction(as 3<=6) and reach to Indian Ocean. ALso, water can flow to right direction(as 6>=4>=4) and reach to Arabian Sea.
Example 2:

Input:
N = 2, M = 3
mat[][] =    {{1, 1, 1},
               {1, 1, 1}}
Output:
6 
Explanation:
Water can flow from all cells to both Indian Ocean and Arabian Sea as the height of all islands are same.
Your Task:

Your task is to complete the function water_flow() which takes an integer array mat, integer N and integer M as the input parameter and returns an integer, denoting the number of cells from which water can to both ocean and sea.

Expected Time Complexity : O(N*M)
Expected Auxiliary Space : O(N*M)

Constraints:

1 <= N, M <= 103
1 <= mat[i][j] <= 106 */


class Solution{   
public:
void dfs(int i, int j, vector<vector<bool>> &ocean, int n, int m, vector<vector<int>> &mat, int lst) {
        if (i<0 || j<0 || i>=n || j>=m || ocean[i][j] || mat[i][j] < lst) {
            return;
        }
        ocean[i][j]=true;
        dfs(i+1, j, ocean, n, m, mat, mat[i][j]);
        dfs(i, j+1, ocean, n, m, mat, mat[i][j]);
        dfs(i-1, j, ocean, n, m, mat, mat[i][j]);
        dfs(i, j-1, ocean, n, m, mat, mat[i][j]);
    }
    int water_flow(vector<vector<int>> &mat,int n,int m){
    // Write your code here.
    vector<vector<int>> ans;
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        for (int i=0; i<n; i++) {
            dfs(i, 0, pacific, n, m, mat, INT_MIN);
            dfs(i, m-1, atlantic, n, m, mat, INT_MIN);
        }
        for (int j=0; j<m; j++) {
            dfs(0, j, pacific, n, m, mat, INT_MIN);
            dfs(n-1, j, atlantic, n, m, mat, INT_MIN);
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans.size();
    }
};