/* Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters. */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>>res;
        unordered_map<string,vector<string>>mp;
        for(auto&i: strs)
            {
            string t=i;//created a copy
			
            sort(t.begin(),t.end());//sorted to get the key
            mp[t].push_back(i);//pushed the initial string in map
        }
        for(auto&i:mp)
            {
            res.push_back(i.second);
            }
        return res;
    }
};