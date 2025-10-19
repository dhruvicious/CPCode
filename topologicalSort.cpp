#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

template <typename T>
class Graph {
   public:
    unordered_map<T, list<T> > adj;

    void addEdge(T u, T v, bool bidir = true) {
        adj[u].push_back(v);
        if (bidir) {
            adj[v].push_back(u);
        }
    }

    void print() {
        for (auto p : adj) {
            cout << p.first << " : ";
            for (auto neighbour : p.second) {
                cout << neighbour << ",   ";
            }
            cout << endl;
        }
    }

    void topologicalSort() {
        unordered_map<T, int> indegree;
        for (auto p : adj) {
            for (auto ch : p.second) {
                if (!indegree[ch]) indegree[ch] = 0;
                indegree[ch]++;
            }
        }
        queue<T> q;
        for (auto p : adj) {
            if (indegree.count(p.first) == 0) {
                q.push(p.first);
            }
        }
        while (!q.empty()) {
            T d = q.front();
            q.pop();
            cout << d << " ";

            for (auto ch : adj[d]) {
                indegree[ch]--;

                if (indegree[ch] == 0) {
                    q.push(ch);
                }
            }
        }
    }
};

int main() {
    // DAG: Directed Acyclic Graph
    Graph<string> g;

    g.addEdge("C++", "WebDev", false);
    g.addEdge("WebDev", "CP", false);
    g.addEdge("CP", "Web3", false);
    g.addEdge("DataScience", "Web3", false);
    g.addEdge("WebDev", "DataScience", false);
    g.addEdge("C++", "Android", false);
    g.addEdge("Java", "Android", false);
    g.addEdge("Android", "CyberSecurity", false);

    // g.print();
    g.topologicalSort();

    return 0;
}
