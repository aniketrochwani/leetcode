class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int n = s1.size();
        vector<int> v(26,0), a(26,0);
        for(int i=0; i<n; i++) v[s1[i]-97]++;
        for(int i=0; i<n; i++) a[s2[i]-97]++;
        if(v==a) return true;
        for(int i=n; i<s2.size(); i++){
            a[s2[i-n]-97]--;
            a[s2[i]-97]++;
            if(v==a) return true;
        }
        return false;
    }
};