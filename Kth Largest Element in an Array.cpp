Problem: https://leetcode.com/problems/kth-largest-element-in-an-array/description

/*
Approach: 
1. Use max heap because it stores data in descending order from top to bottom
2. Pop elements till (k-1) to get the kth element on the top
3. Max heap is a binary tree data structure that has a root with a greater value than all its children

Similarly, min heap is a binary tree data structure that has a root with a lesser value than all its children
priority_queue<int, vector<int>, greater<int>>pq;

TC: O(nlogn) -> push & pop from priority queue takes logn 
SC: O(n) -> size of priority queue
*/

int findKthLargest(vector<int>& nums, int k) 
{
        int n=nums.size();
        //max heap storing higher values on top
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }
        //pop till (k-1)th value to get kth largest value on top
        int kth=k-1;
        while(kth--)
        {
            pq.pop();
        }
        return pq.top();
}
