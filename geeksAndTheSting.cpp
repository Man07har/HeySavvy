/* Our geek loves to play with strings, Currently, he is trying to reduce the size of a string by recursively removing all the consecutive duplicate pairs. In other words, He can apply the below operations any number of times.

Remove all the consecutive duplicate pairs and concatenate the remaining string to replace the original string.
Your task is to find the string with minimum length after applying the above operations.

Note: If the string length become zero after applying operations, return "-1" as a string.


Example 1:

Input:
aaabbaaccd
Output: 
ad
Explanation: 
Remove (aa)abbaaccd =>abbaaccd
Remove a(bb)aaccd => aaaccd
Remove (aa)accd => accd
Remove a(cc)d => ad
Example 2:

Input: 
aaaa
Output: 
Empty String
Explanation: 
Remove (aa)aa => aa
Again removing pair of duplicates then (aa) 
will be removed and we will get 'Empty String'.

Your Task:
This is a function problem. You only need to complete the function removePair() that takes a string as a parameter and returns the modified string. Return an empty string if the whole string is deleted.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= |str| <= 104 */

class Solution {
  public:
    string removePair(string s) {
        // code here
          stack<char>sp;
        for(int i=0;i<s.size();i++){
            if(!(sp.empty()) and sp.top()==s[i] ){
                sp.pop();
            }
            else {
                sp.push(s[i]);
            }
            
        }
        string ans="";
        while(!sp.empty()){
            ans+=sp.top();
            sp.pop();
        }
        if(ans.size()==0){
            return to_string(-1);
        }
        else {
        reverse(ans.begin(),ans.end());
        return ans;}
    }
};