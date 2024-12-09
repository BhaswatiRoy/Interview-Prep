Problem: https://leetcode.com/problems/rotate-image/description

/*
Approach:
1 2 3                  1 4 7                     7 4 1
4 5 6 -- transpose --> 2 5 8 -- reverse rows --> 8 5 2
7 8 9                  3 6 9                     9 6 3
1. Transpose the matrix
2. Reverse each row

TC: O(n^2)
SC: O(1)
*/

void rotate(vector<vector<int>>& matrix) 
{
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int k=0;k<n;k++)
        {
            reverse(matrix[k].begin(),matrix[k].end());
        }
}
