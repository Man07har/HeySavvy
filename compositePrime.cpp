/*Given two integers L and R find the difference of number of composites and primes between the range L and R (both inclusive).

Example 1:

Input: L = 4, R = 6
Output: 1
Explanation: Composite no. are 4 and 6.
And prime is 5.

Example 2:

Input: L = 4, R = 4
Output: 1
Explanation: There is no prime no. in [L,R]
 

Your Task:
You don't need to read or print anything. Your task is to complete the function Count() which takes L and R as input parameter and returns difference between no. of composites and primes between [L,R].
 

Expected Time Complexity: O(nlog(n)) where n = R - L + 1
Expected Space Complexity: O(n)
 

Constraints:
1 <= L <= R <= 105 */ 
 
 
 #include<bits/stdc++.h>
 using namespace std;
 class solution {
 public: 
 bool checkprime(int n){
    if(n==1)
    return false;
    if(n==2||n==3)
    {
        return true;
    }
   for(int i=5;i*i<=n;i+=6)
   {
    if(n%i==0||n%(i+2)==0)
   {
    return false;
   }
   
   }
   return true;

 }
 int Count(int L, int R){
 int p=0, c=0;
 if(L==1){
    L=L+1;
 }
 for(int i=L; i<=R;i++)
 {
    if(checkprime(i))
    p++;
    else 
    c++;
 }
 int diff=c-p;
 return diff;
 }
 };




 int main(){
 int tc;
 cin>>tc;
 while(tc--)
 {
    int L,R;
    cin>>L>>R;
    solution object;
    int ans = object.Count(L,R);
    cout<<ans<<"/n";
    }



    return 0;
 }