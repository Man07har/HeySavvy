/* Given a number (n) and no. of digits (m) to represent the number, we have to check if we can represent n using exactly m digits in any base from 2 to 32.

Example 1:

Input: n = 8, m = 2
Output: Yes 
Explanation: Possible in base 3 as 8 in base 3 is 22.  

Example 2:

Input: n = 8, m = 3
Output: No
Explanation: Not possible in any base. 

Your Task:  
You dont need to read input or print anything. Complete the function baseEquiv() which takes n and m as input parameter and returns "Yes" if its possible to represent the number else "No" without quotes..

Expected Time Complexity: O(logN).
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <=109
1 <= m <=32 */

string baseEquiv(int n, int m)

    {

        string s = "";

        int f = 0 ;

        for(int ind = 2 ; ind <= 32 ; ind++)

        {

            int n1 = n ;

            int c = 0 ;

            while(n1 > 0 )

            {

                c = c + 1 ; 

                if(c > m)

                {

                    break ;

                }

                n1 = n1 / ind ;

            }

            if(c == m )

            {

                s = "Yes";

                f = 1 ;

                break ;

            }

        }

        if(f == 0 ) 

        {

            s = "No";

        }

        return s ;

    }