class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=0; i<nums.size()-1; i++){
            int k = nums[i];
            i++;
            for(int j=0; j<k; j++) ans.push_back(nums[i]);
        }
        
        return ans;
    }
};