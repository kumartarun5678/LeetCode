class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> in, out;
        
        // Build the graph
        for (auto& edge : pairs) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            in[v]++;
            out[u]++;
        }

        // Find the start node
        int start = -1;
        for (auto& it : adj) {
            int node = it.first;
            if (out[node] - in[node] == 1) {
                start = node;
                break;
            }
        }

        // If no node with out - in = 1, start from any node with an outgoing edge
        if (start == -1) {
            for (auto& it : adj) {
                if (out[it.first] > 0) {
                    start = it.first;
                    break;
                }
            }
        }

        vector<int> eur;
        stack<int> st;
        st.push(start);

        // Hierholzer's algorithm for Eulerian path
        while (!st.empty()) {
            int curr = st.top();
            if (!adj[curr].empty()) {
                int neg = adj[curr].back();
                adj[curr].pop_back();
                st.push(neg);
            } else {
                eur.push_back(curr);
                st.pop();
            }
        }

        // Reverse the path since we collected it in reverse order
        reverse(eur.begin(), eur.end());

        // Construct the answer
        vector<vector<int>> ans;
        for (int i = 0; i < eur.size() - 1; i++) {
            ans.push_back({eur[i], eur[i + 1]});
        }
        return ans;
    }
};
