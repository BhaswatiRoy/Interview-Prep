Problem: https://leetcode.com/problems/valid-palindrome/description

/*
Appraoch:
1. Instead of creating a new string and checking palindrome we can use two pointers i=0 & j=n-1
2. Everytime we see an uppercase we convert to lower case and then check if s[i] == s[j]
3. We can also check if a charcter is alphanumeric otherwise we skip it and move to the next character
4. After all these if we ever find a point where s[i] != s[j] then we return false

TC: O(n)
SC: O(1)
*/

bool isPalindrome(string s) 
{
        int n=s.length();
        int i=0,j=n-1;
        while(i<j)
        {
            if(isupper(s[i]))
            {
                s[i]=tolower(s[i]);
            }
            if(isupper(s[j]))
            {
                s[j]=tolower(s[j]);
            }
            if(!isalnum(s[i]))
            {
                i++;
                continue;
            }
            if(!isalnum(s[j]))
            {
                j--;
                continue;
            }
            else
            {
                if(s[i]!=s[j])
                {
                    return false;
                }
            }
            i++;
            j--;
        }
        return true;
}
