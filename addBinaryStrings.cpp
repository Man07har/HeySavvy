/* Given two binary strings A and B consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.


Example 1:

Input:
A = "1101", B = "111"
Output: 10100
Explanation:
 1101
+ 111
10100
Example 2:

Input: 
A = "10", B = "01"
Output: 11
Explanation: 
  10
+ 01
  11

Your Task:
You don't need to read input or print anything. Your task is to complete the function addBinary() which takes 2 binary string A and B and returns a binary string denoting the addition of both the strings.


Expected Time Complexity: O(max(|A|, |B|)).
Expected Auxiliary Space: O(max(|A|, |B|)) (for output string).


Constraints:
1 ≤ |A|, |B| ≤ 106 */

class Solution{

public:

    

    string process( string s ){

        

        int i = 0;

        for ( auto it : s ){

            

            if ( it == '0' )

                i++;

            

            else

                break;

        }

        

        return s.substr(i);

    }

 

 string addBinary(string A, string B)

 {

     int n = A.length();

     int m = B.length();

     

     int i = n-1;

     int j = m-1;

     

     int carry = 0;

     string ans = "";

     

     while( i >= 0 && j >= 0 ){

         int digit = (A[i]-'0') + (B[j]-'0') + carry;

         ans.push_back( digit % 2 + '0' );

         carry = digit / 2;

             i--; j--;

     }

     

     while( i >= 0 ){

         int digit = (A[i]-'0') + carry;

         ans.push_back( digit % 2 + '0' );

         carry = digit / 2;

         i--;

     }

     

     while( j >= 0 ){

         int digit = (B[j]-'0') + carry;

         ans.push_back( digit % 2 + '0' );

         carry = digit / 2;

         j--;

     }

    

     if ( carry  )

         ans.push_back(carry +'0');

         

     reverse(ans.begin(), ans.end());

     return process(ans);   

 }

};