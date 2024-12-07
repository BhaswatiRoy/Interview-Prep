Problem: https://leetcode.com/problems/missing-ranges/description

/*
Approach:
Case 1: missing at start, so compare 1st value with lower
Case 2: missing in between so check if difference of 2 adjacents are > 1
Case 3: missing at end, so compare last value with upper

TC: O(n) -> single pass traversal
SC: O(k) -> k = max number of missing ranges found
*/

vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) 
{
        vector<vector<int>>ans;
        int n=nums.size();
        //empty array means everything is missing
        if(n==0)
        {
            return {{lower,upper}};
        }
        //missing values at start
        //start=0, [3,4,5] -> [0,2] missing
        if(lower<nums[0])
        {
            ans.push_back({lower,nums[0]-1});
        }
        //missing values in between
        //[50,75] -> [51,74] missing
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]-nums[i]>1)
            {
                ans.push_back({nums[i]+1, nums[i+1]-1});
            }
        }
        //missing values at end
        //end=90, [85,86,87] -> [88,90] missing
        if(upper>nums[n-1])
        {
            ans.push_back({nums[n-1]+1,upper});
        }
        return ans;
}
