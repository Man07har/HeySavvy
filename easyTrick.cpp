/* Given a string s whose length is n and array queries of length q where each elements of queries is either of type 1 query or type 2 query which is explained ahead.

There are two types of query.

Query type 1 : ["1",ind,char]  "1" denotes this is type 1 query. In this query you have to change the character at index ind in s to character char.(Data type of ind,char is string in input)

Query Type 2: ["2",left,right,k]  "2" denotes this is type 2 query. In this query you have to return kth lexographically largest character  in the subtring of s (it is the kth largest character in sorted order , not the kth distinct character) starting from index left and ending at index right both left and right are inclusive. (Data type of left,right,k is string in input)

You have to perform each query in the same order as given in  queries and return an array res such that res array contains the answer for each type2 query in same order as it appeared in queries.

Note : 0 based indexing is used.

Example 1:

Input:
n=4
s="abab"
q=2
queries={{"1","2","d"},{"2","1","3","1"}}
Output: 
{"d"}
Explanation:
First query is of type 1 so after changing character at index 2 
to d  s becomes abdb . Now Second query is of type 2 in which 
the 1st(k=1) lexographically largest character is "d" in substring "bdb"(s[1:3]). So we 
returned a array with result of type 2 query {"d"}.
Example 2:

Input:
n=3
s="aaa"
q=3
queries={{"1","1","e"},{"1","2","c"},{"2","1","2","2"}}
Output:
{"c"}
Explanation:
After applying first two queries s becomes aec. Now for 
the last query which is a type 2 second largest character 
in subtring s starting from index 1 to ending at index 2 is "c".
Your Task:
You don't need to read input or print anything. Your task is to complete the function easyTask() which takes an integer n,string s,an integer q and an array queries which contains  queries of type1 and type2  respectively and returns an array res such that res array contains the answer for each type2 query in same order as it appeared in queries.

Expected Time Complexity: O(N+(Q*logN))
Expected Space Complexity: O(N)


Constraints:
1<=n<=5*10^4
1<=q<=10^5
0<=int(left)<=int(right)<=n-1
0<=int(index)<=n-1
1<=int(k)<=right-left+1
s and char contains lowercase english letters
The sum of n over all test cases won't exceed 5*10^4. */


class Solution{
public:
struct node
{
    int start,end;
    vector<int>freq;
    node *right,*left;
    node(int s,int e)
    {
        right=NULL,left=NULL;
        start=s,end=e;
        freq=vector<int>(26,0);
    }
};
string str;
void build(node *ptr,int s,int e)
{
    if(s==e)
    {
        ptr->freq[str[s]-97]=1;
        return;
    }
    int mid=(s+e)/2;
    ptr->left=new node(s,mid);
    build(ptr->left,s,mid);
    ptr->right=new node(mid+1,e);
    build(ptr->right,mid+1,e);
    for(int i=0;i<26;i++)
    ptr->freq[i]=(ptr->left->freq[i]+ptr->right->freq[i]);
    return;
}
void update(node *ptr,int ind,char ch)
{
    if(ptr->start==ind && ptr->end==ind)
     {
         ptr->freq[str[ind]-97]=0;
      ptr->freq[ch-97]=1;
      str[ind]=ch;
      return;
     }
    int mid=(ptr->start+ptr->end)/2;
    if(ind>=mid+1)
    {
        update(ptr->right,ind,ch);
     for(int i=0;i<26;i++)
    ptr->freq[i]=(ptr->left->freq[i]+ptr->right->freq[i]);
    return;
    }
    update(ptr->left,ind,ch);
    for(int i=0;i<26;i++)
    ptr->freq[i]=(ptr->left->freq[i]+ptr->right->freq[i]);
    return;
}
int st,en,k1;
vector<int> util;
void get(node *ptr)
{
   if(ptr->start>=st && ptr->end<=en)
   {
       for(int i=0;i<26;i++)
       util[i]+=ptr->freq[i];
       return;
   }
   int mid=(ptr->start+ptr->end)/2;
   if(st<=mid)
   get(ptr->left);
   if(en>mid)
   get(ptr->right);
   return;
   
}
    vector<char> easyTask(int n,string s,int q1,vector<vector<string>> &q){
        // Code here
        vector<char > res;
        node *root=new node(0,s.size()-1);
        str=s;
        build(root,0,s.size()-1);
        util=vector<int>(26,0);
        for(int i=0;i<q.size();i++)
        {
            if(q[i][0][0]=='1')
            {
                int ind=0;
                for(int j=0;j<q[i][1].size();j++)
                ind=ind*10+q[i][1][j]-'0';
                update(root,ind,q[i][2][0]);
            }
            else
            {
                util=vector<int>(26,0);
                int k=0,str1=0,enn=0;
                for(int j=0;j<q[i][1].size();j++)
                str1=str1*10+q[i][1][j]-'0';
                for(int j=0;j<q[i][2].size();j++)
                enn=enn*10+q[i][2][j]-'0';
                for(int j=0;j<q[i][3].size();j++)
                k=k*10+q[i][3][j]-'0';
                k1=k,st=str1,en=enn;
                get(root);
                for(int i=25;i>=0;i--)
                {
                    if(k<=util[i])
                    {
                        res.push_back(i+97);
                        break;
                    }
                    k-=util[i];
                }
                
            }
        }
        return res;
    }
};