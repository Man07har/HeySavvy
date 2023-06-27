/* Given two linked lists, your task is to complete the function makeUnion(), that returns the union list of two linked lists. This union list should include all the distinct elements only and it should be sorted in ascending order.

Example 1:

Input:
L1 = 9->6->4->2->3->8
L2 = 1->2->8->6->2
Output: 
1 2 3 4 6 8 9
Explaination: 
All the distinct numbers from two lists, when sorted forms the list in the output. 
Example 2:

Input:
L1 = 1->5->1->2->2->5
L2 = 4->5->6->7->1
Output: 
1 2 4 5 6 7
Explaination: 
All the distinct numbers from two lists, when sorted forms the list in the output.
Your Task:
The task is to complete the function makeUnion() which makes the union of the given two lists and returns the head of the new list.

Expected Time Complexity: O((N+M)*Log(N+M))
Expected Auxiliary Space: O(N+M)

Constraints:
1<=N,M<=104 */

class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        set<int>st;
        Node* head = head1;
        while(head!=NULL)
        {
            st.insert(head->data);
            head = head->next;
        }
        Node* head9 = head2;
        while(head9!=NULL)
        {
            st.insert(head9->data);
            head9 = head9->next;
        }
        vector<int>v;
        for(auto x:st)
        {
            v.push_back(x);
            //cout<<x<<" ";
        }
        //cout<<'\n';
        head = new Node(v[0]);
        Node* temp = head;
        int i=1;
        while(i<st.size())
        {
            Node* head3 = new Node(v[i]);
            temp->next = head3;
            temp=temp->next;
            i++;
        }
        return head;
    }
};