/* There are N jobs and the start and finish time of the jobs are given in arrays start[] and end[] respectively. Each job requires one laptop and laptops can't be shared. Find the minimum number of laptops required given that you can give your laptop to someone else when you are not doing your job.


Example 1:

Input:
N = 3
start[] = {1, 2, 3}
end[] = {4, 4, 6}
Output:
3
Explanation:
We can clearly see that everyone's supposed to
be doing their job at time 3. So, 3 laptops
will be required at minimum.
Example 2:

Input:
N = 3
start[] = {1, 5, 2}
end[] = {2, 6, 3}
Output :
1
Explanation:
All jobs can be done using 1 laptop only.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function minLaptops() which takes an integer N and two arrays start and end denoting starting and ending time of N jobs and returns minimum laptops required.


Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 105 
1 ≤ start[i] < end[i] ≤ 109 */

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        
        vector<pair<int,int>> arr;
        for(int i=0;i<N;i++)
        arr.push_back(make_pair(start[i],end[i]));
        
        sort(arr.begin(),arr.end());
        
        priority_queue<int,vector<int>,greater<int>> pq;
        int count=0;
        for(int i=0;i<N;i++){
            
            if(pq.empty() || pq.top() > arr[i].first){
               
                count++;
                pq.push(arr[i].second);
            }
            else{
                pq.pop();
                pq.push(arr[i].second);
                
            }
            
        }
        return count;
    }
};