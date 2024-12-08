Problem: https://leetcode.com/problems/valid-number/description

/*
Approach: 
Too many cases & edge cases to handle
1. 2 variables "decimal_used" & "numbers_used" to keep track of decimals & numbers
2. If we find a + or - in beginning we just increment pointer
3. If we find alphabet which is not e or E then simply return false
4. If we find e or E then we check if numbers are found before if not then return false
5. We also need to check if the part after e or E is a valid number using a separate function
6. If we find a . we check if we got . before then simply return false
7. If we did not get a . before this then increment decimal_used
8. If we find + or - then we check if there is an e or E before it otherwise return false
   It is not allowed to have a + or - without e or E before it
9. After while loop ends we make sure we got numbers i.e "numbers_used" > 0 then we return true
10. otherwise return false

TC: O(n) -> single pass traversal
SC: O(1) -> no extra space used
*/

//for checking part after e or E
//almost same as actual function
bool isvalidinteger(string part)
{
        int m=part.length();
        //e or E is in end so empty string after that so invalid
        if(part=="")
        {
            return false;
        }
        int numbers_used=0;
        int j=0;
        if(part[j]=='+' || part[j]=='-')
        {
            j++;
        }
        while(j<m)
        {
            char ch=part[j];
            if(!isdigit(ch))
            {
                return false;
            }
            else
            {
                numbers_used++;
            }
            j++;
        }
        if(numbers_used>0)
        {
            return true;
        }
        return false;
}
bool isNumber(string s) 
{
        int decimal_used=0;
        int numbers_used=0;
        int n=s.length();
        int i=0;
        //+ or - can be in the beginning
        if(s[i]=='+' || s[i]=='-')
        {
            i++;
        }
        while(i<n)
        {
            char ch=s[i];
            if(isalpha(ch))
            {
                //only 'e' & 'E' are allowed for scientific purposes
                if(ch!='e' && ch!='E')
                {
                    return false;
                }
                else
                {
                    //no numbers used before & after 'e' or 'E'
                    if(numbers_used==0 || i+1 ==n || isvalidinteger(s.substr(i+1))==false)
                    {
                        return false;
                    }
                }
            }
            //if decimal found check if decimal was found before
            else if(ch=='.')
            {
                //only allowed 1 decimal in valid number
                if(decimal_used>0)
                {
                    return false;
                }
                //if no decimal found before then increment the count
                else
                {
                    decimal_used++;
                }
            }
            //+ or - in between are not allowed
            else if(ch=='+' || ch=='-')
            {
                //if a + or - occurs then an e or E must be before it
                if(i>0 && s[i-1]!='e' && s[i-1]!='E') 
                {
                    return false;
                }
            }
            //only case remaining is of seeing a number
            else
            {
                numbers_used++;
            }
            i++;
        }
        //'+' is invalid number but will clear all checks in while loop
        //need to ensure we saw atleast 1 digit
        if(numbers_used>0)
        {
            return true;
        }
        return false;
}
