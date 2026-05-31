class Solution {
    vector<int> visited;
    unordered_map<int, int> recPath;
    bool dfs(int i, unordered_map<int, vector<int>>& adjList, int parent) {
        visited[i] = 1;
        for(auto& child : adjList[i]) {
            if(!visited[child]) dfs(child, adjList, i);
            else if(child != parent) return true;
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        visited.resize(n, 0);
        unordered_map<int, vector<int>> adjList;
        for(int i = 0; i<edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        bool cyclePresent = dfs(0, adjList, -1);
        for(int i = 0; i<n; i++) {
            if(!visited[i]) return false;
        }
        return !cyclePresent;
    }
};
