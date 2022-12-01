/* You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

 

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
 

Constraints:

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters. */

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int a=0,b=0;
        vector<char>voy={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i=0;i<n/2;i++){
            for(auto x : voy){
                if(s[i]==x){
                    a++;
                    break;
                }
            }
        }
        for(int i=n/2;i<n;i++){
            for(auto x : voy){
                if(s[i]==x){
                    b++;
                    break;
                }
            }
        }
        return a==b;
    }
};