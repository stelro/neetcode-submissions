class Solution {
public:
    bool canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites) {

        std::vector<std::vector<int>> adj(numCourses);
        for (const auto& pair : prerequisites) {
            int first_course = pair[0];
            int before_course = pair[1];
            adj[before_course].push_back(first_course);
        }

        int n = numCourses;
        std::vector<int> indigree(n, 0);

        for (int i = 0; i < n; i++) {
            for (auto next : adj[i]) {
                indigree[next]++;
            }
        }

        std::queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indigree[i] == 0) {
                q.push(i);
            }
        }

        std::vector<int> list;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            list.push_back(top);
            for (auto next : adj[top]) {
                indigree[next]--;
                if (indigree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return (int)list.size() == numCourses;
    }
};
