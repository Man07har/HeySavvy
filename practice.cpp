#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string reverse(string s){
    string temp;
    int n=s.size();
    
     for(int i=0;i<=n;i++){
       if(s[n]=='a'||s[n]=='z'){
             temp[i] = s[i];
             --n;
       }
       else 
       --n;
     }
    
    return temp;
}
int main(){
    string s="hello";
    cout<<reverse(s);
    return 0;
}