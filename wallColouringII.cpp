/* There is a row of N walls in Geeksland. The king of Geeksland ordered Alexa to color all the walls on the occasion of New Year. Alexa can color each wall with one of the K colors. The cost associated with coloring each wall with a particular color is represented by a 2D costs array of size N * K. For example, costs[0][0] is the cost of coloring wall 0 with color 0; costs[1][2] is the cost of coloring wall 1 with color 2, and so on... Find the minimum cost to color all the walls such that no two adjacent walls have the same color.

Note: If you are not able to paint all the walls, then you should return -1.

Example 1:

Input:
N = 4, K = 3
costs[][] = {{1, 5, 7},
             {5, 8, 4},
             {3, 2, 9},
             {1, 2, 4}}

Output:
8
Explanation:
Paint wall 0 with color 0. Cost = 1
Paint wall 1 with color 2. Cost = 4
Paint wall 2 with color 1. Cost = 2
Paint wall 3 with color 0. Cost = 1
Total Cost = 1 + 4 + 2 + 1 = 8
Example 2:

Input:
N = 5, K = 1
costs[][] = {{5},
             {4}, 
             {9},
             {2},
             {1}}
Output:
-1
Explanation:
It is not possible to color all the walls under the given conditions.


Your Task:

Your task is to complete the function minCost() which takes a 2D integer matrix costs as the only argument and returns an integer, representing the minimum cost to paint all the walls. If you are not able to paint all the walls, then you should return -1

Expected Time Complexity: O(N*K)
Expected Space Complexity: O(N*K)

Constraints:

0 <= N <= 103
0 <= K <= 103
1 <= costs[i][j] <= 105
*/
class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        int minFirst = -1;
        int minSecond = -1;
        for(int j = 0;j<costs[0].size();j++){
            if(minFirst==-1 || costs[0][j]<costs[0][minFirst]){
                minSecond = minFirst;
                minFirst = j;
            }
            else if(minSecond == -1 || costs[0][j]<costs[0][minSecond])
            minSecond = j;
        }
        for(int i = 1;i<costs.size();i++){
            int curFirst = -1,curSecond = -1;
            for(int j = 0;j<costs[0].size();j++){
                if(minFirst!=-1 && minFirst!=j)
                costs[i][j] += costs[i-1][minFirst];
                else if(minSecond!=-1 && minSecond!=j)
                costs[i][j] += costs[i-1][minSecond];
                else
                costs[i][j] = 2*1e8;
                if(curFirst == -1 || costs[i][j]<costs[i][curFirst]){
                curSecond = curFirst;
                curFirst = j;
                }
                else if(curSecond == -1 || costs[i][j]<costs[i][curSecond])
                curSecond = j;
            }
            // cout<<endl;
            minFirst = curFirst;
            minSecond = curSecond;
        }
        int ans = *min_element(costs.back().begin(),costs.back().end());
        return ans==2*1e8?-1:ans;
    }
};
