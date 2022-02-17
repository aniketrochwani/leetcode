class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int n=nums.size();
        
        vector<int> p;
        for(int i=0; i<n; i++){
            int find = target -  nums[i];
            if(mp[find] != 0){
                p.push_back(i);
                p.push_back(mp[find]-1);
            }else{
                mp[nums[i]] =i+1;
            }
        } 
        return p;
    }
};