Problem: https://leetcode.com/problems/top-k-frequent-elements/description

/*
1. Store frequency of elements in hashmap
2. Store the {frequency, element} in a priority queue/ max heap
3. Then take out top k elements from the priority queue and store them into a vector

d = distinct elements
TC: O(n) + O(dlogd) -> traversing entire array + pushing d unique elements into priority queue
SC: O(d) -> priority queue, map, vector
*/

vector<int> topKFrequent(vector<int>& nums, int k) 
{
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            //map to store each element & its frequency
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            //{frequency, number} stored in max heap
            pq.push({it.second,it.first});
        }
        while(k--)
        {
            //store only the numbers according k most frequent 
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
}
