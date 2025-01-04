class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thresh) 
    {
        //used floyed wareshall
        vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
        for(auto it:edges)
        {
            adj[it[0]][it[1]] = it[2];
            adj[it[1]][it[0]] = it[2];
        }
        for(int i=0;i<n;i++) adj[i][i]=0;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(adj[i][k]==INT_MAX|| adj[k][j]==INT_MAX)
                        continue;
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        int city;
        int min_city=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(adj[i][j]<=thresh)
                    count++;
            }
            if(count<=min_city)
            {
                min_city = count;
                city = i;
            }
        }
        return city;


        
        
    }
};