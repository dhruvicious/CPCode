#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool helper(int k, vi& tasks, vi& workers, int pills, int strength){
    multiset<int> taskSet(tasks.begin(), tasks.end()+k);
    int j= workers.size()-1;
    int remainingPills= pills;

    for(auto it= taskSet.rbegin();it!=taskSet.rend();++it){
        int task=*it;
        if(j>=0 && workers[j]>=task){
            j--;
        }else{
            if(remainingPills==0) return false;
            auto worker_it= upper_bound(workers.begin(), workers.begin()+j+1, task-strength-1);
            if(worker_it==workers.begin()+j+1) return false;
            workers.erase(worker_it);
            remainingPills--;
        }
    }
    return true;
}

int maxTaskAssign(vi& tasks, vi& workers, int pill, int strength) {
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());
    
    int left=0, right= min(tasks.size(), workers.size());
    int ans=0;

    while(left<=right){
        int mid =(left+right)/2;

        vi workers_copy=workers;
        if(helper(mid, tasks, workers_copy, pill, strength)){
            ans=mid;
            left= mid+1;
        }else{
            right= mid-1;
        }
    }
    return ans;
}

int main() {
    
}