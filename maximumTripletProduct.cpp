/* Given an array arr of size n, the task is to find the maximum triplet product in the array.


Example 1:

Input:
n = 4
arr[] = {1, 2, 3, 5}
Output:
30
Explanation:
5*3*2 gives 30. This is the maximum possible
triplet product in the array.
Example 2:

Input:
n = 7
arr[] = {-3, -5, 1, 0, 8, 3, -2} 
Output:
120
Explanation: 
-3*-5*8 gives 120. This is the maximum possible triplet product in the array.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxTripletProduct() which takes an integer n and an array arr and returns the maximum triplet product in the array.


Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)


Constraints:
3 ≤ N ≤ 5*105
-106 ≤ A[i] ≤ 106 */

class Solution {

  public:

    long long maxTripletProduct(long long arr[], int n)

    {

     // Complete the function

     if(n==1)

     return 0;

     sort(arr,arr+n);

     if(n==2)

     {

         return arr[n-1]*arr[n-1]*arr[n-2];

     }

     else if(n>2)

     {

     long long p1=arr[0]*arr[1];

     long long p2=arr[n-2]*arr[n-3];

     long long ans=max((p1*arr[n-1]),(p2*arr[n-1]));

     return ans;

     }

    }

};