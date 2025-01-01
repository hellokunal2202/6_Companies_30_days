//microsoft
//https://leetcode.com/problems/image-smoother/description/
//TC = O(n*m)
class Solution {
public:
    vector<vector<int>>dir{
        {-1,-1},{-1,0},{-1,1},
        {0,-1},{0,0},{0,1},
        {1,-1},{1,0},{1,1}
    };
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
    {
        int m=img.size();
        int n=img[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int sum=0;
                int count=0;
                for(auto& it:dir)
                {
                    int new_x=i+it[0];
                    int new_y=j+it[1];
                    if(new_x>=0&&new_x<m&&new_y>=0&&new_y<n)
                    {
                        sum+=img[new_x][new_y];
                        count++;
                    }
                }
                ans[i][j]=sum/count++;
                
            }
        }
        return ans ;
        
    }
};