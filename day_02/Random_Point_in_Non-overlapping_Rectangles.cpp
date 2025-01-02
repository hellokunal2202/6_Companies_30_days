//leetcode  : https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/
class Solution {
public:
    int num_pts;
    vector<int>prefix_points;
    vector<vector<int>>rects;
    Solution(vector<vector<int>>& rects)
    {
        num_pts=0;
        this->rects=rects;
        for(auto& it:rects){
            num_pts+=(it[2]-it[0]+1)*(it[3]-it[1]+1);
            prefix_points.push_back(num_pts);
        }

    }
    vector<int> pick() 
    {
        int pick_idx = rand()%num_pts;
        int l=0,r=rects.size()-1;
        while(l<r){
            int mid = l+(r-l)/2;
            if(prefix_points[mid]<=pick_idx) l=mid+1;
            else r=mid;
        }
        vector<int>& rect=rects[l]=;
        int x_pts = rect[2]-rect[0]+1;
        int y_pts = rect[3]-rect[1]+1;
        int pts_in_rect = x_pts*y_pts;
        int pt_start = prefix_points[l]-pts_in_rect;
        int offset = pick_idx-pt_start;
        return {rect[0]+offset%x_pts,rect[1]+offset/x_pts};
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */