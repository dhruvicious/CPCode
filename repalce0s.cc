#include <bits/stdc++.h>
using namespace std;

int replace0s(int n, string &result){
    if(n==0){
        if (result.empty()) result = "5";
        reverse(result.begin(), result.end());
        return stoi(result);
    }else{
        int digit= n%10;
        if(digit==0){
            result+='5';
            return replace0s(n/10, result);
        }else{
            result+=to_string(digit);
            return replace0s(n/10, result);
        }
    }
}

// int replcace0s(int n) {
//     string result = "";
//     while (n) {
//         int digit = n % 10;
//         if (digit == 0) {
//             result +='5';
//         } else {
//             result += to_string(digit);
//         }
//         n /= 10;
//     }
//     reverse(result.begin(), result.end());
//     return stoi(result);
// }

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    string result;
    cout<<replace0s(n, result);
    return 0;
}