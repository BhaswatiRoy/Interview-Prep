Problem: https://leetcode.com/problems/meeting-rooms-ii/description

/*
1. Store all start & end times in 2 different vectors
2. Use two pointers and iterate through both and keep a "room" variable to count and "maxroom" to store
3. Sort them in ascending order
4. If start < end then we do room++ because we need 1 extra room because of a clashing meeting
5. If start >= end the we room-- because 1 room is empty now
6. In every iteration we check if "room" is more than "maxroom"

TC: O(n)
SC: O(n)
*/

int minMeetingRooms(vector<vector<int>>& intervals) 
{
        vector<int>start,end;
        int n=intervals.size();
        //start = {0, 5, 15}
        //end = {10, 20, 30}
        for(int i=0;i<n;i++)
        {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        //sort the timings
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int j=0,k=0,rooms=0;
        int maxrooms=0;
        while(j<n && k<n)
        {
            //1 meeting started before another ended so room++
            //we need extra room to allocate the other meeting 
            if(start[j]<end[k])
            {
                rooms++;
                j++;
            }
            //1 meeting ended before another started so room--
            //meeting ended so vacate that room for the other meeting
            else if(start[j]>=end[k])
            {
                rooms--;
                k++;
            }
            maxrooms=max(rooms,maxrooms);
        }
        return maxrooms;
}
