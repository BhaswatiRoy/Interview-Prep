Problem: https://leetcode.com/problems/word-ladder/description

/*
beginWord="hit", endWord="cog", wordList = ["hot","dot","dog","lot","log","cog"]
        hit
        /
      hot
      /
    dot
    /
  dog
  /
cog

1. Store all words from "wordList" into a map for easy access later
2. If the "endWord" is not in map return 0 as no sequence is possible then
3. Store {word, distance in sequence} in queue
4. Push {beginWord, 1} in queue as the "beginWord" will always be at distance 1 as its starting point
5. Then start popping words from queue like we do in BFS
6. Then iterate through each word and change every character to all 26 alphabets 
7. Then for each word combination check if it in "wordList" & not equal to actual word 
8. Then push to queue & remove from the map to mark it as visited once to save time & not visit again
9. While pushing, also store dist+1 everytime for marking sequence distance
10. And while making word combinations, we need to check if its "endWord" then instantly return dist+1

TC: O(n * m * 26) -> n = wordList length, m = average length of word, 26 = iterating 26 alphabets everytime
SC: O(n * m) -> map stores n words with m length each
*/

int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
        int n=wordList.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[wordList[i]]++;
        }
        //if last word not in wordList then no sequence exists
        if(mp.find(endWord)==mp.end())
        {
            return 0;
        }
        //storing {string, distance}
        queue<pair<string,int>>q;
        //1st word will always be at 1st position in sequence
        q.push({beginWord,1});
        while(!q.empty())
        {
            string node=q.front().first;
            int dist=q.front().second;
            q.pop();
            int m=node.size();
            for(int j=0;j<m;j++)
            {
                string temp=node;
                //change all alphabets of each word to all 26 alphabets
                for(char ch='a'; ch<='z'; ch++)
                {
                    temp[j]=ch;
                    //if we ever find the endWord then return dist+1
                    //no need to check more as this is the nearest we can get
                    if(temp==endWord)
                    {
                        return dist+1;
                    }
                    //check if any in wordList and is not equal to current word
                    //then push it to the queue
                    if(mp.find(temp)!=mp.end() && temp!=node)
                    {
                        q.push({temp,dist+1});
                        //erasing works as visited array to mark it visited
                        //so we dont visit it again and waste time
                        mp.erase(temp);
                    }
                }
            }
        }
        //if till end we dont find the endWord then no sequence exists
        return 0;
}
