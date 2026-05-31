class Solution {
public:

    void dfs(int i, unordered_map<int, unordered_set<int>>& adjList, vector<int>& visited) {
        visited[i] = 1;
        for(auto& child : adjList[i]) {
            cout<<child<<" "<<i<<endl;
            if(!visited[child]) dfs(child, adjList, visited);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> adjList;
        vector<int> visited(n, 0);
        for(int i =0; i<edges.size(); i++) {
            adjList[edges[i][0]].insert(edges[i][1]);
            adjList[edges[i][1]].insert(edges[i][0]);
        }
        int connected_components = 0;
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                dfs(i, adjList, visited);
                connected_components ++;
            }
        }
        return connected_components;
    }
};
