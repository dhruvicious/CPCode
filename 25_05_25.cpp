#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(vector<string>& words){
    map<string, int> strCount;
    int longestPalindrome=0;
    int flag=false;
    for(string word : words){
        strCount[word]++;
    }
    for(auto& itr : strCount){
        string reversed = itr.first;
        int count;
        reverse(reversed.begin(), reversed.end());
        //not self palindromic string
        if(reversed != itr.first){
            count=min(itr.second, strCount[reversed])*4;
            itr.second-=count;
            strCount[reversed]-=count;
        }
        //self palindromic string
        else if(reversed == itr.first){
            count=(itr.second/2)*4;
            if(itr.second%2==1) flag=true;
        }
        longestPalindrome+=count;
    }
    if(flag) longestPalindrome+=2;
    return longestPalindrome;
}

int main() {
    
    return 0;
}