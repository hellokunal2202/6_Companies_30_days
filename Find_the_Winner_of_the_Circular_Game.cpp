//microsoft
//Leetcode : https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
//TC = O(n*k)
class Solution {
public:
    int findTheWinner(int n, int k) 
    {
        //TC : O(n*k)
        queue<int> q;
        for(int i=1;i<=n;i++)
            q.push(i);
        while(q.size()>1)
        {
            for(int i=1;i<=k-1;i++)
            {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
        
    }
};