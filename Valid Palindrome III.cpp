Problem: https://leetcode.com/problems/valid-palindrome-iii/description/

/*
Approach: gives MLE/WA for bigger strings
1. Start from left = 0 & right = n-1
2. If characters match then keep going
3. If they dont match then remove left and check recursively for remaining string
4. Then also remove right and check recursively for remaining string
5. If removal of either left/right is true then return true
6. If anytime left >= right so we finished checking then return true
7. If ever k=0 then we return false because we cant change any more characters

TC: O(n*k) -> considering all n length cases & k removal cases
SC: O(n*n) -> 2d array of n*n
*/

bool validpalindrome(int left, int right, int k, string s, vector<vector<int>>&dp)
{
        if(left>=right)
        {
            return true;
        }
        if(dp[left][right]!=-1)
        {
            return dp[left][right];
        }
        //if characters are same then just recursively move to next characters
        //dont decrement k as we are not removing 
        if(s[left]==s[right])
        {
            return dp[left][right]=validpalindrome(left+1,right-1,k,s,dp);
        }
        //if we reach to a point where no more changes can be made to make palindrome
        //so return false as we cant make palindrome anymore
        if(k==0)
        {
            return dp[left][right]=false;
        }
        //if we remove left we have string from left+1 to right
        bool leftremove=validpalindrome(left+1,right,k-1,s,dp);
        //if we remove right we have string from left to right-1
        bool rightremove=validpalindrome(left,right-1,k-1,s,dp);
        //if any of leftremove or rightremove is T so palidrome can be made
        dp[left][right]=leftremove || rightremove;
        return dp[left][right];
}
bool isValidPalindrome(string s, int k) 
{
        int n=s.length();
        int left=0, right=n-1;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        bool ans=validpalindrome(left,right,k,s,dp);
        return ans;
}
