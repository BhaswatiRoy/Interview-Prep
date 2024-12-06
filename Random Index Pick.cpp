Problem: https://leetcode.com/problems/random-pick-index/description/

/*
Approach 1: Hashing
1. Store all index of each element in a map
2. Then for a target value return a random index using rand() function

TC: O(n) -> iterating through all n elements
SC: O(n) -> storing all n elements
*/

unordered_map<int,vector<int>>mp
Solution(vector<int>& nums) 
{
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
}
    
int pick(int target) 
{
        int size=mp[target].size();
        int randomindex=rand()%size;
        return mp[target][randomindex];
}
