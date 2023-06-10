/* You are given an array of size N. Rearrange the given array in-place such that all the negative numbers occur before all non-negative numbers.
(Maintain the order of all -ve and non-negative numbers as given in the original array).

Example 1:

Input:
N = 4
Arr[] = {-3, 3, -2, 2}
Output:
-3 -2 3 2
Explanation:
In the given array, negative numbers
are -3, -2 and non-negative numbers are 3, 2. 
Example 2:

Input:
N = 4
Arr[] = {-3, 1, 0, -2}
Output:
-3 -2 1 0
Explanation:
In the given array, negative numbers
are -3, -2 and non-negative numbers are 1, 0.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function Rearrange() which takes the array Arr[] and its size N as inputs and returns the array after rearranging with spaces between the elements of the array.

Expected Time Complexity: O(N. Log(N))
Expected Auxiliary Space: O(Log(N))

Constraints:
1 ≤ N ≤ 105
-109 ≤ Elements of array ≤ 109 */



 void Rearrange(int arr[], int n)
        {
            // Your code goes here
            vector<int> v;
            stack<int> a;
            stack<int> b;
            stack<int> c;
            for(int i=0;i<n;i++){
                if(arr[i]<0) a.push(arr[i]);
                else b.push(arr[i]);
            }
            while(!a.empty()) {
                v.push_back(a.top());
                a.pop();
                
            }
            reverse(v.begin(),v.end());
            while(!b.empty()) {
                c.push(b.top());
                b.pop();
                
            }
            while(!c.empty()) {
                v.push_back(c.top());
                c.pop();
            }
            for(int i=0;i<n;i++) arr[i]=v[i];
        }