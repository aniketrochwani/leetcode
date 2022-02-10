class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        int sum=0, ans=0;
        map<int,int> mp;
        mp[0] = 1;
        
        for(int i=0; i<size; i++){
            sum += nums[i];
            if(mp[sum-k]) ans+=mp[sum-k];
            mp[sum]++;
        }
        
        return ans;
    }
};