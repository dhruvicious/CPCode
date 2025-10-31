#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node {
   private:
    T val;
    node<T>* right;
    node<T>* left;

   public:
    node(T val) : val(val), right(nullptr), left(nullptr) {}
    node() : val(T()), right(nullptr), left(nullptr) {}

    node<T>* getRight() { return this->right; }
    node<T>* getLeft() { return this->left; }
    T getVal() { return this->val; }

    void setVal(T val) { this->val = val; }
    void setRight(node<T>* right) { this->right = right; }
    void setLeft(node<T>* left) { this->left = left; }

    ~node() {
        delete this->left;
        delete this->right;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}