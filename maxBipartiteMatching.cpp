/* There are M job applicants and N jobs.  Each applicant has a subset of jobs that he/she is interested in. Each job opening can only accept one applicant and a job applicant can be appointed for only one job. Given a matrix G with M rows and N columns where G(i,j) denotes ith applicant is interested in the jth job. Find the maximum number of applicants who can get the job.

Example 1:

Input: 
M = 3, N = 5
G = {{1,1,0,1,1},{0,1,0,0,1},
{1,1,0,1,1}}
Output: 3
Explanation: There is one of the possible
assignment-
First applicant gets the 1st job.
Second applicant gets the 2nd job.
Third applicant gets the 4th job.
Example 2:

Input:
M = 6, N = 2
G = {{1,1},{0,1},{0,1},{0,1},
{0,1},{1,0}}
Output: 2
Explanation: There is one of the possible
assignment-
First applicant gets the 1st job.
Second applicant gets the 2nd job.
 

Your Task:
You don't need to read to print anything. Your task is to complete the function maximumMatch() which takes matrix G as input parameter and returns the maximum number of applicants who can get the job.

Expected Time Complexity: O(N3).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N, M ≤ 100 */

class Solution {
public:
    bool dfs(vector<unordered_map<int,int>> &graph, vector<bool> &visited, int start, int target){
        if(start==target) return true;
        for(auto& v : graph[start]){
            int next = v.first, capacity=v.second;
            if(visited[next] || capacity==0) continue;
            visited[next] = true;
            
            swap(graph[start][next], graph[next][start]);
            if(dfs(graph, visited, next, target)) return true;
            swap(graph[start][next], graph[next][start]);
        }
        return false;
    }
    
	int maximumMatch(vector<vector<int>>&G){
	    int i_applicants=G.size(), j_jobs=G[0].size(), finalnode = i_applicants+j_jobs;
	    // vector index : source
        // vector value map: key=target, value=capacity
        vector< unordered_map<int,int> > graph(i_applicants+j_jobs+1);
	    // applicant -> job
	    for(int i=0; i<i_applicants; i++) 
	        for(int j=0; j<j_jobs; j++) {
	            if(G[i][j]==0) continue;
	            graph[i][j+i_applicants]=1;
	        }
	    // job -> final node
	    for(int j=0; j<j_jobs; j++) graph[j+i_applicants][finalnode]=1;
        //
        int count=0;
        for(int i=0; i<i_applicants; i++){
            vector<bool> visited(i_applicants+j_jobs+1, false);
            if(dfs(graph, visited, i, finalnode)) count++;
        }
        return count;
    }
};