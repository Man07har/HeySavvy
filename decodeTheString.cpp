/* An encoded string (s) is given, the task is to decode it. The encoding pattern is that the occurance of the string is given at the starting of the string and each string is enclosed by square brackets.

Example 1:

Input: s = 1[b]
Output: b
Explaination: 'b' is present only one time.
Example 2:

Input: s = 3[b2[ca]]
Output: bcacabcacabcaca
Explaination: 2[ca] means 'ca' is repeated 
twice which is 'caca' which concatenated with 
'b' becomes 'bcaca'. This string repeated 
thrice becomes the output.
Your Task:
You do not need to read input or print annything. Your task is to complete the function decodedString() which takes s as input parameter and returns the decoded string.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(|s|)

Constraints:
1 ≤ |s| ≤ 103  */


#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    string decodedString(string s){
        stack<string>stkc;
        stkc.push("#");
        stack<int>stki;
        string ans = "";
        int cnt = 0;
        int cnt1=0;
        for(int i = 0 ; i < s.size() ;){
            if(s[i]==']'){
                string temp="";
                while(!stkc.empty() && stkc.top()!="["){
                    temp = stkc.top() + temp;
                    stkc.pop();
                }
                stkc.pop();
                ans = temp;
                if(!stki.empty()){
                    int n = stki.top();
                    stki.pop();
                    temp = ans;
                    for(int i = 0 ; i < n-1 ; i++){
                        ans = ans +  temp;
                    }
                }
                stkc.push(ans);
            }
            else if(s[i]-'0' >=0 && s[i]-'0' <=9){
                int n = 0;
                while(s[i]-'0' >=0 && s[i]-'0' <=9){
                    n = n*10 + s[i]-'0';
                    i++;
                }
                stki.push(n);
                i--;
            }
            else if(s[i]=='['){
                string temp = "";
                temp+='[';
                stkc.push(temp);
            }
            else{
                string temp = "";
                temp += s[i];
                stkc.push(temp);
            }
            i++;
        }
        ans ="";
        while(stkc.top()!="#"){
           ans = stkc.top() + ans;
           stkc.pop();
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
