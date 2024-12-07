Problem: https://leetcode.com/problems/longest-common-prefix/description

/*
strs = ["flower","flow","flight"]
1. Consider "flower" as 1st prefox
2. Then compare with next word "flow"
3. Reduce alphabets from end of "flower" to match with "flow"
4. Then "flow" is new prefix
5. Again compate with next word "flight"
6. Reduce alphabets from end of "flow" to match with "flight"
7. Then "fl" is new prefix

TC: O(S) -> S = sum of characters in each word = 6+4+6 = 16
SC: O(1) -> no extra space needed
*/

string longestCommonPrefix(vector<string>& strs) 
{
        int n=strs.size();
        //no strings to check prefixes
        if(n==0)
        {
            return "";
        }
        //1st string considered as base prefix
        string prefix=strs[0];
        for(int i=1;i<n;i++)
        {
            while(strs[i].find(prefix)!=0)
            {
                //shorten the length of prefix to match
                //do it till we find a mach
                prefix=prefix.substr(0,prefix.length()-1);
                //if no match found then no prefixes
                if(prefix=="")
                {
                    return "";
                }
            }
        }
        return prefix;
}
