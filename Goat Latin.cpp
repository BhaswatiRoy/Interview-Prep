Problem: https://leetcode.com/problems/goat-latin/description/

/*
Approach:
1. Store all words in a vector of string
2. Then check if word's 1st character is vowel or consonant 
3. Then make changes accordingly
4. Also keep count of word index to make changes accordingly.
TC: O(n) -> single pass traversal
SC: O(n) -> vector of strings
*/

bool checkvowel(char ch)
{
        ch=tolower(ch);
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        {
            return true;
        }
        return false;
}
string toGoatLatin(string sentence) 
{
        vector<string>words;
        string word="";
        int n=sentence.length();
        for(int i=0;i<n;i++)
        {
            if(sentence[i]==' ')
            {
                if(!word.empty())
                {
                    words.push_back(word);
                }
                word="";
            }
            else
            {
                word+=sentence[i];
            }
        }
        if(!word.empty())
        {
            words.push_back(word);
        }
        int m=words.size();
        int wordindex=1;
        for(int j=0;j<m;j++)
        {
            string currword=words[j];
            if(checkvowel(currword[0])==true)
            {
                //push 'ma' once for vowel
                currword+="ma";
            }
            else
            {
                if(currword.size()>1) 
                {
                    char firstchar=currword[0];
                    currword.erase(currword.begin());
                    currword+=firstchar;
                }
                currword+="ma";
            }
            int it=wordindex;
            //push 'a' according to word index
            while(it--)
            {
                currword.push_back('a');
            }
            wordindex++;
            words[j]=currword;
        }
        string ans="";
        for(int k=0;k<m;k++)
        {
            ans+=words[k];
            if(k!=m-1)
            {
                ans+=" ";
            }
        }
        return ans;
}
