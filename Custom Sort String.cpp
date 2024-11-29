Problem: https://leetcode.com/problems/custom-sort-string/description

/*
order = "kqep", s = "pekeq"
1. Store all characters of "s" in a map with frequency
2. Traverse through the order and add characters from the map with frequency
3. After a character is added then remove it from the map
4. In the end traverse the map to see if any element is left to add then add with frequency

TC: O(n + m) -> iterate over "s" to store in map + iterate over "order"
SC: O(26 + m) -> at max 26 english characters stored in map + size of ans is same as "s"
*/

string customSortString(string order, string s) 
{
        int n=order.length();
        int m=s.length();
        unordered_map<char,int>mp;
        //store everything from "s" in a map with frequency of characters
        for(int i=0;i<m;i++)
        {
            mp[s[i]]++;
        }
        string ans="";
        for(int j=0;j<n;j++)
        {
            //if any "order" character is found in "s"
            //then add all occurrences of that character in "ans"
            if(mp.find(order[j])!=mp.end())
            {
                int freq=mp[order[j]];
                while(freq--)
                {
                    ans+=order[j];
                }
                //also remove that character from the map as it's done
                mp.erase(order[j]);
            }
        }
        //store remaining characters from the map
        for(auto it:mp)
        {
            int remfreq=it.second;
            while(remfreq--)
            {
                ans+=it.first;
            }
        }
        return ans;
}
