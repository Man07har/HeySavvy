/* Given a binary string S consists only of 0s and 1s. The task is to calculate the number of substrings that have more 1s than 0s.

Example 1:

Input:
S = "011"
Output: 4
Explanation: There are 4 substring which 
has more 1s than 0s. i.e "011","1","11" and "1"
Example 2:

Input:
S = "0000"
Output: 0
Explanation: There is no substring
which has more 1s than 0s
Your Task:  
You dont need to read input or print anything. Complete the function countSubstring() which takes the string S as input parameter and returns the number of substring which has more 1s than 0s.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)

Constraints:
1 < |S| < 105
|S| denotes the length of the string S */


class BIT
{
private:
    vector<int> bit;

public:
    BIT(int size = 0)
    {
        bit.assign(size + 1, 0);
    }
    int getsum(int idx)
    {
        int sum = 0;
        for (; idx > 0; idx -= idx & (-idx))
            sum += bit[idx];
        return sum;
    }
    void addvalue(int idx, int val)
    {
        for (; idx < bit.size(); idx += idx & (-idx))
        {
            bit[idx] += val;
        }
    }
};
class Solution{
public:
  long long countSubstring(string S){
      int n=S.size();
      BIT *b=new BIT(n);
    vector<long long int>pre(n,0);
    pre[0]=S[0]=='0'?-1:1;
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+(S[i]=='0'?-1:1);
    }
    map<long long,int>mp;
    for(int i=0;i<n;i++){
        mp[pre[i]]++;
    }
    long long int l=1;
    for(auto &el:mp){
        el.second=l++;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        if(pre[i]>0)ans++;
        ans+=b->getsum(mp[pre[i]]-1);
        b->addvalue(mp[pre[i]],1);
    }
    return ans;
  }
};