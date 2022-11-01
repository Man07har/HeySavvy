/* Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives 
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 

Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2
Explanation: Sorting matrix elements gives 
us {1,2,3}. Hence, 2 is median.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function median() which takes the integers R and C along with the 2D matrix as input parameters and returns the median of the matrix.

Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)


Constraints:
1 <= R, C <= 400
1 <= matrix[i][j] <= 2000 */

class Solution{   
public:
    int median(vector<vector<int>> &a, int n, int m) {
       
        int low = 1, high = 2000, req = (n * m) / 2 ;
        int ans = -1;
    
        auto countSmaller = [&](int val) {
            int smaller = 0;
            for (int i = 0; i < n; i++) {
                smaller += lower_bound(a[i].begin(), a[i].end(), val) - a[i].begin();
            }
            return smaller;
        };
    
        while (low <= high) {
            int mid = (low + high) >> 1;
            int smallerElements = countSmaller(mid);
            if (smallerElements <= req) {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};