class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        
        map<int,bool> mp;
        int ans = INT_MIN;
        
        for(int i=0; i<nums.size(); i++) mp[nums[i]] = true;
        
        for(int i=0; i<nums.size(); i++) if(mp.find(nums[i]-1) != mp.end()) mp[nums[i]] = false;
        
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]]){
                int count = 0;
                int k = nums[i];
                while(mp.find(k++) != mp.end()) count++;
                ans = max(ans,count);
            }    
        }
        
        return ans;
    }
};