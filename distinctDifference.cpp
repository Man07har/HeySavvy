/* Given an array A[] of length N. For each index i (1<=i<=N), find the diffference between the number of distinct element in it's left and right side in the array. 

Example 1:

Input:
N = 3
arr[] = {4, 3, 3}
Output: {-1, 0, 2}
Explanation: For index i=1, there are 0 distinct element in the left side of it, and 1 distinct element(3) in it's right side. So difference is 0-1 = -1. 

Similarly for index i=2, there is 1 distinct element (4) in left side of it, and 1 distinct element(3) in it's right side. So difference is 1-1 = 0.

Similarly for index i=3, there are 2 distinct elements (4 and 3) in left side of it, and 0 distinct elements in it's left side. So difference is 2-0 = 2.

Example 2:

Input:
N = 4
arr[] = {4, 4, 3, 3}
Output: {-2, 0, 0, 2}
Explanation: For index i=1, there are 0 distinct element in the left side of it, and 2 distinct element(4 and 3) in it's right side. So difference is 0-2 = -2.

Similarly for index i=2, there is 1 distinct element (4) in left side of it, and 1 distinct element(3) in it's right side. So difference is 1-1 = 0.

Similarly for index i=4, there are 2 distinct elements (4 and 3) in left side of it, and 0 distinct element in it's right side. So difference is 2-0 = 2.
Your Task: 
You don't need to read input or print anything. Your task is to complete the function getDistinctDifference() which takes the array A[] and its size N as input parameters and returns an array containing the difference between number of ditinct elements in left and right side for each 1<=i<=N.

Expected Time Complexity: O(N)
Expected Space Complexity:O(N)

Constraints:

1 <= N <= 105
1 <= A[i] <= 109
Array may contain duplicate elements. */


class Solution {
  public:
vector<int> getDistinctDifference(int N, vector<int> &A) 
{
        // code here
     vector<int>distLeft(A.size(),0);
     vector<int>distRight(A.size(),0);
     set<int>distElementsSet;
     vector<int>ans;
      
     distLeft[0]=0;
     distRight[A.size()-1]=0;
     distElementsSet.insert(A[0]);
        
     //left traversal distinct elements count
    for(int i=1;i<A.size();i++)
    {
        distLeft[i] += distElementsSet.size();
        distElementsSet.insert(A[i]);
   }
        
    distElementsSet = set<int>(); //re-initialize set
    distElementsSet.insert(A[A.size()-1]);
     //right traversal distinct elements count
    for(int i=A.size()-2;i>=0;i--)
    {
      distRight[i] += distElementsSet.size();
      distElementsSet.insert(A[i]);
    }
    for(int i=0;i<A.size();i++)
   {
      ans.push_back(distLeft[i] - distRight[i]);
   }
        return ans;
 }
}