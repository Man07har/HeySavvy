/* Geek is extremely punctual but today even he is not feeling like doing his homework assignment. He must start doing it immediately in order to meet the deadline. For the assignment, Geek needs to type a string s.
To reduce his workload, he has decided to perform one of the following two operations till he gets the string.

Append a character at the end of the string.
Append the string formed thus far to the end of the string. (This can not be done more than once.)
Help Geek find the minimum operations required to type the given string.


Example 1:

Input:
s = abcabca
Output: 5
Explanation: a -> ab -> abc -> abcabc 
-> abcabca

Example 2:

Input:
s = abcdefgh
Output: 8
Explanation: a -> ab -> abc -> abcd 
-> abcde -> abcdef -> abcdefg -> abcdefgh

Your Task:  
You don't need to read input or print anything. Your task is to complete the function minOperation() which takes a string s as input parameter and returns the minimum operations required to type it.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 103 */

class Solution {
  public:
    int minOperation(string s) {
   
        int n = s.length();
        int mid = n/2;
        int matching_count = 0;
        int j = mid;
        
        int i = 0;
        
        if(n == 0 || n == 1)
            return n;
            
        
        while(i<mid) {
            
            if(s[i] == s[j]) {
                matching_count++;
                j++;
                
                
            }
            
            else {
                mid = mid - 1;
                j = mid;
                i = 0;
                matching_count = 0;
                continue;   
                
            }
            
            
            i++;
        }
        
        return n - matching_count + 1;
    }
};