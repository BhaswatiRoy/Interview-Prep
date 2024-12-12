Problem: https://leetcode.com/problems/powx-n/description

/*
Approach:
ans = 1
2^10 = (2*2)^5 = 4^5 (n%2==1) (power is odd)
4^5 = 4 * 4^4 (n%2==0) (power is even) -> ans = 1*4
4^4 = (4*4)^2 = 16^2 (n%2==0) (power is even)
16^2 = (16*16)^1 = (256)^1 (n%2==1) (power is odd)
-> ans = 1*4*256 = 1024
TC: O(logn) -> n is halved everytime its even
SC: O(1)
*/

double myPow(double x, int n) 
{
        double ans=1.0;
        long long num=n;
        //took long long instead of int because int is ranged -2147483648 to -2147483647
        //if we change the max -ve value of int to +ve it will give int overflow 
        if(num<0)
        {
            num=-1*num;
        }
        while(num>0)
        {
            //2^10 = (2*2)^5 = 4^5
            if(num%2==0)
            {
                x = (x*x);
                num=num/2;
            }
            //4^5 = 4 * 4^4 -> ans = 1 * 4
            else
            {
                ans = (ans*x);
                //now n becomes even so previous case again
                num=num-1;
            }
        }
        //if power was -ve like 5^(-2) then it is 1/5^(2)
        if(n<0)
        {
            ans=1.0/ans;
        }
        return ans;
}
