bool makePalindrome(int n,vector<string> &arr)
    {
        unordered_map<string,int>mp;
        
        for(int i = 0 ; i < n ; i++)
        {
            mp[arr[i]]++;
        }
        
        int palindrome = 0;
        
        for(auto it : mp)
        {
            string str = it.first;
            string revstr = str;
            reverse(revstr.begin() , revstr.end());
            
            // if str is not palindrome and it's reverse is not present in arr
            if(mp[str] != mp[revstr])
            {
                return false;
            }
            // if str is palindrome
            if(str == revstr)
            {
                // counting number of palindromes that are present odd times
                if(mp[str]%2)
                {
                    palindrome++;
                }
                // if more than one type of palindrome present odd number of times
                if(palindrome > 1)
                return false;
            }
        }
        
        return true;
        
    }
