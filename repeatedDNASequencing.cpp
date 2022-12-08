/*  question */

#include<bits/stdc++.h>
#include<vector>
using namespace std;
class solution {

    public:
    vector<string> findRepeatDnaSequencing(String s){
        int k=10;
        int windowStart=0;
        int windowEnd=0;
        int windowSum="";
        
        for(windowEnd;windowEnd<str.length();windowEnd++)
{
    windowSum+=str[windowEnd];
    if(windowEnd>=k-1){
        for(auto character: windowEnd){
            charFrequency[character]++;
        }
        if(charFrequency[character]>1){
            int a=0;
            result[a]= character;
            a++;
        }
        windowStart++;
    }
} return result;

    }
   
};
int main(){
    solution s;
    s.findRepeatDnaSequencing("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    return 0;
}