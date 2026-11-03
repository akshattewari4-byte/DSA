
class Solution {
public:
    bool is(int src, vector<bool>& vis,
            vector<bool>& recpath,
            vector<vector<int>>& edge) {

        vis[src] = true;
        recpath[src] = true;

        for (int i = 0; i < edge.size(); i++) {
            int v = edge[i][0];
            int u = edge[i][1];

            if (u == src) {
                if (!vis[v]) {
                    if (is(v, vis, recpath, edge))
                        return true;
                }
                else if (recpath[v]) {
                    return true;
                }
            }
        }

        recpath[src] = false;
        return false;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<bool> vis(numCourses, false);
        vector<bool> recpath(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (is(i, vis, recpath, prerequisites))
                    return false;
            }
        }

        return true;
    }
};
