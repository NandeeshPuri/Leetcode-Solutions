class Solution {
private:
    int num_;
    vector<string> ans_;
    unordered_map<string, vector<int>> graph_;
    bool dfs(vector<vector<string>> &tickets, const string &start, vector<bool> &visited, vector<string> &ans) {
        if (ans.size() == num_ + 1) {
            ans_ = ans;
            return true;
        }
        for (const int edge_id : graph_[start]) {
            if (!visited[edge_id]) {
                visited[edge_id] = true;
                const string &destin = tickets[edge_id][1];
                ans.push_back(destin);
                if (dfs(tickets, destin, visited, ans)) return true;
                ans.pop_back();
                visited[edge_id] = false;
            }
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        num_ = tickets.size();
        // start point to edge idx
        for (int i = 0; i < num_; i++) {
            const auto &ticket = tickets[i];
            graph_[ticket[0]].push_back(i);
        }
        // sort the edges based on the string
        for (auto &p : graph_) {
            auto &edges = p.second;
            sort(edges.begin(), edges.end(), [&](int a, int b) {
            return tickets[a][1] < tickets[b][1];
        });
        }
        vector<string> ans = {"JFK"};
        vector<bool> visited(num_, false);
        dfs(tickets, "JFK", visited, ans);
        return ans_;
    }
};