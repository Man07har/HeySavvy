/* Santa is still not married. He approaches a marriage bureau and asks them to hurry the process. The bureau checks the list of eligible girls of size N and hands it over to Santa. Santa being conscious about his marriage is determined to find a girl with maximum connections so that he can gather more information about her. Accordingly, he looks to figure out the maximum number of girls (from the list) who know each other to achieve the above purpose.

In order to finalize the girl, he needs to find the Kth prime. Where k = largest group of girls who know each other. Considering Santa's poor knowledge of Maths, he seeks Banta's help for the answer. Now you, a fan of Santa Banta Jokes, take this prestigious opportunity to solve the problem.

In case no of connections is zero, print "-1". Here the connection between girls is represented by a 2-D array g of dimension M*2, where M is the number of connections.

Note :
1. Suppose girl "a" knows girl "b" and girl "b" knows girl "c", then girl "a" also knows girl "c". Transitivity holds here.
2. Consider 1 as a composite number.
3. For precompute function given in the template you just have to complete it and use it wherever required, do not call it again and again, it is already being called by driver function before executing test cases. 

Example 1:

Input : 
N = 10
M = 6
g[] = {{1,2},{2,3},{3,4},{4,5},{6,7},{9,10}}
Output : 
11
Explanation:
Here in this graph there are 4 groups. 
In 1st group: (1 -> 2 -> 3 -> 4 -> 5) are 
there. In 2nd group: (6 -> 7) are there.
In 3rd group: (8) is there.
In 4th group: (10 -> 9) are there.
In these 4 group the maximum number of 
value is 5. So, K = 5 and the 5th prime number 
is 11. Return 11.
Example 2:

Input : 
N = 2
M = 1
g[] = {{1, 2}} 
Output : 
3
Explanation:
In this Example there will only be a 
single group of 2 girls, and hence the 
value of K is 2, The 2nd prime is 3.
Your Task:

This is a function problem. The input is already taken care of by the driver code. You only need to complete the function helpSanta() that takes a number of girls (n), a number of connections (m), a 2-D array of girls connections (g), and return the Kth prime no if there are no connections then return -1. The driver code takes care of the printing.

Expected Time Complexity: O(N + M).
Expected Auxiliary Space: O(N + M).

Constraints:
1 ≤ n ≤ 105
0 ≤ m ≤ 105
1 ≤ u, v ≤ n
Sum of n+m will not exceed 105. */

class Solution{
public:
    vector<int>prime;
    void precompute(){
        // seive is done here...
        vector<bool>isprime(1e6+1,true);
        isprime[0]=false;
        isprime[1]=false;
        for(int i=2;i<1e6+1;i++)
        {
            if(isprime[i]==true)
            {
                prime.push_back(i);
                int j=2*i;
                while(j<1e6+1)
                {
                    isprime[j]=false;
                    j=j+i;
                }
            }
        }
    }
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,int &teamsize){
        teamsize++; // value of teamsize is increased...
        vis[node]=1;
        for(auto child:adj[node]){
            if(vis[child]==0){
                dfs(child,adj,vis,teamsize);
            }
        }
    }
    int helpSanta(int n,int m,vector<vector<int>>&g){
        vector<int>vis(n+1,0);
        int maxi=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                int teamsize=0; //initializing the teamsize variable...
                dfs(i,g,vis,teamsize); //dfs function to traverse through each connected nodes....
                maxi=max(maxi,teamsize); //maximizing the team size...
            }
        }
        if(maxi==1){
            return -1;
        }
        return prime[maxi-1];
    }
};