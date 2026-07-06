#include <iostream>

using namespace std;

class listNode {
    int       val;
    listNode* next;
    listNode(int val) : val(val), next(nullptr) {}
    listNode(int val, listNode* next) : val(val), next(next) {}
};

int main() {
}
