class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);

        for (auto pair : prerequisites) {
            int we_want = pair[0];
            int we_need = pair[1];
            adj[we_need].push_back(we_want);
        }

        int n = numCourses;
        std::vector<int> indegree(numCourses, 0);
        for (int i = 0; i < n; i++) {
            for (auto next : adj[i]) {
                indegree[next]++;
            }
        }

        std::queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        std::vector<int> list;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            list.push_back(top);
            
            for (auto next : adj[top]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (list.size() != numCourses) return {};

        return list;
    }
};
