Problem: https://leetcode.com/problems/interval-list-intersections/description

/*
Approach:
case 1: [0,4], [7,8] -> no overalap so move 1st pointer ahead
case 2: [7,8], [0,4] -> no overlap so move 2nd pointer ahead
in whichever list we have lesser value we move that pointer ahead

case 3: [1,4], [2,6] -> intersection: {2,4} 
so we take max(start1,start2) & min(end1,end2) for intersection

TC: O(n+m) -> worst case both have same size and we traverse both
SC: O(n) -> result vector stores n intervals of size 2 each
*/

vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) 
{
        int n=firstList.size();
        int m=secondList.size();
        vector<vector<int>>ans;
        if(n==0 || m==0)
        {
            return {};
        }
        int i=0,j=0;
        while(i<n && j<m)
        {
            int start1=firstList[i][0];
            int end1=firstList[i][1];
            int start2=secondList[j][0];
            int end2=secondList[j][1];
            //case 1: [0,4], [7,8] -> no overalap so move ahead
            if(start2>end1)
            {
                i++;
            }
            //case 2: [7,8], [0,4] -> no overlap so move ahead
            else if(start1>end2)
            {
                j++;
            }
            //case 3: [1,4], [2,6] -> intersection: {2,4} 
            else 
            {
                vector<int>intersections;
                intersections.push_back(max(start1,start2));
                intersections.push_back(min(end1,end2));
                ans.push_back(intersections);
                //[1,8], [2,6] -> move 2nd pointer
                if(end1>end2)
                {
                    j++;
                }
                //[1,6], [2,8] -> move 1st pointer
                else
                {
                    i++;
                }
            }
        }
        return ans;
}
