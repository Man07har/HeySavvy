#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    unordered_set<int> st;
    char arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i]=='0' && (i==n-1 || arr[i+1]!='0')){
            st.insert(i-2);
        }
    }
    string res="";
    for(int i=0;i<n;i++){
        if(st.count(i)==1){
            int temp=10*(arr[i]-'0')+(arr[i+1]-'0');
            res+='a'+(arr[i]-'0'-1);
        }
    }
    cout<<res<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}