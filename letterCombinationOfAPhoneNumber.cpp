/* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9']. */


class Solution {
public:
    vector<string>solve(string digits,string*arr){
        if(digits.size()==0){
            vector<string>bs;
            bs.push_back("");
            return bs;
        }
      
        char c=digits[0];
        string a=arr[c-'0'];
         string smallinput=digits.substr(1);
        vector<string>rest=solve(smallinput,arr);
        vector<string>res;
        for(auto x:rest){
           for(auto x1:a){
               res.push_back(x1+x);
           } 
        }
        return res;
    }
    vector<string>ans;
    void solve2(string digits,string *arr,int i,string com){
        if(i==digits.size()){
         ans.push_back(com);
         return;
        }
         char c=digits[i];
        string a=arr[c-'0'];
        for(int k=0;k<a.size();k++){
            solve2(digits,arr,i+1,com+a[k]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>a;
        if(digits.size()==0)
            return a;
        string arr[]={"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
      //  vector<string>ans=solve(digits,arr);
      solve2(digits,arr,0,"");
        return ans;
    }
};