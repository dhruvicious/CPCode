#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    int getDecimalValue(ListNode* head){
        string numStr="";
        while(head){
            if(head->val==1) numStr.push_back('1');
            else numStr.push_back('0');
            head=head->next;
        }
        int result=0;
        for(int i =0;i<numStr.size();i++){
            result+=pow(2,(numStr.size()-i-1))*(numStr[i]-'0');
        }
        return result;
    }

    int getDecimalValue(ListNode* head) {
        int result=0;
        while(head){
            result=(result<<1)|head->val;
            head=head->next;
        }
        return result; 
    }
};

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif



    return 0;
}