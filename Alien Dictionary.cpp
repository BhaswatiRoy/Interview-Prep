Problem: https://leetcode.com/problems/alien-dictionary/description

/*
Approach:
words = ["wrt","wrf","er","ett","rftt"]

1. Keep a map to store all distinct characters
2. Take 2 adjacent strings like "wrt" & "wrf" so t comes before f in dictionary
3. Iterate in both string till a point where characters are different 
4. Store them in adjacency matrix according to ascii 
5. like t -'a' (116 - 97 = 19) index stores f - 'a' (102 - 97 = 5)
6. handle prefix violation: ("abc", "ab"), in English, a comes before ab, which comes before abc
7. shorter word should come before, and in above case its coming after so handle that violation
8. then apply topological sort to get alien dictionary lexicographical format
9. in end check if topo sort has same number of elements as in map as map stores distinct characters
10. if not then return "", and if it has same number of elements then store then in a string & return

TC: O(n * m) -> n = number of words, m = max length of a word
SC: O(26 * 26) = O(676) -> constant space
*/

void toposort(int n, vector<vector<int>>&adj, vector<int>&indegree, vector<int>&kahns, unordered_map<int,int>mp)
{
        queue<int>q;
        //t -> f so indegree of f will be ++1
        for(int i=0;i<26;i++)
        {
            //there can be multiple adjacent nodes
            vector<int>temp=adj[i];
            for(int j=0;j<temp.size();j++)
            {
                indegree[temp[j]]++;
            }
        }
        for(int k=0;k<indegree.size();k++)
        {
            //use the map to check if the character was used
            //other all 26 alphabets will be pushed to queue
            if(indegree[k]==0 && mp.find(k)!=mp.end())
            {
                q.push(k);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            kahns.push_back(node);
            vector<int>adjnodes=adj[node];
            for(int l=0;l<adjnodes.size();l++)
            {
                int adjnode=adjnodes[l];
                indegree[adjnode]--;
                if(indegree[adjnode]==0)
                {
                    q.push(adjnode);
                }
            }
        }
}

string alienOrder(vector<string>& words) 
{
        int n=words.size();
        vector<vector<int>>adj(26);
        vector<int>indegree(26);
        vector<int>kahns;
        //map to track all distinct alphabets
        unordered_map<int,int>mp;
        for(auto it1: words)
        {
            for(auto it2: it1)
            {
                mp[it2-'a']++;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            string s1=words[i];
            string s2=words[i+1];
            int sz1=s1.length();
            int sz2=s2.length();
            int j=0,k=0;
            while(j<sz1 && k<sz2)
            {
                if(s1[j]!=s2[k])
                {
                    //since we are storing index wise we need numbers
                    //converting characters to ASCII values
                    adj[s1[j]-'a'].push_back(s2[k]-'a');
                    break;
                }
                j++;
                k++;
            }
            //handle prefix violation like: ["abc", "ab"]
            //second word is a prefix of the first word, 
            //which is invalid for lexicographical order in the alien dictionary
            //in English, a comes before ab, which comes before abc
            //shorter words come before so this is a violation
            if (j==sz2 && sz1>sz2) 
            {
                //return empty string for invalid input
                return "";  
            }
        }
        toposort(n,adj,indegree,kahns,mp);
        //if topo sort is not all for unique characters
        //then cycle present so return ""
        if(kahns.size()<mp.size())
        {
            return "";
        }
        string ans="";
        for(int l=0;l<kahns.size();l++)
        {
            ans+=char(kahns[l]+'a');
        }
        return ans;
}
