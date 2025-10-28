#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class node{
    public:
    int val;
    node *left, *right;
    node(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node* buildTree(vector<int> &arr){
    if(arr.empty() || arr[0]==-1) return nullptr;
    node* root = new node(arr[0]);
    queue<node*> q;
    q.push(root);
    int i =1;

    while(!q.empty() && i<arr.size()){
        node* curr = q.front(); q.pop();
        if(i<arr.size() && arr[i]!=-1){
            curr->left = new node(arr[i]);
            q.push(curr->left);
        }
        i++;
        if(i<arr.size() && arr[i]!=-1){
            curr->right = new node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int maxSum = INT_MIN;
int maxPath(node* root){
    if(!root) return 0;
    int left = max(0,maxPath(root->left));
    int right = max(0,maxPath(root->right));
    maxSum = max(maxSum, root->val +left+right);
    return root->val+max(left, right);
}

int findMaxPath(node* root){
    maxPath(root);
    return maxSum;
}

int main(){
    vector<int> levOrder;
    int x;
    while(cin>>x){
        levOrder.push_back(x);
    }

    node* root = buildTree(levOrder);
    cout<<findMaxPath(root);
    return 0;
}