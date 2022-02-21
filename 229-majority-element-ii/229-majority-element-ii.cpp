class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int key1 = -1;
        int key2 = -1;
        int c1 = 0; 
        int c2 = 0;
        
        for(int i=0; i<n; i++){
            if(key1 == nums[i]) c1++;
            else if(key2 == nums[i]) c2++;
            else if(c1 == 0){
                key1 = nums[i];
                c1=1;
            }else if(c2 == 0){
                key2 = nums[i];
                c2=1;
            }else{
                c1--;
                c2--;
            }
        }
        
        vector<int> ans;
        c1=0, c2=0;
        
        for(int i=0; i<n; i++){
            if(nums[i] == key1) c1++;
            else if(nums[i] == key2) c2++;
        }
        
        if(c1>n/3) ans.push_back(key1);
        if(c2>n/3) ans.push_back(key2);
        
        return ans;
    }
};