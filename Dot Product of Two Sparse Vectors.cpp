Problem:

/*
Approach 1: Naive dot product finding
1. Store all elements of both vectors and then find dot product
2. Space wise not much efficient
TC: O(n)
SC: O(n)

Approach 2: Hashing
v1 = {1,0,0,2,3}, v2 = {0,3,0,4,0}
mp1 = {0:1, 3:2, 4:3}, mp2 = {1:3, 3:4}
1. Store the non zero index & values only in map
2. Iterate through the 1st vector 
3. check if 2nd vector has non zero value at that index
4. If both has non zero value then find product
TC: O(n)
SC: O(n) -> in production this will perform much better

Approach 3: 
If the hashing function sucks in production then last solution is not good
Because then a lot of time will go for lookups & insertions
We cant assume the hash function is always good
1. Store the non zero index & values only in vector<pair<>>
2. Use two pointers to iterate & see if we find same indices
3. If same index found then move ahead both pointers & compute dot product
4. If not same index then move ahead the pointer for lower value
TC: O(n)
SC: O(n) -> in production this will perform much better & no tension of bad hashing function
*/

//Approach 2: Hashing
unordered_map<int,int>mp;
//function to store non zero values in map
SparseVector(vector<int> &nums) 
{
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                mp[i]=nums[i];
            }
        }
}
int dotProduct(SparseVector& vec) 
{
        int result=0;
        for(auto it: mp)
        {
            //Inside the SparseVector class, there is a member variable called mp
            //used to store the non-zero elements of the vector efficiently
            //For each index in the first vector (this->sparse)
            //check if the same index exists in the second vector (vec.sparse) using vec.sparse.find(index)
            if(vec.mp.find(it.first)!=vec.mp.end())
            {
                result+=(it.second*vec.mp[it.first]);
            }
        }
        return result;
}

//Approach 3: Two Pointers
vector<pair<int,int>>vp;
SparseVector(vector<int> &nums) 
{
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                vp.push_back({i,nums[i]});
            }
        }
}
int dotProduct(SparseVector& vec) 
{
        int i=0,j=0;
        int result=0;
        while(i<vp.size() && j<vec.vp.size())
        {
            //indices match so dot product can be found
            //v1 = {1,6}, v2 ={1,8}
            if(vp[i].first==vec.vp[j].first)
            {
                result+=(vp[i].second * vec.vp[j].second);
                i++;
                j++;
            }
            //move i pointer ahead if ith value is smaller
            //v1 = {1,5}, v2 = {3,6}, so move i ahead 
            else if(vp[i].first<vec.vp[j].first)
            {
                i++;
            }
            //move j pointer ahead if jth value is smaller
            //v1 = {3,6}, v2 = {1,5}, so move j ahead 
            else if(vp[i].first>vec.vp[j].first)
            {
                j++;
            }
        }
        return result;
}
