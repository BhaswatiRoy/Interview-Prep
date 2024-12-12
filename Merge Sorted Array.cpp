Problem:

/*
nums1 = [1,2,3,0,0,0], m=3
nums2 = [2,5,6]      , n=3

i=2, j=2, last=5
3 < 6 -> [1,2,3,0,0,6]
3 < 5 -> [1,2,3,0,5,6]
3 > 2 -> [1,2,0,3,5,6]
2 = 2 -> [1,0,2,3,5,6]
1 < 2 -> [1,2,2,3,5,6]

TC: O(m+n)
SC: O(1)
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
        //last numbers in both arrays
        int i=m-1, j=n-1;
        //last empty position of nums1
        int last=(n+m)-1;
        while(i>=0 && j>=0)
        {
            //is nums2 has greater value then add to last index
            if(nums1[i]<nums2[j])
            {
                nums1[last]=nums2[j];
                j--;
                last--;
            }
            //otherwise add nums1 value to last index
            else if(nums1[i]>=nums2[j])
            {
                nums1[last]=nums1[i];
                nums1[i]=0;
                i--;
                last--;
            }
        }
        //remaining nums2 elements are added to nums1
        while(j>=0)
        {
            nums1[last]=nums2[j];
            j--;
            last--;
        }
}
