//leetcode :https://leetcode.com/problems/bulls-and-cows/
class Solution {
public:
    string getHint(string secret, string guess) 
    {
        unordered_map<char,int>s;
        unordered_map<char,int>g;
        int bulls=0;
        int n=secret.length();
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
                bulls++;
            else
            {
                s[secret[i]]++;
                g[guess[i]]++;
            }
        }
        int cows=0;
        for(auto& it:s)
        {
            char c=it.first;
            if(g.find(c)!=g.end())
            {
                cows+=min(it.second,g[c]);
            }
        }
        string ans="";
        ans+=to_string(bulls);
        ans+="A";
        ans+=to_string(cows);
        ans+="B";
        return ans ;
    }
};