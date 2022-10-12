/* Given a string w, integer array b,  character array x and an integer n. n is the size of array b and array x. Find a substring which has the sum of the ASCII values of its every character, as maximum. ASCII values of some characters are redefined.
Note: Uppercase & lowercase both will be present in the string w. Array b and Array x contain corresponding redefined ASCII values. For each i, b[i] contain redefined ASCII value of character x[i].

Example 1:

Input:
W = abcde
N = 1
X[] = { 'c' }
B[] = { -1000 }
Output:
de
Explanation:
Substring "de" has the
maximum sum of ascii value,
including c decreases the sum value
Example 2:

Input:
W = dbfbsdbf 
N = 2
X[] = { 'b','s' }
B[] = { -100, 45  }
Output:
dbfbsdbf
Explanation:
Substring "dbfbsdbf" has the maximum
sum of ascii value.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxSum() which takes string W, character array X, integer array B, integer N as length of array X and B as input parameters and returns the substring with the maximum sum of ascii value.
 

Expected Time Complexity: O(|W|)
Expected Auxiliary Space: O(1)


Constraints:

1<=|W|<=100000
1<=|X|<=52
-1000<=Bi<=1000 */

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          int arr[26];
          int Arr[26];
          for(int i=0;i<26;i++){
              arr[i]=97+i;
              Arr[i]=65+i;
          }
         for(int i=0;i<n;i++){
             if(islower(x[i])){
                 arr[x[i]-'a']=b[i];
             }
             else
              Arr[x[i]-'A']=b[i];
         }  
         
         int sum=0,maxsum=INT_MIN;
        
         string ans="";
         string temp="";
         for(int i=0;i<w.size();i++){

             if(islower(w[i])) sum+=arr[w[i]-'a'];
             else sum+=Arr[w[i]-'A'];
             
             temp+=w[i];
             if(sum> maxsum){ maxsum=sum;ans=temp;}
             if(sum<0) {sum=0;temp="";}
         }
         return ans;
      }
};

 



int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
