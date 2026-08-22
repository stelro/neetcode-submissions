class Solution {
public:
    struct UnionFind {
        std::vector<int> parent;
        UnionFind(size_t size) {
            parent.resize(size);
            for (int i = 0; i < size; i++) {
                parent[i] = i;
            }
        }
        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }
        void unite(int i, int j) {
            int ii = find(i);
            int jj = find(j);
            parent[ii] = jj;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size() + 1);
        for (auto& edge : edges) {
            auto u = edge[0];
            auto v = edge[1];
            if (uf.find(u) == uf.find(v)) {
                return edge;
            }
            uf.unite(u, v);
        }
        return {};
    }
};
