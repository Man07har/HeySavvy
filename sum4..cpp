/* Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> answer;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int left = j+1, right = n-1;
                while(left < right){
                    if(nums[left] + nums[right] < newTarget){
                        left++;
                    }
                    else if(nums[left] + nums[right] > newTarget){
                        right--;
                    }
                    else{
                        set.insert({nums[i], nums[j], nums[left], nums[right]});
                        left++; right--;
                    }
                }
            }
        }
        for(auto it : set){
            answer.push_back(it);
        }
        return answer;
    }
};