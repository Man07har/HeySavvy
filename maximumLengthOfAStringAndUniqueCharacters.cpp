/* You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.
 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters. */
  
  class Solution 
{
public:
    int maxLength(vector<string>& arr) 
    {
        int max_len = 0;
     
        vector<bitset<26>> unique;
        for (auto s : arr)
        {
            bitset<26> bin;
            for (char ch : s) bin.set(ch - 'a');
            if (bin.count() == s.size())
                unique.push_back(bin);
        }
     
        vector<bitset<26>> concat = {bitset<26>()};
        for (auto& u : unique)
            for (int i = concat.size() - 1; i >= 0; i--)
                if ((concat[i] & u).none())
                {
                    concat.push_back(concat[i] | u);
                    max_len = max(max_len, (int)(concat[i].count() + u.count()));
                }
        
        return max_len;
    }
};