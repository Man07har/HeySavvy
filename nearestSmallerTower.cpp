/* Given an array where each element (arr[i]) represents the height of the tower. Find for each tower, the nearest possible tower that is shorter than it. You can look left or right on both sides.

Note : 

If two smaller towers are at the same distance, pick the smallest tower.

If two towers have the same height then we choose the one with a smaller index.

Example 1:

Input: 

arr[] = {1,3,2}

Output: 

{-1,0,0}

Explanation:

For 0th Index : no tower is smallest, so -1.

For 1st Index : For 3, here 1 & 2 both are 

small & at a same distance, so we will pick 1, 

beacuse it has smallest value, so 0(Index)

For 2nd Index : here 1 is smaller, so 0(Index)

So the final output will be which consistes 

Indexes are {-1,0,0}.

Example 2:

Input: 

arr[] = {4,8,3,5,3}

Output: 

{2,2,-1,2,-1}

Explanation: 

For 0th Index : here 3 is the smaller, so 2(Index) 

For 1st Index : For 8, here 4 & 3 both are

small & at a same distance, so we will pick 3, so 2(Index)

For 2nd Index : no tower is smallest, so -1.

For 3rd Index : For 5, here 3 & 3 both are

small & at a same distance, so we will pick 

3(2nd Index) because it smaller Index, so 2(Index)

For 4th Index : no tower is smallest, so -1.

So the final output will be which consistes

Indexes are {2,2,-1,2,-1}.

Your Task:

You don't need to read input or print anything. Your task is to complete the function nearestSmallerTower() which takes an array of heights of the towers as input parameter and returns an array of indexes of the nearest smaller tower. If there is no smaller tower on both sides then return -1 for that tower.

Expected Time Complexity: O(N)

Expected Auxiliary Space: O(N) 

Constraints:

1 <= N <= 105

1 <= arr[i] <= 105 */



class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {     int n=arr.size();
        stack<int> stb,stf;
        vector<int> v1(n,1e7),v2(n,1e7);
       
        for(int i=0;i<n;i++){
            while(!stb.empty()&&arr[stb.top()]>=arr[i])
            stb.pop();
            if(!stb.empty())
            v1[i]=stb.top();
            stb.push(i);
        }
        
        for(int i=n-1;i>=0;i--){
            while(!stf.empty()&&arr[stf.top()]>=arr[i])
            stf.pop();
            if(!stf.empty())
            v2[i]=stf.top();
            stf.push(i);
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(v1[i]==1e7&&v2[i]==1e7)
            ans.push_back(-1);
            else if(i-v1[i]!=v2[i]-i){
              if(v1[i]!=1e7&&i-v1[i]<v2[i]-i)
              ans.push_back(v1[i]);
              else
              ans.push_back(v2[i]);
            }
            else{
                if(arr[v1[i]]<arr[v2[i]])
                    ans.push_back(v1[i]);
                   
                else if(arr[v1[i]]>arr[v2[i]])
                ans.push_back(v2[i]);
                else
                ans.push_back(min(v1[i],v2[i]));
            }
        }
        return ans;
    }
};
