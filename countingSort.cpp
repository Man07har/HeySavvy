#include<iostream>
using namespace std;
int getMax(int a[],int n)
{
    int temp;
  int max=a[0];
  for(int i=0;i<n;i++){
    if(max<a[i]){
        temp=max;
        max=a[i];
        a[i]=temp;
    }
  }
  return max;
}

int conuntingSort(int a[],int n){
    int max=getMax(&a[n],n);
int count[max+1];
int output[n];
for(int i=0;i<n;i++){
    count[i]=0;
}
for(int i=0;i<n;i++){
    count[a[i]]++;
}
//Now we will find the cumilative frequency
for(int i=0;i<n;i++){
    count[i]+=count[i-1];
}
/*Now we will find the the index of the original array from the count array and store
them in the output array*/
for(int i=n-1;i>=0;i--){
    output[count[a[i]-1]]=a[i];
    count[a[i]]--;
}
// get the original array sorted now with the help of output array
for(int i=0;i<n;i++){
    a[i]=output[i];
}
}
int main()
{
    int a[];
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}