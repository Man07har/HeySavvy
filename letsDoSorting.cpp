#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    vector <int> vect;
    vect.push_back(20);
    vect.push_back(12);
    vect.push_back(34);
    for(auto i:vect){
       cout<<i<<" "<<endl;
    }
    cout<<"Here comes the wonder that you were looking for"<<endl;
    sort(vect.begin(),vect.end());
    for(auto i:vect){
        
        cout<<i<<endl;
    }
    return 0;
}