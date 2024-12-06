Problem: https://leetcode.com/problems/shortest-path-in-binary-matrix/description

/*
We can use a queue instead of priority queue -> watch striver video
Because we do not need to store shortest distance wise because every distance is at +1 
So every level in queue will have same distance value

1. Move from start (0,0) to end (n-1,n-1) using Dijkstra's Algorithm
2. Store the start node in the queue & mark it as 1 in the grid to mark it as visited
3. Store {distance, {row,col}} in queue
4. For each element in the queue, find all 8 adjacent nodes & check if within bounds
5. If any node is marked 0 in the grid means a clear path & has not been visited 
6. Then push to the queue & mark as 1 to mark it as visited
7. If anytime we reach the end node then just return the distance
8. Return -1 at the end if no path is found.
9. In the beginning we see if the start/end has 1 marked so it's not a clear path to visit so return -1.

TC: O(n^2) -> traversing entire matrix in worst case
SC: O(n^2) -> storing all n^2 nodes in queue in worst case
*/

int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
{
        int n=grid.size();
        pair<int,int>start={0,0};
        pair<int,int>end={n-1,n-1};
        if(grid[0][0]==1 || grid[n-1][n-1]==1) 
        {
            return -1;
        }
        //storing {distance, {row,col}} in queue
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        //mark start node as visited
        grid[0][0]=1;
        while(!q.empty())
        {
            pair<int,pair<int,int>>p=q.front();
            int dist=p.first;
            pair<int,int>cell=p.second;
            int row=cell.first;
            int col=cell.second;
            q.pop();
            if(row==n-1 && col==n-1)
            {
                return dist+1;
            }
            //iterate through all 8 directions
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int newrow=row+i;
                    int newcol=col+j;
                    //skip the current cell
                    if(newrow==row && newcol==col)
                    {
                        continue;
                    }
                    //check if the cell is valid and within bounds
                    if(newrow>=0 && newrow<n && newcol>=0 && newcol<n)
                    {
                        //check for a clear path
                        if(grid[newrow][newcol]==0)
                        {
                            //push cell to queue & mark as visited
                            q.push({dist + 1, {newrow, newcol}});
                            grid[newrow][newcol]=1;
                        }
                    }
                }
            }
        }
        return -1;
}
