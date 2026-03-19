#include <cstddef>
#include <cstdint>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <random>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// class UUID {
//    private:
//     std::string value;

//     static std::string generate() {
//         static std::random_device rd;
//         static std::mt19937_64 gen(rd());
//         static std::uniform_int_distribution<uint64_t> dist(
//             std::numeric_limits<uint64_t>::min(), std::numeric_limits<uint64_t>::max());

//         std::stringstream ss;
//         ss << std::hex << std::setw(16) << std::setfill('0') << dist(gen) << std::setw(16) << std::setfill('0')
//            << dist(gen);

//         return ss.str();
//     }

//    public:
//     UUID() : value(generate()) {};
//     const std::string& str() const noexcept { return value; }

//     bool operator==(const UUID& other) const noexcept { return this->value == other.value; }
// };

class UUID {
   private:
    uint64_t high;
    uint64_t low;

    static std::pair<uint64_t, uint64_t> generate() {
        static std::random_device rd;
        static std::mt19937_64 gen(rd());
        static std::uniform_int_distribution<uint64_t> dist(
            std::numeric_limits<uint64_t>::min(), std::numeric_limits<uint64_t>::max());
        return {dist(gen), dist(gen)};
    }

   public:
    UUID() {
        auto [h, l] = generate();
        high = h;
        low = l;
    }

    std::string str() const {
        static constexpr char hex[] = "0123456789abcdef";
        std::string out(32, '0');
        uint64_t values[2] = {high, low};
        for (int part = 0; part < 2; ++part) {
            for (int i = 0; i < 16; ++i) {
                uint8_t nibble = (values[part] >> ((15 - i) * 4)) & 0xF;
                out[part * 16 + i] = hex[nibble];
            }
        }
        return out;
    }
    bool operator==(const UUID& other) const noexcept { return high == other.high && low == other.low; }
    friend struct std::hash<UUID>;
};

namespace std {
template <>
struct hash<UUID> {
    std::size_t operator()(const UUID& id) const noexcept {
        size_t h1 = std::hash<uint64_t>{}(id.high);
        size_t h2 = std::hash<uint64_t>{}(id.low);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};
}  // namespace std

template <typename T>
class graphEL {
   private:
    template <typename K>
    struct Vertex {
        UUID id;
        K value;
    };

    struct Edge {
        UUID src;
        UUID dest;
        double weight;
    };
    std::unordered_map<UUID, Vertex<T>> vertices;
    std::vector<Edge> edges;
    bool isDirected;

   public:
    explicit graphEL(bool directed = true) : isDirected(directed) {}

    UUID addVertex(const T& value) {
        Vertex<T> v{UUID(), value};
        UUID id = v.id;
        vertices.emplace(id, v);
        return id;
    }

    void addEdge(const UUID& src, const UUID& dest, double weight = 0.0) {
        if (!vertices.contains(src) || !vertices.contains(dest)) {
            throw std::invalid_argument("One or both the vertices specified do not exist");
        }
        edges.push_back({src, dest, weight});
        if (!isDirected) {
            edges.push_back({dest, src, weight});
        }
    }

    const std::unordered_map<UUID, Vertex<T>>& getVertices() const noexcept { return vertices; }

    const std::vector<Edge>& getEdges() const noexcept { return edges; }

    std::size_t order() const noexcept { return vertices.size(); }

    std::size_t size() const noexcept { return edges.size(); }

    void printVertices() const {
        for (auto& [uuid, vertex] : vertices) {
            std::cout << "uuid: " << uuid.str() << "value: " << vertex.value << "\n";
        }
    }

    void printEdges() const {
        for (auto e : edges) {
            std::cout << "src: " << e.src.str() << " dest: " << e.dest.str() << " weight: " << e.weight << " \n";
        }
    }

    std::vector<T> bfs(const UUID& start) const {
        std::vector<T> traversalRes;
        if (!vertices.contains(start)) {
            throw std::invalid_argument("Start vertex does not exist.");
        }

        std::queue<UUID> queue;
        std::unordered_set<UUID> visited;

        visited.insert(start);
        queue.push(start);

        while (!queue.empty()) {
            const UUID& q = queue.front();
            queue.pop();
            traversalRes.push_back(vertices.at(q).value);
            for (const Edge& edge : edges) {
                if (edge.src == q) {
                    if (!visited.contains(edge.dest)) {
                        visited.insert(edge.dest);
                        queue.push(edge.dest);
                    }
                }
            }
        }
        return traversalRes;
    }

    std::vector<T> dfs(const UUID& start) {
        if (!vertices.contains(start)) {
            throw std::invalid_argument("Start vertex does not exist");
        }
        std::vector<T> traversalRes;
        std::unordered_set<UUID> visited;
        auto helper = [&](const auto&& self, const UUID& current) -> void {
            visited.insert(current);
            traversalRes.push_back(vertices.at(current).value);

            for (const Edge& edge : edges) {
                if (edge.src == current && !visited.contains(edge.dest)) {
                    self(edge.dest);
                }
            }
        };
        helper(helper, start);
        return traversalRes;
    }
};

void run_tests() {
    std::cout << "--- Running Custom Tests ---\n";

    {
        graphEL<std::string> g(false);
        auto a = g.addVertex("A");
        auto b = g.addVertex("B");
        g.addEdge(a, b);

        auto res = g.bfs(b);
        std::cout << "Test 1 (Undirected B->A): " << (res.size() == 2 ? "PASS" : "FAIL") << "\n";
    }

    {
        graphEL<std::string> g(true);
        auto a = g.addVertex("A");
        auto b = g.addVertex("B");
        g.addEdge(a, b);

        auto res = g.bfs(b);
        std::cout << "Test 2 (Directed B ignores A): " << (res.size() == 1 ? "PASS" : "FAIL") << "\n";
    }

    {
        graphEL<int> g(true);
        auto v1 = g.addVertex(1);
        auto v2 = g.addVertex(2);
        auto v3 = g.addVertex(3);

        g.addEdge(v1, v2);
        g.addEdge(v2, v3);
        g.addEdge(v3, v1);

        auto res = g.bfs(v1);
        std::cout << "Test 3 (Cycle Handling): " << (res.size() == 3 ? "PASS" : "FAIL") << "\n";
    }

    {
        graphEL<int> g;
        UUID fake;
        auto real = g.addVertex(100);
        try {
            g.addEdge(real, fake);
            std::cout << "Test 4 (Invalid UUID): FAIL (No exception thrown)\n";
        } catch (const std::invalid_argument& e) {
            std::cout << "Test 4 (Invalid UUID): PASS\n";
        }
    }
}

int main() {
    run_tests();
    return 0;
}
