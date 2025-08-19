#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class FindSumPairs {
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freqMap;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
        for(int num:nums2){
            freqMap[num]++;
        }
    }
    void add(int index, int val) {
        freqMap[nums2[index]]--;
        this->nums2[index]+=val;
        freqMap[nums2[index]]++;
    }
    
    int count(int tot) {
        int count=0;
        for(int i =0;i<this->nums1.size();i++){
            int target=tot-this->nums1[i];
            count+=freqMap[target];
        }
        return count;
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