Problem: https://leetcode.com/problems/random-pick-with-weight/description

/*
wt = {1, 2, 3} -> weight sum = 6
chances to pick 1: 1/6
chances to pick 2: 2/6
chances to pick 3: 3/6

prefix sum =    {1, 3, 6} -> sorted because all positive numbers
bucket ranges = (0,1],(1,3], (3,6]
so we can apply binary search here
larget probability of choosing depends on value of weight/sum
like chances to pick 1 is 1/6 but chances to pick 3 is 3/6 which is 1/2

we will generate a random number: rand()% totalweight = 4
now we will check in which part of cummulative sum array is the random number
using binary search we check that 4 is in the 3rd bucket (3,6] so we return index = 2

TC: O(n) & O(logn) -> initialization & picking
SC: O(n) -> prefix sum stored
*/

vector<int>prefixsum;
int totalweight=0;
Solution(vector<int>& w) 
{
        int n=w.size();
        for(int i=0;i<n;i++)
        {
            totalweight+=w[i];
            prefixsum.push_back(totalweight);
        }
}
    
int pickIndex() 
{
        int target=rand()%totalweight;
        int m=prefixsum.size();
        int l=0, r=m-1, mid=0;
        while(l<r)
        {
            mid=(l+r)/2;
            if(prefixsum[mid]>target)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
}
