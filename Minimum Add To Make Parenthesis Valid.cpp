Problem: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description

/*
Approach 1:
1. If its a ( then push to the stack
2. If its a ) then check if stack is not empty & top is ( then remove top
3. In end count the size of stack, we need that many additions

TC: O(n)
SC: O(n)

Approach 2:
1. Keep 2 variables open & close for counting
2. If we get a ( then open++
3. If we get a ) we check if open>0 so unmatched ( is there so open--
   Because we match the previous ( with current )
4. Otherwise do close++
5. In end just return open + close for number of unmatched parenthesis

TC: O(n)
SC: O(1)
*/

int minAddToMakeValid(string s) 
{
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(!st.empty() && st.top()=='(')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        return st.size();
}

int minAddToMakeValid(string s) 
{
        int n=s.length();
        int open=0, close=0;
        for(int i=0;i<n;i++)
        {
            //count increase for (
            if(s[i]=='(')
            {
                open++;
            }
            else if(s[i]==')')
            {
                //any unmatched ( will be cancelled out
                if(open>0)
                {
                    open--;
                }
                //otherwise increase ) count
                else
                {
                    close++;
                }
            }
        }
        //at last return the no of unmatched ( & )
        return open+close;
}
