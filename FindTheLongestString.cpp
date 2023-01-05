/* Given an array of strings arr[]. You have to find the longest string which is lexicographically smallest and also all of its prefix strings are already present in the array.

 

Example 1:

Input: ab a abc abd

Output: abc

Explanation: We can see that length of the longest 

string is 3. And there are two string "abc" and "abd"

of length 3. But for string "abc" , all of its prefix

"a" "ab" "abc" are present in the array. So the

output is "abc".

Example 2:

Input: ab a aa abd abc abda abdd abde abdab

Output: abdab

Explanation: We can see that each string is fulfilling

the condition. For each string, all of its prefix 

are present in the array.And "abdab" is the longest

string among them. So the ouput is "abdab".

 

Your Task:  

You don't need to read input or print anything. Your task is to complete the function longestString() which takes the array arr[] as input parameter and returns the longest string which is also lexicographically smallest.And if there is no such string return empty string.

 

Expected Time Complexity: O(NlogN)

Expected Space Complexity: O(N)

 

Constraints:

1 <= length of arr[] <= 103

1 <= arr[i].length <=30 */
class Solution
{
public:
    static bool compare(string s1, string s2)
    {
        return s1.length() < s2.length();
    }
    string longestString(vector<string> &words)
    {
        // code here
        sort(words.begin(),words.end(),compare);
        unordered_map<string, int> mp;
        vector<string> res;
        int maxi =0;
        for(int i=0;i<words.size();i++)
        {
            int a = words[i].length();
            string s = words[i].substr(0,a-1);
            if(words[i].length()== 1)
            {
                mp[words[i]]++;
                maxi = max(maxi, a);
                res.push_back(words[i]);
            }
            else if(mp[s] > 0)
            {
                mp[words[i]]++;
                maxi = max(maxi, a);
                res.push_back(words[i]);
            }
            
        }
        sort(res.begin(), res.end());
        for(int i=0;i<res.size();i++)
        {
            if(res[i].length()== maxi)
            {
                return res[i];
            }
        }
        return "";
    }
};


