 #include<bits/stdc++.h>
 using namespace std;
 class solution {
 public: 
 bool checkprime(int n){
    if(n==1)
    return false;
    if(n==2||n==3)
    {
        return true;
    }
   for(int i=5;i*i<=n;i+=6)
   {
    if(n%i==0||n%(i+2)==0)
   {
    return false;
   }
   
   }
   return true;

 }
 int Count(int L, int R){
 int p=0, c=0;
 if(L==1){
    L=L+1;
 }
 for(int i=L; i<=R;i++)
 {
    if(checkprime(i))
    p++;
    else 
    c++;
 }
 int diff=c-p;
 return diff;
 }
 };




 int main(){
 int tc;
 cin>>tc;
 while(tc--)
 {
    int L,R;
    cin>>L>>R;
    solution object;
    int ans = object.Count(L,R);
    cout<<ans<<"/n";
    }



    return 0;
 }