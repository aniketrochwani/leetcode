class Solution {
public:
    vector<vector<int>> ans;
    
    void find(vector<int> candidates, int ind, int target, vector<int> ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
//         if(target == 0){
//             ans.push_back(ds);
//             return;
//         }
        
//         if(ind+1 > candidates.size()) return;
        
        if(target>=candidates[ind]){
            ds.push_back(candidates[ind]);
            find(candidates, ind, target - candidates[ind], ds);
            ds.pop_back();
        }
        find(candidates, ind+1, target, ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        find(candidates, 0, target, ds);
        return ans;
    }
};