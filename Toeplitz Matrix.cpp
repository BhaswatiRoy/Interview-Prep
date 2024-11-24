Problem:

/*
Approach:
1. Check every element with its adjacent diagonal element
2. Check every i,j th element with its adjacent i+1,j+1 element
3. if at any point the element does not match with its adjacent diagonal element then return false

TC: O(n*m) -> traversing the n*m matrix
SC: O(1) -> no extra space used
*/

bool isToeplitzMatrix(vector<vector<int>>& matrix) 
{
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<m-1;j++)
            {
                //diagonal of i,j is always i+k,j+k where k=1,2,3,4
                //so we compare each element with its adjacent diagonal element
                if(matrix[i][j]!=matrix[i+1][j+1])
                {
                    return false;
                }
            }
        }
        return true;
}
