/* We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Constraints:

1 <= n <= 2000
0 <= dislikes.length <= 104
dislikes[i].length == 2
1 <= dislikes[i][j] <= n
ai < bi
All the pairs of dislikes are unique. */


class Solution {
    unordered_map<int,vector<int> > gr;
    vector<int> vis;
    vector<int> colo;
public:
    bool bfs(int u){
        colo[u]=1;
        queue<int> que;
        que.push(u);
        while(!que.empty()){
            int i=que.front();
            que.pop();
            for(auto v:gr[i]){
                if(colo[v]==-1){
                    colo[v]=1-colo[i];
                    que.push(v);
                }
                else if(colo[v]==colo[i]){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        for(auto d:dislikes){
            gr[d[0]].push_back(d[1]);
            gr[d[1]].push_back(d[0]);
        }
        colo.resize(N+1,-1);
        for(int i=1;i<=N;i++){
            if(colo[i]==-1){
                if(!bfs(i)){
                    return false;
                }
            }
        }
        return true;
    }
};