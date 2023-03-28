/* Geek went to buy some chocolates from a nearby shop with k coins in his pocket. He found that the shop contains n chocolates which are arranged in sorted order (increasing) of their prices.

Now geek wants to taste costlier chocolates so he decided that he will buy the costliest chocolate (of course among the ones that he can afford) till there exists at least one type of chocolate he can afford. You may assume that there is an infinite supply of chocolates in the shop Geek visited.

As you know, Geek is a shy person and hence he will enquire about the prices of the chocolates at most 50 times from the shopkeeper. Now, your task is to find the number of chocolates he had enjoyed. 

Note: If you call the Shop.get function more than 50 times it will return -1. Price of chocolates are pairwise distinct.

Example 1:

Input:
3 5 
2 4 6

Output:
1

Explanation: The prices of chocolates are [2, 4, 6] and Geek had 5 coins with him. So he can only buy chocolate that costs 4 coins (since he always picks the costliest one).
Example 2:

Input:
4 9 
1 2 3 4

Output:
3

Explanation: The prices of chocolates are [1, 2, 3, 4] and Geek had 9 coins with him. So he can buy two chocolates that cost 4 coins. Thereafter, he had only 1 coin with him, hence he will have 1 more chocolate (that costs 1 coin).
Your Task:
Return the number of chocolates geeks had eaten. Use the get(int i) function to inquire about the price of the i'th chocolate. 
Note that, you can only call that function 50 times after which it will return -1. Test cases are generated such that the answer can always be found.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(logN)

Constraints:
0 < n < 105
0 < priceOfChocolate < = 107 
0 < k <= 1012  */

#include<bits/stdc++.h>
using namespace std;

class Shop
{
    vector<int> chocolates;
    int countOfCalls;
    public:
    Shop()
    {
        countOfCalls = 0;
    }
    void addChocolate(int x)
    {
        chocolates.push_back(x);
    }
    long long get(int i)
    {
        countOfCalls++;
        if(i<0 || i>=(int)chocolates.size() || countOfCalls>50)return -1;
        return chocolates[i];
    }
};



class Solution{
    public:
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k){
      
        long long ans=0;
        int l=0;
        int h=n-1;
        while(k>0){
             int ind;
             int cost=-1;
             while(l<=h){
                 int mid=l+(h-l)/2;
                 int num=shop.get(mid);
                 if(num<=k){
                     ind=mid;
                     cost=num;
                     l=mid+1;
                 }
                 else{
                     h=mid-1;
                 }
             }
              
             if(cost==-1){
                 break;
             }
             while(cost<=k){
                 k-=cost;
                  ans++;
             }
             l=0;
             h=ind;
        }
        return ans;
    }

};


int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        long long k;
        cin >> k;
        
        Shop shop;
        for(int i = 0; i<n; i++)
        {
            int x;
            cin >> x;
            shop.addChocolate(x);
        }
        
        Solution obj(shop);
        long long res = obj.find(n, k);
        
        cout<<res<<endl;
        
    }
}

