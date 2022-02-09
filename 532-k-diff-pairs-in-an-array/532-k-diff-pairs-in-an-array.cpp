class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++) map[nums[i]]++;
        
        int ans=0;
        if(k>0){
            for(auto i: map){
                if(map.find(i.first+k) != map.end()){
                    ans++;  
                }
            }
        }else{
            for(auto i: map){
                if(i.second > 1){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};