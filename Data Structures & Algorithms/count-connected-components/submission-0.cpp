class Solution {
public:
    class UnionFind {
    private:
        std::vector<int> parent;
    public:
        UnionFind(int size) {
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
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);

        for (auto edge : edges) {
            auto x = edge[0];
            auto y = edge[1];
            uf.unite(x, y);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            std::cout << "i: " << i << std::endl;
            if (uf.find(i) == i) {
                count++;
            }
        }
        return count;
    }
};
