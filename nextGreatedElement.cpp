/* Given an array arr[ ] of size n having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

Example 1:

Input: 
n = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3, 3 is 4, 2 is 4 and for 4? 
since it doesn't exist, it is -1.
Example 2:

Input: 
n = 5, arr[] = [6 8 0 1 3]
Output:
8 -1 1 3 -1
Explanation:
In the array, the next larger element to 
6 is 8, for 8 there is no larger elements 
hence it is -1, for 0 it is 1, for 1 it 
is 3 and then for 3 there is no larger 
element on right and hence -1.
Your Task:
This is a function problem. You only need to complete the function nextLargerElement() that takes list of integers arr[ ] and n as input parameters and returns list of integers of length N denoting the next greater elements for all the corresponding elements in the input array.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 ≤ n ≤ 106
0 ≤ arri ≤ 1018 */

vector<long long> nextLargerElement(vector<long long> &arr, int n){

        // Your code here

        stack<long long> s;

        vector<long long> v1;

        for(int i = n-1 ; i>=0 ; i--){

             if(s.size()==0){

                 v1.push_back(-1);

                 s.push(arr[i]);

             }

            else if(s.top() > arr[i]){

                     v1.push_back(s.top());

                     s.push(arr[i]);

             }

            

            else if(s.top() <= arr[i]){

                while(s.size()!=0 && s.top() < arr[i]){

                    s.pop();

                }

                 if(s.size()==0){

                 v1.push_back(-1);

                 s.push(arr[i]);

                }

               else if(s.top() > arr[i]){

                     v1.push_back(s.top());

                     s.push(arr[i]);

                 }

            }

        }

        

        vector<long long>v2;

        int k = v1.size();

        for(int m=k-1;m>=0;m--){

         v2.push_back( v1.at(m));

        }

        return v2;

    }