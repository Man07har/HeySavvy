/* A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

 

Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
Example 2:

Input: sentence = "leetcode"
Output: false
 

Constraints:

1 <= sentence.length <= 1000
sentence consists of lowercase English letters. */

class Solution {
public:   
    bool checkIfPangram(string s) {
        vector<int>v(26);
        for(int p=0;p<s.length();p++){
            v[s[p]-97]++;
        }
        for(int p=0;p<26;p++){
            if(v[p]==0){
                return false;
            }
        }
        return true;
    }
};