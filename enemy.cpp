/* You live in Geek land. Geek land can be seen as a grid of shape N x M.There are K enemy at K positions. Each enemy blocks the row and column to which it belongs. You have to find the largest continuous area that is not blocked.No two enemies share the same row or the same column.

Example 1:

Input:
N = 2
M = 2
K = 1
enemy[]={{2,2}}
Output:
1
Explanation:
Since only (1,1) cell is free from the enemy hence answer is 1.
 

Example 2:

Input:
N = 3
M = 3
K = 1
enemy[]={{3,3}}
Output:
4
Explanation:
The cells (1,1),(1,2) ,(2,1) and (2,2) are free hence answer =4.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function largestArea() which takes the size of geek land n,m and a 2-D matrix enemy of size k denoting the coordinates of the enemy's and need to return the largest area that is free.

Expected Time Complexity: O(KlogK)
Expected Auxiliary Space: O(K)

Constraints:
1 <= N,M <= 104
0<=K<=min(N,M)
1<=Xi<=N
1<=Yi<=M */


#include<bits/stdc++.h>
using namespace std;



class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
    
            vector<int> row,col;
            row.push_back(0);
            col.push_back(0);
            for(auto &v:enemy){
                row.push_back(v[0]);
                col.push_back(v[1]);
            }
            row.push_back(n+1);
            col.push_back(m+1);
            sort(row.begin(),row.end());
            sort(col.begin(),col.end());
            int row_mx = 0,col_mx = 0;
            for(int i=1;i<row.size();i++){
                row_mx = max(row_mx,row[i]-row[i-1]-1);
                col_mx = max(col_mx,col[i]-col[i-1]-1);
            }
            return row_mx*col_mx;
        }
};



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
