class DSU {
public:
    vector<int> parents, Size;
    int comps;
    DSU(int n) {
        comps = n;
        parents.resize(n+1, 0);
        Size.resize(n+1, 0);
        for(int i = 0; i<=n; i++) {
            parents[i] = i;
            Size[i] = 1;
        }
    }
    int find(int a) {
        if(parents[a] != a) {
            parents[a] = find(parents[a]);
        }
        return parents[a];
    }
    bool unionByRank(int a, int b) {
        int pa = find(a);
        int pb = find(b); 
        if(pa == pb) return false;
        comps--;
        if(Size[pa]<Size[pb]) {
            swap(pa, pb);
        }
        parents[pa] = pb;
        Size[pb] += Size[pa];
        return true;
    }
};


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        DSU dsu(n);
        for(int i = 0; i<edges.size(); i++) {
            if(!dsu.unionByRank(edges[i][0], edges[i][1])) return false;
        }
        return dsu.comps == 1;
    }
};
