Problem: https://leetcode.com/problems/basic-calculator-ii/description

/*
Approach 1: stack approach
1 + 2 * 3 - 5
1. whenever we see numbers we store them in a variable "curr"
2. when we see operators we see if it is * or / then we pop out last number and do * or / with current
3. if we see + then we directly add the number
4. if we see - then we add -1 * number
5. in the end we pop out all stack elements and add them to our result

TC: O(n) -> one pass
SC: O(n) -> stack

Approach 2: algebraic approach
1 + 2 * 3 - 5
1. see video & dry run
2. Instead of the stack we use the "result" variable & "last" to store the top of the stack

TC: O(n)
SC: O(1)
*/

int calculate(string s) 
{
        int n=s.length();
        stack<int>st;
        int curr=0;
        char operation='+';
        for(int i=0;i<n;i++)
        {
            //if digit
            if(isdigit(s[i]))
            {
                curr = (curr*10) + (s[i]-'0');
            }
            //if not digit & not whitespace then operator or its the last character
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || i==n-1)
            {
                //for + directly push the number to stack
                if(operation=='+')
                {
                    st.push(curr);
                }
                //for - push the negative of the number to stack
                else if(operation=='-')
                {
                    st.push(curr*(-1));
                }
                //for * pop the last number then multiply with current then push to stack
                else if(operation=='*')
                {
                    int top=st.top();
                    st.pop();
                    st.push(curr*top);
                }
                //for / pop the last number then multiply with current then push to stack
                else if(operation=='/')
                {
                    int top=st.top();
                    st.pop();
                    st.push(top/curr);
                }
                operation=s[i];
                curr=0;
            }
        }
        //in end add everything in the stack to get the answer
        int result=0;
        while(!st.empty())
        {
            result+=st.top();
            st.pop();
        }
        return result;
}

int calculate(string s) 
{
        int n=s.length();
        int curr=0,last=0;
        int result=0;
        char operation='+';
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                curr=(curr*10)+(s[i]-'0');
            }
            //if not digit & not whitespace then operator or its the last character
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || i==n-1)
            {
                if(operation=='+')
                {
                    result+=last;
                    last=curr;
                }
                else if(operation=='-')
                {
                    result+=last;
                    last=-curr;
                }
                else if(operation=='*')
                {
                    last=last*curr;
                }
                else if(operation=='/')
                {
                    last=last/curr;
                }
                operation=s[i];
                curr=0;
            }
        }
        result+=last;
        return result;
}
