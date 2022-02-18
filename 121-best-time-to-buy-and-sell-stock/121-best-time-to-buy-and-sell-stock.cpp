class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> pre, suff(n,0);
        
        pre.push_back(prices[0]);
        for(int i=1 ;i<prices.size(); i++) pre.push_back(min(pre[i-1],prices[i]));
        
        suff[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--) suff[i] = max(suff[i+1], prices[i]);
        
        int ans = 0;
        for(int i=0; i<n; i++) ans = max(ans, suff[i]-pre[i]);
        
        return ans;
    }
};