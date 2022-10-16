#include<bits/stdc++.h>
using namespace std;

    void solve(int a, int b, int c){
     if(a==(b+c)){
     cout<<"YES";
 }
 else if(b==(a+c))
 {
     cout<<"YES";
 }
 else if(c==(a+b)){
     cout<<"YES";
 }
 else
 cout<<"NO";
}


int main(){
    int t;
    cin>>t;
    while(t--){
       int a[3];
       for(int i=0;i<3;i++)
       {
           cin>>a[i];
       }
       solve(a[1],a[2],a[3]);
    }
    return 0;
}