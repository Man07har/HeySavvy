/* Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string that reads the same backward. More formally, S is a palindrome if reverse(S) = S. In case of conflict, return the substring which occurs first ( with the least starting index).

Example 1:

Input:
S = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic
substring is "aabbaa".
Example 2:

Input: 
S = "abc"
Output: a
Explanation: "a", "b" and "c" are the 
longest palindromes with same length.
The result is the one with the least
starting index.
Your Task:
You don't need to read input or print anything. Your task is to complete the function longestPalin() which takes the string S as input and returns the longest palindromic substring of S.

Expected Time Complexity: O(|S|2).
Expected Auxiliary Space: O(1).
 */


string longestPalin (string S) {
        int size=0 , start=0;
        for(int i=0 ; i<S.length() ; i++)
        {
            /* for odd sizes */
            int left = i , right = i;
            while(left>=0 && right<S.length())
            {
                if(S[left] != S[right]) break;
                left-- ;
                right++ ;
            }
            
            if((right-left-1) > size)
            {
                size = right - left - 1;
                start = left + 1;
            }
            
            /* for even sizes */
            left = i ; right = i+1;
            while(left>=0 && right<S.length())
            {
                if(S[left] != S[right]) break;
                left-- ;
                right++ ;
            }
            
            if((right-left-1) > size)
            {
                size = right - left - 1;
                start = left + 1;
            }
        }
        
        return S.substr(start,size);
    }