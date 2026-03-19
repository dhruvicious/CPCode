%:include <iostream>
%:include <vector>

using namespace std;

class Solution {
   private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[node] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }

   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int noOfComp = 0;
        vector<bool> visited(n);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                noOfComp++;
                dfs(i, isConnected, visited);
            }
        }
        return noOfComp;
    }
};

int main() {
    int n = 0;
    cin >> n;
    vector<vector<int>> isConnected(n, vector<int>(n, 0));
    for (vector<int>& vec : isConnected)
        for (int& i : vec) cin >> i;
    Solution s;
    s.findCircleNum(isConnected);
    return 0;
}
