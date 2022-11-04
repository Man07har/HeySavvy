/* Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters. */

class Solution {
public:
    string reverseVowels(string s) {
          int strt = 0, end = s.size() - 1;
        char vow[256] = {0};
        vow['a'] = 1, vow['A'] = 1, vow['e'] = 1, vow['E'] = 1, vow['i'] = 1, vow['I'] = 1, vow['o'] = 1, vow['O'] = 1, vow['u'] = 1, vow['U'] = 1;
      
        while(strt < end){
            while(strt < end && vow[s[strt]] == 0) 
                strt++;
            while(strt < end && vow[s[end]] == 0) 
                end--;
            
            swap(s[strt],s[end]);
            strt++;end--;
        }
        return s;
    }
};