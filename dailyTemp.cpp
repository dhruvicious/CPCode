#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTempratures(vector<int>& tempratures) {
    vector<int> answer(tempratures.size());
    stack<int> tempStack;
    int j=tempratures.size()-1;
    while(j>=0){
        while(!tempStack.empty() && tempratures[tempStack.top()]<=tempratures[j]){
            tempStack.pop();
        }
        if(tempStack.empty()){
            answer[j]=0;
        }else{
            answer[j]=tempStack.top()-j;
        }
        tempStack.push(j);
        j--;
    }
    return answer;
}

int main() {
    
}