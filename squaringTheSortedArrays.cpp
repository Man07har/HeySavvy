/* Problem Statement #
Given a sorted array, create a new array containing squares of all the number of the input array in the sorted order.

Example 1:

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]
Example 2:

Input: [-3, -1, 0, 1, 2]
Output: [0 1 1 4 9]
Try it yourself #
Try solving this question here: */


//naive approach 

for(int i=0; i<arr.size();i++){
    a[i]=a[i]*a[i];

}
sort(arr.begin(), arr.end());

//two pointer approach

#include<bits/stdc++.h>
#include<vector>
using namespace std;

class solution {
    public: 
    static vector<int> makeSquare(const vector<int> &arr){
        int n=arr.size();
        vector<int>squares(n);
        int left=0;
        int right=n-1;
        int highestIndex=n-1;
        while(left<=right){
            int leftSquare=arr[left]*arr[left];
            int rightSquare=arr[right]*arr[right];
            if(leftSquare>rightSquare){
                squares(highestIndex--)=leftSquare;
                left++;
            }
            else {
                squares(highestIndex--)=rightSquare;
                right--;
            }
        }
        return squares;
    }
};