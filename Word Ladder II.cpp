Problem: https://leetcode.com/problems/word-ladder-ii/description

/*
Approach 1: gives MLE for LC
1. store all words from "wordList" to a map for easy searching later
2. In the queue we will store the entire sequence & a variable "level" to track levels
3. For every sequence stored in the queue, we will take out the last word
4. And change characters in the word to make combinations to find in the "wordList"
5. If we find a word then we push it to the current sequence and push that to the queue
6. Once all sequences of 1 level are done then we remove the used words from the map
7. Since there can be multiple sequences we don't remove the word from the map unless one level is completed
8. If we find the endWord then we push it to the "ans" vector

TC: O(n * m * l) -> n = no of words, m = avg no of transformations for each word, l = length of each word
SC: O(N^2) + O(n) -> Each sequence can go upto n size and there are n words for both queue & "ans" vector + usedonlevels + 
*/

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
{
        int n=wordList.size();
        unordered_map<string,int>mp;
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            mp[wordList[i]]++;
        }
        queue<vector<string>>q;
        q.push({beginWord});
        //stores strings used on 1 level
        vector<string>usedonlevels;
        usedonlevels.push_back(beginWord);
        int level=0;
        while(!q.empty())
        {
            vector<string>seq=q.front();
            int seqsize=seq.size();
            string word=seq[seqsize-1];
            int wordlen=word.length();
            q.pop();
            if(word==endWord)
            {
                //first sequence we got
                if(ans.size()==0)
                {
                    ans.push_back(seq);
                }
                else
                {
                    //if the current sequence length is the same as the sequences in "ans"
                    //because all will be of the same length i.e shortest length
                    if(ans[0].size()==seq.size())
                    {
                        ans.push_back(seq);
                    }
                }
            }
            //if seq size is more than level
            //we reached the next level so remove words used in the last level
            //because we don't need them anymore to find the shortest sequence
            //using them again will only make the sequence bigger not shorter
            if(seq.size()>level)
            {
                level++;
                for(auto it: usedonlevels)
                {
                    mp.erase(it);
                }
                usedonlevels.clear();
            }
            for(int j=0;j<wordlen;j++)
            {
                string temp=word;
                for(char ch='a';ch<='z';ch++)
                {
                    temp[j]=ch;
                    if(mp.find(temp)!=mp.end())
                    {
                        vector<string>newseq=seq;
                        newseq.push_back(temp);
                        q.push(newseq);
                        usedonlevels.push_back(temp);
                    }
                }
            }
        }
        return ans;
}
