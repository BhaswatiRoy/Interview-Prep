Problem: https://leetcode.com/problems/subarray-sum-equals-k

/*
Approach 1: Brute Force - TLE
1. Traverse entire array and generate all subarrays and check if their sum is == k 
TC: O(n^2)
SC: O(1)

Approach 2: Optimized
4 5 1 3 2      k = 9
sum = 0
sum = 4 -> store in map
sum = 9 -> sum == k so count++ -> store in map
sum = 10 -> store in map
sum = 13 -> sum - k = 13 - 9 = 4 present in map so count++
sum = 15 -> store in map

TC: O(n) -> single pass traversal
SC: O(n) -> map used
*/

int subarraySum(vector<int>& nums, int k) 
{
        int n=nums.size(),count=0;
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==k)
            {
                count++;
            }
            if(mp[sum-k]>0)
            {
                count+=mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
}
