
class Solution {
public:
    int man(vector<vector<int>>& points, int p1, int p2) {
        return abs(points[p1][0] - points[p2][0]) +
               abs(points[p1][1] - points[p2][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        vector<bool> mst(n, false);

        int cost = 0;

        pq.push({0, 0});

        while (!pq.empty()) {

            auto p = pq.top();
            int wt = p.first;
            int node = p.second;

            pq.pop();

            if (mst[node]) {
                continue;
            }

            mst[node] = true;
            cost += wt;

            for (int i = 0; i < n; i++) {
                if (!mst[i]) {
                    int edge = man(points, node, i);
                    pq.push({edge, i});
                }
            }
        }

        return cost;
    }
};
