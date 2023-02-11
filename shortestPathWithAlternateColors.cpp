/* You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.

 

Example 1:

Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
Output: [0,1,-1]
Example 2:

Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
Output: [0,1,-1]
 

Constraints:

1 <= n <= 100
0 <= redEdges.length, blueEdges.length <= 400
redEdges[i].length == blueEdges[j].length == 2
0 <= ai, bi, uj, vj < n */

class Solution {

public:
    struct Node {
        int number;
        vector<int> blueCities;
        vector<int> redCitites;

        Node(int number) {
            this->number = number;
        }
    };

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, Node> hashMap;
        for (int i = 0; i < n; i++) {
            hashMap.insert({i,Node(i)});
        }
        for (auto redEdge : redEdges) {
            hashMap.at(redEdge[0]).redCitites.push_back(redEdge[1]);
        }
        for (auto blueEdge : blueEdges) {
            hashMap.at(blueEdge[0]).blueCities.push_back(blueEdge[1]);
        }
        vector<int> ans(n, -1);
        vector<vector<bool>> visit(n, vector<bool>(2, false));
        queue<vector<int>> q;
        q.push({0, 0, -1});
        ans[0] = 0;
        visit[0][0] = visit[0][1] = true;

        while (!q.empty()) {
            auto element = q.front();
            q.pop();
            int nodeNumber = element[0], steps = element[1], prevColor = element[2];

            for (auto neighbor : hashMap.at(nodeNumber).redCitites) {
                if (!visit[neighbor][0] && prevColor != 0) {
                    if (ans[neighbor] == -1) ans[neighbor] = 1 + steps;
                    visit[neighbor][0] = true;
                    q.push({neighbor, 1 + steps, 0});
                }
            }
            for (auto neighbor : hashMap.at(nodeNumber).blueCities) {
                if (!visit[neighbor][1] && prevColor != 1) {
                    if (ans[neighbor] == -1) ans[neighbor] = 1 + steps;
                    visit[neighbor][1] = true;
                    q.push({neighbor, 1 + steps, 1});
                }
            }

        }
        return ans;
    }
};