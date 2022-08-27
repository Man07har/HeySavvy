#include<bits/stdc++.h>
#include<vector>
using namespace std;
class LinearSearchProblem{
    public:
    int LinearSearch(int a[],int n,int val){
       for(int i=0;i<n;i++)
       {
        if(a[i]==val){
            return i;
        }
        else 
        return 0;
       }
    }
};
void main(){
    int n,val;
    int a[];
cout<<"Enter the size of the array"<<endl;
cin>>n;
cout<<"Enter the elements of the array"<<endl;
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
cout<<"Enter the value you want to search"<<endl;
cin>>val;
LinearSearchProblem l;
l.LinearSearch(a[n],n,val);

}