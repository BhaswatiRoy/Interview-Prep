Problem: https://leetcode.com/problems/diagonal-traverse/description

/*
Approach:
1 2 3
4 5 6
7 8 9
1. Start from 0,0, and go diagonally up initially
2. If we reach boundary while going up (col==n-1|| row==0) (like 3) then next we will go down
3. If we reach boundary while going down (row==m-1 || col==0) (like 7) then next we will go up
4. We will have a bool variable "up" to denote if we are going up or down
5. If no boundary while going up then row decreases & col increases
6. If no boundary while going down then col decreases & row increases

TC: O(n*m) -> traverse all n*m elements
SC: O(n*m) -> to store all n diagonal traversal elements
*/

vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
{
        int m=mat.size();
        int n=mat[0].size();
        //empty matrix  
        if(n==0)
        {
            return {};
        }
        vector<int>diagonaltraversal(n*m);
        int row=0,col=0;
        //indicates whether in current traversal we are going diagonally up or down
        bool up=true;
        int i=0;
        while(row<m && col<n)
        {
            diagonaltraversal[i++]=mat[row][col];
            //going diagonally up
            if(up==true)
            {
                //if we reach 3, then we need to move to next row
                //because we hit a boundary
                if(col==n-1)
                {
                    row++;
                    //boundary so need to go down now
                    up=false;
                }
                else if(row==0)
                {
                    col++;
                    //boundary so need to go down now
                    up=false;
                }
                //going diagonally up means row decreases & col increases
                else
                {
                    row--;
                    col++;
                }
            }
            else
            {
                //if we reach 8, then we need to move to next col
                //because we hit a boundary
                if(row==m-1)
                {
                    col++;
                    //boundary so need to go up now
                    up=true;
                }
                //otherwise we keep incrementing row
                else if(col==0)
                {
                    row++;
                    //boundary so need to go up now
                    up=true;
                }
                //going diagonally down means row increases & col decreases
                else
                {
                    row++;
                    col--;
                }
            }
        }
        return diagonaltraversal;
}
