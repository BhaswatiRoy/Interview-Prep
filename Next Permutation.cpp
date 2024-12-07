Problem: https://leetcode.com/problems/next-permutation/description

/*
1 3 5 4 2
    5
  3   4
1       2
till index = 2 its increasing from back, so the breakpoint is index = 2
then swapping idx1 = 2 & idx2 = 4, where the value at idx2 is lesser than idx1
to swap them means we find a greater value lexicographically
and in end we reverse to get lexicographically smallest

1. iterate from end & find idx1 where nums[i] < nums[i+1] -> idx1 = 1
2. If we dont find idx1 for arrays like 5 4 3 2 1 then simply reverse and return
   Because for this case the next permutation is 1 2 3 4 5
3. iterate from end & find idx2 where nums[j] > nums[idx1] -> idx2 = 3
4. Swap idx1 and idx2 positions -> 1 4 5 3 2
5. Reverse positions from idx1 to end -> 1 4 2 3 5 
   Reversing to make sure we get the lowest value after idx1 to get next permutation
TC: O(n) -> single pass traversal
SC: O(1) -> no extra space used
*/

void nextPermutation(vector<int>& nums) 
{
        int n=nums.size();
        //if array has size 0/1 then we cant find permutations
        if(n<=1)
        {
            return;
        }
        int idx1=-1,idx2=-1;
        //traverse from back and find the first index where
        //nums[i] < nums[i+1] -> breakpoint
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                idx1=i;
                break;
            }
        }
        //no valid breakpoint found -> 
        //reverse the entire array & return
        if(idx1==-1) 
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        //traverse from back and find the first index where
        //nums[j] > nums[idx1]
        for(int j=n-1;j>=0;j--)
        {
            if(nums[j]>nums[idx1])
            {
                idx2=j;
                break;
            }
        }
        //swap values at idx1 & idx2
        swap(nums[idx1],nums[idx2]);
        //reverse from idx1+1 to end
        reverse(nums.begin()+idx1+1, nums.end());
}
