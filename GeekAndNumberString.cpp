/* Geek has a string Sof size Nconsisting of characters from '0'to '9'. He wants to minimise the length of the string. In each minimising operation, geek can remove any two consecutive characters if they are of the form {"12", "21", "34", "43", "56", "65", "78", "87", "09", "90"}.
Find the minimum possible length of the string after applying minimising operations. 
 

Example 1:

Input: 
N = 5 
S = "12213"
Output: 1
Explanation: Geek can get the string of 
length 1 in two minimising operation,
In 1st operation Geek will remove "12" 
from "12213" then Geek left with "213"
In 2nd operation Geek will remove "21" 
from "213" then Geek left with "3"
 

Example 2:

Input: 
N = 4
S = "1350"
Output: 4
Explanation: Can't remove any character.
 

Your Task:  
You don't need to read input or print anything. Complete the functionminLength() which takes N and S as input parameters and returns the the minimum possible length of the string.


Expected Time Complexity: O(N)
Expected Auxiliary Space:O(N) */

class Solution{
public:
   int minLength(string s, int n) {

        // code here

        stack<char> st;

        

        for(int i=0;i<n;i++)

        {

            if(st.size()>0)

            {

                if(st.top()=='1'&& s[i] == '2' || st.top()=='2' && s[i] == '1'

                || st.top()=='3' && s[i] == '4' || st.top()=='4' && s[i] == '3' 

                || st.top()=='5' && s[i] == '6' || st.top()=='6' && s[i] == '5'

                || st.top()=='7' && s[i] == '8' || st.top()=='8' && s[i] == '7'

                || st.top()=='9' && s[i] == '0' || st.top()=='0' && s[i] == '9')

                {

                    // cout << st.top() << " ";

                    st.pop();

                }

                else

                {

                    st.push(s[i]);

                }

            }

            else

            {

                st.push(s[i]);

            }

        }

        

        return st.size();

    } 
};
