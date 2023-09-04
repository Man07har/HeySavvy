/* Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

Example 1:

Input:
n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'},
       {'X', 'O', 'X', 'X'},
       {'X', 'O', 'O', 'X'},
       {'X', 'O', 'X', 'X'},
       {'X', 'X', 'O', 'O'}}
Output:
ans = {{'X', 'X', 'X', 'X'},
       {'X', 'X', 'X', 'X'},
       {'X', 'X', 'X', 'X'},
       {'X', 'X', 'X', 'X'},
       {'X', 'X', 'O', 'O'}}
Explanation:
Following the rule the above matrix is the resultant matrix.
Example 2:



Input:
n = 5, m = 4
mat = {{'X', 'O', 'X', 'X'},
       {'X', 'O', 'X', 'X'},
       {'X', 'O', 'O', 'X'},
       {'X', 'O', 'X', 'X'},
       {'X', 'X', 'O', 'O'}}
Output:
ans = {{'X', 'O', 'X', 'X'},
       {'X', 'O', 'X', 'X'},
       {'X', 'O', 'O', 'X'},
       {'X', 'O', 'X', 'X'},
       {'X', 'X', 'O', 'O'}}
Explanation:
Following the rule the above matrix is the resultant matrix.
Your Task:
You do not need to read input or print anything. Your task is to complete the function fill() which takes N, M and mat as input parameters ad returns a 2D array representing the resultant matrix.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 500  */

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class cell
{
public:
    int x;
    int y;
    cell(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

class Solution
{
public:
    bool is_valid(int i, int j, int n, int m, vector<vector<bool>> &vis, vector<vector<char>> &mat)
    {
        if (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && mat[i][j] == 'O')
            return true;
        return false;
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<cell> q;

        // push all the corner O's into the queue
        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 'O')
            {
                vis[i][0] = true;
                q.push(cell(i, 0));
            }
            if (mat[i][m - 1] == 'O')
            {
                vis[i][m - 1] = true;
                q.push(cell(i, m - 1));
            }
        }

        for (int i = 1; i < m - 1; i++)
        {
            if (mat[0][i] == 'O')
            {
                vis[0][i] = true;
                q.push(cell(0, i));
            }
            if (mat[n - 1][i] == 'O')
            {
                vis[n - 1][i] = true;
                q.push(cell(n - 1, i));
            }
        }

        // direction arrays
        int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

        // BFS for all the corner O's and mark all the O's they touch as visited
        while (!q.empty())
        {
            auto c = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int new_x = c.x + dx[i], new_y = c.y + dy[i];
                if (is_valid(new_x, new_y, n, m, vis, mat))
                {
                    vis[new_x][new_y] = true;
                    q.push(cell(new_x, new_y));
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // if an O is unvisited it is untouched by corner O's and hence surrounded by X's only
                if (mat[i][j] == 'O' && !vis[i][j])
                    mat[i][j] = 'X';
            }
        }

        return mat;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends