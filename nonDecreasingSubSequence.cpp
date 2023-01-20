/* Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

 

Example 1:

Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
Example 2:

Input: nums = [4,4,3,2,1]
Output: [[4,4]]
 

Constraints:

1 <= nums.length <= 15
-100 <= nums[i] <= 100*/
class Solution {
public:
  set<vector<int>>st;
    void generate(vector<int>&arr,int start,vector<int>&temp){
         if(arr.size()==start){
            if(temp.size()>1)st.insert(temp);
            return;  
         }
         int curr=arr[start];
         int prev=temp.size()==0?-105:temp[temp.size()-1];

         if(curr>=prev){
             // take 
            temp.push_back(curr);
            generate(arr,start+1,temp);
            // not take
            temp.pop_back();
            generate(arr,start+1,temp);
         }
         else{ 
            // backtrack from here
             generate(arr,start+1,temp);
         }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
         vector<int>temp;
         generate(nums,0,temp);
         return vector(st.begin(),st.end());
    }
};
