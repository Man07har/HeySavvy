/* Given a string S. The task is to find all permutations (need not be different) of a given string.

Example 1:

Input:
S = AAA
Output: AAA AAA AAA AAA AAA AAA
Explanation: There are total 6 permutations, as given in the output.
Example 2:

Input:
S = ABSG
Output: ABGS ABSG AGBS AGSB ASBG ASGB
BAGS BASG BGAS BGSA BSAG BSGA GABS
GASB GBAS GBSA GSAB GSBA SABG SAGB
SBAG SBGA SGAB SGBA
Explanation: There are total 24 permutations, as given in the output.
Your Task:
This is a function problem. You only need to complete the function permutation that takes S as parameter and returns the list of permutations in lexicographically increasing order. The newline is automatically added by driver code.

Constraints:
1 ≤ size of string ≤ 5

Expected Time Complexity: O(N * N!), N = length of string.
Expected Auxiliary Space: O(1)  */



 void solve(int i, int n, vector<string>&ans, string &S){
        if(i==n){
            ans.push_back(S);
            return;
        }
        
        for(int j=i; j<n; j++){
            swap(S[i], S[j]);
            solve(i+1, n, ans, S);
            swap(S[i], S[j]);
        }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        int n=S.size();
        if(n==0 || n==1) return {S}; 
        vector<string>ans;
        solve(0, n, ans, S);
        sort(ans.begin(), ans.end());
        return ans;
    }