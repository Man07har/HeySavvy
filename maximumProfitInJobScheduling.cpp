/* We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

Example 1:



Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:



Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
Example 3:



Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
 

Constraints:

1 <= startTime.length == endTime.length == profit.length <= 5 * 104
1 <= startTime[i] < endTime[i] <= 109
1 <= profit[i] <= 104 */

struct Job {
    int start, end, profit;
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = (int)startTime.size();
        
        Job arr[n];
        for(int i = 0; i < n; i++) {
            arr[i].start = startTime[i];
            arr[i].end = endTime[i];
            arr[i].profit = profit[i];
        }
        sort(arr, arr + n, [&](auto &j1, auto &j2){
            if(j1.end == j2.end) 
                return j1.profit > j2.profit;
            return j1.end < j2.end;
        });

        vector<int> dp(n+1, 0);                      // dp[i] = maximum profit earned till jobs(1...i)
        dp[1] = arr[0].profit;

        for(int i = 2; i <= n; i++) {
            int l = 0, r = i - 2, j = 0;

            while(l <= r) {
                int mid = l + (r - l) / 2;

                if(arr[mid].end <= arr[i - 1].start) {
                    j = mid + 1;
                    l = mid + 1;
                }
                else { r = mid - 1; }
            }
            dp[i] = max(dp[i - 1], arr[i - 1].profit + dp[j]);
        }
        return dp[n];
    }
};