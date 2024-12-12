Problem: https://leetcode.com/problems/find-peak-element/description

/*
Approach 1:
1. iterate through the entire array & check for each element
2. once the peak is found return
TC: O(n)
SC: O(1)

Approach 2:
nums = [1,2,1,3,5,6,4]
1. use binary search instead of linear search
2. if n==1 then return 0
3. check if 0th & n-1th elements are peak elements then return
4. Otherwise set left=1, right=n-2, mid=0
5. mid=left+(right-left)/2= 0+(6-0)/2 = 3
6. nums[3] = 3, we see it is not peak, and its sequence is 1 3 5 which is increasing on the right
7. so the peak must be somewhere on the right
8. left = mid + 1
9. similarly do for increasing on the left
10. If anytime mid is peak return mid
TC: O(logn)
SC: O(1)
*/

//binary search approach
int findPeakElement(vector<int>& nums) 
{
        int n=nums.size();
        //single element is always the peak
        if(n==1) 
        {
            return 0; 
        }
        //check if 0th element is peak element
        if(nums[0]>nums[1]) 
        {
            return 0;
        }
        //check if n-1th element is peak element
        if(nums[n-1]>nums[n-2])
        {
            return n-1;
        }
        //search in remaining array excluding 0th & n-1th index
        int left=1,right=n-2,mid=0;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            //check if mid is peak element -> 5,6,4
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
            {
                return mid;
            }
            //1 3 5 -> increasing towards right sequence
            //so mid is somewhere on right
            else if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1])
            {
                left=mid+1;
            }
            //5 3 1 -> increasing towards left sequence
            //so mid is somewhere on left
            else if(nums[mid-1]>nums[mid] && nums[mid]>nums[mid+1])
            {
                right=mid-1;
            }
        }
        return 0;
}
