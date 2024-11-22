Problem:

/*
Approach:
intervals = [start, end]
1. sort the 2d vector of intervals
2. set 1st interval value to "last"
3. now start iterating from the 2nd interval value at index=1
4. if we find an interval value with an end value more than "last" 's end value then we update "last" 's end value to that
5. otherwise we will push "last" to our output vector and set "last" to the current interval

TC: O(n) -> single pass traversal
SC: O(n^2) -> the 2d vector where we need to store our output
*/

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
        if(intervals.size()==0)
        {
            return {};
        }
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int>last=intervals[0];
        vector<vector<int>>ans;
        for(int i=1;i<n;i++)
        {
            //intervals that can be merged
            if(last[1]>=intervals[i][0])
            {
                //(1,3) & (2,6) -> (1,6)
                last[1]=max(last[1],intervals[i][1]);
            }
            //disjoint intervals so push "last" and set the current interval to "last"
            else
            {
                ans.push_back(last);
                last=intervals[i];
            }
        }
        //add the last value remaining
        ans.push_back(last);
        return ans;
}
