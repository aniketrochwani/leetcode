class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp1, mp2;
        
        for(int i=0; i<nums1.size(); i++) mp1[nums1[i]]++;
        for(int i=0; i<nums2.size(); i++) mp2[nums2[i]]++;
        
        vector<int> ans;
        for(auto it: mp1){
            if(mp1[it.first] and mp2[it.first]){
                for(int i=0; i<min(mp1[it.first], mp2[it.first]); i++) ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};