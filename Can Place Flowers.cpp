Problem: https://leetcode.com/problems/can-place-flowers/description/

/*
Approach:
1. Keep "prev", "next", "curr" pointers
2. If i is at last index then "next" is 0
3. If i is at 1st index then "prev" is 0
4. Otherwise "prev" is i-1 value & "next" is i+1 value
5. If all of "prev", "next", "curr" are 0 then we can place flower at "curr"
6. Once placed, mark "curr" as 1 and increment "total" by 1
7. Lastly check if "total" is equal to n then return true or return false

TC: O(n) -> single pass traversal
SC: O(1) -> no extra space
*/

bool canPlaceFlowers(vector<int>& flowerbed, int n) 
{
        int size=flowerbed.size();
        int prev=0, next=0;
        int total=0;
        for(int i=0;i<size;i++)
        {
            if(total==n)
            {
                break;
            }
            int next, prev;
            int curr=flowerbed[i];
            if(i==size-1)
            {
                next=0;
            }
            else
            {
                next=flowerbed[i+1];
            }
            if(i==0)
            {
                prev=0;
            }
            else
            {
                prev=flowerbed[i-1];
            }
            if(prev==0 && next==0 && curr==0)
            {
                total++;
                flowerbed[i]=1;
            }
        }
        if(total==n)
        {
            return true;
        }
        return false;
}
