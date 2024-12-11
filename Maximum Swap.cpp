Problem: https://leetcode.com/problems/maximum-swap/description/

/*
Approach:
num = 7236
1. convert the number to string 
2. Initialise "maxidx" as n-1, "left" & "right" as -1
3. start iterating from right from n-2
4. If we find a greater value than one at "maxidx" then we make that index as "maxidx"
5. But if we find a smaller value than one at "maxidx" then we make it as "left" & "right" is "maxidx"
6. In end we check if left is -1 then we did not find a smaller value to right side of "maxidx"
7. In that case return the actual num
8. Otherwise swap "left" & "right" and then return

TC: O(n) -> single pass traversal
SC: O(n) -> taking string of length n
*/

int maximumSwap(int num) 
{
        string str=to_string(num);
        int n=str.length();
        int maxidx=n-1;
        int left=-1,right=-1;
        for(int i=n-2;i>=0;i--)
        {
            //store index for max value till now
            if(str[i]>str[maxidx])
            {
                maxidx=i;
            }
            //we dont consider equality case because no point of swapping
            else if(str[i]<str[maxidx])
            {
                //to swap left & right
                //max value with a smaller vlaue to its right
                left=i;
                right=maxidx;
            }
        }
        //could not find a smaller value on left of max digit
        if(left==-1)
        {
            return num;
        }
        //swap largest digit to the smallest digit on its left
        swap(str[left],str[right]);
        int newnum=stoi(str);
        return newnum;
}
