Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

/*
Approach 1:
1. Run nested loops
2. For each value check for smaller value on right of it
3. Store if we get greater profit
TC: O(n^2) -> nested loops
SC: O(1)

Approach 2:
[7,1,5,3,6,4] 
1. Keep variables "mini" for lowest price before current price
2. Keep "profit" to mark current profit & "maxprofit" to mark max profit
3. Keep iterating and compare to store lowest value of "mini"
4. Then find the "profit" & "maxprofit" for each value
TC: O(n) -> single pass solution
SC: O(1)
*/

//optimal approach
int maxProfit(vector<int>& prices) 
{
        int n=prices.size();
        int mini=INT_MAX;
        int profit=0, maxprofit=0;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,prices[i]);
            profit=prices[i]-mini;
            maxprofit=max(maxprofit,profit);
        }
        return maxprofit;
}
