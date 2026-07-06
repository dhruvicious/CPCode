#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   private:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next     = prev;
            prev           = curr;
            curr           = next;
        }
        return prev;
    }

   public:
    int pairSum(ListNode* head) {
        /** while this works this is not how you are supposed to solve this */
        // vector<int> arr;
        // while (head->next != nullptr) {
        //     arr.push_back(head->val);
        //     head = head->next;
        // }
        // int left = 0, right = arr.size() - 1;
        // int maxSum = INT_MIN;
        // while (left < right) {
        //     maxSum = max(arr[left++] + arr[right--], maxSum);
        // }
        // return maxSum;
        //
        ListNode *fast = head, *slow = head;
        while (fast->next && fast) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* revMid = reverseList(slow);

        int       maxSum = INT_MIN;
        ListNode *p1 = head, *p2 = revMid;

        while (p2) {
            maxSum = max(maxSum, p1->val + p2->val);
            p1     = p1->next;
            p2     = p2->next;
        }

        return maxSum;
    }
};

int main() {
    return 0;
}
