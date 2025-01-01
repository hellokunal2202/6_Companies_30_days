//Microsoft
class Solution {
public:
    bool checkOverlap(int r, int h, int k, int x1, int y1, int x2, int y2)
    {
        int dx,dy;
        if(h<x1) dx=x1;
        else if(h>x2) dx=x2;
        else dx=h;

        if(y1>k) dy =y1;
        else if(k>y2) dy=y2;
        else dy=k;

        return (h-dx)*(h-dx) + (k-dy)*(k-dy) <=r*r;       
    }
};