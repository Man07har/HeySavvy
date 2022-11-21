/* Given a positive integer n, generate all possible unique ways to represent n as sum of positive integers.

Note: The generated output is printed without partitions. Each partition must be in decreasing order. Printing of all the partitions is done in reverse sorted order. 

Example 1:

Input: n = 3
Output: 3 2 1 1 1 1
Explanation: For n = 3, 
{3}, {2, 1} and {1, 1, 1}.
 

Example 2:

Input: n = 4 
Output: 4 3 1 2 2 2 1 1 1 1 1 1
Explanation: For n = 4, 
{4}, {3, 1}, {2, 2}, {2, 1, 1}, {1, 1, 1, 1}.

Your Task:
You don't need to read or print anything. Your task is to complete the function UniquePartitions() which takes n as input parameter and returns a list of all possible combinations in lexicographically decreasing order. 
 

Expected Time Complexity: O(2^n)
Expected Space Complexity: O(n)

 

Constraints:
1 <= n <= 25 */

Class Solution{
	public:
	vector<vector<int>> fans;
	void dfs(int n , vector<int >& ans , int cur , int prev  ){
	    if(cur > n){
	        return ;
	    }
	    if(n == 0){
	        fans.push_back(ans);
	        return ;
	    }
	    dfs(n , ans , cur + 1 , prev);
	    if(cur != 0 and cur <= prev){
	        ans.push_back(cur);
	        dfs(n - cur , ans , 0 , cur);
	        ans.pop_back();
	    }
	    
	    
	}
    vector<vector<int>> UniquePartitions(int n) {
        vector<int>ans;
        dfs(n , ans , 0 , n + 1);
      
        return fans;
    }
};