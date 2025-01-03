class Solution {
public:
    int subarraysSum(vector<int>& nums,int goal)
    {
        int l=0,r=0,n=nums.size();
        int count =0,ans=0;
        while(r<n)
        {
            if(nums[r]%2) count++;
            while(l<=r && count>goal)
            {
                if(nums[l]%2) count--;
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans ;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subarraysSum(nums,k)-subarraysSum(nums,k-1);
        
    }
};