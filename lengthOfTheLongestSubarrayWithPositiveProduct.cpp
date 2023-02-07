/* Given an array arr[] consisting of n integers, find the length of the longest subarray with positive (non zero) product.

 

Example 1:

Input:
arr[] ={0, 1, -2, -3, -4} 
Output:
3
Explanation: 
The longest subarray with positive product is: 
{1, -2, -3}.Therefore, the required length is 3.
 

Example 2:

Input:
arr[]={-1, -2, 0, 1, 2}
Output:
2
Explanation:
The longest subarray with positive products 
are: {-1, -2}, {1, 2}. Therefore, the required 
length is 2.
 

Your Task: This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function maxLength() that takes array arr[], and an integer n as parameters and return the length of the longest subarray where the product of all of its element is positive. 

 

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

 

Constraints:
 1<=n<=105
-109<=arr[i]<=109
  */


  class Solution {
    public:
        int maxLength(vector<int> &arr,int n){
           int strt=0,i=0,cnt=0,first=0,last=0,ans=INT_MIN;
           while(i<n)
           {
                if(arr[i]==0)
                {
                    if(cnt%2==0)
                        ans=max(ans,i-strt);
                    else
                        ans=max(ans,max(i-first-1,last-strt));
                
                    cnt=0;
                    strt=i+1;
                }
                else if(arr[i]<0)
                {
                    if(cnt==0)
                        first=i;
                    last=i;
                    cnt++;
                }
                if(i==n-1 && arr[i]!=0)
                {
                    if(cnt%2==0)
                        ans=max(ans,i-strt+1);
                    else
                        ans=max(ans,max(i-first,last-strt));
                }
                i++;
           }
           return ans;
           
        }
};