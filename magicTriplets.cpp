/* Given an array of size n, a triplet (a[i], a[j], a[k]) is called a Magic Triplet if a[i] < a[j] < a[k] and i < j < k.  Count the number of magic triplets in a given array.
 

Example 1:

Input: arr = [3, 2, 1]
Output: 0
Explanation: There is no magic triplet.

Example 2:

Input: arr = [1, 2, 3, 4]
Output: 4
Explanation: Fours magic triplets are 
(1, 2, 3), (1, 2, 4), (1, 3, 4) and 
(2, 3, 4).
 

Your Task:
You don't need to read or print anything. Your task is to complete the function countTriplets() which takes the array nums[] as input parameter and returns the number of magic triplets in the array.

 

Expected Time Complexity: O(N2) 
Expected Space Complexity: O(1)
 

Constraints:
1 <= length of array <= 1000
1 <= arr[i] <= 100000 */

class Node{
   public:
   Node* left;
   Node* right;
   int val;
   int total;
   Node(int val){
       left=NULL;
       right=NULL;
       total=1;
       this->val=val;
   }
};
class Solution{
public:

int count(Node* root){
    if(!root) return 0;
    return root->total;
}

Node* insert(Node* root,int val){
    if(!root) {
        Node* n=new Node(val);
       // n->total=1;
        return n;
    }
    if(root->val<val){
        root->right=insert(root->right,val);
      
    }else{
        root->left=insert(root->left,val);
       
    }
    root->total=count(root->left)+count(root->right)+1;
    return root;
}

int find(Node* root,int val){
    if(!root) return 0;
    if(root->val>val){
        return count(root->right)+1+find(root->left,val);
    }else return find(root->right,val);
}

int countTriplets(vector<int>nums){
    // Code here.
    int n=nums.size();
    vector<int> v(n);
    Node* root=NULL;
    for(int i=n-1;i>=0;i--){
        int c=find(root,nums[i]);
        v[i]=c;
        root=insert(root,nums[i]);
    }
    
   // for(int i=0;i<n;i++) cout<<v[i];
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]<nums[j]){
                ans+=v[j];
            }
        }
    }
    return ans;
}
};