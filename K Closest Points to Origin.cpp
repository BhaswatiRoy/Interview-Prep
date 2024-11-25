Problem: https://leetcode.com/problems/k-closest-points-to-origin/description/

/*
Approach:
1. Traverse and calculate the distance of each point from origin
2. Since we need k closest points we can avoide calculating square root to avoid rounding errors
3. Then push them to the min heap priority queue
4. Then store top k elements from the priority queue to a vector and return

TC: O(n) -> traverse n points
SC: O(nlogn) + O(klogn) -> pushing n elements into the priority queue + extracting top k elements from priority queue of n elements
*/

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
{
        int n=points.size();
        vector<vector<int>>ans;
        //store {distance, ith point} in min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++)
        {
            vector<int>temp=points[i];
            int xi=temp[0];
            int yi=temp[1];
            //calculate distance of the points from origin using Euclidean Distance
            //we dont need to calculate sqrt because it might give rounding error
            int dist=pow((xi-0),2)+pow((yi-0),2);
            pq.push({dist,i});
        }
        //store top k elements into the vector
        while(k--)
        {
            pair<int,int>tops=pq.top();
            pq.pop();
            int idx=tops.second;
            ans.push_back(points[idx]);
        }
        return ans;
}
