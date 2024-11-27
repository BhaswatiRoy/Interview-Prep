Problem: https://leetcode.com/problems/number-of-islands/description

/*
1. Traverse through all points in the grid
2. If any point is "1" i.e land and not visited then call a bfs call
3. The bfs call ensures that all the adjacent "1"s in all 4 directions will be visited
4. Any "1"s not visited are a part of a different island
5. Everytime a bfs call is done island count increases by 1

TC: O(n*m) -> visiting all n*m points on grid
SC: O(n*m) -> visited vector
*/

void bfs(int i, int j, int n, int m, vector<vector<char>>&grid, vector<vector<int>>&visited)
{
        visited[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        vector<int>delrow={0,-1,0,1};
        vector<int>delcol={-1,0,1,0};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int newrow=row+delrow[k];
                int newcol=col+delcol[k];
                if((newrow>=0 && newrow<n) && (newcol>=0 && newcol<m) && grid[newrow][newcol]=='1' && visited[newrow][newcol]==0)
                {
                    q.push({newrow,newcol});
                    visited[newrow][newcol]=1;
                }
            }
        }
}

int numIslands(vector<vector<char>>& grid) 
{
        int n=grid.size();
        int m=grid[0].size();
        int islands=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    islands++;
                    bfs(i,j,n,m,grid,visited);
                }
            }
        }
        return islands;
}
