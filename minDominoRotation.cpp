#include <bits/stdc++.h>
using namespace std;

int minDominoRotation(vector<int> tops, vector<int> bottoms){
    int n= tops.size();
    int v1 =tops[0];
    int v2 =bottoms[0];

    int rotationTopV1=0, rotationBottomV1=0;
    bool canV1=true;
    for(int i=0; i<n;i++){
        if(tops[i]!=v1 && bottoms[i]!=v1){
            canV1=false;
            break;
        }
        if(tops[i]!=v1) rotationTopV1++;
        if(bottoms[i]!=v1) rotationBottomV1++;
    }

    int rotationTopV2=0, rotationBottomV2=0;
    bool canV2=true;
    for(int i =0;i<n;i++){
        if(tops[i]!=v2 && bottoms[i]!=v2){
            canV2=false;
            break;
        }
        if(tops[i]!=v2) rotationTopV2++;
        if(bottoms[i]!=v2) rotationBottomV2++;
    }
    
    int res= INT_MAX;
    if(canV1) res= min(res, min(rotationTopV1, rotationBottomV1));
    if(canV2) res= min(res, min(rotationTopV2, rotationBottomV2));
    return res==INT_MAX? -1:res;
}

int main() {

}