Problem: https://leetcode.com/problems/valid-palindrome-iii/description/

/*
Approach 1: gives MLE/WA for bigger strings
1. Start from left = 0 & right = n-1
2. If characters match then keep going
3. If they dont match then remove left and check recursively for remaining string
4. Then also remove right and check recursively for remaining string
5. If removal of either left/right is true then return true
6. If anytime left >= right so we finished checking then return true
7. If ever k=0 then we return false because we cant change any more characters

TC: O(n*k) -> considering all n length cases & k removal cases
SC: O(n*n) -> 2d array of n*n

Approach 2: DP Memoization - Recursion stack overflow gives MLE
1. Find the longest palindromic subsequence using LCS pattern
2. LPS is basically LCS between a string & its reversed version
3. string length - LPS length <= k -> max k deletions can lead to Palindrome

TC: O(n^2) -> checking both strings of same length
SC: O(n^2) -> 2d dp vector leading to MLE 

Approach 3: DP Tabulation - Accepted
1. Instead o recursion stack we iteratively fill the DP matrix
TC: O(n^2) -> checking both strings of same length
SC: O(n^2) -> 2d dp vector but does not lead to MLE as no recursion stack used
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

//Approach 2: Memoization
//find the longest palindromic subsequence length
int lps(int n, int m, string s1, string s2,vector<vector<int>>&dp)
{
        //s1 = "abc", s2 = "" so lcs is "" of size 0
        if(n==0 || m==0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        //checking from last if characters from both strings have same value
        //then reduce length of both strings in next recursion call
        //1+ is done for counting this index value being same
        if(s1[n-1]==s2[m-1])
        {
            return dp[n][m]=1+lps(n-1,m-1,s1,s2,dp);
        }
        //if not same then reduce length of each one by one in next recursion calls
        //then return the max length obtained
        return dp[n][m]=max(lps(n-1,m,s1,s2,dp),lps(n,m-1,s1,s2,dp));
}
bool isValidPalindrome(string s, int k) 
{
        string s1=s;
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s1.length(), m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //LPS is basically LCS between string & reversed format
        int lpslen=lps(n,m,s1,s2,dp);
        //if we find LPS of length whose difference to original length is <= k
        //then we can remove max k characters to get palindrome
        if(n-lpslen<=k)
        {
            return true;
        }
        return false;
}

//Approach 3: Tabulation
//find longest palindromic subsequence length
int lps(int n, int m, string s1, string s2,vector<vector<int>>&dp)
{
        // Initialize base cases
        //LCS with empty s2 is 0
        for (int i = 0; i <= n; i++) 
        {
            dp[i][0] = 0; 
        }
        //LCS with empty s1 is 0
        for (int j = 0; j <= m; j++) 
        {
            dp[0][j] = 0; 
        }
        //base case 0 id initialized so start iterating from 1
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    //check if we reduce i and we reduce j separately 
                    //which of them is max
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
}
bool isValidPalindrome(string s, int k) 
{
        string s1=s;
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s1.length(), m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //LPS is basically LCS between string & reversed format
        int lpslen=lps(n,m,s1,s2,dp);
        //if we find LPS of length whose difference to original length is <= k
        //then we can remove max k characters to get palindrome
        if(n-lpslen<=k)
        {
            return true;
        }
        return false;
}
