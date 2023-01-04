/*Given a list intervals of n intervals, the ith element [s, e, p] denotes the starting point s, ending point e, and the profit p earned by choosing the ith interval. Find the maximum profit one can achieve by choosing a subset of non-overlapping intervals.

Two intervals [s1, e1, p1] and [s2, e2, p2] are said to be non-overlapping if [e1 <= s2] and [s1 < s2].

Example 1:

Input:

n = 3

intervals = {

{1, 2, 4},

{1, 5, 7},

{2, 4, 4}

}

Output:

8

Explanation:

One can choose intervals [1, 2, 4] and [2, 4, 4] for a 

profit of 8.

Example 2:

Input:

n = 3

intervals = {

{1, 4, 4},

{2, 3, 7},

{2, 3, 4}

}

Output:

7

Explanation:

One can choose interval [2, 3, 7] for a profit of 7.

Your Task:

You don't need to print or output anything. Complete the function maximum_profit() which takes an integer n and a 2D integer array intervals and returns an integer, denoting the maximum profit which one can get by choosing the non-overlapping intervals.

Constraints:

1 <= n and n <= 104

1 <= starting point of ith interval < ending point of ith interval <= 105

1 <= profit earned by choosing ith interval <= 105*/
class Solution {

  public:

    static bool fun(const vector<int>&a,const vector<int>&b)

    {

        if(a[1]==b[1])

        {

            return a[0]<b[0];

        }

        return a[1]<b[1];

    }

    int maximum_profit(int n, vector<vector<int>> &a) {

        sort(a.begin(),a.end(),fun);

        int mx = 0;

        int mn = INT_MAX;

        for(auto i:a)

        {

            mx = max(i[1],mx);

            mn = min(i[1],mn);

        }

        int val[mx+1]={0};

        val[0]=0;

        int i=0;

        int ans = 0;

        for(int j=mn;i<n && j<=mx;j++)

        {

            if(a[i][1]==j)

            {

                while(i<n && a[i][1]==j)

                {

                    val[j]=max(val[j],max(a[i][2]+val[a[i][0]],val[j-1]));

                    ans = max(ans,val[j]);

                    i++;

                }

            }

            else{

                val[j] = max(ans,val[j]);

                val[j]=val[j-1];

            }

        }

        return ans;

    }

};
