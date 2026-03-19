#include <cassert>
#include <utility>
#include <vector>

template <typename T, typename Classifier>
void threeWayPart(std::vector<T>& vec, Classifier f) {
    int low = 0, mid = 0;
    if (vec.empty()) return;
    int high = vec.size() - 1;

    while (mid <= high) {
        int inv = f(vec[mid]);
        assert(inv >= 0 && inv <= 2);
        if (inv == 0) {
            std::swap(vec[low++], vec[mid++]);
        } else if (inv == 1) {
            mid++;
        } else {
            std::swap(vec[mid], vec[high--]);
        }
    }
}

int main() {
}
