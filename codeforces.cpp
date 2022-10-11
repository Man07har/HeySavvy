#include<bits/stdc++.h>
#include<string>
using namespace std;
void solve(string a, string b){
    int num1=a.size();
    int num2= b.size();
   if((a[num1-1]=='S' && b[num2-1]=='M') || (a[num1-1]=='M' && b[num2-1]=='L') || (a[num1-1]=='S' && b[num2-1]=='L')){
       cout<<"<";
   }
   else  if((a[num1-1]=='L' && b[num2-1]=='M')|| (a[num1-1]=='M' && b[num2-1]=='S') || (a[num1-1]=='M' && b[num2-1]=='S')){
       cout<<">";
   }
    else if(a[num1-1]=='S' && b[num2-1]=='S'){
       if(num1>num2){
           cout<<"<";
       }
       else if(num1<num2){
       cout<<">";
       }
       else 
       cout<<"=";
    }
   else if(a[num1-1]=='L' && b[num2-1]=='L'){
       if(num1>num2){
           cout<<">";
       }
       else if(num1<num2){
       cout<<"<";
       }
       else 
       cout<<"=";
   }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        string b;
        cin>>b;
        solve(a,b);
    }
    return 0;
}