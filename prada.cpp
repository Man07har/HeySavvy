#include<iostream>
using namespace std;
int okay_babu(int h){
    if(h==1){
        return 1;
    }
    else
    return 2;
}
int main(){
    cout<<"input dal bsdk";
    int n;
    cin>>n;
    
    int h=okay_babu(n)
    cout<<h;
    return 0;
   
}