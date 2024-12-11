Problem: https://leetcode.com/problems/subsets/description/

/*
p = pick
np = not pick
                 1,2,3
        p /                 \ np
         1       
   p  /      \ np          p /    \ np
   1,2         1            2      
p /   \ np  p /  \ np   p /  \ np p /  \ np
1,2,3  1,2  1,3   1      2,3  2    3   

powersets = [ [1,2,3], [1,2], [1,3], [1], [2,3], [2], [3] ]

TC: O2^n)
SC: O(n) -> recursion stack + "subset" array
*/

void recursion(int idx, vector<int>&nums, vector<int>&subset, vector<vector<int>>&powerset)
{
        if(idx==nums.size())
        {
            powerset.push_back(subset);
            return;
        }
        subset.push_back(nums[idx]);
        recursion(idx+1,nums,subset,powerset);
        subset.pop_back();
        recursion(idx+1,nums,subset,powerset);
}

vector<vector<int>> subsets(vector<int>& nums) 
{
        vector<int>subset;
        vector<vector<int>>powerset;
        recursion(0,nums,subset,powerset);
        return powerset;
}
