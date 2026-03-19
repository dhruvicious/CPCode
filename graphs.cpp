/*
 * Def:: A graph is a mathematical structure used to model pairwise relationships between
 * objects, Formally a graph is an ordered pair:
 *
 * G = (V,E);
 *
 * where V = {v1, v2, v3, v4, ...}; is a non empty finite set of vertices.
 *
 * E is a subset of {V x V} is a set of edges representing relationship between vertices
 *
 * the nature of E determines the type of graph
 *
 *
 * Def:: Vertices(Nodes) represent entities or objects in the system
 * Def:: Edges represent the relationships between the edges
 *  if e = (u,v);
 *  then the vertex u is said to be adjacent to v.
 *
 * Classification of Graphs
 * 1/ Directed
 *      Def:: if edges have direction then (u,v) != (v,u);
 * 2/ Undirected
 *      Def:: if edges have no orientation then (u,v) == (v,u);
 * 3/ Weighted Graph
 *      Def:: if a function w:E->R assigns a numeric weight to each edge, such a graph is
 *              called a weighted graph
 *
 * Degree of a vertex
 *  Def:: For an undirected graph the degree of a vertex deg(v) is the number of edges incident
 *          on it
 *        For a directed graph there are two degree deg+(v) = out-degree
 *        deg-(v) = in-degree
 *
 * Order of a graph = number of vertices
 * Size of a graph  = number of edges
 *
 * Special Graph Types
 * 1/ Simple Graph      -> No loops no multiple edges
 * 2/ MultiGraph        -> Multiple edges allowed between two vertices
 * 3/ Complete Graph    -> Every pair of vertices is connected
 * 4/ Null Graph        -> No Edges
 * 5/ Connected Graph   -> A path exists between every pair of vertices
 *
 * Walk
 *  Def:: A walk in a graph is a finite sequence
 *          v0,v1,v2,v3,...
 *      such that for every i there exists an edge between (v_(i-1), vi);
 *      1) vertices may repeat
 *      2) edges may repeat
 *      3) length of walk == number of edges K.
 *
 * Trail
 *  Def:: A trail is a walk with no repeated edge
 *      1) vertices may repeat
 *      2) edges cannot repeat
 *
 * Path
 *  Def:: A path is a walk where no vertex is repeated
 *      1) no vertex repetition
 *      2) hence no edge repetition (automatically by definition)
 *
 * Loops
 *  Def:: A loop is an edge connecting a vertex to itself
 * Two or more edges connecting the same pair of vertices are called parallel edges
 *
 *
 * Closed Walk
 *  Def:: A walk whose first and last vertices are the same
 *          v0 = vk
 *      vertices and edges may repeat
 *
 * Circuit
 *  Def:: A circuit is a closed trail
 *      1) first vertex = last vertex
 *      2) no repeated edges
 *      3) vertices may repeat
 *      Circuit = Closed Trail
 *
 * Cycle
 *  Def:: A cycle is a closed path
 *      formally for vertices v0,v1,v2,v3,...,v_(k-1), v0;
 *      1) v0 = vk
 *      2) No other vertex repeats
 *      Cycle = Closed Path
 *
 *
 *
 *   ** METHODS OF REPRESENTATION OF GRAPHS **
 *
 * There are three methods of representation of Graphs normally utilized in
 * general applications:
 * 1) Edge List
 * 2) Adjacency List
 * 3) Adjacency Matrix
 */

/*
 * Edge List Representation
 */
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

template <typename T>
struct Edge {
    T src;
    T dest;
    double weight;
    Edge(T s, T d, double w) : src(s), dest(d), weight(w) {}
};

template <typename T>
class GraphEL {
   private:
    std::vector<T> vertices;
    std::vector<Edge<T>> edges;
    bool isDirected;
    bool vertexExists(const T& data) const {
        return std::find(vertices.begin(), vertices.end(), data) != vertices.end();
    }

   public:
    GraphEL(bool directed = true) : isDirected(directed) {}

    // Add vertex
    void addVertex(const T& data) {
        if (!vertexExists(data))
            vertices.push_back(data);
        else
            std::cout << "Vertex already exists.\n";
    }

    // Add Edge
    void addEdge(const T& src, const T& dest, double weight = 0) {
        if (!vertexExists(src) || !vertexExists(dest)) {
            std::cout << "One or both of the vertices do not exist.\n";
            return;
        }
        edges.push_back(Edge<T>(src, dest, weight));

        if (!isDirected) {
            edges.push_back(Edge<T>(dest, src, weight));
        }
    }

    void display() const {
        std::cout << "\nVertex List:\n";
        for (const T& v : vertices) {
            std::cout << v << std::endl;
        }

        std::cout << "\nEdge List:\n";
        for (const Edge<T>& e : edges) {
            std::cout << e.src << " -> " << e.dest << " |Weight:" << e.weight << std::endl;
        }
    }
};

// Adjacency Matrix Representation
template <typename T>
class graphAM {
   private:
    std::vector<T> vertices;
    std::vector<std::vector<double>> AdjMat;
    bool isDirected;

    bool vertexExists(const T& data) const {
        return std::find(vertices.begin(), vertices.end(), data) != vertices.end();
    }

    int getIndex(const T& data) const {
        auto it = std::find(vertices.begin(), vertices.end(), data);
        if (it != vertices.end()) return std::distance(vertices.begin(), it);
        return -1;
    }

   public:
    graphAM(bool directed = true) : isDirected(directed) {}

    void addVertex(const T& data) {
        if (vertexExists(data)) {
            std::cout << "Vertex already exists. \n";
            return;
        }
        vertices.push_back(data);
        for (std::vector<double>& row : AdjMat) {
            row.push_back(0.0f);
        }
        AdjMat.push_back(std::vector<double>(vertices.size(), 0.0f));
    }
    void addEdge(const T& src, const T& dest, double weight = 1) {
        int srcIndex = getIndex(src);
        int destIndex = getIndex(dest);

        if (srcIndex == -1 || destIndex == -1) {
            std::cout << "One or both vertices do not exist";
            return;
        }
        AdjMat[srcIndex][destIndex] = weight;

        if (!isDirected) AdjMat[destIndex][srcIndex] = weight;
    }

    void display() const {
        std::cout << "\nAdjacency Matrix: \n";
        std::cout << std::setw(6) << " ";
        for (const T& v : vertices) {
            std::cout << std::setw(6) << v;
        }
        std::cout << "\n";

        for (size_t i = 0; i < vertices.size(); i++) {
            std::cout << std::setw(6) << vertices[i];
            for (size_t j = 0; j < vertices.size(); j++) {
                std::cout << std::setw(6) << AdjMat[i][j];
            }
            std::cout << '\n';
        }
    }
};

template <typename T>
class graphAL {
   private:
    std::vector<T> vertices;
    std::unordered_map<T, std::vector<std::pair<T, double>>> adjList;
    bool isDirected;

    bool vertexExists(const T& data) const {
        return std::find(vertices.begin(), vertices.end(), data) != vertices.end();
    }

   public:
    graphAL(bool directed = true) : isDirected(directed) {}

    void addVertex(const T& data) {
        if (vertexExists(data)) {
            std::cout << "Vertex already exists.";
            return;
        } else {
            vertices.push_back(data);
            adjList[data] = std::vector<std::pair<T, double>>();
        }
    }

    void addEdge(const T& src, const T& dest, double weight = 0.00f) {
        if (!vertexExists(src) || !vertexExists(dest)) {
            std::cout << "One or both vertices do not exist.";
            return;
        } else {
            adjList[src].push_back({dest, weight});
            if (!isDirected) adjList[dest].push_back({src, weight});
        }
    }

    void display() const {
        std::cout << "\nAdjacency List\n";
        for (const T& v : vertices) {
            std::cout << v << " -> ";
            auto it = adjList.find(v);
            if (it != adjList.end()) {
                for (const auto& n : it->second) {
                    std::cout << "(" << n.first << ", w=" << n.second << ") ";
                }
            }
        }
        std::cout << "\n";
    }
};

void testGraphsELClass() {
    GraphEL<std::string> gd;

    gd.addVertex("A");
    gd.addVertex("B");
    gd.addVertex("C");

    // Edges now use actual data, not indices
    gd.addEdge("A", "B", 4.5);
    gd.addEdge("B", "C", 2.1);
    gd.addEdge("C", "A", 3.0);

    gd.display();

    GraphEL<std::string> gud(false);
    gud.addVertex("P");
    gud.addVertex("Q");
    gud.addVertex("R");

    // Edges now use actual data, not indices
    gud.addEdge("P", "Q", 1.5);
    gud.addEdge("Q", "R", 5.1);
    gud.addEdge("R", "P", 9.0);

    gud.display();
}

void testGraphsAMClass() {
    graphAM<std::string> gd;

    gd.addVertex("A");
    gd.addVertex("B");
    gd.addVertex("C");

    gd.addEdge("A", "B", 4.5);
    gd.addEdge("B", "C", 2.1);
    gd.addEdge("C", "A", 3.0);

    gd.display();

    graphAM<std::string> gud(false);

    gud.addVertex("P");
    gud.addVertex("Q");
    gud.addVertex("R");

    gud.addEdge("P", "Q", 1.5);
    gud.addEdge("Q", "R", 5.1);
    gud.addEdge("R", "P", 9.0);

    gud.display();
}

void testGraphsALClass() {
    // Directed Graph
    graphAL<std::string> gd;

    gd.addVertex("A");
    gd.addVertex("B");
    gd.addVertex("C");

    gd.addEdge("A", "B", 4.5);
    gd.addEdge("B", "C", 2.1);
    gd.addEdge("C", "A", 3.0);

    gd.display();

    // Undirected Graph
    graphAL<std::string> gud(false);

    gud.addVertex("P");
    gud.addVertex("Q");
    gud.addVertex("R");

    gud.addEdge("P", "Q", 1.5);
    gud.addEdge("Q", "R", 5.1);
    gud.addEdge("R", "P", 9.0);

    gud.display();
}

void DrawLine() {
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    testGraphsELClass();
    DrawLine();
    testGraphsAMClass();
    DrawLine();
    testGraphsALClass();
    DrawLine();
    return 0;
}
