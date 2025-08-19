#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

/*
You are given an integer array of length 4. You have four cards, each containing a number in the range [1,9].
You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/']
and the parentheses '(' and ')' to get the value 24

You are restricted with the following rules
    1. The division operator represents real division not integer division.
        For example 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
    2. Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
        For example, if cards = [1, 1, 1, 1], the expression "-1 -1 -1 -1" is *not allowed*.
    3. You cannot concatenate numbers together.
        For example, if cards=[1, 2, 1, 2], the expression "12+12" is not valid.

Return treu of you can get such an expression that evaluates to 24, and false otherwise.
*/

class Solution{
    public:
        bool judgePoint24(vector<int>& cards){
            
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