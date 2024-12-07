Problem: https://leetcode.com/problems/merge-k-sorted-lists/description/

/*
lists = [[1,4,5],[1,3,4],[2,6]]
1 -> 4 -> 5
1 -> 3 -> 4 
2 -> 6

1. Store all heads in min heap priority queue -> [1,1,2] -> {node value, node}
2. The least value one will be stored on top
3. Take out from top and add to new list and go to next value in that list
   1 is taken out from PQ, so 4 is pushed from 1st list

TC: O(nlogk) -> queue stores k elements atmost so insertion/deletion for n elements is logk
SC: O(n) + O(k) = O(n+k) -> result list & PQ
*/

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>>pq;
        ListNode* head=new ListNode(0);
        ListNode* dummy=head;
        int n=lists.size();
        //push all head nodes to priority queue
        for(int i=0;i<n;i++)
        {
            ListNode* node=lists[i];
            //only add the head node if its not NULL
            if(node!=NULL)
            {
                pq.push({node->val, node});
            }
        }
        while(!pq.empty())
        {
            //take out nodes in sorted order
            pair<int, ListNode*>p=pq.top();
            pq.pop();
            ListNode* newnode=p.second;
            //add them to the final sorted list
            dummy->next=newnode;
            //increment the dummy pointer
            dummy=dummy->next;
            //if the next node of the list is not empty we push to queue
            if(newnode->next!=NULL)
            {
                pq.push({newnode->next->val,newnode->next});
            }
        }
        return head->next;
}

