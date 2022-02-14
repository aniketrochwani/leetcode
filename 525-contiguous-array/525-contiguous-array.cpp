class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0]=-1;  // mp[sum] = index
        int prefixSum = 0;
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                prefixSum += -1;
            }else{
                prefixSum += 1;
            }
            
            if(mp.find(prefixSum) == mp.end()){
                mp[prefixSum] = i;
            }else{
                int dis = i-mp[prefixSum];
                if(dis > ans){
                    ans = dis;
                }
            }
        }
        
        if(ans == INT_MIN) return 0;
        return ans;
    }
};