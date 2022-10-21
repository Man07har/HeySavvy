/* Given a matrix as 2D array. Find the reverse spiral traversal of the matrix. 

Example 1:

Input: R = 3, C = 3
  a = {{9, 8, 7},
       {6, 5, 4},
       {3, 2, 1}}
Output: 5 6 3 2 1 4 7 8 9
Explanation: Spiral form of the matrix
in reverse order starts from the centre 
and goes outward.


Example 2:

Input: R = 4, C = 4 
  a = {{1, 2, 3, 4},
       {5, 6, 7, 8},
       {9, 10, 11, 12}, 
       {13, 14, 15, 16}}
Output: 10 11 7 6 5 9 13 14 15 16 12 8 4 3 2 1
Explanation: 


Your Task:  
You dont need to read input or print anything. Complete the function reverseSpiral() which takes R, C and a as input parameters and returns the matrix in reverse spiral form.

Expected Time Complexity: O(R*C)
Expected Auxiliary Space: O(R*C)

Constraints:
1 <= R,C <=100 */


#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
   vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {

     

        vector<int> ans;

        

        int tEle = R*C;

        

        int sRow = 0;

        int lRow = R-1;

        int sCol = 0;

        int lCol = C-1;

        int cnt = 0;

        

        while(cnt < tEle){

            

            if(cnt < tEle){

                for(int i=sCol;i<=lCol;i++){

                    ans.push_back(a[sRow][i]);

                    cnt++;

                }

                sRow++;

            }

            

            if(cnt < tEle){

                for(int i=sRow;i<=lRow;i++){

                    ans.push_back(a[i][lCol]);

                    cnt++;

                }

                lCol--;

            }

            

            if(cnt < tEle){

                for(int i=lCol;i>=sCol;i--){

                    ans.push_back(a[lRow][i]);

                    cnt++;

                }

                lRow--;

            }

            

            

            if(cnt < tEle){

                for(int i=lRow;i>=sRow;i--){

                    ans.push_back(a[i][sCol]);

                    cnt++;

                }

                sCol++;

            }

        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}
