Problem: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

/*Approach 1: 
Push all characters including brackets & alphabets to the stack and set paren=0
If we get an opening bracket then paren+=1 and if a closing bracket then paren-=1
Now check if paren=0 in the end then all ( and ) have canceled out each other so we can get the final string from the stack now
If paren>0 lets say paren = 3 so we have 3 extra ( left hence we need to skip adding any 3 ( 
If paren<0 lets say paren = -3 so we have 3 extra ) left hence we need to skip adding any 3 )
Lastly we need to reverse the string because stack is LIFO
*/

string minRemoveToMakeValid(string s) 
{
        stack<char>st;
        int n=s.length();
        int paren=0;
        //count parenthesis, +1 for ( and -1 for )
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
                paren+=1;
            }
            else if(s[i]==')')
            {
                //if there are ( left then only add ) or don't add )
                if(paren>0)
                {
                    paren-=1;
                    st.push(s[i]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans="";
        //if paren=0 so all ( ) have cancelled out each other then only add everything in the stack
        if(paren==0)
        {
            while(!st.empty())
            {
                ans+=st.top();
                st.pop();
            }
        }
        //open brackets left to deal with so we can't add everything in the stack
        else if(paren>0)
        {
            while(!st.empty())
            {
                if(st.top()=='(')
                {
                    //if open brackets are left in paren then don't add them 
                    //as they don't cancel out with close brackets
                    if(paren>0)
                    {
                        //not adding them until we get paren=0
                        paren--;
                    }
                    else
                    {
                        ans+=st.top();
                    }
                }
                else
                {
                    ans+=st.top();
                }
                st.pop();
            }
        }
        //close brackets left to deal with so we cant add everything in the stack
        else if(paren<0)
        {
            while(!st.empty())
            {
                if(st.top()==')')
                {
                    //if close brackets are left in paren then don't add them
                    //as they don't cancel out with open brackets
                    if(paren<0)
                    {
                        //not adding them unless we get paren =0
                        paren++;
                    }
                    else
                    {
                        ans+=st.top();
                    }
                }
                else
                {
                    ans+=st.top();
                    st.pop();
                }
            }
        }
        //reverse the output string because the stack is LIFO
        reverse(ans.begin(),ans.end());
        return ans;
}
