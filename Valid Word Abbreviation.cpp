Problem: https://leetcode.com/problems/valid-word-abbreviation/description

/*
Approach: 
word = "internationalization", abbr = "i12iz4n"
1. i pointer in word, j pointer in abbr
2. if a number is found in abbr then check if it's a leading 0 then instantly return a false
3. if not then use a while loop to check for more numbers for multi-digits like 12 in "abbr"
4. Once found the entire number convert it to a numeric format like 12.
5. We need to move 12 steps forward in "word" and update the i pointer to i+=steps to move 12 steps forward.
6. Then if a character is found we need to check if the current position at "abbr" and "word" matches.
7. In the end, we just need to check if both i and j have reached the end of both the "word" and "abbr" strings to prove everything is processed.
8. If not then we return a false, otherwise if both pointers reached till the end then return a true.

TC: O(n) -> worst case both "abbr" and "word" will be of the same length where "abbr" is the same as "word" and not an abbreviation
SC: O(1) -> no extra space used
*/

bool isdigit(char ch)
{
        if(ch>='0' && ch<='9')
        {
            return true;
        }
        return false;
}

bool validWordAbbreviation(string word, string abbr) 
{
        int n=word.length();
        int m=abbr.length();
        int i=0,j=0;
        while(i<n && j<m)
        {
            //check if digit or character
            if(isdigit(abbr[j])==true)
            {
                //leading 0 case then instantly return false
                if(abbr[j]=='0')
                {
                    return false;
                }
                int steps=0;
                //checks for multi-digit numbers in between
                while(j<m && isdigit(abbr[j])==true)
                {
                    steps = steps*10 + (abbr[j]-'0');
                    j++;
                }
                //increment i -> z from 4 steps to n in internationalization
                i+=steps;
            }
            else
            {
                //if characters then match with both strings word & abbr
                //if they do not match then return false
                if(word[i]!=abbr[j])
                {
                    return false;
                }
                //if they match just keep iterating
                i++;
                j++;
            }
        }
        //check if in the end both pointers reached the end & processed everything 
        if(i==n && j==m)
        {
            return true;
        }
        //if not then also not valid
        return false;
}
