class Solution{   
  public:
    string secondSmallest(int s, int D){
        
        
        if(9*D <= s)
          return "-1";
          
          if(s==9){
              int a=s*(D+1);
               string ans=to_string(a);
               return ans;
          }
        
        
        vector<int>arr(D,0);
        int k=D-1;
        arr[0]=1;
        s--;
        while(s>9){
            arr[k]=9;
            s=s-9;
            k--;
        }
        arr[k]+=s;
        
         int end1=D-1;
         int end2=D-2;
         int cnt=0;
         while(cnt<=0){
             if(arr[end1]==9 && arr[end2]==9){
                 end1--;
                 end2--;
             }
             else{
                 if(arr[end1]==9){
                     arr[end1]-=1;
                     arr[end2]+=1;
                     cnt++;
                 }
                 else{
                     arr[end1]+=1;
                     arr[end2]-=1;
                     cnt++;
                 }
             }
         }
        
        string ans="";
       
        for(int i=0;i<arr.size();i++){
            ans+=arr[i]+48;
        }
       int start=0;
       int last=D-1;
       return ans;
        
    }
};
