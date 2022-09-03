#include<bits/stdc++.h>
using namespace std;
int inversionCount(int a[],int n)
{
    int ic;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j]){
                ic++;
            }
        }
    }
    return ic;
}
int main(){
int a[5]={3,1,4,0,8};
int n= sizeof(a)/sizeof(a[0]);
cout<<inversionCount(a,n);

    return 0;
}