Problem: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

class Solution {
public:
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
                //if there are ( left then only add ) or dont add )
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
        //if paren=0 so all ( ) have cancelled out eachother then only add everything in stack
        if(paren==0)
        {
            while(!st.empty())
            {
                ans+=st.top();
                st.pop();
            }
        }
        //open brackets left to deal with so we cant add everything in stack
        else if(paren>0)
        {
            while(!st.empty())
            {
                if(st.top()=='(')
                {
                    //if open brackets left in paren then dont add them 
                    //as they dont cancel out with close brackets
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
        //close brackets left to deal with so we cant add everything in stack
        else if(paren<0)
        {
            while(!st.empty())
            {
                if(st.top()==')')
                {
                    //if close brackets left in paren then dont add them
                    //as they dont cancel out with open brackets
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
        //reverse the output string because stack is LIFO
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
