//leetcode :https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid = n/2;
        int count=0;
        for(auto& it:nums)
        {
            count+=abs(it-nums[mid]);
        }
        return count;
        
    }
};