#include <bits/stdc++.h>
using namespace std;

//worst time complexity
void setZeroes(vector<vector<int>>& matrix) {
    set<int> rows, cols;
    //first pass
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    //second pass
    for(int i:rows){
        for(int j=0;j<matrix[0].size();j++){
            matrix[i][j]=0;
        }
    }
    //third pass
    for(int j: cols){
        for(int i=0;i<matrix.size();i++){
            matrix[i][j]=0;
        }
    }
}


void setZeroesOpt(vector<vector<int>>& matrix){
    
}
int main() {

}