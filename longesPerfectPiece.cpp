/* Given an array arr[] of N Numbers. A Perfect Piece is defined as a subarray such that the difference between the minimum and the maximum value in that range is at most 1. Find the Maximal Length Perfect Piece.

 

Example 1:

Input:
N = 4
arr[] = {8, 8, 8, 8}
Output:
4
Explanation:
The longest subarray is [1, 4]
where maximum=8 and minimum = 8 and
difference is 0, which is less than 1.
Its length is 4.
Example 2:

Input:
N = 11
arr[] = {5, 4, 5, 5, 6, 7, 8, 8, 8, 7, 6}
Output:
5
Explanation:
The longest subarray is [6, 10]
where maximum=8 and minimum = 7 and
difference is 1. Its length is 5. 
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestPerfectPiece() which takes an Integer N and an array arr[] of length N as input and returns the maximal length Perfect Piece.

 

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N <= 105
1 <= arr[i] <= 105 */

class Solution {
  public:
    int longestPerfectPiece(int arr[], int n) {
        // code here
        int a, b;
        int i = 0, j = 0, res = 0;
        while (i < n) {
            a = arr[i];
            b = -1;
            j = i + 1;
            while(j < n) {
                if (b == -1 && abs(arr[j] - a) == 1)
                    b = arr[j++];
                else if (arr[j] == a || arr[j] == b)
                    j++;
                else
                    break;
            }
            // cout << i << " " << j << endl;
            res = max(res, j - i);
            if (j >= n)
                break;
            i = j;
            if (abs(arr[j] - arr[j - 1]) == 1) {
                i = j - 1;
                a = arr[j];
                b = arr[i];
                while (arr[i] == b)
                    i--;
                i++;
            }
        }
        return res;
    }
};