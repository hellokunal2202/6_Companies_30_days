//https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/
class Solution {
public:
    bool increasing(vector<int>& nums,int start,int end)
    {
        for(int i=start;i<end;i++)
        {
            if(nums[i]>=nums[i+1])
                return false;
        }
        return true ;
    }
    int incremovableSubarrayCount(vector<int>& nums) 
    {
       bool isValid=true;
       int ans=0;
       int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(i==0)
                {
                    isValid=increasing(nums,j+1,n-1);
                }
                else if(j==n-1)
                {
                    isValid=increasing(nums,0,i-1);
                }
                else
                {
                    bool left=increasing(nums,0,i-1);
                    bool right=increasing(nums,j+1,n-1);
                    bool mid  = (nums[i-1]<nums[j+1]);
                    isValid=left && right && mid;
                }
                if(isValid)
                {
                    ans++;
                }

                
            }
        }
        return ans ;
    }
};