class Solution {
public:
    vector<vector<int>> ans;
    
    void findAllSubsets(int i, vector<int> arr, vector<int> tempStore){
        if(i == arr.size()){
            ans.push_back(tempStore);
            return;
        }    
        
        findAllSubsets(i+1, arr, tempStore);
        tempStore.push_back(arr[i]);
        findAllSubsets(i+1, arr, tempStore);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int i=0;
        vector<int> tempStore;
        findAllSubsets(i, nums, tempStore);
        
        return ans;
    }
};