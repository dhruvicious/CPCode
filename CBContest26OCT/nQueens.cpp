#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<vector<int>> &board, int i, int j, int n){
	for(int k =0;k<i;k++){
		if(board[k][j]){
			return false;
		}
	}
	int ci=i, cj=j;
	while(i>=0 && j>=0){
		if(board[i--][j--]) return false;
	}
	i=ci;
	j=cj;
	while(i>=0 && j<n){
		if(board[i--][j++]) return false;
	}
	return true;
}

void NQueens(vector<vector<int>> &board, int i, int n, int &count){
	if(i==n){
		count++;
		return;
	}
	for(int j =0;j<n;j++){
		if(isSafe(board, i , j, n)){
			board[i][j]=1;
			NQueens(board, i+1, n, count);
			board[i][j]=0;
		}
	}
}


int main(){
	int n;
	cin>>n;
	int count=0;
	vector<vector<int>> board(n, vector<int>(n,0));
	NQueens(board, 0, n, count);
	cout<<count;
}