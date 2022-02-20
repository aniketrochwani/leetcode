class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        stack<vector<int>> st;
        st.push(intervals[0]);
        
        for(int i=1; i<size; i++){
            vector<int> top = st.top();
            if(top[0] <= intervals[i][0] and top[1] >= intervals[i][1]){
                continue;
            }else if(top[0] == intervals[i][0] and top[1] < intervals[i][1]){
                st.pop();
            }
            st.push(intervals[i]);
        }
        
        return st.size();
    }
};