Problem:

/*
Approach:
1. Traverse through the string starting from index=1 because index=0 has /
2. keep storing the characters in "word" if they are alphabets 
3. if we get a / then we check if the "word" is empty then its // or /// so basically multiple / case
4. if "word" is not empty then we check if it's a .. then we pop the last value in the stack because this is the previous directory case
5. if "word" is neither . nor .. then we push it to stack (. is the case of the current directory)
6. and if we get a / we will make "word" empty because anyway, we pushed to stack so the operation done
7. After the entire traversal we check if "word" is empty or not. If not empty we check if it's .. or . or alphabets so we operate accordingly

TC: O(n) -> one traversal across the string
SC: O(n) -> new string & stack
*/

string simplifyPath(string path) 
{
        int n=path.size();
        string word="";
        stack<string>st;
        for(int i=1;i<n;i++)
        {
            //if we get / then we do operations
            if(path[i]=='/')
            {
                //if already a / was found then check if the word is not empty
                //if the word is empty then the string was pushed and its case of // or ///
                if(word!="")
                {
                    //if we find .. then we will pop the last word inserted 
                    //because .. means previous directory
                    if(word=="..")
                    {
                        if(!st.empty())
                        {
                            st.pop();
                        }
                    }
                    else
                    {
                        //if the word is not . then only insert
                        //if the word is . it means the current directory so no action is needed
                        if(word!=".")
                        {
                            st.push(word);
                        }
                    }
                    //and if any / was found make "word" empty
                    word="";
                }
            }
            //if we get a character store it and make the "word"
            else
            {
                word+=path[i];
            }
        }
        //in the end if any word is left to add to the stack then add it
        if(word!="")
        {
            //check if the last word is for the previous directory then remove the last word in the stack
            if(word=="..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            //if the last word is not in the current directory then push it to the stack
            else if(word!=".")
            {
                st.push(word);
            }
        }
        //store all words in a vector
        vector<string>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        //reverse it because the stack is LIFO
        reverse(ans.begin(),ans.end());
        string finalans="/";
        int m=ans.size();
        //finally create a string to generate the final answer
        for(int j=0;j<m;j++)
        {
            finalans+=ans[j];
            if(j!=m-1)
            {
                finalans+='/';
            }
        }
        return finalans;
}
