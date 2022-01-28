class Solution {
public:
    vector<vector<int>> buildGraph(int V, vector<vector<int>> prerequisites){
        vector<vector<int>> graph(V);    
        for(int i=0; i<prerequisites.size(); i++) graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        return graph;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<int> ans;
        
        vector<int> indeg(numCourses,0);
        for(int i=0; i<numCourses; i++){
            for(int j=0; j<graph[i].size(); j++){
                indeg[graph[i][j]]++;
            }   
        }
        
        // We'll use BFS for this purpose
        
        queue<int> qu;
        for(int i=0; i<indeg.size(); i++) if(indeg[i] == 0) qu.push(i);
        
        while(qu.size() > 0){
            // remove
            int rm = qu.front(); qu.pop();
            
            // work
            ans.push_back(rm);
            
            // add neighbour
            for(int i=0; i<graph[rm].size(); i++){
                indeg[graph[rm][i]]--;
                if(indeg[graph[rm][i]] == 0) qu.push(graph[rm][i]);  
            }
        }
        
        if(ans.size() == numCourses) return true;

        return false;
    }
};