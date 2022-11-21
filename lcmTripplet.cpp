/* Given a number N.Find the maximum possible LCM that can be attained by any three numbers less than or equal to N.
Note- LCM stands for Lowest Common Multiple. Also, Numbers can be repeated.

Example 1:

Input:
N=9
Output:
504
Explanation:
504 is the maximum LCM that can be attained
by any triplet of numbers less than or equal 9.
The triplet which has this LCM is {7,8,9}.
Example 2:

Input:
N=7
Output:
210
Explanation:
210 is the maximum LCM that can be attained
by any triplet of numbers less than or equal 7.
The triplet which has this LCM is {5,6,7}.

Your Task:
You don't need to read input or print anything. Your task is to complete the function lcmTriplets() that takes a number N as input parameter and returns the maximum LCM that can be attained by any three numbers less than or equal to N.


Expected Time Complexity:O(logN)
Expected Auxillary Space:O(logN)


Constraints:
1<=N<=106  */


#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
   long long lcmTriplets(long long N) {


        if(N<=2)

        {

           return N;

        }

        if(N%2==0)

        {

            if(N%3==0)

            {

                return (N-1)*(N-2)*(N-3);

            }

            else

            {

                return (N-1)*(N-3)*N;

            }

        }

        else

        {

            return (N-1)*(N-2)*N;

        }
    

    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.lcmTriplets(N) << "\n";
    }
}
