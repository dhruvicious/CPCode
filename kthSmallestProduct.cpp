#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
#define vi vector<int>

ll countLessEqual(const vi& A, const vi& B, ll x){
    ll count=0;
    for(int a: A){
        if(a==0){
            if(x>=0) count+= B.size();
        }else if(a>0){
            count+=upper_bound(B.begin(), B.end(), x/a) - B.begin();
        }else{
            count+= B.end()-lower_bound(B.begin(), B.end(), (x+(-a-1))/a);
        }
    }
    return count;
}

ll kthSmallestProduct(vi& nums1, vi& nums2, ll k){
    ll low = LLONG_MIN, high= LLONG_MAX;
    while(low<high){
        ll mid=low+(high-low)/2;
        if(countLessEqual(nums1, nums2, mid)<k) low=mid+1;
        else high=mid;
    }
    return low;
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}