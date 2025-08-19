#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

// class Solution{
// public:
//     char kthCharacter(int k){
//         string s = "a";
//         while (s.length() < k){
//             string t = "";
//             for (char c : s){
//                 t += (c == 'z' ? 'a' : c + 1);
//             }
//             s+=t;
//         }
//         return s[k-1];
//     }
// };

class Solution{
public:
    char kthCharacter(long long k, vector<int> &operations){
        // string s = "a";
        // for (int op : operations){
        //     if (op == 0){
        //         if (s.length() >= k) continue;
        //         s += s;
        //     }
        //     else if (op == 1){
        //         if (s.length() >= k) continue;
        //         string next;
        //         next.reserve(s.length());
        //         for(char c:s){
        //             next+=(c == 'z' ? 'a' : c + 1);
        //         }
        //         s += next;
        //     }
        //     if(s.length()>k) break;
        // }
        // return s[k-1];

        vector<int> ops=operations;
        reverse(ops.begin(), ops.end());
        char c='a';
        long long len=1;

        for(int op:operations){
            len*=2;
            if(len>=k) break;
        }
        for(int i =ops.size()-1;i>=0;i--){
            if(k>=len/2){
                len/=2;
                continue;
            }
            k-=len/2;
            len/=2;

            if(operations[i]==0){
                c=(c=='a')?'z':c-1;
            }
        }
        return c;
    }
};

int32_t main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}