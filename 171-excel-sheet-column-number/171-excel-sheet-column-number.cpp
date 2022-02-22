class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size(), k=0; 
        int ans = 0;
        for(int i=n-1; i>=0; i--){
            ans += pow(26, k)*(columnTitle[i]-64);
            k++;
        }
        return ans;
    }
};