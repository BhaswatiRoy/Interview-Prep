Problem: https://leetcode.com/problems/max-consecutive-ones-ii/description/

/*
Approach: Max Consecutive Ones II
[1,0,1,1,0,1]
i=0, j=0, zeros=0, maxcount=0
1. when j reaches 1st index 0, zeros++ -> zeros = 1
2. when j reaches 4th index 0, zeros++ -> zeros = 2 so zeros > 1
3. so we increment i to 2nd index right after 0, so that zeros = 1
4. because we can change at max 1 0's so we need to make windows with just 1 0's
5. everytime we also compare size of window with maxcount

TC: O(n) -> traversing all n elements 
SC: O(1)
*/

int findMaxConsecutiveOnes(vector<int>& nums) 
{
        int n=nums.size();
        //find a window with just 1 0
        int i=0,j=0;
        int zeros=0,maxcount=0;
        while(j<n)
        {
            //if we find a zero, just count it
            if(nums[j]==0)
            {
                zeros++;
            }
            //if zeros count is >1 then increment i and reduce zeros
            while(zeros>1)
            {
                if(nums[i]==0)
                {
                    zeros--;
                }
                i++;
            }
            //everytime check the window size and compare with maxcount
            maxcount=max(maxcount,j-i+1);
            j++;
        }
        return maxcount;
}

Problem: https://leetcode.com/problems/max-consecutive-ones-iii/description

/*
Approach: Max Consecutive Ones III
Exactly same as Max Consecutive Ones II 
Only difference is instead of 1, we use k 
So everytime the while loop checks count of zeros it checks if zeros > k
instead of zeros > 1

TC: O(n) -> traversing all n elements 
SC: O(1)
*/

int longestOnes(vector<int>& nums, int k) 
{
        int n=nums.size();
        int i=0,j=0;
        int zeros=0, maxcount=0;
        while(j<n)
        {
            //if we find a zero, just count it
            if(nums[j]==0)
            {
                zeros++;
            }
            //if zeros count is >k then increment i and reduce zeros
            while(zeros>k)
            {
                if(nums[i]==0)
                {
                    zeros--;
                }
                i++;
            }
            //everytime check the window size and compare with maxcount
            maxcount=max(maxcount,j-i+1);
            j++;
        }
        return maxcount;
}
