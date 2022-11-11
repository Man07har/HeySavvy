/*Given a number N. Find if it can be expressed as sum of two prime numbers.

Example 1:

Input: N = 34
Output: "Yes" 
Explanation: 34 can be expressed as 
sum of two prime numbers.
Example 2:

Input: N = 23
Output: "No"
Explanation: 23 cannnot be expressed as
sum of two prime numbers. 

Your Task:  
You dont need to read input or print anything. Complete the function isSumOfTwo() which takes N as input parameter and returns "Yes" if can be expressed as sum of two prime numbers. else return "No".

Expected Time Complexity: O(N*sqrt(N))
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n){
        if(n == 1 || n == 2 || n == 3)return true;
        
        for(int i = 2; i <= sqrt(n); i++){
            if(n%i == 0)return false;
        }
        
        return true;
    }
    string isSumOfTwo(int N){
      
        for(int i = 1; i <= N/2; i++){
            if(isPrime(i) && isPrime(N-i))return "Yes";
        }
        
        return "No";
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}
