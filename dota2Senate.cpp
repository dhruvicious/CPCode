#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        string predictPartyVictory(string senate){
            int n=senate.size();
            queue<int> radiant;
            queue<int> dire;

            for(int i =0;i<senate.length();i++){
                if(senate[i]=='R'){
                    radiant.push(i);
                }else if(senate[i]=='D'){
                    dire.push(i);
                }
            }
            while(!radiant.empty() && !dire.empty()){
                if(radiant.front()<dire.front()){
                    dire.pop();
                    radiant.push(radiant.front()+n);
                    radiant.pop();
                }else{
                    radiant.pop();
                    dire.push(dire.front()+n);
                    dire.pop();
                }
            }
            if(!radiant.empty()) return "Radiant";
            else if(!dire.empty()) return "Dire";
        }
};

int main() {
 
}