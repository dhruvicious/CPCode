#include <bits/stdc++.h>
using namespace std;

string pushDomino(string dominoes){
    int n=dominoes.size();
    vector<int> rightTime(n, INT_MAX);
    vector<int> leftTime(n, INT_MAX);

    int timeR=INT_MAX, timeL=INT_MAX;
    for(int i =0;i<n;i++){
        if(dominoes[i]=='R') timeR=0;
        else if(dominoes[i]=='L') timeR=INT_MAX;
        else if(timeR!=INT_MAX) timeR++;
        rightTime[i]=timeR;

        int j=n-1-i;
        if(dominoes[j]=='L') timeL=0;
        else if(dominoes[j]=='R') timeL=INT_MAX;
        else if(timeL!=INT_MAX) timeL++;
        leftTime[j]=timeL;
    }

    string ans="";
    for(int i =0;i<rightTime.size();i++){
        if(leftTime[i]<rightTime[i]) ans.append("L");
        else if(leftTime[i]>rightTime[i]) ans.append("R");
        else if(leftTime[i]==rightTime[i]) ans.append(".");
    }
    return ans;
}

int main() {
    
}