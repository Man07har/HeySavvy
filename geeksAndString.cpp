/* Geek has a list Li containing (not necessarily distinct) N words and Q queries. Each query consists of a string x. For each query, find how many strings in the List Li has the string x as its prefix. 


Example 1:

Input: 
N = 5, Q = 5
li[] = {'abracadabra', 'geeksforgeeks', 
      'abracadabra', 'geeks', 'geeksthrill'}
query[] = {'abr', 'geeks', 'geeksforgeeks', 
         'ge', 'gar'}

Output: 2 3 1 3 0

Explaination: 
Query 1: The string 'abr' is prefix of 
two 'abracadabra'. 
Query 2: The string 'geeks' is prefix of three 
strings 'geeksforgeeks', 'geeks' and 'geeksthrill'. 
Query 3: The string 'geeksforgeeks' is prefix 
of itself present in li. 
Query 4: The string 'ge' also is prefix of three 
strings 'geeksforgeeeks', 'geeks', 'geeksthrill'. 
Query 5: The string 'gar' is not a prefix of any 
string in li.

Your Task:
You do not need to read input or print anything. Your task is to complete the function prefixCount() which takes N, Q, li[] and query[] as input parameters and returns a list containing the count of prefixes for each query. 


Expected Time Complexity: O(Q*x) + O(N*L) Where Q is the number of queries, x is the longest word in the query, N = number of words inserted in Trie and L = length of longest word inserted in Trie.
Expected Auxiliary Space: O(N*List [i])


Constraints:
1 ≤ N ≤ 3 x 104
1 ≤ Q ≤ 104
1 ≤ |li[i]|, |x| ≤ 100   */
 class Node{
      public :
          int count;
          char data;
          vector<Node*>children;
          Node(char ch){
              count=0;
              data=ch;
              children.resize(26,NULL);
          }
    };
    
    class Trie{
      public :
      Node* root;
      Trie(){
          root=new Node('\0');
      }
      
      void insert(string &word){
          auto node=root;
          for(char w:word){
              if(!node->children[w-'a'])
                  node->children[w-'a']=new Node(w);
              node=node->children[w-'a'];
              node->count++;
          }
      }
      
      int getCount(string &word){
          auto node=root;
          for(char w:word){
               if(!node->children[w-'a']) return 0;
              node=node->children[w-'a'];
          }
           return node->count;
      }
      
      
    };
class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
      Trie t;
       for(int i=0;i<N;i++)
            t.insert(li[i]);
        vector<int>res;
        for(int i=0;i<Q;i++)
            res.push_back(t.getCount(query[i]));
        
        return res;
    }
};