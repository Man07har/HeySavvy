/*  Given a number, in the form of an array Num[] of size N containing digits from 1 to 9(inclusive). The task is to find the next smallest palindrome strictly larger than the given number.

Example 1:

Input:
N = 11
Num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2}
Output: 9 4 1 8 8 0 8 8 1 4 9
Explanation: Next smallest palindrome is
9 4 1 8 8 0 8 8 1 4 9
Example 2:

Input:
N = 5
Num[] = {2, 3, 5, 4, 5}
Output: 2 3 6 3 2
Explanation: Next smallest palindrome is
2 3 6 3 2
Your Task:
Complete the function generateNextPalindrome() which takes an array num, and a single integer n, as input parameters and returns an array of integers denoting the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= Num[i] <= 9 */

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> generateNextPalindrome(int num[], int n)
    {
        // code here

        int flag = 0;
        int l = 0, r = n - 1;
        while (l < r)
        {
            if (num[l] < num[r])
            {
                flag = -1;
            }
            else if (num[l] > num[r])
            {
                flag = 1;
            }
            num[r] = num[l];
            l++;
            r--;
        }

        if (flag == 0 or flag == -1)
        {
            l = (n - 1) / 2;
            while (l >= 0)
            {
                if (num[l] < 9)
                {
                    num[l] += 1;
                    num[n - l - 1] = num[l];
                    vector<int> v;
                    for (int i = 0; i < n; i++)
                        v.push_back(num[i]);
                    return v;
                }
                else
                {
                    num[l] = 0;
                    num[n - l - 1] = num[l];
                }
                l--;
            }
            vector<int> v;
            v.push_back(1);
            for (int i = 0; i < n; i++)
                v.push_back(num[i]);
            v[n] = 1;
            return v;
        }
        else
        {
            vector<int> v;
            for (int i = 0; i < n; i++)
                v.push_back(num[i]);
            return v;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends