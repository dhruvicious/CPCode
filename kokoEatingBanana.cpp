#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& piles, int h) {
    int left=1;
    int right= *max_element(piles.begin(), piles.end());

    while (left<right)
    {
        int mid= left+ (right-left)/2;
        int hours_needed=0;
        for(int i =0; i<piles.size();i++){
            hours_needed+=ceil(double(piles[i])/mid);
        }
        if(hours_needed<=h){
            right=mid;
        }else{
            left=mid+1;

        }
    }
    return left;
}

int main() {
    
}