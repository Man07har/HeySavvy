/* Given an array of positive numbers and a positive number ‘k’, find the maximum sum of any contiguous subarray of size ‘k’.

Example 1:

Input: [2, 1, 5, 1, 3, 2], k=3 
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].
Example 2:

Input: [2, 3, 4, 1, 5], k=2 
Output: 7
Explanation: Subarray with maximum sum is [3, 4]. */

//naive approach

class solution {
public:
int sumOfSubAarray(int arr[]){
    int k;
    int maxSum=0;
    int windowSum=0;
    for(int i=0;i<arr.size(), i++)
    {
        for(int j=i;j<i+k;j++){
            windowSum+= arr[j];
        }
        maxSum= max(maxSum, windowSum)
    }
    return maxSum;

}
};

//Sliding window approach

class Solution {
    public: 
    int sumOfSubAarray(){
        int k;
        int result[];
        int windowStart=0;
        int windowEnd;
        int maxSum=0;
        int windowSum=0;
        for(windowEnd=0;windowEnd<arr.size();windowEnd++){
            windowSum+=arr[windowEnd];
            if(windowEnd>=k-1){
                maxSum= max(maxSum, windowSum);
                windowSum-=arr[windowStart];
                windowStart++;
            }
        }
        return maxSum;
    }
};