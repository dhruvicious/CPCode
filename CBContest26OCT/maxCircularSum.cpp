#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kadaneMax(vector<int> &nums){
	int mxSum = nums[0], curr = nums[0];
	for(int i =1;i<nums.size();i++){
		curr = max(nums[i], curr+nums[i]);
		mxSum=max(mxSum, curr);
	}
	return mxSum;
}
int kadaneMin(vector<int> &nums){
	int mnSum = nums[0], curr = nums[0];
	for(int i =1;i<nums.size();i++){
		curr = min(nums[i], curr+nums[i]);
		mnSum=min(mnSum, curr);
	}
	return mnSum;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int total =0;
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int &i: arr){
			cin>>i;
			total +=i;
		}
		int maxKa = kadaneMax(arr);
		int minKa = kadaneMin(arr);

		if(maxKa<0) cout<<maxKa<<endl;
		else cout<<max(maxKa, total - minKa)<<endl;
	}

}