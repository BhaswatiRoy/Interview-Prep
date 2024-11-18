Problem: https://leetcode.com/problems/valid-palindrome-ii/description

/*
Approach 1: TLE
Remove each character and check if the resulting string is palindrome

TC: O(n) -> checkpalindrom() takes O(n) time and validpalindrome also takes O(n) time
SC: O(n) -> for the temp vector
*/

bool checkpalindrome(string str)
{
        string original=str;
        reverse(str.begin(),str.end());
        if(original==str)
        {
            return true;
        }
        return false;
}

bool validPalindrome(string s) 
{
        if(checkpalindrome(s)==true)
        {
            return true;
        }
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            string temp=s;
            temp.erase(i,1);
            if(checkpalindrome(temp)==true)
            {
                return true;
            }
        }
        return false;
}

/*
Approach 2:
1. Use 2 pointers i & j
2. If we get a position where s[i] != s[j] then we can check
   - if from i+1 to j is a palindrome
   or
   - if from i to j-1 is a palindrome
3. If any of the 2 is a palindrome then we can return true, otherwise false because we can't make a palindrome otherwise
4. Since using 2 pointers we are keeping on checking from start to i & j to end so we need to check only in between

TC: O(n) -> two pointer traversal
SC: O(1) -> no extra space used
*/

bool checkpalindrome(string str, int start, int end)
    {
        while(start<end)
        {
            if(str[start]!=str[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) 
    {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            //cabadc -> removing d solves problem
            // i  j  -> 
            else
            {
                //till i from beginning & till j from end is checked so check from i+1 to j
                //till j from end & till i from beginning is checked so check from i to j-1
                return (checkpalindrome(s,i+1,j)==true || checkpalindrome(s,i,j-1)==true);
            }
        }
        //in end all characters were checked and no problem was found then return true
        return true;
    }
