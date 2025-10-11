#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* prev= nullptr;
        ListNode* curr= head;
        ListNode* newHead= head->next;

        while(curr && curr->next){
            ListNode* nextNode = curr->next;
            ListNode* nextPair = nextNode->next;

            nextNode->next= curr;
            curr->next= nextPair;

            if(prev){
                prev->next= nextNode;
            }

            prev= curr;
            curr = nextPair;
        }
        return newHead;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}