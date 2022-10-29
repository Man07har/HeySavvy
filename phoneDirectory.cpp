/* Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. The task is to implement a search query for the phone directory. Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. Please refer the explanation part for better understanding.
Note: If there is no match between query and contacts, print "0".

Example 1:

Input: 
n = 3
contact[] = {"geeikistest", "geeksforgeeks", 
"geeksfortest"}
s = "geeips"
Output:
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0
Explaination: By running the search query on 
contact list for "g" we get: "geeikistest", 
"geeksforgeeks" and "geeksfortest".
By running the search query on contact list 
for "ge" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list 
for "gee" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list 
for "geei" we get: "geeikistest".
No results found for "geeip", so print "0". 
No results found for "geeips", so print "0".
Your Task:
Youd do not need to read input or print anything. Your task is to complete the function displayContacts() which takes n, contact[ ] and s as input parameters and returns a list of list of strings for required prefixes. If some prefix has no matching contact return "0" on that list.

Expected Time Complexity: O(|s| * n * max|contact[i]|)
Expected Auxiliary Space: O(n * max|contact[i]|)

Constraints:
1 ≤ T ≤ 100, T = number of test cases
1 ≤ n ≤ 50
1 ≤ |contact[i]| ≤ 50
1 ≤ |s| ≤ 6  */

class Solution{

public:

    vector<vector<string>> displayContacts(int n, string contact[], string s)

    {

        vector<vector<string>>ans;

        vector<string>v;

        string str;

       

        for(int i=0;i<s.size();i++)

        {

            str.push_back(s[i]);

            v.push_back(str);

        }

        for(int i=0;i<v.size();i++)

        {

             map<string,int>m;

            vector<string>temp;

            int c=0;

            for(int j=0;j<n;j++)

            {

                if(contact[j].find(v[i])!=string::npos)

                {

                      m[contact[j]]++;

                }

                else

                {

                    c++;

                }

                

            }

            

            for(auto it=m.begin();it!=m.end();it++)

            {

                temp.push_back(it->first);

            }

            if(c==n)

            {

                vector<string>temp1(1,"0");
                ans.push_back(temp1);

            }

            else

            {

                ans.push_back(temp);

             }

        }

        

        return ans;
   
    }

};

